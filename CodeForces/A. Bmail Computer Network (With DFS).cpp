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

ll n;
vector<ll> g[N];
vector<ll> path;
bool dfs(ll u, ll p, ll target, vector<ll> &path){
    path.push_back(u);
    if(u == target){
        return true;
    }
    for(ll nx: g[u]){
        if(nx == p) continue;
        if(dfs(nx, u, target, path)){
            return true;
        }
    }
    path.pop_back();
    return false;
}
/*
        1
      /   \
     2     3
   / | \     \
  4  5  7     6
     |
     8

*/
void solve(){
    cin>>n;
    for(ll i=2; i<=n; i++){
        ll x;
        cin>>x;
        g[i].pb(x);
        g[x].pb(i);
    }
    dfs(1, -1, n, path);
    for(ll i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
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