#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PASSWORD 2025

void clearScreen() {
    system("cls"); // 清除螢幕，適用於 Windows
}

void pauseScreen() {
    printf("\nPress any key to continue...\n");
    getch();
}

void drawTriangle(char ch) {
    printf("\n輸出結果：\n");
    for (char i = 'a'; i <= ch; i++) {
        for (char j = 'a'; j <= i; j++) {
            printf("%c", j);
        }
        printf("\n");
    }
}

void multiplicationTable(int n) {
    printf("\n乘法表 %d x %d\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d\t", i * j);
        }
        printf("\n");
    }
}

int main() {
    int inputPassword, tryCount = 0;
    char choice, ch;

    // 步驟1：登入驗證
    while (1) {
        printf("請輸入4位數密碼：");
        scanf("%d", &inputPassword);

        if (inputPassword == PASSWORD) {
            printf("密碼正確，歡迎使用！\n");
            pauseScreen();
            break;
        } else {
            tryCount++;
            printf("密碼錯誤！你已錯誤 %d 次。\n", tryCount);
            if (tryCount >= 3) {
                printf("錯誤超過3次，程式結束。\n");
                return 0;
            }
            pauseScreen();
            clearScreen();
        }
    }

    // 步驟2：主選單
    do {
        clearScreen();
        printf("\n======= 主選單 =======\n");
        printf("a. 畫出直角三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 結束程式\n");
        printf("======================\n");
        printf("請選擇 (a/b/c)：");

        choice = getch(); // 不需按 Enter
        printf("%c\n", choice);

        if (choice == 'a' || choice == 'A') {
            clearScreen();
            printf("請輸入一個字元 (a~n)：");
            scanf(" %c", &ch);

            if (ch >= 'a' && ch <= 'n') {
                drawTriangle(ch);
            } else {
                printf("輸入錯誤！請輸入小寫英文字母 a~n。\n");
            }
            pauseScreen();

        } else if (choice == 'b' || choice == 'B') {
            clearScreen();
            int n;
            printf("請輸入一個1到9的整數：");
            scanf("%d", &n);

            if (n >= 1 && n <= 9) {
                multiplicationTable(n);
            } else {
                printf("輸入錯誤！請輸入1~9之間的整數。\n");
            }
            pauseScreen();

        } else if (choice == 'c' || choice == 'C') {
            clearScreen();
            printf("確定要結束嗎？(y/n)：");
            char yn = getch();
            printf("%c\n", yn);

            if (yn == 'y' || yn == 'Y') {
                printf("程式結束，感謝使用！\n");
                break;
            } else if (yn == 'n' || yn == 'N') {
                continue;
            } else {
                printf("輸入錯誤！請重新選擇。\n");
                pauseScreen();
            }

        } else {
            printf("輸入錯誤！請選擇 a, b, 或 c。\n");
            pauseScreen();
        }
    } while (1);

    return 0;
}

HW2.cpp 程式感想：

這次練習了密碼驗證與主選單設計，
學會了結合 while 迴圈、if 判斷與 getch()，
讓操作更流暢。也將功能分成獨立的 function，
讓程式結構更清楚。過程中遇到 Git editor 問題，
也順利解決，增加了對開發環境設定的理解。
這次練習讓我對寫完整小應用程式更有信心！


