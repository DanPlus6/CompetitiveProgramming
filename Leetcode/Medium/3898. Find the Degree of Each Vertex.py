# Author: DanPlus6 // David Fu
# Problem Name: 3898. Find the Degree of Each Vertex
# Problem Code: find-the-degree-of-each-vertex
# Problem URL:  https://leetcode.com/problems/find-the-degree-of-each-vertex/
class Solution:
    def findDegrees(self, A: list[list[int]]) -> list[int]: return [sum(a) for a in A]
