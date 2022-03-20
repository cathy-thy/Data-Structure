#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct bstCDT {
   treeNodeADT root;
   bstADT left;
   bstADT right;
   int height;
};

int height(bstADT t){
    if(t==NULL)
        return 0;
    return t->height;
}

bstADT MakeBST(treeNodeADT root, bstADT left, bstADT right){
    bstADT t;
    int lh, rh;
    t = (bstADT)malloc(sizeof(struct bstCDT));
    t->root = root;
    t->left = left;
    t->right = right;
    lh = Height(left);
    rh = Height(right);
    if (lh < rh)
        t->height = rh + 1;
    else   
        t->height = lh + 1;
    return t;
}

bstADT RotateLeft(bstADT t){
    treeNodeADT newRoot;
    bstADT newLeft, newRight;
    newRoot = Root(RightSubtree(t));
    newLeft = MakeBST(Root(t), LeftSubTree(t), LeftSubtree(RightSubtree(t)));
    newRight = RightSubtree(RightSubtree(t));
    return MakeBST(newRoot, newLeft, newRight);
}
bstADT RotateRight(bstADT t){
    treeNodeADT newRoot;
    bstADT newLeft, newRight;
    newRoot = Root(LeftSubtree(t));
    newLeft = LeftSubtree(LeftSubtree(t));
    newRight = MakeBST(Root(t), RightSubtree(LeftSubTree(t)) , RightSubTree(t));
    return MakeBST(newRoot, newLeft, newRight);
}
bstADT RotateLeftRight(bstADT t){
    bstADT tmpTree;
    tmpTree = MakeBST(Root(t), RotateLeft(LeftSubtree(t)), RightSubtree(t));
    return RotateRight(tmpTree);

}
bstADT RotateRightLeft(bstADT t){
    bstADT tmpTree;
    tmpTree = MakeBST(Root(t), LeftSubtree(t), RotateRight(RightSubTree(t)));
    return RotateLeft(tmpTree);
}

bstADT InsertNode(bstADT t, treeNodeADT n) {
    int sign;
    bstADT tmpTree;
    if (BSTIsEmpty(t))
        return MakeBST(n, EmptyBST(), EmptyBST());
    sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
    if (sign == 0)
        return MakeBST(n, LeftSubtree(t), RightSubtree(t));
    else if (sign < 0) {   // insert to left subtree
        tmpTree = MakeBST(Root(t), InsertNode(LeftSubtree(t), n),RightSubtree(t));
        if (Height(LeftSubtree(tmpTree))- Height(RightSubtree(tmpTree)) == 2) {
            if (strcmp(GetNodeKey(n),GetNodeKey(Root(LeftSubtree(tmpTree)))) < 0)
                return RotateRight(tmpTree);   // case 2
            else
                return RotateLeftRight(tmpTree);   // case 3
        } 
        else
            return tmpTree;
    }
    else {   // insert to right subtree
        tmpTree = MakeBST(Root(t), LeftSubtree(t),InsertNode(RightSubtree(t), n));
        if (Height(RightSubtree(tmpTree))- Height(LeftSubtree(tmpTree)) == 2) {
            if (strcmp(GetNodeKey(n),GetNodeKey(Root(RightSubtree(tmpTree)))) > 0)
                return RotateLeft(tmpTree);   // case 1
            else
                return RotateRightLeft(tmpTree);   // case 4
        } 
        else
            return tmpTree;
    }
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
