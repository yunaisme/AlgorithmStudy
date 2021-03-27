/* https://www.hackerrank.com/challenges/bomber-man/problem */
/* 2021-03-27 */

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
char ch[300];
int n,m,T,pd[300][300],bo[300][300];
const int gox[4]={1,-1,0,0},goy[4]={0,0,1,-1};

void print(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (pd[i][j]==0) putchar('.'); 
            else putchar('O');
        }
        cout<<endl;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&T);
    
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        for (int j=1;j<=m;j++) 
            pd[i][j]=(ch[j]=='O');
    }
    
    if (T==1){
        print(); 
        return 0;
    }
    
    if (T%2==0){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) 
                pd[i][j]=1;
        print(); 
        return 0;
    }
    
    memcpy(bo,pd,sizeof bo);
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=0;k<4;k++)
                pd[i][j]|=bo[i+gox[k]][j+goy[k]];
                
    if ((T/2)%2==0){
        memcpy(bo,pd,sizeof bo);
        
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                pd[i][j]=bo[i][j];
                for (int k=0;k<4;k++)
                    if (i+gox[k]>0&&i+gox[k]<=n&&j+goy[k]>0&&j+goy[k]<=m&&bo[i+gox[k]][j+goy[k]]==0) pd[i][j]=0;
            }
        print();
    }
    else {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) pd[i][j]^=1;
        print();
    }
}
