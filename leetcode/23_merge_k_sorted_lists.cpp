/**
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 *
 * Approach: Priority Queue (Min-Heap)
 * - Use a min-heap to keep track of the smallest current head among all lists
 * - Extract the smallest node and push its next node into the heap
 * - Append the extracted node to the result list
 *
 * Time:  O(n log k) - n = total number of nodes, k = numbers of lists
 * Space: O(k)       - The heap stores at most k nodes
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* list = pq.top();
            pq.pop();

            tail->next = list;
            tail = tail->next;

            if (list->next) {
                pq.push(list->next);
            }
        }
        return dummy.next;
    }
};
