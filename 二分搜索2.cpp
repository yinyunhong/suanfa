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
            return binarysearchDG(array,x,m-1,key);//�����
         else
            return binarysearchDG(array,m+1,y,key);//���ұ�
    }
}
void main()
{   int a[100];
    clock_t time;
	time=clock();
	int i,m,n,result, low,high,key;
	cout<<"������Ҫ���ҵ����ָ�����";
	cin>>n;
	cout<<"��������������Ԫ�أ�����С����";
	for(i=0;i<n;i++)
	{cin>>a[i];}
	low=0;
	high=n-1;
	cout<<"����������ҵ�Ԫ�أ�";
	cin>>key;
    m=binarysearchDG(a,0,n-1,key);
	cout<<"�����ҵ�Ԫ�ص�λ���ڣ�"<<m<<endl;
    time=(clock()-time)/CLOCKS_PER_SEC;
    cout<<"ִ��ʱ�䣺"<<double(time)<<"ms"<<endl;
    }