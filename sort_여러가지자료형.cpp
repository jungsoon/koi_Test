#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int print(int *arr);
void vprint(vector<int> v);
void sprint(struct Pos *p);
struct Pos{
    int x;
    int y;
};
bool compare(int x, int y)      // 일반 int형 변수 내림차순 정렬을 위한 함수포인터
{
        return x > y;
}

bool sCompare(Pos &p, Pos &q)   // struct class 내림차순 정렬을 위한 함수포인터
{
    if(p.x > q.x) return true;
    else if(p.x == q.x && p.y > q.y ) return true;
    else return false;

}

int main()
{

        int arr[10];
        vector<int> v(10);

        Pos p[10];
        srand((unsigned)time(NULL));

        for(int i=0;i<10;i++){
            arr[i]=rand()%10;
            v[i]=rand()%10;
        }

        for(int i=0;i<10;i++){
            p[i].x = rand()%10;
            p[i].y = rand()%10;
        }

        cout << "arr 배열 출력" << endl;
        print(arr);
        cout << "\n\n";

        cout << "vector v 출력" << endl;
        vprint(v);
        cout << "\n\n";

        cout << "vector v 출력" << endl;
        sprint(p);
        cout << "\n\n";

        // arr 오름차순 정렬
        sort(arr,arr+10);


        // vector v 오름차순 정렬
        sort(v.begin(), v.end());

        cout << "오름차순 정렬후 arr 배열 출력" << endl;
        print(arr);
        cout << "\n\n";

        cout << "오름차순 정렬후 vector v 출력" << endl;
        vprint(v);
        cout << "\n\n";

        // arr 내림차순 정렬
        sort(arr,arr+10, compare);


        // vector v 내림차순 정렬
        sort(v.begin(), v.end(), compare);

        cout << "내림차순 정렬후 arr 배열 출력" << endl;
        print(arr);
        cout << "\n\n";

        cout << "내림차순 정렬후 vector v 함수포인터 사용 출력" << endl;
        vprint(v);
        cout << "\n\n";

        sort(v.begin(), v.end(), greater<int>());
        cout << "내림차순 정렬후 vector v greater함수 사용 출력" << endl;
        vprint(v);


        cout << "내림차순 정렬후 vector v 함수포인터 사용 출력" << endl;
        sort(p,p+10,sCompare);

        cout << "내림차순 정렬후 class p 함수포인터 사용 출력" << endl;
        sprint(p);

}

int print(int *arr)
{
        for(int i=0;i<10;i++){
            cout << arr[i] << " ";
        }
}
void vprint(vector<int> v)
{
        for(int i=0;i<10;i++){
            cout << v[i] << " ";
        }
}
void sprint(struct Pos *p)
{
        for(int i=0;i<10;i++){
            cout << p[i].x << " " << p[i].y << endl;
        }
}
