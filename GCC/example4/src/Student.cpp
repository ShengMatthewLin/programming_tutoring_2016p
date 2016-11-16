#include <sstream>
#include "Student.hpp"

using namespace std;

std::string Student::desc() const
{
    ostringstream oss;
    oss << "My name is " << _name << " and my age is " << _age;
    return oss.str();
}
