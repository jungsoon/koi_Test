/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> Size;
int n;
int cnt;        // ��� ����ΰ�?
int idx=1;      // �Ѱ��� ����� 1�� ����
// ���� ��, ������ ��, ���� ��, �Ʒ��� ��
bool gade(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y<n);
}
//�������� ������ �ϱ� ���� �Լ� ������
bool cmp(int x, int y)
{
    return x>y;
}
void f_fill(int x, int y, int z)        //x��, y�� ,ä�� ����
{
    cnt++;
    v[x][y]=z;
    if(gade(x+1,y) && v[x+1][y]==1)   f_fill(x+1,y,z);  //������
    if(gade(x-1,y) && v[x-1][y]==1)   f_fill(x-1,y,z);  //����
    if(gade(x,y+1) && v[x][y+1]==1)   f_fill(x,y+1,z);  //��
    if(gade(x,y-1) && v[x][y-1]==1)   f_fill(x,y-1,z); //�Ʒ�

}
void print()
{
    cout << idx-1 << endl;
    for(int i=0;i<n;i++)
        if(Size[i]!=0)
            cout << Size[i] << endl;
}

int main()
{
    cin >> n;
    v.resize(n+1,vector<int> (n+1,0));
    Size.resize(n+1,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt=0;
            if(v[i][j] == 1)
            {
                idx++;
                f_fill(i,j,idx);
                Size[idx-2]=cnt;
            }
        }
    }
    sort(Size.begin(),Size.end(),cmp);
    print();
}
