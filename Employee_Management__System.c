#include <stdio.h>
#include <stdlib.h>
struct employee
{
    char name[1001];
    int age;
    float salary;
    int id;
};
int main()
{
    int n;
    struct employee person[20], tmp;
    int choice;
    printf("\t\t\t\t\n\n****************EMPLOYEE MANAGEMENT SYSTEM*********************");
    printf("\n\nHow many employees do you want to start the company ::");
    scanf("%d", &n); // 5
    for (int i = 1; i <= n; i++)
    {
        printf("Enter Employee information for person ::%d\n", i);
        printf("Employee Name ::");
        scanf("%s", &person[i].name);
        printf("Employee Age::");
        scanf("%d", &person[i].age);
        printf("Employee Salary:: ");
        scanf("%f", &person[i].salary);
        printf("ID Number::");
        scanf("%d", &person[i].id);
    }
    while (1)
    {
        printf("\n\n1.Insert Employee Information.\n2.Delete Employee from office\n3.Sorted Employee information.\n4.Display information\n5.End\nPlease selete the option::");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
        {
            int position;
            printf("Enter position New employee join this company:: ");
            scanf("%d", &position);
            for (int i = n; i >= position; i--)
            {
                person[i + 1] = person[i];
            }
            printf("Employee Name::");
            scanf("%s", &person[position].name);
            printf("Employee age::");
            scanf("%d", &person[position].age);
            printf("Employee Salary:: ");
            scanf("%f", &person[position].salary);
            printf("ID Number::");
            scanf("%d", &person[position].id);
            n++;
        }
        break;
        case 2:
        {
            int index;
            printf("Which position do you want to delete an Employee::");

            scanf("%d", &index);
            printf("SL NO:\t\tEmployee Name:\t\tEmployee Age:\t\tEmployee Salary:\t\tID Nummber:");
            printf("\n%d", index);
            printf("\t\t%s\t\t\t%d\t\t\t%0.2f\t\t\t%d", person[index].name, person[index].age, person[index].salary, person[index].id);
            for (int i = index; i <= n; i++)
            {
                person[i] = person[i + 1];
            }
            n--;
            printf("\n\n%d position is deleted Successfully.",index);
        }
        break;

        case 3:
        {
            for (int i = 1; i <= n - 1; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (person[i].age > person[j].age)
                    {
                        tmp = person[i];
                        person[i] = person[j];
                        person[j] = tmp;
                    }
                }
            }
            printf("SL NO:\t\tEmployee Name:\t\tEmployee Age:\t\tEmployee Salary:\t\tID Number:");
            for (int i = 1; i <= n; i++)
            {
                printf("\n%d", i);
                printf("\t\t%s\t\t\t%d\t\t\t%0.2f\t\t\t%d", person[i].name, person[i].age, person[i].salary, person[i].id);
            }
        }
        break;
        case 4:
        {
            printf("SL NO:\t\tEmployee Name:\t\tEmployee Age:\t\tEmployee Salary:\t\tID Number:");
            for (int i = 1; i <= n; i++)
            {
                printf("\n%d", i);
                printf("\t\t%s\t\t\t%d\t\t\t%0.2f\t\t\t%d", person[i].name, person[i].age, person[i].salary, person[i].id);
            }
        }
        break;
        case 5:
        {
            printf("End the program !!\n\n\n");
            exit(0);
        }
        break;
        default:
            printf("Invalid option !!");
        }
    }

    return 0;
}
