#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 2025
#define MAX_TRIES 3
#define MAX_STUDENTS 10

// 學生結構定義
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

// 清除螢幕（跨平台）
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// 顯示歡迎畫面
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
    printf("=         密碼提示：4 個字                =\n");
    printf("=         每次執行最多可嘗試三次          =\n");
    printf("=                                         =\n");
    printf("=         請輸入正確密碼以繼續…           =\n");
    printf("=                                         =\n");
    printf("=         請勿將密碼洩漏給他人            =\n");
    printf("=                                         =\n");
    printf("=         製作人：謝侑倫                  =\n");
    printf("=         日期：2025年5月                 =\n");
    printf("=                                         =\n");
    printf("===========================================\n\n");
}

// 密碼登入
int login() {
    int tries = 0, input;

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

// 安全的整數成績輸入函式，避免小數與非數字
int readScore(const char *subject) {
    int score;
    char buffer[100];

    while (1) {
        printf("%s成績（0~100）：", subject);
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &score) == 1 && strchr(buffer, '.') == NULL) {
            if (score >= 0 && score <= 100)
                return score;
        }

        printf("錯誤！請輸入整數且介於 0 ~ 100 之間。\n");
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

        students[i].math = readScore("數學");
        students[i].physics = readScore("物理");
        students[i].english = readScore("英文");

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n資料輸入完畢。按任意鍵回主選單...");
    getchar(); getchar();
}

// b. 顯示學生資料
void displayGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("目前沒有學生資料！\n");
    } else {
        printf("學生姓名\t學號\t數學\t物理\t英文\t平均\n");
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

// c. 搜尋學生成績
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
// d. 成績排名
void rankGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("目前沒有學生資料可排序！\n");
    } else {
        Student temp;
        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = 0; j < studentCount - i - 1; j++) {
                if (students[j].average < students[j + 1].average) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        printf("學生姓名\t學號\t平均成績\n");
        for (int i = 0; i < studentCount; i++) {
            printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
        }
    }

    printf("\n按任意鍵回主選單...");
    getchar(); getchar();
}



// 顯示主選單
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

// 主程式
int main() {
    displayWelcomeScreen();

    if (!login())
        return 0;

    char choice;
    while (1) {
        clearScreen();
        showMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                enterGrades();
                break;
            case 'b':
                displayGrades();
                break;
            case 'c':
                searchGrades();
                break;
            case 'd':
                rankGrades();
                break;
            case 'e': {
                char confirm;
                printf("確定離開？ (y/n)：");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("系統結束，感謝使用！\n");
                    return 0;
                }
                break;
            }
            default:
                printf("無效選項，請重新輸入！\n");
                getchar(); getchar();
        }
    }

    return 0;
}


//心得: 這次作業透過結構與陣列的搭配，練習了 C 語言中結構化資料的處理方式，
//更清楚了解如何將多筆相關的資料封裝在一個結構體中，
//並使用陣列儲存多位學生的資料，讓程式的邏輯更清楚、更有組織。
//在這樣的設計下，每位學生的所有資料
//都能以一個結構元素表示，操作起來不容易出錯。
//除了資料結構的練習外，也實作了各種功能性模組，
//進一步練習了條件判斷、迴圈控制與函式設計的應用能力。
//然而最後執行時發現排版錯誤，雖然程式邏輯沒變，但修改格式清楚後更容易閱讀。 


//程式說明:
//開始執行程式後，會先顯示歡迎畫面，接著進行密碼驗證（2025）。
//密碼輸入錯誤 3 次將直接關閉程式。
//輸入正確後才可進入系統功能選單。
//Enter student grades：輸入學生人數與每位學生的姓名、學號、三科成績。
//Display student grades：清除螢幕並顯示所有學生的詳細成績與平均。
//Search for student grades：可根據學生姓名查詢其個人成績資料。
//Grade ranking：依照平均成績從高至低進行排序，並列出排名。
//Exit system：離開程式前會再次詢問使用者是否確定退出（y/n）。







