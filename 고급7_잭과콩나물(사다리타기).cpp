#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

vector <int> w;
vector <vector<int>> DT;

int Min(int x, int y){
    return (x<y)?x:y;
}

int main()
{
    int n,m;
    int a,b,in,del;

    cin >> n >> m;
    cin >> a >> b >> del >> in;
    w.resize(m+1,0);
    DT.resize(m+1, vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        cin >> w[i];
    }

    for(int i=0;i<=m;i++){          // 3행 4열
        for(int j=0;j<=n;j++){
            DT[i][j]=INT_MAX;
        }
    }

    for(int j=1;j<=n;j++)
    {
        DT[0][j]=abs(j-a)*in;   //시작 지점에서 현 지점까지의 추가 비용
    }
    //j=도착점, k=시작점
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k && (w[i]==k || w[i]+1==k)){                           //시작점 k와 도착점 j가 같은 경우(일직선)
                    DT[i][j] = Min(DT[i-1][k]+del , DT[i][j]);                // 다른 곳 경로+추가선 < 가로선 제거 비용
                    cout << i << "/ " << j << "/ " << k << "/ " << DT[i-1][k]+del << endl;
                }
                else if((j<=w[i] && w[i]<k) || (k<=w[i] && w[i]<j)){         // 시작점 k와 도착점 j 사이에 i번째 가로선이 존재하는 경우

                    DT[i][j] = Min(DT[i-1][k]+(abs(j-k)-1)*in , DT[i][j]);         // 가로선을 추가한 것과 다른 경로로 j까지 오는 경우 최소값
                    cout << i << " " << j << " " << k << " " << DT[i-1][k]+(abs(j-k)-1)*in << endl;
                }
                else{                                                           // 시작점 k와 도착점 j 사이에 i번째 가로선이 존재하지 않는 경우
                    DT[i][j] = Min(DT[i-1][k]+abs(j-k)*in , DT[i][j]);          // 가로선을 추가한 것과 다른 경로로 j까지 오는 경우 최소값
                    cout << i << "* " << j << "* " << k << "* " << DT[i-1][k]+abs(j-k)*in << endl;
                }
            }
        }
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << DT[i][j] << " ";
        }
        cout << endl;
    }
    cout << DT[m][b];




}
