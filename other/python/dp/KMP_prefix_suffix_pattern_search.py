def repeatedSubstringPattern(self, s: str) -> bool:
    """
    LC:459. Repeated Substring Pattern
    KMP-Algorithmus: Pattern Matching Substring Search
    I. g. : 
    pattern = dsgwadsgz
    s = adsgwadsxdsgwadsg
    Now at i=1 we observe that we cannot match bc of x, instead of naivly try to match from i=2,
    we can use common prefixes/suffixes of the pattern at this given position:
    dsgwadsgz
    000001230 (if only considered up to last g, the commen pre- and suffix is dsg)
    As the suffix up to this positon has been matched, so has the prefixed and
    we can start at the given index in the table to continue matchign

    Calculate the table: Use two pointer:
    i: assuming that at i ends the string, we want to calculate the length of common prefix and suffix
    j: points to the first element after already checked prefixed
    """
    n = len(s)
    dp = [0] * n

    for i in range(1, n):
        j = dp[i-1]# frist pos after prefix
        while j > 0 and s[i]!=s[j]:
            j = dp[j-1] # next chance
        if s[i] == s[j]:
            j += 1
        dp[i]=j
    prefix = dp[-1]
    # funnyly this is also the answer here
    return prefix != 0 and n%(n-prefix)==0 
