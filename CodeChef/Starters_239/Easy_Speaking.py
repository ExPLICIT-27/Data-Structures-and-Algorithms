# cook your dish here
t = int(input())
vowels = "aeiou"

for _ in range(t):
    cnt = 0
    n = int(input())
    s = input()
    
    ok = True
    for c in s:
        if c not in vowels:
            cnt += 1
        else:
            cnt = 0
        if cnt >= 4:
            ok = False
            break
    
    if ok:
        print("No")
    else:
        print("Yes")