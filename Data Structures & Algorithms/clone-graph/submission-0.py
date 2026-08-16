"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    node_map = {}
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        cloneNode = Node(val = node.val)
        self.node_map[node] = cloneNode
        for n in node.neighbors:
            if n in self.node_map:
                cloneNode.neighbors.append(self.node_map[n])
            else:
                cloneNeighbor = self.cloneGraph(n)
                cloneNode.neighbors.append(cloneNeighbor)
        return cloneNode