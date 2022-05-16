// Greedy Algorithm

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> v1;
vector <int> v2;
vector <int> box;
vector <vector<int>> V;

int main()
{
    int n,c,m;
    cin >> n >> c;
    cin >> m;

    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v1.push_back(a);
        v2.push_back(b);
        box.push_back(c);
    }

    V.push_back(v1);
    V.push_back(v2);
    V.push_back(box);

    for(int i=0;i<V.size();i++){
        for(int j=0;j<V[i].size();j++){
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


}
