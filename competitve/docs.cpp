using namespace std;
#include<bits/stdc++.h>  // this includes all standard libraries!!

// python split in c++
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

// template function creates function on the fly whenever its called with a certain type
template<typename T>
void print(T a){
    cout << a;
}

print<int>(3);
print(3); // this is also ok, the compile will figure it out


int main(){


    auto keywordTest = "blabla";
    std::transform(keywordTest.begin(), keywordTest.end(), keywordTest.begin(), ::tolower);
    //std::cout << keywordTest << "\n";

    // manipulating a string
    // occurance
    string stringTest = "some@stupid test@st@@ring for testing purposes";
    int idx = stringTest.find("test"); // gives pos of first occ, (pos argument for starting position)
    // substring
    string subString = stringTest.substr(5, 6);  // startpos and length of substring
    string subString2 = stringTest.substr(5);  // startpos up to the end 
    // change char (string is not unmutable)
    stringTest[0] = 'A';
    // replace
    replace(stringTest.begin(), stringTest.end(), 't', 'x');  // replace a single char
    stringTest.replace(4, 5, " telefone "); // replaces from index=4 the next 5 char with telefone
    // insert
    stringTest.insert(20, "NEW STRING AT POS 20");
    // deleting a substring
    stringTest.erase(1, 40); // deletes the substring starting at 1 with lenght 40
    cout << stringTest << endl;


    // CONVERSION INT AND STRING/CHAR
    int number = 3;
    char num3 = number - '0';
    int again3AsInt = num3 + '0';
    string stringOf3 = to_string(3);


    // string to int, ll, ull;
    unsigned long long x1 = stoul(stringOf3);
    long long x2 = stoll(stringOf3);
    int x3 = stoi(stringOf3);


    // bitsets and binary operations
    int num = 9;
    // number of 1 in the binary repesentation:
    int ones = __builtin_popcount(9);
    __builtin_popcountll(9); // for longlong
    // count leading zeros:
    int lz = __builtin_clz(9); // 00000000 00000000 00000000 00001001 -> leading zeros: 28

    int bitset1 = 0; // for example: what day a worker will work in a month (MAX_D = 30)
    // Problem: considere a year now (MAX_D=365): overflow
    // solution have 365/64 ll bitsets
    // const int K = MAX_D/64 + 1
    // unsigned long long x[K];
    // problem: bit operations and shifting is a pain in the ass
    // Solution:
    bitset<365> x(string("1010")); // here we use 365 bits, which allow all bit operations. Under the hood: array of ll. Complexity: O(MAX_D / 64)
    bitset<365> y(88888888);
    bitset<365> z;
    z[0] = 1; // 0....01
    z.count(); // provides the number of ones in z
    z.set(16, 1); // set bit 16 to 1
    z.reset(16); // set bit 16 to 0
    z.set(); // set all bits to 1
    z.reset(); // set all bits to 0
    z.flip(32); // flips bit 32
    z.flip(); // flips all bits
    cout << "The bitset of z is " << z << endl;
    z[4378] = 1;


    // pair (already have comperator)
    pair <int,int> one;
    one = pair<int,int>(10,20);
    // better:
    one = make_pair (10,20);

    tuple<int, int> tupleTest{1, -1};  // Error until N4387
    tuple<int, int> tupleTest2{1, -1}; // Always works
    tuple<int, int> tupleTest3 = make_tuple(1, -1); // Always works 
    int getFirstElement = get<0>(tupleTest);


    // vectors
    int n = 10;
    vector<int> vect(n, 10);
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001, 0)); // this can also be outside of a method
    std::vector<int> vectorTest = {1,2,3};

    // reasign values
    vectorTest.assign(10, 0); //10 = newSize, 0 newVals

    // destroys all elements in vector
    vectorTest.clear();

    // concat of vectors
    vector<int> vec1(10, 0), vec2(10, 1);
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());

    // ways of iterating throug containers
    for (std::vector<int>::iterator it = vectorTest.begin(); it != vectorTest.end(); ++it){
        int vier = 4;
        std::cout << vier << "\n";
        std::cout << vier << "\n";
    }

    for (auto it = vectorTest.begin(); it != vectorTest.end(); ++it){
	    int drei = 3;
        std::cout << drei << "\n";
    }

    for (auto x: vectorTest){
        cout << to_string(x) << "\n";
    }

    // leaving a nested for loop with goto (only proper use of goto)
    for (int i=0; i<13; i++){
        for(int j=0; j< 123; j++){
            if (i==11 && j == 100){
                cout << "jumping out" << endl;
                goto el;
            }
        }
    }
    el:
    cout << "End of loop reached" << endl;

    // first element which is not smaller in sorted vector
    vector<int> v{1, 4, 16, 19, 21, 73, 299, 1993};
	std::vector<int>::iterator low;
  	//low=std::lower_bound (v.begin(), v.end(), 20); // 

    //auto t = lower_bound(graph[cur].begin(), graph[cur].end(), cur, 
    //    [=](int left, int right){return get<0>(edges[left]) < right; }); // NOTE: the lmabda comparator takes 2 arguments: first dereverenced of the vector, and second has to be T, the target
    cout << "test";


    // finding elements in vector: normally x.find(3). with vectors:
    find(v.begin(), v.end(), 4);

    // ordered map/dictt -> O(log(n)) 
    std::map<char, int> fst;
    fst['a'] = 10;
    fst['b'] = 20;
    fst['c'] = 30; 
    cout << to_string(fst['c']);
    if (fst.find('c') != fst.end()){
        cout << "its in the ap\n";
    }
    
    // unordered map -> O(1)
    std::unordered_map<int, int> m;
    for(int i = 0; i < 10; ++i){
        m[i] = i;
    }
    if (m.find(9) != m.end()){
        cout << "9 is in the unordered map!\n";
    }
    // geting all keys/vals:
    vector<char> keys;
    vector<int> vals;
    for(auto kv : fst) {
        keys.push_back(kv.first);
        vals.push_back(kv.second);  
    } 
    //for(std::map<Key,Val>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)

    // set 
    std::set<int> st;
    st.insert(4);
    st.insert(3);
    st.insert(4);
    st.erase(4);

    for (auto x: st){
        cout << to_string(x) << "\n";
    }

    //multiset
    // multiset maintain keys in a sorted fashion (keys are not unique) 
    // Search, insertion, and removal complexity: O(log(n))
    multiset<int> s;
    s.insert(12);
    s.insert(10);
    s.insert(10);
    s.insert(90);
    // erase values with:
    multiset<int>::iterator itr = s.find(10);
    if(itr == s.end()){
        cout << "WEEEEEEEE AREEEEE AT THEEEEEE END" << endl;
    } else{
        const auto pos = std::distance(itr, s.end()); // IMportant with distance, the smaller iterator needs to be first!;
        //int sameResult = (int)s.end() - (int)itr;  // THAT DOES NOT WORK :(
        cout << "further elemetns to the right: "  << pos  << endl;
        s.erase(itr);
    }

    // stack
    stack<int> stack1;
    stack1.push(100);
    stack1.push(99);
    stack1.push(98);
    cout << to_string(stack1.size());
    while(!stack1.empty()){
        cout << "The stack size is " + to_string(stack1.size()) + " and head is " << to_string(stack1.top()) << '\n';
        stack1.pop();
    }

    // queue
    queue<int> queue1;
    queue1.push(0); // adds right
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.pop(); // pops left

    while(!queue1.empty()){
        cout << queue1.front() << "\n";
        queue1.pop();
    }

    // deque
    deque<int> quiz;
    quiz.push_back(1);
    quiz.push_back(2);
    quiz.push_back(3);
    quiz.push_front(4);
    quiz.push_front(5);
    quiz.push_front(6);
    
    quiz.pop_front();
    quiz.pop_back();
    for(auto x: quiz){
        cout << to_string(x) << "\n";
    }
    cout << to_string(quiz.front()) << " and " << to_string(quiz.back()) << "\n";

    // heap
    // max heap (for min heap, use as 3rd arg: std::greater<>{}  to all heap functions
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::make_heap(begin(numbers), end(numbers)); // elements have now heap structure
    // heap-pop: prepare popping with pop_heap, this will put the max, value to the back and restores order for the rest, then pop it for real
    std::pop_heap(numbers.begin(), numbers.end());
    auto top = numbers.back();
    numbers.pop_back();
    // heap-push: 
    numbers.push_back(33); // 0..n-1 are in heap structure
    push_heap(numbers.begin(), numbers.end()); // all  are in heap structure


    // priority queue
    // better alternative(wrapper) to heap
    std::priority_queue<int> q;
    q.emplace(2);
    q.emplace(1);
    q.emplace(3);
    assert(q.top() == 3);
    q.pop();
    assert(q.top() == 2);
    q.pop();
    assert(q.top() == 1);
    q.pop();

    
    // example of priority-queue with pairs:
    //typedef pair<int, int> pi; 
    //priority_queue<pi, vector<pi>, greater<pi> > pq;  // to make max heap
    priority_queue<pair<int, int> > pq; 
    pq.push(make_pair(10, 200)); 
    pq.push(make_pair(20, 100)); 
    pq.push(make_pair(15, 400)); 
    pair<int, int> topE = pq.top(); 


    // priority-queue using a vector needs comperator:
    //https://stackoverflow.com/questions/48840649/constructing-a-priority-queue-of-vectors


    // gcd of two numbers:
    cout << to_string(__gcd(5,10)) << "\n";

    // pi
    const double pi = 2*acos(0.0);
    cout << to_string(pi)<< "\n";
    

    // Sorting array and vector
    int arr[10];
    vector<int> vr;
    for(int i = 0; i < 10; ++i){
        //cin >> arr[i];
        arr[i] = ~i;
        vr.push_back(~i);
    }
    sort(arr, arr+10);
    sort(vr.begin(), vr.end());

    // sort reverse (rbegin, rend);
    sort(vr.rbegin(), vr.rend());

    // a sort with lambda:
    vector<string> a{"test  jas","dkajk aksjdk"}; 
    sort(a.begin(), a.end(), [](string s, string t) { // [] means no local variable accesssbile in lambda, [=] l.v. are accessible
        return s.substr(s.find(" ")) < t.substr(t.find(" ")); // only sort for the substring after first space
    });
    // stable sort preserves the order of elements which are equal:
    stable_sort(vr.begin(), vr.end());

    // reverse
    reverse(vr.begin(),vr.end());

    // sort but keeping the orginal vector:
    vector<int> v1{9,8,6,7,4,5,2,0,3,1};
    vector<int> v_sorted(v1.size());
    partial_sort_copy(begin(v1), end(v1), begin(v_sorted), end(v_sorted));

    // transform and lambdas: (transform are mapping functions to a range -> return new range)
    transform(vr.begin(), vr.end(), vr.begin(),
            [](int d) -> int {
                if (d < -5) {
                    return 0;
                } else {
                    return d;
                }
            });

    for (auto x: vr){
        cout << to_string(x) << "\n";
    }
   

    string teststr = "hello word";
    cout << teststr[0] << "\n";
    cout << teststr.back();


    //sortable c++ container are permutated lexicographically (already adjusted for same elements)  via
    //true if the function could rearrange the object as a lexicographicaly smaller permutation.
    // vice versa for next_permutation
    string bitmask(K, '1'); // K leading 1's
    bitmask.resize(N, '0'); // N-K trailing 0's

    do {
        cout << bitmask << endl;
        vector<int> cur;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            //if (bitmask[i]) std::cout << " " << i;
            if (bitmask[i]) cur.push_back(all[i]);
        }
        //rets.push_back(cur);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));


    //permutations:
    std::vector<int> v = {1,2,3};
    // vector should be sorted at the beginning.
    do {
        print(v);

    } while (std::next_permutation(v.begin(), v.end()));



    
}
