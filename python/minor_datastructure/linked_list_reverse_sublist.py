# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        '''
        Pointer con: node before Reversal
        Pointer tail: first node of Reversal (will become the tail)
        
        Go to the m'th Element end always swap the pointer towards the next Element to point to the previous
        AT THE END: Only 2 Pointers need to be ajusted
        IMPORTANT: you have to reverse (n-m)+1 nodes (borders inclusive)
        '''
        if not head:
            return None
        
        m -= 1
        n -= 1
        
        cur, prev = head, None
        
        # move cur to the m'the Element
        i = 0
        while i < m:
            prev = cur
            cur = cur.next
            i += 1
        
        # save Pointer con and tail for later adjustment
        con = prev
        tail = cur
        
        # reverse the sublist:
        i = 0
        while i < (n-m)+1:
            temp = cur.next
            # change pointer
            cur.next = prev
            # go one further
            prev = cur
            cur = temp
            i += 1
        
        # Adjustment
        if con: # is not None
            con.next = prev
        else:
            head = prev
        tail.next = cur
        return head
        
