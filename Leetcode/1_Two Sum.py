from typing import List

class Solution:
    # init ver
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return i, j
    
    # using hashtable
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
    
        for i in range(len(nums)):
            if target - nums[i] in hashmap.keys():
                return hashmap[target-nums[i]], i
            else:
                hashmap[nums[i]] = i