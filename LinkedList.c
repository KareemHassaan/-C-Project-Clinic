/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						24 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Clinic System                                                       							                      *
* ! File Name	: Clinic.c                                                       								                      *
* ! Description : This file has the implementation of Basic of Clinic functions        							                      *
* ! Compiler  	: GNU GCC Native Compiler                                            							                      *
* ! Target 	  	: Windows 10                                                        							                      *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"

/************************************************** Self Files Inclusions ************************************************************/
#include"LinkedList.h"

/***************************************************** Global Variables **************************************************************/
Node * Head = NULL; 														//The head of the Patient list , Global variable.

/*************************************************************************************************************************************/
/******************************************************* Functions Definition ********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: LinkedList_InsertNodeHead																	                      *
* Parameters (in)	: Node * CopyStructNewPatient											                      					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration to insert a node from the begining of the list				           	     			  *
**************************************************************************************************************************************/
 void LinkedList_InsertNodeHead(Node * CopyStructNewPatient)                 
 {
	/*Node cereation Dynamic memmory allocation*/
	 Node * Local_PStructFirstNode = (Node*)malloc(sizeof(Node));
	
	/****************************************** Storing the data of the new patient **************************************************/
	
	/*Storing the Patient ID from the user in the node.*/
	 Local_PStructFirstNode -> uint8patientID   	= CopyStructNewPatient -> uint8patientID;
	/*Storing the Patient First Name from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewPatient -> uint8patientFirstName, Local_PStructFirstNode -> uint8patientFirstName);
	/*Storing the Patient Last Name from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewPatient -> uint8patientSecondName, Local_PStructFirstNode -> uint8patientSecondName);
	/*Storing the Patient Age from the user in the node.*/
	 Local_PStructFirstNode -> uint8patientAge 	= CopyStructNewPatient -> uint8patientAge;
	/*Storing the Patient Gender from the user in the node.*/
	 Local_PStructFirstNode -> uint8patientGender = CopyStructNewPatient -> uint8patientGender;

	/*********************************************************************************************************************************/
	
	/*Making the node to point to the Next Node Already exist and if not exist it will point on NULL*/
	 Local_PStructFirstNode -> NextNode = Head;  
	/*Making the head pointing on the first node*/
	 Head = Local_PStructFirstNode;
 }     

/**************************************************************************************************************************************
* Function Name		: LinkedList_DeleteNode																	                          *
* Parameters (in)	: uint8 Copy_uint8PatientID											                      				          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Delete a node at nth Node in the list				           	     				      *
**************************************************************************************************************************************/
 void LinkedList_DeleteNode(uint8 Copy_uint8PatientID)                 
 {
	/*Initialize current PTR to itterate on the List to get the wanted node to Delete and Initially point on the head*/
	 Node * Local_PStructDeletedptr = Head;  
	/*Initialize Previous PTR the last node before the wanted node to Delete and Initially point on the head*/
	 Node * Local_PStructPreviousDeletedptr = Head;

	/*checking if the list is empty or not*/
	 if(Head == NULL)
	 {
		/*Print that the list is empty*/
		 printf("The List is empty and No Pateint Records.\n");
	 }
	/*checking if the Data wanted to delete in the first node*/
	 else if((Head -> uint8patientID) == Copy_uint8PatientID)
	 {
		/*Making the head pointing on the second node and delete the first one*/
		 Head = Local_PStructDeletedptr -> NextNode;
		/*Free the location from the Heap*/
		 free(Local_PStructDeletedptr);
		/*Printing Confirmation Message that the node Deleted Successfully*/
		 printf("Patient Records whose ID = %d Deleted Successfully.\n",Copy_uint8PatientID);
	 }
	 else
	 {
		/*Searching on the node wanted to delete*/
		 while((Local_PStructDeletedptr != NULL)&&((Local_PStructDeletedptr -> uint8patientID) != Copy_uint8PatientID))
		 {
			/*make the Previous PTR point on the next node (current PTR)*/
			 Local_PStructPreviousDeletedptr = Local_PStructDeletedptr;
			/*while not found the node wanted make the current PTR point on the next node*/
			 Local_PStructDeletedptr = Local_PStructDeletedptr -> NextNode;
		 }
		/*Checking if the node found or not*/
		 if( NULL == Local_PStructDeletedptr)
		 {
			/*Printing that the data not in the list*/
			 printf("Sorry This ID is not Exist.\n\n");
			
		 }
		 else
		 {
			/*Making the previous node pointing on the node after the deleted one*/
			 Local_PStructPreviousDeletedptr -> NextNode = Local_PStructDeletedptr -> NextNode;
			/*Free the location from the Heap*/
			 free(Local_PStructDeletedptr);
			
			/*Printing Confirmation Message that the node Deleted Successfully*/
			 printf("The Patient Data With ID %d Deleted Successfully.\n",Copy_uint8PatientID);
		 }
	 }
 }                             


