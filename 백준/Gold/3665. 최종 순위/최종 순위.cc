#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, n, m;
    cin >> tc;
    while(tc--){
        int order[501];
        int indegree[501];
        memset(indegree, 0, sizeof(indegree));

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> order[i+1];
        }
        bool adj[501][501];
        memset(adj, 0, sizeof(adj));
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                int a = order[i], b = order[j];
                adj[a][b] = true;
            }
        }

        cin >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            if(adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;
            }
            else{
                adj[b][a] = false;
                adj[a][b] = true;
            }
        }

        queue<int> q;
        queue<int> ans;
        bool impossible = false, ambiguous = false;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj[i][j]) indegree[j]++;
            }
        }

        for(int i=1; i<=n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        for(int i=0; i<n; i++){
            if(q.empty()){
                impossible = true;
                break;
            }
            if(q.size() > 1){
                ambiguous = true;
            }

            int a = q.front();
            q.pop();
            ans.push(a);

            for(int j=1; j<=n; j++){
                if(adj[a][j]){
                    if(--indegree[j] == 0){
                        q.push(j);
                    }
                }
            }
        }

        if(impossible){
            cout << "IMPOSSIBLE\n";
        }
        else if(ambiguous){
            cout << "?\n";
        }
        else{
            while(!ans.empty()){
                cout << ans.front() << ' ';
                ans.pop();
            }
            cout << '\n';
        }
    }
}