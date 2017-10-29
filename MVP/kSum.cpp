class Solution {
private:
    // Valid for K >= 2
    void KSum(int k, vector<int>& nums, int l, int r, int target, vector<vector<int>>& retVal, vector<int>& cur, int ci ) 
    {
        int i, mn, mx;
        int km1 = k - 1;

        if ( r-l+1 < k ) return;
        
        while ( l < r )
        {
            mn = nums[l]; // min 
            mx = nums[r]; // max
            
            // If K minus 1 largest + min < target, move to larger
            if ( ( mn + km1*mx ) < target ) l++;
            // If K minus 1 smaller + max > target, move to smaller
            else if ( ( km1*mn + mx ) > target ) r--;
            // If K * min > target, stop looking
            else if ( k*mn > target ) break;
            // If K * min == target, reached the threshold, check then stop looking
            else if ( k*mn == target )
            {
                if ( ( l + km1 <= r ) && ( mn == ( nums[l+km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mn;
                    retVal.push_back( cur );
                }
                break;
            }
            // If K * max < target, stop looking
            else if ( k*mx < target ) break;
            // If K * max == target, reached the threshold, check then stop looking
            else if ( k*mx == target )
            {
                if ( ( l <= r - km1 ) && ( mx == ( nums[r-km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mx;
                    retVal.push_back( cur );
                }
                break;                
            }
            // If K == 2, we found a match!
            else if ( k == 2 )
            {
                cur[ci] = mn;
                cur[ci+1] = mx;
                retVal.push_back( cur );
                l++;
                while ( ( l < r ) && ( nums[l] == mn ) ) l++;
                r--;
                while ( ( l < r ) && ( nums[r] == mx ) ) r--;
            }
            // Otherwise, convert the problem to a K-1 problem
            else
            {
                cur[ci] = mn;
                KSum( km1, nums, ++l, r, target - mn, retVal, cur, ci+1 );
                while ( ( l < r ) && ( nums[l] == nums[l-1] ) ) l++;
            }
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> lRetVal;
        vector<int> lQuad( 4, 0 ); // Pre-allocate the size of the result

        // Sort to provide a mechanism for avoiding duplicates
        sort( nums.begin(), nums.end() );
        
        KSum( 4, nums, 0, nums.size()-1, target, lRetVal, lQuad, 0 );

        return( lRetVal );        
    }
};