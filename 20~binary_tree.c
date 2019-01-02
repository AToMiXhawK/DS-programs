#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};

struct node *head=NULL;

struct node *read(struct node **p)
{
    if (*p==NULL)
    {
        return NULL;
    }
    printf("\nEnter the tree node value:(-1 for NULL)");
    scanf("%d",&(*p)->data);
    if((*p)->data==-1){*p=NULL;return NULL;}
    printf("\nFor the value %d",(*p)->data);
    struct node *pl=(struct node *)malloc(sizeof(struct node ));
    struct node *pr=(struct node *)malloc(sizeof(struct node ));
    printf("\nThe left node");
    (*p)->left=pl;
    read(&(*p)->left);
    printf("\nFor the value %d",(*p)->data);
    printf("\nThe right node");
    (*p)->right=pr;
    read(&(*p)->right);
}

void post(struct node *ptr)
{
    if(ptr!=NULL)
        {
            post(ptr->left);
            post(ptr->right);
            printf("%d  ",ptr->data);
        }

}

void in(struct node *ptr)
{
    if(ptr!=NULL)
        {
            in(ptr->left);
            printf("%d  ",ptr->data);
            in(ptr->right);
        }
}

void pre(struct node *ptr)
{
    if(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            pre(ptr->left);
            pre(ptr->right);
        }
}
void main()
{
    struct node *p=(struct node *)malloc(sizeof(struct node ));
    head=p;
    read(&p);
    printf("\nThe  postorder\n");
    post(p);
    printf("\n");
    printf("\nThe inorder\n");
    in(p);
    printf("\n");
    printf("\nThe preorder\n");
    pre(p);
    printf("\n");
}
