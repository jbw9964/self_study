#include <stdio.h>

// 문제 5 (p.307) : 도서 관리 프로그램 만들기
/*
1. 책을 새로 추가하는 기능 (총 개수는 100권으로 하기) : 제목, 저자 이름, 출판사 3개지 정보를 저장해야 됨
2. 책 제목 검색하면 그 책의 정보가 나와야 됨.
3. 출판사 검색 기능도 있어야 됨.
4. 책을 빌리는 기능
5. 책을 반납하는 기능
*/

// 책 대여 상태는 : check 1 --> 지금 있음. check 0 --> 대여 중

int start();
int add(char info[100][4][20], char *title, char *author, char *publisher, int check);          // 첫번째 인수 : 정보를 가져올 배열
int search_1(char info[100][4][20], int input, char *result_arr);
int check(char *info, char *variable);      // 책 정보 찾는 함수 2 (진짜 맞는지 확인)
int rent(char info[100][4][20], int num);
int put(char info[100][4][20], char *input);    // 반납
int print(char info[100][4][20]);            // 지금 저장된 책들의 정보 모두 printf 하는 함수
int exit();

int main() {
    printf("\ncode_start\n\n");
    int num = 0;
    char info[100][4][20];              // 100권 + 제목, 이름, 출판사, 대여상태 :  간단하게 먼저 3권으로
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 4; j++){        // 0 : 제목, 1 : 이름, 2 : 출판사, 3 : 대여상태   (j)
            for (int k = 0; k < 20; k++){
                info[i][j][k] = NULL;       // add 함수에서는 대여상태는 입력 안하도록
            }
        }
        num++;
    }
    
    int input_loop = 1;
    while (input_loop != 0){
        switch (start()){
        case 1 :    // 책 추가하기
        {
            char title[20];
            char author[20];
            char publisher[20];
            printf("\nBook title : ");
            scanf("%s", title);
            printf("\nBook author : ");
            scanf("%s", author);
            printf("\nBook publisher : ");
            scanf("%s", publisher);
            add(info, title, author, publisher, 1);
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }
            
        case 2 :    // 책 정보 찾기
        {
            int input;
            char result_arr[20];
            printf("\nWhich information do you want to search?\n\n");
            printf("1. Title\n\n");
            printf("2. Author\n\n");
            printf("3. Publisher\n\n");
            printf("Select menu : ");
            scanf("%d", &input);
            printf("\n");
            search_1(info, input - 1, result_arr);

            if (result_arr[0] != NULL){
                for (int i = 0; ; i++){
                    if (result_arr[i] == NULL) break;
                    printf("===============info===============\n\n");
                    printf("location : info[%d]\n\n", result_arr[i] - 1);
                    printf("Title : %s\n\n", info[result_arr[i] - 1][0]);
                    printf("Author : %s\n\n", info[result_arr[i] - 1][1]);
                    printf("Publisher : %s\n\n", info[result_arr[i] - 1][2]);
                    printf("Status : %s\n\n", info[result_arr[i] - 1][3]);
                }
            }   else printf("\nThere's no match with input data.\n\n");
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }

        case 3 :    // 책 빌리기
        {
            int num_1, num_2;               // num_1 : 지금 가지고 있는 책 개수. 이상한거 넣으면 다시 돌아가려고
            num_1 = print(info);
            printf("Press the number of the book you want to borrow.\ninput : ");
            scanf("%d", &num_2);

            if (num_2 > 0 && num_2 <= num_1){
                rent(info, num_2 - 1);
            }   else {
                printf("You put wrong number. Return to main menu.\n\n");
                char any;
                printf("Press any key to continue...\n");
                scanf("%s", &any);
                input_loop = 1;
                break;
            }
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }

        case 4 :    // 책 반납하기
        {
            printf("\nList of books out of stocks\n\n");
            int count_1 = 0;
            int count_2 = 1;
            char input[20];
            for (int i = 0; i < 20; i++) input[i] = NULL;       // input[0] : 첫번째 대출된 책의 번호 info[이 숫자]

            while (info[count_1][0][0] != NULL){
                if (info[count_1][3][0] == 0){
                    printf("%d. %s\n", count_2, info[count_1][0]);
                    printf("Author : %s\n", info[count_1][1]);
                    printf("Publisher : %s\n\n", info[count_1][2]);
                    input[count_2] = count_1;
                    count_2++;
                }
                count_1++;
            }
            if (count_2 == 1) printf("All books are in stocks. Return to main menu.\n\n");
            else put(info, input);
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }

        case 5 :    // 책 목록 보기 (+ 모든 정보 나열)
        {
            print(info);
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }
        
        case 6 :    // 프로그램 끄기
        {
            exit();
            input_loop = 0;
            break;
        }
            
        default:    // 이상한거 넣었을 때 다시 돌아가기
        {
            printf("You choose wrong menu\n");
            printf("Return to main menu\n");
            char any;
            printf("Press any key to continue...\n");
            scanf("%s", &any);
            input_loop = 1;
            break;
        }
        }
    }
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int start(){
    int answer;
    printf("\n==============================Library==============================\n\n");
    printf("Welcome to library. Select menu by pressing it's numbers\n\n");
    printf("1. Add some new book\n\n");
    printf("2. Search the book information\n\n");
    printf("3. Borrow some book\n\n");
    printf("4. Return borrowed book\n\n");
    printf("5. Print books in store\n\n");
    printf("6. Exit the library program\n\n");
    printf("===================================================================\n\n");

    printf("Choose the menu : ");
    scanf("%d", &answer);

    return answer;
}

