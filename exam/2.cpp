#include<bits/stdc++.h>
using namespace std;
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
void level_order(Node *root){
if(root==NULL)return;
cout<<root->val<<" ";
if(root->left!=NULL){
    level_order(root->left);
}
if(root->right!=NULL){
    level_order(root->right);
}
}
int main()
{
     ///////case 1 input
    Node*root= new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right = new Node(7);
   level_order(root);
}
