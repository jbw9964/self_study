#include <iostream>
#include <string>

class Base{
    std::string s;

    public :
    Base() : s("base") {std::cout << "base class constructor" << std::endl; what();}
    Base(std::string input) : s(input) {std::cout << "\nbase class constructor" << std::endl; what();}
    Base(const Base &input){
        s = input.s;
        std::cout << "Base : copy constructor" << std::endl;
    }

    virtual void what() {std::cout << s << " : at Base class" << std::endl;}
};

class Derived : public Base{
    std::string s;

    public :
    Derived() : s("derived"), Base() {std::cout << "derived class constructor" << std::endl;}
    Derived(std::string input) : s(input), Base(input) {std::cout << "\nderived class constructor" << std::endl; what();}
    Derived(Base &input) : Base(input), s("derived") {std::cout << "Derived Base constructor" << std::endl;}

    virtual void what() {std::cout << s << " : at Derived class" << std::endl;}

};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    Base p("it's p");
    Derived c("it's c");

    std::cout << "pointer type" << std::endl;

    Base *base = &c;

    std::cout << std::endl;

    base->what();

    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


// 진도 : p.322