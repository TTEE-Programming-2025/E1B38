#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 2025
#define MAX_TRIES 3

void displayWelcomeScreen() {
    // 顯示個人風格畫面（至少20行）
    printf("===========================================\n");
    printf("=                                         =\n");
    printf("=         歡迎使用簡易成績系統            =\n");
    printf("=                                         =\n");
    printf("=         E1B 38 謝侑倫                   =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
	printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=        歡迎                             =\n");
    printf("=       需輸入密碼進入系統                =\n");
    printf("=                                         =\n");
    printf("=     密碼提示4個字                       =\n");
    printf("=                                         =\n");
    printf("=     每次執行最多嘗試三次                =\n");
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
    return 0; // 失敗
}

int main() {
    displayWelcomeScreen();

    if (!login()) {
        return 0; // 登入失敗就結束程式
    }

    // 如果登入成功，之後可以繼續呼叫主選單函式（第2題）
    // mainMenu(); // 下一題會實作

    return 0;
}
