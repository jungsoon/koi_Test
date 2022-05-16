/*
시간복잡도 n^n
*/
#include <iostream>
using namespace std;
int n,cnt;
int isprime(int num)
{
    if(num<2) return 0;

    for(int i=2;i*i<=num;i++){
        if(num % i == 0) return 0;
    }
    return 1;
}
int solution(int num, int len)
{

    if(len == n){
        if(num == 0) return 0;
        int temp=num;   // 자릿수 자르기 전 임시 변수(temp)
        while(temp)
        {
            if(isprime(temp)) {
                temp /= 10;
            }
            else
                return 0;
        }
        cnt++;
        cout << num << "\n";

    }
    else        // 자릿수(n)의 모든수, n=2라면 20 ~ 99까지 검색
    {
        for(int i=1;i<=10;i++){
            solution(num*10+i,len+1);
        }
    }
}

int main()
{

    cin >> n;

    solution(0,0);
    cout << cnt << "\n";


}
