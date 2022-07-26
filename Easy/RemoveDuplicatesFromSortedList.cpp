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
static ListNode _sentinel(-200, nullptr);
class Solution {
public:
    ListNode *deleteDuplicates(ListNode* head) {
        // Presuming that the list is sorted, this problem becomes incredibly simple.
        ListNode *_head = head;
        ListNode *prev = &_sentinel;
        while (head != nullptr) {
            if (prev->val == head->val) {
                // delete
                prev->next = head->next;
                head = head->next;
            } else {
                // no delete
                prev = head;
                head = head->next;
            }
        }
        return _head;
    }
};