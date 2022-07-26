#include <iostream>
#include <string>

// p.273 : 회사내 사무 데이터베이스 만들기 : virtual, heritage 이용
/*
1. 사원 정보 : 이름, 나이, 근무 연수, 직책, 소속 부서
2. 사원 추가하기 : 이름, 나이, 근무연수, 직책 입력하고 소속 부서도 입력받아서 각각의 클래스에 할당
3. 사원 정보 출력하기
4. 할당된 인원수 생각해서 메모리 적절하게 만들기
(부서 : 전산과, 인사과, 경영과 3개)
*/

class Worker{
    public :
    std::string name;
    int age;
    int year_of_work;
    std::string position;
    std::string department;

    
    Worker(std::string name, int age, int year_of_work, std::string position, std::string department)
    : name(name), age(age), year_of_work(year_of_work), position(position), department(department) {}
    Worker(const Worker &input){
        name = input.name;
        age = input.age;
        year_of_work = input.year_of_work;
        position = input.position;
        department = input.department;
    }
    Worker(){}
    ~Worker(){}

    void print_info() const {
        std::cout << name << "(" << age << ", " << year_of_work << " : " << position << " : " << department << ")" << std::endl;
    }

};

class Company{
    public :
    virtual void print_info() = 0;
    virtual void add_worker() = 0;

};

class Compute_Department : public Company{
    private :
    int total_compute_worker = 0;
    int alloc_worker = 4;

    Worker *worker_list[4];

    public : 
    Compute_Department(std::string name, int age, int year_of_work, std::string position){

        if (alloc_worker <= 2 * total_compute_worker) {alloc_check();}

        worker_list[total_compute_worker] = new Worker(name, age, year_of_work, position, "Compute_Department");
        total_compute_worker++;
    }
    Compute_Department(int alloc_worker) : alloc_worker(alloc_worker) {
        *worker_list = *new Worker* [alloc_worker];
    }
    Compute_Department(){}
    ~Compute_Department(){
        for (int i = 0; i < total_compute_worker; i++){
            delete worker_list[i];
        }
    }

    void print_info() override {
        std::cout << "====================-Compute_Department-====================" << std::endl;
        for (int i = 0; i < total_compute_worker; i++){
            std::cout << "["<< i + 1 << "] : ";
            worker_list[i]->print_info();
        }
        std::cout << "====================-print_info : end-====================" << std::endl;
    }
    void add_worker() override{
        if (alloc_worker <= 2 * total_compute_worker) {alloc_check();}

        std::string temp_name;
        std::string temp_position;
        int temp_age;
        int tempa_year;

        std::cout << "name : ";
        std::cin >> temp_name;
        std::cout << "age : ";
        std::cin >> temp_age;
        std::cout << "year of work : ";
        std::cin >> tempa_year;
        std::cout << "position : ";
        std::cin >> temp_position;
        
        worker_list[total_compute_worker] = new Worker(temp_name, temp_age, tempa_year, temp_position, "Compute_Department");
        total_compute_worker++;
    }
    void alloc_check(){
        if (alloc_worker <= 2 * total_compute_worker){
            Worker **temp_list = new Worker *[alloc_worker + 4];
            for (int i = 0; i < total_compute_worker; i++){
                temp_list[i] = new Worker(worker_list[i]->name, worker_list[i]->age, worker_list[i]->year_of_work, worker_list[i]->position, "Compute_Department");
            }
            for (int i = 0; i < total_compute_worker; i++){
                delete worker_list[i];
            }
            alloc_worker += 4;
            *worker_list = *new Worker *[alloc_worker];
            for (int i = 0; i < total_compute_worker; i++){
                worker_list[i] = temp_list[i];
            }
        }
    }

    void add_worker(std::string temp_name, int temp_age, int temp_year, std::string temp_position) {
        if (alloc_worker <= 2 * total_compute_worker) {alloc_check();}
        
        worker_list[total_compute_worker] = new Worker(temp_name, temp_age, temp_year, temp_position, "Compute_Department");
        total_compute_worker++;
    }

};
class Resource_Department : public Company{
    private :
    int total_resource_worker = 0;
    int alloc_worker = 4;

    Worker *worker_list[4];

    public : 
    Resource_Department(std::string name, int age, int year_of_work, std::string position){

        if (alloc_worker <= 2 * total_resource_worker) {alloc_check();}

        worker_list[total_resource_worker] = new Worker(name, age, year_of_work, position, "Resource_Department");
        total_resource_worker++;
    }
    Resource_Department(int alloc_worker) : alloc_worker(alloc_worker) {
        *worker_list = *new Worker* [alloc_worker];
    }
    Resource_Department(){}
    ~Resource_Department(){
        for (int i = 0; i < total_resource_worker; i++){
            delete worker_list[i];
        }
    }
    
