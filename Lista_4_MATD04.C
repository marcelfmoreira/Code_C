#include <stdio.h>
#include <stdlib.h>

//Questao 1:

typedef struct TreeNode
{
    int data; //IntegerBTS will store an integer
    struct TreeNode *right_child; // right child
    struct TreeNode *left_child; // left child
} IntegerBTS;

IntegerBTS* search(IntegerBTS *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->right_child, x);
    else 
        return search(root->left_child,x);
}

IntegerBTS* new_IntegerBTS(int x)
{
    IntegerBTS *p;
    p = malloc(sizeof(IntegerBTS));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

void add (IntegerBTS *root, int x)
{
    if(root==NULL)
        return new_IntegerBTS(x);
    else if(x>root->data) 
        root->right_child = add(root->right_child, x);
    else 
        root->left_child = add(root->left_child,x);
    return root;
}

void remove(IntegerBTS *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = remove(root->right_child, x);
    else if(x<root->data)
        root->left_child = remove(root->left_child, x);
    else
    {
        
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            IntegerBTS *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        
        else
        {
            IntegerBTS *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = remove(root->right_child, temp->data);
        }
    }
    return root;
}

void preorder(IntegerBTS *root)
{
  if(root!=NULL) // checking if the root is not null
  {
    printf(" %d ", root->data); // printing data at root
    preorder(root->left_child); // visiting left child
    preorder(root->right_child);// visiting right child
  }
}

void inorder(IntegerBTS *root)
{
    if(root!=NULL) // checking if the root is not null
    {
      inorder(root->left_child); // visiting left child
      printf(" %d ", root->data); // printing data at root
      inorder(root->right_child);// visiting right child
    }
}

void posorder(IntegerBTS *root)
{
    if(root!=NULL) // checking if the root is not null
    {
      posorder(root->left_child); // visiting left child
      posorder(root->right_child);// visiting right child
      printf(" %d ", root->data); // printing data at root
    }
}


//Questao 2:

IntegerBTS* find_minimum(IntegerBTS *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL)
        return find_minimum(root->left_child);
    return root;
}

IntegerBTS* find_maximum(IntegerBTS *root)
{
    if(root == NULL)
        return NULL;
    else if(root->right_child != NULL)
        return find_maximum(root->right_child);
    return root;
}


//Questao 3:

int main(){

IntegerBTS *root;
root = new_node(20);
add(root,5);
add(root,1);
add(root,15);
add(root,9);
add(root,7);
add(root,12);
add(root,30);
add(root,25);
add(root,40);
add(root, 45);
add(root, 42);

inorder(root);
printf("\n");

root = remove(root, 1);
root = remove(root, 40);
root = remove(root, 45)
root = remove(root, 9);

inorder(root);

printf("\n");

return 0;
}
