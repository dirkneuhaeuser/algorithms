vector<string> tokenize(string s, string del = " "){
    int start = 0;
    int end = s.find(del);
    vector<string> ret;
    while (end != -1) {
        ret.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    if(s.substr(start, end - start).size()>0){
        ret.push_back(s.substr(start, end - start));
    }
    return ret;
}    
