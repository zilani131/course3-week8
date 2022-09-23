#include<bits/stdc++.h>
using namespace std;
string in;
class treeNode
{
public:
    int data;
    treeNode*cleft;
    treeNode*cright;
    treeNode(int val)
    {
        data=val;
        cleft=NULL;
        cright=NULL;
    }
};
class Node
{
public:
    int val;
    Node*left;
 Node*right;
    Node(int val)
    {
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
void space(int l)
{
    for(int i=0; i<l; i++)
    {

        cout<<"  ";
    }
}

void printTree(treeNode* root,int l)
{
    if(root==NULL)
    {
        return;
    }

    if(root->cleft==NULL&&root->cright==NULL)
    {
        cout<<root->data;
    }
    else
    {
        cout<<endl;
        space(l);
        cout<<"Root : "<<root->data<<endl;
    }

    if(root->cleft!=NULL)
    {
        space(l);
        cout<<"Left : ";
        printTree(root->cleft,l+1);
    }
    if(root->cright!=NULL)
    {
        cout<<endl;
        space(l);
        cout<<"Right : ";
        printTree(root->cright,l+1);
    }
}
void inOrder(treeNode*root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->cleft);
    cout<<root->data<<" ";

    inOrder(root->cright);


}
void preOrder(treeNode*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<< " ";
    preOrder(root->cleft);

    preOrder(root->cright);

    return;
}
void postOrder(treeNode*root)
{
    if(root==NULL)
    {
        return;
    }

    postOrder(root->cleft);

    postOrder(root->cright);
    cout<<root->data<<" ";
    return;

}
///////////leftNonLeaveBoundary
void printLeftNonLeaveBoundary(treeNode *root)
{
    if(root==NULL)
    {
        return;
    }

    if(root->cleft!=NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaveBoundary(root->cleft);
    }
    else if(root->cright!=NULL)
    {
        cout<<root->data<< " ";
        printLeftNonLeaveBoundary(root->cright);
    }
}

///////////print left leaves
void printLeave(treeNode*root)
{
    if(root==NULL)return;

//cout<<root->data<<"leave"<<endl;
    if(root->cleft==NULL&&root->cright==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
//cout<<" first"<<endl;
    printLeave(root->cleft);
    printLeave(root->cright);


}
void printRightNonLeaveBoundary(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->cright!=NULL)
    {
        cout<<root->data<<" ";
        printRightNonLeaveBoundary(root->cright);
    }
    else if(root->cleft!=NULL)
    {
        cout<<root->data<<" ";
        printRightNonLeaveBoundary(root->cleft);
    }
}
/////////print boundary node
void printBoundary(treeNode *root)
{
    cout<<root->data<< " ";
    printLeftNonLeaveBoundary(root->cleft);
/////leftboundaryleave
    printLeave(root->cleft);
////right boundary leave
    printLeave(root->cright);
////////
    printRightNonLeaveBoundary(root->cright);


}
int sum;
int solutionFunc(treeNode*root,bool chkL)
{


    if(root->cleft==NULL&&root->cright==NULL&&chkL==true)return (sum=sum+root->data);

   /* if(root->cleft->cleft==NULL&&root->cleft->cright==NULL)
    {
        sum=sum+root->cleft->data;
    }*/
    if(root->cleft!=NULL)
    {
        solutionFunc(root->cleft,true);
    }
    if(root->cright!=NULL)
    {
        solutionFunc(root->cright,false);
    }
    return sum;
}
  bool isSame(Node* root1, Node* root2){
      //base case
      if(root1==NULL&&root2==NULL)return true;
      if(root1==NULL||root2==NULL)return false;
      if(root1->val!=root2->val)return false;
      bool a=isSame(root1->left,root2->left);
      bool b=isSame(root1->right,root2->right);
          return a&&b;
  }
int sumLeftLeaves(treeNode *root){
if(root==NULL)return 0;
sum=0;
solutionFunc(root,false);
return sum;
}
int main()
{

    int n;
    cin>>n;
    treeNode*allNode[n];
    for(int i=0; i<n; i++)
    {
        allNode[i]=new treeNode(-1);
    }

    int root,l,r;
    for(int i=0; i<n; i++)
    {
        cin>>root>>l>>r;
        if(l>n-1||r>n-1)
        {
            cout<<"Invalid input";
            break;
        }
        allNode[i]->data=root;
        if(l!=-1)
        {
            allNode[i]->cleft=allNode[l];
        }
        if(r!=-1)
        {
            allNode[i]->cright=allNode[r];
        }

    }
     printTree(allNode[0],0);

//inOrder(allNode[0]);

    cout<<endl;
    // preOrder(allNode[0]);
    //cout<<endl;
    //  postOrder(allNode[0]);
   // cout<<endl;
//   printBoundary(allNode[0]);
    //cout<<endl;
    cout<<sumLeftLeaves(allNode[0]);



}
/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/
