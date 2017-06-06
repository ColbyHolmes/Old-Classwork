#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
  int    l1count = 0, l2count = 0, listID;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;
	struct account *list2head = NULL;
  struct account *list2tail = NULL;
  struct account *walk = NULL;
  struct account *temp = NULL;

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {
		if(listID == 1) {
			if(list1head == NULL) {

				list1head = (struct account*) malloc(sizeof(struct account));
				list1head->next = NULL;
				list1tail = list1head;

    	}
			else {

				list1tail->next = (struct account*) malloc(sizeof(struct account));
				list1tail = list1tail->next;
				list1tail->next = NULL;

			}

			list1tail->name = (char*) malloc(sizeof(char) * strlen(name) +1);
			strcpy(list1tail->name, name);
			list1tail->balance = balance;

		}
		else { // listID == 2
      if(list2head == NULL) {

                                list2head = (struct account*) malloc(sizeof(struct account));
                                list2head->next = NULL;
                                list2tail = list2head;

      }
      else {

                                list2tail->next = (struct account*) malloc(sizeof(struct account));
                                list2tail = list2tail->next;
                                list2tail->next = NULL;

      }
		
			list2tail->name = (char*) malloc(sizeof(char) * strlen(name) +1);
			strcpy(list2tail->name, name);
			list2tail->balance = balance;
			
		      }
  }

	temp = list1head;
	while (temp != NULL)
	{
		l1count ++;
		temp = temp->next;
	}
	temp = list2head;
	while (temp != NULL)
	{
		l2count ++;
		temp = temp->next;
	}

	if( l1count > l2count)
	{
		temp = list2head;
		while(temp != NULL)
		{
			list1tail->next = (struct account*) malloc(sizeof(struct account));
			list1tail = list1tail->next;
			list1tail->next = NULL;
			list1tail = temp;
			temp = temp->next;	
		}
	}
	else//if l2count >= l1count
	{
                temp = list1head;
                while(temp != NULL)
                {
                        list2tail->next = (struct account*) malloc(sizeof(struct account));
                        list2tail = list2tail->next;
                        list2tail->next = NULL;
                        list2tail = temp;
                        temp = temp->next;
                }

	}

	// print list1
	walk = list1head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }
	// print list2
	printf("----------------\n");
	walk = list2head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }


  return;
}
