/*
 * This file contains the headers for the assignmnet
 * it contains #defines, file declarations and structs
 */

#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "common.h"

#define FILE_NAME_SIZE 100
#define MAX_NUMBER_READ  80

#define QUEUE_ARRAY_SIZE 5
#define TRUE 1
#define FALSE 0
/* Arrary queue data structure */
struct queue_arr{
   int queue[QUEUE_ARRAY_SIZE];
    int front; // front element of queue
    int rear; // rear element of queue
    int x; // current element of queue
};
typedef struct queue_arr queue_arr_t;


//structure contains data and link
// Structure to create a node with data and the next pointer
struct node
{
    unsigned int data;
    struct node *next;
};

typedef struct node sortedList;
#if 0
void insert_element_from_file(char *filename);
void insert_element_from_cmdline(char *number);
#endif
void  insert_element(unsigned int data);
unsigned int find_element_in_sorted_list(unsigned int num);
unsigned int delete_element_from_sorted_list(unsigned int data);
void display_sorted_list();

/* Operation of queue implemented using array*/
void init_array_queue(queue_arr_t *queue);
void enqueue_arr(queue_arr_t *queue, int element);
int dequeue_arr(queue_arr_t *queue);
void print_queue_arr(queue_arr_t *queue);
bool is_queue_arr_empty(queue_arr_t *queue);
bool is_arr_queue_full(queue_arr_t *queue);

/* Operation of queue implemented using linked lists*/
void display() ;
void enqueue(int value) ;
int dequeue() ;

#endif
