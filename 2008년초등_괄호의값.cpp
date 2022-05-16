/*
2008년 지역본선 - 괄호의 값
입력 : (()[[]])([])
2*(2+(3*3))+(2*3) = 28
출력 : 28
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
