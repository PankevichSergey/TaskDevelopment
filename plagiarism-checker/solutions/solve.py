n = input()
s = input()
t = input()
d = {}

for i in range(len(s)):
    if s[i] != t[i]:
        if not s[i] in d:
            d[s[i]] = t[i]
        elif d[s[i]] != t[i]:
            print("NO")
            exit()
print("YES")
print(len(d))
for k in d:
    print(k, d[k])
