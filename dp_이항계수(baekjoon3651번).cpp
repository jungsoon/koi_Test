#include <iostream>
using namespace std;
int D[101][101];
int R[101][2];
int count=0;

int Pascal(int n, int r){
    if(D[n][r] > 0 ) return D[n][r];
    return D[n][r]=Pascal(n-1,r-1)+Pascal(n-1,r);
}

int main()
{
    int k;
    cin >> k;
    Pascal(k,k);

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}

