# LeetCode
int maxSubArray(int* nums, int numsSize){
    int ThisSum,MaxSum,Sum,j,i=0;
    ThisSum = MaxSum = Sum = 0;
    for(j=0;j<numsSize;j++)
    {
        if(Sum<=0)
        {
            if(nums[j]>0)
                Sum = 1;
            else if(nums[j]==0)
                i = 1;
            else if(nums[j]>Sum||Sum == 0)
                Sum = nums[j];
        }
        ThisSum+=nums[j];
        if(ThisSum>MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    if(Sum>0)
        return MaxSum;
    else if(Sum < 0&&i == 1)
        return 0;
    else
        return Sum;
    
}
