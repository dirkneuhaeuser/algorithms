# Towards Algorithms and Competitive Programming

![patrick-tomasso-Oaqk7qqNh_c-unsplash](https://user-images.githubusercontent.com/44442845/128397574-cb38d50c-08ef-4fe3-9b5e-1ca613c6af65.jpg)

This repository contains my notes on common algorithms in competitive programming.
The explainations are by no means complete and also very consise. Mainly, it concentrates on the implementation side, to use as a quick look-up. If you find something is missing in a specific section or have a question, please reach out to me!
**Note this readme is work in progress.**


# Table of Contents  
1. [Maths](#maths)
    1. [Number Theory](#nt)  
    2. [Combinatorics](#ct)
        1. [Binomial Coefficient](#binCof)
        2. [Multinomial Coefficient](#mulCof) 
        3. [Permutations](#perms)
        3. [Catalan Numbers](#catalan)
        4. [Fibonacci Numbers](#fibs)
    3. [Probability Theory](#pt)
    4. [Game Theory](#gt)
    5. [Fast Matrix Power](#mp)
    6. [Cycle Detetection](#cd)
2. [Graphs](#graphs)
    1. [Bicoloring](#bicolering)
    2. [Cycle-Check on Directed Graphs](#cyclecheck)
    3. [Topological Sort](#topo)
    4. [Eulerian Paths](#euler)
    5. [Tree Graphs](#trees)
    	1. [Master-Theorem](#master)
    	2. [Diameter/Radius/Center](#diameter)
    	3. [LCA and Binary Lifting](#LCA)
    7. [Minimum Spanning Tree](#mst)
    8. [Shortest Paths](#shortestpaths)
    	1. [Unweighted SSSP - BFS](#bfsssp)
    	2. [Weigthed SSSP - Dijkstra](#dijkstrassp)
    	3. [Weigthed SSSP with negative Cycle - Bellmann-Ford](#bellmannsssp)
    	4. [APSP - Floyd-Warshall](#floydapsp)
    10. [Strongly Connected Components](#ssc)
    11. [Articulation Points/Bridges](#articulation)
    12. [Maxflow and Mincut](#maxflow)
    13. [Basic Augmenting](#augmenting)
3. [Dynammic Data-Structures](#dds)
    1. [Fenwick Tree or Binary Index Tree](#FWT)
    2. [Order Statistic Tree](#OST)
    3. [Segment Tree](#ST)
4. [Dynammic Programming](#dp) 
5. [String Processing](#string)
    1. [KMP](#kmp)
    2. [Suffix-Trie](#trie)
6. [Else](#else)
    1. [Convolution](#convolution)
    1. [Bit Manipulation](#bit)

<a name="maths"/>

# 1 Maths

<a name="nt"/>

## 1.1 Number Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>


<a name="ct"/>

## 1.2 Combinatorics

<a name="binCof"/>

### Binomial Coefficient


When calculating it wihout modulo, use Pascal's Formula to prevent unneccesary overflow when calculating the binomial coefficent.

**Pascal's Formula** for <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m}">:

<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m}=\begin{cases}1,  \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\: \text{if } m=0\\1 , \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\: \text{if } n=m\\\binom{n-1}{m} %2B\binom{n-1}{m-1} , \:\: \text{else}\end{cases}">

Pascal's formula In code (long long overflows for n>66):
```
vector<vector<ll>>bincoefs(66, vector<ll>(66, 1));
for(int n = 1; n<66; ++n){
    for(int m = 1; m< n; ++m){
        bincoefs[n][m] = bincoefs[n-1][m] + bincoefs[n-1][m-1];
    }
}
```

With Modulo (precalculate factorials and use modulo arithmetic) - use normal Formula <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m} = \frac{n!}{(n-m)! \cdot m!}">:
```
// out of main:
long long C(long long n, long long k, long long m, long long fact[]){
    // binomial coeffiecents with modulo m
    // n! / ((n-k)! k!) 
    // to use the modular arithmetic, we need to finde the inverse of (n-k)! and k! 
    // factorials need to be precalculated and taken modulo
    if(n < k) return 0;
    return (((fact[n] * invEea(fact[k], m)) % m) * invEea(fact[n-k], m)) % m;
}
// in main:
long long fact[100001];
// precalcualte factorials
fact[0]=1;
for(int i=1; i<100001;++i){
    fact[i] = (fact[i-1]*i)%MOD;
}
// 100000 C 5000:
long long ret = C(100000, 50000, MOD, fact);  // (100000 choose 50000)%1000000007 = 149033233
```
Note: 
* Growth for fixed m, approx: <img src="https://render.githubusercontent.com/render/math?math=O(n^m)">
* <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{p}"> is even iff you can find in the binary representation of n a zero where in p is a 1 at the same position.
* To find odd Coeficients: print pascals-triangle
* Difference to Permutations: Order doesn't matter, thus there are fewer combinations than permutations.


### When to use
* combinations of n elements taken r: <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{r}">
* Binomial Theorem <img src="https://render.githubusercontent.com/render/math?math=(a %2B b)^k = x_0 a^k %2B x_1 a^{k-1}b^1 %2B \ldots %2B x_{k}b^k">, where <img src="https://render.githubusercontent.com/render/math?math=x_i = \binom{k}{i}">.
* To get all subsets of size k from a set of size n (<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{k}"> many), use backtracking: 
[comb1 and comb2
](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/combinatorics.cpp)
* **Combinations to put r elements in k bins**: <img src="https://render.githubusercontent.com/render/math?math=\binom{r %2B k-1}{r}">. To see that, create bijection: separate bins with k-1 stripes "|" (here k=4) and now calculate how many possibiliters there are, to put r dots: <img width="126" alt="Screenshot 2021-05-04 at 03 10 23" src="https://user-images.githubusercontent.com/44442845/126899072-42140c0b-4880-4b5b-bcdb-2934fd517969.png">
* The **Power-set**. The number of subsets of set with k elements (including the empty set): <img src="https://render.githubusercontent.com/render/math?math=2^k">
* **The number of subsets with only even elements** of a set with k elements is <img src="https://render.githubusercontent.com/render/math?math=2^{k-1}">. Intuition: Half of the subsets have eben number of elements, the other half odds number of elements. </br>
Proof with Pascal's Formula: </br>
Number of Subsets with even number of elements:
<img src="https://render.githubusercontent.com/render/math?math=\sum_{k=0}^{n/2}\binom{n}{2k} = \sum_{k=0}^{n/2} (\binom{n-1}{2k-1} %2B \binom{n-1}{2k}) = \sum_{k=0}^{n-1} (\binom{n-1}{k}">. </br>
You get the same result when only considering subsets with odd elements. Thus they divide perfectly.
* The **sum of XOR of all possible subsets of a set with n elemnts**:</br>
Lets consider only **the ith bit**, and how the ith bit will contribute to the total sum. Therefore, lets define **k as the number of numbers, with the ith bit** set.</br>
**Case 1 k>0**:</br> Then we need to take an even number of these. From the set of this k numbers, the number of subsets with an even amount is <img src="https://render.githubusercontent.com/render/math?math=2^{k-1}">, like described above. Now, the amount of other subsequences without ith bit set is <img src="https://render.githubusercontent.com/render/math?math=2^{n-k}">. Multiplied together is the total amount of subsequences with even number of numbers with ith bit set, thus <img src="https://render.githubusercontent.com/render/math?math=2^{n-1}">. Therefore, the total contribution of the ith bit is <img src="https://render.githubusercontent.com/render/math?math=2^{n-1 %2B i}">. Note this does not depend on k, but rather if the bit is set or not in any of these given numbers.</br>
**Case 2 k==0**:</br> Then it does not contribute to the total sum.
```
int xorSum(vector<int> v){
    int bits = 0;
    for (int i=0; i < v.size(); ++i)
        bits |= v[i];
    return bits * pow(2, v.size()-1);
}
```

</br>

<a name="mulCof"/>

#
### Multinomial Coefficient


Let <img src="https://render.githubusercontent.com/render/math?math=n = b_1 %2B b_2 %2B \ldots %2B b_k"> the multinomial coefficient <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{b_1, b_2, \ldots, b_k}"> is given by:

<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{b_1, b_2, \ldots, b_k} = \binom{n}{b_1} \cdot \binom{n-b_1}{b_2} \cdot \binom{n-b_1-b_2}{b_3} \cdot \ldots \cdot \binom{b_k}{b_k} = \frac{n!}{b_1! \cdot b_2! \cdot \ldots \cdot b_k!} ">

### Interpretations:
1. Number of ways to put n interchangeable objets into k boxes, s.t. in box i are <img src="https://render.githubusercontent.com/render/math?math=b_i"> elements
2. Number of **unique permutations** of a word with n letters and k distinct letters, s.t. i-th letter occurs <img src="https://render.githubusercontent.com/render/math?math=b_i"> times.
   E.g. permutating a mask vector `[1, 1, 1, 1, 0, 0, 0]`, leads to  <img src="https://render.githubusercontent.com/render/math?math=\frac{7!}{4! 3!}">.


</br>

<a name="perms"/>

#
### Permutations

Difference to Binomial-Coefficients: Now the Order matters. Total Permutations of sequence of length n: <img src="https://render.githubusercontent.com/render/math?math=n!">. 


Implementation via backtracking. In c++, sortable container can be permutated lexicographically (already adjusted for same elements) via in-build
`prev_permutation` and `next_permutation`:
```
vector<int> test = {1,2,3};
while (next_permutation(test.begin(), test.end())){
    // do sth
}
```
### When to use
* permutations of n elements **taken only r**: <img src="https://render.githubusercontent.com/render/math?math=\frac{n!}{(n-r)!}">, meaning the permutatins of the remaining (n-r) are not included
* **Derangement count**: Count all permutations in which all elements are at different positions (from their initial position). Formula: `derange(n) = (n - 1) * [derange(n - 1) + derange(n - 2)]`

Recusive Forumula (long long overflows for n>21):
```
long long derange[22];
derange[1] = 0;
derange[2] = 1;
for(int i =3; i<22; ++i){
    derange[i] = (i-1) * (derange[i-1] + derange[i-2]);
    cout << derange[i] <<endl;
}
```
*Proof Derangement*: Let's consider a random permuation (e.g., [1, 2, 3, 4, 5])
Then, for the first element you have (n-1) options. Lets assume it goes to i. Now there are two possible options: <br />
**Case 1**: You have a perfect swap (i and 1) -> derange(i-2) <br />
**Case 2**: You don’t have a perfect swap. Then, the i-th element can choose all elements apart of 1 and i, the remaining j can choose all apart of j and i. Thus, all remaining (n-1) have (n-2) Possibilities -> derange(i-1)






</br>

<a name="catalan"/>

#
### Catalan Numbers

The sequence 1, 1, 2, 5, 14, 42, 132, 429, 1430, ... is called Catalan Numbers.

Recursive Formula:
without mod (wachstum <img src="https://render.githubusercontent.com/render/math?math=4^n">, thus long long **overflows at n>32**)
```
long long cat[33];
cat[0] = 1;
for(int i=1; i<33; ++i){
    cat[i] = (4*i+1) * cat[i-1] / (i+2);
    cout << cat[i] << endl;
}
```

with mod:
```
int max_n = 100001;
ll cat[max_n];
cat[0] = 1;
for(int i=1; i<=max_n; ++i){
    cat[i] = ((4*i+2)%MOD * cat[i-1]%MOD *invEea(i+2, MOD)) % MOD;
    cout << cat[i] << endl;
}

```

### When to use (Catalans)
* Number of **distinct binary** trees with n vertices
* Number of ways n pairs of **parentheses** could match: n=2 pairs: ()() (()) 
* Number of ways an expression with **binary operations** can be **bracketet**
* Number of ways a **polygon** with n+2 sides can be **triangled**
* Number of ways you can pass from (0, 0) to (n, n) in a **grid without passing/touching the diagonal** (being only in the lower half)
* More complex examples: [Totorial by Dardy](https://codeforces.com/blog/entry/87585)


### Suber-Catalan 
The sequence 1, 1, 3, 11, 45, 197, 903, 4279, 20793, 103049, ... is called Super-Catalan Numbers.

Recursive Formula:
Note, long long **overflows at n>27**
```
long long super[28];
super[0] = 0;
super[1] = 1;
for(int i=2; i<28; ++i){
    super[i] = ((6*i - 9) * super[i-1] - (i-3) * super[i-2]) / i;
    cout << super[i] << endl;
}
```
### When to use (Super-Catalan)
* Number of ways you can pass from (0, 0) to (n, n) in a **grid without passing the diagonal** (toching the diagonal is ok) (being only in the lower half)
* number of **trees** with n leaves & non-leaves **>=2 childern**
* Number of **non binary bracketing**: x(xxx)x here (xxx) has 3 and not 2 elements 


Note that there are bijective mappings between the specific usecases, e.g., between the number of non-binary backeting and the number of trees with >= 2 children.


</br>

<a name="fibs"/>

#
### Fibonacci Numbers
The sequence 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ... is called fibonaccie sequence

Code (Growth ca <img src="https://render.githubusercontent.com/render/math?math=2^n">; long long will **overflow for n>64**) for <img src="https://render.githubusercontent.com/render/math?math=O(n)"> runtime: 
```
vector<int>fibs={0,1};
for(int i =2; i<65; i++){
    fibs.push_back(fibs[i-1] + fibs[i-2]);
}
```

### Pisano Period

If calculating the Fibonaccis modulo m, eventually there will be a **circle**. Let the circle be of length l, then assume that <img src="https://render.githubusercontent.com/render/math?math=F(k \cdot l) \equiv 0 (\mod m)"> it will be on 0:

```
int pisanoPeriod(int mod){ // O(n^2)
    int fib1 = 0, fib2=1;
    int period = 0;
    while(true){ // assume, that there is indead a pisano period
        // by pigoen hole principle there is at least on tuple fib_i fib_i+1 which whill be equal to another one after n**2
        // doesnt have to be start though
        period++;
        int newFib = (fib1+fib2) % mod;
        fib1 = fib2;
        fib2 = newFib;
        if(fib1==0 && fib2==1){
            return period;
        }
    }
}
```

### Zeckendorf Theorem:
Fibonacci can be presented as a binary string 1010 means: <img src="https://render.githubusercontent.com/render/math?math=0 \cdot 1 %2B 1 \cdot 2 %2B 0 \cdot 3 %2B 1 \cdot 5">.
It can be shown that two 1 are never together, as for example, 2 and 3 would form the 5, which then sets the bit of 5 and unset bits for 2 and 3

### Fibonacci Number in Logarithmic Time with fast Matrix Power
With divide and conquer, the power p of a quadratic matrix can be computed in <img src="https://render.githubusercontent.com/render/math?math=O(\log(n))"> runtime. Note that here the dimension d of the matrix is small,
and the matrix-multiplication of <img src="https://render.githubusercontent.com/render/math?math=O(d^3)"> is neglectable. For implementation see [matrix power](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/mod_pow_mat.cpp).

Recursive Formula:

<img src="https://latex.codecogs.com/gif.latex?\begin{bmatrix}1&space;&&space;1\\1&space;&&space;0\end{bmatrix}\begin{bmatrix}\text{fib}(n&plus;1)\\\text{fib}(n)\end{bmatrix}&space;=&space;\begin{bmatrix}\text{fib}(n&plus;2)\\\text{fib}(n&plus;1)\end{bmatrix}" title="\begin{bmatrix}1 & 1\\1 & 0\end{bmatrix}\begin{bmatrix}\text{fib}(n+1)\\\text{fib}(n)\end{bmatrix} = \begin{bmatrix}\text{fib}(n+2)\\\text{fib}(n+1)\end{bmatrix}" />

```
Matrix A(2);
A.mat[0][0] = 1;
A.mat[0][1] = 1;
A.mat[1][0] = 1;
A.mat[1][1] = 0;
    
Matrix ret = modPowMat(A, n);
cout << ret.mat[0][1] << endl;  //the n-th fib number, modulo MOD in O(log n)
```

</br>
</br>
</br>
</br>
</br>

<a name="pt"/>

## 1.3 Probability Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="gt"/>

## 1.4 Game Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="mp"/>

## 1.5 Fast Matrix Power
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="cd"/>

## 1.6 Cycle Detetection
### Floyds Cycle Detection

Usually it is better to just use a dictionary, however when you need to save memory: For example when dealing with huge strings/vectors:
Floyds Cycle Detection might be favourable.

Implementation:
Let <img src="https://render.githubusercontent.com/render/math?math=\mu"> denote the **start of cycle**, 
<img src="https://render.githubusercontent.com/render/math?math=\lambda"> the **length of cycle** and
f the step function.

We have use two pointers, the **tortoise** t and the **hare** h. h is moving two times as fast as t. When they finally meet, somewhere in the circle, then
t has made i steps, the hare has made these i steps and also circled around in the the circle a bit, thus: <img src="https://render.githubusercontent.com/render/math?math=x_i = x_{i %2B k \cdot \lambda}">.
As the hare is twice as fast, we also derive that <img src="https://render.githubusercontent.com/render/math?math=i = k \cdot \lambda">, and hence <img src="https://render.githubusercontent.com/render/math?math=x_i = x_{i %2B i}">.

### Determine, the start of circle

Setting the tortoise back to the start, then there is a **distance of i** in between both pointers. Now stepping with both one step, we keep the distance of i of both pointers; that means, when both pointers are within the cycle they have a distance of i,
 which is <img src="https://render.githubusercontent.com/render/math?math=0 \equiv i \: (\mod k \cdot \lambda)">.

### Determine, the Length of circle

Leave tortoise at the cycle start and move the hare forward until it is back to the start of the cycle.

Overall code:
```
int t = f(x0), h = f(f(x0));
while(t != h){
    t = f(t); h = f(f(h));
}
int mu = 0; h =x0; // t = k*lambda
while(t != h){ // determining cycle start index
    mu++;
    t = f(t); h = f(h);
}
h = f(t);
int lambda = 1;
while(t != h){ // determining cycle length
    lambda++;
    h = f(h);
}
```




</br>
</br>
</br>
</br>
</br>


<a name="graphs"/>

# 2 Graphs



<a name="bicolering"/>

## 2.1 Bicoloring

To check if a graph is **bipartite**, we can bi-color it with a dfs
```
vector<int> colors;
bool isBipartite(int idx, int col, vector<vector<int>> &AL){
  colros[idx] = col;
  for(int next: AL[cur]){
    if(colors[next] == -1){
      if(!isBipartite(next, col^1, AL)) return false;
    }else if(colors[next] == col) return false;
  }
  return true;
}
# in main:
colors.assign(n, -1);
bool bipartite = true;
for(int i=0; i<n; ++i){
  if(colors[i] == -1) bipartite = bipartite && isBipartite(i, 0, AL);
}
```

</br>
</br>
</br>
</br>
</br>

<a name="cyclecheck"/>

## 2.2 Cycle-Check on Directed Graphs

Cycles on undirected graphs exist per defintion. On directed graphs, they can be found via **backward-edges**.
```
enum {VISITED=-2, UNVISITED=-1, EXPLORED=-3};
vector<int> visited;
bool hasCycle(int idx, vector<vector<int>> &AL){
  visited[idx] = EXPLORED;
  for(int next: AL[idx]){
    if(visited[next] == EXPLORED) return true;
    if(visited[next] == UNVISITED && hasCycle(next, AL)) return true;
  }
  visited[idx] = VISITED;
  return false;
}
# in main:
visited.assign(n, UNVISITED);
bool cycle = false;
for(int i=0; i<n; ++i){
  if(visited[i] == UNVISITED) cycle = cycle || hasCycle(i, AL);
}
```

</br>
</br>
</br>
</br>
</br>

<a name="topo"/>

## 2.3 Topological Sort

**Topological sort** allows for sorting a list according to its dependencies (dependencies first). This only works on **DAG**'s.
We need an adjacency-list `AL[v] = [..u..]` which means that `v` comes before all elments `u` in the topological order.
Both algorithm run in <img src="https://render.githubusercontent.com/render/math?math=O( V %2B E)">. When using the **more flexible Kahn **algorithm together with a priority queue the complexity will be <img src="https://render.githubusercontent.com/render/math?math=O(V \log V %2B E)">


### Kahn Algorithm
The Kahn algorithm looks at the **in-degree** of each node `v`. If it is zero then this means, that no element needs to be before `v` and we can go ahead with it.
Note that Kahn algorithm is **more flexible**, as it allows us to change the order for all elemnts which have **in-degree = zero** at the same time (by using a priority queue). However, this would also let the complexity grow <img src="https://render.githubusercontent.com/render/math?math=O(V %2B E) \rightarrow O(V \log V %2B E)">.

```
priority_queue<int, vector<int>, ::greater<int>> pq; // maybe chose pair<int, int> for more flexible order
for(int i=0; i<n; ++i){
  if(in_degree[i] == 0){
    pq.push(i); 
  }
}
while(pq.size()){
  int cur = pq.top(); pq.pop();
  order.push_back(cur);
  for(int next: AL[cur]){
    if(--in_degree[next] == 0){
      pq.push(next);
    }
  }
}
```

### DFS Variant (post-order)
```
void topsort(int u, vector<int> &vis, vector<int> &order){
  vis[u] = VISITED;
  for(int next: AL[u]){
    if(vis[next] == UNVISITED){
      topsort(next, vis, order);
    }
  }
  order.push_back(u);
}
// in main
for(int i=0; i<n; ++i){
  topsort(i, vis, order);
}
```
Here the `order` vector only needs to be **reversed** to contain the correct topological-order.



</br>
</br>
</br>
</br>
</br>

<a name="euler"/>

## 2.4 Eulerian Paths

A graph has an **Euler Path**, if it is possible to start at an arbitrary node and then **traverse through each edge exactly once**.
Analoguousely, an Euler tour needs to start and end at the same vertex.

### Requirements Undirected Graph.
1. Graph is **connected**
2. Each vertex has an **even edge-degree** (tour). For a euler path two vertices may have an odd degree.

### Requirements Directed Graph.
1. Graph is **connected** (No need for strongly connection. Pretend the graph is undirected and check for connection, this is enough together with condition 2)
2. For each vertex `i` holds `inDegree[i] == outDegree[i]`. For an euler path, the endnode may have `inDegree[i] +1 == outDegree[i]`, together with `inDegree[i] == outDegree[i]+1` for the start node.

### Hierholzer Algorithm 
After checking the above requirements, **Hierholzer-algorithm** finds a possible euler-path. It runs in  <img src="https://render.githubusercontent.com/render/math?math=O(E)"> and works in a post-order fashion.
Therefore, the result needs to be **reversed** eventually. Note the gloabl `idx` array to memorise the progress for each node. 

```
vector<int> hierholzer(int s, vector<vector<int>> &AL){
    // Finds the euler path within a graph in O(E).
    // The algorithm passes through the graph rather arbitrarily. 
    // Idea: If you start u and at some point come back to u, you either have each edge passed (save the progress in vi idx) or you can still have another detour starting from u.
    // With the stack you have this kind of post-order (similar to topological sort) -> REVERSE the result
    vector<int> ret, stack, idx(AL.size(), 0);
    stack.push_back(s);
    while(stack.size()){
        int cur = stack.back();
        if(idx[cur] < AL[cur].size()){
            stack.push_back(AL[cur][idx[cur]]);
            idx[cur]++;
        }else{
            int justFinishedCycle = stack.back(); stack.pop_back();
            ret.push_back(justFinishedCycle);
        }
    }
    return ret; // needs to be reversed.
}

```



</br>
</br>
</br>
</br>
</br>

<a name="trees"/>

## 2.5 Tree Graphs

A tree-graph of `n` nodes has `n-1` edges and each node is directly or indirectly connected to any other node. 

<a name="master"/>

### Master-Theorem

The **Master-Theorem** provides a runtime analysis for **divide and conquer** algorithms and therefore is often found when travesing through trees.

<img src="https://render.githubusercontent.com/render/math?math=n \:\:\:\:\: "> is the input-size <br/>
<img src="https://render.githubusercontent.com/render/math?math=t(n)"> is the effor in the inner node (time to create subproblems, time to merge results of subproblems) <br/>
<img src="https://render.githubusercontent.com/render/math?math=a  \:\:\:\:\:"> is the number of subproblems in the recursion <br/> 
<img src="https://render.githubusercontent.com/render/math?math=b  \:\:\:\:\:"> is the factor by which the subproblem size is reduced in each recursive call 


<img src="https://render.githubusercontent.com/render/math?math=T(N) = aT(\frac{n}{b}) %2B t(n)">


The criterium is the **complexity of the subproblems** is now:  <img src="https://render.githubusercontent.com/render/math?math=\text{crit} = O(aT(\frac{n}{b})) = O(n^{\log_b(a)})"> <br/>

**Proof**: As The depth of the tree is given by <img src="https://render.githubusercontent.com/render/math?math=\log_b(n)"> and at depth i
there are <img src="https://render.githubusercontent.com/render/math?math=a^i"> subproblems. 
This means, there are <img src="https://render.githubusercontent.com/render/math?math=a^{\log_b(n)} = n^{\log_b(a)}"> leaves (log-law).
So, the overall complexit of the tree <img src="https://render.githubusercontent.com/render/math?math=O(n^{\log_b(a)})">.


There are three  possibilities:

1. Subproblems **dominate** the splitting and merging: <br/> 
    <img src="https://render.githubusercontent.com/render/math?math=t(n) = O(n^{\log_b(a)}) \rightarrow T(n) = O(n^{\log_b(a)})">
      
2. Subproblems are **comparabel** to splitting and merging, thus at each level, we add the complexity for<img src="https://render.githubusercontent.com/render/math?math=t(n)">:<br/> 
   <img src="https://render.githubusercontent.com/render/math?math=t(n) = \theta(n^{\log_b(a)}) \rightarrow T(n) = \theta(n^{\log_b(a)} \log_b(n))"> <br/>
   
3. Subproblems are **dominated** by spitting and merging: <br/>
   <img src="https://render.githubusercontent.com/render/math?math=t(n) = \omega(n^{\log_b(a)}) \rightarrow T(n) = \theta(t(n))"> <br/>
   
 
### Example

Let <img src="https://render.githubusercontent.com/render/math?math=T(N) = 2T(\frac{n}{2}) %2B n/2">, then <br/>
<img src="https://render.githubusercontent.com/render/math?math=\text{crit} = O(n^{\log_2(2)}) = O(n)"> and <br/> 
<img src="https://render.githubusercontent.com/render/math?math=O(t(n)) = n/2 = O(n)"> <br/>
Thus, the second case: <img src="https://render.githubusercontent.com/render/math?math=O(T(n)) =  O(n \log(n))"> <br/>

Trees have some interesting properties:


<a name="diameter"/>

### Diameter/Radius/Center
The **Diameter** of a (weighted) tree, is the **longest shortest path between any two nodes**. While the computation of longest shortest path in normal graph can be obtained
via Floyd-Warshall in <img src="https://render.githubusercontent.com/render/math?math=O(n^3)">, in trees it can be done in <img src="https://render.githubusercontent.com/render/math?math=O(n)">. The idea is to pick any random node `r`, from there go the furthest node `fst` of `r` and repeat 
that to find the furthest node `snd` from `fst`. The distance between `fst` and `snd` is the longest distance.

The diameter has either one **center node**, or the center lies on an edge. Either way, the center is defined to be on the half of the diameter (**radius**). 

<a name="LCA"/>

### LCA and Binary Lifting
Given two nodes `u` and `v`, the **Least Common Ancestor** (LCA) is the first node, that lie on both paths to the root, from `u` and also from `v`.
The <img src="https://render.githubusercontent.com/render/math?math=O(n)"> idea would be to precalculate the depth for each node in <img src="https://render.githubusercontent.com/render/math?math=O(n)">
and then to **bring** `u` and `v` to the **same depth** linearly. 
From there always go up to the root linearly <img src="https://render.githubusercontent.com/render/math?math=O(n)">, until both nodes are equal. However, when there are many queries, 
we can improve that to <img src="https://render.githubusercontent.com/render/math?math=O(\log(n))"> by utilising a <img src="https://render.githubusercontent.com/render/math?math=O(n \log(n))"> proprocessing, called **Binary Lifting**.
Therefore we define `up[u][i]` to be that node, that is <img src="https://render.githubusercontent.com/render/math?math=2^i"> higher than node `u`, i.e. that `up[u][0]`(1 up) is the direct parent and `up[u][1]`(2 up) 
is the grandparent. Next, `up[u][2]` would be 4 up and so on. By using this binary expansion, we can get to any arbitrary height.

**Binary Lifting**:
```
int LOG = 20; // 2^LOG should be the max depth
for(int j=1; j<=LOG; ++j){
    for(int i=0; i<n; ++i){
        up[i][j] = up[up[i][j-1]][j-1];
    }
}
```

With that, the idea of the LCA computation remains the same: First bring both nodes to the same level (via binary lifting) and then move both nodes up as 
much as possible while such that both nodes are not even. At the end of this routine, **both nodes will be the direct children of the LCA**:
```
int getLCA(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    // a is deeper;
    int dif = depth[a]-depth[b];
    for(int i=0; i<LOG; ++i){
        if(dif & (1 << i)){
            a = up[a][i];
        }
    }
    // edge-case:
    if(a == b) return a;
    // binary lifting to the predecessor of LCA
    for(int i=LOG-1; i>=0; --i){ // very important here to go from LOG-1 -> 0, as otherwise we cannnot do all jumps
        // for example the grand parent is two levels up. we cannot jump 1 and again 1...
        if(up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    // return LCA
    return up[a][0];
}
```



</br>
</br>
</br>
</br>
</br>

<a name="mst"/>

## 2.6 Minimum Spanning Tree (MST)

There are two well known algorithms for the MST, **Krusal**, which uses the **disjoint-set datastructure**, and **prim's** algorithm, which works similarly to
dijkstra's SSSP. 
The difference is that dijsktra looks at nodes and minimises the distance from a given starting node to it,
while prime just takes the next lowes edge which endpoint has not been seen yet. Both algorithm work in
<img src="https://render.githubusercontent.com/render/math?math=O(E \log E)">.

### Kruskal DJS
```
class DJS{ // O(E Log E)
public:
    vector<int> rank, par;
    int forrests;
    DJS(int n){
        par = vector<int>(n, 0);
        for(int i=0; i<n; ++i)par[i] = i;
        forrests = n;
        rank.assign(n, 1);
    }
    int getPar(int x){
        if(par[x] == x) return x;
        return par[x] = getPar(par[x]);
    }
    bool isSame(int x, int y){
        return getPar(x) == getPar(y);
    }
    bool unionfy(int x, int y){
        if(isSame(x, y)) return false;
        forrests--;
        int px = getPar(x), py = getPar(y);
        if(rank[px] < rank[py]){
            swap(px, py);
        }
        par[py] = px;
        rank[px] += rank[py];
        return true;
    }
};
// in main;
vector<tiii> edges; // add all edges
sort(edges.begin(), edges.end());
DJS djs(n);
long long ret = 0;
for(int j=0; j<edges.size(); ++j){
  auto [cost, a, b] = edges[i];
  if(djs.unionfy(a, b)){
    ret += cost;
  }
}
```

To check whether a spanntree exist, check that `djs.forrests == 1`.

### Prim
```
int startIdx = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq
pq.push({0, startIdx});
vector<bool> seen(n, false)
long long ret = 0;
while(pq.size()){
  auto [tCost, tIdx] = pq.top(); pq.pop();
  if(seen[tIdx]) continue;
  ret += tCost;
  for(auto [next, w]: AL[tIdx]){
    if(seen[next] == false){
      pq.push({w, next});
    }
  }
}
```
### When to use:
Per default use DJS
- Minimum/Maximum Spanning Tree
- Minimum Spanning **Subgraph** (part of the edges are already given)
- **Minimum Spanning Forrest** (stop when `djs.forrests == k`)
- **MiniMax** (Connect all nodes and try to minimise the maximum edge weight used for that). Vice verca for MaxiMin. The result is given just by the MST
- **Second Best Spanning Tree**. (run normal MST, then you have n edges.
  For each of theses edges run MST again and don't include it) O(sorting + MST + Second Best MST) = <img src="https://render.githubusercontent.com/render/math?math=O(E log E %2B E %2B VE)">.
  Alternatively if E is huge, calculate the MST and get the minimal cost. Then for each v run a dfs and get the maximum distance between any two nodes in <img src="https://render.githubusercontent.com/render/math?math=O(V^2)">. 
  Now just pass though all edges which are not part of the MST. Add its weight and subtract the maximum distance between these two nodes within the orginal MST (See kattis spider).
- When there are **several starting points**, use **Prim**'s Algorithm (aksed for optimal forrests here)



</br>
</br>
</br>
</br>
</br>

<a name="shortestpaths"/>

## 2.7 Shortest Paths

When the edges are not weighter we can use a **BFS** for the shortes paths, othrweise **Dijkstra**'s algorithm.
Dijkstra uses the same idea of a BFS, but instead of a normal queue, it uses a **priority queue to favour nodes with a smaller distance**.
Often when a problem appears to be a **DP problem**, but are **not** defined on a **DAG**, then most certainly these are BFS problems.

**Typic Examples**:

Single Source Shortest Path (SSSP) </br>
Singe Source Single Destinaion Shortest Path (SSSDSP) </br>
Multiple Sources Shortest Pahts (MSSP) </br>
.. Other vairations, I will commonly use SSSP.

<a name="bfsssp"/>

### Unweighted SSSP - BFS

The normal **BFS** provides us with the shortest distance to all nodes in <img src="https://render.githubusercontent.com/render/math?math=O(V %2B E)">.

Typical 2D Grid example:
```
queue<pii>q; 
q.insert({startI, startJ})
vector<pii> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
while(q.size()){
    auto [i, j] = q.front(); q.pop();
    for(auto [di, dj]: dir){
        int nextI = i + di;
        int nextJ = j + dj;
        if(nextI < 0 || nextJ < 0 || nextI > n-1 || nextJ >n-1) continue;
        if(dis[nextI][nextJ] < INF) continue;
        dis[nextI][nextJ] = dis[i][j] + 1;
        q.push({nextI, nextJ});
    }
}
```

Note: 
- Similarly, A graph with only **0/1 Weights** can be handeld by a **deque** (very similar to Dijkstra). If we have a 0 Edge we will push it to the front, else to the back. Dijkstra would works just as fine, but this way we save us from using an expensive priority-queue.
- **Shortest Cycle**: Shortest Path on undirected Graphs: Bfs from i to j and if you have seen j already -> Cycle. 

<a name="dijkstrassp"/>

### Weigthed SSSP (no negative cycles) - Dijkstra

If the edges are **weighted**, e.g. we want to minimise the time to go from a to b, we need to use a `priority_queue` instead of a normal `queue`, as the main idea is to always use the cell/node with the current lowest cost/time. This node cannot improved any further, but maybe can be used to improve others.
Unfortunately, the `priority_queue` in c++ doesn't allowe to **update keys**, therefore we use `set` here. The complexity is <img src="https://render.githubusercontent.com/render/math?math=O((V %2B E) \log V)">.

Note Dijkstra does not work, when there is a negative cycle.


```
vector<ll> dijkstra(ll start, vector<vector<pll>> &AL){ // O(E * log(V))
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
```

Notes:
1. For **reconstruction** of a single shortest path use a **parent vector** and whenever you can update the next element, update also the parent (Works for bfs/dijkstra).
2. To know wheter an **edge/node is part of any possible shortest path**: Apply weighted/unweighted from begining and again from end (reversed AL).
A node is part of a shortest path if `dist[node] + distRev[node] == dist[endNode]`, analogously an edge is part of a shortest path if both connected nodes are part of the shortest path + the difference in between both `dist` values is the weight of the edge `w`.
3. When there are some further monoton restrictions, apply them during the for-loop inside Dijkstra.


<a name="bellmannsssp"/>

### Weigthed SSSP with negative Cycle - Bellmann-Ford
When there are **negative cycles** then Dijkstra would run forever without stopping. **Bellmann-Ford** alleviates this issue by running the **exact amount** of **iterations** needed to calculate the shortest path from the rooot to any other node, assuming there are no negative cycles. To check if there is a negative cycle, another single iteration can be made. If any weight improves, then there is a negative cycle. The algorithm runs in <img src="https://render.githubusercontent.com/render/math?math=O(V^3)"> and therfore requires a `V <= 450`.

```
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

```
Note: 
- Sometimes the task is about positive cycles, than **changing the sign** might do the trick.
- Bellmann-Ford sometimes come also with further **restrictions**, which then need to be incorporated into the <img src="https://render.githubusercontent.com/render/math?math=O(V^3)"> loop.

<a name="floydapsp"/>

### APSP - Floyd-Warshall
Instead of computing the shortest path from a single source node, sometimes it is required to have the **shortest distance between all pairs of nodes**.
Floyed-Warshall computes All-Pairs-Shortest-Paths in <img src="https://render.githubusercontent.com/render/math?math=O(V^3)"> in a dp-fashion by trying to find smaller detours from i to j over k:
```

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
```
Note / Applications:
- When we need to reconstruct a shortest path between i and j then we need a **2D reconstruction**.
- In Floyed-Warshall the inital AM do not need all start-values as long these can be build by the **principe of transitivity** (can save a lot of time)
- **Transitive closure problem**: Only check need: Is there a path from a to b. Everyhing can be Boolean. `AM[i][j] = AM[i][j] || (AM[i][k] && AM[k][j])`
- For some compound problems, **optimal subpaths** in form of `AM[i][b] + AM[a][j] + roadLength` or `AM[a][i] + AM[i][b]` are often useful.
- **Diameter** of a graph: The maximum shortest path between any pair nod nodes.
- **Shortest Cycle**: On the diagonal `AM[i][i]` gives you the shortest cycle. If negative: We can go to -INF.



</br>
</br>
</br>
</br>
</br>

<a name="ssc"/>

## 2.8 Strongly Connected Components

On an undirected graph, the connected components can be found with an easy DFS. When the graph is **directed** however, we call a **strongly connected component** (SSC)
a subset of the vertexes in the graph, within each vertex can reach each of the other vertex in the same SSC. **Tarjan's algorithm** runs in <img src="https://render.githubusercontent.com/render/math?math=O(V %2B E)"> and assigns each node to its **SSC-root**; the same root marks the same SSC.

The main idea is that there is a single root node (start node) for each SSC. For this root holds that it coudn't make its `dfs_low` value smaller than `dfs_num`. 
All the nodes afterwars are part of this SCC (unless have been put to a different SSC already - saved in `visited`).

```
vector<int> dfs_num, dfs_low, dfs_stack, visited, root;
int dfs_idx;

void tarjan(int cur, vector<vector<int>> &AL){ // O(V + E)
    dfs_num[cur] = dfs_low[cur] = dfs_idx++;
    dfs_stack.push_back(cur);
    visited[cur] = 1;
    for(int next: AL[cur]){
        if(dfs_num[next] == UNVISITED){
            tarjan(next, AL);
        }
        if(visited[next] == 1){ // not part of other SSC -> same SSC
            dfs_low[cur] = min(dfs_low[next], dfs_low[cur]); // if it is not yet completed;
        }
    }
    if(dfs_low[cur] == dfs_num[cur]){
        // cur is start of a ssp;
        while(true){
            int last = dfs_stack.back(); dfs_stack.pop_back();
            root[last] = cur;
            visited[last] = 0;
            if(last == cur) break;
        }
    }

}
// in main:
dfs_num.assign(n, UNVISITED);
dfs_low.assign(n, UNVISITED);
visited.assign(n, false);
root.assign(n, UNVISITED);
dfs_stack.clear();
dfs_idx=0;
FOR(i, n){
    if(dfs_num[i] == UNVISITED){
        tarjan(i, AL);
    }
}
```
### When to use
- Often, a task is to **reduce all SSC to single node **and
afterwards check for some critera (e.g. count all `in_degree == 0` nodes). Questions like **how many dominos you need to push?**.
- Given a directed Graph G, **how many edges do you need to add, to make it a SCC?**
   1. Reduce all SSC in G to a single node -> G is now DAG
   2. If this DAG consists only of one node, the answer is 0
   3. Else: Count the number of in-degree == 0 nodes and also the out-degree=0 nodes. The max of both is the is the result. <br/>
    
   To see that this is a lower bound is easy. That its also a upper bound more complex. See [stack-overflow](https://stackoverflow.com/questions/14305236/minimal-addition-to-strongly-connected-graph), [codeforces](https://codeforces.com/blog/entry/15102).




</br>
</br>
</br>
</br>
</br>

<a name="articulation"/>

## 2.9 Articulation Points/Bridges

An Articulation Point is a vertix whose removal **disconnects the undirected graph**. Thus it can't be a leaf, but only intermediate vertixes.
Similarly Ariculation Bridges disconnects the graph, when the edge (or bridge) is removed.
Note some variants also come with directed graphs, but usually it applies only to **undirected** graphs. This algorithm runs in <img src="https://render.githubusercontent.com/render/math?math=O(V %2B E)">.

Idea: Similar to tarjan-algorithm to get all SSC, we have a `dfs_low` array, and each children vertex, tries to minmise it using all adj-vertex, but its parent-vertex. When now this low value us lower than the `dfs_num` value of the parent we have found another way.
```
enum {UNVISITED=-1};
vector<int> dfs_low, dfs_num, parent;
vector<pii> bridges;
vector<bool> is_articulation;
int dfs_idx, root, root_children;

void dfs(int cur, vector<vector<int>> &AL){ // O(V+E)
    dfs_num[cur] = dfs_low[cur] = dfs_idx++;
    for(int next: AL[cur]){
        if(dfs_num[next] == UNVISITED){
            parent[next] = cur;
            if(root == cur) root_children++; // only need for articulation points
            dfs(next, AL);
            if(dfs_low[next] > dfs_num[cur]){ 
                // bc of bridges here strictly greater
                bridges.push_back({next, cur});
            }
            if(dfs_low[next] >= dfs_num[cur]){ 
                // for points greater/equal
                is_articulation[cur] = true;
            }
            
            dfs_low[cur] = min(dfs_low[cur], dfs_low[next]);
        }else{
            if(parent[cur] != next){
                dfs_low[cur] = min(dfs_low[cur], dfs_num[next]); // compare with dfs_num of next, otherwise it would set it too low
            }
        }
    }
}
// in main
int n = 100;
dfs_low.assign(n, UNVISITED);
dfs_num.assign(n, UNVISITED);
parent.assign(n, UNVISITED);
is_articulation.assign(n, false);
dfs_idx = 0;
root = 0; // or set to which is root
root_children = 0;
if(root_children>1){
    is_artiuclation[root] = true;
}
```



</br>
</br>
</br>
</br>
</br>

<a name="maxflow"/>

## 2.10 Maxflow and Mincut

Given a weighted directed graph as pipeline network, then </br>
**Edges**: Pipe with given capacity</br>
**Vertices**: Splitting point</br>
**2 Special vertices**: Source s and sink t</br>


**Question**: What is the max-flow/min-cut through the network from s to t?

### Set up the Residual-Graph

**Forward edge**: Normal directed edge as a given pipeline</br>
**Backward edge** (to cancel out incorrect forward flows): each backward edge has capacity 0 at the beginning, when choosing a forward edge,
then the forward edge has +flow, and its corresponding residual edge -flow</br>
**Residual Graph**: All edges in the network which still have flow < capacity </br>

### Maxflow Algorithms

1. Ford-Fulerson Method <img src="https://render.githubusercontent.com/render/math?math=O(\text{Maxflow} E)">: A potential bottleneck with capacity of 1 is used all the time (back and forth with forward and residual graph)
2. Edmonds-Karp Algorithm <img src="https://render.githubusercontent.com/render/math?math=O(V E^2)">
3. **Dinic’s Algorithm** <img src="https://render.githubusercontent.com/render/math?math=O(V^2 E)">
4. Push-Relabel Algorithm <img src="https://render.githubusercontent.com/render/math?math=O(V^3)">, on dense graphs theoretically faster than Dinic, but Dinic is good enough for all Network problems.


Algorithm Edmonds-Karp and Dinic
Run BFS to create level graph:
  - The L-level Graph stops after L iterations
  - The Edmonds-Karp algorithm: uses this graph to only augment one s-t path (if found)
  - The Dinic algorithm: sends a blocking flow, to augment all possible s-t paths

Problems to solve with Network-Flow
Often Problem are disguised and the difficulty is to see the max-flow behind it and model it accordingly

### When to use
1. Normal **MaxFlow** problems (check max bandwith)
2. Unweighted Maximum Cardinality Bipartite Matching (**UMCBM**, The easiest kind of matching)
   1. It can be shown that on bipartite Graphs, the algorithm has only <img src="https://render.githubusercontent.com/render/math?math=O(\sqrt{V})"> phases,
      thus comes with a complexity <img src="https://render.githubusercontent.com/render/math?math=O(\sqrt{V} E)">
3. **Assignment Problem** </br>
   Example: Emeis are thirsty between a and b, but at time x only 2 emeis can drink at a lake. Assign emeis to the lake.
4. **Min-cut** </br>
   Example: [kattis - thekingofthenorth](https://open.kattis.com/problems/thekingofthenorth). Defend your ground with as few soldiers as possible.
6. **Ad-hoc** problems


### Possible Difficulties: 

1. **Vertex Capacity** (add another node after that node and add edge with capacity)
2. **Back-Coupling** (time, add sum-up nodes for current and previous not used flows, see kattis_jupiter)
3. Blowing verteces up to consider **time**
4. **Extract** how many **edges** are used, or the flow within each edge (`get_used_forward_edges(node)` and `get_used_backward_edges(node)`); this is particular useful in assignment problems.
5. Get the **partition of the min_cut** (left and right side; for left side use (`getLeftMinCut(0)`): Do a dfs from sink and only pass through residual edges (not saturated edge)
6. Get **max. Independent Paths**: Each vertex can only be used once (use vertex capacity = 1), this implies disjoint paths.
7. Get **max. Disjoint Paths**: Use each edge only once. 

### Note

Often you need to work with many offsets. Better save them as a variable
```
MaxFlow maxFlow = MaxFlow(2 + sites + people);
int offsetSites = 1;
int offsetPeople = sites+1;
int sink = 2+sites+people -1;

// add edges...

long long flow = maxFlow.dinic(0, sink);
```



</br>
</br>
</br>
</br>
</br>

<a name="augmenting"/>

## 2.11 Basic Augmenting

For Basic **Unweighted Maximum Cardinality Bipartite Matching** (UMCBM) a basic augmenting algorithm in <img src="https://render.githubusercontent.com/render/math?math=O(VE)"> often is also ok instead of the dinic in <img src="https://render.githubusercontent.com/render/math?math=O(\sqrt{V} E)">.
```
vector<int> matchR, visitedL;
bool aum(int LEFT, vector<vector<int>> &al){
    if(visitedL[LEFT]) return false;
    visitedL[LEFT] = 1;
    for(int RIGHT: al[LEFT]){
        if(matchR[RIGHT] == -1  || aum(matchR[RIGHT], al)){
            matchR[RIGHT] = LEFT;
            return true; //current can be matched
        }
    }
    return false; // current cannot be matched
}
```

And in main:
```
matchR.assign(m, -1);
int ret = 0;
FOR(i, n){
    visitedL.assign(n, 0);
    ret+=aum(i, al);
}

```

</br>
</br>
</br>
</br>
</br>
<a name="dds"/>

# 4 Dynammic Datastructures

Until now, we have mainly seen static problems, so for example given an array of numbers, we need a quick way to calculate the sum from the index `i` to index `j` (prefix sum). When dealing with dynammic data, i. e. data which is modified continuously, we want to avoid to linearly recalculate the array.

<a name="fwt"/>

## 4.1 Binary-Index-Tree or Fenwick-Tree
<img align="right" width="640" alt="Fenwick-Tree(https://ioinformatics.org/journal/v9_2015_39_44.pdf)" src="https://user-images.githubusercontent.com/44442845/151425400-974740f4-9141-4f2f-9a8c-3eadbb20840a.png">

The Fenewick-Tree is a quick-to-type datastructure and in particular good for point update and range queries (PURQ). As a requirement, the operation needs to be inversable (sum): `range_query_from_left(j) - range_query_from_left(i-1);`. Given an array of length `n`, our datastructure has `n+1` nodes (0 is dummy variable) and each node `i` saves the result for the segment `[(i-LSOne(i) + 1),...,i]`. The building of the array needs <img src="https://render.githubusercontent.com/render/math?math=O(n \log n)">, and each update or sum query  <img src="https://render.githubusercontent.com/render/math?math=O(\log n)">.


```

// Least secnificant bit
#define LSOne(S) ((S) & -(S))


class PURQ {
private:
    vector<long long> ft;
public:
    PURQ(int n) { // without leading 0
        ft.assign(n+1, 0); // idx 0 is bound, no value asigned to it
    }
    PURQ(vi &vals){
        build(vals);
    }
    // builds in O(n), as oposed to O(n*logn)
    void build(vector<long long> vals){ // vals idx are keys of Fenwick-tree -> first in vector needs to be 0:
        int n = vals.size();
        ft.assign(n, 0);
        for(int i=0;i<n; i++){
            ft[i] += vals[i];
            if(i+LSOne(i)<n){
                ft[i+LSOne(i)] += ft[i];
            }
        }
    }
    // 1-based index
    long long range_query_from_left(int j){ // interval [1,...,j]
        assert(j>=0 && j < ft.size());
        long long ret = 0;
        while(j!=0){
            ret += ft[j];
            j-=LSOne(j);
        }
        return ret;
    }
    // 1-based index
    long long range_query(int i, int j){ // interval [i,...,j]
        assert(j>=i && j < ft.size());
        assert(i>=0 && i < ft.size());
        return range_query_from_left(j) - range_query_from_left(i-1);
    }
    // 1-based index
    void point_update(int i, int val){
        assert(i>0 && i < ft.size());
        while(i < ft.size()){
            ft[i]+=val;
            i += LSOne(i);
        }
    }
};

//vector<long long> test{0,1,1};
//PURQ fw = PURQ(test); 
//fw.range_query(1, 2);

```

Also note, that this data-structure also supports, Range-Updates with Point-Queries (RUPQ) as well as Range-Updates with Range-Queries (RURQ). The implementation is [here](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/fenwick.cpp). Moreover, we can also implement a **2D Fenwick-Tree**, where we normally would use 2D Prefix-Sums or kadane; an implementation can be found [here]([here](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/fenwick2D.cpp))


</br>
</br>
</br>
</br>
</br>
<a name="ost"/>

## 4.2 Order Statistic Tree
Order Statistic Tree (**OST**) is a balanced BST, which also saves the size of each subtree. 
This datastructure can be used to answer order-related queries like "what it the k-th smallest elment?" on dynammic data in  <img src="https://render.githubusercontent.com/render/math?math=O(\log n)"> time (as we have to find the specific node first in <img src="https://render.githubusercontent.com/render/math?math=O(\log n)">). As we are dealing with an balanced BST we also need <img src="https://render.githubusercontent.com/render/math?math=O(\log n)"> for inserting. C++ users are lucky and have have this out of the box:

```
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// To use ordered use ordered_multiset<type>S something like this

//int x=1;
//ost<ll> tree;
//tree.insert(x);
//ll low=tree.order_of_key(x); // this is not possible with normal multiset. There you must have use distance(s.begin(), iterator), which takes O(n);
//tree.lower_bound(x)
//ll secondSmallest = *tree.find_by_order(1); 
 ```

When using it as a **multiset** (and allow the same value several times), we have to take the operator `less_equal`. However, this comes with some pitfalls as well:

`find` will always return end. </br>
`lower_bound` works like upper_bound in normal set (to return the first element > it)</br>
`upper_bound` works like lower_bound in normal set (to return the first element >= it)</br>
`order_of_key(x)` will get you the order of the first key==x (even though this key might be available by many orders)</br>
`find_by_order(x)` works as expected</br>
`erase` by value does not work anymore. Use `t.erase(t.upper_bound(1))`</br>


Instead of using an OST, we could also rely on the **BIT/Fenwick** to to order-related queries. If we have an elment `a`, we just add +1 to it and now, we can query, the sum to a specific answer, getting the number of elements before it. However, **often an OST is prefable**, as it is not restricted to low numbers (roughly 1M), but its tree can have anthing which is sortable (e.g. strings).


</br>
</br>
</br>
</br>
</br>
<a name="st"/>

## 4.3 Segment-Tree 

Within a Segment-Tree (ST) the operatin does **not need to be inversable** and thus, a ST is more powerful than a BIT/Fenwick. Moreover, it is a good choice, when the operation and states are a bit more complicated. ST use slightly more memory (we need up to 4t imes the space of the initial array). Similar to BIT, it takes <img src="https://render.githubusercontent.com/render/math?math=O(4n)"> for the building, and update-call or query-call <img src="https://render.githubusercontent.com/render/math?math=O(\log n)">.


The problems often comes in the form of **two functions**. For the update-function, **changes a range/point of our initial numbers**. `update(idx, idx2 val)` and the  **query-function** calculates the **sum of a given range** `query(idxLeft, idxRight)`. Note any **associative** function (it doesn't matter which operation is done first) can be used instad of the sum-operation, e.g. minimum, maximum, multiplication (also modulo), matrix-multiplication (associative but not commutative, i.e. multiplication form left and right are differnt), bitwise operations (`&`, `|`, `^`) or GCD (which doesn't run in O(1), so it will change the overall complexity).


The idea is that each node within the ST is in charge of a segment `L` to `R`. When quering or updating, we give a range `i` to `j`, and we go down the tree, trying find nodes, which are fully captured by this range and directly update or return.
With **Lazy Propagation** we can go for efficient (log n) range updates as well. The reasoning is, that ones we are at a node, which is fully captured, we set a lazy flag and stop here. Only the time, when we really need to go deeper, we will take this lazy-value and also compute the up-to-date values for the children.
Figuratively, we can say, that old operations are further down in the root tree, while new ones are up. Each time we visit a node, we **propagate it's lazy flag furhter down**. Take into consideration, that for the lazy propagation to work, you might need to **merge lazy-flags**, if the kid already has one.

To apply lazy-propagation, and stop at an inner node, the **update function needs to be distributive relative to the query-function**.
E.g. When having the update function <img src="https://render.githubusercontent.com/render/math?math=\odot"> (e.g. assigning a value or adding a value), we don't need to recurse to the children, but instead just use their old intermediate values: 
<img src="https://render.githubusercontent.com/render/math?math=\text{query}(a \odot x, b \odot x) = \text{query}(a, b) \odot x">


**Distributive** are for example:
- multiplication relative to sum-query
- bitwise AND relative to bitwise OR-query
- Addition relative to max- or min-query
- Assignment relative to max- or mi-query

**Non-distribute** are:
- Addition relative to sum-query
- Assignment relative to sum-query

Note, we we can still gor for lazy-propagation if we are smart about the implementation (e.g. use the length of a segment)

```
class ST{
private:
    // TODO: you need to change these functions+neutrals
    ll NEUTRAL_QUERY = 1ll << 60;
    ll NEUTRAL_UPDATE = 0;
    // Segment-tree consists of two operations, update and query:
    ll conqQuery(ll a, ll b){
        // min query
        return min(a, b);
    }
    // If update function is not distributive, you might need to think a little and update lazy[..] and st[..] differntly
    ll conqUpdate(ll prev, ll op){
        // add modifing
        return prev + op;
    }


    ll n;
    vector<ll> st, lazy;
    ll l(ll p){return p<<1;}
    ll r(ll p){return (p<<1) +1;}

    // only needs O(n), as it just visits all nodes only once
    void build(ll p, ll L, ll R, const vector<ll> &init){
        if (L == R){
            st[p] = init[L];
        } else{
            ll m = (L+R)/2;
            build(l(p), L, m, init);
            build(r(p), m+1, R, init);
            st[p] = conqQuery(st[l(p)], st[r(p)]);
        }
    }

    void propagate(ll p, ll L, ll R){
        // TODO: check if works (distributive law still holds)
        st[p] = conqUpdate(st[p], lazy[p]);
        if(L!=R){
            lazy[l(p)] = conqUpdate(lazy[l(p)], lazy[p]);
            lazy[r(p)] = conqUpdate(lazy[r(p)], lazy[p]);
        }
        lazy[p] = NEUTRAL_UPDATE;
    }

    void update(ll p, ll L, ll R, ll i, ll j, ll val){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return;
        if(L>=i && R<=j){
            st[p] = conqUpdate(st[p], val);
            if(L != R){
                lazy[l(p)] = conqUpdate(lazy[l(p)], val);
                lazy[r(p)] = conqUpdate(lazy[r(p)], val);
            }
        } else{
            ll m = (L+R)/2;
            update(l(p), L, m, i, j, val);
            update(r(p), m+1, R, i, j, val);
            st[p] = conqQuery(st[l(p)], st[r(p)]);

        }
    }


    ll query(ll p, ll L, ll R, ll i, ll j){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return NEUTRAL_QUERY;
        if(i<=L && j>=R){
            return st[p];
        }
        ll m = (L+R)/2;
        return conqQuery(query(l(p), L, m, i, j), query(r(p), m+1, R, i, j));
    }
public:
    ST(ll size) : n(size) {
        st.assign(4*size, NEUTRAL_QUERY); // 4 = 2*2. First 2: to make n a factor of two [actualy 2 * upper(log_2(n))], and second 2 for the inner nodes of the tree
        lazy.assign(4*n, NEUTRAL_UPDATE);
    }
    ST(const vector<ll> &initA): ST(initA.size()) {
        build(1, 0, n-1, initA);
    } 
    // All idx's i,j from 0 to n-1
    // range update, for point update set i == j
    void update(ll i, ll j, ll val) {
        // updates [i,..j]
        update(1, 0, n-1, i, j, val);
    }
    ll query(ll i, ll j){
        // queries [i,..j]
        return query(1, 0, n-1, i, j);
    }
};


//vi nums{0, 1, 2, 3, 4, 5};
//ST st(nums);
//cout << st.query(0, 2) << endl; // 0
//st.update(0, 3, 10); // add 10 to each
//cout << st.query(0, 2) << endl; // 10
//cout << st.query(3, 3) << endl; // 13
//cout << st.query(3, 4) << endl; // 4
```

This normal implementation works with `NEUTRAL_UPDATE` and `NEUTRAL_QUERY`. However some operation, like assignment do not have a neutral, then, we need a dummy, or a value out of range.

When the **states are more complicated** it is useful to implement a `struct Node`. This also allows for defining `operator +`, for more see [here](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/st_node.cpp).
```
struct Node{
    ll val;
    bool invalid=false;
    Node(){}
    Node(ll _val){
        val = _val;
    }
    Node operator+(const Node &right) const{
        if(invalid) return right;
        if(right.invalid) return *this;
        Node x;
        x.val = val+right.val;
        return x;
    }
};
```

Also note, sometimes, the **memory pressure** is very high and we cannot even initaliase the ST in time. Then a **Sparse-Segmente-Tree** could be favoured. Instead of allocating the memory for all potential segments, we only create them on the fly (Pointer-like construction here). A potential implementation is [here](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/sparse_st.cpp).

When having **2 Dimensions** and each node of the first dimension contains another ST. The implementaion is a bit tedious and also we **cannot use lazy propagation** thus only have point-updates at our disposal. An implementation for a **2D-Segment-Tree** can be found [here](www.google.de).
Building takes <img src="https://render.githubusercontent.com/render/math?math=O(n \cdot m)">, while quering/updating takes <img src="https://render.githubusercontent.com/render/math?math=O(\log n \cdot \log m)">. As an alternative, we could use a **quadtree** is a tree, in which each inner node has 4 children. This helps to divide the 2D-grid recursively into north-east, north-west, south-easth and south-west, such that each node can decide what to do with values of its children. Note that the runtime of the quadtree is worse than of a 2D-Segment-Tree.



</br>
</br>
</br>
</br>
</br>
<a name="dp"/>

# 4 Dynammic Programming


### Variants:
1. **Top-Down**:
    - Pro: natural way of thinking (like Backtracking)
    - Pro: A subproblem will only be computed when needed
    - Pro: When a DAG is given (difficult to find a proper travser order with bottom-up)
    - Con: Slower than Bottom-up when we need all subproblems
2. **Bottom-Up**:
    - Pro: Faster when all subproblems are needed
    - Pro: Memory saving technique (get rid of one Dimension)
    - Con: Also not needed states will be computed


**Requirements:**
1. **Optimal Substructure**: You can break down the given problem into a smaller subproblem; This then needs to be solved optimal.
2. **Overlapping SubProblems**: The main advantage (over Backtracking) is that DP saves sates and therfore we do not need to recalculate subproblems.


Syntactic sugar (**memoization**) for Top-Down pattern:
```
int dp(int state1, state2){
  // check base cases
  int &ans = memo[state1][state2];
  if(ans != 0) return ans;
  // else ... ans = ...
}
```

### Retrieve Solution
Often it is not only asked to compute the optimum, but also to retrieve the exact soltution.

**Bottom-Up Example**
For example start in the last element and backtrack to the first element and only go an optimum way.
```
  for(int i=n; i>0; --i){
      if(weight >= nums[i-1].second && ((dp[i-1][weight - nums[i-1].second] + nums[i-1].first)   ==  dp[i][weight])){
          ret.push_back(i-1);
          weight -=  nums[i-1].second;
      }

  }
```
**Tod-Down Example**
Just copy the dp function and if the next recurstion (plus some addons) is equal the memo value at this current point, then go there.
```
void retrieve(int cur, int last, int toGo, vector<int> &rest, vector<int>& idx){
    if(toGo < 0 || cur  == rest.size()) return;
    int &ans = last == memo[cur][last][toGo];
    int pot = dp(cur + 1, last, toGo, rest);
    if(pot == ans ) return retrieve(cur+1, last, toGo, rest, idx);
    idx.push_back(cur);
    return retrieve(cur+1, cur, toGo-1, rest, idx);
}
```



### Classical Types:

- **Kadane and Prefix-Sums**
  1. **1D-Sum**
  Given an Array A, find the subarray (continues elements), which summed up will lead to the maximal possible number.
  The naive Approach would try all O(n^2) possibilites.
  Kadane only needs a linear scan O(n): We sum up a current counter (`curSum`) and each time it falls below 0, we reset to 0, as now its better to start again.
  Note, this is bottom-up DP but with dimension-reduction. You could also have an array `dp` of lenght n, in which `dp[i]` stands for the best result up to index i.
  ```
  int curSum = 0, overallSum =0;
  for(int i=0; i<n; ++i){
      curSum += nums[i];
      curSum = max(curSum, 0);
      overallSum = max(overallSum, curSum);
  }
  ```
    
  2. **2D-Sum or ND-Sum** 1D-Sum can be expanded to 2D-Sum or even further. To do so, calculate prefix sum for all dimensions but the last.
     Now, for all possible field sizes of the first n-1 dimensions, calculate a separate Kadane within the last dimension.
     For example, for the 2D-Sum, precalculate the prefixsum for each row and then Kadane for each colum combination over the rows.
     For 2D you get the **maximal sum of a submatrix** in O(n^3). This submatrix is of **variable size**.
     If we would instead precalculate **2D prefix-sum**, we would end up with O(n^4), as for each cell we still need to investigate O(n^2) potential submatrices.
     However, sometimes the **window-size is fixed**, we don't need need kadane and can check the few possible windows with 2D prefix-sum. 
     Don't forget the **inclusion-exclusion-principle** when calculating 2D prefix-sums.
     
     **2D-sum Kadane** O(n*m), maximal sum of submatrix of any size:
     ```
     // calculate prefix sum for each row
     for(int i=0; i<n; ++i){
         int rowSum = 0;
         for(int j=0; j<m; ++j){
            rowSum += grid[i][j];
            grid[i][j] = rowSum;
         }
     }
     for(int left_col =0; left_col<m; ++left_col){
          for(int right_col =i; right_col<m; ++right_col){
              // do Kadana over rows:
              int curSum = 0;
              int overallSum = 0;
              for(int i=0; i<n; ++i){
                  if(l>0){
                      curSum += grid[i][right_col] - grid[i][left_col-1];
                  }else{
                      curSum += grid[i][right_col];
                  }
              }
              curSum = max(curSum, 0);
              overallSum = max(overallSum, curSum);
          }
     }
     ```
     **2D Prefix-Sum** better for fixed window sized or as requirement to do 3D Kadane:
     ```
     for(int i=0; i<n; ++i){
        int rowSum = 0;
        for(int j=0; j<m; ++j){
            rowSum += grid[i][j];
            grid[i][j] = rowSum;
            if(i>0){
                grid[i][j] += grid[i-1][j];
            }
        }
     }
     ```
- **Longest Increasing Subsequence** (LIS)

    Let A be an array of integers. The LIS can be found with **DP** in <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">. <br/>
    dp[i] := The length of the longest increasing subsequence, which is ending on i.
    ```
    int dp[n];
    memset(dp, 1, sizeof dp);
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(A[j]<A[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
    }
    ```
    Often better solution: **Greedy + Divide & Conquer** in <img src="https://render.githubusercontent.com/render/math?math=O(n \log k)">, where k is the length of the LIS.
    ```
    vector<int> LIS(n), par(-1, n), LIS_id(n);
    int k=0, idxEnd=0;
    for(int i=0; i<n; ++i){
        int pos = lower_bound(LIS.begin(), LIS.begin()+k, A[i]) - LIS.begin();
        if(pos == k){
            k++;
            idxEnd = i;
        }
        LIS[pos] = A[i];
        LIS_id[pos] = i; // only as help for the parent vector par
        if(pos > 0){
            par[i] = LIS_id[pos - 1];
        }
    }

    vector<int> ret; // ret contains the LIS (but reversed)
    for(int i=0; i<k; ++k){
        ret.push_back(A[idxEnd]);
        idxEnd = par[idxEnd];
    }
    ```
    Note:
    - Use `upper_bound` instead of `lower_bound` if **not strictly increasing**. Then you will replace the first larger element with you current element and not the same element
    - **LDS** (decreasing version) can be computed in two ways:
      - Reverse the Array A and then do LIS
      - Change the way you compare: `int pos = lower_bound(LIS.begin(), LIS.begin()+k, A[i], ::greater<int>()) - LIS.begin();` This will give the first element in LDS, which is equal or smaller. Recap, in LDS, you want to keep the values large as long (and early) as possible, such that you have more chances to add new elements.
    - Sometimes the **greedy version is not possible**. For example in [UVa11790 - Muricia's Skyline](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2890), you want the max. Number of increasing buildings, but you measure with the **width**.  Then you can greedily exchange a taller building with a smaller one, because the taller might be more useful in terms of weights.
    - Often there are **2D LIS**, like in [UVa_01196 - Tiling Up Blocks](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3637), [kattis - manhattanmornings](https://open.kattis.com/problems/manhattanmornings) or [kattis - nesteddolls](https://open.kattis.com/problems/nesteddolls). The basic idea here is **sort** the elements in **ascending order for the first dimension** and then for **the second**. If the requirment is given, that the LIS needs to be strictly increasing, then the second dimension needs to be sorted descending (you don't want that theses are building on top of each other). When you now go through the elements, then you know, that all preprocessed have a lower first dimension and you don't need to worry about that. Only you need to LIS in the second dimension.
- **Knapsack or Subset Sum**

  Pseudo-polynomial DP solution in <img src="https://render.githubusercontent.com/render/math?math=O(nw)">, where n is the number of items and w the maximal capacity of the backpack. `dp[i][j]` then describes the **maximal value** you can get **after** you have processed the **first i items and using j weight**. <br/>
**Boolean Subset-Sum**: Is there a subset of a set of numbers, which sumed up is equal to a given value t?
  
  Note: 
    - You can often **reduce the first dimension**. 
      However, if you need to **reconstruct the actual solution**, then, you need it, as you have to backtrack throught the table. Or use **Parent**-Array.
      Recap, that you then need, to go from right to left, in order to not double count. 
    - **Infinit Knapsack**. When each element can be used infinite times, than just for each item, go from left to right `dp[j] = max(dp[j], dp[j-w]+v)`.
    - Restricted Usage. If you can only use m<=n items, add an additonal state


  **Standard Knapsack**

  ```
  vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
  vector<pii> nums;      
  for(int i=1; i<=n; ++i){
      int v = nums[i-1].first;
      int w = nums[i-1].second;
      for(int j=c; j>=0; j--){
          dp[i][j] = dp[i-1][j]; // might be optimal to skip current
          if(j>=w){
              dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v); // or take it
          }
      }
  }
  ```
  
- **Coin Change**

  Very similar to Knapsack, but instead of maximising the value, we want either **minimise the used coins** or we want to **count the possiblities** to give a certain amount in different coins. <br/>
  **Minimise Used Coins:** <br/>
  `dp[i][j]` denotes the min. number of coins used to get to the value j by using up to the first i coins. Set the dp to 0 and only set `dp[0][0] = 1`. <br/>
  **Count the possibities:** <br/>
  `dp[i][j]` denotes the number of possibilities to give the value j by using up to the first i coins. Set the dp to INF and only set `dp[0][0] = 0`. Then just add up possibilities. <br/>
  **Check if possible:** <br/>
  `dp[i][j]` denotes whether its possible to give the value j by using up to the first i coins. <br/>
        
        

- **Traveling Salesman Person and Hamiltonian Paths**

    **Hamiltonian Cycle Problem (HCP)**  Find a path, such that you visit each node exactly once and end up in the initial Position. NP-Complete (If you would    use DFS, in a fully connected graph you have O(n^n). With DP we save the stats `cur` and `mask` and achieve a complexity of <img src="https://render.githubusercontent.com/render/math?math=O(2n \cdot n^2)">.

    Analogously, a **hamiltonian path** is np-complete. Difference: No need to return to initial position.

    **Traveling Salesman Problem (TSP)** about finding the lowest-cost Hamiltonian Cycle.
Top-Down (Held-Karp-Algortithm):
parameter: n nodes (current node) and bitmask over the next (n-1) to visit
    ```
    int dp(int last, int mask, vector<pii> &coords){
        int &ans = memo[last][mask];
        if(ans != -1) return ans;
        if(mask == 0){
            return cost(0, last, coords);
        }
        ans = INF;
        int m = mask;
        while(m){
            int v = LSOne(m);
            int next = __builtin_ctz(v) + 1;
            m ^= v;
            ans = min(ans, dp(next, mask^v, coords) + cost(last, next, coords));
        }
        return ans;
    }

    ```
    Note, it is very hard to iterate through bitmask in a Bottom-Up manner (first only the ones with one bit set, all numbers with two bits set...) <br/>
    Also note, that the current node also contains the start node, while the bit mask does not. Thus, you have to offset +1 when getting the next node from the bitmask. This reduces the number of states by half.



</br>
</br>
</br>
</br>
</br>


<a name="string"/>

# 5 String Processing

Find **all positions** of a substring a string:
```
vector<int> indices;
int pos = 0;
pos = result.find("love", 0); // O(n*m) where n is length of result and m length of query(here: "love")
while(pos != string::npos){
    indices.push_back(pos);
    pos = result.find("love", pos+1);
}
```

**Standard** string processing functions:
```
str[i] = tolower(str[i]); // or toupper
bool checkDigit = isdigit(result[i]);
bool checkAlpha = isalpha(result[i]);

bool isVowel(char x){
    char vowel[6]="aeiou";
    for(int i=0; i<6; ++i){
        if(x == vowel[i])return true;
    }
    return false;
}
```
**Tokenize** a String with a given delimiter with `str.find_first_of(delimiters, start)`:
```
int current, next = -1;
vector<string> separatedWords;
string delimiters = ", ";
do
{
    current = next + 1;
    next = result.find_first_of( delimiters, current );
    string token =  result.substr( current, next - current );
    if(token != ""){
        separatedWords.push_back(token);
        cout << token << endl;
    }
}while (next != string::npos);
```

</br>
</br>
</br>
</br>
</br>


<a name="kmp"/>

## 5.1 KMP

**Substring-Matching**: When searching for a substring p in text t, the naive way would take <img src="https://render.githubusercontent.com/render/math?math=O(nm)">, where n is the length of the text and m the length of t. A faster way offers the KMP algorithm in <img src="https://render.githubusercontent.com/render/math?math=O(n %2B m)">.

Whenever there is a mismatch, it uses pre-gathered information on whether the last characters are also a prefix to try to continue on that prefix.
```
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
```

</br>
</br>
</br>
</br>
</br>


<a name="trie"/>

## 5.2 Suffix-Trie

**Substring-Matching**: With a suffix-Trie you can match subsrings in <img src="https://render.githubusercontent.com/render/math?math=O(m)">, after the prepocessing of <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">, in which we insert all suffixes of the word into the trie.

A more sophisticated version would be the **suffix-tree**, which compresses paths if they do not branch.

**Longes Common Repeated Substring** in O(vertices): <br/>
In suffix-tree: The deepest inner vertix is the answer (the path towards it) <br/>
In suffix-trie: The deepest inner vertix is the answer, with more than one branche (when using an aditional terminal symbol)<br/>


**Longes Common Substring** in O(Vertices)<br/>
Insert two words (all its suffixes) and add different terminal symbol, then dfs and mark all inner nodes which have both terminal symbols in their respective subtree


```
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
```



</br>
</br>
</br>
</br>
</br>


<a name="else"/>

# 6 Else

<a name="convolution"/>

## 6.1 Convolution

Let A and B be polynomials of degree n.
With Fast-Fourir-Transformation (FFT), the **multiplication of polynomials** A and B can be solved in <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))"> instead of <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">.


**Naive Code** in <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">:
```
for(int j=0; j<=n; ++j){
    for(int k=0; k<=n; ++k){
	res[j+k] += A[j] * B[k];
    }
}
```

**Better Idea** in <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))">:
1. Convert polynoms to point-value (degree n polynom needs n+1 distrinct points) representation  <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))">) by FFT)
2. Do polynomial multiplication in point-value representation (<img src="https://render.githubusercontent.com/render/math?math=O(n)">)
3. Convert back to coefficient representation. (<img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))"> by inversed FFT)



### FFT-Intuition

Given A, a vector of coefficents, FFT will evaluate the polynomial at n + 1 (`A.size()`) different positions in place.

To evaluate the Ploynom at the position x, use D&C:
<img src="https://render.githubusercontent.com/render/math?math=A(x) = A_0(x^2) %2B x \cdot A_1(x^2)"> ,where
<img src="https://render.githubusercontent.com/render/math?math=A_0"> is the polynom of all the even indicies of A,
and <img src="https://render.githubusercontent.com/render/math?math=A_1"> all the odds. Note, you need bit-reversal order for iterating through <img src="https://render.githubusercontent.com/render/math?math=A_0"> first and then <img src="https://render.githubusercontent.com/render/math?math=A_1">.

<img src="https://render.githubusercontent.com/render/math?math=A(x) = (a_0, a_1,a_2, \ldots, a_n) = a_0 %2B a_1x^1 %2B a_2x^2 %2B \ldots %2B a_nx^n"> <br/>
<img src="https://render.githubusercontent.com/render/math?math=A_0(x) = (a_0, a_2, a_4 \ldots) = a_0 %2B a_2x^1 %2B a_4x^2 %2B \ldots"> <br/>
<img src="https://render.githubusercontent.com/render/math?math=A_1(x) = (a_1, a_3, a_5 \ldots) = a_1 %2B a_3x^1 %2B a_5x^2 %2B \ldots">

Fast way: Use the nth-root, as the the square of the n-th root of unity can complety be reduced to the the n/2-root of unity. <br/>
All n-th roots are give by: <img src="https://render.githubusercontent.com/render/math?math=e^{i2\pi k/n} = \cos(2 \pi k/n) %2B i \sin(2 \pi k/n) \:\: \forall k \in \{0, 1, \ldots, n-1\}"> <br/>

Note:
1. A is always halved, at each iterations (due to D&C)
2. Choosing x smart (take all n-th root elements), we can retrieve all n values for A from <img src="https://render.githubusercontent.com/render/math?math=A_0"> and <img src="https://render.githubusercontent.com/render/math?math=A_1"> in one go and do not need to calculate them for each value x again (collapsing property of the n-th root of unity). 


In a nutshell, we calculate y in <img src="https://render.githubusercontent.com/render/math?math=WA = y">, given W and A, 
where W is a nxn matrix, with <img src="https://render.githubusercontent.com/render/math?math=w_{k,j} = e^{i2\pi k/n \cdot j} \:\:  \forall k,j \in \{0, 1, \ldots, n-1\} "> all elements
from the n-th root and their exponentials. The collapsing-property can now be written as <img src="https://render.githubusercontent.com/render/math?math=w_{2k, n} = w_{k, n/2}">.

**Putting things togther**:<br/>
Suppose, we have already the subproblems <img src="https://render.githubusercontent.com/render/math?math=Y_0[k] = A_0(w_{k, n/2})">
and <img src="https://render.githubusercontent.com/render/math?math=Y_1[k] = A_1(w_{k, n/2}), k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">,
both vectors of length n/2. We have to combine them, to calculate Y.

First half for all <img src="https://render.githubusercontent.com/render/math?math=k, k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">: <br/>
<img src="https://render.githubusercontent.com/render/math?math=Y[k] = Aw_{k,n} = A_0 w_{2k, n} %2B w_{k,n} \cdot A_1 w_{2k, n} "> <br/>
<img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:= Y_0[k] %2B w_{k,n} \cdot Y_1[k]">

Second half for all <img src="https://render.githubusercontent.com/render/math?math=\frac{n}{2} %2B k, k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">: <br/>
<img src="https://render.githubusercontent.com/render/math?math=Y[k] = Aw_{k,n} = A_0 w_{2k, n} - w_{k,n} \cdot A_1 w_{2k, n} "> <br/>
<img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:= Y_0[k] - w_{k,n} \cdot Y_1[k]">

### Inverse FFT

FFT calcualted n+1 different points, <img src="https://render.githubusercontent.com/render/math?math=WA = y">,
now reverse and calcualte <img src="https://render.githubusercontent.com/render/math?math=W^{-1}Y = A"> for given <img src="https://render.githubusercontent.com/render/math?math=W^{-1}">
and <img src="https://render.githubusercontent.com/render/math?math=Y">.

It can be shown: <img src="https://render.githubusercontent.com/render/math?math=w^{-1}_{k,j} = \frac{1}{n} (1/w_{k, j})">,
in polar coordinates is that just scaling <img src="https://render.githubusercontent.com/render/math?math=(\frac{1}{n})">
and conjugation <img src="https://render.githubusercontent.com/render/math?math=w^{-1}_{k,1} = w_{k,-1} = e^{-i2\pi k/n} = \cos(-2 \pi k/n) %2B i \sin(-2 \pi k/n) = \cos(2 \pi k/n) - i \sin(2 \pi k/n)">

Thus,
<img src="https://render.githubusercontent.com/render/math?math=y_j \cdot e^{-i \Theta} = \overline{\overline{y_j} \cdot e^{i \Theta}}">
```
void IFFT(vector<cd> &Y){
    for(auto &p:Y)p=conj(p);
    FFT(Y);
    for(auto &p:Y)p = conj(p); // conjugate here acutally not neccessary, as we only need real units in our problems
    for(auto &p:Y)p /= Y.size();
}
```

### When to use

Convolution are often hidden, and do not need to come in the form of polynomial-multiplication. In the following we denote * as convolution and thus the sth element is defined as <img src="https://render.githubusercontent.com/render/math?math=(f*g)_s = \sum_{j+k=s} f_j \cdot g_k">.
* **Frequency Convolution (All Possible Sums)** <br/>
Given two arrays of non-negative integers A and B. How many ways are there to get a sum <img src="https://render.githubusercontent.com/render/math?math=y = A_j %2B B_k"> for all possible y? <br/>
Example: <br/>
<img src="https://render.githubusercontent.com/render/math?math=A = \{1, 1, 1, 3, 3, 4\}"> and
<img src="https://render.githubusercontent.com/render/math?math=B = \{1, 1, 2, 3, 3\}">. <br/>
Transform them to frequency array: <br/>
<img src="https://render.githubusercontent.com/render/math?math=f_A = [0, 3, 0, 2, 1]"> and
<img src="https://render.githubusercontent.com/render/math?math=f_B = [0, 2, 1, 2]">. <br/>
Then the convolution <img src="https://render.githubusercontent.com/render/math?math=f_A * f_B = [0, 0, 6, 3, 10, 4, 5, 2] "> gives the possibilities a sum (the index is the sum) can be calculated. <br/> 
 <img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:f_A = [\color{red} 0\color{black}, 3, 0, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, 0, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, \color{green} 0\color{black}, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, \color{green} 0\color{black}, \color{purple} 2\color{black}, 1] \:\:  \ldots">
 <img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:f_B = [\color{red}0\color{black}, 2, 1, 2] \:\:\:\:\:\:\:\: f_B = [\color{blue}0\color{black}, \color{red}2\color{black}, 1, 2] \:\:\:\:\:\:\:\: f_B = [\color{green}0\color{black}, \color{blue}2\color{black}, \color{red}1\color{black}, 2] \:\:\:\:\:\:\:\: f_B = [\color{purple}0\color{black}, \color{green}2\color{black}, \color{blue}1\color{black}, \color{red}2\color{black}] \:\: \ldots">
 
```
vector<ll> multiply(vector<ll> &p1, vector<ll> &p2){ // O(n*log(n))
    int n = 1;
    while(n < p1.size() + p2.size() -1) n <<=1;
    vector<cd> A(p1.begin(), p1.end());
    vector<cd> B(p2.begin(), p2.end());
    A.resize(n);
    B.resize(n);
    FFT(A);
    FFT(B);
    vector<cd> mult(n);
    for(int i=0; i<n; ++i){
        mult[i] = A[i]*B[i];
    }
    IFFT(mult);
    vector<ll>ret;
    for(cd a: mult){
        ret.push_back(round(a.real()));  // rounding might be changed. When dealing with frequencies/integer-values this sould be ok!
    }
    ret.resize(p1.size() + p2.size() -1);
    return ret;
}
```

* **All Dot Products** <br/>
Given two arrays of integers A and B. Determine the dot product of B with all possible contiguous subsequences of A. <br/>
As here the multiplication is not athwart, we need to reverse B, then normal convolution. <br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=f = [5, 7, 2, 2, 3, 6]"> and
<img src="https://render.githubusercontent.com/render/math?math=g = [2, 1, 3, 4]"> and <img src="https://render.githubusercontent.com/render/math?math=\bar{g} = [4, 3, 1, 2]"> the reversed of g.<br/>
Then, <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g} = [20, 43, 34, \textbf{27, 31, 38,} 23, 12, 12]">.

* **Bitstring Alignments** <br/>
Let A and B be bitstrings with <img src="https://render.githubusercontent.com/render/math?math=|A| \ge |B|"> . How many substrings A' of A of length B are there, such that, if <img src="https://render.githubusercontent.com/render/math?math=B_k = 1 \rightarrow A_k^' =1">? <br/>
Reverse B and convolution will give you the alignment score at each index. Add up all 1's in B and if you can find this number in <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g}"> you have a perfect alignment. <br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=f = [1, 1, 0, 1, 1, 1, 1, 0]"> and
<img src="https://render.githubusercontent.com/render/math?math=g = [1, 1, 0, 1]"> and <img src="https://render.githubusercontent.com/render/math?math=\bar{g} = [1, 0, 1, 1]"> the reversed of g.<br/>
Then, <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g} = [1, 1, 1, \textbf{3, 2, 2, 3, 2}, 2, 1, 0]">.

* **Bitstring Matching** <br/>
Same as Bitstring Alignments, but we need to align both 0 and 1. <br/>
Run Alignments <img src="https://render.githubusercontent.com/render/math?math=p=f*\bar{g}"> and then flip both vectors and calculate it again, lets name it q. The alignment score at each index k is given by  <img src="https://render.githubusercontent.com/render/math?math=(p%2Bq)[k]">

* **String Matching** <br/>
More general version of Bitstring Matching. Let A and B be strings, how many times does B appear in A as substring? <br/>
Compute array f: Translate each element from A to a value <img src="https://render.githubusercontent.com/render/math?math=e^{i2\pi k/n}"> with k as encoding of the character <img src="https://render.githubusercontent.com/render/math?math=(a \rightarrow 0, b\rightarrow 1, \ldots, z \rightarrow 25)"> and <img src="https://render.githubusercontent.com/render/math?math=n=25">.
Vice versa calcualte g from B, but use <img src="https://render.githubusercontent.com/render/math?math=e^{-i2\pi k/n}">. As this is again is alignment, reverse g. <br/>
Then, only when two characters are matching, the multiplcation is 1, and else less than 1.
Thus if there is a match, you will find the `B.size()` in <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g}">. Note that other string processing methods like KMP or Rabin-Karp are better, performance-wise.
* **String Matching with Wildcards** <br/>
You can search with wildcards, therefore set the specific value in g to 0 and do not look for the `B.size()` in the convultion, but for `B.size() - numsWildcards`.

* **All Distances** <br/>
Let A be a bitstring, how many ways are to choose i and j, such that, <img src="https://render.githubusercontent.com/render/math?math=A_i = A_j = 1"> and  <img src="https://render.githubusercontent.com/render/math?math=j-i = k">? <br/>
The dot-product of A with itself solves this problem for all possible k, namely:  <img src="https://render.githubusercontent.com/render/math?math=\ldots, -2, -1, 0, 1, 2, \ldots ">. Note the center is then for k=0 and left and right sides are symmetric<br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=A = [1, 0, 1, 1, 1]">
Then, <img src="https://render.githubusercontent.com/render/math?math=A*\bar{A} = [1, 1, 2, 2, 4, 2, 2, 1, 1]">. So there are 4 possible ways to choose p and q, such that the difference is 0, and both are 1.

</br>
</br>
</br>
</br>
</br>

<a name="bit"/>

## 6.2 Bit Manipulation

- Bitwise **not** `~x`: <br/>
  E.g. For 6, which is 110 in binary, ~6 will be 11...11001, which is -5.	
  
- Gettint the **least significant bit** `x&-x` or `x&(~x + 1)`:
  ```
  int LSOne(int num){
      return num & -num;
  }
  ```
  E.g. For 6, which is 110 in binary, it will return 010, which is 2.
  
- **Count trailing zeros**:
  ```
  __builtin_ctz(num);
  ```
  E.g., 8 is 1000, thus `__builtin_ctz(8) = 3`.

# References

<a id="1">[1]</a> 
Halim, Steven et al. (2013). 
Competitive programming 4. 
Citeseer.

<a id="2">[2]</a> 
Laaksonen, Antti (2018). 
Competitive Programmer’s Handbook. 

<a id="3">[3]</a> 
Cormen, Thomas et al. (2009). 
Introduction to algorithms. 
MIT press.

