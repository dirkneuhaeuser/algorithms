def inorderTraversalStack(self, root: TreeNode) -> List[int]:
    '''
    In order using stack: go as far left as possible add value. go to right repeat.
    '''
    ret = []
    stack = []
    while root or len(stack)>0:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        ret.append(root.val)
        root = root.right ## root will set to None if there is no path -> inner while will just pop the next
        
    return ret
