#include <Config.hpp>

using namespace std;

Config & Config::instance()
{
    static Config obj;
    return obj;
}

void Config::set_setting(
    const string & key,
    const string & value
    )
{
    _settings[key] = value;
}

string Config::get_setting(
    const string & key
    ) const
{
    return _settings.at(key);
}
