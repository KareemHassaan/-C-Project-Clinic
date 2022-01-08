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
#include"Clinic.h"  

/***************************************************** Global Variables **************************************************************/

/*Variable To Store That The Admin Password is Valid.*/
uint8 Global_uint8ClinicPasswordCheck = 0;										
/*Array of Struct to Store the Schedule of the Clinic and Avaliable Time Slots.*/
Slot ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOTS_NUM] = CLINIC_SYSTEM_TIME_SLOTS_SCHEDULE;


/*************************************************************************************************************************************************************/
/***************************************************** Admin Mode Functions Defintion ************************************************************************/
/*************************************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminPasswordCheck																	          *
* Parameters (in)	: None						                      																  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To check the Validity of the Password of the Admin								                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminPasswordCheck()
 {
	/*Variable to count down the Password Entering trials*/
	 static uint8 Local_uint8ClinicPasswordTrials = 0;
	/*Variable to scan in it the Password entered by the user*/
	 uint16 Local_uint16ClinicAdminPassword = 0;

	/*Clearing the Password Validity Flag*/
	 Global_uint8ClinicPasswordCheck = 0;
	/*Reset the Number of the Password trials*/
	 Local_uint8ClinicPasswordTrials = CLINIC_SYSTEM_MAX_PASSWORD_TRIALS;
	 
	 
	while((Local_uint8ClinicPasswordTrials !=0 ) && (Global_uint8ClinicPasswordCheck == 0))
	{
		/*Scaning from the Admin the Password*/
		 printf("Please Enter The Admin Password : ");
		 scanf("%d",&Local_uint16ClinicAdminPassword);
		
		/*Checking if the Password valid or not*/
		 if(CLINIC_SYSTEM_ADMIN_PASSWORD == Local_uint16ClinicAdminPassword)
		 {
			 /*Firing a Flag that the password Checked successfully and valid*/
			 Global_uint8ClinicPasswordCheck = CLINIC_SYSTEM_VALID_PASSWORD;
		 }
		 else
		 {
		 	 /*Printing an Error message that the password entered is incorrect*/
			 printf("The Password is incorrect, Please Try Again.\n");
		 }

		/*Decrement the number of password Entering Trials*/		
		 Local_uint8ClinicPasswordTrials--;
	}
 }
 
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAddNewPatientRecord																	          *
* Parameters (in)	: uint8 Copy_uint8PatientID						                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Add New Patient Record in the List                							                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminAddNewPatientRecord()
 {
	/************************************ Scaning the new patient ID and check its validity *****************************************/
	
	/*Local Variable to store the Patient ID From The Admin*/
	 uint8  Local_uint8ClinicSystemNewID = 0;
	
	/*Printing a Message to the Admin To Enter the Patient ID*/
	 printf("Please Enter Patient ID :");
	/*Scaning From the Admin the Patient ID*/
	 scanf("%d",&Local_uint8ClinicSystemNewID);
	
	/*Scaning From the Admin the Patient ID while it is Repeated*/
	 while(LinkedList_ID_Search(Local_uint8ClinicSystemNewID))
	 {
		/*Printing a Message to the Admin To Reenter the Patient ID*/
		 printf("Sorry This ID is already used Enter another one : ");
		/*Rescaning From the Admin the Patient ID*/
		 scanf("%d",&Local_uint8ClinicSystemNewID);
	 }
	
	/***************************************** Storing the data of the new patient *************************************************/
	
	/*New Dynamic Allocation Struct to store the New Patient Record*/
	 Node * Local_PStructNewpatient = (Node*)malloc(sizeof(Node));
	
	/*Storing the Patient ID*/
	 Local_PStructNewpatient -> uint8patientID = Local_uint8ClinicSystemNewID;
	/*Storing the Patient First Name*/
	 printf("Please Enter Patient First Name :");
	 scanf("%s",&Local_PStructNewpatient-> uint8patientFirstName);
	/*Storing the Patient Last Name*/
	 printf("Please Enter Patient Last Name :");
	 scanf("%s",&Local_PStructNewpatient-> uint8patientSecondName);
	/*Storing the Patient Age*/
	 printf("Please Enter Patient Age :");
	 scanf("%d",&Local_PStructNewpatient-> uint8patientAge);
	/*Storing the Patient Gender*/ 
	 printf("Please Enter Patient Gender :");
	 scanf("%s",&Local_PStructNewpatient-> uint8patientGender);
	
	/*Inserting the New Pateint Record in the Clinic List*/
	 LinkedList_InsertNodeHead(Local_PStructNewpatient);
	 
	/******************************************************************************************************************************/
	
	/*Printing Confirmation message that the Pateint Record Added*/
	printf("Patient Records Added successfully.\n");
	
 }
 
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAddNewPatientRecord																	          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Edit a Patient Record in the List               	 							                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminEditPatientRecord()
 {	
	/*Pointer to struct to store the Patient Address needed to edit*/
	 static Node * Local_PStructEditedPatient = NULL;
	/*Variable to store the option of Editing*/
	 uint8  Local_ClinicSystemEditingOption = 0;
	/*Variable to store the ID of the Patient needed to Edit*/
	 uint8  Local_uint8ClinicSystemNewID = 0;

	/************************************ Scaning the new patient ID and check its validity *****************************************/
	
	/*Printing a message to the admin to enter the Pateint ID*/
	 printf("Please Enter Patient ID Needed to Edit:");
	/*Scaning from the Admin the ID of the Patient needed to edit*/
	 scanf("%d",&Local_uint8ClinicSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 if(!LinkedList_ID_Search(Local_uint8ClinicSystemNewID))
	 {
		/*Printing a message to the admin that Pateint ID not found*/
		 printf("Sorry This ID is not Found Be sure of the ID \n");
		
	 }
	
	/******************************************** Editing Patient Record Partition **************************************************/
	
	/*Storing the adresses of the wanted pateint to edit in a variable after found it*/
	 Local_PStructEditedPatient = LinkedList_ID_Search(Local_uint8ClinicSystemNewID);
	
	/*Printing an interface to the Admin to Choose An Option*/
	 printf("|************************************ EDIT PATIENT RECORD **************************************|\n\
		   \r|Please Enter (1) To Edit Patient ID.                                                           |\n\
		   \r|Please Enter (2) To Edit Patient First Name.                                                   |\n\
		   \r|Please Enter (3) To Edit Patient Second Name.                                                  |\n\
		   \r|Please Enter (4) To Edit Patient Age.                                                          |\n\
		   \r|Please Enter (5) To Edit Patient Gender.                                                       |\n\
		   \r|Please Enter (6) To Edit All Records.                                                          |\n\
		   \r|***********************************************************************************************|\n");
	 
	/*Scaning from the Admin Editing option needed*/
	 scanf("%d",&Local_ClinicSystemEditingOption);
	
	/*switching on the Editing option entered by the admin*/
	 switch(Local_ClinicSystemEditingOption)
	 {
		/************************************* CLINIC_SYSTEM_EDIT_PATIENT_ID *******************************************/
		
		 case CLINIC_SYSTEM_EDIT_PATIENT_ID:
		 
				/*Printing a message to the admin to enter the New Pateint ID*/
				 printf("Please Enter Patient New ID :");
				/*Scaning from the Admin the New ID of the Patient*/
				 scanf("%d",&Local_uint8ClinicSystemNewID);
				
				/*Checking if the New ID is Already Exist or not*/
				 while(LinkedList_ID_Search(Local_uint8ClinicSystemNewID))
				 {
					/*Printing a message to the admin to Reenter the New Pateint ID*/
					 printf("Sorry This ID is already used Enter another one : ");
					/*Rescaning from the Admin the New ID of the Patient*/
					 scanf("%d",&Local_uint8ClinicSystemNewID);
				 }
				
				/*Storing the New ID in The Patient Records*/
				 Local_PStructEditedPatient -> uint8patientID= Local_uint8ClinicSystemNewID;
				/*Confirmation message that the patient ID changed*/
				 printf("Patient ID Changed Successfully.\n");
				
		 break;
		 
		 /******************************** CLINIC_SYSTEM_EDIT_PATIENT_FIRST_NAME **************************************/
		 
		 case CLINIC_SYSTEM_EDIT_PATIENT_FIRSTNAME:
				
				/*Printing a message to the admin to enter the New Pateint First Name*/
				 printf("Please Enter Patient New First Name :");
				/*Scaning from the Admin the New First Name of the Patient*/
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientFirstName);
				 
				/*Confirmation message that the patient First Name changed*/
				 printf("Patient First Name Changed Successfully.\n");
				
		 break;
		 
		 /******************************** CLINIC_SYSTEM_EDIT_PATIENT_SECOND_NAME *************************************/
		 
		 case CLINIC_SYSTEM_EDIT_PATIENT_SECONDNAME:
		 
				/*Printing a message to the admin to enter the New Pateint Last Name*/
				 printf("Please Enter Patient New Last Name :");
				/*Scaning from the Admin the New Last Name of the Patient*/
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientSecondName);
				
				/*Confirmation message that the patient Last Name changed*/
				 printf("Patient Last Name Changed Successfully.\n");
				
		 break;
		
		/************************************ CLINIC_SYSTEM_EDIT_PATIENT_AGE ******************************************/
		
		 case CLINIC_SYSTEM_EDIT_PATIENT_AGE:
		 
				/*Printing a message to the admin to enter the New Pateint Age*/
				 printf("Please Enter Patient New Age :");
				/*Scaning from the Admin the New Age of the Patient*/
				 scanf("%d",&Local_PStructEditedPatient-> uint8patientAge);
				 
				/*Confirmation message that the patient Age changed*/
				 printf("Patient Age Changed Successfully.\n");
				
		 break;
		
		/********************************** CLINIC_SYSTEM_EDIT_PATIENT_GENDER *****************************************/
		
		 case CLINIC_SYSTEM_EDIT_PATIENT_GENDER:
		 
				/*Printing a message to the admin to enter the New Pateint Gender*/
				 printf("Please Enter Patient Gender :");
				/*Scaning from the Admin the New Gender of the Patient*/
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientGender);
				
				/*Confirmation message that the patient Gender changed*/
				 printf("Patient Gender Changed Successfully.\n");
				
		 break;
		
		/************************************ CLINIC_SYSTEM_EDIT_ALL_RECORDS *****************************************/
		
		 case CLINIC_SYSTEM_EDIT_ALL_RECORDS:
				
				/*Printing a message to the admin to enter the New Pateint ID*/
				 printf("Please Enter Patient New ID :");
				/*Scaning from the Admin the New ID of the Patient*/
				 scanf("%d",&Local_uint8ClinicSystemNewID);
				
				/*Checking if the New ID is Already Exist or not*/
				 while(LinkedList_ID_Search(Local_uint8ClinicSystemNewID))
				 {
					/*Printing a message to the admin to Reenter the New Pateint ID*/
					 printf("Sorry This ID is already used Enter another one : ");
					/*Rescaning from the Admin the New ID of the Patient*/
					 scanf("%d",&Local_uint8ClinicSystemNewID);
				 }
				
				/*Storing the New ID in The Patient Records*/
				 Local_PStructEditedPatient -> uint8patientID= Local_uint8ClinicSystemNewID;
				/*storing the New Patient First Name Entered by the Admin*/
				 printf("Please Enter Patient New First Name :");
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientFirstName);
				/*storing the New Patient Last Name Entered by the Admin*/
				 printf("Please Enter Patient New Last Name :");
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientSecondName);
				/*storing the New Patient Age Entered by the Admin*/
				 printf("Please Enter Patient New Age :");
				 scanf("%d",&Local_PStructEditedPatient-> uint8patientAge);
				/*storing the New Patient Gender Entered by the Admin*/
				 printf("Please Enter Patient Gender :");
				 scanf("%s",&Local_PStructEditedPatient-> uint8patientGender);
				
				/*Confirmation message that All the patient Records changed*/
				 printf("All Patient Records Changed Successfully.\n");
				
		 break;
		
		/***************************************** OPTION_INVALID **************************************************/
		
		 default:
			
				/*Printin to the Admin a message that the option entered is invalid*/
				printf("Sorry the option Entered is invalid.\n");
		 break;
	 }
 }

