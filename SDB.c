
#include <stdio.h>
#include <stdlib.h>
#include "SDB_interface.h"

SDB_node* head = NULL;

static int counter =0;

void SDB_IsFull(void)
{
if (counter ==10)
{
    printf("\nthe data is full there is no a free space :( \n");

}
else
{
  printf("\nthe data is not full there is %d free space ;) \n",(10-counter));
}
}

void SDB_Get_UsedSize(void)
{
  printf("\n there are %d entery in the database \n ",counter);
}

void SDB_ADD_Data(void)
{
    if(head == NULL)
    {
        head = (SDB_node*)malloc(sizeof(SDB_node));
        printf("\nPlease Enter the ID for the first student: \n");
        scanf("%d", &head->id);
        printf("\nPlease Enter the Year of the student: \n");
        scanf("%d", &head->year);
        u8 i;
        for(i = 0; i < 3; i++)
        {
            printf("\n Pleas Enter the Courses ID number   : %d \n ",i+1);
            scanf("%d",&(head->courses_Ids[i]));
            printf("\n Pleas Enter the Course Grade number : %d  (hint 0-->100)\n",i+1);
            scanf("%d",&(head->courses_Grades[i]));
        }
        head->next_node_ptr = NULL;
        counter++;
    }
    else
    {
        if (counter<10)
        {
           SDB_node* New_Node;
           New_Node = (SDB_node*)malloc(sizeof(SDB_node));
           printf("\n pleas Enter The ID For a Student: \n");
           scanf("%d",&New_Node->id);
           printf("\n Pleas Enter The Year of The student: \n");
           scanf("%d",&New_Node->year);

           for (int i =0; i<3;i++)
           {
            printf("\n Pleas Enter the Courses ID number   : %d \n ",i+1);
            scanf("%d",&(New_Node->courses_Ids[i]));
            printf("\n Pleas Enter the Course Grade number : %d   (hint 0-->100)\n",i+1);
            scanf("%d",&(New_Node->courses_Grades[i]));

           }

           SDB_node* Last_Node = head;

           while(Last_Node->next_node_ptr != NULL)
           {
            Last_Node = Last_Node->next_node_ptr;
           }

           Last_Node->next_node_ptr = New_Node;
           New_Node->next_node_ptr = NULL;
           counter ++;


        }

        else
        {
            printf("\n The database is full sorry ");
        }
    }
}

void SDB_Delet_Data(void)
{
    if (head != NULL)
    {
      u32 id = 0;

      printf("\n Please Enter the ID to be deleted: \n");
      scanf("%d",&id);
      SDB_node*current_node = head;
      SDB_node* temp =head;

      if(temp->id == id)
      {
        head =head->next_node_ptr;
        free(temp);
        temp = NULL;
        counter-- ;
        printf("\n the ID had found and deleted successfully \n");
      }
      else
      {
        while(current_node->next_node_ptr !=NULL)
        {
          if(current_node->next_node_ptr->id == id)
          {
                     temp= current_node->next_node_ptr;
                     break;
          }
          else
          {
            current_node = current_node->next_node_ptr;
          }
        }
        if(current_node->next_node_ptr==NULL)
        {
         printf("\n the data you search is not found pls try again later sorry \n");
        }else
        {
        current_node->next_node_ptr = temp->next_node_ptr;

        free(temp);
        temp=NULL;
        counter--;

        printf("\n The ID you Search for it is found and data deleted successfully \n");
        }
      }

    }
    else
    {
      printf("\n There is no any  data To delet from it pls add entry first ");
    }


}

void SDB_Read_Data(void)
{
  if( head !=NULL)
  {
    u32 id =0;
    u8 fire_flag =0;
    printf("\n please enter the ID of the student: \n");

    scanf("%d",&id);

    SDB_node* search_node = head ;

    while (search_node !=NULL)
    {
      if(search_node->id ==id)
      {
        printf("\n student ID = %d  and the student year is : %d \n",search_node->id , search_node->year);

        for(int i=0 ; i<3;i++)
        {
           printf("\n course code of course number : %d  is = %d \n",i+1,search_node->courses_Ids[i]);
           printf("\n course Grade of course number : %d  is = %d from 100\n",i+1,search_node->courses_Grades[i]);

        }
        fire_flag =1;
        break;
      }
      else

      {
        search_node = search_node->next_node_ptr;
      }
    }
    if(fire_flag !=1)
    {
      printf("\n there is no data for this ID\n");
    }

  }else
    {
      printf("\n There is no any  data  pleas add data entery first ");
    }


}

void SDB_Get_Ids(void)
{
  if(head!= NULL)
  {
     SDB_node* search_node ;

     search_node = head;

     while(search_node != NULL)
     {
      printf("\n student ID = %d  and the student year is : %d \n",search_node->id , search_node->year);

        for(int i=0 ; i<3;i++)
        {
           printf("\n course code of course number : %d  is = %d \n",i+1,search_node->courses_Ids[i]);
           printf("\n course Grade of course number : %d  is = %d from 100\n",i+1,search_node->courses_Grades[i]);
        }

        search_node =search_node->next_node_ptr;
     }

  }else
    {
      printf("\n There is no any  data  pleas add data entery first ");
    }

}

void SDB_IS_ID_Exist(void)
{
  if (head !=NULL)
  {
    u32 id =0;
    u8 fire_flag =0;
    printf("\n please enter the ID  to check if it exist or not\n");

    scanf("%d",&id);

    SDB_node* search_node = head;

    while( search_node != NULL)
    {
      if(search_node->id == id)
      {
        printf("\n yes this ID is exist ..successfully process...\n ");

        fire_flag =1;
        break;
      }else
      {
        search_node = search_node->next_node_ptr;
      }
    }

    if(fire_flag !=1)
    {
      printf("\n sorry this ID is  not exist ..Failed process...\n ");
    }
  }
  else
    {
      printf("\n There is no any  data  pleas add data entery first ");
    }

}

