

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
void spacePrint( int l){
    for(int i=0;i<l;i++){
        cout<<" ";
    }
}
void printTreeOrdering(Node* root,int l){
if(root==NULL){
    return;
}
if(root->left==NULL&&root->right==NULL){
    cout<<root->val;
}
else{
        cout<<endl;
    spacePrint(l);

    cout<<"Root : "<<root->val;

}
if(root->left){
    cout<<endl;
    spacePrint(l);
    cout<<"Left : ";
    printTreeOrdering(root->left,l+1);
}

if(root->right){
    cout<<endl;
    spacePrint(l);
    cout<<"Right : ";

    printTreeOrdering(root->right,l+1);
}
}
Node* invert_tree(Node* root)
{
    //base case
 if(root==NULL){
    return root;
 }
Node*temp=root->left;
root->left=root->right;
root->right=temp;
if(root->left!=NULL){
    invert_tree(root->left);
}
if(root->right!=NULL){
    invert_tree(root->right);
}
return root;
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
Node*root= NULL;
buildTreeTraversalOrder(root);
Node*inve=invert_tree(root);
printTreeOrdering(inve,0);


}
