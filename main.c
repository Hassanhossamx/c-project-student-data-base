#include <stdio.h>
#include <stdlib.h>
#include "SDB_interface.h"

s8 determinator = 0;

int main(void)

{
  while(1)
  {
    printf("\nPlease Choose a mode:\n1. Add Entry\n2. Delete Entry\n3. Read Entry\n4. Get all IDs\n5. Check the existence of an ID\n6. Number of IDs\n7. Is database full?\n(Press -1 to exit)\n");
    scanf("%d", &determinator);

   if(determinator == -1)
       {
          printf("\n Thank you we 5alina nshofaak tanii ;) \n");
          break;
       }
    switch(determinator)
        {
            case 1 : SDB_ADD_Data()     ; break;
            case 2 : SDB_Delet_Data()   ; break;
            case 3 : SDB_Read_Data()    ; break;
            case 4 : SDB_Get_Ids()      ; break;
            case 5 : SDB_IS_ID_Exist()  ; break;
            case 6 : SDB_Get_UsedSize() ; break;
            case 7 : SDB_IsFull()       ; break;
            default: printf("\nPlease Enter a valid mode\n");
        }

  }

return 0;
}
