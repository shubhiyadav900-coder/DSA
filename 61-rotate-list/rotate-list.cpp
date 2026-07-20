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

    // Function to find the kth node from the beginning
    ListNode* findNthNode(ListNode* temp, int k) {

        int cnt = 1;

        while(temp != NULL) {

            if(cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        // Base cases
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Find the tail and length of the linked list
        ListNode* tail = head;
        int len = 1;

        while(tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;

        // If no rotation is needed
        if(k == 0)
            return head;

        // Make the linked list circular
        tail->next = head;

        // Find the new last node
        ListNode* newLastNode = findNthNode(head, len - k);

        // New head is the next node
        head = newLastNode->next;

        // Break the circle
        newLastNode->next = NULL;

        return head;
    }
};