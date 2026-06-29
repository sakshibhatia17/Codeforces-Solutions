import sys
input = sys.stdin.readline
 
t = int(input())
for _ in range(t):
    l, a, b = map(int, input().split())
    g = __import__("math").gcd(l, b)
    step = l // g
 
    cur = a
    ans = a
    for _ in range(step):
        ans = max(ans, cur)
        cur = (cur + b) % l
 
    print(ans)