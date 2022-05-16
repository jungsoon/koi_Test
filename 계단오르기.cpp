#include <iostream>
using namespace std;

int n,ans;

void solution(int v)
{
    if(v>n) return;
    if(v==n){
        ans++;
        return;
    }
    solution(v+1);
    solution(v+2);

}

int main()
{
    cin >> n;

    solution(0);

    cout << ans;

    return 0;
}
