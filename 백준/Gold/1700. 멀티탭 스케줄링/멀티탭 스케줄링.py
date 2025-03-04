from collections import defaultdict

def min_plug_removals(n, k, use):
    pos = defaultdict(list)  # 각 기기의 사용 시점을 저장할 딕셔너리
    hole = set()  # 현재 콘센트에 꽂힌 기기 저장
    result = 0  # 플러그를 뽑은 횟수

    # 각 기기가 언제 사용되는지 저장
    for i in range(k):
        pos[use[i]].append(i)

    # 차례대로 사용하기
    for i in range(k):
        now = use[i]  # 현재 사용해야 할 기기

        # 현재 사용한 시점 제거
        pos[now].pop(0)

        # 이미 꽂혀있다면 넘어가기
        if now in hole:
            continue

        # 구멍에 여유 있다면 꽂기
        if len(hole) < n:
            hole.add(now)
            continue  # 꽂았으면 다음으로 넘어감

        # 구멍에 여유 없다면 기존의 것 빼고 넣기
        last_use = -1
        remove_device = -1

        for h in hole:
            # 앞으로 사용되지 않을 기기 찾기 (즉시 제거)
            if not pos[h]:
                remove_device = h
                break

            # 가장 나중에 등장하는 기기 찾기
            if pos[h][0] > last_use:
                last_use = pos[h][0]
                remove_device = h

        # 콘센트에서 제거 후 새 기기 꽂기
        hole.remove(remove_device)
        hole.add(now)
        result += 1

    return result


# 입력 예제
n, k = map(int, input().split())  # 콘센트 개수, 사용 횟수
use = list(map(int, input().split()))  # 사용 순서

# 결과 출력
print(min_plug_removals(n, k, use))
