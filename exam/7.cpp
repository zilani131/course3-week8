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

int sum=0;
int sumVal(Node*root)
{
    if(root==NULL){
        return 0;
    }
    int a=sumVal(root->left);
    int b=sumVal(root->right);
    int tilth=abs(a-b);
    sum+=tilth;
    return root->val+a+b;
}
int findTilt(Node* root){
sumVal(root);
return sum;
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
int s=findTilt(root);
cout<<s;

}
