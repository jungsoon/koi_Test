/*
시간복잡도 루트n
*/
#include <iostream>
using namespace std;
int n,cnt;
int isprime(int num)        // 소수인지 아닌지 판단하는 함수
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
        if(isprime(num)) {
            cnt++;
            cout << num << "\n";
        }
        return 0;
    }
    else        // 자릿수(n)의 모든수, n=2라면 20 ~ 99까지 검색
    {
        if(isprime(num))
        {
            solution(num*10+1,len+1);
            solution(num*10+3,len+1);
            solution(num*10+7,len+1);
            solution(num*10+9,len+1);

        }
    }
}

int main()
{
    cin >> n;

    solution(2,1);
    solution(3,1);
    solution(5,1);
    solution(7,1);

    cout << cnt << "\n";

}
