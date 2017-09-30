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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


TreeNode *gen_tree();

class Solution {
public:
	void public_method();
private:
	void private_method();
};

/************************* customized *************************/
vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
/************************* customized *************************/

/************************* segmentation *************************/
class Widget
{
public:
    Widget();
    virtual ~Widget();
    virtual std::size_t const;
    virtual void normalzie();
    void swap(Widget &other);
};

void doProcessing(Widget &w)
{
    if (w.size() > 10 && w != someNastyWidget)
    {
        Widget temp(w);
        temp.normalize();
        temp.swap(w);
    }

    return ;
}

template<typename T>
void doProcessing(T &w)
{
    if (w.size() > 10 && w != someNastyWidget)
    {
        T temp(w);
        temp.normalize();
        temp.swap(w);
    }

    return ;
}

/************************* segmentation *************************/
