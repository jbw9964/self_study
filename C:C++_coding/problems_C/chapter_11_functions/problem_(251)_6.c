#include <stdio.h>

// 문제 6 (p.251) : 에라토스테네스의 체를 이용해 1 부터 N까지의 소수 구하기
// 에라토스테네스의 체 : 숫자 2부터 시작. 2의 배수들을 모두 지움. 다음으로 지워지지 않은 수(3)을 소수로 저장. 3의 배수들을 모두 지움. 계속 이어나가기.

int net_era(int num, int *point_prime);              // 입력된 수 만큼 체를 만듬. 2부터 시작.
int zero(int num, int *point_arr, int i);                   // 입력된 배열에서 0이 아닌 수가 보이면 그 수를 반환시키고 그 수의 배수들을 모두 0으로 만듬.
int loop(int num, int *point_arr, int i);

int main() {
    printf("\ncode_start\n\n\n");

    int num;
    printf("Number : ");
    scanf("%d", &num);

    int prime[num];                                     // 이렇게 하고싶진 않았는데... 원래 C에서 배열의 크기를 변수로 지정할 순 없음. C99이상에 VLA가 있어 가능하다고 함.
    int *point_prime = prime;                           // 소수들을 저장시킬 배열 포인트
    for (int i = 0; i < num; i++) {prime[i] = 0;}       // 일단 모두 0으로 저장
    
    net_era(num, point_prime);

    printf("\nThe prime numbers under %d\n", num);
    printf("Prime numbers : %d", prime[0]);
    for (int i = 1; ; i++){
        if (prime[i] == 0) {break;}
        printf(", %d", prime[i]);
    }

    printf("\n\n\ncode_end\n");
    return 0;
}

int net_era(int num, int *point_prime){
    int arr[num];                                      
    int *point_arr = arr;
    for (int i = 0; i <= num - 2; i++) {arr[i] = i + 2;}  // num 까지의 수를 저장시켜 둘 arr 만듬
    arr[num - 1] = 0;

    int count = 0;                                       // point_prime 몇번째 원소에 저장하는지 나타내려고.
    for (int i = 0; i < num; i++){
        if (arr[i] != 0){                                // arr[i] 가 0이 아닐 때 (zero, loop 통과한 전이든 후든 상관 없음) point_prime에 저장.
            point_prime[count] = zero(num, point_arr, i); // i : 29
            count = count + 1;
        }
    }
    return 0;
}

int zero(int num, int *point_arr, int i){                        // arr[]가 0이 아닌 값이었으니까 그 값을 반환
    int result = point_arr[i];
    loop(num, point_arr, i);                     // arr[i]의 주소값을 첫번째 걸로 보냄.
    return result;
}

int loop(int num, int *point_arr, int i){              // 여기서 뭔가 prime 지정이 안되는듯
    int number = point_arr[i];                            // 첫번째 값을 0으로 만들고 그 배수들 또한 0으로 만듬
    point_arr[i] = 0;
    for (int j = 0; j < num; j+=number){              // i+=number 니까 i : 0 --> 3 --> 6 이런식으로 되니까 문제 없음
        point_arr[j] = 0;
    }
    return 0;
}

// 아쉬운 점 : 지금 뭔가 되긴 됐는데 결론적으로 포인터에 대한 이해가 있어야 될듯
// 지금 뭔가 계속 segment failue 11 이 됐는데 아마 그 이유는 내가 포인터 주소를 배열의 중간값으로 넣었었는데
// 뭔가 count 되고 i 늘엉나면서 배열 할당된 메모리(?) 넘어가서 그럴듯. 결국 그냥 처음 주소를 넣는걸로 해서 마침.
// 근본적으로 문제해결은 된 게 없음. 포인터에 대한 이해가 필요하다.

// 진도 : p.251