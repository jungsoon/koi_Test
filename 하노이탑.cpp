#include <iostream>
#include <cstdio>
using namespace std;

int hanoi(int n, int from, int temp, int to)
{
    if(n==1){
        printf("���� 1�� %c ���� %c�� �ű��.\n",from,to);       // 1���� ������ from -> to�� �ű��.
    }
    else{
        hanoi(n-1,from,to,temp);            //������ temp
        printf("���� %d�� %c���� %c���� �ű��.\n",n,from,to);
        hanoi(n-1,temp,from, to);            // n-1���� temp -> to�� �ű��.
    }
}

int main()
{
    hanoi(3,'A','B','C');
}
