/* Product of Array Except Self.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

// Given an array 'nums', return a new array 'ans'
// where ans[i] is the product of all elements of nums except nums[i]
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    // Initialize the answer array with 1s
    vector<int> ans(n, 1);

    // Build prefix product: ans[i] will hold the product of all elements to the left of i
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // Suffix product: multiply each ans[i] by the product of all elements to its right
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;   // combine prefix (already in ans[i]) and suffix
        suffix *= nums[i];  // update suffix for the next element to the left
    }

    return ans;
}