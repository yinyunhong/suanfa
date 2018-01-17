#include<iostream.h>     
const int c = 10;             //背包的容量    
const int w[] = {3,2,5,6,4};//物品的重量   
const int v[] = {3,4,5,2,6};//物品对应的待加    
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //n为物品的个数     
int x[n];    
#define max(a,b)  (a>b)?a:b
void package01(int m[][10],const int w[],const int v[],const int n)//n代表物品的个数     
{    
    int i, j;   //放置最后一个物品时 
    for(j = 1; j <= c; j++)    
    {  
       if(j < w[n]) //背包容量小于最后一个物品的重量时  
           m[n][j-1] = 0;   //置0，表示放不下  
       else           
           m[n][j-1] = v[n];  //背包能够放下最后一个物品时,置1
    }  
           
 
    for(i = n-1; i >= 0; i--)    //放前n-1个物品
        for(j = 1; j <= c; j++)   
        {  
           if(j < w[i])     
               m[i][j-1] = m[i+1][j-1];//如果j < w[i]则，不能放置，它等于上一个状态的值   
           else //否则，比较到底是放置前后的值，选择较大者的
			   
               m[i][j-1] = max(m[i+1][j-1] ,m[i+1][j-1-w[i]]+v[i] );  
        }  
}    
void answer(int m[][10],const int n)    
{    
    int j = c-1; /*i = 0, j= c-1坐标上存放着背包容量为c时的最大价值*/   
    int i;   
      
    for(i = 0; i < n; i++)    
        if(m[i][j] == m[i+1][j])   
            x[i] = 0;    
        else                  
        {     
            x[i] = 1;  
            j = j - w[i];  //当物品放入背包后，重新计算背包剩余容量
        }  
    i -= 1;  
    x[n] = m[i][j] ? 1 : 0;     
}    
int main()    
{    
 int m[6][10]={0};   
 int i, j;  
 int sum=0;    
 package01(m,w,v,n);    
 
 answer(m,n);    
 cout<<"最好的安排是:（1表示放该物品，0表示不放该物品）\n";    
 for(i = 0; i < 5; i++)    
 {cout<< x[i];
 if(x[i]==1) sum=sum+w[i];}
 cout<<endl;
 cout<<"背包中所放物体的总重量为：";
 cout<<sum<<"kg";
 
 cout<<endl;  
  
 return 0;    
}    