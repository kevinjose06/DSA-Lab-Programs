//Implement a dictionary of word-meaning pairs using binary search trees.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node 
{
    char word[MAX];
    char meaning[MAX];
    struct node *left, *right;
};

// Create a new node
struct node* createNode(char *word, char *meaning) 
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST (by strcmp)
struct node* insert(struct node *root, char *word, char *meaning) 
{
    if (root == NULL) return createNode(word, meaning);

    int cmp = strcmp(word, root->word);

    if (cmp < 0)
        root->left = insert(root->left, word, meaning);
    else if (cmp > 0)
        root->right = insert(root->right, word, meaning);
    else
        strcpy(root->meaning, meaning); // update if duplicate

    return root;
}

// Search a word
struct node* search(struct node *root, char *word) 
{
    if (root == NULL) return NULL;

    int cmp = strcmp(word, root->word);

    if (cmp == 0) return root;
    else if (cmp < 0) return search(root->left, word);
    else return search(root->right, word);
}

// Traversal (preorder)
void preorder(struct node *root) 
{
    if (root != NULL) 
    {
        printf("%s : %s\n", root->word, root->meaning);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() 
{
    struct node *root = NULL;
    char word[MAX], meaning[MAX];
    int n, i;

    printf("Enter number of words: ");
    scanf("%d", &n);
    getchar(); // eat newline

    // Insert N words
    for (i = 0; i < n; i++) 
    {
        printf("\nEnter word %d: ", i + 1);
        scanf("%s", word);
        getchar(); // eat newline

        printf("Enter meaning of %s: ", word);
        fgets(meaning, sizeof(meaning), stdin);
        meaning[strcspn(meaning, "\n")] = '\0'; // remove newline

        root = insert(root, word, meaning);
    }

    // Search all words
    printf("\nSearching for all inserted words:\n");
    for (i = 0; i < n; i++) {
        printf("Enter word to search:(Enter X to exit) ");
        scanf("%s", word); 
        if(strcmp(word,"X") == 0)
        {
            break;
        }

        struct node *res = search(root, word);
        if (res != NULL)
            printf("Found! %s : %s\n", res->word, res->meaning);
        else
            printf("Word '%s' not found!\n", word);
    }

    // Display dictionary
    printf("\nDictionary contents (Preorder Traversal):\n");
    preorder(root);

    return 0;
}
