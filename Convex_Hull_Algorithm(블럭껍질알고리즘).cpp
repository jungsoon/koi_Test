#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define MAX 100002

using namespace std;

typedef long long ll;

struct INFO {
    int x, y; // �ʱⰪ : 0,0
    int p, q; // �ʱⰪ : 1,0
    INFO(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}      //������
};
//------------------ ���� -------------------------------------
bool comp(const INFO &A, const INFO &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)           //1LL�� ���� �ָ� int���� long long������ �����
        return 1LL * A.q * B.p < 1LL * A.p*B.q;

    // y ��������, y�� ���� ���� x ��������
    if(A.y < B.y) return true;
    else if(A.y == B.y && A.x < B.x) return true;
    else return false;
}
//--------------------------------------------------------------

ll ccw(const INFO &A, const INFO &B, const INFO &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

INFO cover[MAX];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        cover[i] = INFO(x, y);
    }
    cout << endl;

    // y��ǥ ���� �������� ����
    sort(cover, cover + n, comp);

    // ���������κ��� ��� ��ġ ���
    for (int i = 1; i < n; i++) {
        printf("%d %d ",cover[i].x, cover[i].y);
        cover[i].p = cover[i].x - cover[0].x;
        cover[i].q = cover[i].y - cover[0].y;
        printf("%d %d\n",cover[i].p,cover[i].q);
    }

    // �ݽð� �������� ����(������ ����)
    sort(cover + 1, cover + n, comp);

    for(int i=0;i<n;i++){
        printf("%d %d %d %d\n",cover[i].x, cover[i].y, cover[i].p, cover[i].q);
    }
    stack<int> s;

    // ���ÿ� first, second�� �־��ش�.
    s.push(0);
    s.push(1);

    int next = 2;

    while (next < n) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();

            // first, second, next�� ��ȸ�� ( > 0 )�̶�� second push
            // ��ȸ��( < 0 )�̶�� ���� while�� ��� �ݺ�
            if (ccw(cover[first], cover[second], cover[next]) > 0) {
                s.push(second);
                break;
            }
        }

        // next push
        s.push(next++);
    }

    printf("%d", s.size());
    return 0;
}


//��ó: https://www.crocus.co.kr/1288 [Crocus]
