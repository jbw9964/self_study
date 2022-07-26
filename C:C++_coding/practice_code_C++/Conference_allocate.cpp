#include <iostream>

// 회의실 배정 문제

class Stack{
    private :
    int begin;
    int end;
    int size;

    int layer = 0;

    bool valid = true;

    public :
    Stack(int begin, int end) : begin(begin), end(end), valid(true), layer(0) {size = end - begin;}
    Stack(const Stack &input);
    Stack(const Stack *input);
    ~Stack() {valid = false;}

    int show_begin() const {return begin;}
    int show_end() const {return end;}
    int show_size() const {return size;}
    int show_layer() const {return layer;}

    bool show_valid() const {return valid;}

    void show_stack() const;
    void show_stack_result() const;

    void set_layer(int input) {layer = input;}
    void set_valid() {valid = false;}
};

Stack::Stack(const Stack &input){
    begin = input.begin;
    end = input.end;
    size = begin - end;
    layer = input.layer;
    valid = true;
}
Stack::Stack(const Stack *input){
    begin = input->begin;
    end = input->end;
    size = begin - end;
    layer = input->layer;
    valid = true;
}

void Stack::show_stack() const {
    std::cout << "[" << begin << " ~ " << end << "] --> layer : " << layer << ", valid : ";
    if (valid == true) std::cout << "true";
    else std::cout << "false";
}
void Stack::show_stack_result() const {
    std::cout << "[" << begin << " ~ " << end << "]";
}

class Conference{
    private :
    int total_numbers;
    int total_valid_numbers;

    Stack *meetings[100];
    Stack *result[100];

    public :
    Conference(int total_numbers);

    void cal_layer();               // valid 한 스택들 중, 각 true인 스택마다 겹치는 ture 스택 개수를 계산해서 layer 변경하는 함수
    
    int show_max_layer() const;    // true 인 스택 중, 가장 큰 layer 값을 리턴하는 함수
    int show_stack_position(int max_layer) const;   // int max_layer 와 같은 스택 중, size가 가장 작은 스택의 위치를 리턴하는 함수

    void edit_schedule();           // true 한 스택 중, layer 값이 가장 큰 스택을 false 시키는 함수. 그런 다음 다시 cal_layer 함수 호출함
    void calculate();               // edit_schedule 해서 max_layer 가 1이 될때까지 돌리는 함수. 그리고 마지막으로 결과를 result 스택에 넣는 함수.

    void show_meeting() const;      // stack 들 값 보기
    void show_result() const;       // 결과 스택 보기
};

Conference::Conference(int total_numbers) : total_numbers(total_numbers){
    for (int i = 0; i < total_numbers; i++){
        int begin, end;
        std::cin >> begin;
        std::cin >> end;
        meetings[i] = new Stack(begin, end);
    }
    cal_layer();
    std::cout << std::endl;
    show_meeting();
    std::cout << std::endl;
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    int number;
    std::cin >> number;

    Conference a(number);
    
    a.calculate();
    a.show_result();

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

void Conference::cal_layer(){       // valid 한 스택들 중, 각 true인 스택마다 겹치는 ture 스택 개수를 계산해서 layer 변경하는 함수
    for (int i = 0; i < total_numbers; i++){

        if (meetings[i]->show_valid() == false) continue;

        int begin = meetings[i]->show_begin();
        int end = meetings[i]->show_end();

        int count = 0;
        for (int j = 0; j < total_numbers; j++){
            if (meetings[j]->show_valid() == true && !(begin >= meetings[j]->show_end() || end <= meetings[j]->show_begin()))
            count++;
        }
        count--;
        meetings[i]->set_layer(count);
    }
}

int Conference::show_max_layer() const {    // true 인 스택 중, 가장 큰 layer 값을 리턴하는 함수
    int max;
    int i;

    for (i = 0; i < total_numbers; i++){
        if (meetings[i]->show_valid() == true) {max = meetings[i]->show_layer(); break;}
    }

    for (i = 0; i < total_numbers; i++){
        if (meetings[i]->show_valid() == false) continue;

        if (meetings[i]->show_layer() > max) max = meetings[i]->show_layer();
    }

    return max;
}
int Conference::show_stack_position(int max_layer) const {  // int max_layer 와 같은 스택 중, size가 가장 작은 스택의 위치를 리턴하는 함수
    int size;
    int i;

    for (i = 0; i < total_numbers; i++){
        if (meetings[i]->show_layer() == max_layer && meetings[i]->show_valid() == true) {size = meetings[i]->show_size(); break;}
    }

    int count = i;
    for (i = 0; i < total_numbers; i++){
        if (meetings[i]->show_valid() == false) continue;

        if (meetings[i]->show_size() < size && meetings[i]->show_layer() == max_layer) {size = meetings[i]->show_size(); count = i;}
    }

    return count;
}

void Conference::edit_schedule(){   // true 한 스택 중, layer 값이 가장 큰 스택을 false 시키는 함수. 그런 다음 다시 cal_layer 함수 호출함
    int max_layer = show_max_layer();
    int min_position = show_stack_position(max_layer);

    meetings[min_position]->set_valid();

    cal_layer();
}
void Conference::calculate(){   // edit_schedule 해서 max_layer 가 1이 될때까지 돌리는 함수. 그리고 마지막으로 결과를 result 스택에 넣는 함수.
    int max_layer;
    cal_layer();

    while (true){
        max_layer = show_max_layer();

        if (max_layer < 1) break;

        edit_schedule();
    }

    for (int i = 0; i < total_numbers; i++){
        if (meetings[i]->show_valid() == true) {result[total_valid_numbers] = meetings[i]; total_valid_numbers++;}
    }
}

void Conference::show_meeting() const {
    for (int i = 0; i < total_numbers; i++){
        std::cout << "[" << i + 1 << "] : ";
        meetings[i]->show_stack();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Conference::show_result() const {
    std::cout << "show_result" << std::endl;
    std::cout << std::endl;

    std::cout << total_valid_numbers << " # ";
    for (int i = 0; i < total_valid_numbers; i++){
        result[i]->show_stack_result();
        if (i != total_valid_numbers - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}


/*  해결 논리 생각해보기
약간 설명이 이상할 수도 있음. 일단 입력값들을 다 받음. 데이터 구조는 시작, 끝나는 시간, 회의하는 시간 등 으로 구성됨 
제일 중요한 게 입력받은 값에서 어떻게 계산해서 자신의 시간표 중 겹치는(?) 개수를 토대로 생각해야됨. 그런다음 겹치는 개수가 가장 큰 시간표를 없애는 거임.

1. 겹치는 개수가 가장 큰 블록(?)을 없앤다.
2. 만약 겹치는 개수가 가장 큰 블록이 여러개라면, 회의하는 시간이 가장 큰 시간을 없앤다.
3. 겹치는 개수가 2개라면 무조건 그 블록을 없애야만 우리 값에 가까워진다.
4. 겹치는 개수가 1개면 좀 생각해봐야할 듯
5. 블록 중 겹치는 수가 0이면 그건 무조건 넣는게 이득이니까 계산에서 제외한다. (어떻게 구현할지는 생각 해봐야 됨.)
*/

/*
11
1 4
2 13
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
12 14

--> 4 # [1, 4], [5, 7], [8, 11], [12, 14]

[1 ~ 3] [2 ~ 6] [3 ~ 5] [4 ~ 5]
1, 2    3, 4    2, 2    2, 1
*/
