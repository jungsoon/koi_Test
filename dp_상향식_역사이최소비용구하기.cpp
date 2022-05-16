#include <iostream>
using namespace std;

int cost[4][4]={
    {0,10,75,94},
    {-1,0,35,50},
    {-1,-1,0,80},
    {-1,-1,-1,0}
    };
int Min(int a, int b) { return a<b ? a:b; }
int DT[4][4]={0};
int solution(int n)
{
    int minvalue[n+1];
    minvalue[0]=1;
    minvalue[1]=cost[0][1];
    for(int i=2;i<n;i++){
        minvalue[i]=cost[0][i];     // 0행 최소값으로 설정
        for(int j=1;j<i;j++){
            minvalue[i] = Min(minvalue[i], minvalue[j]+cost[j][i]);
        }
    }
    return minvalue[n-1];
}

int main()
{
    cout << solution(4) << "\n";
}
