/*
 * This file contains the main.c for the assignmnet 
 * it prints the MENU and input cmdline and file 
 */

#include "header.h"
#include "bst.h"

extern queue_arr_t queue;
extern tree_node *root;

/* static function declarations */
static unsigned int isNumber(char* stringArray);
static void get_cmdline_input(char * string);
static unsigned int  validate_file_name(char *file_name);

/* main program */
int main()
{
  unsigned int option, num;
  char input[FILE_NAME_SIZE] ;
  const char delimiters[]=" ,\n";
  char buffer[MAX_NUMBER_READ] ;
  char *file_token, *input_token;
  FILE *fp = NULL;

  init_array_queue(&queue);
  bstCreateRoot(&root);
  while(1) {
    /* MENU for user */
    printf("\nInput Description \n");
    printf("1.    Input into Array Queue from File (Multiple elements\n");
    printf("2.    Input into Array Queue from command line (Single Element) \n");
    printf("3.    Remove element from Array Queue (Single Element)\n");
    printf("4.    Input into List Queue from File\n");
    printf("5.    Input into List Queue from command line \n");
    printf("6.    Remove element from List Queue \n");
    printf("7.    Input into Sorted List from File \n");
    printf("8.    Input into Sorted List from command line \n");
    printf("9.    Find element in Sorted List \n");
    printf("10.   Remove element in Sorted List \n");
    printf("11.   Input into BST from File \n");
    printf("12.   Input into BST from command line \n");
    printf("13.   Find element in BST \n");
    printf("14.   Remove element from BST \n");
    printf("15.   Print BST in order. \n");
    printf("16.   Exit from the Program. \n");
    printf("\n  please enter the corrent input from above MENU \n");

    /* Menu option from User */
    printf("Enter Input option = ");
    scanf("%u", &option);
    getchar();

 //   printf("\n input  = %c \n",option);
    /* Error hadling if input is incorrect */
    if(option < 1 || option > 16) {
       printf("Error : Invalid MENU option \n");
       continue;
    }

    /* switch case handling for all above options */
    switch(option) {
     case 1:
        printf("\n files with txt and csv extension supported. ");
        printf("\n multiple files with space separation can be entered ");
        printf(" Enter the file name[s]: \n");
        get_cmdline_input(input);
        file_token = strtok(input,delimiters);
        while(file_token != NULL) {
          /* validate file name for txt/ csv extension */
          if(!validate_file_name(file_token)) {
            printf("File Name entered in not corret %s \n",file_token);
          }
          else {
            /* insert from file into sorted list */
            fp = fopen(file_token, "r");
            if(fp == NULL) {
              printf("Error:  could not open file %s\n",file_token);
            }
            else {
              while(fgets(buffer, MAX_NUMBER_READ, fp)) {

                input_token = strtok(buffer,delimiters);
                while(input_token != NULL)
                {
                  if(!isNumber(input_token)) {
                    printf("not valid number %s\n",input_token);
                  } else {
                     enqueue_arr(&queue, atoi(input_token));
                  }
                  input_token = strtok(NULL,delimiters);
                }
              }
              fclose(fp);
            }
              //            insert_element_from_file(token);
          }
          file_token = strtok(NULL, delimiters);
        }
        file_token = NULL;
        input_token = NULL;
        print_queue_arr(&queue);
       break;
     case 2:
        printf("\n Maximum 100 letters  with delimiter ' ' ','\n");
        printf("Enter the Number[s] : \n");
        get_cmdline_input(input);
        input_token = strtok(input,delimiters);
        while(input_token != NULL) {
          if(!isNumber(input_token)) {
            printf("Number entered in not corret %s ... skipping it \n",input_token);
          }
          else {
            enqueue_arr(&queue,atoi(input_token));
          }
          input_token = strtok(NULL, delimiters);
        }
        print_queue_arr(&queue);

       break;
     case 3:
           printf("\n Deleted Element is %d",dequeue_arr(&queue));
        print_queue_arr(&queue);
       break;
     case 4:
        printf("\n files with txt and csv extension supported. ");
        printf("\n multiple files with space separation can be entered ");
        printf(" Enter the file name[s]: \n");
        get_cmdline_input(input);
        file_token = strtok(input,delimiters);
        while(file_token != NULL) {
          /* validate file name for txt/ csv extension */
          if(!validate_file_name(file_token)) {
            printf("File Name entered in not corret %s \n",file_token);
          }
          else {
            /* insert from file into sorted list */
            fp = fopen(file_token, "r");
            if(fp == NULL) {
              printf("Error:  could not open file %s\n",file_token);
            }
            else {
              while(fgets(buffer, MAX_NUMBER_READ, fp)) {

                input_token = strtok(buffer,delimiters);
                while(input_token != NULL)
                {
                  if(!isNumber(input_token)) {
                    printf("not valid number %s\n",input_token);
                  } else {
                     enqueue(atoi(input_token));
                  }
                  input_token = strtok(NULL,delimiters);
                }
              }
              fclose(fp);
            }
              //            insert_element_from_file(token);
          }
          file_token = strtok(NULL, delimiters);
        }
        file_token = NULL;
        input_token = NULL;
        display();
       break;
     case 5:
        printf("\n Maximum 100 letters  with delimiter ' ' ','");
        printf("Enter the Number[s] : \n");
        get_cmdline_input(input);
        input_token = strtok(input,delimiters);
        while(input_token != NULL) {
          if(!isNumber(input_token)) {
            printf("Number entered in not corret %s ... skipping it \n",input_token);
          }
          else {
            enqueue(atoi(input_token));
          }
          input_token = strtok(NULL, delimiters);
        }
        display();

       break;
     case 6:
          printf("Dequeued element is :%d\n", dequeue());
         display();
       break;
     case 7:
        /* Insert the elements from csv or txt file */
        printf("\n files with txt and csv extension supported. \n");
        printf("\n multiple files with space separation can be entered \n");
        printf("\n Enter the file name[s]: \n");
        get_cmdline_input(input);
        file_token = strtok(input,delimiters);
        while(file_token != NULL) {
          /* validate file name for txt/ csv extension */
          if(!validate_file_name(file_token)) {
            printf("File Name entered in not corret %s \n",file_token);
          }
          else {
            /* insert from file into sorted list */
            fp = fopen(file_token, "r");
            if(fp == NULL) {
              printf("Error:  could not open file %s\n",file_token);
            }
            else {
              while(fgets(buffer, MAX_NUMBER_READ, fp)) {

                input_token = strtok(buffer,delimiters);
                while(input_token != NULL)
                {
                  if(!isNumber(input_token)) {
                    printf("not valid number %s\n",input_token);
                  } else {
                     insert_element(atoi(input_token));
                  }
                  input_token = strtok(NULL,delimiters);
                }
              }
              fclose(fp);
            }
              //            insert_element_from_file(token);
          }
          file_token = strtok(NULL, delimiters);
        }
        file_token = NULL;
        input_token = NULL;
        display_sorted_list();
        break;

     case 8:
        printf("\n Maximum 100 letters  with delimiter ' ' ','\n");
        printf("Enter the Number[s] : \n");
        get_cmdline_input(input);
        input_token = strtok(input,delimiters);
        while(input_token != NULL) {
          if(!isNumber(input_token)) {
            printf("Number entered in not corret %s ... skipping it \n",input_token);
          }
          else {
            insert_element(atoi(input_token));
          }
          input_token = strtok(NULL, delimiters);
        }

        display_sorted_list();
        break;

     case 9:
        printf("please enter element  \n");
        scanf("%d",&num);
        if(find_element_in_sorted_list(num))
        {
           printf("element = %d is present in sorted list \n",num);
        }
        else {
          printf("elemnt = %d is not present in sorted list \n",num);
        }
        display_sorted_list();
        break;

     case 10:
       printf("please enter element \n");
       scanf("%d", &num);
       if(delete_element_from_sorted_list(num))
       {
         printf("element %d is deleted from sorted list \n",num);
       }
       else
       {
         printf("element %d is not present in sorted list \n",num);
       }
        display_sorted_list();
       break;
     case 11:
        /* Insert the elements from csv or txt file */
        printf("\n files with txt and csv extension supported. \n");
        printf("\n multiple files with space separation can be entered \n");
        printf("\n Enter the file name[s]: \n");
        get_cmdline_input(input);
        file_token = strtok(input,delimiters);
        while(file_token != NULL) {
          /* validate file name for txt/ csv extension */
          if(!validate_file_name(file_token)) {
            printf("File Name entered in not corret %s \n",file_token);
          }
          else {
            /* insert from file into sorted list */
            fp = fopen(file_token, "r");
            if(fp == NULL) {
              printf("Error:  could not open file %s\n",file_token);
            }
            else {
              while(fgets(buffer, MAX_NUMBER_READ, fp)) {

                input_token = strtok(buffer,delimiters);
                while(input_token != NULL)
                {
                  if(!isNumber(input_token)) {
                    printf("not valid number %s\n",input_token);
                  } else {
                     bstInsert(&root, atoi(input_token));
                  }
                  input_token = strtok(NULL,delimiters);
                }
              }
              fclose(fp);
            }
              //            insert_element_from_file(token);
          }
          file_token = strtok(NULL, delimiters);
        }
        file_token = NULL;
        input_token = NULL;
        display_sorted_list();

       break;
     case 12:
        printf("\n Maximum 100 letters  with delimiter ' ' ','\n");
        printf("Enter the Number[s] : \n");
        get_cmdline_input(input);
        input_token = strtok(input,delimiters);
        while(input_token != NULL) {
          if(!isNumber(input_token)) {
            printf("Number entered in not corret %s ... skipping it \n",input_token);
          }
          else {
            bstInsert(&root, atoi(input_token));
          }
          input_token = strtok(NULL, delimiters);
        }


       break;
     case 13:
        printf("please enter element  \n");
        scanf("%d",&num);
        if(bstSearch(root,num))
        {
           printf("element = %d is present in BSTt \n",num);
        }
        else {
          printf("elemnt = %d is not present in BST \n",num);
        }
       break;
     case 14:
       printf("please enter element \n");
       scanf("%d", &num);
       if(bstDelete(&root,num))
       {
         printf("element %d is deleted from BST \n",num);
       }
       else
       {
         printf("element %d is not present in BST \n",num);
       }
       break;
     case 15:
        inorder(root);
       break;
     case 16:
       exit(0);  
       break;
     default:
       break;
    }

  }
}


