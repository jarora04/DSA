#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

struct btree{
    int data;
    struct btree *left;
    struct btree *right;
};

void insert_bst(struct btree **r,int num)
{
    
    if(*r==NULL)
    {
        (*r)=(struct btree*)malloc(sizeof(struct btree));
        (*r)->data=num;
        (*r)->left=NULL;
        (*r)->right=NULL;
        
    }
    else{
        if((*r)->data>num)
        {
            insert_bst(&((*r)->left),num);
        }
        else if((*r)->data<num)
        {
            insert_bst(&((*r)->right),num);
        
    }

}
}

void inorder_display(struct btree *r)
{
   if(r)
    {
     inorder_display(r->left);
    cout<<r->data<<"\t";
    inorder_display(r->right);
    }
   
}

void postorder_display(struct btree *r)
{
    if(r)
    {
        postorder_display(r->left);
        postorder_display(r->right);
        cout<<r->data<<"\t";    
    }
}

void preorder_display(struct btree *r)
{
    if(r)
    {
        cout<<r->data<<"\t";
        preorder_display(r->left);
        preorder_display(r->right);
    }
}

void min_bst(struct btree *r)
{
    while(r->left!=NULL)
    {
        r=r->left;
    }
    cout<<r->data<<endl;
}

void max_bst(struct btree *r)
{
    while(r->right!=NULL)
    {
        r=r->right;
    }
    cout<<r->data<<endl;
}

void search_bst(struct btree **r,int num, struct btree **p,struct btree **x,int *f)
{
    *f=false;
    struct btree *b=*r;
    *p=NULL;
    while(b!=NULL)
    {
        if(b->data==num)
        {
            cout<<"element is found"<<endl;
            *x=b;
            *f=true;
            return ;
        }
        *p=b;
        if(b->data>num)
        b=b->left;

        else
        b=b->right;

    }
}

void del_bst(struct btree **r,int num)
{
    int found;
    struct btree *x,*parent,*xsucc;
    search_bst(r,num,&parent,&x,&found);
    if(x->left==NULL&&x->right==NULL)
    {
        if((*r)==x)
        {
            (*r)=NULL;
        }
        else{
            if(parent->left==x)
            {
                parent->left=NULL;
            }
            else{
                parent->right=NULL;
            }
        }
    }
    if(x->left!=NULL&&x->right==NULL)
    {
        if((*r)==x)
        {
            (*r)=(*r)->left;
        }
        else{
            if(parent->left==x)
            {
                parent->left=x->left;
            }
            else{
                parent->right=x->left;
            }
        }
    }
    if(x->left==NULL&&x->right!=NULL)
    {
        if((*r)==x)
        {
            (*r)=(*r)->right;
        }
        else{
            if(parent->left==x)
            {
                parent->left=x->right;
            }
            else{
                parent->right=x->right;
            }
        }
    }
    if(x->left!=NULL&&x->right!=NULL)
    {
        xsucc=x->right;
        while(xsucc->left!=NULL)
        {
            xsucc=xsucc->left;
        }
        x->data=xsucc->data;
        del_bst(&(x->right),xsucc->data);
    }

}

void bst2dll(struct btree *root,struct btree **head)
{
    static btree *temp=NULL;
    bst2dll(root->left,head);
    if (temp == NULL) 
        *head = root; 
    else { 
        root->left = temp; 
        temp->right = root; 
    } 
    temp= root; 
    cout<<"1";

    bst2dll(root->right,head);
}
void BinaryTree2DoubleLinkedList(btree* root, btree** head) 
{ 
    // Base case 
     if(root==NULL)
     return;
    static btree* prev = NULL; 
 
    BinaryTree2DoubleLinkedList(root->left, head); 
    if (prev == NULL) 
        *head = root; 
    else { 
        root->left = prev; 
        prev->right = root; 
    } 
    prev = root; 
  
    BinaryTree2DoubleLinkedList(root->right, head); 
} 

int depth(struct btree* b)
{
    if (b == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = depth(b->left);
        int rDepth = depth(b->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void print(struct btree *head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->right;
    }
}
int main()
{
    struct btree *b=NULL;
    insert_bst(&b,1);
    insert_bst(&b,2);
    insert_bst(&b,3);
    insert_bst(&b,4);
    insert_bst(&b,5);
    insert_bst(&b,6);
   /* cout<<"inoder expression is:";
    inorder_display(b); 
    cout<<endl;
    cout<<"postorder expression is:";
    postorder_display(b);
    cout<<endl;
    cout<<"preorder expression is:";
    preorder_display(b);
    cout<<endl;
    cout<<"min bst is:";
    min_bst(b);
    cout<<"max bst is:";
    max_bst(b);

    cout<<"deleting bst is:";
    del_bst(&b,3);
    cout<<"inoder expression is:";*/
     inorder_display(b); 
      preorder_display(b);
       postorder_display(b);
    struct btree *head=NULL;
    //BinaryTree2DoubleLinkedList(b,&head);
   
    cout<<endl;
    cout<<depth(b);
   print(head);
   

    return 0;
}