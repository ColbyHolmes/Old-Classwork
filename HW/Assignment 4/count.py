#!/usr/bin/python
# Colby Holmes
# Assignment 4
# Problem 1
import sys

# Get the total number of args passed to the demo.py
total = len(sys.argv)
count = 0

if total > 3:
  print("\nToo many arguments!\n")

elif total < 3:
  print("\nToo few arguments!\n")

else:
# Open file and check items
  for line in open(sys.argv[1]):
    for token in line.split():
      if token.lower() == sys.argv[2].lower(): #if theyre the same
        count += 1 #increment count

print(count)