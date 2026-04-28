values = ["10", "25", "n", "40", "abc"]

result = []

for v in values:
    if v.isdigit():
        result.append(int(v))
    else:
        result.append("N/A")

print(result)