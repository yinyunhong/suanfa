#include <iostream>  
#include <string>
#include <time.h> 
 
using namespace std;  
  
//计算每一次的部分匹配值，如str=="abcdab"时返回值为2  
int everymatch(string str)  
{  
    int num=0;  //匹配值的数量
    int n=str.length();  
    string pre,back;  
  
    for(int i=0;i!=n-1;++i){  
        pre=str.substr(0,i+1);  //将前i+1个字符放入pre中
        back=str.substr(n-1-i);  //将后i+1个字符放入back中
        if(pre==back)  
            num=pre.length();  //表示相匹配的字符的个数
    }  
    return num;  
}  
  
//计算待查询的目的字符串的部分匹配表  
void targetmatch(string str,int* table)  
{  
    int n=str.length();  
    for(int i=0;i!=n;++i){  
        string b=str.substr(0,i+1);                       
        int temp=everymatch(b);   //计算目的字符串中每个字符的部分匹配值     
        table[i]=temp;  //用数组记录每个字符的部分匹配值
    }  
}  
  
// KMP算法  
int KMP(string str1,string str2,int *table)  
{  
	
    int n1=str1.length();  
    int n2=str2.length();  
    int i,j; 

    for(i=0;i<n1-n2;i++)//当目标字符串位于源字符串的最后位置时，即i=n1-n2时退出循环
	{  
          
        for(j=0;j<n2;j++)
		{  
            if(str1[i+j]==str2[j]) //当目标字符串中的字符与源字符串字符相等时，j加1，向后比较其它字符 
                continue; 
            else  break; //不等时，跳出目标字符串的循环 
        }  
        if(j==n2)  
           break;  //目标字符串与源字符串每个字符都相等时，跳出源字符串的循环
        else if(j==0)  
             continue; //目标字符串的第一个字符就与源字符串不相等时，目标字符串向后移一位
        else  
            i+=j-1-table[j-1]; // 目标字符串与源字符串仅部分字符相同时
    }  
  
    if(i>n1-n2)  
       return -1;  
    return i;  
}  

  
int main()  
{    string source;
    string target;
    cout<<"请输入源字符串：\n";
	cin>>source;
	cout<<"请输入目的字符串：\n";
	cin>>target;
	
    clock_t time;
	time=clock(); 
    int n=target.length();  
    int *table=new int[n];  
  
    targetmatch(target,table);  
    cout<<"目标字符串中每个字符的部分匹配值："<<endl;
    for(int i=0;i<n;++i)  
        cout<<table[i]<<' ';  
    cout<<endl;  
    cout<<"目标字符串在源字符串的起始位置为："<<endl; 
    cout<<KMP(source,target,table)<<endl;  
    time=clock()-time;
    cout<<"执行时间："<<double(time)<<"s"<<endl;
    return 0;  
}