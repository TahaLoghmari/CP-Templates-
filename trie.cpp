struct Node 
{
    int elements[26] ; 
    int cntEndWith , cntPrefix ; 
    Node()
    {
        cntEndWith = 0 , cntPrefix = 0 ; 
        for ( int i = 0 ; i < 26 ; ++i ) elements[i] = -1 ; 
    }
};
struct Trie
{
    vector<Node> tree ; 
    Trie() {
        tree.resize(1,Node());
    }
    void insert(string word) {
        int current = 0 ; 
        for ( auto & e : word ) 
        {
            if ( tree[current].elements[e-'a'] == -1 )
            {
                tree[current].elements[e-'a'] = tree.size() ; 
                tree.push_back(Node());
            }
            current = tree[current].elements[e-'a'] ; 
            tree[current].cntPrefix++;
        }
        tree[current].cntEndWith++;
    }
    int countWordsStartingWith(string word) 
    {
        int current = 0 ; 
        for ( auto & e : word ) 
        {
            if ( tree[current].elements[e-'a'] == -1 ) return 0 ; 
            current = tree[current].elements[e-'a'] ; 
        }
        return tree[current].cntPrefix ; 
    }
    vector<pair<int,int>> countWordsStartingWithPrefixesOf(string word) {
        vector<pair<int,int>> results ; 
        int current = 0 ; 
        for ( int i = 0 ; i < word.size() ; ++i ) { 
            int c = word[i] - 'a' ; 
            if (tree[current].elements[c] != -1 )
            {
                current = tree[current].elements[c] ; 
                results.push_back({tree[current].cntPrefix,i+1});
            } 
            else return {}; 
        }
        return results; 
    }
    void erase(string word) {
        int current = 0 ; 
        for ( auto & e : word ) 
        {
            current = tree[current].elements[e-'a'];
            tree[current].cntPrefix--;
        }
        tree[current].cntEndWith--;
    }
};