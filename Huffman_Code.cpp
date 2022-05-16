#include <iostream>
#include <vector>
using namespace std;

struct Tree{
    char code;
    char b_code[21];
};
vector <Tree> v;
char tree[255];
int main()
{
    int n,idx=1;

    char binary[255];
    cin >> n;

    v.resize(n+1);
    for(int i=0;i<n;i++){
        cin >> v[i].code >> v[i].b_code;
        int j=0;
        idx=1;
        while(v[i].b_code[j] != '\0'){
            if(v[i].b_code[j]=='0') idx = idx*2;
            else idx = idx*2+1;
            j++;
        }
        tree[idx]=v[i].code;

    }
    cin >> binary;
    idx=1;
    int i=0;
    while(binary[i] != '\0'){
        if(binary[i]=='0') idx = idx*2;
        else if(binary[i]=='1') idx = idx*2+1;

        //cout << idx << " " << tree[idx] << endl;
        if(tree[idx]>='A' && tree[idx]<='Z') {
            cout << tree[idx];
            idx=1;
        }
        i++;
    }

}

