def solution(sequence, k):
    L = len(sequence)
    sequence = [0] + sequence
    
    # 누적합 구하기
    for i in range(1, L+1):
        sequence[i] = sequence[i-1] + sequence[i]
    
    # 길이 1부터 늘려가기
    for l in range(1, L + 1):
        # 조건에 맞지 않으면 스킵
        if sequence[-1] - sequence[-1 - l] < k:
            continue
        if sequence[l] - sequence[0] > k:
            break

        # Lower bound 알고리즘
        s = 0
        e = L - l

        while s < e:
            m = (s + e) // 2
            if sequence[m+l] - sequence[m] >= k:
                e = m
            else:
                s = m + 1

        # 합이 k가 아닐 수 있음
        if sequence[s+l] - sequence[s] == k:
            return [s, s + l - 1]
