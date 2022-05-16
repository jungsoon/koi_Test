#include <iostream>
using namespace std;
int fibo(int n)
{
    int fibonacci=0;
    if(n==1)
        return 1;
    else if(n==0)
        return 0;
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main()
{
    int num;
    cin >> num;
    cout << fibo(num) << endl;
}
