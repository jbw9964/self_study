#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "stack.h"
#include "stack.c"


bool infix_to_postfix(char *infix, char *postfix);  // 만약 입력에 이상한게 들어있으면 false, 없으면 true 리턴.
int calc_postfix(char *postfix);

int main(){
    printf("\ncode_start\n\n\n");

    while (true){
        char infix[128], postfix[128];

        printf("Enter an experession : ");
        gets(infix);

        printf("\n");
        printf("[infix notation] : %s\n", infix);
        bool result_1 = infix_to_postfix(infix, postfix);
        
        if (result_1){
            printf("[postfix notation] : %s\n\n", postfix);
            int result_2 = calc_postfix(postfix);
    
            printf("Result : %d\n\n", result_2);
        }

        char temp[10];
        printf("press q to quit, anything to continue... ");
        scanf("%s", temp);

        if (temp[0] == 'q') {break;}
        
        printf("\n");
        fflush(stdin);
    }
    
    printf("\n\ncode_end\n\n");
    return 0;
}

bool infix_to_postfix(char *infix, char *postfix){  // 만약 입력에 이상한게 들어있으면 false, 없으면 true 리턴.

    Stack_pointer Stack = CreateStack(100); // infix 의 연산자들이 들어갈 Stack
    bool is_good = true;

    while(true){
        if (!is_good) {printf("Shuting down...\n\n"); return false;}
        char text = infix[0];       // infix 의 첫번째 문자를 text 라 선언, 초기화

        if (isdigit(text)){         // text 가 숫자일 때 postfix 문자열에 그대로 넣음
            postfix[0] = text;
            postfix++;
            postfix[0] = 0;
            infix++;
            
            continue;

        }   else if (!text) {       // infix 끝까지 갔을 때 Stack 에 남있는 연산자 모두 출력, 메모리 해제
            while (Stack->list){
                postfix[0] = Top(Stack);
                postfix++;
                postfix[0] = 0;
                Pop(Stack);
            }

            DisposeStack(Stack);
            break;
            }    

        switch (text){          // 우선순위 : ^  >  *,/,%  > +,-

            case '^' : {        // 규칙 2번에 따라 ‘^’ 보다 높거나 같은 연산은 ‘^’ 밖에 없음.

                while (Stack->list){
                    if (Top(Stack) == '^'){
                        postfix[0] = Top(Stack);
                        postfix++;
                        postfix[0] = 0;
                        Pop(Stack);
                    }   else {break;}
                }
                Push(text, Stack);

                break;
            }

            case '*' : {        // 규칙 2번에 따라 ‘*’ 보다 높거나 같은 연산은 ‘^’, '*,/,%' 임.
                while (Stack->list){
                    if (Top(Stack) == '(') {break;}     // 규칙 2 예외에 해당하는지 확인
                    if (Top(Stack) != '+' && Top(Stack) != '-'){
                        postfix[0] = Top(Stack);
                        postfix++;
                        postfix[0] = 0;
                        Pop(Stack);
                    }   else {break;}
                }
                Push(text, Stack);

                break;
            }
            case '/' : {
                while (Stack->list){
                    if (Top(Stack) == '(') {break;}
                    if (Top(Stack) != '+' && Top(Stack) != '-'){
                        postfix[0] = Top(Stack);
                        postfix++;
                        postfix[0] = 0;
                        Pop(Stack);
                    }   else {break;}
                }
                Push(text, Stack);

                break;
            }
            case '%' : {
                while (Stack->list){
                    if (Top(Stack) == '(') {break;}
                    if (Top(Stack) != '+' && Top(Stack) != '-'){
                        postfix[0] = Top(Stack);
                        postfix++;
                        postfix[0] = 0;
                        Pop(Stack);
                    }   else {break;}
                }
                Push(text, Stack);

                break;
            }

            case '+' : {        // 규칙 2번에 따라 ‘+’ 보다 높거나 같은 연산자는 모든 연산자들임.
                while (Stack->list){
                    if (Top(Stack) == '(') {break;}
                    postfix[0] = Top(Stack);
                    postfix++;
                    postfix[0] = 0;
                    Pop(Stack);
                }
                Push(text, Stack);

                break;
            }
            case '-' : {
                while (Stack->list){
                    if (Top(Stack) == '(') {break;}
                    postfix[0] = Top(Stack);
                    postfix++;
                    postfix[0] = 0;
                    Pop(Stack);
                }
                Push(text, Stack);
                
                break;
            }

            case '(' : {        // 여는 괄호를 만나면 닫는 괄호를 만날때까지 만나는 연산자를 Stack 에 집어넣음
                Push(text, Stack);
                break;
            }
            case ')' : {        // 닫는 괄호를 만나면 여는 괄호를 만날 때까지 Stack 내 모든 연산자를 출력함, Pop 함.
                while (Stack->list){
                    if (Top(Stack) == '(') {Pop(Stack); break;}
                    postfix[0] = Top(Stack);
                    postfix++;
                    postfix[0] = 0;
                    Pop(Stack);
                }

                break;
            }

            case ' ' : {break;}
            default : {printf("You put something wrong : %c\n", text); is_good = false; break;}
        }

        infix++;
    }
    
    return true;
}

