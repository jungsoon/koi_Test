#include <cstdio>
#include <iostream>
using namespace std;
#define MAXDAY 100

int N,M;
int R[MAXDAY+1];
int D[MAXDAY+1][MAXDAY*2+1];

void solution(int i, int j, int v){
    if(i > N) return ;      // 날짜가 지정한 날짜 보다 크다면  return
    if(D[i][j] == -1) D[i][j]=v;
    if(D[i][j] > v) D[i][j]=v;  // 비용 최소값 구하기

}

int main()
{
    int x;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) R[i]=1;        // 날짜 배열에 1을 채운다.
    for(int i=0;i<M;i++){
        scanf("%d",&x);
        R[x]=0;     // 쉬는 날에 0으로 채운다.
    }

    for(int i=0;i<=M;i++){          // D 배열에 -1을 채운다.
        for(int j=0;j<=M*2;j++){
            D[i][j]=-1;
        }
    }
    D[0][0]=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<=i*2;j++){
            if(D[i][j]==-1) continue;


            if(R[i+1]==0) solution(i+1,j,D[i][j]);          //쉬는날에는 쿠폰은 없고, 날짜만 카운트 한다.

            if(j >= 3) solution(i+1, j-3, D[i][j]);
            cout << i << " " << j << D[i][j] << endl;
            solution(i+1,j,D[i][j]+10000);

            solution(i+1,j+1,D[i][j]+25000);
            solution(i+2,j+1,D[i][j]+25000);
            solution(i+3,j+1,D[i][j]+25000);

            solution(i+1,j+2,D[i][j]+37000);
            solution(i+2,j+2,D[i][j]+37000);
            solution(i+3,j+2,D[i][j]+37000);
            solution(i+4,j+2,D[i][j]+37000);
            solution(i+5,j+2,D[i][j]+37000);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
}
