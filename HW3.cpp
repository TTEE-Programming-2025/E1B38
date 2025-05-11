#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 9

char seats[SIZE][SIZE];

int main() {
    char password[10];
    int attempts = 0;
    char choice;

    srand(time(NULL)); // seed for random

    // Personal welcome screen (at least 20 lines)
    printf("*********************\n");
    printf("*   WELCOME USER    *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*  -------------    *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*   Enter Password  *\n");
    printf("*                   *\n");
    printf("* You have 3 tries  *\n");
    printf("*                   *\n");
    printf("*********************\n");
    printf("*                   *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*                   *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*                   *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*                   *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*                   *\n");
    printf("* I AM  E1B  38     *\n");
    printf("*                   *\n");
    printf("*********************\n");

    // Password verification
    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, "2025") == 0) {
            printf("Password correct! Welcome!\n");
            break;
        } else {
            printf("Wrong password!\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many attempts. Program ends.\n");
        return 0;
    }

    // Initialize seat map
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';

    // Randomly reserve 10 seats
    int count = 0;
    while (count < 10) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++;
        }
    }

    // Main menu
    while (1) {
        printf("\n");
        printf("----------[Booking System]----------\n");
        printf("|  a. Available seats              |\n");
        printf("|  b. Arrange for you              |\n");
        printf("|  c. Choose by yourself           |\n");
        printf("|  d. Exit                         |\n");
        printf("------------------------------------\n");

        printf("Select an option: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            // Option a: show seat layout
            printf(" \\123456789\n");
            for (int i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for (int j = 0; j < SIZE; j++) {
                    printf("%c", seats[i][j]);
                }
                printf("\n");
            }
            printf("Press any key to return to menu...\n");
            getchar();
            getchar();
        } else if (choice == 'b') {
            // Option b: auto arrange seats
            int n, found = 0;
            printf("How many seats do you need (1~4)? ");
            scanf("%d", &n);

            if (n < 1 || n > 4) {
                printf("Invalid number.\n");
                continue;
            }

            // Find n continuous available seats in a row
            for (int i = SIZE - 1; i >= 0 && !found; i--) {
                for (int j = 0; j <= SIZE - n; j++) {
                    int ok = 1;
                    for (int k = 0; k < n; k++) {
                        if (seats[i][j + k] != '-') {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) {
                        for (int k = 0; k < n; k++) {
                            seats[i][j + k] = '@';
                        }
                        found = 1;
                        break;
                    }
                }
            }

            if (!found) {
                printf("Sorry, no suitable seats found.\n");
                continue;
            }

            // Show suggestion
            printf(" \\123456789\n");
            for (int i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for (int j = 0; j < SIZE; j++) {
                    printf("%c", seats[i][j]);
                }
                printf("\n");
            }

            char confirm;
            printf("Do you accept these seats? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y') {
                // Confirm ¡÷ @ becomes *
                for (int i = 0; i < SIZE; i++)
                    for (int j = 0; j < SIZE; j++)
                        if (seats[i][j] == '@')
                            seats[i][j] = '*';
                printf("Seats confirmed.\n");
            } else {
                // Cancel ¡÷ @ becomes -
                for (int i = 0; i < SIZE; i++)
                    for (int j = 0; j < SIZE; j++)
                        if (seats[i][j] == '@')
                            seats[i][j] = '-';
                printf("Cancelled.\n");
            }
        } else if (choice == 'c') {
            // Option c: manual seat selection
            char input[100];
            int row, col;
            int valid = 1;

            // Clear previous @ marks
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    if (seats[i][j] == '@')
                        seats[i][j] = '-';

            printf("Enter seats (e.g. 2-3 3-5):\n");
            getchar();
            fgets(input, sizeof(input), stdin);

            char* token = strtok(input, " \n");
            while (token != NULL) {
                if (sscanf(token, "%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9) {
                    valid = 0;
                    break;
                }
                if (seats[row - 1][col - 1] == '*' || seats[row - 1][col - 1] == '@') {
                    valid = 0;
                    break;
                }
                seats[row - 1][col - 1] = '@';
                token = strtok(NULL, " \n");
            }

            if (!valid) {
                printf("Invalid format or seat already taken. Try again.\n");
                continue;
            }

            // Show seat result
            printf(" \\123456789\n");
            for (int i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for (int j = 0; j < SIZE; j++) {
                    printf("%c", seats[i][j]);
                }
                printf("\n");
            }

            printf("Press any key to confirm your seats...\n");
            getchar();

            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    if (seats[i][j] == '@')
                        seats[i][j] = '*';

            printf("Your seats are confirmed.\n");
        } else if (choice == 'd') {
            // Option d: exit
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}