/**************************************************************************************************************************************
* Function Name		: LinkedList_Traverse                   																	      *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To to print the list				           	     							              *
**************************************************************************************************************************************/  
 void LinkedList_Traverse()                               
 {
	/*Printing Loop Counter to itterate on the list*/
	 uint8 Local_uint8PatientNumber = 1;
	/*PTR to struct point on the current node to print it*/
	 Node * Local_PStructprint = Head;
	
	/*check if the list is empty or not*/
	 if(Local_PStructprint == NULL)
	 {
		/*Printing that the list is empty*/
		 printf("The List is empty and No Pateint Records.\n");
		return;
	 }
	 else
	 {
		
		/*Printing a Header*/
		printf("|************************************** PATIENT RECORDS ****************************************|\n");
		
		while(Local_PStructprint != NULL)
	    {
			/******************************************** Printing the data of the patient ****************************************************/
			
			printf("The Patient Number %d :\n" ,Local_uint8PatientNumber);
			/*Printing the Patient ID of the current node.*/
			printf("Patient ID           : %d\n"  ,Local_PStructprint->uint8patientID);
			/*Printing the Patient First Name of the current node.*/
			printf("Patient Name         : ");
			LinkedList_StringPrint(Local_PStructprint -> uint8patientFirstName);
			/*Printing the Patient Last Name of the current node.*/
			printf(" ");
			LinkedList_StringPrint(Local_PStructprint -> uint8patientSecondName);
			printf("\n");
			/*Printing the Patient Age of the current node.*/
			printf("Patient Age          : %d\n"  ,Local_PStructprint->uint8patientAge);
			/*Printing the Patient Gender of the current node.*/
			printf("Patient Gender       : %c\n"  ,Local_PStructprint->uint8patientGender);
			
			/*Closing the Header*/
			printf("|***********************************************************************************************|\n");
			 
			/*********************************************************************************************************************************/
			
			/*Making the PTR Point to the Next Node*/
			Local_PStructprint = Local_PStructprint -> NextNode;
			/*Incerement the Loop Counter*/
			Local_uint8PatientNumber++;
	    }
		
	 }
 }  

/**************************************************************************************************************************************
* Function Name		: LinkedList_ID_Search																	                          *
* Parameters (in)	: uint8 Copy_uint8PatientID											                      						  *
* Parameters (out)	: None																						                      *
* Return value		: Node * Local_uint8IDExistance																					  *
* Description		: Function declaration To search in the list				           	     							          *
**************************************************************************************************************************************/
 Node  * LinkedList_ID_Search(uint8 Copy_uint8PatientID)
 {
	Node * Local_uint8IDExistance = ClinicSystem_ID_NOT_EXIST;
	
	/*PTR to struct to Point on the Wanted Node and Initially point on the head*/
	 Node * Local_PStructUnknownNode = Head; 
	
	/*check if the list is empty or not*/
	 if(Head == NULL)
	 {
		
		Local_uint8IDExistance = ClinicSystem_ID_NOT_EXIST;
	 }
	 else
	 {
		/*Searching about the Node Position needed*/
		 while((Local_PStructUnknownNode != NULL) && (Local_PStructUnknownNode -> uint8patientID != Copy_uint8PatientID))
		 {
			/*Storing the Pointer of the Needed Node*/
			 Local_PStructUnknownNode = Local_PStructUnknownNode -> NextNode;
		 }
		 
		 if(Local_PStructUnknownNode != NULL)
		 {
			/*Return the Pointer of the Needed Node*/
			 Local_uint8IDExistance = Local_PStructUnknownNode;
		 }
		 else
		 {
			/*Return NULL if Not found*/
			 Local_uint8IDExistance = ClinicSystem_ID_NOT_EXIST;
		 }
	 }
	
	/*Return the Pointer of the Needed Node*/
	 return	Local_uint8IDExistance;
 }

/**************************************************************************************************************************************
* Function Name		: LinkedList_StringStore																	                      *
* Parameters (in)	: uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination												  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Copy an array of char to another one				           	     				      *
**************************************************************************************************************************************/
 void LinkedList_StringStore(uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination)
 {
	uint8 Local_uint8NameLoopCounter = 0;
	
	/*Storing the Patient Name from the user in the node char by char.*/
	for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < ClinicSystem_NAME_SIZE; Local_uint8NameLoopCounter++)
	{
		Copy_uint8StoringDestination[Local_uint8NameLoopCounter] = Copy_uint8String[Local_uint8NameLoopCounter];
	}	
 }

/**************************************************************************************************************************************
* Function Name		: LinkedList_StringPrint																	                      *
* Parameters (in)	: uint8 * Copy_uint8String											                      						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function declaration To Print an array of char				           	     							      *
**************************************************************************************************************************************/
 void LinkedList_StringPrint(uint8 * Copy_uint8String)
 {
	uint8 Local_uint8NameLoopCounter = 0;
	
	/*Printing the Patient Name char by char.*/
	for(Local_uint8NameLoopCounter = 0; Copy_uint8String[Local_uint8NameLoopCounter] != '\0'; Local_uint8NameLoopCounter++)
	{
		printf("%c", Copy_uint8String[Local_uint8NameLoopCounter]);
	}
 }
