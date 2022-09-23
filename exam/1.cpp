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
// isSame function
bool isSame(Node* root1, Node* root2)
{
    //base case
    if(root1==NULL&&root2==NULL)return true;
    if(root1==NULL||root2==NULL)return false;
    if(root1->val!=root2->val)return false;
    bool a=isSame(root1->left,root2->left);
    bool b=isSame(root1->right,root2->right);
    return a&&b;
}
int main()
{
     ///////case 1 input
    Node*c1temp1= new Node(1);
    c1temp1->left=new Node(2);
    c1temp1->right=new Node(3);
    Node*c1temp2=new Node(1);
    c1temp2->left=new Node(2);
    c1temp2->right=new Node(3);
    cout<<isSame(c1temp1,c1temp2)<<endl;
    ///////case 2 input
    Node*c2temp1= new Node(1);
    c2temp1->left=new Node(2);
    Node*c2temp2=new Node(1);
      c2temp2->right=new Node(2);
   cout<<isSame(c2temp1,c2temp2)<<endl;
    Node*c3temp1= new Node(1);
    c3temp1->left=new Node(2);
    c3temp1->right=new Node(1);
    Node*c3temp2=new Node(1);
    c3temp2->left=new Node(1);
    c3temp2->right=new Node(2);
     cout<<isSame(c3temp1,c3temp2)<<endl;
}
