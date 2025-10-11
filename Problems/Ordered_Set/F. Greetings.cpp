#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define all(x) x.begin(),x.end()
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#define dbgA(...)
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>>
using iset = tree<T, null_type, Cmp, rb_tree_tag,
          tree_order_statistics_node_update, allocator<T>>;

void solve()
{
    int n ; cin >> n ; 
    ll cnt = 0;
    vector<pair<int,int>> se(n) ; 
    iset<int> r;
    for ( int i = 0 ; i < n ; ++i ) 
    {
        int s , e ; cin >> s >> e ; 
        se[i] = {s,e} ; 
        r.insert(e);
    }
    sort(all(se));
    for ( auto & [s,e] : se ) 
    {
        auto it = r.order_of_key(e);
        cnt += it ; 
        r.erase(r.find(e));
    }
    cout << cnt << endl ; 
}  
int32_t main() 
{
    cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif   
    int t = 1 ; 
    cin >> t ; 
    while( t-- ) solve() ; 
    return 0;
}