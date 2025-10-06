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
#define fs first
#define sc second
#define vi vector<int>
#define pi pair<int, int>
#define TC int T;cin>>T;while(T--)
#define loop(j,n,a) for(int j=n;j<a;j++)
#define loop1(j,n,a) for(int j=n;j<=a;j++)
#define sz(x) (sizeof(x)/sizeof(x[0]))
#define INF 1000000000
#define MOD 1000000000
int const N = 200005;
 
int n;
vector<int> g[N];
int dp[N][2];
int dfs(int u, int p){
    for(int nx: g[u]){
        if(nx == p) continue;
        dfs(nx, u);
        dp[u][0]+=max(dp[nx][1], dp[nx][0]);
    }
 
    for(int nx: g[u]){
        if(nx == p) continue;
        dp[u][1]=max(dp[u][1], dp[u][0] - max(dp[nx][1],dp[nx][0]) + dp[nx][0] + 1);
    }
    return max(dp[u][0], dp[u][1]);
}
void solve(){
    cin>>n;
    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }    
    int mx = dfs(1, -1);
    cout<<mx;
}
 
int main(){
    optimize();
    fraction()
    int t=1;
    while(t--){
        solve();    
    }
}