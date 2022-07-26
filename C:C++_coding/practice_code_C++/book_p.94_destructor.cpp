#include <iostream>
#include <string.h>

class Marine{
    private : 
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char *charter_name;

    public : 
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char *name);
    ~Marine();

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void damage_show();
    void name();

    void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    charter_name = NULL;
}
Marine::Marine(int x, int y){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    charter_name = NULL;
}
Marine::Marine(int x, int y, const char *name){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    charter_name = new char(strlen(name) + 1);
    strcpy(charter_name, name);
    is_dead = false;
}
Marine::~Marine(){
    if (charter_name != NULL){
        delete [] charter_name;
    }
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attack(){
    return damage;
}
void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status(){
    std::cout << "===== Marine =====" << std::endl;
    std::cout << "charter name : " << charter_name << std::endl;
    std::cout << "Location (x,y) : (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp <<std::endl;
}
void Marine::damage_show(){
    std::cout << damage << std::endl;
}
void Marine::name(){
    std::cout << charter_name << std::endl;
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Marine *marine[100];
    marine[0] = new Marine(2,3,"jason");
    marine[1] = new Marine(5,5,"wilson");

    marine[0]->be_attacked(marine[1]->attack());
    marine[0]->show_status();
    
    delete marine[0];
    delete marine[1];

    marine[0]->name();
    marine[0]->damage_show();
    marine[0]->show_status();

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 궁금한 점 : 지금 delete marine[?] 를 해보면서 디버깅으로 확인하니까 coord_x, coord_y, hp만 초기화가 됨. damage 랑 name은 안 바뀜
// 그러면 이게 그냥 delete 했을때 어떤건 없어지고 어떤건 안 없어지는건데 그 기준은 뭐임?
// 그리고 delete 해도 marine[0]->show_status() 하니까 초기화(?)가 됐어도 잘 출력이 됨. 그럼 애초에 delete 하는 이유가 뭐임??
// delte 하면 location 이랑 hp에 할당된 메모리만 없어지는 건가? show_status()는 쓰레기(?)값을 출력하는 거고?

// 진도 : p.94