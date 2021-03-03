def generateParenthesis(self, n: int) -> List[str]:
    '''Normally it is used when you are faced with a number of options and you have to choose one option. After your choice you have a new set of options (hence recursion). The procedure is repeated over and over until a final state.
    backtracking:
    1. create ans list
    2. do backtracking and add to ans if youre in a leaf
    
    IMPORTANT:
    REASSIGNMENT of non-local variables: NOT POSSIBLE (unless nonlocal is used)
    USAGE of non-local variables: POSSIBLE (also altering a list entry is possible)
    '''
    ans = []
    def backtrack(s="", l=0, r=0):
        if len(s)==2*n:
            ans.append(s)
        else:
            if l<n:
                backtrack(s+'(',l+1,r)
            if l>r:
                backtrack(s+')',l,r+1)
    backtrack()
    return ans
