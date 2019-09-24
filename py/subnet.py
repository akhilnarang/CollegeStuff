#!/usr/bin/env python3
import re


def convertToDecimal(binary):
    decimal = []
    for i in range(0, len(binary), 8):
        decimal.append(str(int(binary[i : i + 8], 2)))
    return ".".join(decimal)


ip_str = input("Enter IP: ").split(".")
ip = [int(x) for x in ip_str]

default_masks = {
    "A": ["255.0.0.0", 24],
    "B": ["255.255.0.0", 16],
    "C": ["255.255.255.0", 8],
}


if ip[0] < 1:
    print("Invalid IP")
    exit(1)

if ip[0] <= 126:
    ip_class = "A"
    taken_for_subnet = ".".join(map(str, ip[:1])) + "."
elif 128 <= ip[0] < 192:
    ip_class = "B"
    taken_for_subnet = ".".join(map(str, ip[:2])) + "."
elif 192 <= ip[0] < 224:
    ip_class = "C"
    taken_for_subnet = ".".join(map(str, ip[:3])) + "."
elif 224 <= ip[0] < 240:
    ip_class = "D"
    print("Class E IP, nothing to do!")
    exit(1)
else:
    ip_class = "E"
    print("Class E IP, nothing to do!")
    exit(1)

print("IP address {} has class {}".format(".".join(ip_str), ip_class))
print("Default mask is {}".format(default_masks[ip_class]))

ip_binary = [bin(x)[2:] for x in ip]
print("Binary representation is {}".format(".".join(ip_binary)))

ip_range = int(input("Enter number of hosts: ")) + 2

# To get the closest power of 2
pow = 1
while True:
    result = 2 ** pow
    if ip_range <= result:
        break
    pow += 1

mask = ("0" * pow).rjust(default_masks[ip_class][1], "1")
n = 2 ** (default_masks[ip_class][1] - pow)
subnets = []
for k in range(n):
    start = re.sub("1+", str(bin(k)[2:]), mask).rjust(default_masks[ip_class][1], "0")
    end = start[:-pow] + "1" * pow
    subnets.append([start, end])

print("\nThe subnet mask is", default_masks[ip_class][0] + convertToDecimal(mask), "\n")

print("subnets :")
for i in subnets:
    print(
        taken_for_subnet + convertToDecimal(i[0]),
        "-",
        taken_for_subnet + convertToDecimal(i[1]),
    )
