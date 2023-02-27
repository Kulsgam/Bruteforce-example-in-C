from string import ascii_letters, digits, punctuation
from itertools import product

for passcode in product(ascii_letters + digits + punctuation, repeat=4):
    # Product gives a packed object of tuples to all the possible permutations for the "repeat" number specified. '*' is used to unpack the tuples
    # Eg:- list = ['a', 'b', 'c']; if repeat is 2 ---> ['a', 'b'] and ['b', 'a'] and so on...
    print(*passcode)
