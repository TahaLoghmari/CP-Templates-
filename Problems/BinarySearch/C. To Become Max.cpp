
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
    int n , k , ans = -1 ; cin >> n >> k ;
    vector<int> a(n); for ( auto & e : a ) cin >> e ; 
    int l = 0 , r = 1e10 ; 
    while ( l <= r ) 
    {
        int m = l + ( r - l ) / 2 ; 
        int done = 0 ; 
        for ( int i = 0 ; i < n - 1 ; ++i ) 
        {
            int needed = 0 , track = m , cant = 0 ;
            for ( int j = i ; j < n ; ++j ) 
            {
                if ( a[j] >= track ) break ; 
                if ( j == n-1 ) cant = true ;
                needed += track - a[j] ; 
                track--;
            }
            if ( needed <= k && !cant ) done = 1 ; 
        }
        if ( done ) 
        {
            ans = m ;
            l = m + 1 ; 
        }
        else r = m - 1 ; 
    }
    cout << max(*max_element(all(a)),ans) << endl ; 
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