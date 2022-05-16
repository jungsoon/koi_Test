#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#define SIZE INT_MAX

using namespace std;

vector <int> coin, DT;

int solution(int money2,int n)     //皋葛捞力捞记 规过
{
    int result = INT_MAX;
    if(money2==0) return 0;
    if(DT[money2]) return DT[money2];

    for(int i=n-1;i>=0;i--){
        if(coin[i] <= money2){
            int cnt = solution(money2-coin[i], n);
            if(cnt + 1 < result){
                result = cnt+1;
            }
        }
    }
    return DT[money2]=result;

}

int main()
{
    int money, n;

    cin >> money;
    cin >> n;
    coin.resize(n,0);
    DT.resize(money+1,0);

    for(int i=0;i<n;i++){
        cin >> coin[i];
    }

    cout << solution(money,n);

}
