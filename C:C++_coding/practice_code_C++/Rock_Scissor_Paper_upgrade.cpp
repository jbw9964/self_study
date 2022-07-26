#include <iostream>
#include <random>

// 가위바위보 + 묵찌빠 만들기

int calculate_normal(int computer, int user);
int calcaulate_special(int computer, int user, int points);
void print_status(int computer, int user);

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    int computer;
    int user;

    int points = 0;     /* 결국에 묵찌빠까지 이기려면 2번 연속으로 '이겨야' 되니까 이길수록 1씩 늘거나 줄거나 (사실 곱하지만) 하는 방식으로 생각
    
    points = 1 : 기계가 가위바위보만 이김,  points = -1 : 사람이 가위바위보만 이김, points = 0 : 가위바위보에서 비김
    points = 2 : 기계가 묵찌빠에서도 이김   points = -2 : 사람이 묵찌빠에서도 이김
    */

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,3);

    // 첫번째 그냥 가위바위보. : 비기거나 묵찌빠에서 승부가 안났을 때 계속
    while (points == 0 && abs(points) != 2){
        computer = dis(gen);
        std::cout << "computer : " << computer << std::endl;        // 확인하기 편하게 컴퓨터가 뭐 냈는지 보여줌

        std::cout << "==============================>> NORMAL Rock, Scissor, Paper <<==============================" << std::endl;
        std::cout << "1. Rock\n2. Scissor\n3. Paper\n4. Exit program" << std::endl;
        std::cout << "\nInput : ";
        std::cin >> user;
        if (user == 4) {break;}
        else {points = calculate_normal(computer, user);}

        print_status(computer, user);

        if (points == 1) {std::cout << "Winner : <Computer>" << std::endl;}
        else if (points == -1) {std::cout << "Winner : <User>" << std::endl;}
        else {std::cout << "<Draw>" << std::endl;}

        // 묵찌빠 : 묵찌빠 승부가 안났을 때 + 첫번째 가위바위보에서 비기지 않았을 때
        while (abs(points) != 2 && points != 0){
            computer = dis(gen);
            std::cout << "computer : " << computer << std::endl;

            std::cout << "==============================>> SPECIAL Rock, Scissor, Paper <<==============================" << std::endl;
            std::cout << "1. Rock\n2. Scissor\n3. Paper\n4. Exit program" << std::endl;
            std::cout << "\nInput : ";
            std::cin >> user;
            if (user == 4) {std::cout << "Exiting program" << std::endl; return 0;}
            else {points *= calcaulate_special(computer, user, points);}

            print_status(computer, user);
            if (points == 1) {std::cout << "Winner : <Computer>" << std::endl;}
            else if (points == -1) {std::cout << "Winner : <User>" << std::endl;}
        }
    }

    if (points == 2) {std::cout << "Final Winner : <Computer>" << std::endl;}
    else if (points == -2) {std::cout << "Final Winner : <User>" << std::endl;}

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 평범한 가위바위보
int calculate_normal(int computer, int user){       // result --> 0 : 무승부, 1 : 컴퓨터가 이김, -1 : 유저가 이김
    int result = 0;
    if (computer == user) {return 0;}
    else if (computer - user == -1 || computer - user == 2){
        result = 1;
    }   else result = -1;

    return result;
}

// 묵찌빠
int calcaulate_special(int computer, int user, int points){     // result --> 2 : 승부 남, 1 : 컴퓨터가 가위바위보 이김, -1 : 유저가 가위바위보 이김
    int result = 0;
    if (computer == user) {return 2;}
    else if (computer - user == -1 || computer - user == 2){
        result = 1;
    }   else result = -1;

    if (points == -1 && result == -1) {return 1;}           // 만약 유저가 이기고 있었는데 또 유저가 가위바위보 이기면 -1 * -1 이어서 1이 됨. (그냥 -1이어야 되는데) 그거 방지하려고 return 1

    return result;
}

// 보기 편하게 컴퓨터, 유저 뭐 냈는지 보여주는 함수
void print_status(int computer, int user){
    int answer = computer;
    std::cout << "Computer : ";
    switch (answer){
    case 1 :
        std::cout << "Rock" << std::endl;
        break;
    case 2 :
        std::cout << "Scissors" << std::endl;
        break;
    case 3 :
        std::cout << "Paper" << std::endl;
        break;
    default:
        std::cout << "Wrong input.";
        return;
        break;
    }
    answer = user;
    std::cout << "User : ";
    switch (answer){
    case 1 :
        std::cout << "Rock" << std::endl;
        break;
    case 2 :
        std::cout << "Scissors" << std::endl;
        break;
    case 3 :
        std::cout << "Paper" << std::endl;
        break;
    default:
        std::cout << "Wrong input.";
        return;
        break;
    }
    std::cout << std::endl;
}


// 진도 : p.364