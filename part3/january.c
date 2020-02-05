#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int index;
  float max;
  float min;
  struct node *next;
} node_t;

void insert(node_t **node, int index, float min, float max);
void delete(node_t **node, int index);
void print_list(node_t *node);

int main() {
  node_t *root = NULL;
    
  while (1) {
    printf("===========================================\n");
    printf("Please enter a command: ");
    int index;
    float min, max;
    char command = 'P';
    int r = scanf(" %c", &command);
    if (r != 1) {
      printf("Breaking loop now.\n");
      break;
    }
    if (command == 'P') {
      if (root == NULL) printf("List is empty! \n");
      else {
        printf("day     min     max\n");
        print_list(root);
      }
    }
    else if (command == 'Q') {
      printf("Quit program \n");
      break;
    }
    else if (command == 'D') {
      scanf(" %d", &index);
      delete(&root, index);
    }
    else if (command == 'A') {
      scanf(" %d", &index);
      scanf(" %f", &min);
      scanf(" %f", &max);
      insert(&root, index, min, max);
    }
    else {
      printf("Command not found\n");
    }
  }
  return 0;
}

void insert(node_t **node, int index, float min, float max) {

  // if empty list or end of list
  if (*node == NULL) {
    *node = (node_t *)malloc(sizeof(node_t));
    (**node).index = index;
    (**node).min = min;
    (**node).max = max;
    (**node).next = NULL;
  }

  // update existing node
  else if ((**node).index == index) {
    (**node).min = min;
    (**node).max = max;
  }
  // if only one node or first in list, insert first or after root
  else if ((**node).next == NULL && (**node).index < index) {
    insert(&(**node).next, index, min, max);
  }

  // Insert before root
  else if ((**node).index > index) {
    node_t *old_root = (node_t *)malloc(sizeof(node_t));
      (*old_root).index = (**node).index;
      (*old_root).min = (**node).min;
      (*old_root).max = (**node).max;
      (*old_root).next = (**node).next;
      (**node).index = index;
      (**node).min = min;
      (**node).max = max;
      (**node).next = old_root;
  }
  
  // Move forward in list
  else if (((**node).next == NULL) || ((**node).next->index < index)) {
    insert(&(**node).next, index, min, max);
  }
  
  // Insert between two nodes
  else {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    (*new_node).index = index;
    (*new_node).min = min;
    (*new_node).max = max;
    (*new_node).next = (**node).next;
    (**node).next = new_node;
  }
}
void delete(node_t **node, int index) {
  if ((*node) == NULL) {
    
  }

  else if ((**node).index == index) {
    node_t *old_node = *node;
    *node = (**node).next;
    free(old_node);
  }

  else {
    delete(&(**node).next, index);
  }
}

void print_list(node_t *node) {
  if (node == NULL) printf("List is empty! \n");
  if (node != NULL) printf("%d     %f     %f \n", node->index, node->min, node->max);
  if (node->next != NULL)
    print_list(node->next);
}