#include "header.h"
#include "common.h"

//Global pointers for queue front and rear nodes initialized
struct node * front = NULL;
struct node * rear = NULL;

// Function takes value to be enqueued and enqueue in the list
// Enqueue() operation on a queue
void enqueue(int value) {
    struct node * ptr;
   
    ADD_START_TIME(start); 
    ptr = (struct node * ) malloc(sizeof(struct node));
    if(ptr != NULL)
    {
      ptr->data = value;
      ptr->next = NULL;
    
      if ((front == NULL) && (rear == NULL)) {
        //During first enqueue operation if the front and rear are null the queue is emmpty
        front = rear = ptr; 
      } else {
        //When queue is not empty we set the rear pointer to the enqueue address
        rear->next = ptr;
        rear = ptr;
      }
      printf("Node is Inserted\n\n");
    }
    else
    {
      printf("There is no memory left on the system to allocate, cannot enqueue\n");
    }
    ADD_END_TIME(end);
    time_diff(start,end);
    GETTIMESPENT_IN_FUNCTION(start, end);
}

// Function returns the dequeued element from front of the queue, if and only if 
// Dequeue() operation on a queue
// queue is not empty or have become empty.
int dequeue() {
    ADD_START_TIME(start); 
    // When front is null that means the queue has become empty again
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    } else {
        // front is not null, means we have element, 
        // return and free front and move front to next
        struct node * temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        //Getting time spent macros
        ADD_END_TIME(end);
        time_diff(start,end);
        GETTIMESPENT_IN_FUNCTION(start, end);
        return temp_data;
    }
}

// Function to check if queue is empty
bool is_queue_empty()
{
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
        return true;
    } 
    printf("\nQueue is not Empty\n");
    return false;
}

// Function to check if queue is full, for linked list implmentation this case will never
// happen as this queue will enqueue elements till memory is available on system
bool is_queue_full()
{
   printf("\n In linked list implementation till memory is available we will have queue");
   return false;
}

// Function to get the size of queue
// If queue is empty, it will return 0 size
// If queue is not empty it will return number of elements in the queue
int getsize() {
    struct node * temp;
    int size = 0;
    //Check queue is empty
    if ((front == NULL) && (rear == NULL)) {
      size = 0;
    } else {
       //Compute size
       temp = front;
       while (temp) {
         temp = temp->next;
         size++;
       }
    }
    return size;
}

// Display all elements of the queue
void display() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        temp = front;
        while (temp) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}
#if 1
//Main function to test the linked list functionality
int queue_using_ll_main() {
    int choice = 0, value = 0;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 7) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.IsEmpty\n5.IsFull\n6.GetSize\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 2:
                printf("Enqueued element is :%d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                is_queue_empty();
                break;
            case 5:
                is_queue_full();
                break;
            case 6:
                printf("\n sizei of queue in linked list %d\n",getsize());
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
#endif
