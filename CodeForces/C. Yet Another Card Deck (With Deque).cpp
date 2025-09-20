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
const int N = 300005; 

int n, q;
vector<int> g(N), v(N);
void solve(){
    cin>>n>>q;
    deque<int> dq;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        dq.push_back(x);
    }
    for(int j=1; j<=q; j++){
        int x;
        cin>>x;
        v[j] = x;
    }
    for(int i=1; i<=q; i++){
        int ans = 1;
        for(auto it=dq.begin(); it!=dq.end(); it++){
            if(*it == v[i]){
                int val = *it;
                dq.erase(it);
                dq.push_front(val);
                break;
            }
            ans++;
        }
        cout<<ans<<" ";
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