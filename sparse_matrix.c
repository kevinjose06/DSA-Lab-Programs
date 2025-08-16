/*Write a program to enter two matrices in normal form. Write a function to convert two matrices to 
tuple form and display it. Also, find the transpose of the two matrices represented in tuple form and display it.
 Find the sum of the two matrices in tuple form and display the sum in tuple form.*/

#include<stdio.h>

struct tuple
{
    int row;
    int col;
    int val;
};

//Function to print the entered matrix in Tuple format
void toTuple(int a[10][10],int r,int c,struct tuple t[])
{
    int i,j,k=1;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                t[k].row=i;
                t[k].col=j;
                t[k].val=a[i][j];
                k++;
            }
            t[0].row=r; //The initial values are assigned as Metadata abuout the Matrix
            t[0].col=c;
            t[0].val=k-1;
        }
    }
    printf("Row\tColumn\tValue\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
    }
}

//Print the transpose of the matrix in Tuple format in ascending order of Column number as row number
void transpose(struct tuple t[],struct tuple tr[])
{
    int r=t[0].row;
    int c=t[0].col;
    int v=t[0].val;

    tr[0].row=c;
    tr[0].col=r;
    tr[0].val=v;

    int k=1,i,j;
    for(i=0;i<c;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(t[j].col==i)
            {
                tr[k].row=t[j].col;
                tr[k].col=t[j].row;
                tr[k].val=t[j].val;
                k++;
            }
        }
    }
    printf("Row\tColumn\tValue\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t%d\t%d\n",tr[i].row,tr[i].col,tr[i].val);
    }
}


//Add the tuples 
void addTuples(struct tuple t1[], struct tuple t2[], struct tuple s[]) {
    if (t1[0].row != t2[0].row || t1[0].col != t2[0].col) {
        printf("Matrix sizes do not match for addition!\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    s[0].row = t1[0].row;
    s[0].col = t1[0].col;

    while (i <= t1[0].val && j <= t2[0].val) 
    {
        if (t1[i].row == t2[j].row && t1[i].col == t2[j].col) 
        {
            s[k].row = t1[i].row;
            s[k].col = t1[i].col;
            s[k].val = t1[i].val + t2[j].val;
            i++; j++; k++;
        } else if ((t1[i].row < t2[j].row) || (t1[i].row == t2[j].row && t1[i].col < t2[j].col)) /*If element in Tuple 1 isn't in Tuple
                                                                                                    2 display it*/
        {
            s[k++] = t1[i++];
        } else {
            s[k++] = t2[j++];
        }
    }

    while (i <= t1[0].val) s[k++] = t1[i++]; //If Tuple 2 gets exhausted earlier print rest of Tuple 1
    while (j <= t2[0].val) s[k++] = t2[j++]; //If Tuple 1 gets exhausted earlier print rest of Tuple 2

    s[0].val = k - 1;

    printf("Row\tColumn\tValue\n");
    for(i=1;i<=s[0].val;i++)
    {
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].val);
    }
}

int main()
{
    struct tuple t1[50],t2[50],s[50],tr1[50],tr2[50];
    int i,j,r1,c1,r2,c2,a[10][10],b[10][10],r[10][10];

    printf("Enter the number of rows and columns of matrix 1:");
    scanf("%d%d",&r1,&c1);

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("Enter element [%d][%d]:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix 2:");
    scanf("%d%d",&r2,&c2);

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("Enter element [%d][%d]:",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    printf("Matrix 1 in normal form:\n");

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2 in normal form:\n");

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    printf("\n------Matrix 1 in tuple format------\n");
    toTuple(a,r1,c1,t1);
    
    printf("\n------Matrix 2 in tuple format------\n");
    toTuple(b,r2,c2,t2);

    printf("\n------Transpose of Matrix 1 in tuple format------\n");
    transpose(t1,tr1);
    printf("\n------Transpose of Matrix 2 in tuple format------\n");
    transpose(t2,tr2);

    printf("The Sum of the matrices is:\n");
    addTuples(t1,t2,s);

    return 0;
}