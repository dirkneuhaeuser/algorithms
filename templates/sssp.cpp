vector<int> dijkstra(int start, vector<vector<pii>> graph){ // O(E * log(V))
    // SSSP idea: Always take the next node with minimial distance
    // once taken a node with minimial distance, you can't correct it, as a detour over others will make it worse
    // graph is given like a vector of pii, where first is targetNode, and second is weight.
    priority_queue<pii> q;
    vector<int> distances(graph.size(), INF);
    priority_queue<pii, vector<pii>, ::greater<pii>> nodes;
    nodes.push({0, start});
    while(nodes.size()){
        pii node = nodes.top();
        nodes.pop(); // intotal O(V * log(V))
        int nodeIdx = node.second;
        if(distances[nodeIdx] < INF) continue; // you have that node already 
        int nodeDistance = node.first;
        distances[nodeIdx] = nodeDistance;
        for(int i = 0; i<graph[nodeIdx].size(); ++i){
            int adjNode = graph[nodeIdx][i].first;
            if(distances[adjNode] == INF){
                nodes.push({nodeDistance + graph[nodeIdx][i].second, adjNode}); // In total O(E * log(V))
            }
        }

    }
    return distances;
}
