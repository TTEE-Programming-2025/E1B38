#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#define MAX_TRIES 3

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayWelcomeScreen() {
    printf("===========================================\n");
    printf("=                                         =\n");
    printf("=         歡迎使用簡易成績系統            =\n");
    printf("=                                         =\n");
    printf("=         E1B 38 謝侑倫                   =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=     需輸入密碼進入系統                  =\n");             
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=         密碼提示：4 個字                =\n");
    printf("=         每次執行最多可嘗試三次          =\n");
    printf("=                                         =\n");
    printf("=         請輸入正確密碼以繼續…           =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=         請勿將密碼洩漏給他人            =\n");
    printf("=                                         =\n");
    printf("=         製作人：謝侑倫                  =\n");
    printf("=         日期：2025年5月                 =\n");
    printf("=                                         =\n");
    printf("===========================================\n\n");
}

int login() {
    int tries = 0;
    int input;

    while (tries < MAX_TRIES) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("歡迎使用本系統。\n\n");
            return 1; 
        } else {
            tries++;
            printf("密碼錯誤！剩餘次數：%d\n", MAX_TRIES - tries);
        }
    }

    printf("\n錯誤次數過多，系統將自動結束！\n");
    return 0;
}

void showMenu() {
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades        |\n");
    printf("|  b. Display student grades      |\n");
    printf("|  c. Search for student grades   |\n");
    printf("|  d. Grade ranking               |\n");
    printf("|  e. Exit system                 |\n");
    printf("------------------------------------\n");
    printf("請輸入選項 (a ~ e)：");
}

void mainMenu() {
    char choice;

    while (1) {
        clearScreen();
        showMenu();

        scanf(" %c", &choice); // 注意空格：跳過換行

        switch (choice) {
            case 'a':
                printf("成績輸入\n");
                break;
            case 'b':
                printf("顯示成績\n");
                break;
            case 'c':
                printf("搜尋成績 \n");
                break;
            case 'd':
                printf("成績排名\n");
                break;
            case 'e':
                printf("離開系統 \n");
                return;
            default:
                printf("無效選項，請重新輸入。\n");
                break;
        }
        printf("\n按任意鍵繼續...");
        getchar(); // 吃掉換行
        getchar(); // 等待任意鍵
    }
}

int main() {
    displayWelcomeScreen();

    if (!login()) {
        return 0;
    }

    mainMenu();
    return 0;
}

