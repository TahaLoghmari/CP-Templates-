
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

// if you have ai = bi or ai = ai+1 or bi = bi+1 or ai = ai+2 or bi = bi+2, for all j from 0 - i can 
// become equal 
// for all i ai can become any aj or b[j] where j > i except for a[i+1] 
// ai shouldn't necessarily be current bi, what if it becomes another bi 

void solve()
{
    int n ; cin >> n ; 
    vector<int> a(n), b(n); 
    for ( auto & e : a ) cin >> e; for ( auto & e : b ) cin >> e ; 
    int max_ = 0 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( i != n-1 ) {
            if ( a[i] == a[i+1] || b[i] == b[i+1] ) max_ = max(i+1,max_);
        }
        if ( i < n-2 ) 
        {
            if ( a[i] == a[i+2] || b[i] == b[i+2] ) max_ = max(i+1,max_);
        }
        if ( a[i] == b[i] ) max_ = max(i+1,max_);
    }
    multiset<int> track ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        track.insert(a[i]);
        track.insert(b[i]);
    }
    for ( int i = 0 ; i < n-1 ; ++i ) 
    {
        // now in a
        track.erase(track.find(b[i]));
        track.erase(track.find(a[i+1]));
        auto it = track.find(b[i]);
        if ( it != track.end() ) max_ = max(i+1,max_);
        track.insert(a[i+1]);
        track.insert(b[i]);
        // now in b 
        track.erase(track.find(a[i]));
        track.erase(track.find(b[i+1]));
        it = track.find(a[i]);
        if ( it != track.end() ) max_ = max(i+1,max_);
        track.insert(b[i+1]);
        track.insert(a[i]);

        track.erase(track.find(a[i]));
        track.erase(track.find(b[i]));
    }

    cout << max_ << endl ; 
    
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