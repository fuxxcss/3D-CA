#include<stdio.h>
#include"ca8.c"

void key_generator(int (*K)[SIZE][SIZE]){
    FILE *fp;
    fp=fopen("block.key","w");
    //block.key input K
    fwrite(K,sizeof(int),SIZE*SIZE*SIZE,fp);
    //if not fclose,K will be broken
    fclose(fp);
}

void encryption(int (*M)[SIZE][SIZE],int (*K)[SIZE][SIZE]){
    int n=64;
    FILE *fp;
    //n rounds encryption
    for(int l=1;l<n+1;l++){
        for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) M[i][j][k]^=K[i][j][k];
        op(M,0,l);
    }
    fp=fopen("block.cipher","w");
    //block.cipher input C
    fwrite(M,sizeof(int),SIZE*SIZE*SIZE,fp);
    fclose(fp);
}

void decryption(int (*C)[SIZE][SIZE],int (*K)[SIZE][SIZE]){
    int n=64;
    FILE *fp;
    //n rounds decryption
    for(int l=n;l>0;l--){
        opr(C,l);
        for(int i=0;i<SIZE;i++)
           for(int j=0;j<SIZE;j++)
              for(int k=0;k<SIZE;k++) C[i][j][k]^=K[i][j][k];
    }
    fp=fopen("block.message","w");
    //message output 
    fwrite(C,sizeof(int),SIZE*SIZE*SIZE,fp);
    fclose(fp);
}