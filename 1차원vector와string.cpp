#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v;
    string name;

    cout << "�̸� 5���� �Է��ϼ���"<<endl;
    for(int i=0;i<5;i++){
        cout << i+1 << ">> ";
        cin>>name;
        v.push_back(name);
    }

    sort(v.begin(), v.end());

    cout << "== sort �� ��� ==\n";
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }

}


