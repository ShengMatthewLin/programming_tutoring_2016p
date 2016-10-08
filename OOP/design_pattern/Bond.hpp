#ifndef BOND
#define BOND

#include <AbsSecurity.hpp>
#include <string>

class Bond : public AbsSecurity
{
  public:
    
    Bond() {};
    
    virtual double price() const { throw "not implemented"; }
    
    virtual std::string repr() const { return "this is a bond"; }
    
  private:
    
    // Bond attributes here
};

#endif