/* infix -> postfix 규칙

1. 숫자를 만나면 postfix 문자열에 넣는다.
2. 연산자를 만나면 Stack 에서 해당 연산자보다 높거나 같은 우선순위의 연산자를 출력, Pop 한다.
- 예외 : Stack 에 여는 괄호가 있을 때, Stack 에서 여는 괄호 아래에 있는 연산자는 생각 안함.
3. 닫는 괄호를 만나면 Top(Stack) == (여는괄호) 일 때까지 Stack 내의 연산자를 모두 출력, Pop 한다.
4. 입력이 끝나면 Stack 내 남아있는 연산자를 모두 출력, Pop 한다.

p.s : 제곱 연산자 (^) 의 우선순위는 가장 높고 modulo 연산자 (%) 는 *,/ 과 동등하다 생각하고 만듬. 
또한 a ^ b ^ c 라 입력 받았을 때, (a^b)^c 로 계산한다 가정함.

(2 ^ 3 ^ 2 = 8 ^ 2 로 만듬.)

연산자 우선순위 : ^  >  *,/,%  >  +,-

*/

int calc_postfix(char *postfix){

    Stack_pointer Stack = CreateStack(100);
    int result = 0;

    while (true){
        char text = postfix[0];     // postfix 의 첫번째 문자를 text 라 선언, 초기화

        if (isdigit(text)){         // text 가 숫자일 때 Stack 에 Push
            Push(text - '0', Stack);
            postfix++;

            continue;
        }   else if (!text){        // postfix 끝까지 갔을 때 Stack 에 남아있는 값은 게산 결과 이므로 result 에 저장 후 Stack 메모리 해제
            result = Top(Stack);
            Pop(Stack);
            DisposeStack(Stack);

            break;
        }

        int value_first = Top(Stack);
        Pop(Stack);
        int value_second = Top(Stack);
        Pop(Stack);

        // value_second (연산기호) value_first

        switch (text){
            
            case '^' : {        // 23^ == 2^3
                if (value_first == 0){  // 20^ = 2^0 = 1
                    value_second = 1;

                }   else{
                    int temp = value_second;
                    for (int i = 1; i < value_first; i++){
                        value_second *= temp;
                    }
                }

                Push(value_second, Stack);
                break;
            }

            case '*' : {
                value_second *= value_first;
                Push(value_second, Stack);
                break;
            }
            case '/' : {
                value_second /= value_first;
                Push(value_second, Stack);
                break;
            }
            case '%' : {        // 32% == 3 % 2
                value_second %= value_first;
                Push(value_second, Stack);
                break;
            }

            case '+' : {
                value_second += value_first;
                Push(value_second, Stack);
                break;
            }
            case '-' : {
                value_second -= value_first;
                Push(value_second, Stack);
                break;
            }
        }

        postfix++;
    }
    
    return result;
}