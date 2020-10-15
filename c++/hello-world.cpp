using namespace std;
#include <tr1/unordered_map>

#include<bits/stdc++.h>  // this includes all standard libraries!!
//#include <iostream>
//#include <vector>
//#include <map>
//#include <set> 
//#include <stack>
//#include <deque>
//#include <queue>

int main(){
    std::cout << "hello world\n";
    auto keywordTest = "blabla";
    std::cout << keywordTest << "\n";

    // ways of iterating throug containers
    std::vector<int> vectorTest = {1,2,3};
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

    // ordered map/dictt -> O(log(n)) 
    std::map<char, int> fst;
    fst['a'] = 10;
    fst['b'] = 20;
    fst['c'] = 30; 
    cout << to_string(fst['c']);
    if (fst.find('c') != fst.end()){
        cout << "its in the map\n";
    }
    
    // unordered map -> O(1)
    std::tr1::unordered_map<int, int> m;
    for(int i = 0; i < 10; ++i){
        m[i] = i;
    }
    if (m.find(9) != m.end()){
        cout << "9 is in the unordered map!\n";
    }
    //for(std::map<Key,Val>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)

    // set 
    std::set<int> st;
    st.insert(4);
    st.insert(3);
    st.insert(4);

    for (auto x: st){
        cout << to_string(x) << "\n";
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

    cout << "\n\n";
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

    for(int i = 0; i < 10; ++i){
        cout << arr[i] << "  " << vr[i] << "\n";
    }

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





    
}
