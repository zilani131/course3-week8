#include<bits/stdc++.h>
using namespace std;
class treeNode{
    public:
int data;
treeNode*left;
treeNode*right;
treeNode(int val){
data=val;
left=NULL;
right=NULL;
}
};
void printSpace(int l){
for(int i=0;i<l;i++){
    cout<<" ";
}

}
void printTree(treeNode*root,int l){
////////base case
if(root==NULL){
    return;
}
if(root->left==NULL&&root->right==NULL){
    cout<<root->data;
}
else{
         cout<<endl;
        printSpace(l);
      //  printf("z");

    cout<<"Root : "<<root->data;
}
if(root->left!=NULL){
    cout<<endl;
    printSpace(l);
    cout<<"Left : ";
    printTree(root->left,l+1);
}

if(root->right!=NULL){
    cout<<endl;
    printSpace(l);
    cout<<"Right : ";
    printTree(root->right,l+1);
}

}


void inOrder(treeNode*root){
if(root==NULL){
    return;
}
inOrder(root->left);
cout<<root->data<<" ";
inOrder(root->right);
return;
}
int main(){
int n;
cin>>n;
treeNode*allNode[n];
for(int i=0;i<n;i++){
    allNode[i]=new treeNode(-1);
}
int root,r,l;
for(int i=0;i<n;i++){
    cin>>root>>l>>r;
    if(r>n-1||l>n-1){
        cout<<"Invalid input";
        break;
    }
    allNode[i]->data=root;
    if(l!=-1){
        allNode[i]->left=allNode[l];
    }
    if(r!=-1){
        allNode[i]->right=allNode[r];
    }
}
printTree(allNode[0],0);
cout<<endl;
inOrder(allNode[0]);
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1


3
0 1 2
1 -1 -1
2 -1 -1
*/
