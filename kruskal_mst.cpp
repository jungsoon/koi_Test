#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> check;

class Edge{
public:
    int node[2];
    int vertex;
    Edge(int a, int b, int vertex){
        this->node[0]=a;
        this->node[1]=b;
        this->vertex=vertex;
    }
    //간선을 오름차순으로 정렬할 때 기준을 vertex로 정해줍니다.
    bool operator<(Edge &edge){         // 연산자 중복(overloading)
        return this->vertex < edge.vertex;
    }
};

int Find(int node){               //노드를 찾아서 연결
    if(check[node]==node) return node;
    return Find(check[node]);
}

void Union(int node1, int node2)    //Union find - 두 노드를 작은 값을 기준으로 연결
{
    node1=Find(node1);
    node2=Find(node2);

    if(node1<node2) check[node2]=node1;
    else check[node1]=node2;
}
bool isCycle(int node1, int node2){    //사이클인지 판별하는 함수
    node1 = Find(node1);
    node2 = Find(node2);
    if(node1 == node2) return true;
    else return false;
}

int main()
{
    vector<Edge> v;
    int n;
    int n1, n2, value;
    cin >> n;

    check.resize(n+1,0);

    for(int i=0;i<n;i++){
        cin >> n1 >> n2 >> value;
        v.push_back(Edge(n1,n2,value));
    }

    //간선을 오름차순으로 정렬
    sort(v.begin(), v.end());

    //각 노드는 자기자신이 부모로 초기화
    for(int i=1;i<=7;i++){
        check[i]=i;
    }
    cout << "[ 크루스칼 알고리즘을 이용한 최소 신장 트리(MST) ]\n";
    cout << "node1 | node2 | 가중치\n";
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(!isCycle(v[i].node[0], v[i].node[1])){
            cout << "*" << v[i].node[0] << "    |   " << v[i].node[1] << "   |   " << v[i].vertex << endl;
            sum += v[i].vertex;
            Union(v[i].node[0], v[i].node[1]);
        }
    }
    cout << "비용의 합계 : " << sum << "\n";

    return 0;
}
