#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(vector<int> values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *temp = head;

    for (int i = 1; i < values.size(); i++)
    {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }

    return head;
}

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> criticalPoints;
        ListNode *temp = head;
        ListNode *prev = temp;
        ListNode *curr = temp->next;
        ListNode *next = temp->next->next;
        int idx = 1;
        while (next != nullptr)
        {

            // local Maxima
            if (curr->val > prev->val && curr->val > next->val)
            {
                criticalPoints.push_back(idx);
            }
            else if (curr->val < prev->val && curr->val < next->val)
            {
                criticalPoints.push_back(idx);
            }
            prev=curr;
            curr=next;
            next= next->next;
            idx++;
        }

        if(criticalPoints.size()<2){
            return{-1,-1};
        }
        int maxima = criticalPoints.back()- criticalPoints.front();
        int minima = INT_MAX;
        for(int i=1;i<criticalPoints.size();i++){
            minima= min(minima, criticalPoints[i]-criticalPoints[i-1]);
        }

        return {minima, maxima};
    }
};

int main()
{

    vector<int> values = {1,3,2,2,3,2,2,2,7};

    ListNode *head = createList(values);

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << endl;
    Solution s;
    vector<int> res = s.nodesBetweenCriticalPoints(head);
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
