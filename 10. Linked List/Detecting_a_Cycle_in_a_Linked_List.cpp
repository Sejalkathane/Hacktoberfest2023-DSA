#include <iostream>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to check if there is a cycle in the linked list
bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false; // No cycle if the list is empty or has only one node.
    }

    ListNode* tortoise = head;  // Slow pointer
    ListNode* hare = head;     // Fast pointer

    while (hare && hare->next) {
        tortoise = tortoise->next;  // Move the slow pointer by one step
        hare = hare->next->next;    // Move the fast pointer by two steps

        if (tortoise == hare) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}

int main() {
    // Create a linked list with a cycle for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle

    // Check for a cycle in the linked list
    if (hasCycle(head)) {
        std::cout << "Cycle detected in the linked list." << std::endl;
    } else {
        std::cout << "No cycle detected in the linked list." << std::endl;
    }

    return 0;
}
