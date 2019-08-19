
#include "gtest/gtest.h"
#include "student.h"
#include "course.h"

TEST(Dynamic_Memory, Constructor) {
    const int MAX_STUDENT_TEST = 30;
    Course course(MAX_STUDENT_TEST);

    int max_students = course.get_max_students();

    EXPECT_EQ(max_students, MAX_STUDENT_TEST);
}

TEST(Dynamic_Memory, Enroll_Student) {
    Course course;
    Student student1_test("Oscar", "Olazabal", 19382);
    Student student2_test("Bob", "Ross", 82740);
    const size_t NUM_STUDENT_TEST = 2;

    course.enroll_student(student1_test);
    course.enroll_student(student2_test);

    EXPECT_EQ(course.get_num_students(), NUM_STUDENT_TEST);
}

TEST(Dynamic_Memory, Get_Student) {
    Course course;
    Student student1_test("Oscar", "Olazabal", 19382);
    Student student2_test("Bob", "Ross", 82740);

    course.enroll_student(student1_test);
    course.enroll_student(student2_test);

    EXPECT_EQ(course.get_student(0), student1_test);
    EXPECT_EQ(course.get_student(1), student2_test);
}

