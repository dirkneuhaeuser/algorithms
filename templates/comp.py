import math
import sys
from collections import *
from time import sleep 
input = sys.stdin.readline


MOD = int(10**9 + 7)
############ ---- Input Functions ---- ############
def inp():
    return(int(input())) # read int
def inlt():
    return(list(map(int,input().split()))) # read list of int
def insr():
    s = input()
    return(list(s[:len(s) - 1]))  # string -> [chrs]
def invr():
    return(map(int,input().split())) # same as inlt?

t = inp()
ret = []
for i in range(t):
    n, k = inlt()
    l = inlt()
    ls = Counter(l)
    keys = sorted(ls.keys(), reverse=True)
    for key in keys:
        k -= ls[key]
        if k <= 0:
            ret.append(math.comb(ls[key], k+ls[key]) % MOD)
            break

for r in ret:
    print(r)

        


    
