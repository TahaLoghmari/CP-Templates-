vector<int> dijkstra(int src) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, LONG_LONG_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while ( !pq.empty( )) 
    {
        int u = pq.top().second;
        pq.pop();
        for ( auto x : graph[u] ) 
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) 
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
