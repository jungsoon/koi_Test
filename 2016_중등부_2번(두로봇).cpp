#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;       // p의 각 항목이 int형이다.
vector<p> g[101010];            // p를 가진 g 벡터가 101010개이다.

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
	int n, a, b; cin >> n >> a >> b;        // 방의 개수n, a로봇 위치, b로봇 위치
	for(int i=0; i<n-1; i++){
		int s, e, x; cin >> s >> e >> x;        // 노드와 노드를 연결, 길이는 x이다.
		g[s].push_back({e, x});             // g벡터에 마지막과 길이를 시작에 넣는다.
		g[e].push_back({s, x});             // g벡터에 마지막과 길이를 마지막에 넣는다.
	}
	if(a == b){                             // a와 b가 같다는 것은 0이다.
		cout << "0"; return 0;
	}
	dfs(a, 0, 0);                           //dfs 호출
	cout << dist[b] - maxi[b];              // b로봇 위치의
}
