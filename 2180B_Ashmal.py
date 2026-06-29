import sys
 
input = sys.stdin.readline
 
t = int(input())
for _ in range(t):
    n = int(input())
    arr = input().split()
 
    s = ""
    for x in arr:
        if x + s < s + x:
            s = x + s
        else:
            s = s + x
 
    print(s)