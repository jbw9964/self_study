#include <iostream>

// 문제 1 (p.68) : 클래스 활용해서 달력 계산기 만들기

class Date{
    private:
    int year_;
    int month_;
    int day_;

    public:
    int check_day(){
        int result = 0;
        if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12){
            if (day_ > 31){
                day_ -= 31;
                month_++;
                result = 1;
            }
        }   else if (month_ == 2){
            if (day_ > 28){
                day_ -= 28;
                month_++;
                result = 1;
            }
        }   else{
            if (day_ > 30){
                day_ -= 30;
                month_++;
                result = 1;
            }
        }
        return result;
    }
    int check_month(){
        int result = 0;
        if (month_  > 12){
            year_++;
            month_ -= 12;
            result = 1;
        }
        return result;
    }

    void set_date(int year, int month, int date){
        year_ = year;
        month_ = month;
        day_ = date;
        show_date();
    }

    void add_day(int inc){
        day_ += inc;
        int i, j;
        for (;;){
            i = check_day();
            j = check_month();
            if (i == 0 && j == 0) break;
        }
    }

    void add_month(int inc){
        month_ += inc;
        int i, j;
        for (;;){
            i = check_day();
            j = check_month();
            if (i == 0 && j == 0) break;
        }
    }

    void add_year(int inc){
        year_ += inc;
    }

    void show_date(){
        printf("\n");
        std::cout << year_ << "." << month_ << "." << day_ << std::endl;
    }
};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Date date;
    
    int year;
    int month;
    int day;
    std::cout << "year : ";
    std::cin >> year;
    std::cout << "month : ";
    std::cin >> month;
    std::cout << "day : ";
    std::cin >> day;
    date.set_date(year, month, day);
   
    int loop  = 1;
    while (loop == 1){
        printf("\n");
        int answer;
        std::cout << "1. add day" << std::endl;
        std::cout << "2. add month" << std::endl;
        std::cout << "3. add year" << std::endl;
        std::cout << "4. show date" << std::endl;
        std::cout << "5. end program" << std::endl;
        printf("\n");
        std::cout << "input : ";
        std::cin >> answer;

        int input;
        switch (answer){
            case 1 :
                input = 0;
                std::cout << "date add : ";
                std::cin >> input;
                date.add_day(input);
                date.show_date();
                break;

            case 2 :
                input = 0;
                std::cout << "month add : ";
                std::cin >> input;
                date.add_month(input);
                date.show_date();
                break;

            case 3 :
                input = 0;
                std::cout << "year add : ";
                std::cin >> input;
                date.add_year(input);
                date.show_date();
                break;

            case 4 :
                date.show_date();
                break;

            case 5 :
                loop = 0;
                break;
        
            default:
                std::cout << "You put wrong answer." << std::endl;
                break;
        }
    }    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 아쉬운 점 : 애초에 check_day 에서 자체적으로 for 문을 써려고 했는데 어떠한 이유인지는 모르겠지만
// segment failue 가 떴었음. 그런데 또 이상한게 add_day 에서 for 문은 잘 됐음. 뭔가 잘못 썼었던 건가...? 몰?루?
