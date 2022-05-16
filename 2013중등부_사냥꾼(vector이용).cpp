#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct animal{
    int x;
    int y;
};

bool compare(const animal &p, const animal &q){
    return p.x < q.x || (p.x == q.x) && (p.y < q.y);
}

int main()
{
    int n, m, range;

    cin >> n >> m >> range;
    vector<int> r(n);
    vector<animal> xpos(m);

    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    for(int i=0;i<m;i++){
        cin >> xpos[i].x >> xpos[i].y;
    }

    sort(r.begin(),r.end());
    sort(xpos.begin(),xpos.end(), compare);
/*
    for(int i=0;i<n;i++){
        cout << r[i] << " ";
    }
    cout << endl;
    for(int i=0;i<m;i++){
        cout << xpos[i].x << " " << xpos[i].y << endl;
    }

*/
    int cnt=0;
    int idx=0;          // ���Ÿ� index��
    for(int i=0;i<m;i++){
        while(idx < n && r[idx] < xpos[i].x)    //idx < n ���ٸ� ���Ÿ� < ������ x��ǥ�� ������ count
        {
            idx++;
        }

        if(idx>0 && abs(r[idx-1] - xpos[i].x) + xpos[i].y <= range)     // ���Ÿ� idx>0���� ũ�� ���� idx ��(���Ÿ�)�� ����Ŵ
        {
            cnt++;
            continue;
        }
        if(idx<n && abs(r[idx] - xpos[i].x) + xpos[i].y <= range)
        {
            cnt++;
            continue;
        }

    }
    cout << cnt << endl;

    return 0;
}
