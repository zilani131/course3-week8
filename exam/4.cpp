
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
//function solution
bool funSol(Node* root1,Node* root2){
if(root1==NULL&&root2==NULL)return true;
if(root1==NULL||root2==NULL)return false;
if(root1->val!=root2->val)return false;
    bool a=funSol(root1->left,root2->right);
    bool b=funSol(root1->right,root2->left);
    return a&&b;

}
// isSymetric function
bool isSymmetric(Node* root)
{
    //base case
    return funSol(root->left,root->right);
}
int main(){
Node*root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    //root->left->right=new Node(3);
     root->right->left=new Node(4);
    root->right->right=new Node(3);
    cout<<isSymmetric(root);

}
