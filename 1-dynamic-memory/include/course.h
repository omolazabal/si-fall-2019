
#ifndef COURSE_H
#define COURSE_H

#include "student.h"

using namespace std;

class Course {
private:
    size_t num_students,
           max_students;
    int professor_cwid,
        class_num;
    Student *students;

public:
    Course();
    Course(size_t max);
    ~Course();

    Student get_student(size_t index) const;
    void enroll_student(const Student &student);

    // Mutators
    void set_class_number(int num);
    void set_professor_cwid(int id);

    // Accessors
    int get_class_number() const;
    size_t get_max_students() const;
    size_t get_num_students() const;
    int get_professor_cwid() const;
};

#endif
