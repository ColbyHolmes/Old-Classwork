#!/usr/bin/python
# Colby Holmes
# Assignment 4
# Problem 2
import sys

# Get the total number of args passed to the cluster_counter.py
total = len(sys.argv)
linec = 0
count = 0
groupc = 0
groups = []
countg = []
lst = [] #list to store tokens of a line

if total > 2:
  print("\nToo many arguments!\n")

elif total < 2:
  print("\nToo few arguments!\n")

else:
# Open file and check items
  for line in open(sys.argv[1]):
    for token in line.split():

      if linec == 0: #first line
	lst.append(token)
	if count == 0:#first element adds to groups every time
	  groupc += 1
	  groups.append(token)
          countg.append(1)

      if count > 0: #if its not the first token of a line
#check if the element above is different
	  if token.lower() == lst[count].lower() and linec > 0:
            lst[count] = token
            count += 1
            continue
#check if previous element is different
          elif token.lower() == lst[count-1].lower():
            lst[count] = token
            count += 1
            continue
	  else:
#if its a new cluster

            check = 1
	    for i in range(len(groups)): #check to see if it's the same letter as a previous cluster
	      if token.lower() == groups[i].lower():
		countg[i] += 1
                check = 0
            if check == 1:
	      groups.append(token)
              countg.append(1)
              groupc += 1


#replace lst with current line token
      lst[count] = token
      count += 1
    #end token loop

    linec += 1
    count = 0 #reset count every line
  #end line loop

print "\nYou have ", groupc, " groups: ", groups[:]
print("The Number of clusters are listed below: ")
for i in range(len(groups)):
  print groups[i], " : ", countg[i] 
 