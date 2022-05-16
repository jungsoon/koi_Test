#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> DT;

int Min(int x,int y,int z)
{
    if(x<y && x<z) return x;
    else if(y<x && y<z) return y;
    else return z;
}

int main()
{
    string s1, s2;
    int n1,n2;

    cin >> s1 >> s2;
    n1=s1.size();
    n2=s2.size();

    DT.resize(n1+1, vector<int> (n2+1,0));

    for(int i=0;i<=n2;i++){
        DT[0][i] = i;
    }

    for(int i=0;i<=n1;i++){
        DT[i][0] = i;
    }


    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i] == s2[j]) {
                DT[i][j] = DT[i-1][j-1];
            }
            else{
                DT[i][j]=Min(DT[i-1][j-1], DT[i-1][j], DT[i][j-1])+1;
            }
        }
    }

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            cout << DT[i][j] <<" ";
        }
        cout << endl;
    }

    cout << DT[n1-1][n2-1] << "\n";
    return 0;
}
