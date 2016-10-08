#include <cmath>
#include <math.h>
#include <iostream>

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

double normalCFD2(const double value)
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

double d_one(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    return (log(S / K) + (r + sigma * sigma *0.5) * T) / (sigma * sqrt(T));
}

double d_two(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    return d_one(S, K, r, T, sigma) - sigma * sqrt(T);
}

double call_option_price(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    const double d1 = d_one(S, K, r, T, sigma);
    const double d2 = d_two(S, K, r, T, sigma);
    const double px = S * normalCFD(d1) - K * exp(-r * T) * normalCFD(d2);
    return px;
}

double put_option_price(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    const double d1 = d_one(S, K, r, T, sigma);
    const double d2 = d_two(S, K, r, T, sigma);
    const double px = K * exp(-r * T) * normalCFD(-d2) - S * normalCFD(-d1);
    return px;
}

double call_option_delta(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    const double d1 = d_one(S, K, r, T, sigma);
    return normalCFD(d1);
}

double put_option_delta(
    const double S,
    const double K,
    const double r,
    const double T,
    const double sigma
    )
{
    return call_option_delta(S, K, r, T, sigma) - 1.0;
}


int main()
{
    const double r = 0.03;
    
    const double call_S = 50.0;
    const double call_K = 50.0;
    const double call_T = 1.0;
    const double call_sigma = 0.2;
    
    const double put_S = 50.0;
    const double put_K = 50.0;
    const double put_T = 1.5;
    const double put_sigma = 0.3;
    
    const double call_px = call_option_price(call_S, call_K, r, call_T, call_sigma);
    const double call_delta = call_option_delta(call_S, call_K, r, call_T, call_sigma);
    
    const double put_px = put_option_price(put_S, put_K, r, put_T, put_sigma);
    const double put_delta = put_option_delta(put_S, put_K, r, put_T, put_sigma);
    cout << "call option: price = " << call_px << " and delta = " << call_delta << endl;
    cout << "put option: price = " << put_px << " and delta = " << put_delta << endl;
    
    return 0;
}