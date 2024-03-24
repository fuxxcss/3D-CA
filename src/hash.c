#include<stdio.h>
#include<stdlib.h>
#include"ca8.c"
//biggest length 2^512-1 B in the last block
//block size is 512bit
int ca[SIZE][SIZE][SIZE];
int V[SIZE][SIZE][SIZE]={
        {{0,0,1,1,0,0,0,0},{0,0,1,1,0,0,0,1},{0,0,1,1,0,0,1,0},{0,0,1,1,0,0,1,1},{0,0,1,1,0,1,0,0},{0,0,1,1,0,1,0,1},{0,0,1,1,0,1,1,0},{0,0,1,1,0,1,1,1}},
        {{0,0,1,1,1,0,0,0},{0,0,1,1,1,0,0,1},{0,1,1,0,0,0,0,1},{0,1,1,0,0,0,1,0},{0,1,1,0,0,0,1,1},{0,1,1,0,0,1,0,0},{0,1,1,0,0,1,0,1},{0,1,1,0,0,1,1,0}},
        {{0,1,1,0,0,1,1,1},{0,1,1,0,1,0,0,0},{0,1,1,0,1,0,0,1},{0,1,1,0,1,0,1,0},{0,1,1,0,1,0,1,1},{0,1,1,0,1,1,0,0},{0,1,1,0,1,1,0,1},{0,1,1,0,1,1,1,0}},
        {{0,1,1,0,1,1,1,1},{0,1,1,1,0,0,0,0},{0,1,1,1,0,0,0,1},{0,1,1,1,0,0,1,0},{0,1,1,1,0,0,1,1},{0,1,1,1,0,1,0,0},{0,1,1,1,0,1,0,1},{0,1,1,1,0,1,1,0}},
        {{0,1,1,1,0,1,1,1},{0,1,1,1,1,0,0,0},{0,1,1,1,1,0,0,1},{0,1,1,1,1,0,1,0},{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,0,1,0,0}},
        {{0,1,0,0,0,1,0,1},{0,1,0,0,0,1,1,0},{0,1,0,0,0,1,1,1},{0,1,0,0,1,0,0,0},{0,1,0,0,1,0,0,1},{0,1,0,0,1,0,1,0},{0,1,0,0,1,0,1,1},{0,1,0,0,1,1,0,0}},
        {{0,1,0,0,1,1,0,1},{0,1,0,0,1,1,1,0},{0,1,0,0,1,1,1,1},{0,1,0,1,0,0,0,0},{0,1,0,1,0,0,0,1},{0,1,0,1,0,0,1,0},{0,1,0,1,0,0,1,1},{0,1,0,1,0,1,0,0}},
        {{0,1,0,1,0,1,0,1},{0,1,0,1,0,1,1,0},{0,1,0,1,0,1,1,1},{0,1,0,1,1,0,0,0},{0,1,0,1,1,0,0,1},{0,1,0,1,1,0,1,0},{0,0,1,1,0,0,0,0},{0,0,1,1,0,0,0,1}}               
};
int padded_size;
int *pad(int *M,int size){
    //len=len of size
    int len=0;
    int tmp=size;
    while(tmp!=0){
        tmp<<=1;
        len++;
    }
    int fill=512-(size+len)%512;
    padded_size=fill+size+len;
    int *new=(int *)malloc(sizeof(int)*padded_size);
    //fill M
    for(int i=0;i<size;i++) new[i]=M[i];
    //fill 1
    for(int i=size;i<size+fill-1;i++) new[i]=1;
    //fill 0
    new[size+fill]=0;
    //fill size
    tmp=size;
    for(int i=1;i<len+1;i++){
        new[i+size+fill]=tmp%2;
        tmp<<=1;
    }
    return new;
}
int *pad_salt(int *salt,int size){
    int *new=(int *)malloc(sizeof(int)*padded_size);
    //fill salt
    for(int i=0;i<size;i++) new[i]=salt[i];
    //fill 0
    for(int i=size;i<padded_size;i++) new[i]=0;
    return new;
}
void hash_salt(int *salt_pad,int *t){
    int block_size=padded_size/512;
    for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) ca[i][j][k]=salt_pad[i*64+j*8+k];
    for(int n=0;n<block_size;n++){
        int w=t[n];
        op(ca,1,w);
        for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) ca[i][j][k]^=salt_pad[n*512+i*64+j*8+k];
    }
}

int weight(int (*ca)[SIZE][SIZE]){
    int num=0;
    for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) if(ca[i][j][k]==1) num+=i*j*k;
    return num;
}
int *hash(int *M_pad,int *t,int flag){
    int block_size=padded_size/512;
    int *w_table=(int *)malloc(sizeof(int)*block_size);
    //fill the ca
    for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) ca[i][j][k]=M_pad[i*64+j*8+k];
    //H(0)=op(M(0))
    //H(r)=op(H(r-1)^M(r))
    for(int n=0;n<block_size;n++){
        int w;
        if(flag==1) w=t[n];
        else w=weight(ca);
        w_table[n]=w;
        op(ca,1,w);
        for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) ca[i][j][k]^=M_pad[n*512+i*64+j*8+k]^V[i][j][k];
    }
    FILE *fp;
    fp=fopen("block.hash","w");
    fwrite(ca,sizeof(int),SIZE*SIZE*SIZE,fp);
    fclose(fp);
    return w_table;
}

