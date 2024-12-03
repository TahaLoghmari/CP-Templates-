struct node 
{
    int parent ; 
};
class DSU 
{
    public:
    int n ; 
    vector<int> s ;
    vector<node> p ; 
    DSU( int n_ ) 
    {
        n = n_ ; 
        s.resize(n+1,1);
        p.resize(n+1);
        for ( int i = 1 ; i <= n ; ++i ) p[i] = {i} ; 
    }
    node get( int a ) 
    {
        return p[a] = ( p[a].parent == a ? p[a] : get(p[a].parent) ) ; 
    }
    void Union( int a_ , int b_ ) 
    {
        node a = get(a_) , b = get(b_) ; 
        if ( a.parent == b.parent ) return ; 
        if ( s[a.parent] < s[b.parent] ) swap(a,b);
        p[b.parent].parent = a.parent ; 
        s[a.parent] += s[b.parent];
    }
};