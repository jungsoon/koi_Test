#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;       // p�� �� �׸��� int���̴�.
vector<p> g[101010];            // p�� ���� g ���Ͱ� 101010���̴�.

int dist[101010];
int maxi[101010];
int chk[101010];

void dfs(int v, int d, int m){
	dist[v] = d;
	maxi[v] = m;
	chk[v] = 1;
	cout << d << " " << m << " " << v << endl;
	for(auto i : g[v]){
		if(!chk[i.first]) dfs(i.first, d + i.second, max(m, i.second));
	}
}

int main(){
	int n, a, b; cin >> n >> a >> b;        // ���� ����n, a�κ� ��ġ, b�κ� ��ġ
	for(int i=0; i<n-1; i++){
		int s, e, x; cin >> s >> e >> x;        // ���� ��带 ����, ���̴� x�̴�.
		g[s].push_back({e, x});             // g���Ϳ� �������� ���̸� ���ۿ� �ִ´�.
		g[e].push_back({s, x});             // g���Ϳ� �������� ���̸� �������� �ִ´�.
	}
	if(a == b){                             // a�� b�� ���ٴ� ���� 0�̴�.
		cout << "0"; return 0;
	}
	dfs(a, 0, 0);                           //dfs ȣ��
	cout << dist[b] - maxi[b];              // b�κ� ��ġ��
}
