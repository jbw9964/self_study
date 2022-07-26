#include <iostream>

// 문제 1 (p.68) : 클래스 활용해서 달력 계산기 만들기

class Date{
    private :
    int year = 0;
    int month = 0;
    int day = 3;

    public :
    void set_date(int year_, int month_, int day_);
    void add_day(int input);
    void add_month(int input);
    void add_year(int input);
    
    void check();
    void show_date();
    Date() = default;
    
};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Date date;

    int loop = 1;
    while (loop == 1){
        int answer;
        std::cout << "1. Set date\n2. Add day\n3. Add month\n4. Add year\n5. show date\n6. Exit" << std::endl;
        std::cout << "answer : ";
        std::cin >> answer;

        switch (answer){
        case 1 :
        {
            int year, month, day;
            std::cout << "year : ";
            std::cin >> year;
            std::cout << "month : ";
            std::cin >> month;
            std::cout << "day : ";
            std::cin >> day;
            date.set_date(year, month, day);
            break;
        }

        case 2 :
        {
            int input;
            std::cout << "add day input : ";
            std::cin >> input;
            date.add_day(input);
            break;
        }

        case 3 :
        {
            int input;
            std::cout << "add month input : ";
            std::cin >> input;
            date.add_month(input);
            break;
        }

        case 4 :
        {
            int input;
            std::cout << "add year input : ";
            std::cin >> input;
            date.add_year(input);
            break;
        }

        case 5 :
        {date.show_date(); break;}
        case 6 :
        {loop = 0; break;}
        default :
        {std::cout << "You put wrong answer." << std::endl; break;}
        }
    }

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

void Date::set_date(int year_, int month_, int day_){
    year = year_;
    month = month_;
    day = day_;
    show_date();
}

void Date::add_day(int input){
    day += input;
    check();
    show_date();
}

void Date::add_month(int input){
    month += input;
    check();
    show_date();
}

void Date::add_year(int input){
    year += input;
    show_date();
}

void Date::check(){

    int loop = 1;
    while (loop == 1){
        loop = 0;
        if (day > 32){
            day -= 31;
            month++;
            loop = 1;
        }
        if (month > 13){
            month -= 12;
            year++;
            loop = 1;
        }
    }
    if (day >= 29 && month == 2) {day -= 28; month++;}
    if (day >= 30){
        if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {day -= 30; month++;}
        else if (day >= 32){day -= 31; month++;}
    }
    

}

void Date::show_date(){
    std::cout << std::endl << year << "." << month << "." << day << std::endl << std::endl;
}

// 궁금한 점 : 디폴트 생성자랑 class private 에서 year, month, day = 0 한거랑
// 근본적으로 어떤 차이가 있는건지 잘 모르겠음.
// 디폴트 생성자는 쓰레기 값이여도 상관없으니까 그냥 초기화만 시켜둔 건가?
// 그리고 디폴트 생성자랑 그냥 생성자랑 큰 차이를 모르겠음.
// 쓰레기 값으로 초기화 시키는 거면 도대체 디폴트 생성자는 왜 씀??

// 진도 : p.83