struct node 
{
    node * l ;
    node * r ; 
    int value ; 
    node ( int v = 0 , node * left = nullptr , node * right = nullptr ) 
    {
        value = v ; 
    }
    node( node * left , node * right ) 
    {
        value = 0 ; 
        l = left ; 
        r = right ; 
        if ( l ) value += l->value ;
        if ( r ) value += r->value ; 
    }
}; 
template<typename Node>
class pst 
{
    vector<node*> roots ; 
    int n ; 
    node * build ( int tl , int tr , vector<int> & a ) 
    {
        if ( tl == tr ) return new node(a[tl]);
        int m = ( tl + tr ) / 2 ; 
        return new node(build(tl,m,a),build(m+1,tr,a));
    }
    int query( node * root , int tl , int tr , int l , int r ) 
    {
        if ( tl >= l && tr <= r ) return root -> value ; 
        if ( tl > r || tr < l ) return 0 ; 
        int m = ( tl + tr ) / 2 ; 
        return query(root->l,tl,m,l,r) + query(root->r,m+1,tr,l,r);
    }
    node * update ( node * root , int tl , int tr , int pos , int value ) 
    {
        if ( tl == tr ) return new node(value);
        int m = ( tl + tr ) / 2 ; 
        if ( pos <= m ) return new node(update(root->l,tl,m,pos,value),root->r) ; 
        else return new node(root->l,update(root->r,m+1,tr,pos,value));
    }
    public : 
    pst( vector<int> & a )
    {
        n = a.size() ; 
        roots.push_back(build(0,n-1,a));
    }
    int q ( int pos , int l , int r ) 
    {
        return query(roots[pos],0,n-1,l,r);
    }
    void up ( int value , int pos , int state ) 
    { 
        roots.push_back(update(roots[state],0,n-1,pos,value));
    }
};