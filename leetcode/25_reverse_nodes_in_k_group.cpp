/**
 * 25. Reverse Nodes in k-Group
 * Difficulty: Hard
 *
 * Approach: Dummy node + iterative group reversal
 * - Use dummy head to simplify edge cases
 * - For each group: find end, reverse in-place, reconnect
 * Time:  O(n)
 * Space: O(1)
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        // stopped in front of end
        while (curr != end) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (true) {
            ListNode* groupStart = prev->next;
            ListNode* groupEnd = prev;

            for (int i = 0; i < k; ++i) {
                groupEnd = groupEnd->next;
                if (!groupEnd) return dummy.next;
            }

            ListNode* nextGroupStart = groupEnd->next;
            ListNode* newHead = reverse(groupStart, nextGroupStart);

            prev->next = newHead;
            groupStart->next = nextGroupStart;

            prev = groupStart;
        }
    }
};
