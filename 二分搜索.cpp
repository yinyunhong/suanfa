#include<iostream.h>
#include<time.h>
int bsearchFDG(int array[],int low,int high,int target)
{
    while(low<=high)
        {
            int mid=(low+high)/2;
            if(array[mid]>target)
                high=mid-1;
            else if(array[mid]<target)
            low=mid+1;
            else
                return mid;
        }
    return-1;
}
void main()
{   
	clock_t start, finish; 
    double duration=0; 
    start = clock(); 
	int a[100];
	int i,n,result, low,high,key;
	cout<<"������Ҫ���ҵ����ָ�����";
	cin>>n;
	cout<<"��������������Ԫ�أ�����С����";
	for(i=0;i<n;i++)
	{cin>>a[i];}
	low=0;
	high=n-1;
	cout<<"����������ҵ�Ԫ�أ�";
	cin>>key;
    result=bsearchFDG(a,low,high,key);
	cout<<"�����ҵ�Ԫ�ص�λ���ڣ�"<<result<<endl;
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    cout<<"ִ��ʱ�䣺"<< duration<<"ms"<<endl;
}