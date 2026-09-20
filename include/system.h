#ifndef SYSTEM_H
#define SYSTEM_H
// student info
struct Student {
    int studentID;
    char name[50];
    char department[50];
    float CumulativeGradePoint;
};
// course info
struct Course {
    char courseCode[10];
    char title[50];
    char instructor[50];
};
// enrollment info
struct Enrollment {
    int studentID;
    char courseCode[10];
};
// semester marks
struct SemesterRecord {
    int studentID;
    int semesterNumber;
    char courseCode[10];
    float marks;
};
// function prototypes
void registerStudent();
void viewStudents();
void searchStudentByID();
void deleteStudent();
void registerCourse();
void viewCourses();
void deleteCourse();
void enrollStudent();
void addMarks();
void updateMarks();
void viewTranscript();
void saveData();
void loadData();
void searchRecords();
void menu();
#endif
