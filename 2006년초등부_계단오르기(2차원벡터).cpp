//2006년 지역본선 초등부 4번문제 - 계단오르기
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> d;

int main() {
    int i,n,d[301][2]={0,},a[30]={0,};
    scanf("%d",&n);

    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    d[1][0]=d[1][1]=a[1];

    for(i=2;i<=n;i++){
        d[i][0]=d[i-1][1]+a[i];
        d[i][1]=max(d[i-2][0],d[i-2][1])+a[i];
        printf("%d %d\n",d[i][0],d[i][1]);
    }
}
