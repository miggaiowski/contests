#! /usr/bin/env python

def palindrome(s):
    i = 0
    j = len(s) - 1
    while (i < j):
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True

def isprime(n):
    '''check if integer n is a prime'''
    # make sure n is a positive integer
    n = abs(int(n))
    # 0 and 1 are not primes
    if n < 2:
        return False
    # 2 is the only even prime number
    if n == 2: 
        return True    
    # all other even numbers are not primes
    if not n & 1: 
        return False
    # range starts with 3 and only needs to go up the squareroot of n
    # for all odd numbers
    for x in range(3, int(n**0.5)+1, 2):
        if n % x == 0:
            return False
    return True

with open("pi.txt") as f:
    pi = f.read()

npa = 0
npr = 0
for i in xrange(len(pi)-7):
    if palindrome(pi[i:i+7]):
        # print pi[i:i+7]
        npa += 1
        if isprime(int(pi[i:i+7])):
            print pi[i:i+7]
            npr +=1

print "palindromes: ", npa
print "primes: ", npr

