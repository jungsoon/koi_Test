//2006년 지역본선 초등부 4번문제 - 계단오르기
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

//int Max(int a, int b) {return a>b?a:b;}

int main() {
    int i,n,d[301][2]={0,},a[301]={0,};
    scanf("%d",&n);

    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    d[1][0]=d[1][1]=a[1];

    for(i=2;i<=n;i++){
        d[i][0]=d[i-1][1]+a[i];
        d[i][1]=max(d[i-2][0],d[i-2][1])+a[i];
    }
    cout << max(d[n][0],d[n][1]) << endl;

    return 0;
}
