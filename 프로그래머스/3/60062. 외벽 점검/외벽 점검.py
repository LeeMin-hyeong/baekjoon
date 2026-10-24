from itertools import permutations

def solution(n, weak, dist):
    W = len(weak)
    F = len(dist)

    # 원형 구조를 직선으로 변환
    weak = weak + [w + n for w in weak]

    answer = F + 1

    # 점검 시작 위치
    for start in range(W):

        # 친구 투입 순서
        for order in permutations(dist):
            cnt = 1
            end = weak[start] + order[0]

            # 취약 지점 순회
            for i in range(start, start + W):

                # 현재 친구가 점검할 수 없는 경우
                if weak[i] > end:
                    cnt += 1

                    if cnt > F:
                        break

                    # 다음 친구 배정
                    end = weak[i] + order[cnt - 1]

            else:
                answer = min(answer, cnt)

    return answer if answer <= F else -1