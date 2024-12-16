/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *current = slow;
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = prev;

    while (ptr2 != NULL) {
        if (ptr1->val != ptr2->val) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}
