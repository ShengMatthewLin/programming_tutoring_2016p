#include <EuropeanOption.hpp>
#include <iostream>

using namespace std;

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
    
    EuropeanOption call_option(EuropeanOption::Call, call_S, call_K, r, call_T, call_sigma);
    
    EuropeanOption put_option(EuropeanOption::Put, put_S, put_K, r, put_T, put_sigma);
    
    cout << "call option: price = " << call_option.price() << " and delta = " << call_option.delta() << endl;
    cout << "put option: price = " << put_option.price() << " and delta = " << put_option.delta() << endl;
    cout << "call option imp vol = " << call_option.calc_imp_vol(call_option.price()) << " with price " << call_option.price() << endl;
    cout << "put option imp vol = " << put_option.calc_imp_vol(put_option.price()) << " with price " << put_option.price() << endl;
    return 0;
}