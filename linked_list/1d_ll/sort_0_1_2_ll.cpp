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

//    TC->O(N)  SC->O(1)
// Solution class containing YOUR logic
class Solution {
public:
    // Sort linked list of 0s, 1s, and 2s
    // Using ONE dummy list and creating NEW nodes
    void sortZeroOneTwo(LinkedList& ll) {

        Node dummy(-1);

        // Boundaries inside the same list
        Node* zeroEnd = &dummy;
        Node* oneEnd  = &dummy;
        Node* tail    = &dummy;

        Node* curr = ll.head;

        while (curr) {
            Node *nextNode=curr->next;
            curr->next=nullptr;
            if (curr->data == 0) {
                // insert after zeroEnd
                curr->next = zeroEnd->next;
                zeroEnd->next = curr;
                if (oneEnd == zeroEnd)
                    oneEnd = curr;
                if (tail == zeroEnd)
                    tail = curr;
                zeroEnd = curr;
            }
            else if (curr->data == 1) {
                // insert after oneEnd
                curr->next=oneEnd->next;
                oneEnd->next=curr;
                if (tail == oneEnd)
                    tail = curr;
                oneEnd = curr;
            }
            else { // data == 2
                // insert at end
                tail->next = curr;
                tail = curr;
            }
            curr = nextNode;
        }
        ll.head = dummy.next;
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
