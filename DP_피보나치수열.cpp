//피보나치 수열
#include <iostream>
using namespace std;

/* 시간복잡도는 2의 n승입니다. */
/*
int dp(int x) {
    if(x == 1) return 1;
    if(x == 2) return 1;
    return dp(x-1) + dp(x-2);
}
*/

/* 시간복잡도는 O(N)*/
int D[100];
int dp(int x) {
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(D[x] != 0) return D[x];
    return D[x] = dp(x-1) + dp(x-2);
}

int main(){
    printf("%d",dp(30));
}
