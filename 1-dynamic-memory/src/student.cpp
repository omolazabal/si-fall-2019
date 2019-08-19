
#include "student.h"

Student::Student() : cwid(-1) {}

Student::Student(string fname, string lname, int id) : 
    cwid(id), student_fname(fname), student_lname(lname) {}

void Student::set_cwid(int id) {
    cwid = id;
}

void Student::set_fname(string fname) {
    student_fname = fname;
}

void Student::set_lname(string lname) {
    student_lname = lname;
}

int Student::get_cwid() const {
    return cwid;
}

string Student::get_fname() const {
    return student_fname;
}

string Student::get_lname() const {
    return student_lname;

}

bool operator==(const Student &lhs, const Student &rhs) {
    return (lhs.cwid == rhs.cwid &&
            lhs.student_fname == rhs.student_fname &&
            lhs.student_lname == rhs.student_lname);
}

