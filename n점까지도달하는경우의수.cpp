
/*
플레이어가 한 번에 3점, 5점, 10점을 얻을 수 있는 게임이 있습니다.
m=13일때 경우의 수는  (3,10), (3,5,5), (5,3,5), (5,5,3), (10,3)
=> (3,10),(8,5),(10,3) => 3번 index=1, 5번 index=1, 8번 index=2, 10번 index=2 => 5
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;

    cin >> m;

    vector<int> v(m+1,0);
    v[0]=1;

    for(int i=1;i<=m;i++){
        if(i-3 >= 0) v[i] += v[i-3];
        if(i-5 >= 0) v[i] += v[i-5];
        if(i-10 >= 0) v[i] += v[i-10];

    }
    cout << v[m];
}
