#include <iostream>

// 문제 1 (p.108) : 문자열 클래스 만들기

class String{
    char *str;
    int len;

    public :
    String(char c, int n);                  // 문자 c가 n개 있는 문자열로 정의
    String(const char *s);
    String(const String &s);
    ~String();

    void add_string(const String &s);       // str 뒤에 s를 붙인다
    void copy_string(const String &s);      // str에 s를 복사한다
    int str_len();                          // 문자열 길이 리턴
    void show_string();
};

int count_str_len(const char *input);
void copy_str(char *a, const char *b);      // a를 b와 같은 문자열로 만들어줌. a --> b

String::String(char c, int n){
    str = new char[n + 1];
    len = n;
    for (int i = 0; i < n; i++){
        str[i] = c;
    }
    str[n] = 0;
}
String::String(const char *s){
    int length = count_str_len(s);
    len = length;
    str = new char[length + 1];
    for (int i = 0; i < length; i++){
        str[i] = s[i];
    }
    str[length] = 0;
}
String::String(const String &s){
    str = new char[s.len + 1];
    copy_str(str, s.str);
    len = s.len;
}
String::~String(){
    delete [] str;
}

void String::add_string(const String &s){
    int i;
    for (i = 0;;i++){
        str[len + i] = s.str[i];
        if (s.str[i] == 0) break;
    }
    len += i;
}
void String::copy_string(const String &s){
    int i;
    for (i = 0;;i++){
        str[i] = s.str[i];
        if (s.str[i] == 0) break;
    }
    len = i;
}

int String::str_len() {return len;}
void String::show_string(){
    std::cout << str << std::endl;
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    String str_1('a',3);
    String str_2("bb");
    String str_3(str_2);

    str_1.add_string(str_2);
    str_3.copy_string(str_1);

    str_1.show_string();
    str_2.show_string();
    str_3.show_string();

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

int count_str_len(const char *input){
    int count = 0;
    while (*input){
        input++;
        count++;
    }
    return count;
}
void copy_str(char *a, const char *b){
    for (int i = 0;;i++){
        a[i] = b[i];
        if (b[i] == 0) break;
    }
}

// 궁금한 점 : 뭔가 문제 의도대로 만든건지... 잘 모르겠음; 뭔가 느낌상 <string.h>를 이용하지 않고 네가 직접 만들어 봐라 라고 생각해서 만들었는데... 잘 모르겠음;
// 그래도 이번에 확실하게 const를 왜, 어떻게 쓰는건지 이해한 것 같음.
// 별 이유 없이 혹시나 모르게 그 값을 수정할 여지조차 안 남기려고(?) 하는것 같음. 뭐 문법적(?)으로 의미(?)가 있는건 아닌듯함.
// 그니까 꼭 const를 사용해 써야되는 건 아니라는 듯 함.

// 진도 : p.108