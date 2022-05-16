#include <iostream>
using namespace std;

int main()
{
    int room,a,b;
    int node, edge, len;
    cin >> room >> a >> b;
    int sum=0;
    for(int i=0;i<room-1;i++){
        cin >> node >> edge >> len;
        if(a<b-1){
            sum += len;
            a++;
        }
    }
    cout << sum << endl;
    return 0;

}
