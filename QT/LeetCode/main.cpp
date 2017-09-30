#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    int numDecodings(string s) {
    // empty string or leading zero means no way
    if (!s.size() || s.front() == '0') return 0;

    // r1 and r2 store ways of the last and the last of the last
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;
        
        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }
        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}

int main(int argc, char *argv[])
{
    vector<int> ivec;
    ivec.push_back(4);
    ivec.push_back(14);
    ivec.push_back(2);

    Solution slt;
    vector<int> result = slt.totalHammingDistance(ivec, 2);
    for(auto &i : result) cout << i << ' ';
    cout<<endl;

    return 0;
}


Five efficient solutions in C++, well-explained

5
  LHearen
Reputation:  1,070
SOLUTIONS

MaxHeap

Simply, we can just use map to count each distinct number and then insert them all into a priority_queue. The time complexity will be O(klogk) where k is the number of the distinct numbers.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        unordered_map<int, int> count_map;
        for(auto n: nums) count_map[n]++;
        priority_queue<pair<int, int>> maxHeap;
        for(auto& pair: count_map) maxHeap.emplace(pair.second, pair.first);
        while(k--)
        {
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return v;
    }
};
MinHeap

Actually, we can also solve this using minimal heap which will remove the least frequent if the size of the minimal heap is larger than k, ensuring the top most k frequent will be stored in the minimal heap in the end.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        unordered_map<int, int> count_map;
        for(auto n: nums) count_map[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for(auto& pair: count_map)
        {
            minHeap.emplace(pair.second, pair.first);
            if(minHeap.size() > k) minHeap.pop();
        }
        while(k--)
        {
            v.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return v;
    }
};
Multimap

Using multimap to sort the numbers by its frequency and to accelerate the collecting process, we can adopt set to collect the frequencies for each number and then collect from the most frequent to the least.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        unordered_map<int, int> keys_map;
        for(auto n: nums) keys_map[n]++;
        multimap<int,int> count_map;
        set<int> count_set;
        for(auto& pair: keys_map) count_set.insert(pair.second), count_map.emplace(pair.second, pair.first);
        for(auto count_iter=count_set.rbegin(); count_iter!=count_set.rend(); ++count_iter)
        {
            int i = *count_iter;
            if(count_map.count(i))
            {
                for(auto iter = count_map.equal_range(i).first; iter != count_map.equal_range(i).second; ++iter)
                {
                    v.push_back(iter->second);
                    if(v.size() == k) return v;
                }
            }
        }
        return v;
    }
};
Vector

Actually the previous solution can be simplified with vector but we then have to traverse all the possible frequency instead of that just appear (count_set used in the previous solution).

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        if(nums.empty()) return v;
        unordered_map<int, int> keys_map;
        for(auto n: nums) keys_map[n]++;
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& pair: keys_map) buckets[pair.second].push_back(pair.first);
        for(int i = nums.size(); i; --i)
        {
            for(int j = 0; j < buckets[i].size(); ++j)
            {
                v.push_back(buckets[i][j]);
                if(v.size() == k) return v;
            }
        }
        return v;
    }
};
Array

Counting the frquency count and through these values, we can swiftly locate the frquency count which separate the top k most frequent numbers from the rest. We cannot use lower_bound to locate it, because the index and the frequency count is not one-to-one.

So the following method won't work; and arr here is a vector format of cumulative.
int kCount = lower_bound(arr.rbegin(), arr.rend(), k)-upper_bound(arr.rbegin(), arr.rend(), 0)+1;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        if(nums.empty()) return v;
        int cumulative[nums.size()+1] = {0};
        unordered_map<int, int> keys_map;
        for(auto n: nums) cumulative[keys_map[n]++]++;
        int kCount = 0;
        for(int i = nums.size(); i; --i) if(cumulative[i]>=k) { kCount = i; break; }
        for(auto& pair: keys_map)
            if(pair.second > kCount) v.push_back(pair.first);
        if(v.size() == k) return v;
        for(auto& pair: keys_map)
        {
            if(pair.second == kCount) v.push_back(pair.first);
            if(v.size() == k) return v;
        }
        return v;
    }
};
Always welcome new ideas and practical tricks, just leave them in the comments!

