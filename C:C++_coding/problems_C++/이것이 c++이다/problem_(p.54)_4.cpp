#include <iostream>

// 이것이 c++이다.
// 문제 4 (p.54) : 참조 형식 매개변수를 이용해 void 형 swap 함수 만들기

void swap(int &first, int &second);

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    int num_1 = 1;
    int num_2 = 2;
    int arr_1[5] = {0,1,1,1,1};
    int arr_2[5] = {2,2,2,2,2};

    swap(num_1, num_2);

    std::cout << num_1 << num_2 << std::endl;
    
    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

void swap(int &first, int &second){
    auto temp = first;
    first = second;
    second = temp;
}

// 아쉬운 점 : auto 이용해서 arr_1, arr_2 도 바꿀 수 있도록 만들고 싶었는데 그러지 못함.
// auto &a = arr_1 은 되지만 int &a = arr_1 은 안됨. 그래서 이것까지 포함해서 swap 함수를 만드려면 swap의 인자가 그냥 int 면 안되고 다른거(뭔지는 모르겠음)여야 될 듯.

// 진도 : p.54