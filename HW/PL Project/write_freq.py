'''
@author: Colby Holmes
'''
import sys
import urllib.request
from bs4 import BeautifulSoup


def main():
    if (len(sys.argv) > 3 or len(sys.argv) < 3):
        print("Incorrect number of arguments")
        exit()
    
    names = []
    counts = []
    
    file = open(sys.argv[2], 'r')
    
    # data from url
    data = urllib.request.urlopen(sys.argv[1]).read()
    soup = BeautifulSoup(data, 'html.parser')

    for stopword in file:   #for each stopword
        stopword = stopword.rstrip()
        count = 0;
        for string in soup.strings:     #check all strings
            lyst = string.split()
            for word in lyst:
                if word.lower() == stopword.lower():
                    count = count +1;

        check = True
        
        if len(names) == 0:
            names.append(stopword)
            counts.append(count)
            check = False
        
        for index in range(len(counts)):
            if counts[index] < count:
                names.insert(index, stopword)
                counts.insert(index, count)
                check = False
                break
            
        if check:
            names.append(stopword)
            counts.append(count)
            
    for index in range(len(names))[0:10]:
        print (names[index], ':', counts[index])
                 
                


if __name__ == "__main__":
    main()

