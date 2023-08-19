from cs50 import get_int

while 1:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(1,n+1):
    print(' '*(n-i) + '#'*i + ' '*2 + '#'*i)
