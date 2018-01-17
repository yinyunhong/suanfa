#include<iostream.h>
#include<string.h>
#include<time.h>


int strStr(char* haystack, char* needle) {
    if (haystack == NULL || needle == NULL) return -1;
    int i,j,h,n;
    h=strlen(haystack);
    n=strlen(needle);
    for (i=0;i<h-n+1;i++) {
         j=0;
        for (;j<n;j++) {
            if (haystack[i+j] != needle[j]) {
                break;
            }
        }
        if (j == n) return i;
    }

    return -1;
}
void main()
{
	clock_t time;
	time=clock();
	int m;
	char source[100];
	char target[100];
	cout<<"请输入源字符串：\n";
	cin>>source;
	cout<<"请输入目的字符串：\n";
	cin>>target;
	m=strStr(source,target);
	cout<<"目的字符串在源字符串中第一次出现的起始位置为："<<m;
    cout<<endl;
    time=(clock()-time)/CLOCKS_PER_SEC;
    cout<<"执行时间："<<double(time)<<"s"<<endl;
}
