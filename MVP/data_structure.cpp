#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// bfs, fifo, queue, iterative
	vector<int> BFS(TreeNode *root) {
		int mva = INT_MIN;
		vector<int> ivec;
		if (!root) return ivec;

		queue<TreeNode *> tnq;
		tnq.push(root);
		tnq.push(nullptr);

		while (!tnq.empty()) {
			TreeNode *tmp = tnq.front();
			tnq.pop();
			if (tmp) {
				mva = (tmp->val > mva) ? tmp->val : mva;
				if (tmp->left) tnq.push(tmp->left);
				if (tmp->right) tnq.push(tmp->right);
			}
			else {
				ivec.push_back(mva);
				if (!tnq.empty()) tnq.push(nullptr);
				mva = INT_MIN;
			}
		}

		return ivec;
	}

	// dfs, filo, stack, iterative
	vector<int> DFS(TreeNode *root) {
		vector<int> ivec;
		if (!root) return ivec;

		stack<TreeNode *> tns;
		stack<int> ins;
		tns.push(root);
		ins.push(0);

		while (!tns.empty()) {
			TreeNode *tmp = tns.top();
			int l = ins.top();
			tns.pop();
			ins.pop();

			if (ivec.size() < l + 1) {
				ivec.push_back(tmp->val);
			}
			else {
				ivec[l] = ivec[l] > tmp->val ? ivec[l] : tmp->val;
			}

			if (tmp->left || tmp->right) {
				l += 1;
				if (tmp->left) { tns.push(tmp->left);  ins.push(l); }
				if (tmp->right) { tns.push(tmp->right); ins.push(l); }
			}
		}

		return ivec;
	}

	// recursive
	vector<int> REC(TreeNode *root) {
		vector<int> ivec;
		if (!root) return ivec;

		bool flag = 1;
		int iv = INT_MIN; 
		for (int i = 0; flag; ++i) {
			flag = helper(root, iv, i);
			ivec.push_back(iv);
			iv = INT_MIN; 
		}

		return ivec;
	}

	bool helper(TreeNode *root, int &iv, int level) {
		bool idx = 1;
		if (!root) {
			idx = 0; 
			return idx; 
		}

		if (level == 0) {
			iv = iv > root->val ? iv : root->val;
			if (root->left || root->right) idx = 1; 
			else idx = 0; 
			return idx;
		}

		bool idx1 = helper(root->left, iv, level - 1); 
		bool idx2 = helper(root->right, iv, level - 1);
		idx = idx1 || idx2; // it is important to split the idx1 and idx2; 

		return idx; 
	}
};

int main(int argc, char *argv[])
{
	TreeNode tn0(0), tn1(1), tn2(2), tn3(3), tn4(4), tn5(5), tn6(6), tn7(7);
	tn0.left = &tn1, tn0.right = &tn2;
	tn1.left = &tn3, tn1.right = &tn4;
	tn2.left = &tn5, tn2.right = &tn6;
	tn3.left = &tn7;

	TreeNode *ptn0 = &tn0;

	Solution slt;
	vector<int> ivec = slt.REC(ptn0);
	for (auto &i : ivec) cout << i << " ";

	system("pause"); 
	return 0;
}