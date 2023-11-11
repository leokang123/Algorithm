from sys import stdin
from collections import deque

T = int(stdin.readline())

for _ in range(T):
	n = int(stdin.readline())
	pair_list = [0] + list(map(int, stdin.readline().split()))
	visits = [0 for _ in range(n + 1)]
	tmp = deque()
	tot_cnt = 0
	for i in range(1, n + 1):
		if visits[i]:
			continue
		tmp.append((i, pair_list[i])) 
		cnt = 1
		team = set()
		while len(tmp):
			pair = tmp.popleft()
			if pair[1] == i:
				tot_cnt += cnt
				visits[pair[1]] = 1
				break
			if visits[pair[1]] and i != pair[1]:
				for idx in team:
					visits[idx] = 0
				break
			visits[pair[0]] = 1
			team.add(pair[0])
			cnt += 1
			tmp.append((pair[1], pair_list[pair[1]]))
	print(n - tot_cnt)

