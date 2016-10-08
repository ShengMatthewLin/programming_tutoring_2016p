#ifndef SECURITY_FACTORY
#define SECURITY_FACTORY

#include <AbsSecurity.hpp>
#include <memory>
#include <string>

class SecurityFactory
{
  public:
    
    SecurityFactory() {};
    
    std::unique_ptr<AbsSecurity> build_security(const std::string & sec_id);
};


#endif