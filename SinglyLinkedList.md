# Singly Linked List Implementation in C++

## What is a Singly Linked List?

A singly linked list is a data structure that consists of nodes, where each node contains:
1. A value (data).
2. A pointer (`next`) to the next node in the list.

The last node in the list points to `nullptr`, indicating the end of the list.

---

## ListNode Structure

### Definition of the Node Structure
```cpp
struct ListNode {
    int val;               // Data value in the node
    ListNode* next;        // Pointer to the next node

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with value and next node pointer
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

---

## Basic Operations on a Singly Linked List

### 1. **Insert at the Beginning**
Inserts a new node with a given value at the beginning of the list.

```cpp
ListNode* insertAtBeginning(ListNode* head, int newVal) {
    ListNode* newNode = new ListNode(newVal);
    newNode->next = head;   // Point new node to the old head
    return newNode;         // New node becomes the new head
}
```

### 2. **Insert at the End**
Inserts a new node with a given value at the end of the list.

```cpp
ListNode* insertAtEnd(ListNode* head, int newVal) {
    ListNode* newNode = new ListNode(newVal);

    if (head == nullptr) {  // If list is empty
        return newNode;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;   // Point last node's next to the new node
    return head;
}
```

### 3. **Delete a Node**
Deletes a node with a specified value from the list.

```cpp
ListNode* deleteNode(ListNode* head, int key) {
    if (head == nullptr) return nullptr;

    if (head->val == key) { // If the node to delete is the head
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* current = head;
    while (current->next != nullptr && current->next->val != key) {
        current = current->next;
    }

    if (current->next != nullptr) { // Node with the key found
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    return head;
}
```

### 4. **Search for a Node**
Searches for a node with a specified value.

```cpp
bool searchNode(ListNode* head, int key) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == key) {
            return true;  // Found the node
        }
        current = current->next;
    }
    return false;  // Node not found
}
```

### 5. **Reverse a Linked List**
Reverses the entire linked list.

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;  // Save the next node
        curr->next = prev;                // Reverse the pointer
        prev = curr;                      // Move prev to current
        curr = nextNode;                  // Move to the next node
    }

    return prev;  // Return the new head (prev becomes the new head)
}
```

### 6. **Print a Linked List**
Prints all the values in the linked list.

```cpp
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
```

---

## Example Usage

```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// All functions (insertAtBeginning, insertAtEnd, deleteNode, etc.) go here

int main() {
    ListNode* head = nullptr;

    // Insert elements
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);

    // Print the list
    printList(head);  // Output: 20 10 30

    // Search for a node
    std::cout << "Node 10 exists: " << searchNode(head, 10) << std::endl;

    // Delete a node
    head = deleteNode(head, 10);
    printList(head);  // Output: 20 30

    // Reverse the list
    head = reverseList(head);
    printList(head);  // Output: 30 20

    return 0;
}
```

---

## Summary of Operations

| Operation          | Description                               | Time Complexity |
|--------------------|-------------------------------------------|-----------------|
| `insertAtBeginning` | Inserts a node at the start of the list   | O(1)            |
| `insertAtEnd`       | Inserts a node at the end of the list     | O(n)            |
| `deleteNode`        | Deletes a node by value                  | O(n)            |
| `searchNode`        | Searches for a node by value             | O(n)            |
| `reverseList`       | Reverses the entire linked list          | O(n)            |
| `printList`         | Prints the values of all nodes in the list| O(n)            |

---
