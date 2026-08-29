class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [[] for _ in range(n+1)]
        for u, v, w in times:
            adj[u].append((v, w))
        pq = []
        tt = [float('inf')] * (n+1)
        tt[k] = 0
        heapq.heappush(pq, (0, k))
        while pq:
            t, node = heapq.heappop(pq)
            for v, w in adj[node]:
                if tt[v] > t+w:
                    tt[v] = t+w
                    heapq.heappush(pq, (tt[v], v))
        res = 0
        for nt in tt[1:]:
            if nt == float('inf'):
                return -1
            res = max(res, nt)
        return res
