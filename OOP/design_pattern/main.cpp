#include <EuropeanOption.hpp>
#include <iostream>
#include <memory>
#include <AbsSecurity.hpp>
#include <SecurityFactory.hpp>
#include <Config.hpp>

using namespace std;

int main()
{
    Config & settings = Config::instance();
    settings.set_setting("debug", "true");
    
    const double r = 0.03;
    
    const double call_S = 50.0;
    const double call_K = 50.0;
    const double call_T = 1.0;
    const double call_sigma = 0.2;
    
    const double put_S = 50.0;
    const double put_K = 50.0;
    const double put_T = 1.5;
    const double put_sigma = 0.3;
    
    EuropeanOption::Builder option_builder;
    option_builder
        .setType(EuropeanOption::Call)
        .setS(call_S)
        .setK(call_K)
        .setR(r)
        .setT(call_T)
        .setSigma(call_sigma);
    
    EuropeanOption call_option(option_builder.build());
    
    option_builder
        .setType(EuropeanOption::Put)
        .setS(put_S)
        .setK(put_K)
        .setR(r)
        .setT(put_T)
        .setSigma(put_sigma);
    
    EuropeanOption put_option(option_builder.build());
    
    cout << call_option.repr()
         << ": price = " << call_option.price()
         << " and delta = " << call_option.delta() << endl;
    
    cout << put_option.repr()
         << ": price = " << put_option.price()
         << " and delta = " << put_option.delta() << endl;
    
    cout << call_option.repr()
         << ": imp vol = " << call_option.calc_imp_vol(call_option.price())
         << " with price " << call_option.price() << endl;
    
    cout << put_option.repr()
         << ": imp vol = " << put_option.calc_imp_vol(put_option.price())
         << " with price " << put_option.price() << endl;
    
    SecurityFactory factory;
    unique_ptr<AbsSecurity> opt_obj_ptr = factory.build_security("OPTION");
    cout << "You get: " << opt_obj_ptr.get()->repr() << endl;
    
    unique_ptr<AbsSecurity> bond_obj_ptr = factory.build_security("BOND");
    cout << "You get: " << bond_obj_ptr.get()->repr() << endl;
    
    
    return 0;
}
