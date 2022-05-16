#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Object{
    int weight;
    double value;
    double unit_value;
};

bool compare(Object x, Object y)
{
    return x.unit_value > y.unit_value;
}

int main()
{
    Object arr[]={{1,10,0},{2,7,0},{5,15,0},{9,10,0},{2,12,0},{3,11,0},{4,5,0}};
    int w,total;
    cin >> w;

    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        arr[i].unit_value=arr[i].value / arr[i].weight;
    }

    sort(arr,arr+n,compare);
    int sum_w=0,result_w=0;
    double sum_v=0, result_v=0;
    for(int i=0;i<n;i++){
        sum_w += arr[i].weight;
        sum_v += arr[i].value;
        cout << sum_w << " " << sum_v <<"\n";
        if(w<=sum_w){
            if(sum_w-w > 0){
                sum_w -= arr[i].weight;
                sum_v -= arr[i].value;
                result_w = sum_w+(w - sum_w);
                result_v = sum_v+(w - sum_w)*arr[i].unit_value;
                //cout << result_v << " " << result_w << "\n";
            }
            else{
                result_v=sum_v;
                result_w=sum_w;
            }
            break;
        }
    }
    cout << result_w << " " << result_v << "\n";

    return 0;
}
