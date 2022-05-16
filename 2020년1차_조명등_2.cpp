#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const ll INF = (ll)1e18;
int N;
typedef pair<ll, ll> p;

struct Data
{
    Data() {}
    Data(ll x, ll y):a(x-y),b(x+y){}        // a:왼쪽 그림자, b:오른쪽 그림자
    ll a,b;
};
vector <Data> arr;

struct Line
{
    Line() {}
    Line(ll a, ll b):a(a),b(b) {}
    ll a,b;
    inline ll f(ll x) {return a*x+b;};
};

bool comp(Line l1, Line l2, Line l3)
{
    double x1 = (double)(l2.b - l1.b) / (l1.a - l2.a);
    double x2 = (double)(l3.b - l1.b) / (l1.a - l3.a);
    return x1>=x2;
}

void input()
{
    int n=0;
    ll x,y;

    cin >> N;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> x >> y;
        arr[i]=Data(x,y);
    }

    // 쓸모없는 좌표는 제거해라.그림자 위치보다 작은 위치입력된 데이터 -------------
    for(int i=1;i<=N;i++){
        cout << "%" << arr[i].a << " " << arr[i].b << endl;

        while(n>=1 && arr[n].a >= arr[i].a) --n;
        cout << "*" << arr[n].a << " " << arr[n].b << endl;
        if(arr[n].b < arr[i].b) arr[++n]=arr[i];
    }
    //------------------------------------------------------

    N=n;

}
ll solution()
{
    deque<Line> dq;
    dq.push_back(Line(-2*arr[1].a, arr[1].a*arr[1].a));
    ll dpi;
    for(int i=1;i<=N;i++)
    {
        while((int)dq.size()>=2 && dq[0].f(arr[i].b) >= dq[1].f(arr[i].b))
            dq.pop_back();

        dpi = dq.front().f(arr[i].b) + arr[i].b * arr[i].b;

        if(i<N)
        {
            Line l = Line(-2*arr[i+1].a , arr[i+1].a * arr[i].b);
            while((int)dq.size()>=2 && comp(dq[(int)dq.size()-2],dq.back(),l))
                  dq.pop_back();
            dq.push_back(l);
        }
    }
    return dpi;
}

int main()
{
    int T;
    const char* rem[4] ={"00","25","50","75"};      // 4로 나눈 값을 미리 저장
    cin >> T;
    while(T--)
    {
        input();
        ll ans = solution();
        cout << ans << endl;
        printf("%lld.%s\n",ans/4,rem[ans/4]);
    }
    return 0;
}
