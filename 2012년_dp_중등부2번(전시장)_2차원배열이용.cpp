#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 300000
int d[SIZE+1][2],Max[SIZE+1], idx[SIZE+1];
int n,h,k;

struct Picture{
    int h;
    int cost;
};

bool compare(const Picture &p, const Picture &q){
    return (p.h < q.h || (p.h == q.h) && p.cost > q.cost);
}

int main()
{

    int s;
    cin >> n >> s;
    vector<Picture> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i].h >> p[i].cost;
    }

    sort(p.begin(),p.end(),compare);
/*
    cout << endl;
    for(int i=0;i<n;i++){
        cout << p[i].h << " " << p[i].cost << endl;
    }
*/

    for(int i=1;i<=n;i++){
        for(idx[i]=idx[i-1]+1;idx[i]<i;idx[i]++){
            if(p[i].h - p[idx[i]].h < s)
                break;
        }
        idx[i]--;
    }

 //   for(int i=1;i<=n;i++) cout << idx[i] << " ";
 /*
    for(int i=1;i<=n;i++){
        d[i]=Max[idx[i]] + p[i].cost;
        Max[i]=(Max[i-1]>d[i]) ? Max[i-1] : d[i];
    }
*/
    for(int i=1;i<=n;i++){
        d[i][0]= d[idx[i]][1]+p[i].cost;
        d[i][1]= (d[i-1][1] > d[i][0]) ? d[i-1][1] : d[i][0];
    }

    cout << d[n][0] << endl;

    return 0;

}
