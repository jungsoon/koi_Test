/*
�ﰢȭ�� �����(S)
�ﰢ���� �κ��� ������ ���� ������ �Ѻ��� ���̺��� �۴�. a+b>c
*/
#include <iostream>
using namespace std;
void solution(int n, int a, int b, int c);
int chk[21][21][21];

int cnt;
int n;
int main()
{

    cin >> n;

    solution(n,1,1,1);
    cout << cnt << endl;
    return 0;
}
void solution(int n, int a, int b, int c)
{
    if(a+b+c == n)
    {
        if(a<=b && b<=c && a+b>c && chk[a][b][c]==0)
        {
            printf("%d %d %d\n",a,b,c);
            cnt++;
            chk[a][b][c]=1;
        }
        return;
    }

    solution(n, a+1, b, c);
    solution(n, a, b+1, c);
    solution(n, a, b, c+1);
}

//�ݺ������� Ǭ ����
/*
int solution()
{
    int total=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                if(i+j+k == n && i+j > k )
                {
                    cout << i << " " << j << " " << k << endl;
                    total++;
                }
            }
        }
    }
    return total;
}
*/
