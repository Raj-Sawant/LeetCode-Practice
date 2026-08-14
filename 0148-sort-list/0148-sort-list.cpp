class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* mid = findMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;  
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        
        return merge(left, right);
    }
    
private:
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
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (left && right) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        
        
        if (left) current->next = left;
        if (right) current->next = right;
        
        ListNode* result = dummy->next;
        delete dummy;  
        return result;
    }
};