'''
@author: Colby Holmes
'''

import urllib.request
from bs4 import BeautifulSoup


def main():
    # data from url
    data = urllib.request.urlopen("http://www.technewsworld.com/ ").read()
    soup = BeautifulSoup(data, 'html.parser')
    #soup.prettify()
    
    for item in soup.find_all(attrs={'class': 'title'})[0:10]:#first 10
        t = item.get_text()  #title
        for link in item.find_all('a'):
            l = link.get('href') #link
            date = link.find_next(attrs={'class': 'date'})#date
            d = date.get_text()

            print(t)
            print(d)
            print(l)        

        print ('\n')

if __name__ == "__main__":
    main()



