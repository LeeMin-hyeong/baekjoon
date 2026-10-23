from collections import deque
import heapq

dy = (0, 1, 0, -1)
dx = (1, 0, -1, 0)

def solution(board):
    N = len(board)
    q = []
    dist = [[[float('inf')] * 4 for _ in range(N)] for _ in range(N)]

    heapq.heappush(q, (0, 0, 0, -1))
    while q:
        cost, y, x, direction = heapq.heappop(q)
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            if not (0 <= ny < N and 0 <= nx < N):
                continue
            if board[ny][nx] == 1:
                continue
                
            new_cost = cost + (100 if i == direction or direction == -1 else 600)

            if new_cost < dist[ny][nx][i]:
                dist[ny][nx][i] = new_cost
                heapq.heappush(q, (new_cost, ny, nx, i))
        
    
    return min(dist[N-1][N-1])