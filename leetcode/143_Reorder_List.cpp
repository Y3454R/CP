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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || (head->next != NULL && head->next->next == NULL))
            return;

        ListNode* kocchop = head;
        ListNode* khorgosh = head;

        while (khorgosh->next != NULL && khorgosh->next->next != NULL) {
            kocchop = kocchop->next;
            khorgosh = khorgosh->next->next;
        }

        ListNode* bandor = kocchop->next;
        kocchop->next = NULL;
        
        ListNode* curr = bandor;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode* curr1 = head;
        ListNode* curr2 = prev;

        while (curr1 != NULL && curr2 != NULL) {
            ListNode* tmp1 = curr1->next;
            ListNode* tmp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = tmp1;
            curr1 = tmp1;
            curr2 = tmp2;
        }
        
    }
};
