#include <iostream>
#include <cmath>

// 문제 2 (p.83) : 기하학 소프트웨어 만들기. 점들을 입력 받고 그 점들로 여러가지 하는 프로그램
/*
1. 점 설정하기
2. 설정한 점들 보기
3. 모든 점들간의 거리 계산하기
4. 모든 점들을 서로 이었을 때, 생기는 직선간의 모든 교점의 개수 구하기
5. 모든 점들을 이은 직선의 모든 방정식 보기

코드 짠 개요
class Point로 점들을의 형식을 지정. class Line으로 점들을 이었을 때 직선의 방정식 형식을 지정.
class Geometry : 총 100개의 점들과 100개의 직선들을 저장할 수 있도록 하였음. 또한 나중에 교점의 개수를 나타내기 위해 class Point 형식으로
100개의 교점을 저장하도록 함.

또한 편의를 위해 Geometry에서 설정된 점들의 개수, 점들간 계산한 직선의 방정식 개수, 교점의 개수를 추가로 int 형식으로 선언함.

main 함수 : 206 줄에 있음 (main 함수는 뭐 별거 없음)
*/

class Point{
    private : 
    double x;
    double y;

    public :
    Point(double pos_x, double pos_y) {x = pos_x; y = pos_y;}
    double position_x() {return x;}
    double position_y() {return y;}
    void print_point() {std::cout << "( x : " << x << " / y : " << y << " )" << std::endl;}
};

class Line{
    private :       // f(x, y) = ax + by + c = 0
    double a;
    double b;
    double c;

    public :
    Line(double input_a, double input_b, double input_c) {a = input_a; b = input_b; c = input_c;}
    double print_a() {return a;}
    double print_b() {return b;}
    double print_c() {return c;}
    void print_line(){std::cout <<a << "x + " << b << "y + " << c << " = 0" << std::endl;}
};

class Geometry{
    private :
    Point *point_arry[100];
    int point_numbers = 0;

    Line *line_arry[100];
    int line_numbers = 0;
    
    Point *cross_point_arry[100];
    int cross_point_numbers = 0;
    

    public : 
    // 점 수준의 함수들
    void add_point(double input_x, double input_y);
    void show_all_points();
    void print_distance();

    // 직선 수준의 함수들
    void show_all_lines();
    void calculate_all_lines();         // 지금까지 설정된 점들로 모든 직선의 방정식 계산하는 함수. 계산하면서 겹치는 직선의 방정식은 하나만 넣도록 함.
    void print_num_meet();              // 모든 직선간 교점의 좌표를 계산하고 겹치는 좌표는 하나만 넣는 함수. 그리고 교점의 개수도 나타내느 함수.
};

void Geometry::add_point(double input_x, double input_y){       // 점 설정하는 함수
    point_arry[point_numbers] = new Point(input_x, input_y);
    point_arry[point_numbers]->print_point();
    point_numbers++;
}
void Geometry::show_all_points(){                               // 설정된 점들을 보여주는 함수
    if (point_numbers == 0) {std::cout << "There no points in arry.\n" << std::endl; return;}
    for (int i = 0; i < point_numbers; i++){
        std::cout << i + 1 << ". ";
        point_arry[i]->print_point();
    }
}
void Geometry::print_distance(){                                // 설정된 모든 점들간의 거리를 계산하는 함수
    std::cout << "\nshowing all sets of points" <<std::endl;
    show_all_points();
    std::cout << "\ndistance between ( 'n'th pair = 'n'th pair )" << std::endl;
    double dis_x, dis_y, result;
    for (int i = 0; i < point_numbers; i++){
        std::cout << std::endl;
        for (int j = i + 1; j < point_numbers; j++){
            dis_x = point_arry[i]->position_x() - point_arry[j]->position_x();
            dis_y = point_arry[i]->position_y() - point_arry[j]->position_y();
            result = sqrt(pow(dis_x,2) + pow(dis_y, 2));
            std::cout << "( " << i + 1 << " = " << j + 1 << " ) : " << result << std::endl;
        }
    }
}

