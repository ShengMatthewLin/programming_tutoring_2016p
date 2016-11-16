#include <string>
#include "misc/GradeBook.hpp"

class Student
{
  public:

    Student(const std::string & name, const int age)
        : _name(name), _age(age)
        { }

    std::string desc() const;

    GradeBook& get_grade_book() {
        return _grade_book;
    }

private:

    std::string _name;
    int _age;
    GradeBook _grade_book;    
};