    void print_info() override {
        std::cout << "====================-Resource_Department-====================" << std::endl;
        for (int i = 0; i < total_resource_worker; i++){
            std::cout << "["<< i + 1 << "] : ";
            worker_list[i]->print_info();
        }
        std::cout << "====================-print_info : end-====================" << std::endl;
    }
    void add_worker() override{
        if (alloc_worker <= 2 * total_resource_worker) {alloc_check();}

        std::string temp_name;
        std::string temp_position;
        int temp_age;
        int tempa_year;

        std::cout << "name : ";
        std::cin >> temp_name;
        std::cout << "age : ";
        std::cin >> temp_age;
        std::cout << "year of work : ";
        std::cin >> tempa_year;
        std::cout << "position : ";
        std::cin >> temp_position;
        
        worker_list[total_resource_worker] = new Worker(temp_name, temp_age, tempa_year, temp_position, "Resource_Department");
        total_resource_worker++;
    }
    void alloc_check(){
        if (alloc_worker <= 2 * total_resource_worker){
            Worker **temp_list = new Worker *[alloc_worker + 4];
            for (int i = 0; i < total_resource_worker; i++){
                temp_list[i] = new Worker(worker_list[i]->name, worker_list[i]->age, worker_list[i]->year_of_work, worker_list[i]->position, "Resource_Department");
            }
            for (int i = 0; i < total_resource_worker; i++){
                delete worker_list[i];
            }
            alloc_worker += 4;
            *worker_list = *new Worker *[alloc_worker];
            for (int i = 0; i < total_resource_worker; i++){
                worker_list[i] = temp_list[i];
            }
        }
    }

    void add_worker(std::string temp_name, int temp_age, int temp_year, std::string temp_position) {
        if (alloc_worker <= 2 * total_resource_worker) {alloc_check();}
        
        worker_list[total_resource_worker] = new Worker(temp_name, temp_age, temp_year, temp_position, "Resource_Department");
        total_resource_worker++;
    }

};
class Business_Department : public Company{
    private :
    int total_business_worker = 0;
    int alloc_worker;

    Worker *worker_list[4];

    public : 
    Business_Department(std::string name, int age, int year_of_work, std::string position){

        if (alloc_worker <= 2 * total_business_worker) {alloc_check();}

        worker_list[total_business_worker] = new Worker(name, age, year_of_work, position, "Business_Department");
        total_business_worker++;
    }
    Business_Department(int alloc_worker) : alloc_worker(alloc_worker) {
        *worker_list = *new Worker* [alloc_worker];
    }
    Business_Department(){}
    ~Business_Department(){
        for (int i = 0; i < total_business_worker; i++){
            delete worker_list[i];
        }
    }
    
    void print_info() override {
        std::cout << "====================-Business_Department-====================" << std::endl;
        for (int i = 0; i < total_business_worker; i++){
            std::cout << "["<< i + 1 << "] : ";
            worker_list[i]->print_info();
        }
        std::cout << "====================-print_info : end-====================" << std::endl;
    }
    void add_worker() override{
        if (alloc_worker <= 2 * total_business_worker) {alloc_check();}

        std::string temp_name;
        std::string temp_position;
        int temp_age;
        int tempa_year;

        std::cout << "name : ";
        std::cin >> temp_name;
        std::cout << "age : ";
        std::cin >> temp_age;
        std::cout << "year of work : ";
        std::cin >> tempa_year;
        std::cout << "position : ";
        std::cin >> temp_position;
        
        worker_list[total_business_worker] = new Worker(temp_name, temp_age, tempa_year, temp_position, "Business_Department");
        total_business_worker++;
    }
    void alloc_check(){
        if (alloc_worker <= 2 * total_business_worker){
            Worker **temp_list = new Worker *[alloc_worker + 4];
            for (int i = 0; i < total_business_worker; i++){
                temp_list[i] = new Worker(worker_list[i]->name, worker_list[i]->age, worker_list[i]->year_of_work, worker_list[i]->position, "Business_Department");
            }
            for (int i = 0; i < total_business_worker; i++){
                delete worker_list[i];
            }
            alloc_worker += 4;
            *worker_list = *new Worker *[alloc_worker];
            for (int i = 0; i < total_business_worker; i++){
                worker_list[i] = temp_list[i];
            }
        }
    }

    void add_worker(std::string temp_name, int temp_age, int temp_year, std::string temp_position) {
        if (alloc_worker <= 2 * total_business_worker) {alloc_check();}
        
        worker_list[total_business_worker] = new Worker(temp_name, temp_age, temp_year, temp_position, "Business_Department");
        total_business_worker++;
    }
};

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Compute_Department a;
    a.add_worker("joon_1",23,2,"인턴");
    a.add_worker("joon_2",23,2,"인턴");
    a.add_worker("joon_3",23,2,"인턴");
    a.add_worker("joon_4",23,2,"인턴");
    a.add_worker("joon_5",23,2,"인턴");
    a.print_info();

    Resource_Department b;
    b.add_worker("joon_1",23,2,"인턴");
    b.add_worker("joon_2",23,2,"인턴");
    b.add_worker("joon_3",23,2,"인턴");
    b.add_worker("joon_4",23,2,"인턴");
    b.add_worker("joon_5",23,2,"인턴");
    b.print_info();
    
    Business_Department c;
    c.add_worker("joon_1",23,2,"인턴");
    c.add_worker("joon_2",23,2,"인턴");
    c.add_worker("joon_3",23,2,"인턴");
    c.add_worker("joon_4",23,2,"인턴");
    c.add_worker("joon_5",23,2,"인턴");
    c.print_info();

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 결국에 만들긴 했는데.... 참 뭔가 이런 방식 말고 다른걸 원했었는데...
// 결국에 Compnay heritage는 여기서 쓸모가 없다.

// 진도 : p.340