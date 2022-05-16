/*
4
120 110 140 150
485
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main()
{
    int n,sum=0,total_money;
    cin >> n;

    for(int i=0;i<n;i++){
        int money;
        cin >> money;
        v.push_back(money);
        sum += money;
    }

    cin >> total_money;

    sort(v.begin(), v.end());

    if(sum <= total_money)
    {
        cout << v[n-1];
        return 0;
    }

    sum=0;
    int answer=0;
    for(int i=0;i<v.size();i++){

        if( sum+(v[i]*(n-i)) >= total_money){
            answer = (total_money - sum)/(n-i);
            break;
        }
        else sum += v[i];
    }
    cout << answer;

    return 0;
}
