#include <stdio.h>

int main()
{
    char str[20], extra[20], copy[20];
    int in, i, len, j;

    printf("Enter the string on which you want to perform your operations : ");
    scanf("%s", str);

    while (1)
    {
        printf("\nHere are the operations you can perform with their respective option numbers:\n");
        printf("1 : Length of the string\n");
        printf("2 : String concatenation\n");
        printf("3 : String comparison\n");
        printf("4 : To insert a sub string\n");
        printf("5 : To delete a substring\n");
        printf("0 : Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &in);

        switch (in)
        {
        case 0:
            printf("\nThank you!");
            return 0;
            break;

        case 1:
            for (in = 0; str[in] != '\0'; in++)
            {
                continue;
            }
            printf("The length of the string is : %d\n", in);
            break;

        case 2:
            printf("Enter the string with which you like to concatenate : ");
            scanf("%s", extra);
            for (in = 0; str[in] != '\0'; in++)
            {
                continue;
            }
            for (i = 0; extra[i] != '\0'; i++)
            {
                str[in] = extra[i];
                in++;
            }
            str[in] = '\0';
            printf("The new string is : %s\n", str);
            break;

        case 3:
            printf("Enter the string with which you like to compare : ");
            scanf("%s", extra);

            i = 1; // Flag for equal

            for (in = 0; (str[in] != '\0') && extra[in] != '\0'; in++)
            {
                if (str[in] != extra[in])
                {
                    i--;
                    break;
                }
                else if (str[in + 1] != '\0' && extra[in + 1] == '\0')
                {
                    i--;
                    break;
                }
                else if (str[in + 1] == '\0' && extra[in + 1] != '\0')
                {
                    i--;
                    break;
                }
            }

            if (i)
            {
                printf("Both the strings are equal.");
            }
            else
            {
                printf("The strings are not equal.");
            }
            break;

        case 4:
            printf("Enter the substring you like to add : ");
            scanf("%s", extra);
            printf("Enter the position at which you would like to add : ");
            scanf("%d", &in);
            for (len = 0; extra[len] != '\0'; len++)
            {
                continue;
            }
            j = 0;
            in--;
            for (i = in; i < (in + len); i++)
            {
                str[i + len] = str[i];
                str[i] = extra[j];
                j++;
            }

            printf("The new string is : %s\n", str);
            break;

        case 5:
            printf("Enter the substring you like to remove : ");
            scanf("%s", extra);
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}