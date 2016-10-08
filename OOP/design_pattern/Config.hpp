#ifndef CONFIG
#define CONFIG

#include <map>
#include <string>

class Config
{
  public:

    static Config & instance();

    void set_setting(const std::string & key, const std::string & value);

    std::string get_setting(const std::string & key) const;

  private:

    Config() {;}

    std::map<std::string, std::string> _settings;
    
};

#endif
