#include <iostream>
#include <cmath>

// 계산기 만들기

class Calculator{
    private :
    double value = 0;
    std::string variable_name = "Not allocated";

    double previous = 0;

    public :
    Calculator(){}
    Calculator(double input) : value(input) {}
    Calculator(double input, std::string name) : value(input), variable_name(name) {}
    Calculator(const Calculator &input) {value = input.value;}
    
    Calculator operator+(const Calculator &input);
    Calculator operator-(const Calculator &input);
    Calculator operator*(const Calculator &input);
    Calculator operator/(const Calculator &input);
    Calculator operator=(double input) {previous = value; value = input; return *this;}
    
    void println() const {std::cout << value << std::endl;}
    double print_value() const {return value;}
    void push_back() {value = previous;}

    Calculator operator+=(const Calculator &input);
    Calculator operator-=(const Calculator &input);
    Calculator operator*=(const Calculator &input);
    Calculator operator/=(const Calculator &input);
};

Calculator Calculator::operator+(const Calculator &input){
    Calculator temp = (value + input.value);
    return temp;
}
Calculator Calculator::operator-(const Calculator &input){
    Calculator temp = (value - input.value);
    return temp;
}
Calculator Calculator::operator*(const Calculator &input){
    Calculator temp = (value * input.value);
    return temp;
}
Calculator Calculator::operator/(const Calculator &input){
    Calculator temp = (value / input.value);
    return temp;
}

Calculator Calculator::operator+=(const Calculator &input){
    *this = *this + input;
    return *this;
}
Calculator Calculator::operator-=(const Calculator &input){
    *this = *this - input;
    return *this;
}
Calculator Calculator::operator*=(const Calculator &input){
    *this = *this * input;
    return *this;
}
Calculator Calculator::operator/=(const Calculator &input){
    *this = *this / input;
    return *this;
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    int loop_1 = 1;
    Calculator calculator_array[100];
    std::string variable_array[100];

    int total_variable = 0;

    while (loop_1 != 0){
        std::cout << "====================" << std::endl;
        std::cout << "1. Set new variable" << std::endl;
        std::cout << "2. Calculate with varialbes and constants" << std::endl;
        std::cout << "3. Show current variables" << std::endl;
        std::cout << "4. Exit Calculator" << std::endl;
        std::cout << "\nchoose menu : ";
        int answer;
        std::cin >> answer;

        switch (answer){
            case 1 :
            {
                std::cout << "You can set variables up to 100." << std::endl;
                std::cout << "current variable number : " << total_variable << std::endl;
                for (int i = 0; i < total_variable; i++){
                    std::cout << "[" << i + 1 << "] " <<variable_array[i] << " : " << calculator_array[i].print_value() << std::endl;
                }
                std::cout << "\nVariable name : ";
                char name[3];
                std::cin >> name;
                if (name[0] >= '0' && name[0] <= '9') {std::cout << "You should not name the variable as numbers" << std::endl; break;}
                else if (name[1] != 0) {std::cout << "You should set variables name as one letter" << std::endl; break;}

                std::cout << "Value : ";
                int temp;
                std::cin >> temp;

                variable_array[total_variable] = name[0];
                calculator_array[total_variable] = temp;
                total_variable++;

                break;
            }

            case 2 :
            {
                if (total_variable != 0){
                    std::cout << "Current variables" << std::endl;
                    for (int i = 0; i < total_variable; i++){
                        std::cout << "[" << i + 1 << "] " << variable_array[i] << " : " << calculator_array[i].print_value() << std::endl;
                    }
                }


                break;
            }

            case 3 :
            {
                if (total_variable == 0) {std::cout << "There's no variable." << std::endl; break;}
                for (int i = 0; i < total_variable; i++){
                    std::cout << "[" << i + 1 << "] " << variable_array[i] << " : " << calculator_array[i].print_value() << std::endl;
                }
                break;
            }
            case 4 : {loop_1 = 0; break;}
            default : {std::cout << "You put wrong menu." << std::endl; break;}
        }
    }

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 좆박았네. class는 어떻게 진짜 개 대충 만들긴 했지만 이걸 결국에 내가 원하는 모습이 문자열을 통해 입력하는 거라는 걸 까먹었음. ㅅㅂ.
// 그 말인 즉슨 내가 터미널에 'a + b + 1' 이라고 입력하면 그 값이 나오도록 해야되는데 생각해보니 이걸 어떻게 할 수 있는 방법이 아예 생각이 안남.
// ㅅㅂ 좆됐네


// class 형태여도 c = a + b 해도 값 나오도록