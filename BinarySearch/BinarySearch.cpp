// Algorithm to the interval [a, b)
int search(vector<int>& nums, int target)
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

// Algorithm to the interval [a, b]
int search(vector<int>& nums, int target)
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