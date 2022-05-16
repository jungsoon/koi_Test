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
bool compare(int x, int y)      // �Ϲ� int�� ���� �������� ������ ���� �Լ�������
{
        return x > y;
}

bool sCompare(Pos &p, Pos &q)   // struct class �������� ������ ���� �Լ�������
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

        cout << "arr �迭 ���" << endl;
        print(arr);
        cout << "\n\n";

        cout << "vector v ���" << endl;
        vprint(v);
        cout << "\n\n";

        cout << "vector v ���" << endl;
        sprint(p);
        cout << "\n\n";

        // arr �������� ����
        sort(arr,arr+10);


        // vector v �������� ����
        sort(v.begin(), v.end());

        cout << "�������� ������ arr �迭 ���" << endl;
        print(arr);
        cout << "\n\n";

        cout << "�������� ������ vector v ���" << endl;
        vprint(v);
        cout << "\n\n";

        // arr �������� ����
        sort(arr,arr+10, compare);


        // vector v �������� ����
        sort(v.begin(), v.end(), compare);

        cout << "�������� ������ arr �迭 ���" << endl;
        print(arr);
        cout << "\n\n";

        cout << "�������� ������ vector v �Լ������� ��� ���" << endl;
        vprint(v);
        cout << "\n\n";

        sort(v.begin(), v.end(), greater<int>());
        cout << "�������� ������ vector v greater�Լ� ��� ���" << endl;
        vprint(v);


        cout << "�������� ������ vector v �Լ������� ��� ���" << endl;
        sort(p,p+10,sCompare);

        cout << "�������� ������ class p �Լ������� ��� ���" << endl;
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
