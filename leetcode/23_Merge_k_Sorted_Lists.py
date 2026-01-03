from typing import List, Optional


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def make_linked_list(vec):
    if len(vec) == 0:
        return None

    x = ListNode(vec[-1])

    for v in vec[-2::-1]:
        y = ListNode(v, x)
        x = y

    return x


def make_vec(l):
    if l is None:
        return []

    vec = [l.val]

    while l.next is not None:
        vec.append(l.next.val)
        l = l.next

    return vec


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        ans = []
        for l in lists:
            ans.extend(make_vec(l))
        return make_linked_list(sorted(ans))


def main():
    vec_lists = [[1], [1, 3, 4], [2, 6]]
    lists = []
    for vec in vec_lists:
        lists.append(make_linked_list(vec))

    for l in lists:
        print(make_vec(l))

    print(Solution().mergeKLists(lists))


if __name__ == '__main__':
    main()
