/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = nullptr;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        if (head == nullptr || m >= n) {
            return head;
        }
        ListNode *current = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *begin, *end;
        for (int i = 1; i < m; i++) {
            if (current == nullptr) {
                return nullptr;
            }
            prev = current;
            current = current->next;
        }
        begin = prev; 
        end = current;
        for (int i = m; i <= n; i++) {
            if (current == nullptr) {
                return nullptr;
            }
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        end->next = current;
        if (begin != nullptr) {
            begin->next = prev;
            return head;
        } else {
            return prev;
        }
    }
};