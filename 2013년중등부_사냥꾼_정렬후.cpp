#include<stdio.h>
#include<algorithm>
#include<time.h>
using namespace std;

int M,N,L;
int x[100000]={0,};


struct Animal {
    int x,y;

    bool operator<(const Animal&animal) const{return x < animal.x;}

}a[100000];



int solve(void)

{
    sort(x,x+M);
    sort(a,a+N);
    int count=0, j=0;
    for(int i=0; i<N; i++){
        while(j< M && x[j] < a[i].x) j++;
        if(j > 0 && (a[i].x-x[j-1])+a[i].y <= L || j < M && (x[j]-a[i].x)+a[i].y <= L)
        {
            count++;

        }

    }
    return count;
}

int main(void)
{
    int i;

    scanf("%d %d %d",&M, &N, &L);
    for(i=0; i<M; i++) scanf("%d",&x[i]);
    for(i=0; i<N; i++) scanf("%d %d",&a[i].x, &a[i].y);

    printf("%d\n",solve());
    return 0;

}

