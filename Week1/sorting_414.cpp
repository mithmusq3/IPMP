class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
     int ctr=0,ctr1=0,ctr2=0;
        int n = nums.size();
        long fmax = LONG_MIN;
        long smax = fmax;
        long tmax = fmax;
        for(int i =0;i<n;i++)
        {
            
            if(fmax < nums[i])
            {
                tmax = smax;
                smax = fmax;
                fmax = nums[i];
            }
            else if(smax < nums[i] && fmax > nums[i])
            {
                tmax = smax;
                smax = nums[i];
                ctr1++;
            }
            else if(nums[i] < smax && nums[i] > tmax){
                tmax = nums[i];
                ctr2++;
            }
        }

        if(n == 2 || (tmax == LONG_MIN))
        {
            return (int)fmax;
        }
        return (int)tmax;
        
    }
};