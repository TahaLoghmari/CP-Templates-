
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
- in order for let's say 2 numbers to have same sum and same digit sum as a number n , sum of i'th digits in the two
numbers should sum up to the i'th digit in n, and same for 3 numbers, if you think about it, it makes sense so now 
it's just a matter of in how many ways can we write current digit in n in terms of 3 digits, and that's all 
*/
void solve()
{
    int n ; cin >> n ; 
    int cnt = 1 ; 
    while ( n )
    {
        int current_digit = n%10 ;
        int current_count = 0 ; 
        for ( int i = 0 ; i <= 9 ; ++i ) 
        {
            for ( int j = 0 ; j <= 9 ; ++j ) 
            {
                for ( int k = 0 ; k <= 9 ; ++k ) 
                {
                    if ( i + j + k == current_digit ) current_count++;
                }
            }
        }
        cnt *= current_count ; 
        n /= 10 ; 
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