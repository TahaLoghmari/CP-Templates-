
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
- If we have a graph cycle, that means it's a single round dance that's complete cause each node has its two neighbors
- For all non cycle subgraphs, we can connect them together into a single connected graph to get the minimum,
and for the maximum each non cycle subgraph is a round dance 
- So the problem becomes, count the number of non cycle subgraphs and the number of subgraphs with a cycle
*/
vector<bool> vis ; 
vector<set<int>> graph;
bool is_cyclic( int parent , int node ) 
{
    vis[node] = true ; 
    for ( auto & e : graph[node] ) 
    {
        if ( vis[e] && e != parent ) return true ; 
        else if ( !vis[e] && is_cyclic(node,e) ) return true ; 
    }
    return false ; 
}
void solve()
{
    int n ; cin >> n ; 
    graph.resize(0); graph.resize(n+1);
    vis.resize(0); vis.resize(n+1);
    for ( int i = 0 ; i < n ; ++i ) 
    {
        int node ; cin >> node ; 
        graph[node].insert(i+1);
        graph[i+1].insert(node);
    } 
    int cnt_cyclic_subgraphs = 0 , cnt_non_cyclic_subgraphs = 0 ; 
    for ( int i = 1 ; i <= n ; ++i ) 
    {
        if ( !vis[i] ) 
        {
            if ( is_cyclic(-1,i) ) cnt_cyclic_subgraphs++;
            else cnt_non_cyclic_subgraphs++;
        }
    }
    dbg(cnt_cyclic_subgraphs,cnt_non_cyclic_subgraphs);
    cout << cnt_cyclic_subgraphs + min((int)1,cnt_non_cyclic_subgraphs) << " " << cnt_cyclic_subgraphs + cnt_non_cyclic_subgraphs << endl ;

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