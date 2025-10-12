
#include <bits/stdc++.h>
using namespace std;
#define int long long  
#define all(x) x.begin(),x.end()
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#define dbgA(...)
#endif

void solve()
{
    int n , m ; cin >> n >> m ;
    vector<pair<int,int>> segments(m);
    for ( auto & [f,s] : segments )
    {
        int l , r ; cin >> l >> r ; 
        l--;r--;
        f = l, s = r ; 
    } 
    int q ; cin >> q ;
    vector<int> queries(q); 
    for ( auto & e : queries )
    {
        int x ; cin >> x ; 
        x--; e = x ; 
    }
    int l = 0 , r = q , ans = -1 ;
    while ( l <= r ) 
    {
        int m = l + ( r - l ) / 2 ; 
        vector<int> a(n); 
        for ( int i = 0 ; i < m ; ++i ) a[queries[i]] = 1 ; 
        vector<int> prefix(n);
        for ( int i = 0 ; i < n ; ++i ) prefix[i] = (a[i] == 1) + ( i ? prefix[i-1] : 0 ) ; 
        bool done = false ; 
        for ( auto & [sl,sr] : segments ) 
        {
            int count_ones = prefix[sr] - ( sl ? prefix[sl-1] : 0 ) ; 
            int count_zeros = ( sr - sl + 1 ) - count_ones ; 
            if ( count_zeros < count_ones ) done = true ;
        }
        if ( done ) 
        {
            ans = m ; 
            r = m - 1 ; 
        }
        else l = m + 1 ; 
    }
    cout << ans << endl ; 
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