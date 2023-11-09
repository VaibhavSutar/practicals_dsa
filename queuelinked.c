#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*ptr,*ptr1;

struct node * front;
struct node * rear;

void insert(int item) {

    ptr = (struct node * ) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    } else {
        ptr -> data = item;
        if (front == NULL) {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        } else {
            rear -> next = ptr;
            rear = ptr;
            rear -> next = NULL;
        }
    }
}

void deleteNode() {
    if (front == NULL) {
        printf("Underflow");
        return;
    } else {
        ptr = front;
        printf("The deleted node is: %d",ptr-> data);
        front = front -> next;
        free(ptr);
    }
}
void display()
{
         struct node * temp;
    if(front == NULL | rear == NULL)
    {
        printf("Empty");
        return;
    }
    else
    {
        temp = front;
        while(temp)
        {
            printf("%d-->", temp->data);
            temp = temp-> next;
        }
        print("NULL\n");
        
    }
}
main()
{
    int choice,num;
    do
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
            printf("Enter element to be inserted: ");
            scanf("%d",&num);
            insert(num);
            break;
            }
            case 2:
            deleteNode();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exit \n");
            break;
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    }
    while (choice !=4);
    return 0;
     /* End of while */
} 