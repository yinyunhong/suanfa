#include<iostream>  
#include<string>  
#include<queue> 
#include<vector> 
using namespace std;  
  
typedef int KeyType;  
#define NUM 13  
class BinSTree;  
class BinStreeNode  
{  
public:  
    KeyType key;  
    BinStreeNode *lchild;  
    BinStreeNode *rchild;  
    BinStreeNode()  
    {  
        lchild=NULL;  
        rchild=NULL;  
    }  
};  
  
class BinSTree  
{  
public:  
    BinStreeNode *root;  
    BinSTree()  
    {  
        root=NULL;  
    }  
    ~BinSTree()  
    {  
        //delete root;  
    }  
    BinStreeNode *BSTreeSearch(/*BinStreeNode *bt,*/KeyType k,BinStreeNode *&p);//����ʧ�ܷ���NULL,p��¼������ĸ����  
    void BSTreeInsert(KeyType k);//bt�����ã�������Ϊ����㣬��Ҫ�޸�root  
     
    int isValidBST(BinStreeNode *bt,int lower,int upper);  
    void BSTreeInOrder(BinStreeNode *bt); 
	int BSTreeInOrder1(BinStreeNode *bt,int k1,int k2);
     
    void BSTreeLevelTraverse(BinStreeNode *bt);//��α���  
    bool IsEmpty()  
    {  
        return root==NULL;  
    }  
};  
/* 
* ���������������㷨 
* �ڸ�ָ��Ϊbt�Ķ����������в���Ԫ��k�Ľڵ㣬�����ҳɹ����򷵻�ָ��ýڵ��ָ�� 
* ���ҳɹ�ʱ������pָ����ҵ��Ľ��;����ʧ��ʱ������pָ��kӦ����ĸ��ڵ� 
*/  
BinStreeNode *BinSTree::BSTreeSearch(/*BinStreeNode *bt,*/KeyType k,BinStreeNode *&p)  
{  
    BinStreeNode *q=NULL;  
    q=root;  
    while(q)  
    {  
        p=q;  
        if(q->key==k)  
            return p;  
        else if(q->key>k)  
            q=q->lchild;  
        else  
            q=q->rchild;  
    }  
    return NULL;  
}  
//�������  
void BinSTree::BSTreeInsert(KeyType k)  
{  
    BinStreeNode *p=NULL,*q;  
    q=root;  
    if(BSTreeSearch(k,p)==NULL)//����ʧ��ʱ�Ų���  
    {  
        BinStreeNode *r=new BinStreeNode;  
        r->key=k;  
        if(q==NULL)//�����Ϊ��  
        {  
            root=r;  
            return ;  
        }  
        if(p&&k<p->key)  
            p->lchild=r;  
        else if(p&&k>p->key)  
            p->rchild=r;  
    }  
}  
  

//�������  
int BinSTree::BSTreeInOrder1(BinStreeNode *bt,int k1,int k2) //ʱ�临�Ӷ�O(N);  
{  int b[100];
   int i=0;
   int n=0;
   
    if(bt)  
    {  
          
        BSTreeInOrder(bt->lchild); 
		
        {cout<<bt->key<<" ";
		 
		if(bt->key>=k1&&bt->key<=k2)
		{b[i]=bt->key;
		i++;n++;} }
        BSTreeInOrder(bt->rchild);  
    } 
	cout<<endl;
	cout<<"������"<<k1<<","<<k2<<"֮��Ľ���У�";
    for(i=0;i<n;i++)
		cout<<b[i];

    return 1;

} 

void BinSTree::BSTreeInOrder(BinStreeNode *bt) //���������ʱ�临�Ӷ�O(N);  
{  
    if(bt)  
    {  
          
        BSTreeInOrder(bt->lchild); 
		
        cout<<bt->key<<" ";  
        BSTreeInOrder(bt->rchild);  
    } 

}  

//��α���  
void BinSTree::BSTreeLevelTraverse(BinStreeNode *bt)  
{  
    queue<BinStreeNode*> q;  
    if(bt)  
        q.push(bt);  
    while(!q.empty())  
    {  
        cout<<q.front()->key<<" ";//���ʶ�ͷ���  
        if(q.front()->lchild)  
            q.push(q.front()->lchild);  
        if(q.front()->rchild)  
            q.push(q.front()->rchild);  
        q.pop();  
    }  
    cout<<endl;  
}  
int BinSTree::isValidBST(BinStreeNode *bt,int lower,int upper) {
 

        if (bt == NULL) return 1;

        if (bt->key <= lower || bt->key >= upper) return 0;
        int isLeftValidBST =isValidBST(bt->lchild, lower, bt->key);
        int isRightValidBST =isValidBST(bt->rchild, bt->key, upper);

        return (isLeftValidBST && isRightValidBST);
    }
int main()  
{  
    int a[NUM]={34, 18, 76, 13,12,11, 52, 82, 16, 67, 58, 73, 72 }; 
	
    BinSTree bst;  
    BinStreeNode *pBt = NULL, *p = NULL, *pT = NULL;  
	cout<<"����ڵ�󣬰���α����У�"<<endl;
    for(int i=0;i<NUM;i++)  //����α���������
    {  
        bst.BSTreeInsert(a[i]);  
    }  
	
    pT = bst.BSTreeSearch(52, p ); //���������Ƿ�������������� 
    bst.BSTreeLevelTraverse(bst.root);  
    if(pT)  
    {  
        cout<<pT->key<<"�����ڶ�������"<<endl;  
    }  
	
	cout<<"������������:"<<endl;
    bst.BSTreeInOrder1(bst.root,20,50); //���������k1��k2��Χ֮�������
    cout << endl; 
	
    int m=bst.isValidBST(bst.root,11,82);//�ж϶������Ƿ���Ч
    if(m==0)  cout<<"ԭ������һ����Ч�Ķ�����";
    else cout<<"ԭ������Ч�Ķ�����";
    cout<<endl;
   
    system("pause");  
    return 0;  
}  