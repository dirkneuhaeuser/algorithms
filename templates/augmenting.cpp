vector<int> match, vis;
vector<vector<int>> graph;


int aug(int L){
    if(vis[L]) return 0;
    vis[L]=1;
    for(auto &R: graph[L]){
        if((match[R] ==-1) || aug(match[R])){
            cout << L << " " << R << endl;
            match[R] = L;
            return 1;
        }
    }
    return 0;
}


// BETTER TAKE DINIC STRAIGHT AWAY
//match = vector<int>(4, -1);
//vis = vector<int>(4, 0);
//graph = vector<vector<int>>(4, vector<int>());
//graph[0].push_back(3);
//graph[0].push_back(2);
//
//graph[1].push_back(3);
//
//graph[2].push_back(0);
//
//graph[3].push_back(0);
//graph[3].push_back(1);
//
//int mcbm = 0;
//for(int i=0; i<4; ++i){
//    vis.assign(vis.size(),0);
//    mcbm+= aug(i);
//}
//cout << mcbm << endl;
//dbg(match);
