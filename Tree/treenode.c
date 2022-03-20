#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

struct treeNodeCDT {
   char *key;
   void *value;
};

treeNodeADT NewNode(char *key, void *value) {
   treeNodeADT node;
   node = (treeNodeADT)malloc(sizeof(struct treeNodeCDT));
   node->key = (char *)malloc((strlen(key) + 1) * sizeof(char));
   strcpy(node->key, key);
   node->value = value;
   return node;
}

treeNodeADT CopyNode(treeNodeADT n) {
   return NewNode(n->key, n->value); //create new space and then copy
}

char *GetNodeKey(treeNodeADT n) {
   if (n == NULL)
      exit(0);
   return n->key;
}

void *GetNodeValue(treeNodeADT n) {
   if (n == NULL)
      exit(0);
   return n->value;
}

void DelNode (treeNodeADT n) {
   free(n->key);
   free(n);
} 

