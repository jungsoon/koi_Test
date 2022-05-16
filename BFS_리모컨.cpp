#include <iostream>
#include <queue>
using namespace std;

struct remocon {
    int x;
    int cnt;
};
queue<remocon> Q;
int a,b;
void BFS(int temp,int cnt)
{
    remocon r;

    Q.push((remocon){temp,cnt});

    while(!Q.empty())
    {
        r=Q.front();
        Q.pop();
        if(r.x == b) break;

        cout << r.x << " " << r.cnt << endl;

        if(r.x < b)
        {
            Q.push({r.x+10, r.cnt+1});
            Q.push({r.x+5, r.cnt+1});
            Q.push({r.x+1, r.cnt+1});
        }
        else{
            Q.push({r.x-10, r.cnt+1});
            Q.push({r.x-5, r.cnt+1});
            Q.push({r.x-1, r.cnt+1});
        }
    }
    cout << r.cnt << endl;
}
int main()
{
    cin >> a >> b;

    BFS(a,0);

}
