class Solution:
    def smallestIndex(self, nums: list[int]) -> int:
        def get_digit_sum(num: int) -> int:
            total = 0
            while num > 0:
                total += num % 10
                num //= 10
            return total

        for i, val in enumerate(nums):
            if get_digit_sum(val) == i:
                return i
                
        return -1
