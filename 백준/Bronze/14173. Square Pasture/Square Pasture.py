# 입력
x1, y1, x2, y2 = map(int, input().split())
w1, z1, w2, z2 = map(int, input().split())


# 가로 세로 구하기
x_axis = [x1, x2, w1, w2]
y_axis = [y1, y2, z1, z2]

row = max(x_axis) - min(x_axis)
col = max(y_axis) - min(y_axis)

# 출력
if row > col:
    print(row**2)
else:
    print(col**2)