/*
N-Queen
알고리즘 : BackTracking
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> col;
vector<int> dia;
int n;
void solution(int x)
{
    if(x>n){
        answer++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i] || !col[x+i] || !dia[n+(x-i)]){
            col[x+i]=dia[n+(x-i)+1]=1;
            solution(x+1);
            col[]

        }
    }


}

int main()
{
    cin >> n;

    v.resize(n+1,0);
    col.resize(n*n+1,0);
    dia.resize(n*n+1,0);
    for(int i=1;i<=n;i++){
        v[i]=1;
        solution(i);
    }
    return 0;
}
