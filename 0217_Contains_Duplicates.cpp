/* METHOD -1 (UnOrdered-Set)
   Time-Complexity -> O(n)
   Space Complexity -> O(n)*/
// Function to check if the input array has any duplicates
bool containsDuplicate(vector<int>& nums) {

    // This set will store numbers we've already seen
    unordered_set<int> visited;

    // Loop through each number in the array
    for (int i = 0; i < nums.size(); i++) {
        // If the number is already in the set, it's a duplicate
        if (visited.count(nums[i]))
            return true;

        // Otherwise, add the number to the set
        visited.insert(nums[i]);
    }

    // If we finish the loop with no duplicates found, return false
    return false;
}

/* METHOD -2 (Sorting)
   Time-Complexity -> O(n)
   Space Complexity -> O(1)*/

   bool containsDuplicate(vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());

    // Check adjacent elements for duplicates
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1])
            return true;
    }

    // No duplicates found
    return false;
}

/* METHOD -3 (Brute-Force)
   Time-Complexity -> O(n^2)
   Space Complexity -> O(1)*/
   bool containsDuplicate(vector<int>& nums) {
    // Compare every pair of elements
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }

    // No duplicates found
    return false;
}