/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidReserveTimeSlot																		          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Reserve a New Time Slot with The Doctor                							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminReserveTimeSlot()
 {
	/*Variable to store the ID scanned from the admin*/
	 uint8  Local_uint8ClinicSystemNewID = 0;
	/*Variable to Store the Slot Time Scanned from the Admin needed to reserve*/
	 uint8 Local_uint8ClinicSystemSlotSelected = 0;
	/*Loop Counter of the Search for Loop that check that the Patient ID is not Reserve a slot before*/
	 uint8 Local_uint8ClinicSystemIDLoopCounter = 0;
	/*Pointer to struct the patient that wants to Reserve a slot*/
	 static Node * Local_PStructWantedPatient = NULL;
	/*Variable as a Flag to the Avaliable Slot Time List if it is Empty or not*/
	 static uint8 LocalClinicSystemAvaliableTimeSlots = CLINIC_SYSTEM_TIME_SLOTS_EMPTY;
	/*Variable as a Flag to check that the ID Entered is Exist in the List or not*/
	 uint8 Local_uint8ClinicSystemIDTimeSlotsExistance = ClinicSystem_ID_NOT_EXIST;
	 
	
	/******************************** Printing an interface to the Admin to Choose The Slot Needed from the Avaliable Time Slots ******************************/
	
	 printf("\r|********************************* CLINIC AVALIABLE TIME SLOTS ***********************************|\n");
	
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_00_PM__2_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_NOT_RESERVED)
	 {
	 	printf("\r|Please Enter (1) To Reserve 2:00 to 2:30 Slot.                                                   |\n");
	 	LocalClinicSystemAvaliableTimeSlots++;
	 }
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_30_PM__3_00_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_NOT_RESERVED)
	 {
	 	printf("\r|Please Enter (2) To Reserve 2:30 to 3:00 Slot.                                                   |\n");
	 	LocalClinicSystemAvaliableTimeSlots++;
	 }
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_3_00_PM__3_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_NOT_RESERVED)
	 {
	 	printf("\r|Please Enter (3) To Reserve 3:00 to 3:30 Slot.                                                   |\n");
	 	LocalClinicSystemAvaliableTimeSlots++;
	 }
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_00_PM__4_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_NOT_RESERVED)
	 {
	 	printf("\r|Please Enter (4) To Reserve 4:00 to 4:30 Slot.                                                   |\n");
	 	LocalClinicSystemAvaliableTimeSlots++;
	 }
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_30_PM__5_00_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_NOT_RESERVED)
	 {
	 	printf("\r|Please Enter (5) To Reserve 4:30 to 5:00 Slot.                                                   |\n");
	 	LocalClinicSystemAvaliableTimeSlots++;
	 }
	 if(CLINIC_SYSTEM_TIME_SLOTS_EMPTY == LocalClinicSystemAvaliableTimeSlots)
	 { 
	 	printf("\r|Sorry There is no any Slot available today.                                                      |\n");
	 }
	 printf("\r|*************************************************************************************************|\n");
	
	
	/**************************************************** Scaning Time Slot and Chek its validity ************************************************************/
	
	/*Scaning From the Admin the Time Slot Needed to Reserve*/
	 scanf("%d",&Local_uint8ClinicSystemSlotSelected);
	/*Checking if that Slot in the range and not reserved before*/
	 while((Local_uint8ClinicSystemSlotSelected > CLINIC_SYSTEM_SLOTS_NUM) || (ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemSlotSelected-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED))
	 {
		/*Printing a message to the Admin to Reenter the Slot Time again*/
		 printf("Please Enter a valid option and not Reserved Slot : ");
		/*Rescaning the Slot Time from the Admin*/
		 scanf("%d",&Local_uint8ClinicSystemSlotSelected);
	 }
	
	/********************************************************************************************************************************************************/
	
	/*Checking if the Avaliable Slot Time is not Empty*/
	 if(CLINIC_SYSTEM_TIME_SLOTS_EMPTY != LocalClinicSystemAvaliableTimeSlots)
	 {
		/************************************************* Scaning Patient ID and Chek its validity **************************************************************/
		
		/*Printing a message to the admin to enter the Pateint ID*/
		 printf("Please Enter Patient ID Needed to Reserve the slot:");
		/*Scaning from the Admin the ID of the Patient*/
		 scanf("%d",&Local_uint8ClinicSystemNewID);
		
		/*Checking if the ID is Already Exist or not*/
		while(!LinkedList_ID_Search(Local_uint8ClinicSystemNewID))
		{
			/*Printing a message to the admin to Reenter the Pateint ID*/
			 printf("Sorry This ID is not Found Be sure of the ID, Try again : ");
			/*Rescaning from the Admin the New ID of the Patient*/
			 scanf("%d",&Local_uint8ClinicSystemNewID);
		}
		
		/*Searching for the Position of the Entered Patient ID and Save its address in a variable*/
		Local_PStructWantedPatient = LinkedList_ID_Search(Local_uint8ClinicSystemNewID);
		
		
		/************************************************** Checking if the Entered ID is Reserved a Slot before or not ********************************************/
		
		 for(Local_uint8ClinicSystemIDLoopCounter = 1; Local_uint8ClinicSystemIDLoopCounter <= CLINIC_SYSTEM_SLOTS_NUM ;Local_uint8ClinicSystemIDLoopCounter++)
		 {
			if(Local_PStructWantedPatient -> uint8patientID == ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemIDLoopCounter-1].ClinicSystem_uint8SlotID)
			{
				/*Firing a Flag that the Entered ID is already Reserved a Slot before*/
				 Local_uint8ClinicSystemIDTimeSlotsExistance = ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemIDLoopCounter-1].ClinicSystem_uint8SlotTime;
			}
		 }
		
		/************************************************************************************************************************************************************/
		
		
		if(ClinicSystem_ID_NOT_EXIST == Local_uint8ClinicSystemIDTimeSlotsExistance)
		{
			/*The Entered ID is not Reserved a Slot before and Reserve for it a Slot*/
			 ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemSlotSelected-1].ClinicSystem_uint8SlotID = Local_PStructWantedPatient -> uint8patientID;
			/*Changing the status of that Slot to Reserved*/
			 ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemSlotSelected-1].ClinicSystem_uint8Reservation = CLINIC_SYSTEM_RESERVED;
			 
			/*Print a Confirmation message that the Slot Reserved*/
			 printf("Slot Reserved Successfully\n");
		}
		else
		{
			/*The Entered ID is already Reserved a Slot before and Print a message by that*/
			 printf("The ID You Entered is already Reserved in Slot %d\n",Local_uint8ClinicSystemIDTimeSlotsExistance);
		}
	 }
	 else
	 {
		/*MISRA*/
	 }
	 
	/*Reset the Value of Variable as a Flag to the Avaliable Slot Time List if it is Empty or not */
	 LocalClinicSystemAvaliableTimeSlots = CLINIC_SYSTEM_TIME_SLOTS_EMPTY;
 } 
	
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminCancelReservationTimeSlot																  *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Cancel a Reservation with The Doctor           	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminCancelReservationTimeSlot()	
 {
	/*Loop Counter of the Searching for loop that the ID is Existing in the Reservation List or not*/
	 uint8 Local_uint8ClinicSystemIDLoopCounter = 0;
	/*Variable as a Flag to know if the ID is Existing in the Reservation List or not and storing its position*/
	 uint8 Local_uint8ClinicSystemIDTimeSlotsPosition = ClinicSystem_ID_NOT_EXIST;
	/*Variable to Store the Scanned ID from the Admin*/
	 uint8 Local_uint8ClinicSystemDeletedID = 0;
	
	/*Printing a message to the admin to enter the Pateint ID*/
	 printf("Please Enter Patient ID Needed to Cancel its Reservation :");
	/*Scaning from the Admin the ID of the Patient*/
	 scanf("%d",&Local_uint8ClinicSystemDeletedID);
	
	
	/**************************************** Checking if the Entered ID is Existing in the Reservation List or not *********************************************/
	
	 for(Local_uint8ClinicSystemIDLoopCounter = 1; Local_uint8ClinicSystemIDLoopCounter <= CLINIC_SYSTEM_SLOTS_NUM ;Local_uint8ClinicSystemIDLoopCounter++)
	 {
		if(Local_uint8ClinicSystemDeletedID == ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemIDLoopCounter-1].ClinicSystem_uint8SlotID)
		{
			/*Firing a Flag that the Entered ID is Existing in the Reservation List and Store its Position*/
			 Local_uint8ClinicSystemIDTimeSlotsPosition = Local_uint8ClinicSystemIDLoopCounter;
		}
	 }
	
	/************************************************************************************************************************************************************/
	
	
	if(ClinicSystem_ID_NOT_EXIST != Local_uint8ClinicSystemIDTimeSlotsPosition)
	{
		/*The Entered ID is Existing in the Reservation List and Cancel its Reservation*/
		 ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemIDTimeSlotsPosition-1].ClinicSystem_uint8SlotID = CLINIC_SYSTEM_NO_ID;
		 /*Changing the status of that Slot to NOT Reserved*/
		 ClinicSystem_ArrayStructSlotsTimeSchedule[Local_uint8ClinicSystemIDTimeSlotsPosition-1].ClinicSystem_uint8Reservation = CLINIC_SYSTEM_NOT_RESERVED;
		 printf("Slot Reservation Canceled Successfully.\n");
	}
	else
	{
		/*The Entered ID is not Existing in the Reservation List and Print a message by that*/
		 printf("Sorry This ID is not Reserved any Slot.\n");
	}
	
 }
	
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminDeletePatientRecord																	      *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Delete a Patient Record				           	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminDeletePatientRecord()	
 {
	/*Variable to Store the Scanned ID from the Admin*/ 
	 uint8  Local_uint8ClinicSystemDeletedID = 0;

	/*Printing a message to the admin to enter the Pateint ID*/
	 printf("Please Enter Patient ID you want to delete it : ");
	/*Scaning from the Admin the ID of the Patient*/
	 scanf("%d",&Local_uint8ClinicSystemDeletedID);

	/*Calling Function To Delete The Patient Record*/
	 LinkedList_DeleteNode(Local_uint8ClinicSystemDeletedID);

 } 

 
