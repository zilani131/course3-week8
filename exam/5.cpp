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
//Zigzag order function
void zigzag_order(Node *root)
{
    if(root==NULL)return;
    stack<Node*>curr,nxt;
    bool leftToRight=true;

    curr.push(root);
    while(!curr.empty())
    {
        Node*temp=curr.top();
        curr.pop();

        if(temp)
        {
            cout<<temp->val<<" ";
            if(leftToRight)
            {
                if(temp->left)
                {
                    nxt.push(temp->left);
                }
                if(temp->right)
                {
                    nxt.push(temp->right);
                }
            }
            ////right to left
            else
            {
                if(temp->right)
                {
                    nxt.push(temp->right);
                }
                if(temp->left)
                {
                    nxt.push(temp->left);
                }
            }
        }
        if(curr.empty())
        {
            leftToRight=!leftToRight;
            swap(curr,nxt);
        }

    }
}

void buildTreeTraversalOrder(Node* &root)
{
    int a;
    cin>>a;
    root=new Node(a);
    queue <Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node*presentNode=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node*l=NULL;
        Node*r=NULL;
        if(x!=-1)
        {
            l=new Node(x);
        }
        if(y!=-1)
        {
            r=new Node(y);
        }
        presentNode->left=l;
        presentNode->right=r;
        if(l!=NULL)
        {
            q.push(l);
        }
        if(r!=NULL)
        {
            q.push(r);
        }
    }

}
int main()
{
    ///////case 1 input
    Node*root=NULL;
    buildTreeTraversalOrder(root);
    zigzag_order(root);
}
/*
3
9 20
-1 -1 15 7
-1 -1 -1 -1 -1 -1 -1 -1
*/
