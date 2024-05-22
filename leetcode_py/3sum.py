class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        nums.sort()
        for i in range(len(nums) - 2): 
            if nums[i] > 0: 
                break
            if i > 0 and nums[i] == nums[i-1]: 
                continue
            j = i + 1; 
            k = len(nums) - 1
            while j < k: 
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0: 
                    triplet = [nums[i], nums[j], nums[k]]
                    answer.append(triplet)
                    while j < k and nums[j] == triplet[1]:
                        j += 1
                    while j < k and nums[k] == triplet[2]:
                        k -= 1
                elif sum < 0: 
                    j += 1
                else: 
                    k -= 1
        return answer
