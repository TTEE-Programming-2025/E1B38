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
    printf("=         �w��ϥ�²�����Z�t��            =\n");
    printf("=                                         =\n");
    printf("=         E1B 38 �¨ݭ�                   =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=     �ݿ�J�K�X�i�J�t��                  =\n");             
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=         �K�X���ܡG4 �Ӧr                =\n");
    printf("=         �C������̦h�i���դT��          =\n");
    printf("=                                         =\n");
    printf("=         �п�J���T�K�X�H�~��K           =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=         �ФűN�K�X���|���L�H            =\n");
    printf("=                                         =\n");
    printf("=         �s�@�H�G�¨ݭ�                  =\n");
    printf("=         ����G2025�~5��                 =\n");
    printf("=                                         =\n");
    printf("===========================================\n\n");
}

int login() {
    int tries = 0;
    int input;

    while (tries < MAX_TRIES) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("�w��ϥΥ��t�ΡC\n\n");
            return 1; 
        } else {
            tries++;
            printf("�K�X���~�I�Ѿl���ơG%d\n", MAX_TRIES - tries);
        }
    }

    printf("\n���~���ƹL�h�A�t�αN�۰ʵ����I\n");
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
    printf("�п�J�ﶵ (a ~ e)�G");
}

void mainMenu() {
    char choice;

    while (1) {
        clearScreen();
        showMenu();

        scanf(" %c", &choice); // �`�N�Ů�G���L����

        switch (choice) {
            case 'a':
                printf("���Z��J\n");
                break;
            case 'b':
                printf("��ܦ��Z\n");
                break;
            case 'c':
                printf("�j�M���Z \n");
                break;
            case 'd':
                printf("���Z�ƦW\n");
                break;
            case 'e':
                printf("���}�t�� \n");
                return;
            default:
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
                break;
        }
        printf("\n�����N���~��...");
        getchar(); 
        getchar(); 
    }
}

// a. ��J�ǥͦ��Z
void enterGrades() {
    clearScreen();

    printf("�п�J�ǥͤH�ơ]5~10�^�G");
    scanf("%d", &studentCount);
    while (studentCount < 5 || studentCount > 10) {
        printf("���~�I�Э��s��J�ǥͤH�ơ]5~10�^�G");
        scanf("%d", &studentCount);
    }

    for (int i = 0; i < studentCount; i++) {
        printf("\n-- �� %d ��ǥ� --\n", i + 1);

        printf("�m�W�G");
        scanf("%s", students[i].name);

        printf("�Ǹ��]6���ơ^�G");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("���~�I�Э��s��J6���ƾǸ��G");
            scanf("%d", &students[i].id);
        }

        printf("�ƾǦ��Z�]0~100�^�G");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("���~�I�Э��s��J�ƾǦ��Z�]0~100�^�G");
            scanf("%d", &students[i].math);
        }

        printf("���z���Z�]0~100�^�G");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("���~�I�Э��s��J���z���Z�]0~100�^�G");
            scanf("%d", &students[i].physics);
        }

        printf("�^�妨�Z�]0~100�^�G");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("���~�I�Э��s��J�^�妨�Z�]0~100�^�G");
            scanf("%d", &students[i].english);
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n��ƿ�J�����C�����N��^�D���...");
    getchar(); getchar();
}
void displayGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("�ثe�S���ǥ͸�ơI\n");
    } else {
        printf("�ǥͩm�W\t�Ǹ�\t\t�ƾ�\t���z\t�^��\t����\n");
        for (int i = 0; i < studentCount; i++) {
            printf("%s\t\t%d\t%d\t%d\t%d\t%.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
        }
    }

    printf("\n�����N��^�D���...");
    getchar(); getchar();
}
void searchGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("�ثe�S���ǥ͸�ƥi�j�M�I\n");
    } else {
        char searchName[50];
        int found = 0;

        printf("�п�J�n�j�M���ǥͩm�W�G");
        scanf("%s", searchName);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                printf("\n���ǥ͸�ơG\n");
                printf("�m�W�G%s\n", students[i].name);
                printf("�Ǹ��G%d\n", students[i].id);
                printf("�ƾǡG%d\n", students[i].math);
                printf("���z�G%d\n", students[i].physics);
                printf("�^��G%d\n", students[i].english);
                printf("�����G%.1f\n", students[i].average);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n�d�L���ǥ͸�ơC\n");
        }
    }

    printf("\n�����N���^�D���...");
    getchar(); getchar();
}
void searchGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("�ثe�S���ǥ͸�ƥi�j�M�I\n");
    } else {
        char searchName[50];
        int found = 0;

        printf("�п�J�n�j�M���ǥͩm�W�G");
        scanf("%s", searchName);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                printf("\n���ǥ͸�ơG\n");
                printf("�m�W�G%s\n", students[i].name);
                printf("�Ǹ��G%d\n", students[i].id);
                printf("�ƾǡG%d\n", students[i].math);
                printf("���z�G%d\n", students[i].physics);
                printf("�^��G%d\n", students[i].english);
                printf("�����G%.1f\n", students[i].average);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n�d�L���ǥ͸�ơC\n");
        }
    }

    printf("\n�����N���^�D���...");
    getchar(); getchar();
}
