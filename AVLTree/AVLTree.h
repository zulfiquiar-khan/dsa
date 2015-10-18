#include<stdlib.h>

struct AVLTreeNode{
  int data;
  int height;
  struct AVLTreeNode* left;
  struct AVLTreeNode* right;
};


typedef struct AVLTreeNode avlNode ;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
avlNode* rotateSingleLeft(avlNode* X){
        if(X==NULL||X->left==NULL) return NULL;
        avlNode* W=X->left;
        X->left=W->right;
        W->right=X;
        X->height=max(height(X->left),height(X->right))+1;
        W->height=max(height(W->left),height(W->right))+1;
        return W;
}

avlNode* rotateSingleRight(avlNode* X){
        if(X==NULL||X->right==NULL) return NULL;
        avlNode* W=X->right;
        X->right=W->left;
        W->left=X;
        X->height=max(height(X->left),height(X->right))+1;
        W->height=max(height(W->left),height(W->right))+1;
        return W;
}

avlNode* rotateDoubleLeftRight(avlNode* X){
    if(X==NULL) return NULL;
    X->left=rotateSingleRight(X->left);
    return rotateSingleLeft(X);
}

avlNode* rotateDoubleRightLeft(avlNode* X){
    if(X==NULL) return NULL;
    X->right=rotateSingleLeft(X->right);
    return rotateSingleRight(X);
}

int height(avlNode* X){
    if(X==NULL) return -1;
    return X->height;
}

void traverseInorder(avlNode* root){
    if(root==NULL) return root;
    traverseInorder(root->left);
    printf("%d ",root->data);
    traverseInorder(root->right);
}

void traversePreorder(avlNode* root){
    if(root==NULL) return root;
    printf("%d ",root->data);
    traversePreorder(root->left);
    traversePreorder(root->right);
}

avlNode* insert(avlNode* root,avlNode* parent,int data){
    if(root==NULL){
        root=(avlNode*)malloc(sizeof(avlNode));
        if(root==NULL) {
            printf("Memory Error\n");
        }
        else{
            root->data=data;
            root->left=root->right=NULL;
            root->height=0;
        }
    }
    else if(data<root->data){
        root->left=insert(root->left,root,data);
        if(abs(height(root->left)-height(root->right))==2){
            if(data<root->left->data){
                    root=rotateSingleLeft(root);
            }
            else{
                root=rotateDoubleLeftRight(root);
            }
        }
    }
    else if(data>root->data){
        root->right=insert(root->right,root,data);
        if(abs(height(root->left)-height(root->right))==2){
            if(data>root->right->data){
                   root=rotateSingleRight(root);
                
            }
            else{
             root=rotateDoubleRightLeft(root);
            }
        }
    }
    root->height=max(height(root->left),height(root->right))+1;
    return root;
}

avlNode* createFullBalanceBst(int h,int * count){
    if(h==0) return NULL;
    avlNode* root=(avlNode*)malloc(sizeof(avlNode));
    root->height=h;
    root->left=createFullBalanceBst(h-1,count);
    root->data=(*count)+1;
    *count=(*count)+1;
    root->right=createFullBalanceBst(h-1,count);
    return root;
}

avlNode* generateAVLTreeWithMinNodes(int h,int* count){
        if(h<=0) return NULL;
    avlNode* root=(avlNode*)malloc(sizeof(avlNode));
    root->left=generateAVLTreeWithMinNodes(h-1,count);
    root->data=(*count)+1;
    *count=(*count)+1;
    root->right=generateAVLTreeWithMinNodes(h-2,count);
    root->height=h;
    return root;

}