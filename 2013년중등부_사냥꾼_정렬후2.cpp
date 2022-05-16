/* 2013년 중등부_사냥꾼_정렬후 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#define Max_N 100000
using namespace std;
int xpos[Max_N];

pair<int,int> a[Max_N];         // 여러개의 타입 매개변수를 가진 클래스 템플릿

int calc(int x, int y, int z)
{
    return abs(z-x)+y;      // (사대위치 - x축위치) + y축위치
}

int main()
{
   int idx=0, m, n, l;
   int i;
   int answer=0;   //정답개수

    scanf("%d%d%d", &m, &n, &l);    // m=사대수, n=동물수, l=사정거리

    for (i=0;i<m;i++) {
        scanf("%d", &xpos[i]);
    }
    for (i=0;i<n;i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a,a+n);                // 동물의 위치 정렬
    sort(xpos,xpos+m);          // 사대 위치 정렬

    for(i=0;i<n;i++){
        while(idx < m && xpos[idx] < a[i].first){              // 사대거리 < m, 사대거리와 동물의 x축 위치가 큰 경우 idx를 증가 시킨다.
          idx++;
        }
        if(idx>0 && calc(a[i].first,a[i].second,xpos[idx-1])<=l)        // idx가 count하면 이 문장을 실행한다. 이전 사대거리와 동물의 위치간의 거리가 비교
        {
            answer++;
            continue;
        }
        if(idx<m && calc(a[i].first,a[i].second,xpos[idx])<=l)          // 현재 사대거리와 동물 위치간의 거리를 비교 확인하기 위한 조건
        {
            answer++;
            continue;
        }

    }
    printf("%d",answer);

 return 0;
}
