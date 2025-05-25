#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#define MAX_TRIES 3

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

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
        getchar(); 
        getchar(); 
    }
}

// a. 輸入學生成績
void enterGrades() {
    clearScreen();

    printf("請輸入學生人數（5~10）：");
    scanf("%d", &studentCount);
    while (studentCount < 5 || studentCount > 10) {
        printf("錯誤！請重新輸入學生人數（5~10）：");
        scanf("%d", &studentCount);
    }

    for (int i = 0; i < studentCount; i++) {
        printf("\n-- 第 %d 位學生 --\n", i + 1);

        printf("姓名：");
        scanf("%s", students[i].name);

        printf("學號（6位整數）：");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("錯誤！請重新輸入6位整數學號：");
            scanf("%d", &students[i].id);
        }

        printf("數學成績（0~100）：");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("錯誤！請重新輸入數學成績（0~100）：");
            scanf("%d", &students[i].math);
        }

        printf("物理成績（0~100）：");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("錯誤！請重新輸入物理成績（0~100）：");
            scanf("%d", &students[i].physics);
        }

        printf("英文成績（0~100）：");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("錯誤！請重新輸入英文成績（0~100）：");
            scanf("%d", &students[i].english);
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n資料輸入完畢。按任意鍵回主選單...");
    getchar(); getchar();
}
void displayGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("目前沒有學生資料！\n");
    } else {
        printf("學生姓名\t學號\t\t數學\t物理\t英文\t平均\n");
        for (int i = 0; i < studentCount; i++) {
            printf("%s\t\t%d\t%d\t%d\t%d\t%.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
        }
    }

    printf("\n按任意鍵回主選單...");
    getchar(); getchar();
}
void searchGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("目前沒有學生資料可搜尋！\n");
    } else {
        char searchName[50];
        int found = 0;

        printf("請輸入要搜尋的學生姓名：");
        scanf("%s", searchName);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                printf("\n找到學生資料：\n");
                printf("姓名：%s\n", students[i].name);
                printf("學號：%d\n", students[i].id);
                printf("數學：%d\n", students[i].math);
                printf("物理：%d\n", students[i].physics);
                printf("英文：%d\n", students[i].english);
                printf("平均：%.1f\n", students[i].average);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n查無此學生資料。\n");
        }
    }

    printf("\n按任意鍵返回主選單...");
    getchar(); getchar();
}
void searchGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("目前沒有學生資料可搜尋！\n");
    } else {
        char searchName[50];
        int found = 0;

        printf("請輸入要搜尋的學生姓名：");
        scanf("%s", searchName);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                printf("\n找到學生資料：\n");
                printf("姓名：%s\n", students[i].name);
                printf("學號：%d\n", students[i].id);
                printf("數學：%d\n", students[i].math);
                printf("物理：%d\n", students[i].physics);
                printf("英文：%d\n", students[i].english);
                printf("平均：%.1f\n", students[i].average);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n查無此學生資料。\n");
        }
    }

    printf("\n按任意鍵返回主選單...");
    getchar(); getchar();
}
