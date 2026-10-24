def solution(n, m, x, y, r, c, k):
    d = ((1, 0), (0, -1), (0, 1), (-1, 0))
    direction = ('d', 'l', 'r', 'u')

    dist = abs(x-r) + abs(y-c)

    if dist > k or (k-dist) % 2 != 0:
        return 'impossible'

    answer = []

    for step in range(k):
        remain = k-step-1

        for i in range(4):
            nx = x + d[i][0]
            ny = y + d[i][1]

            if not (1 <= nx <= n and 1 <= ny <= m):
                continue

            next_dist = abs(nx-r) + abs(ny-c)

            if next_dist <= remain and (remain-next_dist) % 2 == 0:
                answer.append(direction[i])
                x, y = nx, ny
                break

    return ''.join(answer)