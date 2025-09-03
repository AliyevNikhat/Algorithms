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

map<ll, ll> memo;
ll getDp(ll x){
    if(memo.count(x)) return memo[x];
    if(x==1) return memo[x]=1;
    if(x==2) return memo[x]=3;
    if(x==3) return memo[x]=4;
    return memo[x]=getDp(x/2)+x;
}

int const N = 1e6+5;
vector<int> adj[N], vis(N), dp(N, -1);
int n, cn=0;
bool dfs(int u, int parent){
    vis[u]=true;

    for(int nx: adj[u]){
        if(!vis[nx]){
            if(dfs(nx, u)) return true;
        }
        else if(nx != parent){
            return true;
        }
    }
    return false;
}
void solve(){
    cin>>n; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            if(x){
                adj[i].push_back(j);
            }
            if(i < j && x){
                cn++; //Edge Count
            }
        }
    }
    bool noConnect = false;
    bool hasCycle = dfs(1, -1);
    // cout<<hasCycle<<endl;
    // cout<<cn<<endl;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            noConnect=true;
        }
    }
    if(hasCycle || n-1 != cn || noConnect){
        cout<<"NO";
    }else{
        cout<<"YES";
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