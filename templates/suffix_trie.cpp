struct Vertex{
    char character;
    vector<Vertex*> children;
    bool end;
    Vertex(char character){
        character=character;
        end=false;
        children.assign(26, nullptr);
    }
};

class Trie{
private:
    Vertex* root;
public:
    Trie(){root = new Vertex('!');}

    void insert(string word){
        Vertex* head = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(head->children[idx] == nullptr){
                head->children[idx] = new Vertex(word[i]);
            }
            head=head->children[idx];
        }
        head->end=true;
    }

    bool exist(string word){
        Vertex* head = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(head->children[idx] == nullptr){
                return false;
            }
            head=head->children[idx];
        }
        return head->end;
    }

    bool startWith(string prefix){
        // to check in all suffixes if there is this prefix -> substring check in O(m), where m is the length of the prefix, after O(n*n) creating of the suffixtree
        // naive find() would require O(n*m)
        // KMP would need O(n+m);
        Vertex* head = root;
        for(int i=0; i<prefix.size(); ++i){
            int idx = prefix[i]-'a';
            if(head->children[idx] == nullptr){
                return false;
            }
            head=head->children[idx];
        }
        return true;
    }

};

// 1. normal trie -> prefix checks in O(m)
// Trie root = Trie();
//root.insert("hallo"); // create in O(n);
//cout << root.exist("hallb");
//cout << root.exist("hallo");

// STRING MATCHING
// 2. suffix-trie: add all suffixes O(n*n)
//string toInsert = "hellolover";
//for(int i=0; i<toInsert.size(); ++i){
//    root.insert(toInsert.substr(i));
//}
//// substring check in O(m)
//cout << root.startWith("ello"); // true
//cout << root.startWith("allo"); // true


// LRS: FINDING LONGEST REPEATED SUBSTRING IN O(vertices) -> better: suffix-tree: the deepest inner vertix is the answer (the path towards it)

// LCS: LONGEST COMMON SUBSTRING IN O(Vertices) -> insert two words (all its suffixes) and add different terminal symbol, then dfs and mark all inner nodes which have both terminal symbols in their respective subtree
