import sys
sys.setrecursionlimit(5000)


def min_jump(nums, i:int, dp):
    #print(i)
    if i == len(nums) - 1:
        print(i)
        return 0
    if i >= len(nums):
        return 10 ** 6

    min_res = 10 ** 6
    for j in range(1, (nums[i])+1):
        if dp[i][j] == 0:
            dp[i][j] = min_jump(nums, i+j, dp) + 1
        min_res = min(min_res, dp[i][j])
    return(min_res)

def jump(nums):
    dp = []
    for i in range(len(nums)):
        temp_dp = []
        for j in range(max(nums)):
            temp_dp.append(0)
        dp.append(temp_dp)
    print(dp)
    ans =  min_jump(nums, 0, dp)
    return ans

nums = [2, 3, 1, 1, 4]
print(jump(nums))