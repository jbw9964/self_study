#include <iostream>
#include <string>

class Employee{
    protected :
    std::string name;
    int age;

    std::string position;
    int rank;

    public :

    Employee(std::string name, int age, std::string position, int rank)
    : name(name), age(age), position(position), rank(rank) {}
    Employee(const Employee &input){
        name = input.name;
        age = input.age;
        position = input.position;
        rank = input.rank;
    }
    Employee(){}

    void print_info(){
        std::cout << name << " (" << position << ", " << age << ") ==>"
        << calculate_pay() << "만원" << std::endl;
    }
    int calculate_pay() {return 200 + rank * 50;}


};

class Manager : public Employee{
    int year_of_service;

    public :
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
    : Employee(name, age, position, rank), year_of_service(year_of_service) {}
    Manager(const Manager &input){
        year_of_service = input.year_of_service;
        Employee(input.name, input.age, input.position, input.rank);
    }
    Manager() : Employee() {}

    int calculate_pay() {return 200 + rank * 50 + 5 * year_of_service;}
    void print_info(){
        std::cout << name << " (" << position << ", " << age << ", " << year_of_service << "년차) ==>"
        << calculate_pay() << "만원" << std::endl;
    }

};

class EmployeeList{
    int alloc_employee;

    int current_employee;
    int current_manager;

    Employee **employ_list;
    Manager **manager_list;

    public : 
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
        employ_list = new Employee *[alloc_employee];
        manager_list = new Manager *[alloc_employee];

        current_employee = 0;
        current_manager = 0;
    }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++){
            delete employ_list[i];
        }
        for (int i = 0; i < current_manager; i++){
            delete manager_list[i];
        }
        delete [] employ_list;
        delete [] manager_list;
    }

    void add_employee(Employee *input){
        employ_list[current_employee] = input;
        current_employee++;
    }
    void add_manager(Manager *input){
        manager_list[current_manager] = input;
        current_manager++;
    }
    void print_employee_info(){
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++){
            employ_list[i]->print_info();
            total_pay += employ_list[i]->calculate_pay();
        }
        for (int i = 0; i < current_manager; i++){
            manager_list[i]->print_info();
            total_pay += manager_list[i]->calculate_pay();
        }
        std::cout << "총 비용 : " << total_pay <<std::endl;
    }

};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));

    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


// 진도 : p.302