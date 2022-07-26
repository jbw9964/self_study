#include <stdio.h>

// 문제 1 : (p.360) : 구조체 이용해서 도서 관리 프로그램 만들기
/*
1. 책 추가하기
2. 지금 있는 책 정보 보기 --> 정보 : 제목, 저자, 빌림 상태
3. 책 빌리기
*/

struct Book{
    char title[30];
    char author[30];
    int borrow;
};

void add(struct Book *info, char *title, char *author);
void show(struct Book *info, int count);
void borrow(struct Book *info);

int main() {
    printf("\ncode_start\n\n");
    
    struct Book arr[5];

    int count = 0;
    int i = 0;
    while (i == 0){
        int answer;
        printf("========================================\n");
        printf("Choose menu\n");
        printf("1. Add new book\n");
        printf("2. Show current books\n");
        printf("3. Borrow book\n");
        printf("4. End program\n");
        printf("\ninput : ");
        scanf("%d", &answer);
        printf("\n");

        switch (answer){
        case 1 :
        {
            char title[30];
            char author[30];
            getchar();
            printf("Title : ");
            scanf("%[^\n]s", title);
            printf("Author : ");
            getchar();
            scanf("%[^\n]s", author);
            
            add(&arr[count], title, author);
            printf("\nBook was addedd in arr[%d]\n\n", count);
            count++;
            break;
        }
        
        case 2 :
        {
            if (count == 0) printf("There's no book in sotre.\n\n");
            else {
                for (int i = 0; i < count; i++){show(arr, i);}
            }
            break;
        }

        case 3 :
        {
            if (count == 0) printf("There's no book in sotre.\n\n");
            else {
                for (int i = 0; i < count; i++){show(arr, i);}
                printf("Which one do you want to borrow? : ");
                int num;
                scanf("%d", &num);
                borrow(&arr[num - 1]);
            }
            break;
        }

        case 4 : 
        {
            i = 1;
            break;
        }

        default :
            printf("You put wrong input.\n\n");
            break;
        }
    }


    printf("\n\ncode_end\n");
    return 0;
}

void add(struct Book *info, char *title, char *author){
    int count = 0;
    while (*title != NULL){
        info->title[count] = title[0];
        title++;
        count++;
    }
    info->title[count] = NULL;
    count = 0;
    while (*author != NULL){
        info->author[count] = author[0];
        author++;
        count++;
    }
    info->author[count] = NULL;
    info->borrow = 1;
}

void show(struct Book *info, int count){
    for (int i = 0; i < count; i++){
        info++;
    }
    printf("%d. %s\n", count + 1, info->title);
    printf("author : %s\n", info->author);
    printf("status : ");

    if (info->borrow == 1) printf("returned\n\n");
    else printf("borrowed\n\n");

}

void borrow(struct Book *info){
    printf("Title : %s\n", info->title);
    printf("Author : %s\n", info->author);
    printf("Are you sure borrow this book? (y or n) : ");
    char answer[5];
    scanf("%s", &answer);
    if (answer[0] == 'y'){
        info->borrow = 0;
        printf("Book was borrowed.\n\n");
    }   else if (answer[0] == 'n'){
        printf("Return to main menu.\n\n");
    }   else printf("You put wrong answer.\n\n");
}


// 진도 : p.360