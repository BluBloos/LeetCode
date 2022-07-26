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
        // Presuming that the list is sorted, this problem becomes incredibly simple.
        ListNode *_head = head;
        ListNode *prev = nullptr;
        while (head != nullptr) {
            bool deleted = false;
            if (deleted = ((prev != nullptr) ? prev->val == head->val : false)) {
                ListNode *next = head->next;
                prev->next = next;
            }
            // advance to next item.
            if (deleted) {
                ListNode *__head = head;
                head = head->next;
                delete __head;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return _head;
    }
};