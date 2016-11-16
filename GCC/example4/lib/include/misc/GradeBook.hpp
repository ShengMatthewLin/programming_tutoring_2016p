#include <map>
#include <string>

class GradeBook
{
  public:
    GradeBook() : _grades() { }

    void add_grade(const std::string & subject, const int grade);

    int get_total_grade() const;

  private:

    std::map<std::string, int> _grades;
};
