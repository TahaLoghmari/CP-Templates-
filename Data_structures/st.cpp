struct node 
{
    int first ;   
    node(int value = 1e10)
    {
        first = value ; 
    }
    static node merge(const node& a, const node& b) 
    {
        return node(min(a.first,b.first));
    }
    static void lazy_add( int & a , int b , int l , int r )  
    {
        a += b ; 
    }
};
template<typename node>
class seg
{
    int n ; 
    vector<node> tree ;
    vector<int> lazy ;  
    void Build( const vector<int>& a , int tl , int tr , int v ) 
    {
        if ( tl == tr )
        {
            tree[v].first = a[tl];
            return ; 
        }  
        int m = tl + ( tr - tl ) / 2 ; 
        Build(a,tl,m,v*2);
        Build(a,m+1,tr,v*2+1);
        tree[v] = node::merge(tree[v*2],tree[v*2+1]);
    }
    void push( int v , int l , int r )  
    {
        node::lazy_add(tree[v].first,lazy[v],l,r); 
        if ( l != r ) 
        {
            lazy[v*2] += lazy[v] ; 
            lazy[v*2+1] += lazy[v] ;
        }
        lazy[v] = 0 ; 
    }
    node query( int tl , int tr , int v , int l , int r ) 
    {
        push(v,tl,tr);
        if ( tl > r || tr < l ) return node() ; 
        if ( tl >= l && r >= tr ) return tree[v];
        int m = tl + ( tr - tl ) / 2 ; 
        node first = query(tl,m,v*2,l,r) , second = query(m+1,tr,v*2+1,l,r);
        return node::merge(first,second);
    }
    void update_range( int tl , int tr , int v , int l , int r , int value ) 
    {
        push(v,tl,tr);
        if ( l > tr || tl > r ) return ; 
        if ( tl >= l && tr <= r ) 
        {
            lazy[v] += value ; 
            push(v,tl,tr);
            return ; 
        }
        int m = tl + ( tr - tl ) / 2  ; 
        update_range(tl , m , v*2 , l , r , value ) ; 
        update_range(m+1 , tr , v*2+1 , l , r , value ) ; 
        tree[v] = node::merge(tree[v*2],tree[v*2+1]);
    } 
    void update( int tl , int tr , int v , int pos , int value ) 
    {
        push(v,tl,tr);
        if ( tl == tr )
        {
            tree[v].first = value ; 
            return ; 
        } 
        int m = tl + ( tr - tl ) / 2 ; 
        if ( pos > m ) update(m+1,tr,v*2+1,pos,value);
        else update(tl,m,v*2,pos,value);
        tree[v] = node::merge(tree[v*2],tree[v*2+1]);
    }
    public:
    seg( vector<int> & a_ ) 
    {
        n = a_.size() ; 
        tree.resize(n*4);
        lazy.resize(n*4,0); 
        Build(a_,0,n-1,1);
    }
    node q( int l , int r ) 
    {
        return query(0,n-1,1,l,r);
    }
    void up( int pos , int value ) 
    {
        update(0,n-1,1,pos,value);
    }
    void up( int l , int r , int value ) 
    {
        update_range(0,n-1,1,l,r,value);
    }
}; 