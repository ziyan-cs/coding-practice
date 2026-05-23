/**
 * 82. Remove Duplicates from Sorted List II
 * Difficulty: Medium
 *
 * Approach: Dummy node + single pass traversal
 * - Use dummy head to handle edge cases (head node deletion)
 * - Traverse the list and skip all consecutive duplicate nodes
 * - Append only non-duplicate nodes to the result list
 *
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            bool is_equal= false;
            while (curr->next && curr->val == curr->next->val) {
                is_equal = true;
                curr = curr->next;
            }

            if (!is_equal) {
                tail->next = curr;
                tail = tail->next;
            }
            curr = curr->next;
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
