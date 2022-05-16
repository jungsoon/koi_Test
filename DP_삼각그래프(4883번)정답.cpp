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
    if(i==1 && j==2) return dp[i][2] = a[i][2];             // n=1�� ��� ������ ��带 ���Ѵ�.
    if(i==1 && j==3) return dp[i][3] = a[i][2]+a[i][3];     // n=2�� ��� 1��°�� �ι�°�� ���Ѵ�.
    if(i<=1 || j<1 || j>3) return INF;                      // i�� 1�� ����, j�� 1�� �̸�, j�� 3�� �̻��̸� �ִ밪�� �����Ѵ�.
    if(dp[i][j]!=INF) return dp[i][j];                      // dp�迭�� �ִ밪�� �ƴϸ� dp�� return�ض�.

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
