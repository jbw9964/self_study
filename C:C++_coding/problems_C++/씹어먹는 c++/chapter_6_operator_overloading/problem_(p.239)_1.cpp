#include <iostream>

// 문제 1 (p.239) : N 차원 배열을 제공하는 클래스 만들기

//  모르겠다 ㅅㅂ...




// arr[2][2] = 'c' 하면 바뀌는 식
// std::cout << arr[2][2] 하면 출력되는 식

// 기본 생성 : 원소 2개인 3차원 배열

/*
arr[0]  -- arr[0][0]    -- arr[0][0][0]
                        -- arr[0][0][1]
        -- arr[0][1]    -- arr[0][1][0]
                        -- arr[0][1][1]

arr[1]  -- arr[1][0]    -- arr[1][0][0]
                        -- arr[1][0][1]
        -- arr[1][1]    -- arr[1][1][0]
                        -- arr[1][1][1]
*/

class Array{
    int **point_arry;

    friend class Multi_Array;

    public : 
    Array(int elemnets_number){

    }

};

class Multi_Array{
    int dimension;
    char *elemnts_number_arr;

    public :
    Array(int dimension) : dimension(dimension){
        elemnts_number_arr = new char[dimension];
        std::cout << "The arr is " << dmension << " dimensions in arry." << std::endl;
        
        for (int i = 0; i < dimension; i++){
            std::cout << "How many elemnts you want in arr";
            for (int j = 0; j < i; j++) {std::cout << "[0]";}
            
            int num;
            std::cout << "? : ";
            std::cin >> num;

            for (int j = 0; j < num; j++){

            }

        }


    }

};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    

    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


// 진도 : p.239