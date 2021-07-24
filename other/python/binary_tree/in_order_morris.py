def inorderTraversalMorris(self, root: TreeNode) -> List[int]:
    '''
    Morris-Traversal restructures Graph according to in-Order traversal.
    For example the root is always after the most right leaf of the left subtree. -> If you have left -> do that

    rekusive in order: easiest
    iterative in order: fastest
    morris in order: constant space
    '''
    ret = []
    current = root
    while current:
        if current.left:
            pre = current.left
            while pre.right:
                pre = pre.right
            newcurrent = current.left
            current.left = None
            pre.right = current
            current = newcurrent
        else:
            ret.append(current.val)
            current = current.right
    return ret
        
