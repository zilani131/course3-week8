#include<bits/stdc++.h>
using namespace std;
class treeNode
{
public:
    int data;
    treeNode*right;
    treeNode*left;
    treeNode(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
void printSpace(int l)
{
    for(int i=0; i<l; i++)
    {
        cout<<"  ";
    }


}
////////////////////////inorder format/////
void inorder(treeNode* root){
if(root==NULL){
    return;
}
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
void preorder(treeNode* root){
if(root==NULL){
    return;
}
cout<<root->data<<" ";
preorder(root->left);

preorder(root->right);
}
void postorder(treeNode* root){
if(root==NULL){
    return;
}

postorder(root->left);

postorder(root->right);
cout<<root->data<<" ";
}
/*
printing format
root: 0
left :
     root:1
     left: 3
     right:4
right:
    root:2
    left:
        root:5
        left:7
        right:8
    right: 6*/
///////////////////////////printing function/////////
void printTree(treeNode* root,int level)
{
    if(root==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    //cout<<"out"<<endl;
    if((root->left==NULL)&&(root->right==NULL))
    { //cout<<"ina"<<endl;
        cout<<root->data<<endl;
    }
    else
    {    //cout<<"inb"<<endl;
        cout<<endl;
        printSpace(level);
        cout<<"Root : "<<root->data<<endl;

    }
   // cout<<root->left->data<<endl;
    if(root->left!=NULL)
    {
        //cout<<"left"<<endl;
        printSpace(level);
        cout<<"Left : ";
        printTree(root->left,level+1);
    }

    if(root->right!=NULL)
    {
       // cout<<"right"<<endl;
        printSpace(level);
        cout<<"Right : ";
        printTree(root->right,level+1);
    }

}

int main()
{
    int n;
    cin>>n;
    treeNode* allNode[n];
//int root,left,child;
    for(int i=0; i<n; i++)
    {

        allNode[i]=new treeNode(-1);

    }
////////////taking 3 value in each iteration root,left right

    for(int i=0; i<n; i++)
    {int root,cleft,cright;
        cin>>root>>cleft>>cright;
        allNode[i]->data=root;
////the left and the right value can not exit the last index number
        if(cleft>n-1||cright>n-1)
        {
            cout<<"Invalid value "<<endl;
            break;
        }
        if(cleft!=-1)
        {
            allNode[i]->left=allNode[cleft];
          // cout<<"not "<<endl;
        }
        if(cright !=-1)
        {
            allNode[i]->right=allNode[cright];
        }
    }

      printTree(allNode[0],0);
      inorder(allNode[0]);
      cout<<endl;
     preorder(allNode[0]);
      cout<<endl;
       postorder(allNode[0]);
      cout<<endl;
}


/*input format
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
