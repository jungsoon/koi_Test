#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int solution(int x){

    if(x<=1) return 1;

    if(v[x]) return v[x] % 20100529;

    return v[x]=(solution(x-1) + 2*solution(x-2)) % 20100529;

}
int main()
{
    int n;
    cin >> n;

    v.resize(n+1, 0);
    v[0]=1;
    v[1]=1;
    v[2]=3;

    solution(n);

    cout << v[n] << endl;

    return 0;
}