int add(char info[100][4][20], char *title, char *author, char *publisher, int check){
    int num = 0;
    while (info[0][0][0] != NULL){
        num++;
        info++;
    }
    int count = 0;
    while (*title){
        info[0][0][count] = title[0];
        count++;
        title++;
    }
    count = 0;
    while (*author){
        info[0][1][count] = author[0];
        count++;
        author++;
    }
    count = 0;
    while (*publisher){
        info[0][2][count] = publisher[0];
        count++;
        publisher++;
    }

    printf("\ninformation was added at array.\n\n");
    printf("Title : info[%d][0] --> %s\n", num, info[0][0]);
    printf("Author : info[%d][1] --> %s\n", num, info[0][1]);
    printf("Publisher : info[%d][2] --> %s\n", num, info[0][2]);
    printf("Status : info[%d][3] --> ", num);

    if (check == 1){
        info[0][3][0] = 1;
        printf("in stocks\n\n");
    }   else printf("out of stocks\n\n");

    return 0;
}

int search_1(char info[100][4][20], int input, char *result_arr){
    char variable[20];
    for (int i = 0; i < 20; i++) variable[i] = NULL;
    for (int i = 0; i < 20; i++) result_arr[i] = NULL;
    if (input == 0) printf("Title : ");
    else if (input == 1) printf("Author : ");
    else if (input == 2) printf("Publisher : ");
    else{
        printf("You put wrong menu. Return to main menu.\n");
        return 0;
    }
    scanf("%s", variable);

    switch (input){
    case 0:
    {
        int count_1 = 0;
        int count_2 = 0;
        printf("\nTitle : %s\n", variable);
        while (info[0][0][0] != NULL){
            int result = 0;
            if (info[0][0][0] == variable[0]){
                result = check(info[0][0], variable);
            }
            if (result == 1){
                result_arr[count_2] = count_1 + 1;
                count_2++;
            }
            info++;
            count_1++;      // info 첫번째 숫자
        }
        break;
    }
        
    case 1:
    {
        int count_1 = 0;
        int count_2 = 0;
        printf("\nAuthor : %s\n", variable);
        while (info[0][0][0] != NULL){
            int result = 0;
            if (info[0][1][0] == variable[0]){
                result = check(info[0][1], variable);
            }
            if (result == 1){
                result_arr[count_2] = count_1 + 1;
                count_2++;
            }
            info++;
            count_1++;
        }
        break;
    }

    case 2:
    {
        int count_1 = 0;
        int count_2 = 0;
        printf("\nAuthor : %s\n", variable);
        while (info[0][0][0] != NULL){
            int result = 0;
            if (info[0][2][0] == variable[0]){
                result = check(info[0][2], variable);
            }
            if (result == 1){
                result_arr[count_2] = count_1 + 1;
                count_2++;
            }
            info++;
            count_1++;
        }
        break;
    }
    
    default:
        printf("You put wrong menu. Return to main menu\n");
        return 0;
    }
    return 0;
}

int check(char *info, char *variable){
    int result = 1;
    for (int i = 0; ; i++){
        if (*variable == NULL) break;
        if (*variable != *info){
            result = 0;
            break;
        }
        variable++;
        info++;
    }
    return result;
}

int rent(char info[100][4][20], int num){
    char answer[5];

    if (info[num][3][0] != 1){
        printf("\nBooks are out of stocks\n");
        printf("You can't borrow this book. Return to main menu.\n\n");
        return 0;
    }   else{
        printf("\nBook information\n");
        printf("Title : %s\n", info[num][0]);
        printf("Author : %s\n", info[num][1]);
        printf("Publisher : %s\n", info[num][2]);
        printf("Status : ");
        printf("in stocks\n");
        printf("\nAre you sure borrow this book? (y or n) : ");
        scanf("%s", answer);
    }
    if (answer[0] == 'y'){
        info[num][3][0] = 0;
        printf("Book was borrowed.\n\n");
    }   else{
        printf("Return to main menu.\n\n");
        return 0;
    }
    return 0;
}

int put(char info[100][4][20], char *input){

    int answer;
    printf("Which book you're going to return?\n\n");
    printf("input : ");
    scanf("%d", &answer);

    if (input[answer] == NULL) printf("\nYou put wrong number. Return to main menu.\n\n");
    else{
        int num = input[answer];
        info[num][3][0] = 1;
        printf("\nBook was returned. Back to main menu.\n\n");
    }
    return 0;
}

int print(char info[100][4][20]){
    printf("===============info===============\n\n");
    int count = 0;
    while (info[0][0][0] != NULL){
        printf("%d. %s\n", count + 1, info[0][0]);
        printf("Author : %s\n", info[0][1]);
        printf("Publisher : %s\n", info[0][2]);
        printf("Status : ");
        if (info[0][3][0] == 1) printf("in stocks\n\n");
        else printf("out of stocks\n\n");
        count++;
        info++;
    }
    if (count == 0) printf("The stocks are empty. Please add some new books.\n\n");
    printf("===============info===============\n\n");
    return count;
}

int exit(){
    printf("\nExiting Library program\n\n");
    return 0;
}

// 아쉬운 점 : 결국 대부분 오류 안나는 상황으로 만들긴 한듯. 그런데 혹신까지는 못하겠음. 예를들어 result_arr의 첫째값이 Null 일 때 
// 자료값이 없다고 했었는데 사실 이 부분은 잘못된 menu를 눌렀을 때도 해당됨. 그래서 이런 경우를 없애려면 조금 더 수정하고 방법을 생각해야 함.
// 그리고 깔끔한 것 같기도 한데 start 함수 나오는게 너무 큰 것 같기도 함.
// +뭔가 노랑색으로 오류 뜨는데 이것 좀 없으면 더 깔끔할듯.

// 진도 : p.307