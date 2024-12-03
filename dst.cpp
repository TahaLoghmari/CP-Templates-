struct node 
{
    node * left_child = nullptr ;  
    node * right_child = nullptr ; 
    int sum = 0 , left , right ; 
    node( int l , int r ) 
    {
        left = l , right = r ; 
    }
    void add_left_right() 
    {
        int m = left + ( right - left ) / 2 ; 
        if ( !left_child && !right_child && left < right ) 
        {
            left_child = new node(left,m) ; 
            right_child = new node(m+1,right) ;
        }   
    }
    void add( int pos , int value , int remove ) 
    {
        add_left_right() ; 
        sum -= remove ; 
        sum += value ; 
        if ( left_child && right_child ) 
        {
            if ( left_child -> right >= pos ) left_child-> add(pos,value,remove);
            else right_child -> add(pos,value,remove);
        }
    }
    int query ( int l , int r ) 
    {
        if ( left > r || right < l ) return 0 ; 
        if ( left >= l && right <= r ) return sum ; 
        add_left_right() ; 
        return left_child->query(l,r) + right_child->query(l,r) ; 

    }
};
class dst 
{
    node * root ; 
    public : 
    dst( int l , int r ) 
    {
        root = new node(l,r) ; 
    }
    void add( int pos , int value , int remove = 0 ) 
    {
        root ->add(pos,value,remove) ; 
    }
    int q( int l , int r ) 
    {
        return root->query(l,r); 
    }
};