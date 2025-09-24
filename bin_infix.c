//Create a binary tree for a given simple arithmetic expression and find the prefix / postfix equivalent.

#include<stdio.h>
#include<stdlib.h>

struct node
{
        char data;
        struct node* lchild;
        struct node* rchild;
};

void postfix(struct node* r)
{
        if(r != NULL)
        {
                postfix(r->lchild);
                postfix(r->rchild);
                printf("%c",r->data);
        }
}

void prefix(struct node* r)
{
        if(r != NULL)
        {
                printf("%c",r->data);
                prefix(r->lchild);
                prefix(r->rchild);

        }
}

void tree(struct node **r)
{
        char val;

        printf("Enter the value(Enter $ for NULL) : ");
        scanf("%c",&val);
        getchar();
        if(val =='$')
        {
                r == NULL;
                return;
        }

        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->lchild = NULL;
        n->rchild = NULL;
        *r = n;
        printf("Enter the value of left child of %c: ",val);
        tree(&((*r)->lchild));
        printf("\n");
        printf("Enter the value of right child of %c: ",val);
        tree(&((*r)->rchild));
}

int main()
{
        struct node  *root = NULL;

        tree(&root);
        postfix(root);
        printf("\n");
        prefix(root);
        return 0;
}
