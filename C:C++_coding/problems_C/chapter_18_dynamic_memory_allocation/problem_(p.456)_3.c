#include <stdio.h>
#include <stdlib.h>

// 문제 3 (p.460) : 구조체에서 이전 노드와 다음 노드를 포함해서 코드 작성하기(?)

struct Data{
    int inside;
    struct Data *next;
    struct Data *previous;
};

struct Data *first_create(int inside);
struct Data *append_create(struct Data *pre_location, int inside);
void *link(struct Data *input, struct Data *previous);
void print(struct Data *head);

int main() {
    printf("\ncode_start\n\n");

    struct Data *num_1 = first_create(1);
    struct Data *num_2 = append_create(num_1, 2);
    struct Data *num_3 = append_create(num_2, 3);

    struct Data *new_num = first_create(5);
    link(new_num, num_1);

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

// 모르겠는 점 : 코드 돌리면 정상적으로 작동은 하는데... 디버깅 하면 오류가 뜸. first_create, append_create 에서 오류가 뜸.
// expected unqualified-id 라고 뜨는데... 뭔지 잘 모르겠음;

// 진도 : p.456