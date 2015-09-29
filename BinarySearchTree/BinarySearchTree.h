#include<stdlib.h>

struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
};

typedef struct BinarySearchTreeNode bstNode;

bstNode* findAnElementRecursive(bstNode* root,int data){
    if(root==NULL||root->data==data) return root;
    else if(root->data>data) findAnElementRecursive(root->left,data);
    else if(root->data<data) findAnElementRecursive(root->right,data);
}

bstNode* findAnElementIterative(bstNode* root,int data){
    while(root!=NULL){
        if(root->data==data)return root;
        else if(root->data>data) root=root->left;
        else root=root->right;
    }
    return root;
}

bstNode* findMinimumElementRecursive(bstNode* root){
    if(root->left==NULL||root==NULL)return root;
    else findMinimumElementRecursive(root->left);
}

bstNode* findMinimumElementIterative(bstNode* root){
    while(root!=NULL&&root->left!=NULL){root=root->left;}
    return root;
}


bstNode* findMaximumElementRecursive(bstNode* root){
    if(root->right==NULL||root==NULL)return root;
    else findMaximumElementRecursive(root->right);
}

bstNode* findMaximumElementIterative(bstNode* root){
    while(root!=NULL&&root->right!=NULL){root=root->right;}
    return root;
}

bstNode* findInorderPredecessor(bstNode* root,bstNode* element){
    if(root==NULL||element==NULL)return NULL;
    bstNode* found=findAnElementIterative(root,element->data);
    if(found==NULL)return NULL;
    bstNode* predecessor=findMaximumElementIterative(found->left);
    return predecessor;
}

bstNode* findInorderSuccessor(bstNode* root,bstNode* element){
    if(root==NULL||element==NULL)return NULL;
    bstNode* found=findAnElementIterative(root,element->data);
    if(found==NULL)return NULL;
    bstNode* successor=findMinimumElementIterative(found->right);
    return successor;
}

bstNode* insertAnElementRecursive(bstNode* root,int data){
    if(root==NULL){
        root=(bstNode*)malloc(sizeof(bstNode));
        if(root==NULL){
            printf("Memory Errro\n");
            return NULL;
        }
        else{
            root->data=data;
            root->left=root->right=NULL;
        }       
    }
    else{
        if(root->data>data){
            root->left=insertAnElementRecursive(root->left,data);
        }
        else if(root->data<data){
            root->right=insertAnElementRecursive(root->right,data);
        }
    }
    return root;
}

void insertAnElementIterative(bstNode* root,int data){
    if(root==NULL){
        return;
    }
    bstNode* element=(bstNode*)malloc(sizeof(bstNode));
    element->data=data;
    element->left=element->right=NULL;
    while(1){
        if(root->data<data){
            if(root->right==NULL){
                root->right=element;
                break;
            }
            else{
                root=root->right;
            }
        }
        else if(root->data>data){
            if(root->left==NULL){
                root->left=element;
                break;
            }
            else{
                root=root->left;
            }
        }
    }
    return;
}

void traverseInorder(bstNode* root){
    if(root==NULL){
        return;
    }
    traverseInorder(root->left);
    printf("%d ",root->data);
    traverseInorder(root->right);
}

void traversePreorder(bstNode* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    traversePreorder(root->left);
    traversePreorder(root->right);
}

bstNode* deleteRecursive(bstNode* root,int data){
    if(root==NULL){return NULL;}
    bstNode* temp=NULL;
    if(root->data<data){root->right=deleteRecursive(root->right,data);}
    else if(root->data>data){root->left=deleteRecursive(root->left,data);}
    else{
        if(root->left!=NULL && root->right!=NULL){
            temp=findMaximumElementIterative(root->left);
            root->data=temp->data;
            root->left=deleteRecursive(root->left,root->data);
        }
        else{
            if(root->left==NULL&&root->right==NULL){return NULL;}
            if(root->left==NULL)return root->right;
            if(root->right==NULL)return root->left;
        }
    }
    return root;
}

