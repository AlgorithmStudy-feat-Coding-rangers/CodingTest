n = int(input())
serial_list = [input() for i in range(n)]
serial_list.sort(key=lambda x: (len(x), sum(list(map(int, filter(str.isdigit, x)))), x))

for serial in serial_list:
    print(serial)