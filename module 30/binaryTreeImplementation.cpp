#include<bits/stdc++.h>
using namespace std;
class treeNode
{
public:
    int data;
    treeNode*left;
    treeNode*right;
    treeNode(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
void printSpace(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"  ";
    }
}

void printTree(treeNode* root,int level)
{

    if(root==NULL)
    {
        cout<<"the root is empty";
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        ////leaf node
        cout<<root->data;
    }
    else
    {cout<<endl;
        printSpace(level);
        cout<<"Root : "<<root->data<<endl;
    }
    if(root->left!=NULL)
    {
        printSpace(level);
        cout<<"Left : ";
        printTree(root->left,level+1);


    }

    if(root->right!=NULL)
    {cout<<endl;
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
            cout<<"The input is not valid";
            break;
        }
        allNode[i]->data=root;
        if(l!=-1)
        {
            allNode[i]->left=allNode[l];
        }
        if(r!=-1)
        {
            allNode[i]->right=allNode[r];
        }
    }

    printTree(allNode[0],0);
}

