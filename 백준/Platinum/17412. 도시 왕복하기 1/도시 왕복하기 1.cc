#include <bits/stdc++.h>
using namespace std;

int cap[401][401], flow[401][401], parent[401];
int n, p;

int maxflow(){
	int ret = 0;
	while(true){
		memset(parent, 0, sizeof(parent));
		queue<int> q;
		q.push(1);
		parent[1] = 1;
		
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v=1; v<=n; v++){
				if(parent[v]==0){
					if(cap[u][v]-flow[u][v] > 0){
						parent[v] = u;
						q.push(v);
					}
				}
			}
		}
		if(parent[2]==0) break;
		int f = 987654321;
		for(int i=2; i!=1; i=parent[i])
			f = min(f, cap[parent[i]][i]-flow[parent[i]][i]);
		for(int i=2; i!=1; i=parent[i]){
			flow[parent[i]][i] += f;
			flow[i][parent[i]] -= f;
		}
		ret++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	for(int i=0; i<p; i++){
		int u, v; cin >> u >> v;
		cap[u][v] = 1;
	}
	cout << maxflow() << '\n';
}
