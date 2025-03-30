#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 1111 

int main() {
    int input;
    
    
    printf("YU LUN\n");
    printf("*   WELCOME  *\n");
    printf("*   Created by YU LUN   *\n");
    printf("hahahahahahahahahahahahahahah\n\n");
    
    
    printf("請輸入 4 位數密碼：");
    scanf("%d", &input);
    
   
    if (input == PASSWORD) {
        printf("密碼正確！歡迎進入系統。\n");
        
        
        system("clear");
        
        
        printf("----------------------------------\n");
        printf("| 'A'...'Z' : Uppercase         |\n");
        printf("| 'a'...'z' : Lowercase         |\n");
        printf("| '0'...'9' : Digit             |\n");
        printf("| Otherwise : Your name         |\n");
        printf("----------------------------------\n");
        
        
        char ch;
        printf("請輸入一個字元：");
        scanf(" %c", &ch);
        
       
        if (ch >= 'A' && ch <= 'Z') {
            printf("Uppercase\n");
        } else if (ch >= 'a' && ch <= 'z') {
            printf("Lowercase\n");
        } else if (ch >= '0' && ch <= '9') {
            printf("Digit\n");
        } else {
            printf("你的班級座號及姓名\n");
        }
        
        
        printf("按任意鍵結束...\n");
        getchar();
        getchar();
    } else {
        printf("密碼錯誤！程式結束。\n");
    }
    
    return 0;
}

