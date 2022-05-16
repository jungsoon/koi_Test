/*
O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> arr, DT;
int main()
{
    int n;

    cin >> n;
    arr.resize(n+1,0);
    DT.resize(n+1,0);

    for(int i=1;i<=n;i++){
       cin >> arr[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if() {
                DT[i]=DT[i]+1;
            }
            else{

            }
        }
    }

    for(int i=0;i<=n;i++){
        cout << DT[i] << " ";
    }

    cout << DT[n] << "\n";

    return 0;
}
