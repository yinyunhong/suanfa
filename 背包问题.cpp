#include<iostream.h>     
const int c = 10;             //����������    
const int w[] = {3,2,5,6,4};//��Ʒ������   
const int v[] = {3,4,5,2,6};//��Ʒ��Ӧ�Ĵ���    
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //nΪ��Ʒ�ĸ���     
int x[n];    
#define max(a,b)  (a>b)?a:b
void package01(int m[][10],const int w[],const int v[],const int n)//n������Ʒ�ĸ���     
{    
    int i, j;   //�������һ����Ʒʱ 
    for(j = 1; j <= c; j++)    
    {  
       if(j < w[n]) //��������С�����һ����Ʒ������ʱ  
           m[n][j-1] = 0;   //��0����ʾ�Ų���  
       else           
           m[n][j-1] = v[n];  //�����ܹ��������һ����Ʒʱ,��1
    }  
           
 
    for(i = n-1; i >= 0; i--)    //��ǰn-1����Ʒ
        for(j = 1; j <= c; j++)   
        {  
           if(j < w[i])     
               m[i][j-1] = m[i+1][j-1];//���j < w[i]�򣬲��ܷ��ã���������һ��״̬��ֵ   
           else //���򣬱Ƚϵ����Ƿ���ǰ���ֵ��ѡ��ϴ��ߵ�
			   
               m[i][j-1] = max(m[i+1][j-1] ,m[i+1][j-1-w[i]]+v[i] );  
        }  
}    
void answer(int m[][10],const int n)    
{    
    int j = c-1; /*i = 0, j= c-1�����ϴ���ű�������Ϊcʱ������ֵ*/   
    int i;   
      
    for(i = 0; i < n; i++)    
        if(m[i][j] == m[i+1][j])   
            x[i] = 0;    
        else                  
        {     
            x[i] = 1;  
            j = j - w[i];  //����Ʒ���뱳�������¼��㱳��ʣ������
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
 cout<<"��õİ�����:��1��ʾ�Ÿ���Ʒ��0��ʾ���Ÿ���Ʒ��\n";    
 for(i = 0; i < 5; i++)    
 {cout<< x[i];
 if(x[i]==1) sum=sum+w[i];}
 cout<<endl;
 cout<<"���������������������Ϊ��";
 cout<<sum<<"kg";
 
 cout<<endl;  
  
 return 0;    
}    