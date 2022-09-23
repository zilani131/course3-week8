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

void average_level(Node*root){
if(root==NULL) return;
queue<Node*>q;
q.push(root);
while(!q.empty()){
    int n=q.size();
    int sum=0;
    for(int i=0;i<n;i++){
        Node*chk=q.front();
        q.pop();
        sum+=chk->val;
        if(chk->left!=NULL){
            q.push(chk->left);
        }
        if(chk->right!=NULL){
            q.push(chk->right);
        }
    }
    double avg=double(sum)/double(n);
    cout<<avg<<" ";

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
int main(){

Node *root=NULL;
buildTreeTraversalOrder(root);
average_level(root);

}

