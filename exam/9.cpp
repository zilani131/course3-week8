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

bool is_unival(Node* root)
{

    if(root==NULL) return false;
queue<Node*>q;
q.push(root);
int uni=root->val;
while(!q.empty()){
    int n=q.size();

        Node*chk=q.front();
        q.pop();
    if(uni!=chk->val)return false;
        if(chk->left!=NULL){
            q.push(chk->left);
        }
        if(chk->right!=NULL){
            q.push(chk->right);
        }
    }
   return true;

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
int main(){

Node *root=NULL;
buildTreeTraversalOrder(root);
cout<<is_unival(root);

}
