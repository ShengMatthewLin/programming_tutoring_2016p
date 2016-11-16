#include <iostream>
#include "Student.hpp"

using namespace std;

int main()
{
    Student peter("Peter", 12);
    peter.get_grade_book().add_grade("English", 90);
    peter.get_grade_book().add_grade("Math", 92);
    cout << peter.desc() << endl;
    cout << "My total score is " << peter.get_grade_book().get_total_grade() << endl;
    return 0;
}
