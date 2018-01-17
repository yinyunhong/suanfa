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
    BinStreeNode *BSTreeSearch(/*BinStreeNode *bt,*/KeyType k,BinStreeNode *&p);//查找失败返回NULL,p记录待插入的父结点  
    void BSTreeInsert(KeyType k);//bt用引用，插入结点为根结点，需要修改root  
     
    int isValidBST(BinStreeNode *bt,int lower,int upper);  
    void BSTreeInOrder(BinStreeNode *bt); 
	int BSTreeInOrder1(BinStreeNode *bt,int k1,int k2);
     
    void BSTreeLevelTraverse(BinStreeNode *bt);//层次遍历  
    bool IsEmpty()  
    {  
        return root==NULL;  
    }  
};  
/* 
* 二叉排序树查找算法 
* 在根指针为bt的二叉排序树中查找元素k的节点，若查找成功，则返回指向该节点的指针 
* 查找成功时，参数p指向查找到的结点;查找失败时，参数p指向k应插入的父节点 
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
//插入操作  
void BinSTree::BSTreeInsert(KeyType k)  
{  
    BinStreeNode *p=NULL,*q;  
    q=root;  
    if(BSTreeSearch(k,p)==NULL)//查找失败时才插入  
    {  
        BinStreeNode *r=new BinStreeNode;  
        r->key=k;  
        if(q==NULL)//根结点为空  
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
  

//中序遍历  
int BinSTree::BSTreeInOrder1(BinStreeNode *bt,int k1,int k2) //时间复杂度O(N);  
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
	cout<<"在区间"<<k1<<","<<k2<<"之间的结点有：";
    for(i=0;i<n;i++)
		cout<<b[i];

    return 1;

} 

void BinSTree::BSTreeInOrder(BinStreeNode *bt) //中序遍历，时间复杂度O(N);  
{  
    if(bt)  
    {  
          
        BSTreeInOrder(bt->lchild); 
		
        cout<<bt->key<<" ";  
        BSTreeInOrder(bt->rchild);  
    } 

}  

//层次遍历  
void BinSTree::BSTreeLevelTraverse(BinStreeNode *bt)  
{  
    queue<BinStreeNode*> q;  
    if(bt)  
        q.push(bt);  
    while(!q.empty())  
    {  
        cout<<q.front()->key<<" ";//访问队头结点  
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
	cout<<"插入节点后，按层次遍历有："<<endl;
    for(int i=0;i<NUM;i++)  //按层次遍历二叉树
    {  
        bst.BSTreeInsert(a[i]);  
    }  
	
    pT = bst.BSTreeSearch(52, p ); //搜索数据是否在排序二叉树中 
    bst.BSTreeLevelTraverse(bst.root);  
    if(pT)  
    {  
        cout<<pT->key<<"存在在二叉树中"<<endl;  
    }  
	
	cout<<"中序遍历结点有:"<<endl;
    bst.BSTreeInOrder1(bst.root,20,50); //输出在区间k1和k2范围之间的数据
    cout << endl; 
	
    int m=bst.isValidBST(bst.root,11,82);//判断二叉树是否有效
    if(m==0)  cout<<"原树不是一棵有效的二叉树";
    else cout<<"原树是有效的二叉树";
    cout<<endl;
   
    system("pause");  
    return 0;  
}  