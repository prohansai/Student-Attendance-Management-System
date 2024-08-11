#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[50];
    int rollNumber;
    int classesPresent;
    int totalClasses;
} Student;
int main() {
    int numStudents,i;
    printf("Enter number of students in the class: ");
    scanf("%d", &numStudents);

    
    Student *students = calloc(numStudents, sizeof(Student));
    if (students == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }
    for (i = 0; i < numStudents; i++) {
        printf("\nEnter the details for student %d:\n", i+1);
        printf("Name: \n");
        scanf("%s", students[i].name);
        printf("Roll Number: \n ");
        scanf("%d", &students[i].rollNumber);
        students[i].classesPresent = 0;
        students[i].totalClasses = 0;
    }

    
    int choice;
    do {
        printf("\n**Menu**\n");
        printf("1. Take attendance\n");
        printf("2. Display attendance for a student\n");
        printf("3. Display students with attendance less than 75%%\n");
        printf("4. Add a student\n");
        printf("5. Remove a student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { printf(" ** TAKING ATTENDANCE**\n");
                int numDays;
                printf("Enter number of days to take attendance for: ");
                scanf("%d", &numDays);

                for (int day = 1; day <= numDays; day++) {
                    printf("Enter attendance for day %d:\n", day);

                    for (int i = 0; i < numStudents; i++) {
                        printf("Enter attendance for student %s:\n", students[i].name);

                        
                        int attendance;
                        do {
                            printf("Enter attendance (1=Present, 0=Absent): \n");
                            scanf("%d", &attendance);
                        } while (attendance != 0 && attendance != 1);

                        
                        students[i].totalClasses++;
                        if (attendance == 1) {
                            students[i].classesPresent++;
                        }
                    }
                }
                break;
            }

            case 2: {printf("**Displaying Attendance **\n");
                int rollNumber;
                printf("Enter roll number of the student: \n");
                scanf("%d", &rollNumber);

                
                int found = 0;
                for (int i = 0; i < numStudents; i++) {
                    if (students[i].rollNumber == rollNumber) {
                        found = 1;
                        printf("Attendance for %s (Roll number %d):\n",
                               students[i].name, students[i].rollNumber);
                        printf("Classes present: %d\n", students[i].classesPresent);
                        printf("Total classes held: %d\n", students[i].totalClasses);
                        printf("Attendance percentage: %.2f%%\n",
                               (float)students[i].classesPresent / students[i].totalClasses * 100);
                        break;
                    }
                }

                if (!found) {
                    printf("Error: No student with roll number %d found.\n", rollNumber);
                }
                break;
            }

            case 3: {
                printf("**STUDENTS WITH ATTENDANCE LESS THAN 75%%**\n");
                for (int i = 0; i < numStudents; i++) {
                    float attendancePercentage = (float)students[i].classesPresent / students[i].totalClasses * 100;
                    if (attendancePercentage < 75) {
                        printf("%s (Roll number %d):\n", students[i].name, students[i].rollNumber);
                        printf("Classes present: %d\n", students[i].classesPresent);
                        printf("Total classes held: %d\n",students[i].totalClasses);
        printf("Attendance percentage: %.2f%%\n\n", attendancePercentage);
                    }
                }
                break;
            }
            
case 4: 
    numStudents++;
    students = realloc(students, numStudents * sizeof(Student));
    printf("Enter name of student: ");
    scanf("%s", students[numStudents - 1].name);
    printf("Enter roll number of student: ");
    scanf("%d", &students[numStudents - 1].rollNumber);
    printf("Student added successfully\n");
    break;

case 5: // Remove a student
    if (numStudents == 0) {
        printf("No students in class\n");
        break;
    }
    printf("Enter roll number of student to be removed: ");
    int roll;
    scanf("%d", &roll);
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == roll) {
            found = 1;
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j+1];
            }
            numStudents--;
            students = realloc(students, numStudents * sizeof(Student));
            printf("Student removed successfully\n");
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found\n", roll);
    }
    break;
    

            case 6: {
                printf("EXITING PROGRAM...THANK YOU...\n");
                break;
            }

            default:
                printf("Error: INVALID CHOICE. PLEASE ENTER A Valid CHOICE.\n");
                break;
        }
    } while (choice != 6);

    
    free(students);

    return 0;
}
