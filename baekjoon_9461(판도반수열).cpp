#include <stdio.h>

int t;
long long dp[105];

int main() {
    dp[1]=dp[2]=dp[3]=1;
    dp[4]=dp[5]=2;
    for(int i=6; i<=100; i++)
        dp[i] = dp[i-1]+dp[i-5];
    scanf("%d",&t);
    while(t--){
        int in;
        scanf("%d",&in);
        printf("%lld\n",dp[in]);
    }
    return 0;
}
