#include <iostream>  
#include <string>
#include <time.h> 
 
using namespace std;  
  
//����ÿһ�εĲ���ƥ��ֵ����str=="abcdab"ʱ����ֵΪ2  
int everymatch(string str)  
{  
    int num=0;  //ƥ��ֵ������
    int n=str.length();  
    string pre,back;  
  
    for(int i=0;i!=n-1;++i){  
        pre=str.substr(0,i+1);  //��ǰi+1���ַ�����pre��
        back=str.substr(n-1-i);  //����i+1���ַ�����back��
        if(pre==back)  
            num=pre.length();  //��ʾ��ƥ����ַ��ĸ���
    }  
    return num;  
}  
  
//�������ѯ��Ŀ���ַ����Ĳ���ƥ���  
void targetmatch(string str,int* table)  
{  
    int n=str.length();  
    for(int i=0;i!=n;++i){  
        string b=str.substr(0,i+1);                       
        int temp=everymatch(b);   //����Ŀ���ַ�����ÿ���ַ��Ĳ���ƥ��ֵ     
        table[i]=temp;  //�������¼ÿ���ַ��Ĳ���ƥ��ֵ
    }  
}  
  
// KMP�㷨  
int KMP(string str1,string str2,int *table)  
{  
	
    int n1=str1.length();  
    int n2=str2.length();  
    int i,j; 

    for(i=0;i<n1-n2;i++)//��Ŀ���ַ���λ��Դ�ַ��������λ��ʱ����i=n1-n2ʱ�˳�ѭ��
	{  
          
        for(j=0;j<n2;j++)
		{  
            if(str1[i+j]==str2[j]) //��Ŀ���ַ����е��ַ���Դ�ַ����ַ����ʱ��j��1�����Ƚ������ַ� 
                continue; 
            else  break; //����ʱ������Ŀ���ַ�����ѭ�� 
        }  
        if(j==n2)  
           break;  //Ŀ���ַ�����Դ�ַ���ÿ���ַ������ʱ������Դ�ַ�����ѭ��
        else if(j==0)  
             continue; //Ŀ���ַ����ĵ�һ���ַ�����Դ�ַ��������ʱ��Ŀ���ַ��������һλ
        else  
            i+=j-1-table[j-1]; // Ŀ���ַ�����Դ�ַ����������ַ���ͬʱ
    }  
  
    if(i>n1-n2)  
       return -1;  
    return i;  
}  

  
int main()  
{    string source;
    string target;
    cout<<"������Դ�ַ�����\n";
	cin>>source;
	cout<<"������Ŀ���ַ�����\n";
	cin>>target;
	
    clock_t time;
	time=clock(); 
    int n=target.length();  
    int *table=new int[n];  
  
    targetmatch(target,table);  
    cout<<"Ŀ���ַ�����ÿ���ַ��Ĳ���ƥ��ֵ��"<<endl;
    for(int i=0;i<n;++i)  
        cout<<table[i]<<' ';  
    cout<<endl;  
    cout<<"Ŀ���ַ�����Դ�ַ�������ʼλ��Ϊ��"<<endl; 
    cout<<KMP(source,target,table)<<endl;  
    time=clock()-time;
    cout<<"ִ��ʱ�䣺"<<double(time)<<"s"<<endl;
    return 0;  
}