static unsigned int isNumber(char* stringArray)
{
    unsigned int i = 0;
    //go through each character
    //location in the array until
    //we reach the null character (end of input)
    for (i = 0; stringArray[i]!='\000'; i++)
    {
        if(isdigit(stringArray[i])==0)//if the current character is not a digit....
            return FALSE; //return false and end function here

    }

    return TRUE;//return true since the entire array contained numeric characters
}

/* Read input from Standard Input and store it in buffer
 * input arg : buffer  */
static void get_cmdline_input(char * string)
{
  fgets(string, FILE_NAME_SIZE, stdin);

  while (*string != '\0')
  {
    if (*string == '\n')
    {
      *string = '\0';
      break;
    }
    string++;
  }
  return;
}

/* Validate the file name for extension 
 * input arg : Filename  
 * output : True or False */
static unsigned int validate_file_name(char *file_name)
{
   char *ext = NULL;
   printf("filename is = %s \n", file_name);
   ext = strrchr(file_name, '.');
   if (!ext) {
     return FALSE;
   } else if (!strcmp(ext, ".txt")) {
     return TRUE;
   } else if (!strcmp(ext, ".csv")) {
     return TRUE;
   } else {
      return TRUE;
   }
}

#if 0
/* Validate the file name for extension 
 * input arg : Filename  */
void insert_element_from_file(char *filename)
{
   FILE *fp = NULL;
   unsigned int count = 0, i =0;
   char *token = NULL;
   // open the file in write mode
   fp = fopen(filename, "r");
   if(fp == NULL) {
     printf("Error:  could not open file \n");
     return;
   }

   while(fgets(buffer, MAX_NUMBER_READ, fp)) {

      token = strtok(buffer,delimiters);
      while(token != NULL)
      {
        printf("number = %s",token);
        if(!isNumber(token)) {
          printf("not valid number \n");
        } else {
          insert_element_from_cmdline(token);
        }
        token = strtok(NULL,delimiters);
      }
    }
}

void insert_element_from_cmdline(char *number)
{
     int digit= atoi(number); 
}
#endif
