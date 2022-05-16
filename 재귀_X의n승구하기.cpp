#include <iostream>
using namespace std;

int power(int x, int n)
{
    if(n==1)
        return x;
    else if(n%2 == 0)
    {
        return power(x*x,n/2);
    }
    else{
        return x*power(x*x,(n-1)/2);
    }
}

int main()
{
    int base, exp;
    cin >> base >> exp;
    cout << power(base,exp) << endl;
}
