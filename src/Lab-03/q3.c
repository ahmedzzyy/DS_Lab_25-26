#include <stdio.h>

#define NAME_SIZE 50

struct Student
{
    char name[NAME_SIZE];
    int roll_no;
    float marks;
};

void readStudent(struct Student *student);

void displayStudents(struct Student *students, int n);

void displayTopStudent(struct Student *students, int n);

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++)
    {
        printf("--- Student %d ---\n", i + 1);
        readStudent(&students[i]);
        printf("--- End ---\n");
    }
    displayStudents(students, n);
    displayTopStudent(students, n);

    return 0;
}

void readStudent(struct Student *student)
{
    printf("Enter details for student:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Roll No: ");
    scanf("%d", &student->roll_no);
    printf("Marks: ");
    scanf("%f", &student->marks);
}

void displayStudents(struct Student *students, int n)
{
    printf("\nStudent Details:\n");

    for (int i = 0; i < n; i++)
    {
        printf("--- Student %d ---\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--- End ---\n");
    }
}

void displayTopStudent(struct Student *students, int n)
{
    struct Student *topStudent = &students[0];
    for (int i = 1; i < n; i++)
    {
        if (students[i].marks > topStudent->marks)
        {
            topStudent = &students[i];
        }
    }

    printf("\n---Top Student ---\n");
    printf("Name: %s\n", topStudent->name);
    printf("Roll No: %d\n", topStudent->roll_no);
    printf("Marks: %.2f\n", topStudent->marks);
    printf("--- End ---\n");
}