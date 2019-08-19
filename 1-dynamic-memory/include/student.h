
#ifndef STUDENT_H
#define STUDENT_H

#include "string"

using namespace std;

class Student {
private:
    int cwid;
    string student_fname,
        student_lname;

public:
    // Contructors
    Student();
    Student(string fname, string lname, int id);

    // Mutators
    void set_cwid(int id);
    void set_fname(string fname);
    void set_lname(string lname);

    // Accessors
    int get_cwid () const;
    string get_fname () const;
    string get_lname () const;

    friend bool operator==(const Student &lhs, const Student &rhs);
};

#endif
