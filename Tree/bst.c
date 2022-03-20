#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

struct bstCDT {
   treeNodeADT root;
   bstADT left;
   bstADT right;
};

bstADT EmptyBST() {
   return NULL;
}

int BSTIsEmpty(bstADT t) {
   return (t == NULL);
}

bstADT MakeBST(treeNodeADT root, bstADT left, bstADT right) {
   bstADT t;
   t = (bstADT)malloc(sizeof(struct bstCDT));
   t->root = root;
   t->left = left;
   t->right = right;
   return t;
}

treeNodeADT Root(bstADT t) {
   if ((BSTIsEmpty(t)))
      exit(0);
   return t->root;
}

bstADT LeftSubtree(bstADT t) {
   if ((BSTIsEmpty(t)))
      exit(0);
   return t->left;
}

bstADT RightSubtree(bstADT t) {
   if ((BSTIsEmpty(t)))
      exit(0);
   return t->right;
}

treeNodeADT FindNode(bstADT t, char *key) {
   int sign;
   if (BSTIsEmpty(t))
      return NULL;
   sign = strcmp(key, GetNodeKey(Root(t)));
   if (sign == 0)
      return Root(t);
   else if (sign < 0)
      return FindNode(LeftSubtree(t), key);
   else
      return FindNode(RightSubtree(t), key);
}

treeNodeADT GetMinNode(bstADT t) {
   if (BSTIsEmpty(LeftSubtree(t)))
      return t->root; 
   else
      return GetMinNode(LeftSubtree(t));
}

bstADT InsertNode(bstADT t, treeNodeADT n) {
   int sign; 
   if (BSTIsEmpty(t))
      return MakeBST(n, NULL, NULL);
   sign = strcmp(n->key, GetNodeKey(Root(t)));
   if (sign == 0){
      DelNode( t->root );	t->root = n;
   }
   else if (sign < 0){
      t->left = InsertNode(LeftSubtree(t), n);}
   else
      t->right = InsertNode(RightSubtree(t), n);     
   return t;
}


bstADT DeleteNode(bstADT t, char *key) {
  int sign;  treeNodeADT n; bstADT t2;
  if (BSTIsEmpty(t))      return t;
  sign = strcmp(key, GetNodeKey(Root(t)));

  if (sign < 0){
    t->left = DeleteNode(LeftSubtree(t), key);
    }

  else if (sign > 0){
    t->right = DeleteNode(RightSubtree(t), key);
    }

  else{
    if (BSTIsEmpty(LeftSubtree(t))){
      t2 = t; t = RightSubtree(t); DelNode(t2->root); free(t2);
    }
    else if (BSTIsEmpty(RightSubtree(t))){
      t2 = t; t = LeftSubtree(t); DelNode(t2->root); free( t2 );
    }

    else {
      n = GetMinNode(RightSubtree(t));
      DelNode( t->root );      
      t->root = CopyNode(n);
      t->right = DeleteNode(RightSubtree(t), GetNodeKey(n));
    }
  }
  
  return t;

}  
