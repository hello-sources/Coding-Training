int countHillValley(int* nums, int numsSize){
    int slow=0, ans=0;
    int n = numsSize;
    for(int fast = 1; fast < n; ++fast){
        if(nums[fast] != nums[slow]){
            slow++;
            nums[slow] = nums[fast];
        } else{
            numsSize--;
        }
    }
    for(int i = 1; i < numsSize-1; ++i){
        if((nums[i]>nums[i-1] && nums[i]>nums[i+1]) || 
            (nums[i]<nums[i-1] && nums[i]<nums[i+1])){
            ans++;
        }
    }
    return ans;
}