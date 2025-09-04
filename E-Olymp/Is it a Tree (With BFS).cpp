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

int const N = 10e6+5;
vector<pair<int,int>> adj[N];
vector<bool> vis(N);
int n, cn;

void solve(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            if(x){
                adj[i].pb({j, i});
            }
            if(i<j && x){
                cn++;
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout<<i<<" : ";
    //     for(auto nx: adj[i]){
    //         cout<<"{"<<nx.first<<" , "<<nx.second<<"}";
    //     }cout<<endl;
    // }return;
    // cout<<cn<<endl;
    queue<pair<int,int>> q;
    q.push({1, -1});
    vis[q.front().F]=true;
    bool hasCycle=false, noConnection=false;
    while(!q.empty()){
        int node = q.front().F;
        int parent = q.front().S;
        q.pop();
        for(auto nx: adj[node]){
            if(!vis[nx.F]){
                vis[nx.F]=true;
                q.push({nx.F, nx.S});
            }
            else if(nx.F != parent){
                hasCycle=true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            noConnection=true;
        }
    }
    if(hasCycle || n-1!=cn || noConnection){
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