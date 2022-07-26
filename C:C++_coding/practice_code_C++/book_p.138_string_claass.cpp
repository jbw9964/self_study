#include <iostream>

// p.138 : 내가 만들어보는 문자열 클래스
/*
1. 문자(char)로 부터 문자열 생성, C 문자열(char *)로 부터의 생성
2. 문자열 길이를 구하는 함수
3. 문자열 뒤에 다른 문자열 붙이기
4. 문자열 내에 포함되어 있는 문자열 구하기
5. 문자열이 같은지 비교
6. 문자열 크기 비교 (사전 순)
*/

class MyString{
    private :
    char *string;
    int string_length = 0;    // string[string_length] = null임 : "aa", 2 : string[2] = 0

    public : 
    MyString() {string = 0; string_length = 0;}
    MyString(char c){
        string = new char[2];
        string_length = 1;
        string[1] = c;
        string[2] = 0;
    }
    MyString(char c, int n){
        string = new char[n + 1];
        for (int i = 0; i < n; i++) {string[i] = c; string_length++;}
        string[n] = 0;
    }
    MyString(const char *input){
        int count = 0;
        for (int i = 0;;i++){
            if (input[i] == 0) {count = i; break;}
        }
        string = new char[count + 1];
        for (int i = 0; i < count + 1; i++){
            string[i] = input[i];
            string_length++;
        }
        string_length--;
    }
    MyString(const MyString &input);
    ~MyString(){
        delete [] string;
        string_length = 0;
    }

    void show_string() const;
    void show_string_length() const;                  // 저장된 string의 길이를 보여줌
    void show_string_length(char *input) const;       // input 된 문자열의 길이를 보여줌 --> 생각해보니 이건 굳이 class 멤버 함수로 만들 필요가 없네;
                                                      // 그냥 input의 문자열 길이를 나타내 주는 거니까...class 내부 변수들은 아무 상관 없잖아...
    void append_string(const char *input);
    void find_string(const char *search) const;
    void compare_string(const char *input) const;
    void compare_string_size(const char *input) const;
};

MyString::MyString(const MyString &input){
    string_length = input.string_length;

    string = new char[string_length + 1];
    for (int i = 0; i < string_length; i++){
        string[i] = input.string[i];
    }
    string[string_length] = 0;
}

void MyString::show_string() const {
    std::cout << "string in class : " << string << std::endl;
}
void MyString::show_string_length() const {
    std::cout << "The length of '" << string << "' is : " << string_length << std::endl;
}
void MyString::show_string_length(char *input) const {
    int count;
    for (int i = 0;;i++){
        if (input[i] == 0) {count = i; break;}
    }
    std::cout << "The length of '" << input << "' is : " << count << std::endl;
}

void MyString::append_string(const char *input){      // string : "aa", input : "bb" --> string_length : 2, cout : 2
    int count;
    for (int i = 0;;i++){
        if (input[i] == 0) {count = i; break;}
    }
    char *temp = new char[string_length + count + 1];

    int j = 0;
    for (int i = 0; i < string_length + count; i++){
        if (i < string_length - 1) {
            temp[i] = string[i];
        }
        if (i >= string_length - 1){
            temp[i] = input[j];
            j++;
        }
    }

    string = new char[string_length + count + 1];
    string_length += count;
    string = temp;
}
void MyString::find_string(const char *input) const {
    int j;
    for (int i = 0;;i++){
        if (string[i] == 0) {std::cout << "There's NO MATCH with string '" << input << "'." << std::endl; break;}
        bool result = false;
        for (j = 0;;j++){
            if (input[j] == 0) {break;}
            if (string[i + j] == input[j]) {result = true;}
            else {result = false;}
            if (result == false) {break;}
        }
        if (result == true){
            int count = i;

            std::cout << "THERE'S MATCH with string '" << input << "' : string[" << count << "], ";
            for (int k = count; k < count + j; k++){
                std::cout << string[k];
            }
            std::cout << std::endl << "(string : " << string << " )" << std::endl;
            break;
            }
    }
}
void MyString::compare_string(const char *input) const {
    int input_size;
    for (int i = 0;;i++) {if (input[i] == 0) {input_size = i; break;}}

    if (input_size != string_length) {std::cout << "string '" << string << "' and '" << input << "' are NOT same." << std::endl; return;}

    bool result = true;
    for (int i = 0; i < string_length; i++) {if (string[i] != input[i]) {result = false; break;}}

    if (result == false) {std::cout << "string '" << string << "' and '" << input << "' are NOT same." << std::endl;}
    else {std::cout << "string '" << string << "' and '" << input << "' are SAME." << std::endl;}

}
void MyString::compare_string_size(const char *input) const {          // string이 먼저다 : false, input이 먼저다 : true
    bool result = true;
    for (int i = 0;;i++){
        if (result == false || string[i] == 0 || input[i] == 0) {break;}
        if (string[i] < input[i]) {result = false; break;}
        else if (string [i] > input[i]) {break;}
        else {continue;}
    }
    if (result == false) {std::cout << "string '" << string << "' is HIGHER than '" << input << "'." << std::endl;}
    else {std::cout << "string '" << string << "' is LOWER than '" << input << "'." << std::endl;}
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    MyString str_1("aaccaa");
    MyString str_2(str_1);
    MyString str_3("aaa");

    str_1.find_string("cc");
    str_1.compare_string("aaccaa");
    str_1.compare_string("aaccab");

    str_1.compare_string_size("aab");
    str_1.compare_string_size("aad");
    str_1.compare_string_size("aa");

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 신기한 점(?) : find_string 함수에서 결과 출력할 때 쉽게 sizeof(input) 으로 string의 일부분만 출력하려고 했음. 그런데 신기하게도
// find_string 함수 내에서는 sizeof(input) = 8 이고 main 함수에서 sizeof("cc") = 3으로 나왔음. C언어에서 #pragma 뭐로 
// 이걸 조절 했었는데 이 부분은 어떻게 쓰는지 정확하게 모르고 전처리기에 쓰는거라 그냥 안함.
// 아마 저걸로 최소 조정 비트 단위수(?)를 바꾸는 거였음.

// 아쉬운 점 : string.h를 쓰면 참 편할텐데.. 라고 생각한 부분이 많았음. 그래서 중간중간 조금 돌아서 간 부분이 있을 듯.
// 그리고 계속 숫자 세는게 헷갈려서 결과 보면서 조금씩 맞춘 부분이 있음 (string_length) : 마지막에 1이 더 커서 string_length-- 하는 부분을 만듬..

// 또 comapre_string_size 함수에서 서로 같을 때 ("aaa", "aaab") 해당하는 경우를 코드로 안 짬. 귀찮아서...
// 또 일일히 str_1.compare_string_size("~~~~") 이렇게 문자열을 그대로 치는게 좀 깔끔해 보이지가 않음. 이거에 해당하는 함수도 만들라면 만들 수 있는데... 또 귀찮아서 ㅎㅎ;;

// 새로 배운(?) 것 : 함수가 내부 값을 특별히 바꾸는게 아닐 경우 const 함수 사용하기.

// 진도 : p.138