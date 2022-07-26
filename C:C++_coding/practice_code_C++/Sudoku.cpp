#include <iostream>

// 스도쿠 문제 : 정답인지 아닌지

class Table{
    private :
    int array[9][9];

    bool first_result = true;           // 가로, 세로 확인한 결과
    bool second_result = true;          // 블록값 확인한 결과

    public :
    Table(int (*input_array)[9]){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                array[i][j] = input_array[i][j];
            }
        }
    }
    Table(){}
    ~Table(){}

    bool check_row(int current_row);                        // 가로 확인하는 함수
    bool check_collum(int current_collum);                  // 세로 확인하는 함수
    bool check_block(int current_row, int current_collum);  // 블록 확인하는 함수
    
    void total_check();                                     // 위 세 함수 같이 생각할 함수

    void print_array(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    int array[9][9];
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int temp;
            std::cin >> temp;
            array[i][j] = temp;
        }
        std::cout << std::endl;
    }
    
    Table test(array);
    test.print_array();

    test.total_check();
    
    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


bool Table::check_row(int current_row){                         // 가로값 확인하는 함수

    for (int i = 0; i < 9; i++){
        int first_value = array[current_row][i];

        for (int j = i + 1; j < 9; j++){
            if (first_value == array[current_row][j]) {return false;}
        }
    }

    return true;
}
bool Table::check_collum(int current_collum){                   // 세로값 확인하는 함수

    for (int i = 0; i < 9; i++){
        int first_value = array[i][current_collum];

        for (int j = i + 1; j < 9; j++){
            if (first_value == array[j][current_collum]) {return false;}
        }
    }

    return true;
}
bool Table::check_block(int current_row, int current_collum){   // 블록값 확인하는 함수

    // 이 함수는 각 블록값의 첫번째 원소의 row, collum을 인수로 받음.

    for (int i = current_row; i < current_row + 3; i++){
        for (int j = current_collum; j < current_collum + 3; j++){
            
            int first_value = array[i][j];      // i, j 가 증가하면서 첫번째, 두번째 원소값 등 계속 올라감.

            int count = 0;
            // first_value와 같은 값을 같는 원소 수를 셈.

            for (int k = i; k < current_row + 3; k++){
                for (int l = j; l < current_collum  + 3; l++){
                    if (first_value == array[k][l]) {count++;}  // 만약 first_value와 같은 값이 있다면 count++
                }
            }

            // 위의 k, l은 i, j 값과 같은 수부터 시작이므로 블록 내에 같은 값이 있다면 count 는 2 이상이 됨.
            // 즉 first_value 와 같은 원소는 자기 자신밖에 없을 것이므로 count > 2 면 즉시 return false

            if (count != 1) {return false;}
        }
    }

    // 아무 이상 없으면 return true
    return true;
}

void Table::total_check(){
    std::cout << std::endl;

    for (int i = 0; i < 9; i++){        // 일단 가로 확인
        first_result = check_row(i);    // first_result에 true or false 넣음
        if (first_result == false) {std::cout << "False" << std::endl; return;}
    }
    for (int i = 0; i < 9; i++){        // 세로 확인
        first_result = check_collum(i); // first_result에 true or false 넣음
        if (first_result == false) {std::cout << "False" << std::endl; return;}
    }

    for (int i = 0; i != 9; i += 3){    // 블록값 확인 : 각 블록값 첫번째 원소의 row(i), collum(j) 을 check_block 함수에 인자로 넣음
        for (int j = 0; j != 9; j += 3){
            second_result = check_block(i,j);       // (i,j) : (0,0), (0,3), (0,6), (3,0) ~~ 이런식
            if (second_result == false) {std::cout << "False" << std::endl; return;}
        }
    }

    std::cout << "True" << std::endl;
}

// class 내에서 array[9][9] 지정, 값 넣음 (row, collum)

/*
스도쿠는 가로, 세로에서 자신과 같은 숫자가 있으면 안됨 + 자기 배열(?)에서 자신과 같은 수가 있으면 안됨 -- > 함수 두개

9 5 7 6 1 3 2 8 4
4 8 3 2 5 7 1 9 6
6 1 2 8 4 9 5 3 7
1 7 8 3 6 4 9 5 2
5 2 4 9 7 1 3 6 8
3 6 9 5 2 8 7 4 1
8 4 5 7 9 2 6 1 3
2 9 1 4 3 6 8 7 5
7 3 6 1 8 5 4 2 9
--> 정답

5 4 3 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
--> 오답

*/
