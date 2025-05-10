#include <stdio.h>
#include <string.h>

void showMainMenu();

int main() {
    char password[10];
    int attempts = 0;

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

    showMainMenu();

    return 0;
}

void showMainMenu() {
    printf("\n");
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

