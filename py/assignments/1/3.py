#!/usr/bin/env python3

# Numbers from 0 to 6 excluding 3 and 6
print(*[x for x in range(0, 7) if x != 3 and x != 6])
