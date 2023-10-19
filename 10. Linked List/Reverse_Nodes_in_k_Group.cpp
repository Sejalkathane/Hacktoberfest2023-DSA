#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse k nodes in a group
ListNode* reverseKGroup(ListNode* head, int k) {
    int count = 0;
    ListNode* curr = head;
    
    // Count the number of nodes in the list
    while (curr != nullptr && count < k) {
        curr = curr->next;
        count++;
    }
    
    // If there are less than k nodes remaining, no need to reverse
    if (count < k) {
        return head;
    }
    
    // Reverse the next k nodes and attach the reversed part to the head
    curr = reverseKGroup(curr, k);
    
    while (count-- > 0) {
        ListNode* tmp = head->next;
        head->next = curr;
        curr = head;
        head = tmp;
    }
    
    return curr;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 6; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    
    std::cout << "Original List: ";
    printList(head);
    
    int k = 3; // Set the group size

    head = reverseKGroup(head, k);

    std::cout << "Reversed List in K-groups: ";
    printList(head);

    return 0;
}
