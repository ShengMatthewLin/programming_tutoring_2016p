#include <SecurityFactory.hpp>
#include <EuropeanOption.hpp>
#include <Bond.hpp>

using namespace std;

unique_ptr<AbsSecurity> SecurityFactory::build_security(
    const string & sec_id
    )
{
    unique_ptr<AbsSecurity> ptr;
    
    if (sec_id == "OPTION")
    {
        ptr.reset(new EuropeanOption(EuropeanOption::Call, 50, 50, 0.03, 1.0, 0.2));
    }
    else if (sec_id == "BOND")
    {
        ptr.reset(new Bond());
    }
    return ptr;
}