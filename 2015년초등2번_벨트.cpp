#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ss = 0, n;
    double bt1, bt2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        double t1, t2;
        cin >> t1 >> t2 >> s;
        if (s == 1) ss = (ss == 0);

        if (i != 0)
        {
            t2 *= (bt2 / t1);
        }
        else if (i == 0) {
            t2 /= t1;
            t1 /= t1;
        }

        bt1 = t1;
        bt2 = t2;
    }

    cout << ss << " " << bt2;
}
