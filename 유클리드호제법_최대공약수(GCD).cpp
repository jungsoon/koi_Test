#include <iostream>
using namespace std;

int GCD(int num2, int num1)
{
    if(num2==0) {
        cout << "���� : ";
        return num1;
    }

    cout << num1 << " " << num2 << "\n";

    return GCD(num1%num2,num2);
}

int main()
{
    int n,m;
    cout << "�μ��� �Է��ϼ��� : ";
    cin >> n >> m;
    cout << "[Ǯ�̰���]" <<endl;
    cout << GCD(n,m) << endl;
}
