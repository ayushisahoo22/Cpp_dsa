#include <bits/stdc++.h>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class to manage list operations
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode; 
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
};

// Solution class containing YOUR logic
class Solution {
public:
    // Sort linked list of 0s, 1s, and 2s
    // Using ONE dummy list and creating NEW nodes
    void sortZeroOneTwo(LinkedList& ll) {

        Node* dummy = new Node(-1);

        // Boundaries inside the same list
        Node* zeroEnd = dummy;
        Node* oneEnd  = dummy;
        Node* tail    = dummy;

        Node* curr = ll.head;

        while (curr) {
            Node* newNode = new Node(curr->data);

            if (curr->data == 0) {
                // insert after zeroEnd
                newNode->next = zeroEnd->next;
                zeroEnd->next = newNode;
                if (oneEnd == zeroEnd)
                    oneEnd = newNode;
                if (tail == zeroEnd)
                    tail = newNode;
                zeroEnd = newNode;
            }
            else if (curr->data == 1) {
                // insert after oneEnd
                newNode->next = oneEnd->next;
                oneEnd->next = newNode;
                if (tail == oneEnd)
                    tail = newNode;
                oneEnd = newNode;
            }
            else { // data == 2
                // insert at end
                tail->next = newNode;
                tail = newNode;
            }
            curr = curr->next;
        }
        ll.head = dummy->next;
        delete dummy;
    }
};

// Driver code
int main() {
    LinkedList ll;
    Solution sol;

    ll.insert(1);
    ll.insert(2);
    ll.insert(0);
    ll.insert(1);
    ll.insert(2);
    ll.insert(0);

    cout << "Original List:\n";
    ll.print();

    sol.sortZeroOneTwo(ll);

    cout << "Sorted List:\n";
    ll.print();

    return 0;
}
