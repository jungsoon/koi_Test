/*
5 5
#S###
#...#
#.#.#
#....
###G#
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {int x,y;};      // ��ġ ������ ������ ���� class
vector<string> v;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int h , w;
string s;

bool gade(int x, int y)
{
    return (x>=0 && x<w) && (y>=0 && x<h);
}

char solution(int x, int y)
{
    queue<Pos> Q;

    Q.push({x,y});
    v[x][y]='0';        // S(������)�� 0���� �ʱ�ȭ

    // BFS ����
    cout << "\nx \t y \t �ִܰŸ�\n";
    while(!Q.empty())
    {
        Pos current = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int a=current.x+dx[i];                  // ���ο� ��ġ ����
            int b=current.y+dy[i];

            if(gade(a,b) && v[a][b] == 'G')            // �������� �����ߴٸ� return
            {
                int answer = (int)v[current.x][current.y]+1;
                cout << "�ִܰŸ� : ";
                return answer;
            }

            if(gade(a,b) && v[a][b] == '.')
            {
                v[a][b] = v[current.x][current.y]+1;
                printf("%d \t %d \t %c\n", a, b, v[a][b]);
                Q.push((Pos){a, b});
            }
        }
    }
}


int main()
{
    cin >> h >> w;
    cout << "<< �Է� >>" << endl;
    for(int i=0;i<h;i++)
    {
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<h;i++)
    {
        int s=v[i].find("S");
        cout << solution(i,s) << endl;
        break;
    }

    cout << "\n<< �̷�ã�� �迭 �籸�� >>" << endl;
    for(int i=0;i<h;i++)
    {
        cout << v[i] << endl;
    }

}
