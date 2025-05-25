#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 2025
#define MAX_TRIES 3
#define MAX_STUDENTS 10

// �ǥ͵��c�w�q
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

// �M���ù��]�󥭥x�^
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// ����w��e��
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
    printf("=         �K�X���ܡG4 �Ӧr                =\n");
    printf("=         �C������̦h�i���դT��          =\n");
    printf("=                                         =\n");
    printf("=         �п�J���T�K�X�H�~��K           =\n");
    printf("=                                         =\n");
    printf("=         �ФűN�K�X���|���L�H            =\n");
    printf("=                                         =\n");
    printf("=         �s�@�H�G�¨ݭ�                  =\n");
    printf("=         ����G2025�~5��                 =\n");
    printf("=                                         =\n");
    printf("===========================================\n\n");
}

// �K�X�n�J
int login() {
    int tries = 0, input;

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

// �w������Ʀ��Z��J�禡�A�קK�p�ƻP�D�Ʀr
int readScore(const char *subject) {
    int score;
    char buffer[100];

    while (1) {
        printf("%s���Z�]0~100�^�G", subject);
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &score) == 1 && strchr(buffer, '.') == NULL) {
            if (score >= 0 && score <= 100)
                return score;
        }

        printf("���~�I�п�J��ƥB���� 0 ~ 100 �����C\n");
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

        students[i].math = readScore("�ƾ�");
        students[i].physics = readScore("���z");
        students[i].english = readScore("�^��");

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n��ƿ�J�����C�����N��^�D���...");
    getchar(); getchar();
}

// b. ��ܾǥ͸��
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

// c. �j�M�ǥͦ��Z
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
// d. ���Z�ƦW
void rankGrades() {
    clearScreen();

    if (studentCount == 0) {
        printf("�ثe�S���ǥ͸�ƥi�ƧǡI\n");
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

        printf("�ǥͩm�W\t�Ǹ�\t\t�������Z\n");
        for (int i = 0; i < studentCount; i++) {
            printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
        }
    }

    printf("\n�����N��^�D���...");
    getchar(); getchar();
}



// ��ܥD���
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

// �D�{��
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
                printf("�T�w���}�H (y/n)�G");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("�t�ε����A�P�¨ϥΡI\n");
                    return 0;
                }
                break;
            }
            default:
                printf("�L�Ŀﶵ�A�Э��s��J�I\n");
                getchar(); getchar();
        }
    }

    return 0;
}









