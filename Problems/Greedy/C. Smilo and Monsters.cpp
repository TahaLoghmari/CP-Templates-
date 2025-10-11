
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

/*
- it's better to use x on bigger targets because you get the same value by using attack 2 as less times as possible
and also use x to kill a horde with exactly x monsters
*/

void solve()
{
    int n ; cin >> n ; 
    deque<int> a(n); for ( auto & e : a ) cin >> e ; 
    sort(all(a));
    int x = 0 , cnt = 0 ; 
    while ( !a.empty() ) 
    {
        if ( a.size() == 1 ) 
        {
            if ( a[0] == 1 ) 
            {
                cnt++;
                break;
            }
            int value = a[0]+x;
            cnt += abs(x - (value / 2)) + ( value & 1 ? 2 : 1 ) ;
            break ; 
        }
        int needed_value = min(a.front(),a.back()-x);
        x += max(needed_value,(int)0) ; 
        cnt += max(needed_value,(int)0); 
        if ( needed_value == a.front() ) a.pop_front();
        else a.front() -= needed_value ;
        if ( x == a.back() )
        {
            cnt++;
            a.pop_back();
            x = 0 ; 
        }
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