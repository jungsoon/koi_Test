#include <iostream>
using namespace std;

void print(int n)
{
    if(n <= 0) return;
    print(n-1);
    cout << "* ";
}
void solution(int n)
{

    if(n<=0) return;
    solution(n-1);
    print(n);
    cout << endl;
    return;

}


int main()
{
    int n;
    cin >> n;
    solution(n);
}
