#include <iostream>
using namespace std;

int GCD(int num2, int num1)
{
    if(num2==0) {
        cout << "정답 : ";
        return num1;
    }

    cout << num1 << " " << num2 << "\n";

    return GCD(num1%num2,num2);
}

int main()
{
    int n,m;
    cout << "두수를 입력하세요 : ";
    cin >> n >> m;
    cout << "[풀이과정]" <<endl;
    cout << GCD(n,m) << endl;
}
