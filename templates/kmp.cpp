vector<int> preProcess(string pattern){
    vector<int> prefixSuffixMatches(pattern.size()+1, 0);
    prefixSuffixMatches[0] = -1;
    int i=0,j=-1;
    while(i<pattern.size()){
        while((j>=0) && pattern[i] != pattern[j]) j = prefixSuffixMatches[j]; // no match -> reset suffix counter
        ++i; ++j;
        prefixSuffixMatches[i]=j;
    }
    return prefixSuffixMatches;
}


void search(string text, string pattern, vector<int>&prefixSuffixMatches){
    // j is counting matched characters
    int i=0,j=0;
    while(i<text.size()){
        while((j>=0) && text[i] != pattern[j]) j = prefixSuffixMatches[j]; // no match -> reset
        ++i; ++j;
        if(j==pattern.size()){
            cout << "Found pattern in text at " << i-j<< "." <<endl;
            j = prefixSuffixMatches[j]; // -> the prefix of the match might be used for the next match
        }
    }
}
//string text = "I love computer science because there is nothing else to love";
//string pattern = "love";
//vector<int> prefixSuffixMatches = preProcess(pattern);
//search(text, pattern, prefixSuffixMatches);
