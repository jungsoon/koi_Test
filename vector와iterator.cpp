#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5,0);     // 5개의 원소에 0으로 초기화

    for(int i=0;i<5;i++){
        v[i] = i+1;
    }

    vector<int>::iterator it;

    cout << "변경전 => ";
    for(it=v.begin();it != v.end();it++){
        cout << *it << " ";
        *it = (*it) * 2;
    }

    cout << "\n변경후 => ";
    for(it=v.begin();it != v.end();it++){
        cout << *it << " ";
    }

    return 0;
}
