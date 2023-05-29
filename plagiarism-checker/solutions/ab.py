n = int(input())
a = input()
b = input()
print("YES")
cha = False
chb = False
for i in range(n):
    if a[i] != b[i]:
        if a[i] == 'a':
            cha = True
        else:
            chb = True
prs = []
if cha:
    prs.append(('a', 'b'))
if chb:
    prs.append(('b', 'a'))
print(len(prs))
for pr in prs:
    print(*pr)
