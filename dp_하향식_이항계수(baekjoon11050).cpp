#include <iostream>
using namespace std;
int D[100][100];

int Pascal(int n, int r){

    if(n<=0 || r<=0 || n==r) return 1;
    if(n>1 && r==1) return n;
    if(D[n][r] > 0) return D[n][r];
    return D[n][r]=Pascal(n-1,r-1)+Pascal(n-1,r);
}

int main()
{
    int n,r,k;
    int i,j;
    int result;
    cin >> n >> r;
    cout << Pascal(n,r) << endl;
}
