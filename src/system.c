#include <stdio.h>
#include <string.h>
#include "system.h"
// data storage
struct Student students[500];
struct Course courses[500];
struct Enrollment enrollments[1000];
struct SemesterRecord records[2000];
// counters
int studentCount = 0;
int courseCount = 0;
int enrollmentCount = 0;
int recordCount = 0;
// convert marks to grade point
float gp(float m) {
    if (m >= 90) return 4.0;
    if (m >= 80) return 3.0;
    if (m >= 70) return 2.0;
    if (m >= 60) return 1.0;
    return 0.0;
}
// find student index
int findStudentIndex(int id) {
    int i;
    for (i = 0; i < studentCount; i++)
        if (students[i].studentID == id) return i;
    return -1;
}
// check student exists
int studentExists(int id) {
    return findStudentIndex(id) != -1;
}
// check course exists
int courseExists(char code[]) {
    int i;
    for (i = 0; i < courseCount; i++)
        if (strcmp(courses[i].courseCode, code) == 0) return 1;
    return 0;
}
// prevent duplicate enrollment
int alreadyEnrolled(int id, char code[]) {
    int i;
    for (i = 0; i < enrollmentCount; i++)
        if (enrollments[i].studentID == id &&
            strcmp(enrollments[i].courseCode, code) == 0)
            return 1;
    return 0;
}
// register student
void registerStudent() {
    struct Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.studentID);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Department: ");
    scanf(" %[^\n]", s.department);
    s.CumulativeGradePoint = 0.0;
    students[studentCount++] = s;
    printf("Student successfully registered.\n");
}
// view all students
void viewStudents() {
    int i;
    if (studentCount == 0) {
        printf("No students registered.\n");
        return;
    }
    for (i = 0; i < studentCount; i++)
        printf("%d - %s (%s)\n",
               students[i].studentID,
               students[i].name,
               students[i].department);
}
// search student by id
void searchStudentByID() {
    int id, i;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("ID: %d\n", students[i].studentID);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("CGPA: %.2f\n", students[i].CumulativeGradePoint);
            return;
        }
    }
    printf("Student not found.\n");
}
// delete student and related data
void deleteStudent() {
    int id, i, j;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            for (j = i; j < studentCount - 1; j++)
                students[j] = students[j + 1];
            studentCount--;
            i = 0;
            while (i < enrollmentCount) {
                if (enrollments[i].studentID == id) {
                    for (j = i; j < enrollmentCount - 1; j++)
                        enrollments[j] = enrollments[j + 1];
                    enrollmentCount--;
                } else i++;
            }
            i = 0;
            while (i < recordCount) {
                if (records[i].studentID == id) {
                    for (j = i; j < recordCount - 1; j++)
                        records[j] = records[j + 1];
                    recordCount--;
                } else i++;
            }
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
// register course
void registerCourse() {
    struct Course c;
    printf("Enter Course Code: ");
    scanf("%s", c.courseCode);
    printf("Enter Course Title: ");
    scanf(" %[^\n]", c.title);
    printf("Enter Instructor Name: ");
    scanf(" %[^\n]", c.instructor);
    courses[courseCount++] = c;
    printf("Course registered successfully.\n");
}
// view all courses
void viewCourses() {
    int i;
    if (courseCount == 0) {
        printf("No courses registered.\n");
        return;
    }
    for (i = 0; i < courseCount; i++)
        printf("%s - %s\n",
               courses[i].courseCode,
               courses[i].title);
}
// delete course and related data
void deleteCourse() {
    char code[10];
    int i, j;
    printf("Enter Course Code to delete: ");
    scanf("%s", code);
    for (i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].courseCode, code) == 0) {
            for (j = i; j < courseCount - 1; j++)
                courses[j] = courses[j + 1];
            courseCount--;
            i = 0;
            while (i < enrollmentCount) {
                if (strcmp(enrollments[i].courseCode, code) == 0) {
                    for (j = i; j < enrollmentCount - 1; j++)
                        enrollments[j] = enrollments[j + 1];
                    enrollmentCount--;
                } else i++;
            }
            i = 0;
            while (i < recordCount) {
                if (strcmp(records[i].courseCode, code) == 0) {
                    for (j = i; j < recordCount - 1; j++)
                        records[j] = records[j + 1];
                    recordCount--;
                } else i++;
            }
            printf("Course deleted successfully.\n");
            return;
        }
    }
    printf("Course not found.\n");
}
// enroll student
void enrollStudent() {
    int id;
    char code[10];
    printf("Enter Student ID: ");
    scanf("%d", &id);
    printf("Enter Course Code: ");
    scanf("%s", code);
    if (!studentExists(id)) {
        printf("Student not found.\n");
        return;
    }
    if (!courseExists(code)) {
        printf("Course not found.\n");
        return;
    }
    if (alreadyEnrolled(id, code)) {
        printf("Duplicate enrollment.\n");
        return;
    }
    enrollments[enrollmentCount].studentID = id;
    strcpy(enrollments[enrollmentCount].courseCode, code);
    enrollmentCount++;
    printf("Enrollment successful.\n");
}
// add marks
void addMarks() {
    struct SemesterRecord r;
    printf("Enter Student ID: ");
    scanf("%d", &r.studentID);
    printf("Enter Semester Number: ");
    scanf("%d", &r.semesterNumber);
    printf("Enter Course Code: ");
    scanf("%s", r.courseCode);
    printf("Enter Marks: ");
    scanf("%f", &r.marks);
    records[recordCount++] = r;
    printf("Marks added successfully.\n");
}
// update marks
void updateMarks() {
    int id, sem, i;
    char code[10];
    float m;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    printf("Enter Semester Number: ");
    scanf("%d", &sem);
    printf("Enter Course Code: ");
    scanf("%s", code);
    printf("Enter New Marks: ");
    scanf("%f", &m);
    for (i = 0; i < recordCount; i++) {
        if (records[i].studentID == id &&
            records[i].semesterNumber == sem &&
            strcmp(records[i].courseCode, code) == 0) {
            records[i].marks = m;
            printf("Marks updated successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}
// view transcript and calculate gpa
void viewTranscript() {
    int id, i, j;
    float totalgp = 0;
    int totalcourses = 0;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++)
        if (students[i].studentID == id)
            printf("Transcript for Student %d - %s\n", id, students[i].name);
    for (i = 1; i <= 10; i++) {
        float sgpa = 0;
        int count = 0;
        for (j = 0; j < recordCount; j++) {
            if (records[j].studentID == id &&
                records[j].semesterNumber == i) {
                printf("%s - %.0f (%.1f)\n",
                       records[j].courseCode,
                       records[j].marks,
                       gp(records[j].marks));
                sgpa += gp(records[j].marks);
                count++;
                totalgp += gp(records[j].marks);
                totalcourses++;
            }
        }
        if (count > 0)
            printf("Semester SGPA: %.2f\n", sgpa / count);
    }
    if (totalcourses > 0)
        printf("Overall CGPA: %.2f\n", totalgp / totalcourses);
}
// save files
void saveData() {
    int i;
    FILE *f;
    f = fopen("students.txt", "w");
    for (i = 0; i < studentCount; i++)
        fprintf(f, "%d,%s,%s,%.2f\n",
                students[i].studentID,
                students[i].name,
                students[i].department,
                students[i].CumulativeGradePoint);
    fclose(f);
    f = fopen("courses.txt", "w");
    for (i = 0; i < courseCount; i++)
        fprintf(f, "%s,%s,%s\n",
                courses[i].courseCode,
                courses[i].title,
                courses[i].instructor);
    fclose(f);
    f = fopen("enrollments.txt", "w");
    for (i = 0; i < enrollmentCount; i++)
        fprintf(f, "%d,%s\n",
                enrollments[i].studentID,
                enrollments[i].courseCode);
    fclose(f);
    f = fopen("semestermarks.txt", "w");
    for (i = 0; i < recordCount; i++)
        fprintf(f, "%d,%d,%s,%.2f\n",
                records[i].studentID,
                records[i].semesterNumber,
                records[i].courseCode,
                records[i].marks);
    fclose(f);
    printf("Data saved successfully.\n");
}
// load files
void loadData() {
    FILE *f;
    studentCount = courseCount = enrollmentCount = recordCount = 0;
    f = fopen("students.txt", "r");
    while (f && fscanf(f, "%d,%49[^,],%49[^,],%f",
           &students[studentCount].studentID,
           students[studentCount].name,
           students[studentCount].department,
           &students[studentCount].CumulativeGradePoint) == 4)
        studentCount++;
    if (f) fclose(f);
    f = fopen("courses.txt", "r");
    while (f && fscanf(f, "%9[^,],%49[^,],%49[^\n]",
           courses[courseCount].courseCode,
           courses[courseCount].title,
           courses[courseCount].instructor) == 3)
        courseCount++;
    if (f) fclose(f);
    f = fopen("enrollments.txt", "r");
    while (f && fscanf(f, "%d,%9[^\n]",
           &enrollments[enrollmentCount].studentID,
           enrollments[enrollmentCount].courseCode) == 2)
        enrollmentCount++;
    if (f) fclose(f);
    f = fopen("semestermarks.txt", "r");
    while (f && fscanf(f, "%d,%d,%9[^,],%f",
           &records[recordCount].studentID,
           &records[recordCount].semesterNumber,
           records[recordCount].courseCode,
           &records[recordCount].marks) == 4)
        recordCount++;
    if (f) fclose(f);
    printf("Data loaded successfully.\n");
}
// advanced search with and logic
void searchRecords() {
    char sname[50], cname[50];
    float g;
    int i;
    printf("Enter student name (or '-' to skip): ");
    scanf(" %[^\n]", sname);
    printf("Enter course name (or '-' to skip): ");
    scanf(" %[^\n]", cname);
    printf("Enter grade point (or -1 to skip): ");
    scanf("%f", &g);
    for (i = 0; i < recordCount; i++) {
        int ok1 = 1, ok2 = 1, ok3 = 1;
        float grade = gp(records[i].marks);
        if (strcmp(sname, "-") != 0)
            ok1 = strstr(students[findStudentIndex(records[i].studentID)].name, sname) != NULL;
        if (strcmp(cname, "-") != 0)
            ok2 = strcmp(records[i].courseCode, cname) == 0;
        if (g != -1)
            ok3 = grade == g;
        if (ok1 && ok2 && ok3) {
            printf("Student: %s\n",
                   students[findStudentIndex(records[i].studentID)].name);
            printf("Course: %s\n", records[i].courseCode);
            printf("Marks: %.0f Grade: %.1f\n", records[i].marks, grade);
            printf("---------------------------------------\n");
        }
    }
}
