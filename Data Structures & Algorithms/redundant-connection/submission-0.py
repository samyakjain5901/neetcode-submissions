class Solution:
    def _findPar(self, u: int, parent: List[int]) -> int:
        if parent[u] == u:
            return u
        parent[u] = self._findPar(parent[u], parent)
        return parent[u]

    def _union(self, u: int, v: int, parent: List[int], size: List[int]) -> List[int]:
        par_u = self._findPar(u, parent)
        par_v = self._findPar(v, parent)
        if par_u == par_v:
            return [u, v]
        if size[par_u] > size[par_v]:
            parent[par_v] = par_u
            size[par_u] += size[par_v]
        else:
            parent[par_u] = par_v
            size[par_v] += size[par_u]
        return []
    
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = max(max(u, v) for u, v in edges)
        parent = [i for i in range(n+1)]
        size = [1] * (n+1)
        last_red = []
        for u, v in edges:
            cur_red = self._union(u, v, parent, size)
            if cur_red:
                last_red = cur_red
        return last_red
