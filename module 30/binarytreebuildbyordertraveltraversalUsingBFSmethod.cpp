#include<bits/stdc++.h>
using namespace std;
class tNode{
public:
    int val;
    tNode* left;
    tNode* right;
    tNode(int data){
    val=data;
    left=NULL;
    right=NULL;
    }

};
void spacePrint( int l){
    for(int i=0;i<l;i++){
        cout<<" ";
    }
}
void printTreeOrdering(tNode* root,int l){
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
void buildTreeTraversalOrder(tNode* &root){
int a;
cin>>a;
root=new tNode(a);
queue <tNode *>q;
q.push(root);
while(!q.empty()){
    tNode*presentNode=q.front();
    q.pop();
    int x,y;
    cin>>x>>y;
    tNode*l=NULL;
    tNode*r=NULL;
    if(x!=-1){
        l=new tNode(x);
    }
    if(y!=-1){
        r=new tNode(y);
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
void printOrderLevelTraversal(tNode*root){
queue<tNode *>q;
cout<<root->val;
q.push(root);
while(!q.empty()){
    tNode *presentNode=q.front();
    cout<<presentNode->val<<" ";
    q.pop();
    if(presentNode->left){
        q.push(presentNode->left);
    }
    if(presentNode->right){
        q.push(presentNode->right);
    }

}


}
int levelOrderTraversal(tNode*root,int k){
if(root==NULL){
    return -1;
}
int l=0;
queue <tNode*> q;
q.push(root);
q.push(NULL);
int m=-1;
while(!q.empty()){
    tNode*chk=q.front();

    q.pop();
    if(chk!=NULL){
              cout<<chk->val<<" ";
              if(l==k){
                if(chk->val>m){
                    m=chk->val;
                }
              }
        if(chk->left!=NULL){
            q.push(chk->left);
        }
        if(chk->right!=NULL){
            q.push(chk->right);
        }
    }
    else{
        if(!q.empty()){
           cout<<endl;
           l++;
            q.push(NULL);
        }
    }
}

return m;
}
int searchPos(int a[],int chk,int s,int e){

for(int i=s;i<=e;i++){
    if(a[i]==chk){
        return i;
    }
}

}
tNode* buildPreIn(int pre[],int in[],int s,int e){
static int id =0;
int val=pre[id];
id++;
tNode*newNode=new tNode(val);

if(s==e){
    return newNode;
}
int pos=searchPos(in,val,s,e);
newNode->left=buildPreIn(pre,in,s,pos-1);
newNode->right=buildPreIn(pre,in,pos+1,e);
return newNode;

}
int main(){
/*tNode* root=NULL;
buildTreeTraversalOrder(root);

cout<<endl;
printTreeOrdering(root,0);
cout<<endl;
int m=levelOrderTraversal(root,2);
cout<<endl<<m;*/
int n;
cin>>n;
int pre[n];
int in[n];
for(int i=0;i<n;i++){
    cin>>pre[i];
}
for(int i=0;i<n;i++){
    cin>>in[i];
}
tNode *root=buildPreIn(pre,in,0,n-1);
printTreeOrdering(root,0);
}
