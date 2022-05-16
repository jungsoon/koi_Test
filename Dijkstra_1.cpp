#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

int number=6;
int INF = INT_MAX;

int a[6][6]={
    {0,2,5,1,INF,INF},
    {2,0,3,2,INF,INF},
    {5,3,0,3,1,5},
    {1,2,3,0,1,INF},
    {INF,INF,1,1,0,2},
    {INF,INF,5,INF,2,0},
};
bool visit[6];      // �湮�� ���
int d[6];           //�ִܰŸ�

// ���� ���� �����ϴ� ��� , ���� �ּ� �Ÿ��� ������ ������ ��ȯ�մϴ�.
int SmallIndex(){

    int min = INF;
    int index = 0;
    for(int i=0;i<number;i++){
        //cout << d[i] << endl;
        if(d[i]<min && !visit[i]){      //����� ���� ��带 ���ؿ´�.
            min = d[i];
            index = i;                  // ���� ���� ����� �ε��� ���� �����´�.
        }
    }

    return index;
}
//Ư���� �������� �ٸ� �������� ���� �ּҺ���� ����� �ִ� �Լ�
void dijkstra(int start) {
    for(int i=0;i<number;i++){
        d[i] = a[start][i];         // ���������� �ؼ� ��� ��� ����� d�迭�� ����Ѵ�.
    }
    visit[start] = true;                // ���������� �湮ó����
    for(int i=0;i<number-2;i++){
        int current = SmallIndex();  // ���� ª�� ��带 current�� ����

        visit[current]=true;
        for(int j=0;j<6;j++){
            if(!visit[j]) {
                if(d[current]+a[current][j]<d[j]){      // 1���� ��뺸�� �������ļ� ���� ����� �� ������ ��� d�迭�� �����ض�.
                    d[j]=d[current] + a[current][j];
                    cout << d[j]<<endl;
                }
            }
        }
    }
}

int main(void){
    dijkstra(0);
    for(int i=0;i<number;i++){
        printf("%d ",d[i]);
    }
}
