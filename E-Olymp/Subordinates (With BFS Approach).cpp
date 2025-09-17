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
vector<int> g[N], res(N, 0), vis(N);

void solve(){
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        g[x].pb(i);
    }

    vector<int> path;
    queue<int> q;
    vis[1]=true;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        path.pb(node);
        for(int nx: g[node]){
            q.push(nx);
        }
    }

    vector<int> res(n+1, 1);
    for(int i=n-1; i>=0; i--){
        int node = path[i];
        for(int nx: g[node]){
            res[node]+=res[nx];
        }
    }

    for(int i=1; i<=n; i++){
        cout<<res[i]-1<<" ";
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