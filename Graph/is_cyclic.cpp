// For Undirected Graph 
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