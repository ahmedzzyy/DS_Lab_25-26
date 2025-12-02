#include <stdio.h>

#define LENGTH 5
#define NAME_SIZE 50

struct Student
{
    char name[NAME_SIZE];
    int roll;
    int grade;
};

void readStudent(struct Student[]);
void displayStudent(struct Student[]);
void displayStudents(struct Student[]);
void sortStudents(struct Student[]);

int main()
{
    struct Student students[10];
    int i;
    while (1)
    {
        printf("\nHere are the operations you can perform with their respective option numbers:\n");
        printf("1 : Read all student objects\n");
        printf("2 : Display student according to roll\n");
        printf("3 : Display all students\n");
        printf("4 : Sort all students\n");
        printf("0 : Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &i);

        switch (i)
        {
        case 0:
            printf("\nThank you!");
            return 0;
            break;

        case 1:
            readStudent(students);
            break;

        case 2:
            displayStudent(students);
            break;

        case 3:
            displayStudents(students);
            break;

        case 4:
            sortStudents(students);
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void readStudent(struct Student student[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        printf("\n");
        printf("Enter the roll no.: ");
        scanf("%d", &student[i].roll);
        printf("Enter name: ");
        scanf("%s", student[i].name);
        printf("Enter grade: ");
        scanf("%d", &student[i].grade);
    }
}

void displayStudent(struct Student student[])
{
    int i, roll;
    printf("Enter the roll no.: ");
    scanf("%d", &roll);

    for (i = 0; i < LENGTH; i++)
    {
        if (roll == student[i].roll)
        {
            printf("\nRoll No. : %d\n", student[i].roll);
            printf("Name     : %s\n", student[i].name);
            printf("Grade    : %d\n", student[i].grade);
            break;
        }
    }
    if (i == LENGTH)
    {
        printf("No such student.");
    }
}

void displayStudents(struct Student student[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        printf("\nRoll No. : %d\n", student[i].roll);
        printf("Name     : %s\n", student[i].name);
        printf("Grade    : %d\n", student[i].grade);
    }
}

void sortStudents(struct Student student[])
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        for (int j = 0; j < LENGTH - i - 1; j++)
        {
            if (student[j].roll > student[j + 1].roll)
            {
                struct Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by roll number.\n");
}