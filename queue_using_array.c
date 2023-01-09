#include "common.h"
#include "header.h"
//Sizie of array queue

int ch=1,i,j=1;

/* Global defination of array queue */
queue_arr_t queue;

//Function to initialize array queue datat structure
void init_array_queue(queue_arr_t *queue)
{
   for(i = 0; i < QUEUE_ARRAY_SIZE; i++)
   {
     queue->queue[i] = 0;
   }
   queue->x=QUEUE_ARRAY_SIZE;
   queue->front=0;
   queue->rear=0;
}

//Function to enqueue element in array queue
void enqueue_arr(queue_arr_t *queue, int element)
{
    ADD_START_TIME(start); 
    if(queue->rear==queue->x)
       printf("\n Queue is Full");
    else
    {
       queue->queue[queue->rear++] = element;
    }
    ADD_END_TIME(end);
    time_diff(start,end);
    GETTIMESPENT_IN_FUNCTION(start, end);
}

//Function to check if queue is empty
bool is_arr_queue_empty(queue_arr_t *queue)
{
   if(queue->front==queue->rear)
   {
      printf("\n Queue is empty");
      return true;
   }
   return false;
}

//Function to check if queue is full
bool is_arr_queue_full(queue_arr_t *queue)
{
    if(queue->rear==queue->x)
    {
       printf("\n Queue is Full");
       return true;
    }
    return false;
}

//Function to dequeue element from array queue
int dequeue_arr(queue_arr_t *queue)
{
   int element = 0;
   ADD_START_TIME(start);
   if(queue->front==queue->rear)
   {
      printf("\n Queue is empty");
      element = 0;
   }
   else
   {
      element = queue->queue[queue->front++];
      printf("\n Deleted Element is %d",element);
      queue->x++;
   }  
   ADD_START_TIME(end);
   GETTIMESPENT_IN_FUNCTION(start, end)
   return element;        
}

//Function to print elements of array queue
void print_queue_arr(queue_arr_t *queue)
{
    printf("\nQueue Elements are:\n ");
    if(queue->front==queue->rear)
        printf("\n Queue is Empty");
    else
    {
         for(i=queue->front; i<queue->rear; i++)
         {
            printf("\n%d",queue->queue[i]);
            printf("\n");
         }
    }
}

#if 1
/* Array queue main program to test the queue implmentation of array */
int queue_main()
{
    int element = 0;
    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit \n5.Check full \n6.check Empty");
    init_array_queue(&queue);
    while(ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter no %d:",j++);
            scanf("%d",&element);
            enqueue_arr(&queue, element);
            break;
        case 2:
            printf("\n Deleted Element is %d",dequeue_arr(&queue));
            break;
        case 3:
            printf("\nQueue Elements are:\n ");
            print_queue_arr(&queue);

            break;
         case 5:
            if(is_arr_queue_empty(&queue) == 1)
                printf("\n queue is empty" );
            else
                printf("\n queue is not empty");
            break;
         case 6:
            if(is_arr_queue_full(&queue) == 1)
               printf("\n queue is full"); 
            else
               printf("\n queue is not full"); 
            break;
         case 4:
            exit(0);
         default:
                printf("Wrong Choice: please see the options");
         }
    }
    return 0;
}
#endif
