'''

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.



Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
'''
import heapq


class Solution:
    def kthSmallest(self, matrix, k: int) -> int:
        if not matrix or not matrix[0]:
            return -1
        heap = []
        heapq.heapify(heap)
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                nextVal = -matrix[row][col]
                if len(heap) < k:
                    heapq.heappush(heap, nextVal)
                else:
                    heapq.heappushpop(heap, nextVal)

        return -heap[0]
