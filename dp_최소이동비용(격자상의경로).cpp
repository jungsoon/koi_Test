#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(3, vector<int> (4,0));

int arr[3][4] = {
    {1,3,5,8},
    {4,2,1,7},
    {4,3,2,3}
};
int Min(int x, int y) { return (x<y) ? x: y; }

int solution(int x, int y)
{

    if(v[x][y]) return v[x][y];

    if(x==0 && y==0)
        return v[x][y] = arr[0][0];
    else if(x==0)
        return v[x][y] = arr[0][y] + solution(x, y-1);
    else if(y==0)
        return v[x][y] = arr[x][0] + solution(x-1,y);
    else{
        int row=solution(x-1,y);
        int col=solution(x,y-1);

        v[x][y] = Min(row,col) + arr[x][y];
    }
    return v[x][y];

}

int main()
{
    cout << solution(2,3) << endl;
}
