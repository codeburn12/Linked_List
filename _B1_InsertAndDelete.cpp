#include <iostream>
using namespace std;

// Linked list definition
struct ListNode
{
    // ListNode comprises data(any) and next(pointer point to next ListNode)
    int data;
    ListNode *next;

    // Constructor for data initialization for different argument
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
private:
    // Head of ListNode
    ListNode *head;

public:
    // Constructor to initialize head ListNode as nullptr
    Solution() : head(nullptr) {}

    // Insertion at beginning
    void InsertAtBegining(int data)
    {
        ListNode *newNode = new ListNode(data); // New ListNode creation via ListNode structure constructor(Dynamically)
        newNode->next = head; // Since head contain the address of first ListNode, put that address in newNode->next
        head = newNode;       // Now head is pointing to newNode , i.e. newNode is the new head of ListNode
    }

    // Insertion at end
    void InsertionAtEnd(int data)
    {
        ListNode *newNode = new ListNode(data);

        // If list is empty, add newNode
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // Traverse to the end of list
        ListNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        // Now Add to the list 
        current->next = newNode;
    }

    // Insertion at any position
    void InsertAtPosition(int data, int pos)
    {
        // If pos is less than 0 or equals, insert at beginning
        if (pos <= 0)
        {
            InsertAtBegining(data);
            return;
        }
        // Traverse to the ListNode before the specified position
        ListNode *current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }
        // If pos is greater than the length of linked list, insert at end
        if(current == nullptr) {
            InsertionAtEnd(data);
            return;
        }
        // Insert newNode at specified position
        ListNode *newNode = new ListNode(data);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Deletion at beginning
    void DeletionAtBeginning() {
        if(head != nullptr) {
            ListNode *temp = head;
            head = temp->next;
            delete temp;
        }
        else {
            cout << "List is empty, Can't delete anything";
        }
    }

    // Deletion at End
    void DeletionAtEnd() {
        // List is empty
        if(head == nullptr) {
            cout << "List is empty, Can't delete anything";
            return;
        }
        // If there is only one ListNode, make head equals nullptr
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        // Traverse from second ListNode to last ListNode
        ListNode *temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Deletion at any position
    void DeleteAtPosition(int pos) {
        // Invalid position or list is empty
        if(pos < 0 || head == nullptr) {
            cout << "List is empty or invalid position";
            return;
        }

        // First position
        if(pos == 0) {
            DeletionAtBeginning();
            return;
        }

        // Traverse till specified position
        ListNode *current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }
        // Specified position is beyond the ListNode length
        if(current == nullptr || current->next == nullptr) {
            cout << "Given position is beyond ListNode length";
            return;
        }
        // Delition at specified position
        ListNode *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void printList()
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    Solution s;
    s.InsertAtBegining(1);
    s.InsertAtBegining(2);
    s.InsertAtPosition(3,1);
    s.InsertAtPosition(4,2);
    s.InsertionAtEnd(1);
    s.InsertionAtEnd(2);
    s.InsertionAtEnd(3);
    s.InsertionAtEnd(4);
    s.DeletionAtBeginning();        
    s.DeletionAtEnd();        
    s.DeleteAtPosition(3);        
    s.printList();
}