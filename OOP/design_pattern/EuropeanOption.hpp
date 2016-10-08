#ifndef EUROPEAN_OPTION
#define EUROPEAN_OPTION

#include <string>
#include <AbsSecurity.hpp>

static const double UNDEF = -987654321.0;

class EuropeanOption : public AbsSecurity
{
  public:
    
    enum OptionType {Call, Put};
    
    class Builder
    {
      public:
      
        Builder() : 
            _type(Call), 
            _S(UNDEF), 
            _K(UNDEF), 
            _r(UNDEF), 
            _T(UNDEF), 
            _sigma(UNDEF) 
            {};
        
        Builder & setType(const OptionType type) { _type = type; return *this; }
        
        Builder & setS(const double S) { _S = S; return *this; }
        
        Builder & setK(const double K) { _K = K; return *this; }
        
        Builder & setR(const double r) { _r = r; return *this; }
        
        Builder & setT(const double T) { _T = T; return *this; }
        
        Builder & setSigma(const double sigma) { _sigma = sigma; return *this; }
        
        bool is_valid() const;
        
        EuropeanOption build() const;
        
      private:
      
        OptionType _type;
    
        double _S;

        double _K;

        double _r;

        double _T;

        double _sigma;
    };
    
    EuropeanOption(
        const OptionType type,
        const double S,
        const double K,
        const double r,
        const double T
        ) : 
        _type(type), 
        _S(S),
        _K(K),
        _r(r),
        _T(T),
        _sigma(UNDEF),
        _price(UNDEF)
        {};
    
    EuropeanOption(
        const OptionType type,
        const double S,
        const double K,
        const double r,
        const double T,
        const double sigma
        );
    
    virtual double price() const;
    
    double delta() const;
    
    double d_one() const;
    
    double d_two() const;
    
    double calc_imp_vol(const double price) const;
    
    virtual std::string repr() const;
    
  private:
  
    OptionType _type;
    
    double _S;
    
    double _K;
    
    double _r;
    
    double _T;
    
    double _sigma;
    
    double _price;    
};


#endif