from collections import Counter
for i in range(int(input())):
    print(f"#{input()} {Counter(input().split()).most_common(1)[0][0]}")