class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        largest_squares = [min(r) for r in rectangles]
        maxLen = max(largest_squares)
        number = largest_squares.count(maxLen)

        return number
