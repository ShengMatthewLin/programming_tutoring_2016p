#include "misc/GradeBook.hpp"

using namespace std;

void GradeBook::add_grade(
    const string & subject,
    const int grade
    )
{
    _grades[subject] = grade;
}

int GradeBook::get_total_grade() const
{
    int total_grade = 0;
    for (auto iter = _grades.begin(); iter != _grades.end(); ++iter)
    {
        total_grade += iter->second;
    }
    return total_grade;
}
