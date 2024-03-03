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

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode = nullptr, *nextNode = nullptr;
        while (head)
        {
            // Save the next node
            nextNode = head->next;

            // reverse the link
            head->next = prevNode;

            // Move to next node
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    void printList(ListNode *head)
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Display the original linked list
    std::cout << "Original Linked List: ";
    s.printList(head);

    // Reverse the linked list
    head = s.reverseList(head);

    // Display the reversed linked list
    std::cout << "Reversed Linked List: ";
    s.printList(head);
}