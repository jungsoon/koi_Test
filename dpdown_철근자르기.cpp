#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int price[]={0,1,5,8,9,10,17,17,20};
int n;
vector<int> DT;

int solution(int m)
{
    if(m<=0) return DT[m]=0;
    if(DT[m]) return DT[m];

    for(int i=1;i<=m;i++){
        DT[m]=max(DT[m],solution(m-i)+price[i]);
        //cout << m << " " <<  i << " " << result << endl;
    }

    return 0;
}

void solution2()
{

    DT[0]=0;
    for(int i=1;i<=n;i++){
        DT[i]= INT_MIN;
        for(int j=1;j<=i;j++){
            DT[i]=max(DT[i],DT[i-j]+price[j]);
        }
    }
}

int main()
{
    cin >> n;
    DT.resize(n+1,0);
    int len=sizeof(price) / sizeof(int);
    solution2();
    cout << DT[n] << endl;

    return 0;
}
