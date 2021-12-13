unordered_map<string, int> name2idx;
vector<string> idx2name;
int getIdx(string name){
    if(name2idx.count(name) ==0){
        name2idx[name] = idx2name.size();
        idx2name.push_back(name);
    }
    return name2idx[name];
}
