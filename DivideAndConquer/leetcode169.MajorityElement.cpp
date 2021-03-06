// solution1 Moore Voting Algorithm
class Solution 
{
public:
        int majorityElement(vector<int> &num)
        {
            
        int majorityIndex = 0;
        for(int cnt = 1, i = 1; i < num.size(); i++)
        {
            num[majorityIndex] == num[i] ? cnt++ : cnt--;
            if(cnt == 0)
            {
                cnt = 1;
                majorityIndex = i;
            }
        }
         
        return num[majorityIndex];
        }
    
};
// Solution2 divide and conquer
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) 
    {
        if (left == right) 
        {
            return nums[left];
        }
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) 
        {
            return lm;
        }
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};