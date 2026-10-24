import heapq

def solution(n, paths, gates, summits):
    graph = [[] for _ in range(n+1)]
    
    for i, j, w in paths:
        graph[i].append((j, w))
        graph[j].append((i, w))
    
    def dijkstra():
        pq = []
        intensity = [float('inf')]*(n+1)
        for g in gates:
            intensity[g] = 0
            heapq.heappush(pq, (0, g))
        
        while pq:
            cost, cur = heapq.heappop(pq)
            if cur in summits:
                continue
            if intensity[cur] < cost:
                continue
            for nxt, w in graph[cur]:
                new_cost = max(cost, w)
                if new_cost < intensity[nxt]:
                    intensity[nxt] = new_cost
                    heapq.heappush(pq, (new_cost, nxt))
            
        return intensity
    
    answer = [float('inf'), float('inf')]
    
    set_summits = set(summits)
    for idx, intensity in enumerate(dijkstra()):
        if idx not in set_summits:
            continue
        if intensity < answer[1]:
            answer = [idx, intensity]
        
    return answer