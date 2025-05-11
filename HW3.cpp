#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 9

char seats[SIZE][SIZE];

// Function declarations
void showMainMenu();
void generateSeats();
void displaySeats();

int main() {
    char password[10];
    int attempts = 0;
    char choice;

    srand(time(NULL)); // Set random seed

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

    // Password check (max 3 attempts)
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

    generateSeats(); // Initialize seat data

    // Main menu loop
    while (1) {
        showMainMenu();
        printf("Select an option: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            displaySeats(); // Show current seat map
            printf("Press any key to return to menu...\n");
            getchar();
            getchar();
        } else if (choice == 'd') {
            break; // Exit
        } else {
            printf("Other options not implemented yet.\n");
        }
    }

    return 0;
}

// Print menu options
void showMainMenu() {
    printf("\n");
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

// Fill seat map with '-' and randomly mark 10 '*' booked seats
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

// Display the seat map with coordinates
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

