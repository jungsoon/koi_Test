#include <iostream>
using namespace std;
void solution();

int cnt,n;
int main()
{
    cin >> n;

    solution();
    cout << cnt << endl;
    return 0;
}
void solution()
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                if(i+j+k == n && i+j > k )
                {
                    cnt++;
                }
            }
        }
    }
}
