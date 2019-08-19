
#include "course.h"
#include "student.h"
#include <stdexcept>

using namespace std;

Course::Course() {
    // Initialize member variables.
    // By default, course will hold a max of 25 students.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========



    // ====================================================
}

Course::Course(size_t max) {
    // Very similar to default constructor, but parameter specifies max
    // number of students.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========



    // ====================================================
}

Course::~Course() {
    // Utilized to free allocated memory.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========



    // ====================================================
}

Student Course::get_student(size_t index) const {
    // Fetch student at specified index.
    // Utilize stdexcept to handle edge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    return Student();


    // ====================================================
}

void Course::enroll_student(const Student &student) {
    // Insert a new student
    // Utilize stdexcept to handle endge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========



    // ====================================================
}


void Course::set_class_number(int num) { 
    class_num = num;
}

void Course::set_professor_cwid(int id) {
    professor_cwid = id;
}

int Course::get_class_number() const {
    return class_num;
}

size_t Course::get_max_students() const {
    return max_students;
}

size_t Course::get_num_students() const {
    return num_students;
}

int Course::get_professor_cwid() const {
    return professor_cwid;
}

