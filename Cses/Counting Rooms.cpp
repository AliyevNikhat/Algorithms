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

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void BFS() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> adj(n+1, vector<char>(m+1));
    vector<vector<bool>> vis(n+1, vector<bool>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>adj[i][j];
        }
    }
    int cn=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<adj[i].size(); j++){
            if(!vis[i][j] && adj[i][j] == '.'){
                queue<pair<int,int>> q;
                vis[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    auto[xi,yj] = q.front();
                    q.pop();
                    for(int x=0; x<4; x++){
                        int ni = xi + dx[x];
                        int nj = yj + dy[x];
                        if(ni>=1 && ni<=n && nj>=1 && nj<=m && adj[ni][nj]=='.' && !vis[ni][nj]){
                            vis[ni][nj]=true;
                            q.push({ni,nj});
                        }
                    }
                }
                cn++;
            }
        }
    }
    cout<<cn<<endl;
}
 
// int dx[]={1,-1,0,0};
// int dy[]={0,0,1,-1};
void dfs(int n, int m, int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &adj){
    vis[i][j]=true;
 
    for(int x=0; x<4; x++){
        int ni = i + dx[x];
        int nj = j + dy[x];
        if(ni>=1 && ni<=n && nj>=1 && nj<=m && !vis[ni][nj] && adj[ni][nj] == '.'){
            dfs(n,m,ni,nj,vis,adj);
        }
    }
}
 
void solveForDfs(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> adj(n+1, vector<char>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>adj[i][j];
        }
    }
    int cn=0;
    vector<vector<bool>> vis(n+1, vector<bool>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!vis[i][j] && adj[i][j] == '.'){
                dfs(n,m,i,j,vis,adj);
                cn++;
            }
        }
    }
    cout<<cn<<endl;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout<<adj[i][j];
    //     }
    //     cout<<endl;
    // }
}
 
int main() {
    int t=1;
    while(t--){
        //BFS();
        solveForDfs();
    }
}