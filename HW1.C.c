#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 1111 

int main() {
    int input;
    
    
    printf("YU LUN\n");
    printf("*   WELCOME  *\n");
    printf("*   Created by YU LUN   *\n");
    printf("hahahahahahahahahahahahahahah\n\n");
    
    
    printf("�п�J 4 ��ƱK�X�G");
    scanf("%d", &input);
    
   
    if (input == PASSWORD) {
        printf("�K�X���T�I�w��i�J�t�ΡC\n");
        
        
        system("clear");
        
        
        printf("----------------------------------\n");
        printf("| 'A'...'Z' : Uppercase         |\n");
        printf("| 'a'...'z' : Lowercase         |\n");
        printf("| '0'...'9' : Digit             |\n");
        printf("| Otherwise : Your name         |\n");
        printf("----------------------------------\n");
        
        
        char ch;
        printf("�п�J�@�Ӧr���G");
        scanf(" %c", &ch);
        
       
        if (ch >= 'A' && ch <= 'Z') {
            printf("Uppercase\n");
        } else if (ch >= 'a' && ch <= 'z') {
            printf("Lowercase\n");
        } else if (ch >= '0' && ch <= '9') {
            printf("Digit\n");
        } else {
            printf("�A���Z�Ůy���Ωm�W\n");
        }
        
        
        printf("�����N�䵲��...\n");
        getchar();
        getchar();
    } else {
        printf("�K�X���~�I�{�������C\n");
    }
    
    return 0;
}
�o���ϥ� GitHub �ӻs�@�M�סA
���M�b�]�w�W����·СA
�ݭn�ǲߦp���l���x�s�w�B
����{���X�M�޲z��������A
����ڼg�{�����L�{�P�H�e�ۦP�A
���M�ϥ� Dev-C++ �i��}�o�C
�z�L GitHub�A
������K�a�ƥ��M�P�B�{���X�A
���ɶ}�o�Ĳv�C
���M��}�l���Ǥ��ߺD�A
���]��C�C���x Git ���O�C

