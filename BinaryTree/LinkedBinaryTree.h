#include<stdlib.h>
#include"../Stack/DynamicArrayStack.h"
#include"../Queue/LinkedListQueue.h"

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

typedef struct BinaryTreeNode node;

node* createBinaryTree(int size){
    node* root=(node*)malloc(sizeof(node));
    int i=1;
    if(root==NULL){
        printf("Memory error\n");
        return NULL;
    }
    root->data=i;
    root->left=NULL;
    root->right=NULL;
    i++;
    int flag=0;
    while(i<=size){
        printf("inserting %d \n",i);
        printf("----------------------\n");
        insert(root,i,flag);
        printf("inserted %d \n",i);
        printf("----------------------\n");
        if(flag==0){flag=1;}
        else{flag=0;}
        i++;
    }
    return root;
}

void insert(node* root,int data,int flag){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    while(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            if(flag==0){
                root->left=newNode;
                printf("inserted in left of %d \n",root->data);
                }
            else{
                root->right=newNode;
                printf("inserted in right of %d\n",root->data);
            }
            break;
        }
        else if(root->left==NULL){
            root->left=newNode;
            printf("inserted in left of %d\n",root->data);
            break;
        }
        else if(root->right==NULL){
            root->right=newNode;
            printf("inserted in right of %d\n",root->data);
            break;
        }
        else{
            if(flag==0){
                root=root->left;
                printf("moved to left\n");
            }
            if(flag==1){
                root=root->right;
                printf("moved to right\n");
            }
        }
    }
}

void preOrderTraversalRecursive(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversalRecursive(root->left);
        preOrderTraversalRecursive(root->right);
    }
}

void preOrderTraversalIterative(node* root){
    struct Stack* stack=NULL;
    if(root!=NULL){
        stack=createStack();
        while(1){
            while(root!=NULL){
                printf("%d ",root->data);
                push(stack,root);
                root=root->left;
            }
            if(isEmptyStack(stack))break;
                root=pop(stack);
                root=root->right;
        }
        deleteStack(stack);
    }
}

void inOrderTraversalRecursive(node* root){
    if(root!=NULL){
        inOrderTraversalRecursive(root->left);
        printf("%d ",root->data);
        inOrderTraversalRecursive(root->right);
    }
}

void inOrderTraversalIterative(node* root){
    struct Stack* stack=NULL;
    if(root!=NULL){
        stack=createStack();
        while(1){
            while(root!=NULL){
                push(stack,root);
                root=root->left;
            }
            if(isEmptyStack(stack))break;
                root=pop(stack);
                printf("%d ",root->data);
                root=root->right;
        }
        deleteStack(stack);
    }    
}

void postOrderTraversalRecursive(node* root){
    if(root!=NULL){
        postOrderTraversalRecursive(root->left);
        postOrderTraversalRecursive(root->right);
        printf("%d ",root->data);
    }
}

void postOrderTraversalIterative(node* root){
    if(root==NULL){return;}
    node* current=NULL;
    node* previous=NULL;
    struct Stack* stack=createStack();
    push(stack,root);
    
    while(!isEmptyStack(stack)){
        current=(node *)top(stack);
        if(previous==NULL || previous->left==current||previous->right==current){
            if(current->left!=NULL){
                push(stack,current->left);
            }
            else if(current->right!=NULL){
                push(stack,current->right);
            }
        }
        else if(current->left==previous){
            if(current->right!=NULL){
                push(stack,current->right);
            }
        }
        else{
            printf("%d ",current->data);
            pop(stack);
        }
        previous=current;
    }
    
}


void levelOrderTraversalIteartive(node* root){
    if(root==NULL){
        return;
    }
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=(node*) dequeueLinkedQueue(queue);
        printf("%d ",root->data);
        if(root->left!=NULL){
            enqueueLinkedQueue(queue,root->left);
        }
        if(root->right!=NULL){
            enqueueLinkedQueue(queue,root->right);
        }
    }
    deleteLinkedQueue(queue);
}

int findMaxInBinaryTree(node* root ){
if(root==NULL){
        return 0;
    }
    
    int root_data=root->data;
    int left_max=0;
    int right_max=0;
    int max=0;
    
    left_max=findMaxInBinaryTree(root->left);
    right_max=findMaxInBinaryTree(root->right);
    
    if(left_max>right_max){max=left_max;}
    else{max=right_max;}
    if(root_data>max){max=root_data;}
    
    return max;
}

