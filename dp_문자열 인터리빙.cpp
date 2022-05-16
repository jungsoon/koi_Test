#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> DT;
string a,b,c;
int n1,n2,n3;

bool solution(char *a, char *b, char *c)
{
    cout << *a << *b << *c << endl;
    if(!(*a) && !(*b) && !(*c)) return true;
    if(strlen(a) + strlen(b) != strlen(c)) return false;

    bool check=false;
    bool check2=false;

    if(*a == *c){
        check=solution(a+1,b,c+1);
    }
    if(*b == *c){
        check2=solution(a,b+1,c+1);
    }
    return check==true || check2==true;

}

void dp_solution()
{
    DT[0][0]=1;

    for(int i=1;i<=n1;i++){
        if(a[i-1] != c[i-1])
            DT[i][0] = 0;
        else
            DT[i][0] = DT[i-1][0];
    }

    for(int i=1;i<=n2;i++){
        if(b[i-1] != c[i-1])
            DT[0][i] = 0;
        else
            DT[0][i] = DT[0][i-1];
    }

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){

            if(a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]){   // a=b=c

                if(DT[i-1][j]==1 || DT[i][j-1]==1){
                        DT[i][j]=1;
                }
                else {
                        DT[i][j]=0;
                }
            }
            else if(a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1]){
                DT[i][j]=DT[i-1][j];
            }
            else if(a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]){
                DT[i][j]=DT[i][j-1];
            }
            else{
                DT[i][j]=0;
            }
        }
    }

    return;
}

int main()
{

    cin >> a >> b >> c;
    n1=a.size();
    n2=b.size();
    n3=c.size();

    if(n1+n2!=n3) {
        cout << "false";
        return 0;
    }

    DT.resize(n1+1, vector<int> (n2+1,0));
    /*
    if(solution(&a[0], &b[0], &c[0])==1)
        cout << "true";
    else
        cout << "false";
    */
    dp_solution();

    if(DT[n1][n2]) cout << "true" << "\n";
    else cout << "false" << "\n";

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            cout << DT[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
