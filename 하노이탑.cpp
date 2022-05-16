#include <iostream>
#include <cstdio>
using namespace std;

int hanoi(int n, int from, int temp, int to)
{
    if(n==1){
        printf("원판 1을 %c 에서 %c로 옮긴다.\n",from,to);       // 1개의 원판을 from -> to로 옮긴다.
    }
    else{
        hanoi(n-1,from,to,temp);            //목적지 temp
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n",n,from,to);
        hanoi(n-1,temp,from, to);            // n-1개의 temp -> to로 옮긴다.
    }
}

int main()
{
    hanoi(3,'A','B','C');
}
