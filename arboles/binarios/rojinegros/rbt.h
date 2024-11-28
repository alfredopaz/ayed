#ifndef RBTREE_H
#define RBTREE_H

typedef enum {
  RED,
  BLACK
} Color;

typedef struct sRBNode {
  int key;
  Color color;
  struct sRBNode *left;
  struct sRBNode *right;
  struct sRBNode *parent;
} RBNode;

typedef struct {
  RBNode *root;
} RBTree;

RBNode* createRBNode(int key, Color color);
RBTree* createRBTree();
int isRootBlack(RBTree *t);
void rbInsert(RBTree *t, RBNode* z);
void leftRotate(RBTree *t, RBNode* x);

#endif

