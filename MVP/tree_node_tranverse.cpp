#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/************************************ InOrderTraversal ************************************/
void InOrderTraversal(TreeNode *root, vector<int> &res)
{
    if(!root) return ;

    InOrderTraversal(root->left, res);
    res.emplace_back(root->val);
    InOrderTraversal(root->right, res);
} // Recursion;

vector<int> InOrderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    while(true)
    {
        while(root){
            stk.push(root);
            root = root->left;
        }

        if(stk.empty()) break;

        root = stk.top();
        stk.pop();
        res.emplace_back(root->val);
        root = root->right;
    }

    return res;
} // Iteration;

vector<int> InOrderTraversal(TreeNode *root)
{
    vector<int> res;

    TreeNode *cur = root;
    while(cur)
    {
        if(cur->left)
        {
            TreeNode *prev = cur->left;

            while(prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if(!prev->right)
            {
                prev->right = cur;
                cur = cur->left;

                /*
                TreeNode *tmp = cur;
                cur = tmp->left;
                tmp->left = nllptr;
                */ // to avoid dead loops;
            }
            else
            {
                prev->right = nullptr;
                res.emplace_back(cur->val);
                cur = cur->right;
            }

        }
        else
        {
            res.emplace_back(cur->val);
            cur = cur->right;
        }
    }

    return res;
} // Morris;


/************************************ preOrderTraversal ************************************/
void preOrderTraversal(TreeNode *root, vector<int> &res)
{
    if(!root) return ;

    res.emplace_back(root->val);
    preOrderTraversal(root->left, res);
    preOrderTraversal(root->right, res);
}

/************************************ postOrderTraversal ************************************/
void postOrderTraversal(TreeNode *root, vector<int> &res)
{
    if(!root) return ;

    postOrderTraversal(root->left, res);
    postOrderTraversal(root->right, res);
    res.emplace_back(root->val);
}

/************************************ Main ************************************/
vector<int> tranversal(TreeNode *root)
{
    vector<int> res;

    preOrderTraversal(root, res);
    // InOrderTraversal(root, res);
    // postOrderTraversal(root, res);

    return res;
}
