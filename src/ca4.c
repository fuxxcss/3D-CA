#define SIZE 4
//buffer
int new[SIZE][SIZE][SIZE];
void S_top_rule(int (*ca)[SIZE][SIZE],int irr){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        if(irr==0) new[i][j][k]=*(*(*(ca+i)+j)+k);
        else new[i][j][k]=0;
        if(i==0 || i==SIZE-1){
            if(i==SIZE-1){
            new[i][j][k] ^=*(*(*(ca)+j)+k);
            new[i][j][k] ^=*(*(*(ca+SIZE-2)+j)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+SIZE-1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+1)+j)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i+1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+i-1)+j)+k);
        }
        if(j==0 || j==SIZE-1){
            if(j==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i))+k);
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-2)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+1)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j+1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+j-1)+k);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

void S_front_rule(int (*ca)[SIZE][SIZE],int irr){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        if(irr==0) new[i][j][k]=*(*(*(ca+i)+j)+k);
        else new[i][j][k]=0;
        if(i==0 || i==SIZE-1){
            if(i==SIZE-1){
            new[i][j][k] ^=*(*(*(ca)+j)+k);
            new[i][j][k] ^=*(*(*(ca+SIZE-2)+j)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+SIZE-1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+1)+j)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i+1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+i-1)+j)+k);
        }
        if(k==0 || k==SIZE-1){
            if(k==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i)+j));
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-2);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+1);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+k+1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+k-1);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

void S_side_rule(int (*ca)[SIZE][SIZE],int irr){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        if(irr==0) new[i][j][k]=*(*(*(ca+i)+j)+k);
        else new[i][j][k]=0;
        if(k==0 || k==SIZE-1){
            if(k==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i)+j));
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-2);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+1);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+k+1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+k-1);
        }
        if(j==0 || j==SIZE-1){
            if(j==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i))+k);
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-2)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+1)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j+1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+j-1)+k);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

//Permutation
//p=0,1,2 each has 16 rows
void P_rule(int (*ca)[SIZE][SIZE],int p,int row1,int row2){
    if(p==0){
        for(int i=0;i<SIZE;i++){
            *(*(*(ca+row1%SIZE)+i)+row1/SIZE)^=*(*(*(ca+row2%SIZE)+i)+row2/SIZE);
            *(*(*(ca+row2%SIZE)+i)+row2/SIZE)^=*(*(*(ca+row1%SIZE)+i)+row1/SIZE);
            *(*(*(ca+row1%SIZE)+i)+row1/SIZE)^=*(*(*(ca+row2%SIZE)+i)+row2/SIZE);
           }
    }
    else if(p==1){
        for(int i=0;i<SIZE;i++){
            *(*(*(ca+i)+row1%SIZE)+row1/SIZE)^=*(*(*(ca+i)+row2%SIZE)+row2/SIZE);
            *(*(*(ca+i)+row2%SIZE)+row2/SIZE)^=*(*(*(ca+i)+row1%SIZE)+row1/SIZE);
            *(*(*(ca+i)+row1%SIZE)+row1/SIZE)^=*(*(*(ca+i)+row2%SIZE)+row2/SIZE);
        }
    }
    else{
        for(int i=0;i<SIZE;i++){
            *(*(*(ca+row1%SIZE)+row1/SIZE)+i)^=*(*(*(ca+row2%SIZE)+row2/SIZE)+i);
            *(*(*(ca+row2%SIZE)+row2/SIZE)+i)^=*(*(*(ca+row1%SIZE)+row1/SIZE)+i);
            *(*(*(ca+row1%SIZE)+row1/SIZE)+i)^=*(*(*(ca+row2%SIZE)+row2/SIZE)+i);
        }
    }
}

void op(int (*ca)[SIZE][SIZE],int irr,int k){
    if(k%3==0){
    S_top_rule(ca,irr);
    P_rule(ca,0,k%16,k*k%16);
    P_rule(ca,1,k%16,k*k%16);
    P_rule(ca,2,k%16,k*k%16);
    }
    else if(k%3==1){
    S_front_rule(ca,irr);
    P_rule(ca,0,k%16,k*k%16);
    P_rule(ca,1,k%16,k*k%16);
    P_rule(ca,2,k%16,k*k%16);
    }
    else{
    S_side_rule(ca,irr);
    P_rule(ca,0,k%16,k*k%16);
    P_rule(ca,1,k%16,k*k%16);
    P_rule(ca,2,k%16,k*k%16);
    }
}
