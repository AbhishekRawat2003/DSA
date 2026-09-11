#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *createTree(vector<int> arr)
    {
        if (arr.empty())
            return nullptr;

        TreeNode *root = new TreeNode(arr[0]);

        queue<TreeNode *> q;
        q.push(root);

        int i = 1;

        while (i < arr.size())
        {
            TreeNode *current = q.front();
            q.pop();

            if (arr[i] != -1)
            {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1)
            {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }
    int count = 0;
    pair<int, int> solve(TreeNode *root)
    {

        if (root == nullptr)
            return {0, 0};

        auto left = solve(root->left);

        auto right = solve(root->right);

        int sum = root->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        int average = sum / nodes;

        if (average == root->val)
            count++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode *root)
    {
        solve(root);
        return count;
    }
};

int main()
{
    vector<int> arr = {4, 8, 5, 0, 1, -1, 6};
    Solution s;
    TreeNode *root = s.createTree(arr);
    cout << s.averageOfSubtree(root) << endl;
    return 0;
}