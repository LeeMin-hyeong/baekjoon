import heapq

graph = []

def dijkstra(start, n):
    global graph
    dist = [float('inf')] * (n+1)
    q = []
    dist[start] = 0
    heapq.heappush(q, (0, start))
    while q:
        cost, cur = heapq.heappop(q)
        if dist[cur] < cost: continue
        for nxt, w in graph[cur]:
            if cost + w < dist[nxt]:
                dist[nxt] = cost + w
                heapq.heappush(q, (dist[nxt], nxt))
    
    return dist

def solution(n, s, a, b, fares):
    global graph
    graph = [[] for _ in range(n+1)]
    for u, v, w in fares:
        graph[u].append((v, w))
        graph[v].append((u, w))
        
    dist_s = dijkstra(s, n)
    dist_a = dijkstra(a, n)
    dist_b = dijkstra(b, n)
    
    
    answer = float('inf')
    for i in range(1, n+1):
        answer = min(answer, dist_s[i]+dist_a[i]+dist_b[i])
    
    return answer