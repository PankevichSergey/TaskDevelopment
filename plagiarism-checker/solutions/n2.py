n = int(input())
s = input()
t = input()
for i in range(n):
    if s[i] == t[i]:
        continue
    for j in range(i):
        if s[i] != s[j]:
            continue
        if s[j] != t[j] and t[i] != t[j]:
            print("NO")
            exit(0)
cnt = 0
for i in range(n):
    if s[i] == t[i]:
        continue
    cnt += 1
    for j in range(i):
        if s[i] != s[j]:
            continue
        if s[j] != t[j]:
            cnt -= 1
            break
print("YES")
print(cnt)

for i in range(n):
    if s[i] == t[i]:
        continue
    bad = False
    for j in range(i):
        if s[i] != s[j]:
            continue
        if s[j] != t[j]:
            bad = True
    if not bad:
        print(s[i], t[i])

