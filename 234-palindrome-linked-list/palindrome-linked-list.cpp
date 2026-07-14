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
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
    bool isPalindrome(ListNode* head) {
        // Find middle
ListNode *slow = head;
ListNode *fast = head;

while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
}

// Reverse second half
ListNode* newHead = reverseList(slow->next);

// Compare
ListNode* first = head;
ListNode* second = newHead;

while (second != NULL) {
    if (first->val != second->val) {
        reverseList(newHead);
        return false;
    }

    first = first->next;
    second = second->next;
}

// Restore list
reverseList(newHead);

return true;
        
    }
};