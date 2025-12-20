# did not solve on own, cuz didnt understand whatever the flip a ListNode is
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        slow,fast = head,head
        while fast and fast.next: #note2self: if you're wondering why it would work in a test case such as [1,2,3,4], it is cuz slow can still step forward one time, before fast's stepping-out-of-range/bound causes the loop to break
            slow = slow.next
            fast = fast.next.next

        return slow


        
