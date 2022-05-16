#include <iostream>
#include <vector>
using namespace std;

struct resort {
    int day;
    int cost;
    int coupon;
};

int main()
{
    int n, m;
    resort re[3]={
        {1 , 10000, 0},
        {3 , 25000, 1},
        {5 , 37000, 2}};

    cin >> n >> m;

    vector<int> cant_day(m);

    for(int i=0;i<m;i++){
        cin >> cant_day[i];
    }




}
