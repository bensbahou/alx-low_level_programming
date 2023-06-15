#!/usr/bin/python3
def ispalindrome(n):
    return str(n) == str(n)[::-1]

max_palindrome = 0
for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        if str(i * j) == str(i * j)[::-1] and i * j > max_palindrome:
            max_palindrome = i * j
            
print(max_palindrome)

