/**
 * @brief Find the index of the target in the array.
 * 
 * The array must be ascending and each element is unique.
 * Below is the algorithm for the interval [a, b).
 * 
 * @param nums      Int vector.
 * @param target    The 
 * @return Return the index of the target in the array, or -1 if not found.
 */
int search(const vector<int>& nums, const int& target)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + ((right - left) >> 1); // Prevent overflows.
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid;
        else left = mid + 1;
    }
    
    return -1;
}

/**
 * @brief Find the index of the target in the array.
 * 
 * The array must be ascending and each element is unique.
 * Below is the algorithm for the interval [a, b]
 * 
 * @param nums      Int vector.
 * @param target    The 
 * @return Return the index of the target in the array, or -1 if not found.
 */
int search(const vector<int>& nums, const int& target)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1); // Prevent overflows.
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid;
        else left = mid + 1;
    }
    
    return -1;
}
