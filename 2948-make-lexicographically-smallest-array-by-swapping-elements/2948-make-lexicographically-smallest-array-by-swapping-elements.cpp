class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
      
        // Create an array of indices [0, 1, 2, ..., n-1]
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
      
        // Sort indices based on the values in nums (ascending order)
        // This groups elements by their values
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
      
        // Result array to store the final answer
        vector<int> result(n);
      
        // Process groups of elements that can be swapped with each other
        for (int groupStart = 0; groupStart < n;) {
            // Find the end of current group
            // Elements in a group can swap if their difference <= limit
            int groupEnd = groupStart + 1;
            while (groupEnd < n && 
                   nums[indices[groupEnd]] - nums[indices[groupEnd - 1]] <= limit) {
                ++groupEnd;
            }
          
            // Extract the original positions of elements in this group
            vector<int> originalPositions(indices.begin() + groupStart, 
                                         indices.begin() + groupEnd);
          
            // Sort the original positions to place smallest values first
            sort(originalPositions.begin(), originalPositions.end());
          
            // Assign the sorted values to their corresponding positions
            // The smallest value goes to the smallest position index, and so on
            for (int k = groupStart; k < groupEnd; ++k) {
                result[originalPositions[k - groupStart]] = nums[indices[k]];
            }
          
            // Move to the next group
            groupStart = groupEnd;
        }
      
        return result;
    }
};
