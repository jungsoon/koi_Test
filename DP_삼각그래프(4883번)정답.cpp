// code by RiKang, weeklyps.com
#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 100000, INF = INT_MAX;
int n;
int a[N+5][4];
int dp[N+5][4];

int get_dp(int i, int j){
    if(i==1 && j==2) return dp[i][2] = a[i][2];             // n=1일 경우 마지막 노드를 취한다.
    if(i==1 && j==3) return dp[i][3] = a[i][2]+a[i][3];     // n=2일 경우 1번째와 두번째를 취한다.
    if(i<=1 || j<1 || j>3) return INF;                      // i가 1행 이하, j가 1열 미만, j가 3열 이상이면 최대값을 리턴한다.
    if(dp[i][j]!=INF) return dp[i][j];                      // dp배열이 최대값이 아니면 dp를 return해라.

    return dp[i][j] = min({get_dp(i-1,j-1),get_dp(i-1,j),get_dp(i-1,j+1),get_dp(i,j-1)}) + a[i][j];
}

int main(){
    for(int i=1; true; i++){
        scanf("%d",&n);
        if(n==0) break;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=3; k++){
                dp[j][k] = INF;
                scanf("%d",&a[j][k]);
            }
        }
        printf("%d. %d\n",i,get_dp(n,2));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=3;j++){
                printf("%2d ",dp[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
