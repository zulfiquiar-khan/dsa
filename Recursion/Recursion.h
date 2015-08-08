#include<stdio.h>
#include<stdlib.h>



int  generateAllBinaryString(int n,char * A){
    if(n<1){
        printf("%s\n",A);
        return  0;
    }
    else{
            A[n-1]='0';
            generateAllBinaryString(n-1,A);
            A[n-1]='1';
            generateAllBinaryString(n-1,A);
    }
    
}

void generateKaryString(int n,int  k,char *nArray,char *kArray){
    if(n<1){
        printf("%s\n",nArray);
        return;
    }else{
        int i;
        for(i=0;i<k;i++){
            nArray[n-1]=kArray[i];
            generateKaryString(n-1,k,nArray,kArray);
        }
    }
        
}


int getValue(int r,int c,int L,int H,int  matrix[][H]){
        if((r>=L||r<0 )||(c>=H||c<0)){
            return 0;
        }
        return  matrix[r][c];
}


void findMaximumContinuousOnes(int i,int j,int L,int H,int *matrix[][H],int flagMatrix[][H],int size,int  *maxSize){
    
    if(getValue(i,j,L,H,matrix)==0){
        return;
    }
    
    size++;
    flagMatrix[i][j]=1;
    if(*maxSize<=size){
        *maxSize=size;
    }
   
    int direction[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    int counter;
    for(counter=0;counter<8;counter++){
        
        int newI=i+direction[counter][0];
        int newJ=j+direction[counter][1];
        int val=getValue(newI,newJ,L,H,matrix);
        if(val>0 && flagMatrix[newI][newJ]==0){
                    findMaximumContinuousOnes(newI,newJ,L,H,matrix,flagMatrix,size,maxSize);
            
        }
    }
    flagMatrix[i][j]=0;
}

int  getMaxOnes( ){
    int i;
    int j;
    int  maxsize=0;
    int matrix[5][5]={{1,1,0,0,0},{0,1,1,0,1},{0,0,0,1,1},{1,0,0,1,1},{0,1,0,1,1}};
     int flagmatrix[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
     for(i=0;i<5;i++){
         for(j=0;j<5;j++){
             printf("going to recurse (%d,%d)\n",i,j);
             printf(" Before : %u ->%d\n",&maxsize ,maxsize);
            findMaximumContinuousOnes(i,j,5,5,matrix,flagmatrix,0,&maxsize);
            printf("After : %u ->%d\n",&maxsize ,maxsize);
     }
     }
     
     printf("final  ma size :x %d\n",maxsize);
}
