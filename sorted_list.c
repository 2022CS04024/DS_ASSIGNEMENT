#include "header.h"
sortedList *head = NULL;

unsigned int find_element_in_sorted_list(unsigned int num)
{
  sortedList *temp = head;

  while(temp != NULL)
  {
    if(temp->data == num)
    {
      return TRUE;
    }
    // move to the next node
    temp = temp->next;
  }
  return FALSE;
}
// Helper function to return a new node of the linked list
sortedList* createNode(unsigned int data)
{
    sortedList* newNode = (struct node*)malloc(sizeof(sortedList));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// adding element in the linked list as sorted order
void  insert_element(unsigned int data)
{
    sortedList *temp, *tail;
    temp = head;
    tail = createNode(data);
    // if linked list is empty, adding as first node.
    if(head == NULL || head->data > data)
    {
        head = tail;
        head->next = temp;
        return ;
    }
    // search the position and adding the element
    else
    {
        //Move to last node
        while(temp != NULL)
        {
            if(temp->data <= data && (temp->next == NULL || temp->next->data > data))
            {
                tail->next = temp->next;
                temp->next = tail;
                return ;
            }
            // move to the next node
            temp = temp->next;
        }
    }
    return ;
}

// displays the sorted linked list
void display_sorted_list()
{
    sortedList *tmp = head;
    printf("\n");
    // traversing entire linked list
    printf("\nhead==>");
    printf("\n %p",head);
    
    while(tmp != NULL)
    {
        printf("%d-->", tmp->data);
        tmp = tmp->next;
    }
    printf("tail\n");
}

// finds the number of elements in the sorted linked list
unsigned int count()
{
    int c = 0;
    while(head != NULL)
    {
        head = head->next;
        c++;
    }
    return c;
}

// Deletes the any element in the sorted linked list
unsigned int delete_element_from_sorted_list(unsigned int data)
{
    struct node *old, *temp;
    temp = head;

    while(temp != NULL)
    {
        if(temp->data == data)
        {
            // deleting first node if data matches
            if(temp == head)
            {
                head = temp->next;
                free(temp);
                return TRUE;
            }
            // deleting other nodes except first node
            else
            {
                old->next = temp->next;
                free(temp);
                return TRUE;
            }
        }
        // old points to the previous node
        old = temp;
        temp = temp->next;
    }
    return FALSE;
}


