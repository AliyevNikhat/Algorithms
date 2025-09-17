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

int n, mx_d=0, mx_n=0;
vector<int> g[N];
void dfs(int u, int p, int d){
    if(mx_d < d){
        mx_d=d;
        mx_n=u;
    }
    for(int nx: g[u]){
        if(nx == p){
            continue;
        }
        dfs(nx, u, d+1);
    }
}

void solve(){
    cin>>n;
    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, -1, 0);
    mx_d=0;
    dfs(mx_n, -1, 0);
    cout<<mx_d;
}

int main(){
    optimize();
    fraction()
    int t=1;
    while(t--){
        solve();    
    }
}