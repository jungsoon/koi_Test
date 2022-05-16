/* 2015_중등부2번(카드게임)   */
#include<iostream>
#include<stdio.h>
using namespace std;

int A[2000];
int B[2000];
int D[2005][2005];
int N;
#define Max(a,b) (((a)>(b))?(a):(b))
int solution();

int main()
{
    int i,j,tot=0;

    int n;

    cin >> N;

    for(i=1;i<=N;i++) cin >> A[i];
    for(i=1;i<=N;i++) cin >> B[i];

    int answer = solution();
    cout << answer << endl;
}
int solution()
{

    for(int i=1;i<=N;i++) D[0][i]=-1;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N+1;j++){
            D[i][j]=Max(D[i-1][j-1],D[i-1][j]);
            if(D[i][j-1]!=-1 && A[i]>B[j-1])            //현재 행의 이전 열이 -1이 아니고, A배열과 B배열을 비교한다.
                D[i][j]=Max(D[i][j],D[i][j-1]+B[j-1]);  // 현재 D배열의 행열의 값과
        }
    }
    for(int i=1;i<=N+1;i++){
        for(int j=1;j<=N+1;j++){
                cout << D[i][j] << " ";
        }
        cout << endl;
    }
    int max=D[N][0];
    for(int i=1;i<=N+1;i++)
    {
        if(max<D[N][i]) max=D[N][i];
    }
    return max;

}
