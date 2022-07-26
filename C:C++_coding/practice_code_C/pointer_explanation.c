#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    int arr[3] = {1,2,3};
    int multi_arr[2][3] = {{1,2,3},{4,5,6}};
    int a = 10;

    int *point;
    int *point_arr;
    int (*point_multi_arr)[3];

    point = &a;
    point_arr = &arr[1];
    point_multi_arr = multi_arr;

    *point = 2;
    point_multi_arr[0][0] = 2;

    printf("a 주소 : %p\n", &a);
    printf("a 값 : %d\n", a);
    printf("그냥 포인터 주소 : %p\n\n", &point);
    
    printf("arr 주소 : %p\n", arr);
    printf("arr[0] 의 값 : %d\n", arr[0]);
    printf("1차원 배열 포인터 주소 : %p\n", point_arr);
    printf("저장된 값 : %d\n\n", *point_arr);

    printf("multi_arr 주소 : %p\n", multi_arr);
    printf("다차원 배열 포인터 주소 : %p\n", &point_multi_arr[1][0]);
    printf("저장된 값 : %d", *point_multi_arr[0]);
    
    printf("\n\n\ncode_end\n");
    return 0;
}

// 포인터 : 어느 데이터의 주소값을 보관한다.
// & 연산자 : 피연산자의 주소값을 불러옴.
// * 연산자 : 피연산자 주소값에 저장된 데이터를 불러옴.

// 배열 포인터와 포이터 배열
// 배열 포인트 : 다차원 배열의 주소

/*
================================================================================================================================================

0. 포인터가 아닌 그냥 변수들
그냥 변수 : &a
(1차원 포함) 배열 : &안적어도 됨. 뒤에 [?] 안적으면 배열의 시작지점 주소 나타냄
단, 다차원 배열의 경우 [?][?] 둘다 적어야지 정확히 되는데
앞에것 [?]만 적으면 배열중 그 [?]가 시작하는 지점의 주소를 나타냄.

1. 그냥 포인터 : int *point
--> 선언 부분
point = &a : 포인터에 a주소를 넣음, 즉 point = a. 
꼭 주소를 표시하는 & 연산자가 변수앞에 있어야 됨.
*point = a  ,  point = a  :  이건 안됨

--> 출력 부분
point에 저장된 변수 a의 주소를 보려면 : %p point 해야됨
단 주의할 점이 &point 를 해버리면 '포인터에 저장된 주소값'이 아닌 '포인터 자체의 주소값'이 나옴.
즉 원하는 a 의 주소값이 아니라 point 자체가 저장된 주소를 불러옴.


2. (1차원)배열의 포인터 : int *point[?]
--> 선언 부분
point_array = array     OR      point_array = array[?]
이런 식으로 할 수 있음. 위에 [?]에 0 넣으면 array 시작 주소가 들어가는 거고
다른 값이면 그 [?]번째 주소가 들어가는 것.
&array 라고 적어도 상관 없음. 뭔가 컴파일 에러아닌 에러 뜨긴 하는데 되긴 함.

--> 출력 부분 : 값, 주소 출력
값 출력은 %d *point_array 해서 출력 가능 (point_array[0] 값 출력)
단 point_array의 정확한 부분을 찝어서 그냥 적는것도 출력 됨. 즉, 아래것도 출력됨
%d point_array[?]

주소 출력은 그냥 point_array 해서 출력 가능 (point_array[0]의 주소 출력)
하지만 그 다음거나 다른 것 출력하고 싶으면 point_array[?]식으로만 치면 안됨.
point_array + ?     OR      &point_array[?]
이런 식으로 쳐야 출력됨


3. (다차원)배열의 포인터 : int (*point)[?]
--> 선언 부분
거의 비슷하면서 조금만 다름 그냥 point_multi_array = multi_array 하면
multi_array[0][0]의 주소를 받음
하지만 multi[1][?]의 주소를 얻고 싶으면
point_multi_array = &multi_array[1][?] 해야됨
그냥 point_multi_array = &multi_array[1] 만 하면 에러가 안뜨는데 (multi_array[1][0] 할당)
point_multi_array = &multi_array[1][?] 하면 에러가 뜸. 근데 또 되긴 함.

또 그냥 point_multi_array = &multi_array 해도 되긴 함. 에러 뭔가 뜨지만

--> 출력 부분 : 값, 주소 출력
주소 출력은 %p point_multi_array 해도 됨 (multi_array[0] 출력)
앞의 1차원 배열과는 다르게 %p point_multi_array[?] 해도 주소가 출력이 됨.
결국 point_multi_array + ?        OR      point_multi_array[?]
OR point_multi_array 세가지 모두 출력이 됨
하지만 여기서 + ? 하거나 [?] 하는건 ? 다음번째 주소가 아님. ? 나 [?]가 나타내는건
배열의 행을 나타내는 거임. 따라서 + ?, [?] 하는건 (multi_array[0][0]의 주소값) + (열의 개수)*? 가 되는거임.

+ 정확한 주소값 (point_multi_array[?][?]) 를 출력하고 싶을 땐 & 연산자가 붙어야됨.
즉, %p &point_multi_array[?][?] 라고 쳐야됨. 앞에거랑 다르게 & 붙여야 된다는 소리.

값 출력은 또 다름 (왤케 다 다른거야 ㅅㅂ)
정확한 값을 출력할 때는 *를 안 붙여도 됨.

================================================================================================================================================

정리해보면
배열 포인터의 출력   -  값 출력 : 어느 한 값을 콕 찝어 출력할 때 (point_array[?], point_multi_array[?][?]) 에서는 * 연산자를 안 붙여도 됨. 
                            하지만 약간 뭉글하게(?) 표현할 때 (point_array, point_multi_array[?]) 이 때는 *연산자를 붙여야 출력이 됨.
                    주소 출력 : 애는 값 출력할 때랑 반대임. 한 값을 찝어 출력할 때 (point_array[?], point_multi_array[?][?]) 에는 & 연산자가 꼭 필요하고
                            뭉글하게 표현할 때에는 (point_array, point_multi_array[?]) &연산자가 없어도 출력 됨.

배열 포인터의 선언 - 이것도 위에랑 뭔가 동일한 맥락을 따라감. 
                주소를 이용해 선언할 때, 한 주소를 콕 찝어 선언할 때 (array[?], multi_array[?][?]) & 연산자를 꼭 넣어야 되고 아닐 때는 (array, multi_array[?]) & 안써도 됨.
                값을 배열 포인터에 넣을 때에도 위랑 같은 맥락을 따름. 약간 문법이 다른 부분이 있긴 함.
                한 값을 콕 찝어 넣을 때 (point_array[?], point_multi_array[?][?]) * 연산자가 없어도 들어감. 뭉글하게 표현할 때 (point_array, point_multi_array[?]) 에는 * 연산자가 꼭 있어야 됨.
                그리고 이렇게 표현해도 값이 들어가긴 함. { *(point_array + ?), *(point_multi_array[?] + ?) } 뭔가 왜 이런지 알 것 같기도 하고 아니기도 하고...

그냥 포인터 - 이건 교재 처음에 알려줬던 내용이라 크게 바뀌거나 모르는 부분은 없을 듯.
            그냥 주소 넣을 때는 &, 값 다룰 때는 *.

*/