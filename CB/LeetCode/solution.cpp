#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <functional>
#include <algorithm>

#include "solution.hpp"

using namespace std;


void Solution::private_method() {
	cout << "Welcome to Solution! " << endl;

	return;
}

void Solution::public_method() {
	this->private_method();
}

TreeNode *generate_tree()
{
    TreeNode tn0(0), tn1(1), tn2(2), tn3(3), tn4(4), tn5(5), tn6(6), tn7(7), tn8(8), tn9(9);
	TreeNode *root = &tn0;
	tn0.left = &tn1, tn0.right = &tn2;
	tn1.left = &tn3, tn1.right = &tn4;
	tn2.left = &tn5;
	tn3.left = &tn6;
	tn4.right = &tn7;
	tn6.left = &tn8, tn6.right = &tn9;

	return root;
}
