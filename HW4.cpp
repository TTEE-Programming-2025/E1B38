#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 2025
#define MAX_TRIES 3

void displayWelcomeScreen() {
    // ��ܭӤH����e���]�ܤ�20��^
    printf("===========================================\n");
    printf("=                                         =\n");
    printf("=         �w��ϥ�²�����Z�t��            =\n");
    printf("=                                         =\n");
    printf("=         E1B 38 �¨ݭ�                   =\n");
    printf("=                                         =\n");
    printf("=                                         =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
	printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=        �w��                             =\n");
    printf("=       �ݿ�J�K�X�i�J�t��                =\n");
    printf("=                                         =\n");
    printf("=     �K�X����4�Ӧr                       =\n");
    printf("=                                         =\n");
    printf("=     �C������̦h���դT��                =\n");
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
    return 0; // ����
}

int main() {
    displayWelcomeScreen();

    if (!login()) {
        return 0; // �n�J���ѴN�����{��
    }

    // �p�G�n�J���\�A����i�H�~��I�s�D���禡�]��2�D�^
    // mainMenu(); // �U�@�D�|��@

    return 0;
}
