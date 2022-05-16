/*
삼각화단 만들기(S)
삼각형은 두변의 길이의 합이 나머지 한변의 길이보다 작다. a+b>c
*/
#include <iostream>
using namespace std;
void solution(int n, int a, int b, int c);
int chk[21][21][21];

int cnt;
int n;
int main()
{

    cin >> n;

    solution(n,1,1,1);
    cout << cnt << endl;
    return 0;
}
void solution(int n, int a, int b, int c)
{
    if(a+b+c == n)
    {
        if(a<=b && b<=c && a+b>c && chk[a][b][c]==0)
        {
            printf("%d %d %d\n",a,b,c);
            cnt++;
            chk[a][b][c]=1;
        }
        return;
    }

    solution(n, a+1, b, c);
    solution(n, a, b+1, c);
    solution(n, a, b, c+1);
}

//반복문으로 푼 문제
/*
int solution()
{
    int total=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                if(i+j+k == n && i+j > k )
                {
                    cout << i << " " << j << " " << k << endl;
                    total++;
                }
            }
        }
    }
    return total;
}
*/
