#include <stdio.h>
#include <string.h>

typedef struct {
    int rollNumber;
    char name[50];
    char sex[10];
    float score;
} Student;

int count = 0;

void addStudent(Student s[], int size) {
    if (count >= size) {
        printf("Cannot add more students. Storage full.\n");
        return;
    }
    printf("Enter details for student %d:\n", count + 1);
    printf("Roll Number: ");
    scanf("%d", &s[count].rollNumber);
    printf("Name: ");
    scanf(" %[^\n]", s[count].name);
    printf("Sex: ");
    scanf("%s", s[count].sex);
    printf("Exam Score: ");
    scanf("%f", &s[count].score);
    count++;
    printf("Student added successfully!\n");
}

void viewStudents(Student s[]) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("\nAll Student Records:\n");
    printf("Roll\tName\t\tSex\tScore\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%-5s\t%.2f\n", s[i].rollNumber, s[i].name, s[i].sex, s[i].score);
    }
}

void showMaxScore(Student s[]) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].score > s[maxIndex].score) {
            maxIndex = i;
        }
    }
    printf("\nStudent with Maximum Score:\n");
    printf("Roll Number: %d\n", s[maxIndex].rollNumber);
    printf("Name: %s\n", s[maxIndex].name);
    printf("Sex: %s\n", s[maxIndex].sex);
    printf("Score: %.2f\n", s[maxIndex].score);
}

void showMinScore(Student s[]) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].score < s[minIndex].score) {
            minIndex = i;
        }
    }
    printf("\nStudent with Minimum Score:\n");
    printf("Roll Number: %d\n", s[minIndex].rollNumber);
    printf("Name: %s\n", s[minIndex].name);
    printf("Sex: %s\n", s[minIndex].sex);
    printf("Score: %.2f\n", s[minIndex].score);
}

int main() {
    Student s[5];
    int choice = 0;

    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Add student records\n");
        printf("2. View all student records\n");
        printf("3. Show student who gets the maximum score\n");
        printf("4. Show student who gets the minimum score\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(s, 5);
                break;
            case 2:
                viewStudents(s);
                break;
            case 3:
                showMaxScore(s);
                break;
            case 4:
                showMinScore(s);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