int findMaxInBinaryTreeIterative(node* root){
    if(root==NULL){
        return;
    }
    int max=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=(node*) dequeueLinkedQueue(queue);
        if(root->data>max){
            max=root->data;
        }
        if(root->left!=NULL){
            enqueueLinkedQueue(queue,root->left);
        }
        if(root->right!=NULL){
            enqueueLinkedQueue(queue,root->right);
        }
    }
    deleteLinkedQueue(queue);
    return max;
}

node* searchInBinaryTreeRecursive(node* root,int data){
    node* temp=NULL;
    if(root==NULL){
        return root;
    }
    if(root->data==data){
        return root;
    }
    else{
            temp=searchInBinaryTreeRecursive(root->left,data);
            if(temp!=NULL){
                return temp;
            }
            temp=searchInBinaryTreeRecursive(root->right,data);
            if(temp!=NULL){
                return temp;
            }
    }
    return temp;
}

node* searchInBinaryTreeIterative(node* root,int data){
    if(root==NULL){
        return root;
    }
    node* result=NULL;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        node* temp=dequeueLinkedQueue(queue);
        if(temp->data==data){
            result=temp;
            return result;
        }
        if(temp->left!=NULL){
            enqueueLinkedQueue(queue,temp->left);
        }
        if(temp->right!=NULL){
            enqueueLinkedQueue(queue,temp->right);
        }
    }
    return result;
}


void insertNodeIntoBinaryTree(node* root,int data){
    if(root==NULL){
        return;
    }
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(newNode==NULL){
        printf("Memory error\n");
        return NULL;
    }
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        node* temp=dequeueLinkedQueue(queue);
        if(temp->left==NULL){
            temp->left=newNode;
            deleteLinkedQueue(queue);
            return;
        }
        else{
            enqueueLinkedQueue(queue,temp->left);
        }
        if(temp->right==NULL){
            temp->right=newNode;
            deleteLinkedQueue(queue);
            return;
        }
        else{
            enqueueLinkedQueue(queue,temp->right);
        }
    }
}


int sizeOfBinaryTreeRecursive(node* root){
    if(root==NULL){
        return 0;
    }
    return (sizeOfBinaryTreeRecursive(root->left)+1+sizeOfBinaryTreeRecursive(root->right)) ;
}

int sizeOfBinaryTreeIterative(node* root){
    if(root==NULL){
        return 0;
    }
    int size=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        size++;
        if(root->left!=NULL){
            enqueueLinkedQueue(queue,root->left);
        }
        if(root->right!=NULL){
            enqueueLinkedQueue(queue,root->right);
        }
    }
    deleteLinkedQueue(queue);
    return size;
}

void levelOrderTraversalInReverse(node* root){
    if(root==NULL){
        return;
    }
    struct Stack* stack=createStack();
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root->right!=NULL){
            enqueueLinkedQueue(queue,root->right);
        }
        if(root->left!=NULL){
            enqueueLinkedQueue(queue,root->left);
        }
        push(stack,root);
    }
    printf("Level order in reverse : ");
    while(!isEmptyStack(stack)){
        root=pop(stack);
        printf("%d ",root->data);
    }
    printf("\n");
}

void deleteBinaryTree(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    deleteBinaryTree(temp->left);
    deleteBinaryTree(temp->right);
    free(temp);
}

int heightOfBinaryTreeRecursive(node* root){
    if(root==NULL){
        return -1;
    }
    int left=0;
    int right=0;
    left=heightOfBinaryTreeRecursive(root->left);
    right=heightOfBinaryTreeRecursive(root->right);

    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}

int heightOfBinaryTreeIterative(node* root){
    if(root==NULL){
        return 0;
    }
    int level=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    enqueueLinkedQueue(queue,NULL);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root==NULL){
            if(!isEmptyLinkedQueue(queue)){
                enqueueLinkedQueue(queue,NULL);
                level++;
            }
        }
        else{
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
        }
    }
    deleteLinkedQueue(queue);
    return level;
}

node* deepestNodeInBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
    }
    deleteLinkedQueue(queue);
    return root;
}

int noOfLeafNodesInBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root->left==NULL&&root->right==NULL){
            count++;
        }
        else{
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
        }
    }
    deleteLinkedQueue(queue);
    return count;
}


int noOfFullNodesInBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root->left!=NULL&&root->right!=NULL){
            count++;
        }
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
    }
    deleteLinkedQueue(queue);
    return count;
}




int noOfHalfNodesInBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root->left!=NULL&&root->right==NULL){
            count++;
        }
        if(root->left==NULL&&root->right!=NULL){
            count++;
        }
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
    }
    deleteLinkedQueue(queue);
    return count;
}

int isStructurallyIdentical(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return 1;
    }
    else if(root1==NULL||root2==NULL){
        return 0;
    }
    return(isStructurallyIdentical(root1->left,root2->left)&&isStructurallyIdentical(root1->right,root2->right));
}

int diameterOfBinaryTree(node* root,int* height){
    int ld=0;
    int rd=0;
    int lh=0;
    int rh=0;
    if(root==NULL){
        *height=0;
        return 0;
    }
    
    ld=diameterOfBinaryTree(root->left,&lh);
    rd=diameterOfBinaryTree(root->right,&rh);
    
    *height=max(lh,rh)+1;
    
    return max(max(ld,rd),lh+rh+1);
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int maxSumLevelOfBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int currentSum=0;
    int maxSum=0;
    int maxLevel=0;
    int level=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    enqueueLinkedQueue(queue,NULL);
    while(!isEmptyLinkedQueue(queue)){
        root=dequeueLinkedQueue(queue);
        if(root==NULL){
            if(currentSum>maxSum){
                maxSum=currentSum;
                maxLevel=level;
            }
            currentSum=0;
            if(!isEmptyLinkedQueue(queue)){
                enqueueLinkedQueue(queue,NULL);
                level++;
            }
        }
        else{
            currentSum=currentSum+root->data;
            
            if(root->left!=NULL){
                enqueueLinkedQueue(queue,root->left);
            }
            if(root->right!=NULL){
                enqueueLinkedQueue(queue,root->right);
            }
        }
    }
    deleteLinkedQueue(queue);
    return level;
}

void printAllRootToLeafPath(node* root,int pathlen,int path[]){
    if(root==NULL){
        return;
    }
    path[pathlen]=root->data;
    pathlen++;
    if(root->left==NULL&&root->right==NULL){
        printArray(path,pathlen);
    }
    else{
        printAllRootToLeafPath(root->left,pathlen,path);
        printAllRootToLeafPath(root->right,pathlen,path);
    }
}

void printArray(int path[],int pathlen){
    int i=0;
    for(i=0;i<pathlen;i++){
        printf("%d ",path[i]);
    }
    printf("\n");
}


int hasPathSum(node* root,int sum){
    if(root==NULL){
        return 0;
    }
    int retVal=0;
    sum=sum-root->data;
    if(sum==0){
        return 1;
    }
    retVal=hasPathSum(root->left,sum);
    if(retVal!=1){
        hasPathSum(root->right,sum);
    }
}

int sumOfAllElements(node* root){
    if(root==NULL){
        return 0;
    }
    return (root->data+sumOfAllElements(root->left)+sumOfAllElements(root->right));
}

int sumOfAllElementsIterative(node* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    while(!isEmptyLinkedQueue(queue)){
        root=(node*) dequeueLinkedQueue(queue);
        sum=sum+root->data;
        if(root->left!=NULL){
            enqueueLinkedQueue(queue,root->left);
        }
        if(root->right!=NULL){
            enqueueLinkedQueue(queue,root->right);
        }
    }
    deleteLinkedQueue(queue);
    return sum;
}

node* mirrorABinaryTreeRecursive(node* root){
    node* temp=NULL;
    if(root!=NULL){
        mirrorABinaryTreeRecursive(root->left);
        mirrorABinaryTreeRecursive(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}

int areMirrors(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return 1;
    }
    if(root1==NULL||root2==NULL){
        return 0;
    }
    if(root1->data!=root2->data){
        return 0;
    }
    return (areMirrors(root1->left,root2->right)&&areMirrors(root1->right,root2->left));
}