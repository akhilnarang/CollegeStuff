#!/usr/bin/env python3


def get_value(mask):
    ret = ""
    for i in mask:
        for j in range(8 - len(i)):
            ret += "0"
        ret += i
    return ret


ip_str = input("Enter IP: ").split(".")
ip = [int(x) for x in ip_str]

default_masks = {
    "A": "255.0.0.0",
    "B": "255.255.0.0",
    "C": "255.255.255.0",
    "D": "255.255.255.255",
}

bits = {"A": 8, "B": 16, "C": 24, "D": 32}

if ip[0] < 1:
    print("Invalid IP")
    exit(1)

if ip[0] <= 126:
    ip_class = "A"
elif ip[0] >= 128 and ip[0] < 192:
    ip_class = "B"
elif ip[0] >= 192 and ip[0] < 224:
    ip_class = "C"
elif ip[0] >= 224 and ip[0] < 240:
    ip_class = "D"
else:
    ip_class = "E"
    print("Class E IP, nothing to do!")
    exit(1)

print("IP address {} has class {}".format(".".join(ip_str), ip_class))
print("Default mask is {}".format(default_masks[ip_class]))

ip_binary = [bin(x)[2:] for x in ip]
print("Binary representation is {}".format(".".join(ip_binary)))

number_hosts = int(input("Enter number of hosts: "))
i = 1
while True:
    result = 2 ** i
    if number_hosts <= result:
        break
    i += 1

bits_needed = i + bits[ip_class]
remaining_bits = 32 - bits_needed
binary_mask = [bin(int(x))[2:] for x in default_masks[ip_class].split(".")]
print(binary_mask)
zeroed = get_value(binary_mask)
print(bits_needed)
print(remaining_bits)
binary_value = "1" * bits_needed + "0" * remaining_bits
print(binary_value)