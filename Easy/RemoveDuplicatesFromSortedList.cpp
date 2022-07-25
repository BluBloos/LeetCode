// TODO(Noah): Since the list is sorted, there is actually no need to
// store if things have been seen already. It's more of like this collapsing thing,
// because we know that duplicates are always adjacent.
//
// Also, it is possible to remove the checking for the three different cases?

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
    bool inList[201];
public:
    ListNode* deleteDuplicates(ListNode* head) {
        memset(inList, 0, sizeof(inList));
        ListNode *_head = head;
        ListNode *prev = head;
        while (head != nullptr) {
            bool deleted = false;
            if (deleted = (inList[head->val + 100])) {
                // remove duplicate
                // three cases, first node, middle node, end node. 
                if (head == _head) {
                    // first node
                    // this case also handles the first node being simultaneously the first and last.
                    _head = head->next;
                } else if (head->next == nullptr) {
                    // end node
                    prev->next = nullptr;
                } else {
                    // middle node
                    ListNode *next = head->next;
                    prev->next = next;
                }
            } else {
                inList[head->val + 100] = true;
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