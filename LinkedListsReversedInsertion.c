#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
void insertAtEnd(struct Node **, struct Node **, int);
void print(struct Node *);
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n;
    printf("\nEnter n: ");
    scanf(" %d", &n);
    int temp;
    while (n--)
    {
        scanf(" %d", &temp);
        insertAtEnd(&head, &tail, temp);
    }
    print(head);
    return 0;
}
void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
void insertAtEnd(struct Node **head, struct Node **tail, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}