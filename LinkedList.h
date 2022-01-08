/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						24 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Clinic System                                                        							                      *
* ! File Name	: LinkedList.h                                               	      							                      *
* ! Description : This file has the LinkedList definitions needed			       							                          *
* ! Compiler  	: GNU GCC Native Compiler                                            							                      *
* ! Target 	  	: Windows 10                                         							                      				  *
**************************************************************************************************************************************/
#ifndef Linked_List_H
#define Linked_List_H

#define ClinicSystem_NAME_SIZE	 	14															//Number of Name characters.
#define ClinicSystem_ID_NOT_EXIST   0															//Comparator with ID is Not Exist.


/*Structure as a Patient*/
typedef struct node                         
{
    uint8  uint8patientID;
	uint8  uint8patientFirstName[ClinicSystem_NAME_SIZE];
	uint8  uint8patientSecondName[ClinicSystem_NAME_SIZE];
    uint8  uint8patientAge;
    uint8  uint8patientGender;
	
    struct node * NextNode;
}Node;



/*************************************************************************************************************************************/
/******************************************************** Functions Prototype ********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: LinkedList_InsertNodeHead																	                      *
* Parameters (in)	: Node * CopyStructNewPatient											                      					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration to insert a node from the begining of the list				           	     			  *
**************************************************************************************************************************************/
void LinkedList_InsertNodeHead(Node * CopyStructNewPatient); 
/**************************************************************************************************************************************
* Function Name		: LinkedList_DeleteNode																	                          *
* Parameters (in)	: uint8 Copy_uint8PatientID											                      				          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Delete a node at nth Node in the list				           	     				      *
**************************************************************************************************************************************/
void LinkedList_DeleteNode(uint8 Copy_uint8PatientID);  
/**************************************************************************************************************************************
* Function Name		: LinkedList_Traverse                   																	      *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To to print the list				           	     							              *
**************************************************************************************************************************************/  
void LinkedList_Traverse();
/**************************************************************************************************************************************
* Function Name		: LinkedList_ID_Search																	                          *
* Parameters (in)	: uint8 Copy_uint8PatientID											                      						  *
* Parameters (out)	: None																						                      *
* Return value		: Node * Local_uint8IDExistance																					  *
* Description		: Function declaration To search in the list				           	     							          *
**************************************************************************************************************************************/
Node  *  LinkedList_ID_Search(uint8 Copy_uint8PatientID);
/**************************************************************************************************************************************
* Function Name		: LinkedList_StringStore																	                      *
* Parameters (in)	: uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination												  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Copy an array of char to another one				           	     				      *
**************************************************************************************************************************************/
void LinkedList_StringStore(uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination);
/**************************************************************************************************************************************
* Function Name		: LinkedList_StringPrint																	                      *
* Parameters (in)	: uint8 * Copy_uint8String											                      						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Print an array of char				           	     							      *
**************************************************************************************************************************************/
void LinkedList_StringPrint(uint8 * Copy_uint8String);


#endif /* Linked_List_H */