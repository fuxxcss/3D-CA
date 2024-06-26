#include<stdio.h>
#define SIZE 8
#include"block-key.c"

int main(){
    //when K=M
    //64B
    int M[SIZE][SIZE][SIZE]={
        {{0,1,0,0,1,1,0,0},{0,1,1,0,1,1,1,1},{0,1,1,0,1,1,1,1},{0,1,1,0,1,0,1,1},{0,1,1,0,1,0,0,1},{0,1,1,0,1,1,1,0},{0,1,1,0,0,1,1,1},{0,0,1,0,0,0,0,0}},
        {{0,1,1,0,1,0,0,1},{0,1,1,0,1,1,1,0},{0,1,1,1,0,1,0,0},{0,1,1,0,1,1,1,1},{0,0,1,0,0,0,0,0},{0,1,1,1,1,0,0,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,0,1}},
        {{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0},{0,1,1,1,0,0,0,0},{0,1,1,0,0,0,0,1},{0,1,1,1,0,0,1,1},{0,1,1,1,0,1,0,0},{0,0,1,0,0,0,0,0},{0,1,1,0,1,0,0,1}},
        {{0,1,1,1,0,0,1,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,0},{0,1,1,0,1,0,0,0},{0,1,1,0,0,1,0,1},{0,0,1,0,0,0,0,0},{0,1,1,0,1,1,1,1},{0,1,1,0,1,1,1,0}},
        {{0,1,1,0,1,1,0,0},{0,1,1,1,1,0,0,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,1,1},{0,1,1,0,0,0,0,1},{0,1,1,1,1,0,0,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,0}},
        {{0,1,1,0,1,1,1,1},{0,0,1,0,0,0,0,0},{0,1,1,0,0,1,0,0},{0,1,1,0,1,0,0,1},{0,1,1,1,0,0,1,1},{0,1,1,0,0,0,1,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,1,0}},
        {{0,1,1,0,0,1,0,1},{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0},{0,1,1,1,1,0,0,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,0,1},{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0}},
        {{0,1,1,0,0,1,1,0},{0,1,1,1,0,1,0,1},{0,1,1,1,0,1,0,0},{0,1,1,1,0,1,0,1},{0,1,1,1,0,0,1,0},{0,1,1,0,0,1,0,1},{0,0,1,0,1,1,1,0},{0,0,1,0,1,1,1,0}}                          
    };
    int K[SIZE][SIZE][SIZE]={
        {{0,1,0,0,1,1,0,0},{0,1,1,0,1,1,1,1},{0,1,1,0,1,1,1,1},{0,1,1,0,1,0,1,1},{0,1,1,0,1,0,0,1},{0,1,1,0,1,1,1,0},{0,1,1,0,0,1,1,1},{0,0,1,0,0,0,0,0}},
        {{0,1,1,0,1,0,0,1},{0,1,1,0,1,1,1,0},{0,1,1,1,0,1,0,0},{0,1,1,0,1,1,1,1},{0,0,1,0,0,0,0,0},{0,1,1,1,1,0,0,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,0,1}},
        {{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0},{0,1,1,1,0,0,0,0},{0,1,1,0,0,0,0,1},{0,1,1,1,0,0,1,1},{0,1,1,1,0,1,0,0},{0,0,1,0,0,0,0,0},{0,1,1,0,1,0,0,1}},
        {{0,1,1,1,0,0,1,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,0},{0,1,1,0,1,0,0,0},{0,1,1,0,0,1,0,1},{0,0,1,0,0,0,0,0},{0,1,1,0,1,1,1,1},{0,1,1,0,1,1,1,0}},
        {{0,1,1,0,1,1,0,0},{0,1,1,1,1,0,0,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,1,1},{0,1,1,0,0,0,0,1},{0,1,1,1,1,0,0,1},{0,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,0}},
        {{0,1,1,0,1,1,1,1},{0,0,1,0,0,0,0,0},{0,1,1,0,0,1,0,0},{0,1,1,0,1,0,0,1},{0,1,1,1,0,0,1,1},{0,1,1,0,0,0,1,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,1,0}},
        {{0,1,1,0,0,1,0,1},{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0},{0,1,1,1,1,0,0,1},{0,1,1,0,1,1,1,1},{0,1,1,1,0,1,0,1},{0,1,1,1,0,0,1,0},{0,0,1,0,0,0,0,0}},
        {{0,1,1,0,0,1,1,0},{0,1,1,1,0,1,0,1},{0,1,1,1,0,1,0,0},{0,1,1,1,0,1,0,1},{0,1,1,1,0,0,1,0},{0,1,1,0,0,1,0,1},{0,0,1,0,1,1,1,0},{0,0,1,0,1,1,1,0}}
    };
    key_generator(K);
    printf("Key generated\n");
    encryption(M,K);
    printf("Message encrypted\n");
    FILE *fp;
    fp=fopen("block.cipher","r");
    int C[SIZE][SIZE][SIZE];
    fread(C,sizeof(int),SIZE*SIZE*SIZE,fp);
    printf("C\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){ 
           for(int k=0;k<SIZE;k++) printf("%d",C[i][j][k]);
           printf(" ");}
        printf("\n");
    }
    int K_[SIZE][SIZE][SIZE];
    fp=fopen("block.key","r");
    fread(K_,sizeof(int),SIZE*SIZE*SIZE,fp);
    printf("\n");
    decryption(C,K_);
    printf("Messagae decrypted\n");
    fp=fopen("block.message","r");
    fread(M,sizeof(int),SIZE*SIZE*SIZE,fp);
    printf("M\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++) 
           for(int k=0;k<SIZE;k++) if(M[i][j][k]==K_[i][j][k]) printf("Y ");
        printf("\n");
    }
    printf("\n");
}