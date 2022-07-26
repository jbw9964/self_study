#include <stdio.h>

int swap(int *point_arr, int num);
int gcd(int first, int second, int *point_arr, int num);

int main(){
    printf("\ncode_start\n\n\n");

    int num;
    printf("How many numbers do you want? : ");
    scanf("%d", &num);

    int arr[num];
    int *point_arr = arr;

    printf("Which numbers do you want? : ");
    for (int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < num; i++){
        if (swap(point_arr, num) == 0) break;
    }

    printf("\nThe GCD between %d", arr[0]);
    for (int i = 1; i < num; i++) printf(", %d", arr[i]);
    printf(" are : ");

    for (int i = 0; ; i++){
        if (gcd(arr[0], arr[1], point_arr, num) == 0) break;
    }

    printf("%d", arr[0]);

    // 배열의 첫번째 두번재 값 빼고서 두 수의 최대공약수 구함.
    // 그 최대공약수 값이랑 0 을 배열에 넣고서 swap 돌림
    // 또 처음처럼 최대공약수 구하는 식으로 돌림.
    // 중간에 만약 원소값이 0이면 break 시키고 첫번째 원소값(결국엔 하나씩 0으로 넣어지니까) printf 하도록

    printf("\n\n\ncode_end\n");
    return 0;
}

int swap(int *point_arr, int num){
    int result = 0;
    for (int i = 0; i < num - 1; i++){
        if (point_arr[i] < point_arr[i+1]){
            int temp = point_arr[i];
            point_arr[i] = point_arr[i+1];
            point_arr[i+1] = temp;
            result = 1;
        }
    }
    return result;
}

int gcd(int first, int second, int *point_arr, int num){
    if (second == 0) return 0;
    for (int i = 0; ; i++){
        if (first % second == 0) break;
        int temp = second;
        first = first % second;
        second = first;
        first = temp;
    }
    point_arr[0] = second;
    point_arr[1] = 0;
    swap(point_arr, num);
    return 1;

}