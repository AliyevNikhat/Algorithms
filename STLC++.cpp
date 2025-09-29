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
const int N = 200005;

void solve() {
    // ---------------------- STL (C++) ----------------------

    // Pairs
    pair<int,int> p = {1, 3};
    cout << p.first << " " << p.second << endl; // F -> first, S -> second

    // Nested pair example
    // pair<int, pair<int,int>> p2 = {1, {3, 4}};
    // cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int,int> g[] = {{1, 2}, {2, 6}, {1, 4}};
    cout << g[0].first << endl; // 1
    cout << g[2].second << endl; // 4

    // --------------------------------------------------------------
    // Vector
    vector<int> v;
    v.push_back(1);      // pb -> push_back
    v.emplace_back(2);   // em -> emplace_back (faster in some cases)

    // Vector with pair
    vector<pair<int,int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v3(5, 7);      // size 5, every element 7 → [7,7,7,7,7]
    vector<int> v1(5);         // size 5 → [0,0,0,0,0]
    vector<int> v4(5, 20);     // size 5, every element 20 → [20,20,20,20,20]
    vector<int> v2(v4);        // copy of v4 → [20,20,20,20,20]

    // --------------------------------------------------------------
    // Vector using iterators
    vector<int>::iterator it = v.begin(); // points to the first element in v
    it++;
    cout << *it << " ";  // prints the second element

    it += 2;             // move iterator forward by 2
    cout << *it << " ";  // prints the fourth element

    // Normal iterator to the end (past-the-last element)
    it = v.end();

    // Reverse iterator
    vector<int>::reverse_iterator rit = v.rend(); // points before the first element

    cout << v[0] << " " << v.at(0) << endl; // both access the first element

    // Iterating using normal iterator
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterating using auto with iterator
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Range-based for loop (simplest)
    for(auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Erasing elements from vector
    // Example: v = {10, 20, 12, 35}
    v.erase(v.begin() + 1); // removes the second element (20)

    // Example: v = {10, 20, 12, 35, 28}
    v.erase(v.begin() + 2, v.begin() + 4); // removes 3rd and 4th elements, remaining {10, 20, 28}

    // --------------------------------------------------------------
}

int main(){
    optimize();
    fraction()
    int t=1;
    while(t--){
        solve();    
    }
}