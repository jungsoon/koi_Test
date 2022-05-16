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
bool visit[6];      // 방문한 노드
int d[6];           //최단거리

// 가장 쉽게 구현하는 방법 , 가장 최소 거리를 가지는 정점을 반환합니다.
int SmallIndex(){

    int min = INF;
    int index = 0;
    for(int i=0;i<number;i++){
        //cout << d[i] << endl;
        if(d[i]<min && !visit[i]){      //비용을 적은 노드를 구해온다.
            min = d[i];
            index = i;                  // 가장 적은 노드의 인덱스 값을 가져온다.
        }
    }

    return index;
}
//특정한 정점에서 다른 정점으로 가는 최소비용을 계산해 주는 함수
void dijkstra(int start) {
    for(int i=0;i<number;i++){
        d[i] = a[start][i];         // 시작점으로 해서 모든 경로 비용을 d배열에 등록한다.
    }
    visit[start] = true;                // 시작지점을 방문처리함
    for(int i=0;i<number-2;i++){
        int current = SmallIndex();  // 가장 짧은 노드를 current에 보관

        visit[current]=true;
        for(int j=0;j<6;j++){
            if(!visit[j]) {
                if(d[current]+a[current][j]<d[j]){      // 1번의 비용보다 여러거쳐서 가는 비용이 더 저렴한 경우 d배열을 갱신해라.
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
