#include <EuropeanOption.hpp>
#include <cmath>
#include <math.h>
#include <iostream>
#include <sstream>
#include <Config.hpp>

using namespace std;

double normalCFD(double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return 0.5*(1.0 + sign*y);
}

EuropeanOption::EuropeanOption(
    const OptionType type,
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    ) : EuropeanOption(type, S, K, r, T)
{
    _sigma = sigma;
    _price = price();
}

double EuropeanOption::d_one() const
{
    return (log(_S / _K) + (_r + _sigma * _sigma *0.5) * _T) / (_sigma * sqrt(_T));
}

double EuropeanOption::d_two() const
{
    return d_one() - _sigma * sqrt(_T);
}

double EuropeanOption::price() const
{
    if (_type == Call)
    {
        return _S * normalCFD(d_one()) - _K * exp(-_r * _T) * normalCFD(d_two());
    }
    else
    {
        return _K * exp(-_r * _T) * normalCFD(-d_two()) - _S * normalCFD(-d_one());
    }
}

double EuropeanOption::delta() const
{
    if (_type == Call)
    {
        return normalCFD(d_one());
    }
    else
    {
        return normalCFD(d_one()) - 1.0;
    }
}

double EuropeanOption::calc_imp_vol(const double price) const
{
    const Config & settings = Config::instance();
    const bool debug = settings.get_setting("debug") == "true";
    
    double lb = 0.001;
    double ub = 1.0;
    const double tol = 0.000001;
    const int max_iter = 50;
    int iter = 1;
    EuropeanOption tmpOption(*this);
    
    while (iter < max_iter)
    {
        if (debug)
        {
            cout << "#" << iter << ": " << "lb = " << lb << ", ub = " << ub << endl;
        }
        
        double mid = (lb + ub) / 2.0;
        tmpOption._sigma = mid;
        const double mid_val = tmpOption.price() - price;
        if (abs(mid_val) < tol)
        {
            return mid;
        }
        iter += 1;
        tmpOption._sigma = lb;
        const double lb_val = tmpOption.price() - price;
        if (lb_val * mid_val > 0)
        {
            lb = mid;
        }
        else
        {
            ub = mid;
        }
    }
    return UNDEF;    
}

string EuropeanOption::repr() const
{
    ostringstream oss;
    oss << (_type == Call ? "C" :  "P")
        << "/K" << _K
        << "/T" << _T;
    return oss.str();
}

bool EuropeanOption::Builder::is_valid() const
{
    return _S != UNDEF 
        && _K != UNDEF 
        && _r != UNDEF
        && _T != UNDEF;
}

EuropeanOption EuropeanOption::Builder::build() const
{
    if (!is_valid())
    {
        throw "invalid parameters";
    }
    
    EuropeanOption obj(_type, _S, _K, _r, _T);
    if (_sigma != UNDEF)
    {
        obj._sigma = _sigma;
        obj._price = obj.price();
    }
    
    return obj;
}
