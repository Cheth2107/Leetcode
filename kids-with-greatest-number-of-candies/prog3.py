from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        # Find the maximum number of candies
        max_candies = max(candies)
        
        # Initialize the result list
        res = []
        
        # Check if each kid can have the greatest number of candies
        for num in candies:
            if num + extraCandies >= max_candies:
                res.append(True)
            else:
                res.append(False)
        
        return res

# Test the function
if __name__ == "__main__":
    solution = Solution()
    candies = [2, 3, 5, 1, 3]
    extraCandies = 3
    result = solution.kidsWithCandies(candies, extraCandies)
    print(result)
