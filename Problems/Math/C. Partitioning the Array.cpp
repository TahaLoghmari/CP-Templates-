
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
- we need to go over all divisors
- for determining m, we can just go over two subarrays and that's enough, cause if we couldn't find any m for those
two then there's no point for also checking the other subarrays.
- a % x = b % x => x | ( a - b ) so since we need every a[i] to be equal to a[i+k] we need m to be a divisor of 
abs(a[i]-a[i+k]) and for m to be valid for all indexes, we just take their gcd to assure that for every i m divides
abs(a[i]-a[i+j]), and since we can compute all divisors in sqrt(k), we can just brute force it and find if for that k
there's an m that's greater than 1  
*/
void solve()
{
    int n , cnt = 0 ; cin >> n ; 
    vector<int> a(n); for ( auto & e : a ) cin >> e ; 
    for ( int k = 1 ; k*k <= n ; ++k ) 
    {
        if ( (n%k) == 0 ) 
        {
            int divisor = k ; 
            int gcd_ = 0 ; 
            for ( int i = 0 ; i < (n-divisor) ; ++i )
            {
                if ( a[i] == a[i+divisor] ) continue;
                gcd_ = gcd(gcd_,abs(a[i]-a[i+divisor]));
            } 
            if ( gcd_ != 1 ) cnt++; 
        }
        if ( n%(n/k) == 0 && k != (n/k) ) 
        {
            int divisor = n/k ; 
            if ( divisor == n ) 
            {
                cnt++;
                continue;
            }
            int gcd_ = 0 ; 
            for ( int i = 0 ; i < (n-divisor) ; ++i )
            {
                if ( a[i] == a[i+divisor] ) continue;
                gcd_ = gcd(gcd_,abs(a[i]-a[i+divisor]));
            } 
            if ( gcd_ != 1 ) cnt++; 
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