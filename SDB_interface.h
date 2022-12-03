#ifndef SDB_interface_H_
#define SDB_interface_H_
#include "DATA_TYPES.h"

#define NULL 0

typedef struct DataBase
{
    u32 id ;
    u32 year;
    u32 courses_Ids[3];
    u32 courses_Grades[3];
   struct DataBase* next_node_ptr;

}SDB_node;

/**
 * @brief check the data base is full or not
 * 
 * @return true  :the data is full
 * @return false : the data not full
*/
void SDB_IsFull(void);

/**
 * @brief : show me number of students stored  in memory
 * 
 * @return : (display )number of entries
*/

void SDB_Get_UsedSize(void);

/**
 * @brief : Add data for every student add to data base
 * 
 * @param [in] ID : student id
 *  @param [in] year : student age
 *  @param [in] subjects : the three subject 
 *  @param [in] grades : the grade of every subject
 * 
 * @return true : if the data add successfully 
 * @return false : otherwise
 * 
*/

void SDB_ADD_Data(void);

/**
 * @brief : delet the student data according it's id
 * 
 * @return true : if the data is deletd successfully
 * @return  false : otherwise
*/

void SDB_Delet_Data(void);

/**
 * @brief : read the data that match with ID 
 * 
 * @return true : if the data is exist 
 * @return false: otherwise 
*/

void SDB_Read_Data(void);

/**
 * @brief : display the IDs of the students
 * @return : list of IDs
*/

void SDB_Get_Ids(void);

/**
 * @brief : check id is exist or not 
 * @return true: if the id is exist
 * @return  flase : otherwise
*/

void SDB_IS_ID_Exist(void);



#endif