/*************************************************************************************************************************************************************/
/***************************************************** User Mode Functions Defintion *************************************************************************/
/*************************************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidUserViewPatientRecord																          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To View a Specific Patient Records  			          	     							              *
**************************************************************************************************************************************/
 void ClinicSystem_VoidUserViewPatientRecord()	
 {
	/*Variable to Store the Address of the Needed To view Patient*/
	 Node * ClinicSystem_PStructPatientRecordNeeded = NULL;
	/*Variable to Store the Scanned ID from the Admin*/ 
	 uint8  Local_uint8ClinicSystemDeletedID = 0;

	/*Printing a message to the admin to enter the Pateint ID*/
	 printf("Please Enter Patient ID you want to View it :");
	/*Scaning from the Admin the ID of the Patient*/
	 scanf("%d",&Local_uint8ClinicSystemDeletedID);

	 
	/*Storing the Address of the Needed To view Patient in a variable*/
	 ClinicSystem_PStructPatientRecordNeeded = LinkedList_ID_Search(Local_uint8ClinicSystemDeletedID);
	
	/*Checking if the ID Entered Found or not*/
	 if(ClinicSystem_PStructPatientRecordNeeded != ClinicSystem_ID_NOT_EXIST)
	 {
		/****************************************************** Printing The Specific Patient Records ***********************************************************/ 
		
		/*Printing a Header*/
		 printf("|************************************** PATIENT RECORDS ****************************************|\n");
		/*Printing Patient ID*/
		 printf("Patient ID           : %d\n"  ,ClinicSystem_PStructPatientRecordNeeded->uint8patientID);
		/*Printing Patient First Name*/
		 printf("Patient Name         : ");
		 LinkedList_StringPrint(ClinicSystem_PStructPatientRecordNeeded -> uint8patientFirstName);
		/*Printing Patient Last Name*/
		 printf(" ");
		 LinkedList_StringPrint(ClinicSystem_PStructPatientRecordNeeded -> uint8patientSecondName);
		 printf("\n");
		/*Printing Patient Age*/
		 printf("Patient Age          : %d\n"  ,ClinicSystem_PStructPatientRecordNeeded->uint8patientAge);
		 /*Printing Patient Gender*/
		 printf("Patient Gender       : %c\n"  ,ClinicSystem_PStructPatientRecordNeeded->uint8patientGender);
		/*Closing The Header*/
		 printf("|***********************************************************************************************|\n");
		 
		/********************************************************************************************************************************************************/
	 }
	 else
	 {
		/*The Entered ID is not Existing in the List and Print a message by that*/
		 printf("Sorry The ID you Entered is not Exist.\n");
	 }
 } 
 
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidUserViewTodayReservation																     	  *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To View Today's Reservations  			          	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidUserViewTodayReservation()	
 {
	/************************************************************ Printing Today's Reservations *****************************************************************/ 
	 
	 printf("|************************************ Today's Reservation **************************************|\n");
	 
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_00_PM__2_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED)
	 {
	 	printf("\r|From 2:00 to 2:30 Slot Reserveed to Patient ID %d                                               |\n",\
	 	ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_00_PM__2_30_PM-1].ClinicSystem_uint8SlotID);
	 }
	 else
	 {
	 	printf("\r|From 2:00 to 2:30 Slot is Empty                                                                |\n");
	 }
	 
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_30_PM__3_00_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED)
	 {
	 	printf("\r|From 2:30 to 3:00 Slot Reserveed to Patient ID %d                                               |\n",\
	 	ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_2_30_PM__3_00_PM-1].ClinicSystem_uint8SlotID);
	 }
	 else
	 {
	 	printf("\r|From 2:30 to 3:00 Slot is Empty                                                                |\n");
	 }
	 
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_3_00_PM__3_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED)
	 {
	 	printf("\r|From 3:00 to 3:30 Slot Reserveed to Patient ID %d                                               |\n",\
	 	ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_3_00_PM__3_30_PM-1].ClinicSystem_uint8SlotID);
	 }
	 else
	 {
	 	printf("\r|From 3:00 to 3:30 Slot is Empty                                                                |\n");
	 }
	 
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_00_PM__4_30_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED)
	 {
	 	printf("\r|From 4:00 to 4:30 Slot Reserveed to Patient ID %d                                               |\n",\
	 	ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_00_PM__4_30_PM-1].ClinicSystem_uint8SlotID);
	 }
	 else
	 {
	 	printf("\r|From 4:00 to 4:30 Slot is Empty                                                                |\n");
	 }
	 
	 if(ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_30_PM__5_00_PM-1].ClinicSystem_uint8Reservation == CLINIC_SYSTEM_RESERVED)
	 {
	 	printf("\r|From 4:30 to 5:00 Slot Reserveed to Patient ID %d                                               |\n",\
	 	ClinicSystem_ArrayStructSlotsTimeSchedule[CLINIC_SYSTEM_SLOT_4_30_PM__5_00_PM-1].ClinicSystem_uint8SlotID);
	 }
	 else
	 {
	 	printf("\r|From 4:30 to 5:00 Slot is Empty                                                                |\n");
	 }
	 
	 
	 printf("|***********************************************************************************************|\n");
	 
	/********************************************************************************************************************************************************/
 }
 
 
 
 
 