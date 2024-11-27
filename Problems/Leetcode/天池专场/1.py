# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def numberEvenListNode(self, head: Optional[ListNode]) -> int:
        ans = 0
        while head:
            ans += head.val % 2
            head = head.next
        return ans
