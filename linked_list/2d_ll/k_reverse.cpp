#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* reverseDLLInGroups(Node* head, int k)
{
    if(k == 1 || head == NULL)
        return head;
    int cnt = 1;
    Node* temp = head;
    Node* start = head;
    Node* newHead = NULL;
    Node* prevGroup = NULL;

    while(temp)
    {
        if(cnt == k)
        {
            Node* nextGroup = temp->next;
            Node* n = start;
            Node* last = NULL;
            while(n != nextGroup)
            {
                last = n->prev;
                n->prev = n->next;
                n->next = last;
                n = n->prev;
            }
            if(newHead == NULL)
                newHead = temp;
            if(prevGroup != NULL)
            {
                prevGroup->next = temp;
                temp->prev = prevGroup;
            }
            else
            {
                temp->prev = NULL;
            }
            prevGroup = start;
            start->next = nextGroup;
            if(nextGroup)
                nextGroup->prev = start;
            cnt = 1;
            temp = nextGroup;
            start = temp;

            continue;
        }
        temp = temp->next;
        cnt++;
    }
    if(start != NULL)
    {
        Node* n = start;
        Node* last = NULL;
        Node* rem = start;
        while(rem->next)
            rem = rem->next;
        start->prev = NULL;
        while(n != temp)
        {
            last = n->prev;
            n->prev = n->next;
            n->next = last;
            n = n->prev;
        }
        if(newHead == NULL)
            newHead = rem;
        if(prevGroup != NULL)
        {
            prevGroup->next = rem;
            rem->prev = prevGroup;
        }
    }
    return newHead;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << -1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        int k;
        cin >> k;
        head = reverseDLLInGroups(head, k);
        printList(head);
    }
    return 0;
}