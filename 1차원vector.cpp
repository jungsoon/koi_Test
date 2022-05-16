#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void print()
{
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "원소 출력 => ";
    print();
    cout<<endl;
    cout << "v.empty()=> "<< v.empty() << endl;

    vector<int>::iterator it;
    it=v.begin();               //시작 위치를 it에 지정
    it=v.erase(it);
    cout << "v.erase 후 => ";
    print();

    v.insert(it,5);             //it 위치에 5를 삽입하라.
    cout << "v.insert 후 => ";
    print();

    return 0;
}
