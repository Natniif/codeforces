class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums) - 1

        if len(nums) == 0: 
            return [-1,-1]

        while l <= r: 
            mid = (r + l)//2
            if nums[mid] < target: 
                l = mid + 1

            if nums[mid] > target:
                r = mid - 1

            if nums[mid] == target: 
                l = mid
                r = mid
                while l > 0: 
                    if (nums[l-1] == target): 
                        l -= 1
                    else: 
                        break
            
                while r < len(nums) - 1: 
                    if (nums[r+1] == target): 
                        r += 1
                    else: 
                        break
                
                return [l, r]
        
        return [-1, -1]
