#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ss = 0, n;
    int bt=1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        double t1, t2;
        cin >> t1 >> t2 >> s;
        if (s == 1) ss = 1 - ss;        //벨트 회전방향

        if(n != 1)
            bt = (bt/t1)*t2;
        else if(n == 1)
            bt = t2/t1;

    }

    cout << ss << " " << bt;
}
