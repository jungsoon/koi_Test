#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    char str[100001];
    int answer=0, cnt=0, new_cnt=0;
    cin>>str;
    int n=strlen(str);

    //cout << n << endl;

    for(int i=0;i<n;i++){

        if(str[i]=='(') cnt++;
        else cnt--;

        if(str[i-1]=='(' && str[i]=='(') new_cnt++;
        else if(str[i-1]=='(' && str[i]==')'){
            answer += cnt + new_cnt;
            new_cnt=0;
        }
    }
    cout << answer << endl;

}
