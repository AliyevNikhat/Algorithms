#include <bits/stdc++.h>
using namespace std;

// inline char gc() { return getchar_unlocked(); } For Linux 

#define ll long long int
#define ull unsigned long long
#define ld long double
#define S second
#define F first
#define pb push_back
#define em emplace_back
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
int const N = 200001;

vector<int> g[N];
int sub[N];
void dfs(int u){
    for(int nx: g[u]){
        dfs(nx);
        sub[u] += sub[nx]+1;
    }
}

//        (1)
//       /   \
//     (2)   (3)
//      |      \
//     (5)     (4)

void solve() {
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int x; cin>>x;
        g[x].pb(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cout<<sub[i]<<" ";
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