def generateTrees(self, n: int) -> List[TreeNode]:
    '''
    D&C
    '''
    def generate(start, end):
        '''
        provides all perms of the tree, which begins at start and ends in end:
        '''
        if start == end+1:
            return [None]
        ret = []
        for i in range(start, end+1):
            for left in generate(start, i-1):
                for right in generate(i+1, end):
                    node = TreeNode(i, left, right)
                    ret.append(node)
        return ret
    return generate(1,n)
