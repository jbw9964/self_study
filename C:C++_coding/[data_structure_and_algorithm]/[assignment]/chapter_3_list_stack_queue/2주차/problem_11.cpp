#include <iostream>

/* 문제 3.11 (p. 129) : 단순 연결 테일 노드 없이 헤더 노드만으로 구현되어 있고, 헤더 노드로의 포인터만을 가지고 있다고 가정하자.
다음의 메소드를 포함하는 클래스를 작성하시오.
a. 연결리스틍의 크기를 반환하는 메소드
b. 연결리스트를 출력하는 메소드
c. 값 x가 연결리스트에 포함되어 있는지를 조사하는 메소드
d. 연결리스트에 값 x가 없으면 추가하는 메소드
c. 연결리스트에서 값 x를 제거하는 메소드
*/

class List{
    private :

    struct Node{
        int value;
        Node *next;
    };
    
    Node *header;

    public :
    List() : header(new Node) {header->next = NULL;}

    void append(int input);         // List 의 tale 에 input 값을 갖는 Node 생성

    int size() const;               // 문제 a : 값이 들어있는 Node 수를 반환
    void print_list() const;        // 문제 b : 값이 들어있는 Node 들의 값을 출력
    Node* find(int input) const;    // 문제 c : 값이 input 인 Node의 이전 Node 주소를 반환. 없을 시 null
    void if_append(int input);      // 문제 d : 값 input 이 Node에서 없을 시, 값 input 을 갖는 Node를 tale 에 생성
    void delete_value(int input);   // 문제 e : 값이 input 인 Node를 삭제

};

void List::append(int input){
    
    if (!header->next){
        Node *temp = new Node;
        temp->value = input;
        temp->next = NULL;

        header->next = temp;
        return;
    }

    Node *position = header;
    while (position->next){
        position = position->next;
    }
    Node *temp = new Node;
    temp->value = input;
    temp->next = NULL;

    position->next = temp;

}

int List::size() const{                     // 문제 a : 값이 들어있는 Node 수를 반환
    
    Node *position;
    position = header->next;

    int count = 0;
    while (position){
        count++;
        position = position->next;
    }

    return count;
}
void List::print_list() const {             // 문제 b : 값이 들어있는 Node 들의 값을 출력

    Node *position;
    position = header->next;

    std::cout << "values in List : ";
    while (position){
        std::cout << position->value << " ";
        position = position->next;
    }
    std::cout << std::endl;
}
List::Node* List::find(int input) const {   // 문제 c : 값이 input 인 Node의 이전 Node 주소를 반환. 없을 시 null

    Node *temp;
    temp = header->next;

    if (temp->value == input) {return header;}
    while (temp){
        if ((temp->next != NULL) && (temp->next->value == input)) {return temp;}
        temp = temp->next;
    }

    return NULL;
}
void List::if_append(int input){            // 문제 d : 값 input 이 Node에서 없을 시, 값 input 을 갖는 Node를 tale 에 생성

    if (find(input)) {return;}

    Node *temp = new Node;
    temp->value = input;
    temp->next = NULL;

    Node *position;
    position = header->next;

    while (position->next){
        position = position->next;
    }

    position->next = temp;

}
void List::delete_value(int input){         // 문제 e : 값이 input 인 Node를 삭제

    Node *position = find(input);

    if (!position) {return;}

    if (!position->next){
        delete position->next;
    }   else{

        Node *temp = position->next;
        position->next = position->next->next;

        delete temp;
    }

}

int main(){
    std::cout << "\ncode_start\n\n\n" << std::endl;

    List a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    a.append(7);
    a.append(8);
    a.append(9);
    
    auto temp = a.find(9);

    a.size();
    a.if_append(10);

    a.print_list();
    a.delete_value(2);
    a.print_list();
    a.delete_value(1);
    a.print_list();

    std::cout << "\n\n\ncode_end\n" << std::endl;
    return 0;
}