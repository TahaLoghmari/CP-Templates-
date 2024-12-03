void floydWarshall( vector<vector<int>> & graph , int n ) // 0-indexed
{
    for ( int k = 0 ; k < n ; ++k ) 
    {
        for ( int i = 0 ; i < n ; ++i ) 
        {
            for ( int j = 0 ; j < n ; ++j ) 
            {
                if ( graph[i][k] < inf && graph[k][j] < inf ) graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]); 
            }
        }
    }
}