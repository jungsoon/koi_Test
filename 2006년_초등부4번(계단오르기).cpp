
// DP - 2006년 - 초등부 4번(계단오르기)
#include <iostream>
#include <algorithm>
using namespace std;
int D[305][2];
int s[305];

int solution(int n){
    D[1][1]=s[1];
    D[2][1]=s[2];
    D[2][2]=s[1]+s[2];
    for(int i=3;i<=n;i++){
        D[i][1] = max(D[i-2][1],D[i-2][2])+s[i];
        D[i][2] = D[i-1][1]+s[i];
    }
    return max(D[n][1],D[n][2]);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin >> s[i];
    cout << solution(n) << endl;

    return 0;
}
