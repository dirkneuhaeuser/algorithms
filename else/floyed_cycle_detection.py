def detectCycle(self, head: ListNode) -> ListNode:
    '''
    Using the Floyed-Cycle detection-Algorithm: 
    let slow and fastpointer go until they meet at x*-> then let one normal pointer start at head and the other at x*. When they meet -> its our position! :) Reason some Modulo-Maths
    '''
    if not head or not head.next or not head.next.next:
        return None
    fp = head.next.next
    sp = head.next
    
    
    # Until slow and fast pointer Meet:
    while sp != fp:
        if not fp or not fp.next or not fp.next.next:
            return None
        fp = fp.next.next
        sp = sp.next
    
    
    
    
    # find begining of loop:
    p1 = head
    p2 = sp
    while p1 != p2:
        p1 = p1.next
        p2 = p2.next
    
    return p2
