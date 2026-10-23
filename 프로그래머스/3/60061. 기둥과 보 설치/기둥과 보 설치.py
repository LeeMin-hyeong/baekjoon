def solution(n, build_frame):
    board = [[[0, 0] for _ in range(n+1)] for _ in range(n+1)]

    # 해당 구조물이 설치 조건을 만족하는지 검사
    def valid(x, y, a):
        if a == 0:  # 기둥
            return (
                y == 0
                or (y > 0 and board[y-1][x][0])
                or board[y][x][1]
                or (x > 0 and board[y][x-1][1])
            )
        else:  # 보
            return (
                (y > 0 and x < n and
                 (board[y-1][x][0] or board[y-1][x+1][0]))
                or
                (0 < x < n and
                 board[y][x-1][1] and board[y][x+1][1])
            )

    for x, y, a, b in build_frame:
        board[y][x][a] = b

        if b == 1:  # 설치
            if not valid(x, y, a):
                board[y][x][a] = 0

        else:  # 삭제
            possible = True

            for i in range(n+1):
                for j in range(n+1):
                    for k in range(2):
                        if board[i][j][k] and not valid(j, i, k):
                            possible = False
                            break
                    if not possible:
                        break
                if not possible:
                    break

            if not possible:
                board[y][x][a] = 1

    answer = []

    for x in range(n+1):
        for y in range(n+1):
            for a in range(2):
                if board[y][x][a]:
                    answer.append([x, y, a])

    return answer