void Geometry::show_all_lines(){                                // 점들간 계산된 직선의 모든 방정식을 보여주는 함수
    calculate_all_lines();              // 혹시 직선의 방정식 계산이 안되있을 까봐 넣음.
    if (line_numbers == 0) {std::cout << "There are few points to calculate." << std::endl; return;}
    for (int i = 0; i < line_numbers; i++){
        std::cout << i + 1 << ". ";
        line_arry[i]->print_line();
    }
}
void Geometry::calculate_all_lines(){                           // 설정된 점들을 토대로 직선의 모든 방정식을 계산하는 함수
    if (point_numbers < 3) {std::cout << "The numbers of points are not enough" << std::endl; return;}

    /* 직선의 방정식 구하기 : (x1,y1), (x2,y2) : ax + by + c =0
    a = y2 - y1
    b = x1 - x2
    c = -(ax1 + by1) OR -(ax2 + by2)  (그냥 방정식에 대입)
    */

    Line *test_line_arry[100];                          // 일단 중복되는 것도 저장해 둘 test_line_arry 만들어 두기(100개까지 저장 가능)
    int count = 0;
    double input_a, input_b, input_c;                   // 방정식의 계수 ax + by + c = 0

    for (int i = 0; i < point_numbers; i++){
        if (count > 100) {std::cout << "There are too many lines to calculate." << std::endl; return;}
        for (int j = i + 1; j < point_numbers; j++){
            input_a = point_arry[j]->position_y() - point_arry[i]->position_y();
            input_b = point_arry[i]->position_x() - point_arry[j]->position_x();
            input_c = (-1) * (input_a * point_arry[i]->position_x() + input_b * point_arry[i]->position_y());
            test_line_arry[count] = new Line(input_a, input_b, input_c);        // 계산된 a, b, c로 Line 형식 test_line_arry[count]에 저장.
            count++;
        }
    }
    // 위의 코드를 지나면 중복되는 방정식이 있을 수도 있음. ex : x + y = 0, 2x + 2y = 0
    // 아래 코드는 중복되는 방정식이 있을 때 line_arry에 하나만 저장되도록 하는 코드임.

    line_numbers = 0;
    double a1, b1, c1;
    line_arry[0] = test_line_arry[0];
    for (int i = 0; i < count; i++){
        int test_result = 0;
        a1 = test_line_arry[i]->print_a();
        b1 = test_line_arry[i]->print_b();
        c1 = test_line_arry[i]->print_c();

        for (int j = i + 1; j < count; j++){
            double a2, b2, c2;
            a2 = test_line_arry[j]->print_a();
            b2 = test_line_arry[j]->print_b();
            c2 = test_line_arry[j]->print_c();

            if (a1 * b2 == a2 * b1){            // 두 방정식 a1x + b1y + c1 = 0, a2x + b2y + c2 = 0 이 있을 때 "a1*b2 - a2*b1 = 0 이면 두 직선은 평행하거나 동일하다"는 점을 이용함. 
                double ratio;
                if (a1 == 0) {ratio = b1 / b2;}
                else if (b1 == 0) {ratio = a1 / a2;}
                else {ratio = a1 / a2;}

                if ((c1 == 0 && c2 != 0) || (c1 != 0 && c2 == 0)) {continue;}       // c1, c2 둘중 하나만 0일 때, 즉 두 직선이 다를 때
                else if (c1 == 0 && c2 == 0) {test_result = 1;}                     // (x + y = 0, 2x + 2y = 0) 이런식일 경우
                else if (c1 / c2 == ratio) {test_result = 1;}                       // (x + y + 1 = 0, 2x + 2y + 2 = 0) 이런식일 경우
                else {continue;}                                                    // 나머지는 아마... 다 평행하기만 할 듯? (x + y + 1 = 0, 2x+ 2y + 1 = 0)
            }
        }
        if (test_result == 0) {line_arry[line_numbers] = test_line_arry[i]; line_numbers++;}        // 겹치는 직선이 아니라면 line_arry에 넣기, 그 개수도 line_numbers에 저장하기
    }
    std::cout << std::endl << "There are " << line_numbers << " lines for result." << std::endl;
}
void Geometry::print_num_meet(){                                // 계산된 직선의 모든 방정식을 토대로 직선간 모든 교점의 좌표를 계산하여 *cross_point_arry에 넣는 함수
    calculate_all_lines();                      // 혹시몰라 계산 돌려놓기
    if (point_numbers < 3) {return;}
    if (line_numbers == 0) {return;}

    /* 직선의 방정식 간 교점 계산하기 : (a1x + b1y + c1 = 0), (a2x + b2y + c2 = 0)
    x = (b1*c2 - b2c1) / (a1*b2 - a2*b1)
    y = (-a1 / b1) * ((b1*c2 - b2*c1) / (a1*b2 - a2*b1)) - (c1 / b1)    (이때 b1 = 0이면 값을 구할수가 없음 그래서 아래에 0일땐 다르게 계산하도록 함)
    이 사이트의 계산식을 이용함 : https://gaussian37.github.io/math-algorithm-intersection_point/
    */

    Point *test_cross_point_arry[100];          // 일단 중복되는 것도 저장해 둘 test_cross_point_arry 만들어 두기
    int count = 0;
    double cross_point_x, cross_point_y;
    
    // 첫번째 방정식 : a1x + b1y + c1 = 0, 두번째 방정식 : a2x+ b2y + c2 = 0
    for (int i = 0; i < line_numbers; i++){
        if (count > 100) {std::cout << "There are too many points to calculate." << std::endl; return;}
        double a1, b1, c1;
        a1 = line_arry[i]->print_a();
        b1 = line_arry[i]->print_b();
        c1 = line_arry[i]->print_c();

        for (int j = i + 1; j < line_numbers; j++){
            double a2, b2, c2;
            a2 = line_arry[j]->print_a();
            b2 = line_arry[j]->print_b();
            c2 = line_arry[j]->print_c();
            
            if (a1 * b2 == a2 * b1) {continue;}         // 두 직선이 평행할 경우 교점이 없으므로 continue
            
            cross_point_x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
            if (b1 == 0) {cross_point_y = (-1) * (a2 * cross_point_x + c2) / b2;}       // b1 = 0일때, b2y = -(a2x + c2)    (x는 상관없이 구할 수 있으니까 걍 식에 대입해서 구하기)
            else {cross_point_y = (-1) * (a1 / b1) * ((b1*c2 - b2*c1) / (a1*b2 - a2*b1)) - (c1 / b1);}
            
            test_cross_point_arry[count] = new Point(cross_point_x, cross_point_y);
            count++;
        }
    }

    // calculate_all_lines 와 동일하게 위에는 중복되는 점들도 들어갔을 거임.
    // 아래 코드는 중복된 것들 중 하나만 넣도록 하는 코드

    cross_point_numbers = 0;
    double position_x1, position_y1;
    for (int i = 0; i < count; i++){
        position_x1 = test_cross_point_arry[i]->position_x();
        position_y1 = test_cross_point_arry[i]->position_y();
        int test_result = 0;
        for (int j = i + 1; j < count; j++){
            double position_x2, position_y2;
            position_x2 = test_cross_point_arry[j]->position_x();
            position_y2 = test_cross_point_arry[j]->position_y();
            if (position_x1 == position_x2 && position_y1 == position_y2) {test_result = 1;}
        }
        if (test_result == 0) {cross_point_arry[cross_point_numbers] = test_cross_point_arry[i]; cross_point_numbers++;}        // 중복되지 않는 경우 교점의 좌표 cross_point_arry에 저장, 교점의 개수도 cross_point_numbers 저장.
    }
    std::cout << "And there are " << cross_point_numbers << " crossing point for result." << std::endl;
    for (int i = 0; i < cross_point_numbers; i++){      // 출력
        std::cout << i + 1 << " : ( " << cross_point_arry[i]->position_x() << ", " << cross_point_arry[i]->position_y() << " )" << std::endl;
    }
}

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Geometry geometry;
    
    int loop = 1;
    while (loop == 1){
        int answer;
        std::cout << "\n1. add point\n2. show all points\n3. calculate distances between all points\n4. calculate the numbers that all lines meet\n5. show all lines function\n6. Exit" << std::endl;
        std::cout << "answer : ";
        std::cin >> answer;

        switch (answer){
            case 1 :            // add point
            {
                double x, y;
                std::cout << "x : ";
                std::cin >> x;
                std::cout << "y : ";
                std::cin >> y;
                std::cout << std::endl;
                geometry.add_point(x, y);
                break;
            }

            case 2 :            // show points
            {std::cout << std::endl; geometry.show_all_points(); break;}

            case 3 :            // calculate distance between all points
            {
                geometry.print_distance();
                break;
            }

            case 4 :            // calculate numbers that all lines meet
            {
                geometry.print_num_meet();
                break;
            }

            case 5 :            // show lines
            {std::cout << std::endl; geometry.show_all_lines(); break;}
            case 6 : {loop = 0; break;}
            default : {std::cout << "You put wrong answer." << std::endl; break;}
        }
    }

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}

// 아쉬운 점 : 뭔가 돌아돌아돌아서 만든 느낌. 그나마 코딩적으로는 이해 되는것 같지만 이번 문제는 수학적으로 너무 어려웠음.
// 그래서 그냥 쌩으로 교점 계산하는 방정식(?)을 사용했는데 그냥 머리에서 나온거라 어딘가 헛점이 있을수도 있음. 또 게산하는데 뭔가 오래걸릴 것 같기도 하고....
// + 교재에선 add_point 함수의 받는 변수를 const Point &point 라고 썼는데 이건 뭘 의도한거고 어떻게 써야할지 모르겠어서 그냥
// double input_x, input_y 로 대체해서 코드를 짬.
// + 그리고 교재에서 Geometry의 생성자로 뭘 한 것 같은데... 이 부분은 진자 뭔지 모르겠음.

// 진도 : p.83