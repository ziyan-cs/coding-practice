/**
 * 143. Reorder List
 * Difficulty: Medium
 *
 * Approach: Middle split + reverse second half + merge
 * - Use slow/fast pointers to find the middle and split the list into two halves
 * - Reverse the second half of the list in-place
 * - Merge the two halves alternately (first -> second -> first -> second...)
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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        right = reverse(right);

        ListNode* left = head;

        while (left && right) {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;

            left->next = right;
            right->next = leftNext;

            left = leftNext;
            right = rightNext;
        }
    }
};
