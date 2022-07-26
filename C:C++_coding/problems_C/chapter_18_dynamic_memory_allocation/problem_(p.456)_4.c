#include <stdio.h>
#include <stdlib.h>

// 문제 4 (p.460) : 구조체에서 이전 노드와 다음 노드를 포함해서 코드 작성하기(?) 
// + head의 previous 노드가 tail 가르키도록, tail의 next 노드가 head 가르키도록

struct Data{
    int inside;
    struct Data *next;
    struct Data *previous;
};

struct Data *first_create(int inside);
struct Data *append_create(struct Data *pre_location, int inside);
void head_and_tail(struct Data *current_location);
void *link(struct Data *input, struct Data *previous);
void print(struct Data *head);

int main() {
    printf("\ncode_start\n\n");

    struct Data *num_1 = first_create(1);
    struct Data *num_2 = append_create(num_1, 2);
    struct Data *num_3 = append_create(num_2, 3);

    struct Data *new_num = first_create(5);
    link(new_num, num_1);

    head_and_tail(num_1);

    print(num_1);

    printf("\n\ncode_end\n\n");
    return 0;
}

struct Data *first_create(int inside){
    struct Data *new = (struct Data *)malloc(sizeof(struct Data));
    new->inside = inside;
    new->previous = NULL;
    new->next = NULL;
    return new;
}

struct Data *append_create(struct Data *pre_location, int inside){
    struct Data *new = (struct Data *)malloc(sizeof(struct Data));
    new->inside = inside;
    new->previous = pre_location;
    new->next = NULL;

    pre_location->next = new;

    return new;
}

void head_and_tail(struct Data *current_location){
    struct Data *check = (struct Data *)malloc(sizeof(struct Data));
    check = current_location->previous;

    while (current_location->next){
        current_location = current_location->next;
    }
    while (check->previous){
        check = check->previous;
    }

    check->previous = current_location;
    current_location->next = check;
}

void *link(struct Data *input, struct Data *previous){
    input->previous = previous;
    input->next = previous->next;

    previous->next->previous = input;
    previous->next = input;
}

void print(struct Data *head){
    while (head){
        printf("inside data : %d\n", head->inside);
        head = head->next;
    }
}

// 모르겠는 점 : 디버깅을 못해서 뭐가 문제인지 정확하게 모르겠음.... head_and_tail 함수에서 뭔가 문제가 있는 것 같은데... 뭐가 틀린거지????

// 진도 : p.456