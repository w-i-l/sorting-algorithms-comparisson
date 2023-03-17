from os import *

maxim = 10000
nr_elem = 100000
base = 1024

for i in range(10):
    result = system(".\main.exe -{} -{} -{}".format(maxim, nr_elem, base))

    if result != 0:
        print("Failed!\n Exit status: {}".format(result))
        exit(0)

    maxim = int(maxim * 1.3)
    nr_elem += 100000
    base *= 2
