/**
 * 148. Sort List
 * Difficulty: Medium
 *
 * Approach:
 * - Merge sort on linked list, using two pointers to find the middle node
 * - Split the list into two halves recursively
 * - Merge two sorted linked lists in ascending order
 *
 * Time:  O(n log n)
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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (left && right) {
            if (left->val > right->val) {
                tail->next = right;
                right = right->next;
            } else {
                tail->next = left;
                left = left->next;
            }
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* leftLink = sortList(head);
        ListNode* rightLink = sortList(right);

        return merge(leftLink, rightLink);
    }
};
