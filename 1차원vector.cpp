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

    cout << "���� ��� => ";
    print();
    cout<<endl;
    cout << "v.empty()=> "<< v.empty() << endl;

    vector<int>::iterator it;
    it=v.begin();               //���� ��ġ�� it�� ����
    it=v.erase(it);
    cout << "v.erase �� => ";
    print();

    v.insert(it,5);             //it ��ġ�� 5�� �����϶�.
    cout << "v.insert �� => ";
    print();

    return 0;
}
