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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head;
        ListNode *tail;
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr)  {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else { 
            // Pick the head
            if (list1->val > list2->val) {
                head = list2;
                list2 = list2->next;
            } else {
                head = list1;
                list1 = list1->next;
            }
            tail = head;
            while (list1 != nullptr || list2 != nullptr) {  
                int a = (list1 != nullptr) ? list1->val : 200;
                int b = (list2 != nullptr) ? list2->val : 200;
                if (a < b) {
                    tail->next = list1;
                    list1 = list1->next;
                    tail = tail->next;
                } else {
                    tail->next = list2;
                    list2 = list2->next;
                    tail = tail->next;
                }                
            }
        }
        tail->next = nullptr;
        return head;
    }
};