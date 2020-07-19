class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Sorting an array of three integers in O(n)
        This Problem is called the Dutch National Flag Problem.
        """
        red, white, blue = 0, 0 , len(nums)-1
        while white <= blue:
            if nums[white]==0:  # RED
                nums[white], nums[red] = nums[red], nums[white]
                white += 1
                red += 1
            elif nums[white]==1:  # WHITE: Already correct
                white +=1
            else:  # BLUE
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -=1
