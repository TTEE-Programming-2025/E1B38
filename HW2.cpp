#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PASSWORD 2025

void clearScreen() {
    system("cls"); // �M���ù��A�A�Ω� Windows
}

void pauseScreen() {
    printf("\nPress any key to continue...\n");
    getch();
}

void drawTriangle(char ch) {
    printf("\n��X���G�G\n");
    for (char i = 'a'; i <= ch; i++) {
        for (char j = 'a'; j <= i; j++) {
            printf("%c", j);
        }
        printf("\n");
    }
}

void multiplicationTable(int n) {
    printf("\n���k�� %d x %d\n", n, n);
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

    // �B�J1�G�n�J����
    while (1) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &inputPassword);

        if (inputPassword == PASSWORD) {
            printf("�K�X���T�A�w��ϥΡI\n");
            pauseScreen();
            break;
        } else {
            tryCount++;
            printf("�K�X���~�I�A�w���~ %d ���C\n", tryCount);
            if (tryCount >= 3) {
                printf("���~�W�L3���A�{�������C\n");
                return 0;
            }
            pauseScreen();
            clearScreen();
        }
    }

    // �B�J2�G�D���
    do {
        clearScreen();
        printf("\n======= �D��� =======\n");
        printf("a. �e�X�����T����\n");
        printf("b. ��ܭ��k��\n");
        printf("c. �����{��\n");
        printf("======================\n");
        printf("�п�� (a/b/c)�G");

        choice = getch(); // ���ݫ� Enter
        printf("%c\n", choice);

        if (choice == 'a' || choice == 'A') {
            clearScreen();
            printf("�п�J�@�Ӧr�� (a~n)�G");
            scanf(" %c", &ch);

            if (ch >= 'a' && ch <= 'n') {
                drawTriangle(ch);
            } else {
                printf("��J���~�I�п�J�p�g�^��r�� a~n�C\n");
            }
            pauseScreen();

        } else if (choice == 'b' || choice == 'B') {
            clearScreen();
            int n;
            printf("�п�J�@��1��9����ơG");
            scanf("%d", &n);

            if (n >= 1 && n <= 9) {
                multiplicationTable(n);
            } else {
                printf("��J���~�I�п�J1~9��������ơC\n");
            }
            pauseScreen();

        } else if (choice == 'c' || choice == 'C') {
            clearScreen();
            printf("�T�w�n�����ܡH(y/n)�G");
            char yn = getch();
            printf("%c\n", yn);

            if (yn == 'y' || yn == 'Y') {
                printf("�{�������A�P�¨ϥΡI\n");
                break;
            } else if (yn == 'n' || yn == 'N') {
                continue;
            } else {
                printf("��J���~�I�Э��s��ܡC\n");
                pauseScreen();
            }

        } else {
            printf("��J���~�I�п�� a, b, �� c�C\n");
            pauseScreen();
        }
    } while (1);

    return 0;
}

HW2.cpp �{���P�Q�G

�o���m�ߤF�K�X���һP�D���]�p�A
�Ƿ|�F���X while �j��Bif �P�_�P getch()�A
���ާ@��y�Z�C�]�N�\������W�ߪ� function�A
���{�����c��M���C�L�{���J�� Git editor ���D�A
�]���Q�ѨM�A�W�[�F��}�o���ҳ]�w���z�ѡC
�o���m�����ڹ�g����p���ε{���󦳫H�ߡI