void deleteIterative(bstNode* root,int data){
    bstNode* temp=NULL;
    bstNode* prev=NULL;
    int flag=0; //0 for left move 1 for right move
    while(root!=NULL){
        printf("root : %d prev : %d  flag : %d data : %d \n",root->data,(prev!=NULL)?prev->data:0,flag,data);
        if(root->data>data){
            prev=root;
            root=root->left;
            flag=0;
            printf("After left move - root : %d prev : %d  flag : %d data: %d \n",root->data,(prev!=NULL)?prev->data:0,flag,data);
        }
        else if(root->data<data){
            prev=root;
            root=root->right;
            flag=1;
            printf("After right move - root : %d prev : %d  flag : %d data : %d \n",root->data,(prev!=NULL)?prev->data:0,flag,data);
        }
        else{
            printf("Data match - root : %d prev : %d  flag : %d data : %d \n",root->data,(prev!=NULL)?prev->data:0,flag,data);
            if(root->left==NULL&&root->right==NULL){setPreviousNode(prev,NULL,flag);break;}
            else if(root->left==NULL){setPreviousNode(prev,root->right,flag);break;}
            else if(root->right==NULL){setPreviousNode(prev,root->left,flag);break;}
            else{
                temp=findMaximumElementIterative(root->left);
                root->data=temp->data;
                prev=root;
                data=root->data;
                root=root->left;
                flag=0;
                 printf("After special case - root : %d prev : %d  flag : %d data : %d \n",root->data,(prev!=NULL)?prev->data:0,flag,data);
            }
        }
    }
}

void setPreviousNode(bstNode* prev,bstNode* root,int flag){
    if(flag==0)prev->left=root;
    else prev->right=root;
}

bstNode* buildBinarySearchTree(int element[],int length){
    bstNode* root=(bstNode*)malloc(sizeof(bstNode));
    root->left=root->right=NULL;
    root->data=element[0];
    int i=1;
    while(i<length){
        insertAnElementIterative(root,element[i]);
        i++;
    }
    return root;
}

bstNode* lowestCommonAncestorIterative(bstNode* root,int a,int b){
    if(root==NULL)return NULL;
    bstNode* node1=findAnElementIterative(root,a);
    bstNode* node2=findAnElementIterative(root,b);
    if(node1==NULL||node2==NULL)return NULL;
    while(1){
        if(root->data<=b&&root->data>=a)return root;
        else if(root->data<b && root->data<a)root=root->right;
        else root=root->left;
    }
    return NULL;
}

bstNode* lowestCommonAncestorRecursive(bstNode* root,int  a,int  b){
    if(root==NULL)return root;
    if(root->data<=b&&root->data>=a){
        return root;
    }
    if(root->data<b&&root->data<a){
        return lowestCommonAncestorRecursive(root->right,a,b);
    }
    if(root->data>b&&root->data>a){
        return lowestCommonAncestorRecursive(root->left,a,b);
    }
}

bstNode* lowestCommonAncestorRecursiveInterface(bstNode* root,int a,int b){
    bstNode* found1=findAnElementIterative(root,a);
    bstNode* found2=findAnElementIterative(root,b);
    if(found1==NULL||found2==NULL){
        return NULL;
    }
    else{
        return lowestCommonAncestorRecursive(root,a,b);
    }
}

int isBSTMaxMinStrategy(bstNode* root){
    if(root==NULL)return 1;
    bstNode* minNode=findMinimumElementIterative(root->right);
    bstNode* maxNode=findMaximumElementIterative(root->left);
    int min=1000;
    int max=-1000;
    if(minNode!=NULL)min=minNode->data;
    if(maxNode!=NULL)max=maxNode->data;
    if(root->data>max &&root->data<min){return isBSTMaxMinStrategy(root->left)&&isBSTMaxMinStrategy(root->right);}
    else{return 0;}
}

