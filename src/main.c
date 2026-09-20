
#include <stdio.h>
#include "system.h"

void menu(void) {
    int choice;
    do {
        printf("\nStudent Registration and Grade Management System\n");
        printf("1. Register Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student\n");
        printf("5. Register Course\n");
        printf("6. View All Courses\n");
        printf("7. Delete Course\n");
        printf("8. Enroll Student\n");
        printf("9. Add Marks\n");
        printf("10. Update Marks\n");
        printf("11. View Transcript\n");
        printf("12. Search Records\n");
        printf("13. Save Data\n");
        printf("14. Load Data\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: deleteStudent(); break;
            case 5: registerCourse(); break;
            case 6: viewCourses(); break;
            case 7: deleteCourse(); break;
            case 8: enrollStudent(); break;
            case 9: addMarks(); break;
            case 10: updateMarks(); break;
            case 11: viewTranscript(); break;
            case 12: searchRecords(); break;
            case 13: saveData(); break;
            case 14: loadData(); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

int main(void) {
    menu();
    return 0;
}
