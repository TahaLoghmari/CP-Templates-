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
- if I'm smaller than j and i'm in i , then delete j , cause If i delete it then I will take his place and the 
string will be lexographically smaller ( Keep doing this in a while loop until you can't delete - if there's some 
chracters we already went through we just skip them )this overall will take O(n)
*/
void solve()
{
    string s , new_s = "" ; cin >> s ;
    int pos , n = s.size() , needed = 0 , i = 0 , cnt = 1 ; cin >> pos ; 
    vector<int> deleted(n), skip(n); 
    for ( int i = 0 ; i < n ; ++i ) skip[i] = i ; 
    while ( i < n ) 
    {
        int j = i - 1 ; 
        while ( j >= 0 && (s[i]-'0') < (s[j]-'0') ) 
        {
            deleted[j] = cnt++;
            j = min(skip[j],j-1) ; 
        }
        skip[i] = j ; 
        i++;
    }
    for ( int i = n - 1 ; i >= 0 ; --i ) deleted[i] = !deleted[i] ? cnt++ : deleted[i] ; 
    i = n ; 
    pos--;
    while ( (pos-i) >= 0 ) 
    {
        pos -= i ; 
        i--;
        needed++;
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( deleted[i] > needed ) new_s += s[i] ; 
    }
    cout << new_s[pos] ;
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