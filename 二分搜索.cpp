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
	cout<<"请输入要查找的数字个数：";
	cin>>n;
	cout<<"请输入查找数组的元素：（由小到大）";
	for(i=0;i<n;i++)
	{cin>>a[i];}
	low=0;
	high=n-1;
	cout<<"请输入待查找的元素：";
	cin>>key;
    result=bsearchFDG(a,low,high,key);
	cout<<"待查找的元素的位置在："<<result<<endl;
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    cout<<"执行时间："<< duration<<"ms"<<endl;
}