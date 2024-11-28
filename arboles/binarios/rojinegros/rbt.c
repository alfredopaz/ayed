#include "rbt.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

RBNode* createRBNode(int key, Color color) {
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: en la asignación de memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->color = color;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

RBTree* createRBTree() {
  RBTree* newTree = (RBTree*)malloc(sizeof(RBTree));
  if (newTree == NULL) {
    fprintf(stderr, "Error: No se pudo asignar memoria para el árbol.\n");
    exit(EXIT_FAILURE);
  }
  newTree->root = NULL;
  return newTree;
}

int isRootBlack(RBTree *t){
  assert(t != NULL);
  if(t->root) 
    return 1;
  return t->root->color == BLACK;
}

void rbInsert(RBTree *t, RBNode* z) {
  assert(t != NULL);

  RBNode* x = t->root;
  RBNode* y = NULL;

  while(x) {
    y = x;
    if (z->key < x->key) 
      x = x->left;
    else 
      x = x->right;
  }

  z->parent = y;

  if(!y) 
    t->root = z;
  else{
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  } 

  z->color = RED;

  // rbInsertFixUp(t, z); // Llamada comentada
}

void leftRotate(RBTree *t, RBNode* x) {
  assert(t != NULL);
  assert(x != NULL);

  RBNode* y = x->right;
  x->right = y->left;

  if(y->left != NULL) 
    y->left->parent = x;

  y->parent = x->parent;

  if(x->parent == NULL)
    t->root = y;
  else {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}
