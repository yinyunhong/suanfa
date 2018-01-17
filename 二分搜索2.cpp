#include<iostream>
#include<time.h>
using namespace std;


int binarysearchDG(int array[],int x,int y,int key)
{
    int m=x+(y-x)/2;
    if(x>y)
        return -1;
    else
    {
        if(array[m]==key)
            return m;
        else if(array[m]>key)
            return binarysearchDG(array,x,m-1,key);//找左边
         else
            return binarysearchDG(array,m+1,y,key);//找右边
    }
}
void main()
{   int a[100];
    clock_t time;
	time=clock();
	int i,m,n,result, low,high,key;
	cout<<"请输入要查找的数字个数：";
	cin>>n;
	cout<<"请输入查找数组的元素：（由小到大）";
	for(i=0;i<n;i++)
	{cin>>a[i];}
	low=0;
	high=n-1;
	cout<<"请输入待查找的元素：";
	cin>>key;
    m=binarysearchDG(a,0,n-1,key);
	cout<<"待查找的元素的位置在："<<m<<endl;
    time=(clock()-time)/CLOCKS_PER_SEC;
    cout<<"执行时间："<<double(time)<<"ms"<<endl;
    }