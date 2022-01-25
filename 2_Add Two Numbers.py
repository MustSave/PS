# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    # init ver
    # not (*Element)가 (*Element) == None보다 런타임이 길게 나왔음
    # == !=은 값을 비교, (is / is not)은 객체를 비교
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode(val = (l1.val + l2.val) % 10)
        init_node = res
        a = (l1.val + l2.val) // 10
        
        while l1.next != None or l2.next != None:
            if not l1.next: l1.val = 0
            else: l1 = l1.next
        
            if not l2.next: l2.val = 0
            else: l2 = l2.next
            
            res.next = ListNode(val = (l1.val + l2.val + a) % 10)
            a = (l1.val + l2.val + a) // 10
            
            res = res.next
            
        if a == 1:
            res.next = ListNode(val = 1)
        
        return init_node