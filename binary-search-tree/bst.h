#include "treenode.h"

typedef struct bstCDT *bstADT;

bstADT EmptyBST();
int BSTIsEmpty(bstADT t);   //empty tree or not
bstADT MakeBST(treeNodeADT root, bstADT left, bstADT right);

treeNodeADT Root(bstADT t);
bstADT LeftSubtree(bstADT t);
bstADT RightSubtree(bstADT t);

treeNodeADT FindNode(bstADT t, char *key);
treeNodeADT GetMinNode(bstADT t);
bstADT InsertNode(bstADT t, treeNodeADT n);
bstADT DeleteNode(bstADT t, char *key);
