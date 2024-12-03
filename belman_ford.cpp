struct Edge 
{
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
vector<Edge> edges;
vector<long long> dist(MAXN);
vector<int> parent(MAXN, -1);
int n, m;  
bool bellmanFord(int source) {
    fill(dist.begin(), dist.begin() + n + 1, INF);
    dist[source] = 0;
    for(int i = 0; i < n-1; i++) {
        bool any_update = false;
        for(const Edge& e : edges) {
            if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                parent[e.to] = e.from;
                any_update = true;
            }
        }
        if(!any_update) break;
    }
    for(const Edge& e : edges) 
    {
        if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) return true; 
    }
    return false;
}
vector<int> getPath(int destination) {
    vector<int> path;
    for(int curr = destination; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
}
// int source = 1;  // Usually 1 in CP problems
    
//     bool has_negative_cycle = bellmanFord(source);
    
//     if(has_negative_cycle) {
//         cout << "Graph contains negative cycle\n";
//         return;
//     }