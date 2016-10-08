#include <string>

static const double UNDEF = -987654321.0;

class EuropeanOption
{
  public:
    
    enum OptionType {Call, Put};
    
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
    
    double price() const;
    
    double delta() const;
    
    double d_one() const;
    
    double d_two() const;
    
    double calc_imp_vol(const double price) const;
    
  private:
  
    OptionType _type;
    
    double _S;
    
    double _K;
    
    double _r;
    
    double _T;
    
    double _sigma;
    
    double _price;    
};
