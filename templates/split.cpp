vector<string> tokenize(string s, string del = " "){
    int current, next = -1;
    vector<string> separatedWords;
    string delimiters = ", ";
    do
    {
        current = next + 1;
        next = s.find_first_of( delimiters, current );
        string token =  s.substr( current, next - current );
        if(token != ""){
            separatedWords.push_back(token);
        }
    }while (next != string::npos);
    return separatedWords;
}

