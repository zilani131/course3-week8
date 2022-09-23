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

void reverselevel_order(Node *root){
   // cout<<root->val;
   //if(root==NULL)return;
   queue<Node* > q;
   q.push(root);
   stack <int >s;

   while(!q.empty()){
    Node *chk=q.front();

    q.pop();
    s.push(chk->val);
    if(chk->right!=NULL){
        q.push(chk->right);
    }
    if(chk->left!=NULL){
        q.push(chk->left);
    }
   }
   //cout<<s.top();
   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
}
void buildTreeTraversalOrder(Node* &root){
int a;
cin>>a;
root=new Node(a);
queue <Node *>q;
q.push(root);
while(!q.empty()){
    Node*presentNode=q.front();
    q.pop();
    int x,y;
    cin>>x>>y;
    Node*l=NULL;
    Node*r=NULL;
    if(x!=-1){
        l=new Node(x);
    }
    if(y!=-1){
        r=new Node(y);
    }
    presentNode->left=l;
    presentNode->right=r;
    if(l!=NULL){
        q.push(l);
    }
    if(r!=NULL){
        q.push(r);
    }
}

}
int main()
{
     ///////case 1 input
Node*root=NULL;
  buildTreeTraversalOrder(root);
   reverselevel_order(root);
}
