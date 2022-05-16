#include <iostream>
#include <queue>
using namespace std;
struct remocon{
    int temp;
    int cnt;
};
queue <remocon>Q;
int b;

int solution(int temp, int cnt)
{
    remocon r;

    Q.push({temp, cnt});
    while(!Q.empty())
    {
        r=Q.front();
        Q.pop();
        if (r.temp == b){
            break;
        }

        else if(r.temp < b){
            Q.push({r.temp+10,r.cnt+1});
            Q.push({r.temp+5,r.cnt+1});
            Q.push({r.temp+1,r.cnt+1});
        }
        else{
            Q.push({r.temp-10,r.cnt+1});
            Q.push({r.temp-5,r.cnt+1});
            Q.push({r.temp-1,r.cnt+1});
        }


    }

    return r.cnt;
}

int main()
{
    int a;

    cin >> a >> b;

    printf("%d",solution(a,0));
}
