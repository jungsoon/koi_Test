#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5,0);     // 5���� ���ҿ� 0���� �ʱ�ȭ

    for(int i=0;i<5;i++){
        v[i] = i+1;
    }

    vector<int>::iterator it;

    cout << "������ => ";
    for(it=v.begin();it != v.end();it++){
        cout << *it << " ";
        *it = (*it) * 2;
    }

    cout << "\n������ => ";
    for(it=v.begin();it != v.end();it++){
        cout << *it << " ";
    }

    return 0;
}
