vector<int> dijkstra(int start, vector<vector<pii>> al){ // O(E * log(V))
    // SSSP idea: Always take the next node with minimial distance
    // once taken a node with minimial distance, you can't correct it, as a detour over others will make it worse
    // al is weighted!
    vector<int> dist(al.size(), INF);
    priority_queue<pii, vector<pii>, ::greater<pii>> nodes;
    nodes.push({0, start});
    while(nodes.size()){
        auto [d, u] = nodes.top(); nodes.pop(); // intotal O(V * log(V))
        if(dist[u] < INF) continue; // you have that node already 
        dist[u] = d;
        for(auto [v, w]: al[u]){
            if(dist[v] == INF){
                nodes.push({d + w, v}); // In total O(E * log(V))
            }
        }
    }
    return dist;
}
