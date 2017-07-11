/**
 * Linked List Random (w/ loading animation)
 * University of Central Florida
 * Author: Daniel Ohana
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *progress = "-\\|/";

typedef struct node
{
  int data;
  struct node *next;
} node;

// Allocates necessary data or a brand new node.
node *createNode(int data)
{
  node *ptr = malloc(sizeof(node));

  if (ptr == NULL)
    exit(1);

  ptr->data = data;
  ptr->next = NULL;

  return ptr;
}

// Inserts data into an existing linked list by creating a new node for it.
node *insert(node *head, int data)
{
  // It's probably a good idea to create a list before
  // we insert a node into one.
  if (head == NULL)
    return createNode(data);

  // First we have to crawl to the end of our list.
  node *crawl;
  for (crawl = head; crawl->next != NULL; crawl = crawl->next)
    ;

  // Now we can insert a node into the place we're at (the end of the list).
  crawl->next = createNode(data);

  return head;
}

// Crawls through the list and prints all encountered values.
// UPDATE: Gives user option to print.
void printList(node *head)
{
  int stop = 0;

  while (stop == 0)
    {
      printf("\nPrint list? (0: Yes, 1: No)\n");
      scanf("%d", &stop);

      if (stop == 1)
        return;

      if (head == NULL)
        {
          printf("Your list is empty.");
          return;
        }
    
        // Crawl through our list, printing every node value we encounter.
        for (; head != NULL; head = head->next)
        {
          // Print a space if we have more to go.
          // Print a new line if we're done.
          printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
        }
    
       return;
    }

  return;
}

// Takes in a message string and rewrites that message with a neat little animation.
void loading(char *s, int i)
{
  printf("\r%s\t[%c]", s, progress[i / 100 % 4]);
  fflush(stdout);
}

int main(void)
{
  node *head = NULL;
  int i, r, p;

  srand(time(NULL));

  printf("\n");
  // Fill the linked list with 50,000 random values.
  for (i = 0; i < 50000; i++)
  {
    loading("Filling linked list...", i);

    r = rand() % 100 + 1;

    head = insert(head, r);
  }

  // Finally, print our list.
  printList(head);

  printf("\n\n><><><><><><><><><><><><><><");
  printf("\n   THANK YOU FOR PLAYING!\n");
  printf("><><><><><><><><><><><><><><\n\n");



  return 0;
}
