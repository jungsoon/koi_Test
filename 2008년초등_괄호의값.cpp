/*
2008�� �������� - ��ȣ�� ��
�Է� : (()[[]])([])
2*(2+(3*3))+(2*3) = 28
��� : 28
   */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
stack<char> st;
int main()
{

    cin >> s;
    cout << s.size() << endl;

    for(int i=0;i<s.size();i++){
        cout << s[i] << " ";
    }

    return 0;
}
