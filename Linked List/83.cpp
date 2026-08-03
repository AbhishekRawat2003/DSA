#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};

void insert(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(head, x);
    }

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After Operation: ";
    printList(head);

    return 0;
}