# Competetive-Programming Excersices
This folder contains problems I solved on online-judge and kattis.
I sorted them according to their classification by Competetive-Programming 4.

The complete list:



|Problem | Category | Solution | idea |
|-|-|-|-|
|[UVa10541 - stripe](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1482)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/UVa10541_stripe.cpp) | First of all subtract from the possible white balls all the balls you already know where they will be (1 in between each black at least). For the rest, you can distribute them freely. Formula to put r elements in k bins: <img src="https://render.githubusercontent.com/render/math?math=\binom{r%2Bk -1}{r}">|
|[UVa11955 - Binomial_Theorem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3106)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/UVa11955_binomial_theorem.cpp) | String processing + Pascals formula for binomial coeficients|
|[UVa12712 - Pattern_Locker](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4450)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/UVa12712_pattern_locker.cpp) | <img src="https://render.githubusercontent.com/render/math?math=\binom{L \cdot L}{i}">, but keep track of permutation: <img src="https://render.githubusercontent.com/render/math?math=(\binom{L \cdot L}{i} \cdot i! = \frac{(L\cdot L)!}{(L\cdot L -i)!}">,  Also derivable via first one has <img src="https://render.githubusercontent.com/render/math?math=(L\cdot L)"> second one <img src="https://render.githubusercontent.com/render/math?math=(L\cdot L -1)"> |
|[kattis - Election](https://open.kattis.com/problems/election)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/kattis_election.cpp) | Pascals formula for binomial coeficients |
|[kattis - Tree Insertion](https://open.kattis.com/problems/insert)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/kattis_insert.cpp) | BST, Post-Order + Pascals formula for binomial coeficients but using bigint as n>66 |
|[kattis - Locked Treasure](https://open.kattis.com/problems/lockedtreasure)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/kattis_locked_treasure.cpp) | For each (m-1)-group, create key and give it to the rest|
|[kattis - Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/kattis_odd_bin_coefs.cpp) | Print Pascals triangle mod 2 and find pattern. Eventually, you need to count all 1 in the upper triangel, up to row n|
|[kattis - Perica](https://open.kattis.com/problems/perica)|Binomial coefficient|[c++](https://github.com/dirkneuhaeuser/algorithms/blob/master/training/combinatorics/bin_coef/kattis_perica.cpp) | Calculate the binomial Coefficient with Modulo: Precalculate the factorials and use mod-inverse|




