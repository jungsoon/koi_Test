#include <iostream>
using namespace std;

int cost[4][4]={
    {0,10,75,94},
    {-1,0,35,50},
    {-1,-1,0,80},
    {-1,-1,-1,0}
    };

int DT[4][4]={0};

int solution(int s, int e)
{
    cout << s << " " << e <<endl;
    if(s == e || s == e-1) return cost[s][e];
    int minValue = cost[s][e];

    for(int i=s+1;i<e;i++)
    {
        int temp=solution(s,i)+solution(i,e);
        if(temp < minValue) minValue=temp;
    }
    return minValue;
}

int main()
{
    cout << solution(0,3) << "\n";
}
