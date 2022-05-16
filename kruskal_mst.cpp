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
    //������ ������������ ������ �� ������ vertex�� �����ݴϴ�.
    bool operator<(Edge &edge){         // ������ �ߺ�(overloading)
        return this->vertex < edge.vertex;
    }
};

int Find(int node){               //��带 ã�Ƽ� ����
    if(check[node]==node) return node;
    return Find(check[node]);
}

void Union(int node1, int node2)    //Union find - �� ��带 ���� ���� �������� ����
{
    node1=Find(node1);
    node2=Find(node2);

    if(node1<node2) check[node2]=node1;
    else check[node1]=node2;
}
bool isCycle(int node1, int node2){    //����Ŭ���� �Ǻ��ϴ� �Լ�
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

    //������ ������������ ����
    sort(v.begin(), v.end());

    //�� ���� �ڱ��ڽ��� �θ�� �ʱ�ȭ
    for(int i=1;i<=7;i++){
        check[i]=i;
    }
    cout << "[ ũ�罺Į �˰����� �̿��� �ּ� ���� Ʈ��(MST) ]\n";
    cout << "node1 | node2 | ����ġ\n";
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(!isCycle(v[i].node[0], v[i].node[1])){
            cout << "*" << v[i].node[0] << "    |   " << v[i].node[1] << "   |   " << v[i].vertex << endl;
            sum += v[i].vertex;
            Union(v[i].node[0], v[i].node[1]);
        }
    }
    cout << "����� �հ� : " << sum << "\n";

    return 0;
}
