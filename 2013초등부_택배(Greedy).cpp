#include <iostream>
#include <algorithm>
using namespace std;
#define N 10001

struct Delivery{
    int v1;
    int v2;
    int box;
};

Delivery V[N];
int truck[N];

bool compare(const Delivery &p,const Delivery &q){

//  v2는 작은 숫자가, v2가 같을 때는 v1숫자가 작은 숫자면 참
    return p.v2 < q.v2 || (p.v2 == q.v2 && p.v1 > q.v1);
}
int min(int p,int q) {
    return p<q ? p : q;
}
int main()
{
    int n,c,m;
    int result=0,v=0;

    cin >> n >> c;
    cin >> m;

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&V[i].v1,&V[i].v2,&V[i].box);
    }
    sort(V,V+m,compare);

    int sum=0;
    for(int i=0;i<m;i++){
        int x=0;
        for(int j=V[i].v1 ; j<V[i].v2 ; j++){
            if(truck[j]>x) x=truck[j];  // pop
        }

        v=min(V[i].box,c-x);
        cout << v<<endl;

        for(int j=V[i].v1 ; j<V[i].v2 ; j++){
            truck[j] += v;      // push
        }
        result += v;
    }
    printf("%d\n",result);
    return 0;

    return 0;

}
