#!/usr/bin/python
# Colby Holmes
# Assignment 4
# Problem 3
import sys

class Employee(object):
  def __init__(self, first, last, pos, id, wage, w1, w2, w3, w4, w5):
    self.first = first
    self.last = last
    self.position = pos
    self.epid = id
    self.wage = wage
    self.w1 = w1
    self.w2 = w2
    self.w3 = w3
    self.w4 = w4
    self.w5 = w5

  def plast(self):
    print(self.last)

  def phigh(self):
    print "Name: ", self.first, self.last, "\nEPID: ", self.epid

  def change(self, first, last, id):
    self.first = first
    self.last = last
    self.epid = id

#end employee

# Get the total number of args passed to the demo.py
total = len(sys.argv)
linec = 0
count = 0
employeelist = []
first = ""
last = ""
pos = ""
id = ""
wage = 0
w1 = 0
w2 = 0
w3 = 0
w4 = 0
w5 = 0

if total > 3:
  print("\nToo many arguments!\n")

elif total < 3:
  print("\nToo few arguments!\n")

else:
  for line in open(sys.argv[1]):
    if linec < 2:
      linec += 1
      continue #skips first 2 lines

    for token in line.split(","): #separate by commas
      if count == 0:  # NAME
	namec = 0
	for word in token.split(): #split into first and last name
          if namec == 0:
	    first = word
	    namec = 1
          elif namec == 1:
            last = word
            namec = 0
	  else:
	    print("SOMETHING BAD HAPPENED!")

      elif count == 1: # POSITION
	pos = token

      elif count == 2: # EPID
	id = token

      elif count == 3: # WAGE
	wage = token

      elif count == 4: # WEEK 1
	w1 = token

      elif count == 5: # WEEK 2
	w2 = token

      elif count == 6: # WEEK 3
	w3 = token

      elif count == 7: # WEEK 4
	w4 = token

      elif count == 8: # WEEK 5
	w5 = token
   
      count += 1
    #end token loop

    count = 0
    employeelist.append(Employee(first,last,pos,id,wage,w1,w2,w3,w4,w5))

  #end line loop


if sys.argv[2] == '1': #LIST ALPHA
  #sort by last name
  employeelist.sort(key=lambda x: x.last, reverse=False)
  for i in range(len(employeelist)):
    employeelist[i].plast()

elif sys.argv[2] == '2': #AVERAGE
  averages = []
  oneavg = totalavg = 0
  for i in range(len(employeelist)):
    oneavg += float(employeelist[i].wage) * int(employeelist[i].w1)
    oneavg += float(employeelist[i].wage) * int(employeelist[i].w2)
    oneavg += float(employeelist[i].wage) * int(employeelist[i].w3)
    oneavg += float(employeelist[i].wage) * int(employeelist[i].w4)
    oneavg += float(employeelist[i].wage) * int(employeelist[i].w5)

    oneavg = oneavg / 5
    averages.append(oneavg)

  for i in range(len(averages)):
    totalavg += averages[i]

  totalavg = totalavg / len(averages)

  print "Average: ", totalavg

elif sys.argv[2] == '3': #RICH
  entryname = ""
  entryid = ""
  ewage = 0
  middlename = ""
  middleid = ""
  mwage = 0
  seniorname = ""
  seniorid = ""
  swage = 0

  for i in range(len(employeelist)):
    if employeelist[i].position == "Entry Level": 
      if float(employeelist[i].wage) > float(ewage):
	entryname = employeelist[i].first + " " + employeelist[i].last
        entryid = employeelist[i].epid
        ewage = employeelist[i].wage

    elif employeelist[i].position == "Middle Level":
      if float(employeelist[i].wage) > float(mwage):
	middlename = employeelist[i].first + " " + employeelist[i].last
        middleid = employeelist[i].epid
        mwage = employeelist[i].wage

    elif employeelist[i].position == "Senior Level":
      if float(employeelist[i].wage) > float(swage):
	seniorname = employeelist[i].first + " " + employeelist[i].last
        seniorid = employeelist[i].epid
        swage = employeelist[i].wage


  print "Entry Level:", entryname, entryid

  print "\nMiddle Level:", middlename, middleid
  
  print "\nSenior Level:", seniorname, seniorid

else:
  print "INVALID ARGUMENT!"  
