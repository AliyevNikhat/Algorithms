#include <bits/stdc++.h>
using namespace std;

// inline char gc() { return getchar_unlocked(); } For Linux 

#define ll long long int
#define ull unsigned long long
#define ld long double
#define S second
#define F first
#define pb push_back
#define map unordered_map
#define unset unordered_set
#define pr priority_queue // Dijkstra Algorithm
#define all(a) a.begin(), a.end()
#define intmin INT32_MIN
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define MX 100000
#define vi vector<int>
#define pi pair<int, int>
#define TC int T;cin>>T;while(T--)
#define loop(j,n,a) for(int j=n;j<a;j++)
#define loop1(j,n,a) for(int j=n;j<=a;j++)
#define sz(x) (sizeof(x)/sizeof(x[0]))
#define INF 1000000000
#define MOD 1000000000
int const N = 200005;
/*
        1
      /   \
     2     3
   / | \     \
  4  5  7     6
     |
     8

*/
int n;
vector<int> g[N];
vector<int> ans;

void solve(){
    cin>>n;
    vector<int> vis(n+1, false);
    vector<int> path(n+1, 0);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        g[i].pb(x);
        g[x].pb(i);
    }
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int nx: g[node]){
            if(!vis[nx]){
                path[nx]=node;
                vis[nx]=true;
                q.push(nx);
            }
        }
    }
    for(int i=path[n]; i!=0; i=path[i]){
        ans.push_back(i);
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }cout<<n;
}

int main(){
    optimize();
    fraction()
    int t=1;
    while(t--){
        solve();    
    }
}





/*
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> adj[105]; // kiçik n üçün
bool visited[105];
int path_length;

bool dfs(int u, int target, int acc) {
    visited[u] = true;
    if (u == target) {
        path_length = acc;
        return true;
    }
    for (auto [v, w] : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, target, acc + w)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    long long total = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = u+1; v <= n; v++) {
            memset(visited, 0, sizeof(visited));
            dfs(u, v, 0);
            total += path_length;
        }
    }
    cout << total << "\n";
}
*/