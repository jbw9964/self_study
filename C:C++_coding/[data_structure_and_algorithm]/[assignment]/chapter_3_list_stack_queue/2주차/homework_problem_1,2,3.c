#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 2주차 과제
1. 다음 swapWithNext() 함수는 beforep가 가리키는 노드의 다음 노드와 그 다음 노드의 위치를 변경하여 자리바꿈을 수행한다.
이 함수의 내부 구현 코드를 C언어로 보이시오. [20점]
void swapWithNext(PtrToNode beforep);

2. 두개의 정렬된 리스트 L1, L2가 주어졌을 때 L1과 L2의 교집합을 리턴하는 함수 intersection()의 내부 구현 코드를 C언어로 보이시오 [20점]
List intersection(const List L1, const List L2);

3. 두개의 정렬된 리스트 L1, L2가 주어졌을 때 L1과 L2의 합집합을 리턴하는 함수 union()의 내부 구현 코드를 C언어로 보이시오 [10점]
List union(const List L1, const List L2);

+ 2, 3번 문제의 List 정렬 알고리즘은 따로 만들지 않았음.
*/

struct List{
    int value;
    struct List* next;
    bool is_header;
};

void append(struct List* header, int value){

    if (!header->is_header) {printf("The input List is not a header.\n"); return;}

    if (header->next == NULL){
        struct List* temp = (struct List*)malloc(sizeof(struct List));
        temp->value = value;
        temp->next = NULL;
        temp->is_header = false;

        header->next = temp;
        return;
    }

    struct List* position = header->next;

    while (position->next){
        position = position->next;
    }

    struct List* temp = (struct List*)malloc(sizeof(struct List));
    temp->value = value;
    temp->next = NULL;
    temp->is_header = false;

    position->next = temp;
}
int size(struct List header){

    if (!header.is_header) {printf("The input List is not a header.\n"); return 0;}

    int count = 0;
    struct List* temp = header.next;

    while (temp){
        count++;
        temp = temp->next;
    }

    return count;
}
void print_list(struct List header){

    if (!header.is_header) {printf("The input List is not a header.\n"); return;}

    struct List* temp = &header;
    
    if (!temp->next) {printf("There's no value in list\n"); return;}
    temp = temp->next;

    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
void point_print_list(struct List *header){

    if (!header->is_header) {printf("The input List is not a header.\n"); return;}

    struct List* temp = header;
    
    if (!temp->next) {printf("There's no value in list\n"); return;}
    temp = temp->next;

    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void swap_with_next(struct List* input);      // 문제 1 : input->next 와 input->next->next 의 위치를 변경하는 함수
struct List* intersection(struct List header_1, struct List header_2);    // 문제 2 : header_1 과 header_2 중 같은 값들이 들어있는 새로운 List의 헤더 리턴
struct List* union_fucntion(struct List header_1, struct List header_2);  // 문제 3 : header_1 과 header_2 의 모든 값이 들어있는 새로운 List의 헤더 리턴

bool check_array_intersec(int *array, int size, int value);    // array 내 value 값이 있으면 true 리턴

int main(){
    printf("\ncode_start\n\n\n");

    struct List header_1;
    struct List header_2;
    
    header_1.next = NULL;
    header_2.next = NULL;
    header_1.is_header = true;
    header_2.is_header = true;

    int num_1, num_2;
    printf("num 1 : ");
    scanf("%d", &num_1);
    printf("num 2 : ");
    scanf("%d", &num_2);

    for (int i = 1; i < num_1 + 1; i++){
        append(&header_1, 2*i);
    }
    for (int i = 1; i < num_2 + 1; i++){
        append(&header_2, 3*i);
    }
    printf("header 1 : ");
    print_list(header_1);
    printf("header 2 : ");
    print_list(header_2);

    struct List *intersec_list = intersection(header_1, header_2);
    printf("\nintersection list : ");
    point_print_list(intersec_list);

    struct List *union_list = union_fucntion(header_1, header_2);
    printf("union list : ");
    point_print_list(union_list);

    printf("\n\n\ncode_end\n\n");
    return 0;
}

void swap_with_next(struct List* input){  // 문제 1 : input->next 와 input->next->next 의 위치를 변경하는 함수
    /* 
    만약 input 으로 header 가 들어오면 첫번째, 두번째 list 를 바꿈. 물론 두번째, 세번째가 바뀌도록 코딩 가능함
    그런데 문제 의도가 정확히 어떤건지 모르겠어서 첫번째, 두번째 list 를 바꾸는 것으로 만들었음.
    두번째, 세번째가 바뀌도록 만들려면 input->is_header = true 를 이용하면 됨.
    */
    if (!input->is_header) {printf("The input List is not a header.\n"); return;}
    if (!input->next) {printf("There's no List at input->next.\n"); return;}

    struct List* temp_1 = input->next;
    struct List* temp_2 = input->next->next;
    struct List* temp_3 = input->next->next->next;

    input->next = temp_2;
    temp_2->next = temp_1;
    temp_1->next = temp_3;
}
struct List* intersection(struct List header_1, struct List header_2){    // 문제 2 : header_1 과 header_2 중 같은 값들이 들어있는 새로운 List의 헤더 리턴
    /*
    header_1, header_2 가 정렬된 리스트여야 제대로 작동함
    */

    if (!(header_1.is_header && header_2.is_header)) {printf("The input List are not header of the list.\n"); return NULL;}
    if (header_1.next == NULL || header_2.next == NULL) {printf("The input List is empty.\n"); return NULL;}

    int temp_size_1 = size(header_1);
    int temp_size_2 = size(header_2);
    int *array_1 = (int *)malloc(sizeof(int) * temp_size_1);
    int *array_2 = (int *)malloc(sizeof(int) * temp_size_2);
    int *result_array = (int *)malloc(sizeof(int) * temp_size_1);

    struct List* temp = header_1.next;
    for (int i = 0; i < temp_size_1; i++){
        array_1[i] = temp->value;
        temp = temp->next;
    }

    temp = header_2.next;
    for (int i = 0; i <temp_size_2; i++){
        array_2[i] = temp->value;
        temp = temp->next;
    }

    int count = 0;
    for (int i = 0; i < temp_size_1; i++){
        if (check_array_intersec(array_2, temp_size_2, array_1[i]) == true){
            result_array[count] = array_1[i];
            count++;
        }
    }

    if (count == 0) {return NULL;}

    struct List *result_list = (struct List*)malloc(sizeof(struct List));
    result_list->is_header = true;
    temp = result_list;

    for (int i = 0; i < count; i++){
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = result_array[i];
        result_list->is_header = false;
        result_list->next = NULL;
    }

    result_list = temp;    

    return result_list;
}
struct List* union_fucntion(struct List header_1, struct List header_2){  // 문제 3 : header_1 과 header_2 의 모든 값이 들어있는 새로운 List의 헤더 리턴
    /*
    header_1, header_2 가 정렬된 리스트여야 제대로 작동함
    */

    if (!(header_1.is_header && header_2.is_header)) {printf("The input List are not header of the list.\n"); return NULL;}
    if (header_1.next == NULL || header_2.next == NULL) {printf("The input List is empty.\n"); return NULL;}

    struct List *result_list = (struct List*)malloc(sizeof(struct List));
    result_list->is_header = true;
    result_list->next = NULL;

    struct List *temp_1 = header_1.next;
    struct List *temp_2 = header_2.next;
    struct List *header_position = result_list;

    while (true){

        if (!(temp_1->next || temp_2->next)) {break;}

        int value_1 = temp_1->value;
        int value_2 = temp_2->value;

        if (!temp_1->next){
            if (value_1 < value_2 && !temp_1->is_header){
                result_list->next = (struct List*)malloc(sizeof(struct List));
                result_list = result_list->next;
                result_list->value = value_1;
                result_list->is_header = false;
                result_list->next = NULL;

                temp_1->is_header = true;

                continue;
            }

            result_list->next = (struct List*)malloc(sizeof(struct List));
            result_list = result_list->next;
            result_list->value = value_2;
            result_list->is_header = false;
            result_list->next = NULL;
            temp_2 = temp_2->next;

            continue;

        }   else if (!temp_2->next){
            if (value_1 > value_2 && !temp_2->is_header){
                result_list->next = (struct List*)malloc(sizeof(struct List));
                result_list = result_list->next;
                result_list->value = value_2;
                result_list->is_header = false;
                result_list->next = NULL;

                temp_2->is_header = true;

                continue;
            }

            result_list->next = (struct List*)malloc(sizeof(struct List));
            result_list = result_list->next;
            result_list->value = value_1;
            result_list->is_header = false;
            result_list->next = NULL;
            temp_1 = temp_1->next;
            
            continue;
        }

        if (value_1 < value_2){
            result_list->next = (struct List*)malloc(sizeof(struct List));
            result_list = result_list->next;
            result_list->value = value_1;
            result_list->is_header = false;
            result_list->next = NULL;
            temp_1 = temp_1->next;

        }   else if (value_1 > value_2){
            result_list->next = (struct List*)malloc(sizeof(struct List));
            result_list = result_list->next;
            result_list->value = value_2;
            result_list->is_header = false;
            result_list->next = NULL;
            temp_2 = temp_2->next;

        }   else{
            result_list->next = (struct List*)malloc(sizeof(struct List));
            result_list = result_list->next;
            result_list->value = value_1;
            result_list->is_header = false;
            result_list->next = NULL;
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }
    }

    if (temp_1->is_header && !temp_2->is_header){           // temp_1 값만 저장됬을 때
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_2->value;
        result_list->is_header = false;
        result_list->next = NULL;

        temp_1->is_header = false;
        temp_2->is_header = false;
        result_list = header_position;

        return result_list;

    }   else if (!temp_1->is_header && temp_2->is_header){  // temp_2 값만 저장됬을 때
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_1->value;
        result_list->is_header = false;
        result_list->next = NULL;

        temp_1->is_header = false;
        temp_2->is_header = false;
        result_list = header_position;

        return result_list;
    }

    // temp_1, temp_2 모두 저장 안됬을 때
    if (temp_1->value < temp_2->value){
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_1->value;
        result_list->is_header = false;

        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_2->value;
        result_list->is_header = false;
        result_list->next = NULL;

    }   else if (temp_1->value > temp_2->value){
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_2->value;
        result_list->is_header = false;
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_1->value;
        result_list->is_header = false;
        result_list->next = NULL;
    }   else{
        result_list->next = (struct List*)malloc(sizeof(struct List));
        result_list = result_list->next;
        result_list->value = temp_1->value;
        result_list->is_header = false;
        result_list->next = NULL;
    }

    temp_1->is_header = false;
    temp_2->is_header = false;

    result_list = header_position;

    return result_list;
}

bool check_array_intersec(int *array, int size, int value){     // array 내 value 값이 있으면 true 리턴

    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if (array[mid] == value){
            return true;
        }   else if (array[mid] > value){
            high = mid - 1;
        }   else {
            low = mid + 1;
        }
    }
    
    return false;
}
