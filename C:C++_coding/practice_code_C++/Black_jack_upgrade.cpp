#include <iostream>

// 블랙잭 업그레이드 버전

void sort(int *array);
void simplify(int *array, int ideal_value);
int calculate(int *array, int ideal_value);

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    int total_num;
    int ideal_value;
    std::cin >> total_num;
    std::cin >> ideal_value;

    int *array = new int[total_num];
    for (int i = 0; i < total_num; i++) {std::cin >> array[i];}
    array[total_num] = 0;
    
    sort(array);
    simplify(array, ideal_value);

    int value = calculate(array, ideal_value);
    std::cout << value << std::endl;

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

void sort(int *array){
    int size = 0;
    while (array[size] != 0){
        size++;
    }
    int *temp = new int[size];

    for (int i = size - 1; i >= 0; i--){
        int count = 0;
        int max = 0;
        max = array[0];
        for (int j = 0; j < size; j++){
            if (max < array[j]) {max = array[j]; count = j;}
        }
        temp[i] = max;
        array[count] = 0;
    }

    for (int i = 0; i < size; i++){
        array[i] = temp[i];
    }

    delete [] temp;
}
void simplify(int *array, int ideal_value){
    int size = 0;
    while (array[size] != 0){
        size++;
    }
    int test;
    int maximum, minimum = array[0];
    int count = 1;

    for (int i = size - 1; i >= 0; i--){
        count++;
        int testing = 0;
        maximum = array[i];
        test = maximum + minimum;
        if (test >= ideal_value) {array[i] = 0; testing = 1;}
        else if (test + array[1] > ideal_value) {array[i] = 0; testing = 1;}

        if (testing == 0) break;
        
    }

    int *temp = new int[count];
    for (int i = 0; i < count; i++){
        temp[i] = array[i];
    }
    array = new int[count];
    for (int i = 0; i < count; i++){
        array[i] = temp[i];
    }

    delete [] temp;
}

int calculate(int *array, int ideal_value){
    int size = 0;
    while (array[size] != 0){
        size++;
    }

    int *value = new int[(size) * (size - 1) * (size - 2) / 6];
    int count = 0;

    int first, second;
    for (int i = size - 1; i >= 0; i--){
        first = array[i];
        second = array[i - 1];

        int test = ideal_value - (first + second);          // 마지막 이상적인 원소 값

        for (int j =  i - 2; j >= 0; j--){
            if (test - array[j] >= 0) {value[count] = first + second + array[j]; count++; break;}
        }
        if (value[count - 1] == ideal_value) break;
    }

    int max = value[0];
    for (int i = 1; i < count; i++){
        if (max < value[i]) max = value[i];
    }

    delete [] value;

    return max;
}







// 100 --> 98
// (원본)
// 16 85 30 14 95 63 52 87


// 14 16 30 52 63

// 63 + 14 = 77
// 98 = 52 + 16 + 30

// 일단 1차 간단화 : 배열 중 최댓값 + 최소값 > 설정값 이면 그 최댓값은 조합에 넣어질 수 없음.
// 2차 간단화 : (최댓값 + 최솟값) + 2번째 최솟값 > 설정값 이면 그 최댓값 또한 조합에 넣어질 수 없음.
// 3차 마지막 : 마지막 남은 배열들 값으로 값을 더하면서 그 값 중 최댓값을 구함
/* 3차
(최댓값 + 2차 최댓값) 을 묵은 다음 생각함. 즉, (마지막 원소 + 마지막에서 두번째 원소) 로 묶어서 생각하는데
남아있는 값 중 가장 큰 값을 여기에 더해 보면서 100 이하인 값이 나올때까지 돌림. 만약 100이 나오면 그 값이 이상적인 값이므로 그냥 끝내면 됨.
100이 아닌 값이 나오면 그 수를 일단 저장하고 (2차 최댓값 + 3차 최댓값) 으로 묶어서 똑같이 생각함.
만약 (2차 + 3차) 에서 나온 값이 앞에 나온 값도다 크면 값 바꾸고 다음으로 넘어감.

[일단 필요한 것]
1. 입력한 배열 정렬 알고리즘
2. 정렬 후 1, 2차 간단화 알고리즘
3. 유효한 값에서 계산 돌릴 알고리즘

*/

/*

8 100
16 85 30 14 95 63 52 87
--> 98

5 21
1 2 3 4 5
--> 12

*/





// 진도 : p.364