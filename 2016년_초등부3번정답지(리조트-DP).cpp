#include <cstdio>
#include <iostream>
using namespace std;
#define MAXDAY 100

int N,M;
int R[MAXDAY+1];
int D[MAXDAY+1][MAXDAY*2+1];

void solution(int i, int j, int v){
    if(i > N) return ;      // ��¥�� ������ ��¥ ���� ũ�ٸ�  return
    if(D[i][j] == -1) D[i][j]=v;
    if(D[i][j] > v) D[i][j]=v;  // ��� �ּҰ� ���ϱ�

}

int main()
{
    int x;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) R[i]=1;        // ��¥ �迭�� 1�� ä���.
    for(int i=0;i<M;i++){
        scanf("%d",&x);
        R[x]=0;     // ���� ���� 0���� ä���.
    }

    for(int i=0;i<=M;i++){          // D �迭�� -1�� ä���.
        for(int j=0;j<=M*2;j++){
            D[i][j]=-1;
        }
    }
    D[0][0]=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<=i*2;j++){
            if(D[i][j]==-1) continue;


            if(R[i+1]==0) solution(i+1,j,D[i][j]);          //���³����� ������ ����, ��¥�� ī��Ʈ �Ѵ�.

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
