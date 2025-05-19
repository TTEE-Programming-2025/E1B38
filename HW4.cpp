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
        getchar(); // �Y������
        getchar(); // ���ݥ��N��
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

