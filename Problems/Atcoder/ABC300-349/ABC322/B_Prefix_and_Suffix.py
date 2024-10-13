_, _ = map(int, input().split())
s, t = input(), input()

ok1, ok2 = t.startswith(s), t.endswith(s)

if ok1 and ok2:
    print(0)
elif ok1 and not ok2:
    print(1)
elif not ok1 and ok2:
    print(2)
else:
    print(3)
