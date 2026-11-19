#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char description[MAX][50];
    char categoryNames[4][20] = {
        "Food", "Travel", "Books", "Entertainment"
    };

    int category[MAX], month[MAX], year[MAX];
    float amount[MAX];

    int count = 0;
    int choice, i, j;
    int m, y, c, n;

    float budget = 0;
    int budgetMonth = 0, budgetYear = 0;
    int budgetSet = 0;

    do
    {
        printf("\n===== STUDENT EXPENSE TRACKER =====\n");
        printf("1. Set Monthly Budget\n");
        printf("2. Add Expense\n");
        printf("3. View All Expenses\n");
        printf("4. Total Expenses\n");
        printf("5. Category Report\n");
        printf("6. Check Remaining Budget\n");
        printf("7. Monthly Report\n");
        printf("8. Edit Expense\n");
        printf("9. Delete Expense\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            // SET BUDGET
            case 1:
                printf("Enter month (1-12): ");
                scanf("%d", &budgetMonth);

                printf("Enter year: ");
                scanf("%d", &budgetYear);

                printf("Enter budget: Rs. ");
                scanf("%f", &budget);

                if(budgetMonth < 1 || budgetMonth > 12 ||
                   budgetYear < 2000 || budgetYear > 2100 ||
                   budget <= 0)
                {
                    printf("Invalid details!\n");
                    budgetSet = 0;
                }
                else
                {
                    budgetSet = 1;
                    printf("Budget saved successfully!\n");
                }
                break;


            // ADD EXPENSE
            case 2:
                if(count >= MAX)
                {
                    printf("Storage full!\n");
                    break;
                }

                printf("Enter description: ");
                scanf(" %49[^\n]", description[count]);

                printf("Enter month: ");
                scanf("%d", &month[count]);

                printf("Enter year: ");
                scanf("%d", &year[count]);

                printf("\nCategories:\n");
                for(i = 0; i < 4; i++)
                    printf("%d. %s\n", i + 1, categoryNames[i]);

                printf("Choose category: ");
                scanf("%d", &c);

                printf("Enter amount: Rs. ");
                scanf("%f", &amount[count]);

                if(month[count] < 1 || month[count] > 12 ||
                   year[count] < 2000 || year[count] > 2100 ||
                   c < 1 || c > 4 || amount[count] <= 0)
                {
                    printf("Invalid expense details!\n");
                }
                else
                {
                    category[count] = c - 1;
                    count++;
                    printf("Expense added successfully!\n");
                }
                break;


            // VIEW ALL
            case 3:
                if(count == 0)
                {
                    printf("No expenses recorded.\n");
                    break;
                }

                printf("\n===== ALL EXPENSES =====\n");

                for(i = 0; i < count; i++)
                {
                    printf("\nExpense %d\n", i + 1);
                    printf("Description: %s\n", description[i]);
                    printf("Date: %02d/%d\n", month[i], year[i]);
                    printf("Category: %s\n",
                           categoryNames[category[i]]);
                    printf("Amount: Rs. %.2f\n", amount[i]);
                }
                break;


            // TOTAL EXPENSE
            case 4:
            {
                float total = 0;

                for(i = 0; i < count; i++)
                    total += amount[i];

                printf("Total Expenses: Rs. %.2f\n", total);
                break;
            }


            // CATEGORY REPORT
            case 5:
            {
                float total[4] = {0, 0, 0, 0};
                int highest = 0;

                if(count == 0)
                {
                    printf("No expenses recorded.\n");
                    break;
                }

                for(i = 0; i < count; i++)
                    total[category[i]] += amount[i];

                printf("\n===== CATEGORY REPORT =====\n");

                for(i = 0; i < 4; i++)
                {
                    printf("%s: Rs. %.2f\n",
                           categoryNames[i], total[i]);

                    if(total[i] > total[highest])
                        highest = i;
                }

                printf("Highest Spending Category: %s\n",
                       categoryNames[highest]);
                break;
            }


            // REMAINING BUDGET
            case 6:
            {
                float spent = 0;

                if(!budgetSet)
                {
                    printf("Set monthly budget first!\n");
                    break;
                }

                for(i = 0; i < count; i++)
                {
                    if(month[i] == budgetMonth &&
                       year[i] == budgetYear)
                    {
                        spent += amount[i];
                    }
                }

                printf("Budget: Rs. %.2f\n", budget);
                printf("Spent: Rs. %.2f\n", spent);

                if(spent > budget)
                    printf("Budget exceeded by Rs. %.2f\n",
                           spent - budget);
                else
                    printf("Remaining: Rs. %.2f\n",
                           budget - spent);

                break;
            }


            // MONTHLY REPORT
            case 7:
            {
                float total = 0;
                float catTotal[4] = {0, 0, 0, 0};
                int highest = 0;

                printf("Enter month: ");
                scanf("%d", &m);

                printf("Enter year: ");
                scanf("%d", &y);

                for(i = 0; i < count; i++)
                {
                    if(month[i] == m && year[i] == y)
                    {
                        total += amount[i];
                        catTotal[category[i]] += amount[i];
                    }
                }

                printf("\n===== MONTHLY REPORT =====\n");

                for(i = 0; i < 4; i++)
                {
                    printf("%s: Rs. %.2f\n",
                           categoryNames[i], catTotal[i]);

                    if(catTotal[i] > catTotal[highest])
                        highest = i;
                }

                printf("Monthly Total: Rs. %.2f\n", total);

                if(total > 0)
                    printf("Highest Category: %s\n",
                           categoryNames[highest]);

                if(budgetSet &&
                   m == budgetMonth &&
                   y == budgetYear)
                {
                    if(total > budget)
                        printf("Budget exceeded by Rs. %.2f\n",
                               total - budget);
                    else
                        printf("Remaining Budget: Rs. %.2f\n",
                               budget - total);
                }

                break;
            }


            // EDIT EXPENSE
            case 8:
                if(count == 0)
                {
                    printf("No expenses to edit.\n");
                    break;
                }

                for(i = 0; i < count; i++)
                    printf("%d. %s - Rs. %.2f\n",
                           i + 1, description[i], amount[i]);

                printf("Enter expense number: ");
                scanf("%d", &n);

                if(n < 1 || n > count)
                {
                    printf("Invalid expense number!\n");
                    break;
                }

                i = n - 1;

                printf("Enter new description: ");
                scanf(" %49[^\n]", description[i]);

                printf("Enter new month: ");
                scanf("%d", &month[i]);

                printf("Enter new year: ");
                scanf("%d", &year[i]);

                printf("Enter category (1-4): ");
                scanf("%d", &c);
                category[i] = c - 1;

                printf("Enter new amount: Rs. ");
                scanf("%f", &amount[i]);

                printf("Expense updated successfully!\n");
                break;


            // DELETE EXPENSE
            case 9:
                if(count == 0)
                {
                    printf("No expenses to delete.\n");
                    break;
                }

                for(i = 0; i < count; i++)
                    printf("%d. %s - Rs. %.2f\n",
                           i + 1, description[i], amount[i]);

                printf("Enter expense number to delete: ");
                scanf("%d", &n);

                if(n < 1 || n > count)
                {
                    printf("Invalid expense number!\n");
                    break;
                }

                i = n - 1;

                for(j = i; j < count - 1; j++)
                {
                    strcpy(description[j], description[j + 1]);
                    category[j] = category[j + 1];
                    month[j] = month[j + 1];
                    year[j] = year[j + 1];
                    amount[j] = amount[j + 1];
                }

                count--;

                printf("Expense deleted successfully!\n");
                break;


            case 10:
                printf("Thank you!\n");
                break;


            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 10);

    return 0;
}
