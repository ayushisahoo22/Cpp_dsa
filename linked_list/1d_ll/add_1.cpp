#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list representing a positive integer number.
// Each node of the linked list represents a digit of the number,
// with the 1st node containing the leftmost digit of the number and so on


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage node-level operations
class LinkedList {
public:
    // function to insert digit at the end
    Node* append(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) {
            return newNode;
        }
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    // Function to print the list
    void printList(Node* head) {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

// Solution class having the addOne logic 
class Solution {
public:
    // function to reverse the linked list
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;

        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Reverse the list to make least significant digit accessible
        head = reverseList(head);

        Node* current = head;
        int carry = 1;  
        while (current && carry) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            // If there's no next node and we still have a carry, append a new node
            if (!current->next && carry) {
                current->next = new Node(carry);
                carry = 0;  
            }

            current = current->next;
        }

        // Reverse the list back to restore original order
        head = reverseList(head);
        return head;
    }
};

int main() {
    Node* head = nullptr;
    LinkedList ll;
    Solution sol;

    // Example: Number 129 (1 -> 2 -> 9)
    head = ll.append(head, 1);
    head = ll.append(head, 2);
    head = ll.append(head, 9);

    cout << "Original Number: ";
    ll.printList(head);

    head = sol.addOne(head);

    cout << "After Adding One: ";
    ll.printList(head);

    return 0;
}