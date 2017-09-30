#include <iostream> 
#include <vector>
#include <unordered_map> 
#include <queue> 
#include <stack> 

using namespace std;

class TreeNode {
public: 
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// width-based traverse, queue based
	vector<vector<int>> levelOrder_queue_based(TreeNode* root) {
		vector<vector<int>> vvi; 
		if (!root) return vvi; 

		queue<TreeNode *> tnq; 
		tnq.push(root), tnq.push(nullptr); 
		vector<int> vi;
		while (!tnq.empty()) {
			TreeNode* temp = tnq.front();
			tnq.pop();
			if (temp) {
				vi.push_back(temp->val); 
				if(temp->left) tnq.push(temp->left); 
				if(temp->right) tnq.push(temp->right); 
			}
			else {
				vvi.push_back(vi); 
				vi.clear(); 
				if (!tnq.empty()) tnq.push(nullptr); 
			}
		}
		return vvi; 
	}
	vector<vector<int>> levelOrder_queue_based2(TreeNode* root){
		vector<vector<int>> res; 
		if (!root) return res; 

		queue<TreeNode *> q; 
		q.push(root);
		while (!q.empty()) {
			vector<int> level; 
			int size = q.size(); 
			while (size > 0) {
				TreeNode *temp = q.front(); 
				q.pop(); 
				--size; 
				level.push_back(root->val); 
				if (root->left) q.push(root->left); 
				if (root->right) q.push(root->right); 
			}
			res.push_back(level); 
		}
		return ret; 
	}
	
	// width-based traverse, deque based
	vector<vector<int>> levelOrder_deque_based(TreeNode* root) {
		vector<vector<int>> vvi; 
		if (!root) return vvi; 

		deque<TreeNode *> dq; 
		dq.push_back(root);
		while (!dq.empty()) {
			vvi.push_back(vector<int>()); 
			int size = dq.size(); 
			vvi.back().reserve(size); 
			for (int i = 0; i < size; ++i) {
				vvi.back().push_back(dq.front()->val);
				if (dq.front()->left) dq.push_back(dq.front()->left);
				if (dq.front()->right) dq.push_back(dq.front()->right);
				dq.pop_front();
			}
		}
		return vvi; 
	}

	// depth-based traverse, stack based
	vector<vector<int>> levelOrder_stack_based(TreeNode* root) {
		vector<vector<int>> vvi;
		unordered_map<TreeNode *, int> check; 
		unordered_map<int, vector<int>> vi; 

		int depth = 0;
		stack<TreeNode *> tnstk;
		tnstk.push(root); 

		while (!tnstk.empty()) {
			if (root && !check[root]) {
				tnstk.push(root);
				++depth;
				vi[depth].push_back(root->val);
				check[root] = 1;
			}
			if (root->left && !check[root->left]) root = root->left;
			else if (root->right && !check[root->right]) root = root->right;
			else {
				tnstk.pop();
				--depth; 
				if(!tnstk.empty()) root = tnstk.top();
			}
		}
		for (auto &idx : vi)
			vvi.push_back(idx.second); 

		return vvi; 
	}

	// depth-based traverse, non_stack_non_queue based
	vector<vector<int>> ret;
	void buildVector(TreeNode *root, int depth) {
		if (!root) return;

		if (depth == ret.size()) ret.push_back(vector<int>());

		ret.at(depth).push_back(root->val);
		buildVector(root->left, depth + 1);
		buildVector(root->right, depth + 1);
	}
	vector<vector<int>> levelOrder_non_based(TreeNode* root) {
		buildVector(root, 0);
		return ret;
	}

	// preOrderTraverse 
	vector<int> preOrderTraverse(TreeNode* root, vector<int>& ivec){
		if (!root) return ivec;

		ivec.push_back(root->val); 
		preOrderTraverse(root->left, ivec); 
		preOrderTraverse(root->right,ivec); 
		return ivec; 
	}
	// inOrderTraverse 
	vector<int> inOrderTraverse(TreeNode* root, vector<int>& ivec) {
		if (!root) return ivec;

		inOrderTraverse(root->left, ivec);
		ivec.push_back(root->val);
		inOrderTraverse(root->right, ivec);
		return ivec;
	}
	// postOrderTraverse 
	vector<int> postOrderTraverse(TreeNode* root, vector<int>& ivec) {
		if (!root) return ivec;

		postOrderTraverse(root->left, ivec);
		postOrderTraverse(root->right, ivec);
		ivec.push_back(root->val);
		return ivec;
	}
};

int main() {
	// to generate a tree. 
	TreeNode tn0(0), tn1(1), tn2(2), tn3(3), tn4(4), tn5(5), tn6(6), tn7(7), tn8(8), tn9(9);
	TreeNode *root = &tn0;
	tn0.left = &tn1, tn0.right = &tn2;
	tn1.left = &tn3, tn1.right = &tn4;
	tn2.left = &tn5;
	tn3.left = &tn6;
	tn4.right = &tn7;
	tn6.left = &tn8, tn6.right = &tn9;

	Solution slt; 
	vector<vector<int>> vet = slt.levelOrder_deque_based(root);

	return 0; 
}