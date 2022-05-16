/*
input : 5 3 , output:-1
input : 6 3 , output:2
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main()
{
    int n,k;
    cin >> n >> k;
    v.resize(k+1,0);

    if(k*(k+1)/2 > n)
    {
        cout << -1 << "\n";
        return 0;
    }
    int cnt=1,sum=0;

    for(int i=0;i<k;i++)
    {
        v[i]=cnt;
        sum += cnt;
        cnt++;
    }

    //cout << "*" << sum << endl;
    if(sum == n)
    {
        cout << v[k-1] - v[0] << "\n";
    }
    else{
        while(n-sum >= 0)
        {
            //cout << n-sum << " " << sum << endl;

            for(int i=k-1;i>=0;i--){

                    v[i]++;
                    sum++;
                    if(n == sum ) break;
            }

        }
        cout << v[k-1] - v[0] << "\n";
    }

    return 0;

}
