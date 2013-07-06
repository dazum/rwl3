#include "llist_threads_rw.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXDATALEN 80

void *build_list(void *);

llist_t ll; 
int maxlen=MAXDATALEN;

extern int main(void)
{
  pthread_t thread1, thread2;
  int smallint1 = 2;
  int smallint2 = 3;

  llist_init(&ll);

  pthread_create(&thread1,
      NULL,
      build_list,
      (void *) &smallint1);

  pthread_create(&thread2,
      NULL,
      build_list,
      (void *) &smallint2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  llist_show(&ll);

  return 0;  
}

void *build_list(void *arg)
{
  int *factorp=(int *)arg;
  unsigned int multiple;
  char *stringp;
  int i;

  for (i = 0; i < 100; i++) {
    multiple = (*factorp) * i;
    stringp = malloc(maxlen);
    if (stringp == NULL)
      perror("malloc");
    sprintf (stringp, "%d is a multiple of %d", multiple, *factorp);
    llist_insert_data(multiple, stringp, &ll);
  }
  return NULL;
}
