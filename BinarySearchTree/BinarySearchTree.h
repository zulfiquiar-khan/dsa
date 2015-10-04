#include<stdlib.h>
#include"../LinkedList/SinglyLinkedList.h"

struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
};

typedef struct BinarySearchTreeNode bstNode;

bstNode* findMiddleNode(bstNode*);

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

int isBSTSingleScanStrategy(bstNode* root,int min,int max){
    if(root==NULL)return 1;
    return (root->data>min&&
                root->data<max &&
                isBSTSingleScanStrategy(root->left,min,root->data) &&
                isBSTSingleScanStrategy(root->right,root->data,max));
}

int isBstInorderStartegy(bstNode* root,int * prev){
    if(root==NULL)return 1;
    if(!isBstInorderStartegy(root,prev)) return 0;
    if(root->data<*prev) return 0;
    *prev=root->data;
    return isBstInorderStartegy(root->right,prev);
}

bstNode* convertBinarySearchTreeToCircularDoublyLinkedList(bstNode* root){
    bstNode* head=NULL;
    bstNode* prev=NULL;
    bstToCdll(root,&head,&prev);
    return head;
}

void bstToCdll(bstNode* root,bstNode** head ,bstNode** prev){
    bstNode* right=NULL;
    if(root==NULL)return NULL;
    bstToCdll(root->left,head,prev);
    root->left=*prev;
    if(*prev==NULL){
       *head=root; 
    }
    else{
        (*prev)->right=root;
    }
    right=root->right;
    (*head)->left=root;
    root->right=*head;    
    *prev=root;
    bstToCdll(right,head,prev);
}

bstNode* append(bstNode* a,bstNode* b){
    bstNode* aLast=NULL;
    bstNode* bLast=NULL;
    if(a==NULL)return b;
    if(b==NULL)return a;
    aLast=a->left;
    bLast=b->left;
    
    aLast->right=b;
    a->left=bLast;
    
    bLast->right=a;
    b->left=aLast;
    
    return a;
}

bstNode* bstToCdllDp(bstNode* root){
    bstNode* aList=NULL;
    bstNode* bList=NULL;
    if(root==NULL)return NULL;
    aList=bstToCdllDp(root->left);
    bList=bstToCdllDp(root->right);
    
    root->left=root;
    root->right=root;
    
    aList=append(aList,root);
    aList=append(aList,bList);
    
    return aList;
}

bstNode* convertDllToBst(bstNode* head){
    if(head==NULL)return NULL;
    bstNode* root=findMiddleNode(head);
    if(root==NULL)return NULL;
    bstNode* left=NULL;
    bstNode* right=NULL;
    
    if(root->left!=NULL){
        root->left->right=NULL;
    }
    if(root->right!=NULL){
        root->right->left=NULL;
    }
    left=convertDllToBst(root->left);
    right=convertDllToBst(root->right);
    root->left=left;
    root->right=right;
    return root;
}

bstNode* findMiddleNode(bstNode* head){
    bstNode* slowPtr=head;
    bstNode* fastPtr=head;
    
    if(head==NULL){
        return NULL;
    }
    
    while(fastPtr->right!=NULL){
        fastPtr=fastPtr->right;
        if(fastPtr->right!=NULL){
            slowPtr=slowPtr->right;
            fastPtr=fastPtr->right;
            }
    }
    return slowPtr;
}

bstNode* convertSortedArrayToBst(int array[],int start,int end){
    if(end<start){
        return NULL;
    }
    bstNode* left=NULL;
    bstNode* right=NULL;
    int mid=(start+end)/2;
    bstNode* root=(bstNode*)malloc(sizeof(bstNode));
    root->data=array[mid];
    left=convertSortedArrayToBst(array,start,mid-1);
    right=convertSortedArrayToBst(array,mid+1,end);
    root->left=left;
    root->right=right;
    
    return root;
}

bstNode* sortedListToBst(struct singlyNode** list ,int start,int end){
    if(start>end)return NULL;
    int mid=start+(end-start)/2;
    bstNode* left=sortedListToBst(list,start,mid-1);
    bstNode* parent=(bstNode*)malloc(sizeof(bstNode));
    parent->left=left;
    parent->data=(*list)->data;
    (*list)=(*list)->next;
    parent->right=sortedListToBst(list,mid+1,end);
    return parent;
}