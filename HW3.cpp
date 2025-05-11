#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 9

char seats[SIZE][SIZE];

void showMainMenu();
void generateSeats();
void displaySeats();
void arrangeSeats();

int main() {
    char password[10];
    int attempts = 0;
    char choice;

    srand(time(NULL));

    // Welcome screen (20+ lines)
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

    // Password check
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

    generateSeats();

    // Main menu loop
    while (1) {
        showMainMenu();
        printf("Select an option: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            displaySeats();
            printf("Press any key to return to menu...\n");
            getchar();
            getchar();
        } else if (choice == 'b') {
            arrangeSeats();
        } else if (choice == 'd') {
            break;
        } else {
            printf("Other options not implemented yet.\n");
        }
    }

    return 0;
}

// Show menu
void showMainMenu() {
    printf("\n");
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

// Initialize seats and randomly mark 10 as booked (*)
void generateSeats() {
    int i, row, col, count = 0;
    for (i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';

    while (count < 10) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++;
        }
    }
}

// Show current seat layout
void displaySeats() {
    int i, j;
    printf(" \\123456789\n");
    for (i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// Auto arrange seats for user
void arrangeSeats() {
    int n, found = 0;
    printf("How many seats do you need (1~4)? ");
    scanf("%d", &n);

    if (n < 1 || n > 4) {
        printf("Invalid number.\n");
        return;
    }

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
        return;
    }

    displaySeats();

    char confirm;
    printf("Do you accept these seats? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y') {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '*';
        printf("Seats confirmed.\n");
    } else {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '-';
        printf("Cancelled.\n");
    }
}


