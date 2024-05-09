#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    int grades[4];
    struct student *left;
    struct student *right;
} student;

student *new_student(const char *name, int grades[4])
{
    student *new_student_node = (student *)malloc(sizeof(student));
    strcpy(new_student_node->name, name);
    for (int i = 0; i < 4; i++)
    {
        new_student_node->grades[i] = grades[i];
    }
    new_student_node->left = NULL;
    new_student_node->right = NULL;
    return new_student_node;
}

void insert_student(student **root, const char *name, int grades[4])
{
    if (*root == NULL)
    {
        *root = new_student(name, grades);
        return;
    }
    if (strcmp(name, (*root)->name) < 0)
    {
        insert_student(&(*root)->left, name, grades);
    }
    else
    {
        insert_student(&(*root)->right, name, grades);
    }
}

void print_inorder(student *root)
{
    if (root == NULL)
        return;
    print_inorder(root->left);
    printf("%s\n", root->name);
    print_inorder(root->right);
}

void print_reverse_inorder(student *root)
{
    if (root == NULL)
        return;
    print_reverse_inorder(root->right);
    printf("%s\n", root->name);
    print_reverse_inorder(root->left);
}

student *search_student(student *root, const char *name)
{
    if (root == NULL)
        return NULL;
    if (strcmp(name, root->name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
    {
        return search_student(root->left, name);
    }
    else
    {
        return search_student(root->right, name);
    }
}

int main()
{
    student *root = NULL;

    int grades1[] = {1, 2, 3, 4};
    int grades2[] = {5, 6, 7, 8};
    int grades3[] = {9, 10, 11, 12};

    insert_student(&root, "Бобылев", grades1);
    insert_student(&root, "Аршавин", grades2);
    insert_student(&root, "Сидоров", grades3);

    printf("По возрастанию:\n");
    print_inorder(root);

    printf("\nПо убыванию:\n");
    print_reverse_inorder(root);

    char search_name[] = "Бобылев";
    student *found = search_student(root, search_name);
}
