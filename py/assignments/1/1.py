#!/usr/bin/env python3

# Numbers between 2000 and 3200 which are a multiple of 7 but not a multiple of 5
print(*[x for x in range(2000, 3200) if x % 7 == 0 and x % 5 != 0])
