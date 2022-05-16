//DP - 삼각그래프(백준 4883번)

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int N = 100000, INF = INT_MAX;
vector <vector<int>> arr;
vector <vector<int>> D;

int dp(int i, int j)
{
    if(i==1 && j==2) return D[i][2]=arr[i][2];
    if(i==1 && j==3) return D[i][3]=arr[i][2]+arr[i][3];
    if(i<=1 || j<1 || j>3) return INF;
    if(D[i][j]!=INF) return D[i][j];

    return D[i][j]=min({dp(i-1,j-1),dp(i-1,j),dp(i-1,j+1),dp(i,j-1)})+arr[i][j];

}

int main()
{
    int n, k=1,i,j;

    while(1){
        cin >> n;

        if(n==0) break;
        arr.resize(n+1,vector<int> (4));
        D.resize(n+1,vector<int> (4));
        for(i=1;i<=n;i++)
            for(j=1;j<=3;j++){
                D[i][j] = INF;
                scanf("%d",&arr[i][j]);
            }
        cout << k << ". " << dp(n,2) << endl;
        k++;
    }


}
