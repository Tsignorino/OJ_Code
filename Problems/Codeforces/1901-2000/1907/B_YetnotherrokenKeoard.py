for _ in range(int(input())):
    s = list(input())

    upper, lower = [], []
    for i, v in enumerate(s):
        if v == "b":
            s[i] = ""
            if lower:
                s[lower.pop()] = ""
            continue  # !

        if v == "B":
            s[i] = ""
            if upper:
                s[upper.pop()] = ""
            continue  # !

        if v.islower():
            lower.append(i)
        else:
            upper.append(i)

    print("".join(s))
