/**
 * @file linkedListMoveToEnd.c    Task to perform searches in unordered linked list and move to end when found.
 * @brief 
 *    Load up a linked list of strings and perform number of unordered
 *    searches. No check for NULL is used. Move to End of list on 
 *    a successful find.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <malloc.h>
#include <stdio.h>
#include "report.h"

/**
 * \typedef linkedListMoveToEnd/NODE
 *
 * Simple linked list of string elements.
 */
typedef struct node {
  /** The string being stored. */
  char *value;

  /** Next one in the list. */
  struct node *next;
} NODE, *NODE_PTR;


/** Head of the linked list of strings. */
static NODE_PTR ds;

/** Tail of the linked list of strings. */
static NODE_PTR last;

/** construct the initial instance. Simply initialize 'ds' and 'last'. */
void construct (int n) {
  last = ds = NULL;
}

/** insert strings one at a time to the end of the linked list. */
void insert (char *s) {
  if (ds == NULL) {
    last = ds = (NODE_PTR) calloc (1, sizeof (NODE));
    ds->value = s;
  } else {
    last->next = (NODE_PTR) calloc (1, sizeof (NODE)); 
    last->next->value = s;
    last = last->next;
  }
}


/** 
 * Search for the target within the linked list. Assume ds and last are never null. 
 * When found, move the element to be at the end of the list. 
 */
int search (char *target, int(*cmp)(const void *,const void *)) {

  NODE_PTR tmp = ds;
  NODE_PTR prev= NULL;

  while (tmp != NULL) {
    if (!cmp(tmp->value, target)) {
      if (prev == NULL) {
	/* adjust head (tricky) */
	ds = ds->next;
      } else {
	prev->next = tmp->next;
      }

      tmp->next = NULL;
      last->next = tmp;
      last = last->next;
      return 1;
    }
    
    /* advance */
    prev = tmp;
    tmp  = tmp->next;
  }

  return 0;
}
