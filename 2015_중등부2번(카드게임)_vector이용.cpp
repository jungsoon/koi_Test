#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
int N;
vector <int> A;
vector <int> B;
vector <vector <int> > D;

int solution(int i,int j)
{
    if(i>=N || j>=N) return 0;

    if(D[i][j] != -1) return D[i][j];

    int ret=0;

    ret = max(ret,solution(i+1, j));
    cout << "*" << i << j <<endl;
    ret = max(ret,solution(i+1, j+1));

    if(A[i]>B[j]){
        ret=max(ret,B[j]+solution(i,j+1));
    }
    cout << "#"<<endl;
    D[i][j]=ret;
    return ret;
}
int main()
{
    cin >> N;

    for(int i=0;i<N;i++){
        int ball;
        scanf("%d", &ball);
        A.push_back(ball);
    }
    for(int i=0;i<N;i++){
        int ball;
        scanf("%d", &ball);
        B.push_back(ball);
    }

    D=vector<vector<int >> (N,vector<int> (N,-1));           // 2차원 vector N크기 , -1로 초기화

    printf("%d\n",solution(0,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }





}
