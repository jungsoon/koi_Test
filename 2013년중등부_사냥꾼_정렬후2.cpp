/* 2013�� �ߵ��_��ɲ�_������ */

#include <cstdio>
#include <iostream>
#include <algorithm>
#define Max_N 100000
using namespace std;
int xpos[Max_N];

pair<int,int> a[Max_N];         // �������� Ÿ�� �Ű������� ���� Ŭ���� ���ø�

int calc(int x, int y, int z)
{
    return abs(z-x)+y;      // (�����ġ - x����ġ) + y����ġ
}

int main()
{
   int idx=0, m, n, l;
   int i;
   int answer=0;   //���䰳��

    scanf("%d%d%d", &m, &n, &l);    // m=����, n=������, l=�����Ÿ�

    for (i=0;i<m;i++) {
        scanf("%d", &xpos[i]);
    }
    for (i=0;i<n;i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a,a+n);                // ������ ��ġ ����
    sort(xpos,xpos+m);          // ��� ��ġ ����

    for(i=0;i<n;i++){
        while(idx < m && xpos[idx] < a[i].first){              // ���Ÿ� < m, ���Ÿ��� ������ x�� ��ġ�� ū ��� idx�� ���� ��Ų��.
          idx++;
        }
        if(idx>0 && calc(a[i].first,a[i].second,xpos[idx-1])<=l)        // idx�� count�ϸ� �� ������ �����Ѵ�. ���� ���Ÿ��� ������ ��ġ���� �Ÿ��� ��
        {
            answer++;
            continue;
        }
        if(idx<m && calc(a[i].first,a[i].second,xpos[idx])<=l)          // ���� ���Ÿ��� ���� ��ġ���� �Ÿ��� �� Ȯ���ϱ� ���� ����
        {
            answer++;
            continue;
        }

    }
    printf("%d",answer);

 return 0;
}
