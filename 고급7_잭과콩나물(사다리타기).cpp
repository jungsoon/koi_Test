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

    for(int i=0;i<=m;i++){          // 3�� 4��
        for(int j=0;j<=n;j++){
            DT[i][j]=INT_MAX;
        }
    }

    for(int j=1;j<=n;j++)
    {
        DT[0][j]=abs(j-a)*in;   //���� �������� �� ���������� �߰� ���
    }
    //j=������, k=������
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k && (w[i]==k || w[i]+1==k)){                           //������ k�� ������ j�� ���� ���(������)
                    DT[i][j] = Min(DT[i-1][k]+del , DT[i][j]);                // �ٸ� �� ���+�߰��� < ���μ� ���� ���
                    cout << i << "/ " << j << "/ " << k << "/ " << DT[i-1][k]+del << endl;
                }
                else if((j<=w[i] && w[i]<k) || (k<=w[i] && w[i]<j)){         // ������ k�� ������ j ���̿� i��° ���μ��� �����ϴ� ���

                    DT[i][j] = Min(DT[i-1][k]+(abs(j-k)-1)*in , DT[i][j]);         // ���μ��� �߰��� �Ͱ� �ٸ� ��η� j���� ���� ��� �ּҰ�
                    cout << i << " " << j << " " << k << " " << DT[i-1][k]+(abs(j-k)-1)*in << endl;
                }
                else{                                                           // ������ k�� ������ j ���̿� i��° ���μ��� �������� �ʴ� ���
                    DT[i][j] = Min(DT[i-1][k]+abs(j-k)*in , DT[i][j]);          // ���μ��� �߰��� �Ͱ� �ٸ� ��η� j���� ���� ��� �ּҰ�
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
