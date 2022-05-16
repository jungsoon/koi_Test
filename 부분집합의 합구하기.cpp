#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> DT;

bool solution(int idx, int n, int sub)
{
    cout << idx << " " << n << " " << sub << endl;

    if(sub == 0) return true;
    if(n == 0)  return false;
    if(sub < arr[idx]) return false;

    return solution(idx+1,n-1,sub-arr[idx]) || solution(idx+1,n-1,sub);
}

int main()
{
    int subset;
    cin >> n >> subset;
    arr.resize(n+1,0);
    DT.resize(n+1,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int result=solution(0,n-1, subset);
    cout << "*" << result << endl;
/*
    for(int i=0;i<n;i++){
        cout << DT[i] << endl;
    }*/
}
