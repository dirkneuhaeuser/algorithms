// SSSP DIJKSTRA
vector<ll> dijkstra(int start, vector<vector<pii>> &AL){ // O(E * log(V))
    // Instead of PQ use a set to update nodes once you see a lower value. The complexity lower but in Big O still the same
    // DOES NOT WORK WITH NEGATIVE WEIGHT CYCLES
    ll n = AL.size();
    vector<ll> dist(AL.size(), INF);
    dist[start] = 0;
    set<pll> pq;
    pq.emplace(dist[start], start);
    while(pq.size()){
        auto [cost, cur] = *pq.begin(); // intotal O(V * log(V))
        pq.erase(pq.begin());
        for(auto [next, w]: AL[cur]){
            if(dist[cur] + w >= dist[next]) continue;
            auto it = pq.find({dist[next], next});
            if(it != pq.end()){
                pq.erase(it); // O(E * log(V));
            }
            dist[next] = dist[cur] + w;
            pq.emplace(dist[next], next);

        }
    }
    return dist;
}

//vector<ll> dijkstra_pq(ll start, vector<vector<pll>> &AL){ // O(E * log(V))
//    // SSSP idea: Always take the next node with minimial distance
//    // once taken a node with minimial distance, you can't correct it, as a detour over others will make it worse
//    // AL is weighted!
//    // DOES NOT WORK WITH NEGATIVE WEIGHT CYCLES
//    vector<ll> dist(AL.size(), INF);
//    priority_queue<pll, vector<pll>, ::greater<pll>> nodes;
//    nodes.push({0, start});
//    while(nodes.size()){
//        auto [d, u] = nodes.top(); nodes.pop(); // intotal O(V * log(V^2))
//        if(dist[u] < INF) continue; // you have that node already 
//        dist[u] = d;
//        for(auto [v, w]: AL[u]){
//            if(dist[v] == INF){
//                nodes.push({d + w, v}); // In total O(E * log(V^2)) -> we can add nodes multiple times, BUT: O(E * log(V^2)) = O(E * 2 * log(V)) = O(E * log(V))
//            }
//        }
//    }
//    return dist;
//}

// BELOW FOR NEGATIVE CYCLES
vector<int> bellmann_ford(int start, vector<vector<pii>> &AL){ // O(V^3)
    // Get the distance from start node to all other nodes and works with negative cycles (no infinite queue)
    // Stops after n iterations, if afterwars still relaxations are possible -> negative cycle
    // Limit ~ V<450
    int n = AL.size();
    vector<int> dist = vector<int>(n, INF);
    dist[start] = 0;
    for(int i=0; i<n; ++i){ // O(V^3)
        for(int v=0; v<n; ++v){
            if(dist[v] != INF){
                for(auto [next, w]: AL[v]){
                    dist[next] = min(dist[next], dist[v] + w);
                }
            }
        }
    }
    return dist;
}

vector<bool> NINFS;
void dfsGetNINF(int cur, vector<vector<pii>> &AL){
    NINFS[cur] = true;
    for(auto [next,w]: AL[cur]){
        if(NINFS[next] == 0){
            dfsGetNINF(next, AL);
        }
    }
}

vector<bool> getNegativeCycleStarts(int start, vector<int> &dist, vector<vector<pii>> &AL){
    // Gets nodes which are part of a negtive cycle. BUT is does not return ALL nodes of this cycle. Do a dfs to get all nodes after this being detected.
    int n = AL.size();
    vector<bool> isNINF = vector<bool>(n, false);
    for(int v=0; v<n; ++v){
        if(dist[v] != INF){
            for(auto [next, w]: AL[v]){
                if(dist[next] > dist[v] + w){
                    dist[next] = dist[v] + w;
                    isNINF[next] = true;
                    isNINF[v] = true;
                }
            }
        }
    }
    return isNINF;
}

// vector<int> dist = bellmann_ford(0, AL);
// vector<bool> starts = getNegativeCycleStarts(0, dist, AL);
// NINFS.assign(n, false);
// FOR(i, n){
//     if(starts[i] && NINFS[i] == 0){
//         dfsGetNINF(i, AL);
//     }
// }
// // now if not NINFS[i] == true, dist[i] has the exact distance from 0 to i. Else we can say its negative INF.



/////// APSP
// for reconstruction:
for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
        par[i][j] = i;
    }
}
for(int k=0; k<n; ++k){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(AM[i][j] > AM[i][k] + AM[k][j]){
                AM[i][j] = AM[i][k] + AM[k][j];
                par[i][j] = par[k][j]; // alwyas points to the penultimate element in the path. For example par[k][j] points to x in  k a b c x j
            }
        }
    }
}
// retrievel of solution from i to j
int cur = j;
while(true){
    ans.push_back(cur);
    if(i == cur){
        break;
    }
    cur = par[i][cur];
}
