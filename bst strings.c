#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char temp[50];
typedef struct node
{
        char data[50];
        struct node *left,*right;   //left and right pointer
        int ht; //ht stores height
}node;

//this function will calculate height of each node

int height(node *P)
{
        int lh,rh;
        if(P==NULL)
                return(0);

        if(P->left==NULL)
                lh=0;
        else
                lh=1+P->left->ht;

        if(P->right==NULL)
                rh=0;
        else
                rh=1+P->right->ht;

        if(lh>rh)
                return(lh);

        return(rh);
}
//this will rotate right
node * rotateright(node *x)
{
        node *y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height(x);
        y->ht=height(y);
        return(y);
}

//this will rotate left

node * rotateleft(node *x)
{
        node *y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height(x);
        y->ht=height(y);

        return(y);
}

//this will be used for right right rotation
node * RR(node *P)
{
        P=rotateleft(P);
    printf("RR rotation\n");
        return(P);
}
node * LL(node *P)
{
        P=rotateright(P);
    printf("LL rotation\n");
        return(P);
}

//this will be used for left right rotation
node * LR(node *P)
{
        P->left=rotateleft(P->left);
    printf("RL rotation\n");
        P=rotateright(P);
    printf("RR rotation\n");

        return(P);
}

//this will be used for right left rotation
node * RL(node *P)
{
        P->right=rotateright(P->right);
    printf("RR rotation\n");
        P=rotateleft(P);
    printf("RL rotation\n");
        return(P);
}
int BF(node *P)
{
        int lh,rh;
        if(P==NULL)
                return(0);

        if(P->left==NULL)
                lh=0;
        else
                lh=1+P->left->ht;

        if(P->right==NULL)
                rh=0;
         else
                rh=1+P->right->ht;

        return(lh-rh);
}

void inorder(node *P)
{
        if(P!=NULL)
        {
                inorder(P->left);
                printf("%s\t",P->data,BF(P));
                inorder(P->right);
        }
}

node * insert(node *P,char x[50])
{
        if(P==NULL)
        {
                P=(node*)malloc(sizeof(node));
                strcpy(P->data,x);
                P->left=NULL;
                P->right=NULL;
        }
        else
            {

                if(strcmp(x,P->data)>0)    //right subtree
                {
                        P->right=insert(P->right,x);
                        int bf=BF(P);
                        if(bf==-2)
                                if(strcmp(x,P->right->data)>0)
                                   P=RR(P);  //RR means right right imbalance,so right right rotation
                                else
                                   P=RL(P);  //RL means right left imbalance,so right left rotation
                }
                else
                {
                  if(strcmp(x,P->data)<0)   //left subtree
                  {
                        P->left=insert(P->left,x);
                        if(BF(P)==2)
                        if(strcmp(x,P->left->data)<0)
                        P=LL(P);    //RR means left left imbalance , so left left rotation
                        else
                        P=LR(P);    //RL means left right imbalance , so left right rotation
                  }
                }

            }
        P->ht = height(P);
        return(P);
}

int main()
{
        node *root=NULL;
        int x,n,i,op;
        char k[50];
	struct node *copy;

		 printf("\nEnter no. of elements:");
                                        scanf("%d",&n);
                                        printf("\nEnter data FOR TREE:");
                                        root=NULL;
                                        for(i=0;i<n;i++)
                                        {
                                                scanf("%s",&k);
                                                root=insert(root,k);
						copy=root;
                                        }


                        printf("\n\nInorder:\n");
                                        inorder(root);
                                        printf("\n");



	       int y;
               printf("Enter 1 if u want to insert(-1 for return)=");
           scanf("%d",&y);
           if(y==1)
             {
                 scanf("%s",&k);
                root=insert(root,k);
                inorder(root);
             }
               else
                printf("Thank you for using my program");

       return 0;
}
