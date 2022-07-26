#include <iostream>
#include <string>
#include <fstream>

/*
//Users//jeongjunsang//Desktop//coding//practice_C++//
*/

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    std::ifstream in ("//Users//jeongjunsang//Desktop//coding//practice_C++//text.txt");
    
    if (!in.is_open()){
        std::cout << "파일을 찾을 수 없음" << std::endl;
        return 0;
    }

    std::string s;
    while (in){
        getline(in, s);
        std::cout << s << std::endl;
    }

    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


// 진도 : p.364