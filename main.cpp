 #include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        
        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->val;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->val;
                head2 = head2->next;
            }
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        
        ListNode* result = reverse(dummy->next);
        
        // remove leading zeros
        while (result && result->val == 0 && result->next)
            result = result->next;
        
        return result;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // EXAMPLE INPUT:
    // head1: 1 -> 2 -> 3 (123)
    // head2: 9 -> 9 -> 9 (999)
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    
    ListNode* head2 = new ListNode(9);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);
    
    Solution s;
    ListNode* result = s.addTwoNumbers(head1, head2);
    
    cout << "Output: ";
    printList(result);   // Expected output: 1 -> 1 -> 2 -> 2
    
    return 0;
}