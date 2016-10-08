#ifndef ABSECURITY
#define ABSECURITY

#include <string>

class AbsSecurity
{
  public:
    
    virtual double price() const = 0;
    
    virtual std::string repr() const = 0;
};

#endif