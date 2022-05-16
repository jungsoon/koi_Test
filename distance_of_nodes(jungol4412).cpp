#include <iostream>
using namespace std;
//vector<int> v;
int d1,d2;
int solution(int x, int y)
{
    if(x==y) return 0;
    else if(x<y) return solution(x, y/2)+1;
    else if(y<x) return solution(x/2, y)+1;
}

int main()
{
    int n,m;

    cin >> n >> m;
    cout << solution(n,m) << endl;
    return 0;
}
