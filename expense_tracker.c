
#include <stdio.h>

#define MAX 100

int main(void) {
    char categories[4][20] = {
        "Food", "Travel", "Education", "Other"
    };
    float expenses[MAX], total = 0;
    int choice, count = 0, i, category[MAX];
    int highest = 0;

    while (count < MAX) {
        printf("\n1. Add expense\n");
        printf("2. View report\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        if (choice == 1) {
            printf("Amount (INR): ");
            if (scanf("%f", &expenses[count]) != 1 ||
                expenses[count] <= 0) {
                printf("Invalid amount.\n");
                return 1;
            }

            printf("Category: 0-Food 1-Travel "
                   "2-Education 3-Other: ");
            if (scanf("%d", &category[count]) != 1 ||
                category[count] < 0 ||
                category[count] > 3) {
                printf("Invalid category.\n");
                return 1;
            }

            total += expenses[count];

            if (expenses[count] > expenses[highest])
                highest = count;

            count++;
            printf("Expense added successfully!\n");
        }
        else if (choice == 2) {
            printf("\n===== EXPENSE REPORT =====\n");

            for (i = 0; i < count; i++) {
                printf("%d. %-10s Rs. %.2f\n",
                       i + 1, categories[category[i]],
                       expenses[i]);
            }

            printf("Total spent: Rs. %.2f\n", total);

            if (count > 0) {
                printf("Average expense: Rs. %.2f\n",
                       total / count);
                printf("Highest expense: Rs. %.2f\n",
                       expenses[highest]);
            } else {
                printf("No expenses recorded yet.\n");
            }
        }
        else if (choice == 3) {
            printf("Thank you for using Expense Tracker!\n");
            break;
        }
        else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
