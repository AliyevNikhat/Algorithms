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
int const N = 200000+5;

int n;
vector<int> g[N], res(N);

int BFS(int u){
    vector<bool> vis(n+1, false);
    vector<int> dist(n+1, 0);
    queue<int> q;
    q.push(u);
    vis[u]=true;
    int farthest = u;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int nx: g[node]){
            if(!vis[nx]){
                vis[nx]=true;
                dist[nx]=dist[node]+1;
                q.push(nx);
                res[nx]=max(res[nx], dist[nx]);
                if(dist[nx] > dist[farthest]){
                    farthest = nx;
                }
            }
        }
    }
    return farthest;
}

void solve(){
    cin>>n;
    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int curr = BFS(1);
    int nx = BFS(curr);
    BFS(nx);
    for(int i=1; i<=n; i++){
        cout<<res[i]<<" ";
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