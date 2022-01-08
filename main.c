/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						24 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Clinic System                                                       							                      *
* ! File Name	: main.c                                                       								                          *
* ! Description : This file has the implementation of main function of the Clinic system        					                  *
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
uint8 Global_uint8ClinicSystemMode 		   = 0;									//Variable To Store the Mode of the system.
uint8 Global_uint8ClinicSystemModes_ON_OFF = 0;									//Variable To Store the Mode of the system.
uint8 Global_uint8ClinicSystemAdminOption  = 0;									//Variable To Store The Option Entered By the Admin.
uint8 Global_uint8ClinicSystemUserOption   = 0;									//Variable To Store The Option Entered By the Admin.

/***************************************************** Extern Variables **************************************************************/
extern uint8 Global_uint8ClinicPasswordCheck;								 	//Variable To Store That The Admin Password is Valid.

/******************************************************* Main Function ***************************************************************/
void main(void)
{
	while(1)
	{
		/*Printing an interface to the user to Choose the system mode*/
		printf("|**************************************** Clinic System ****************************************|\n\
			  \r|Please Enter (1) For Admin Mode				                                |\n\
			  \r|Please Enter (2) For User Mode					                                |\n\
			  \r|***********************************************************************************************|\n");
		
		/*Scaning from the user the system mode*/
		scanf("%d",&Global_uint8ClinicSystemMode);
		
		/*Switching on the entered mode*/
		switch(Global_uint8ClinicSystemMode)
		{	
			/******************************************************************************************************************************/
			/**************************************************** ADMIN MODE **************************************************************/
			/******************************************************************************************************************************/
			 case CLINIC_SYSTEM_ADMIN_MODE:
				
				/*Checking the Validity of the Password*/
				 ClinicSystem_VoidAdminPasswordCheck();
				/*Checking from the Global Variable that the Password checking is done successfully*/
				 if(CLINIC_SYSTEM_VALID_PASSWORD == Global_uint8ClinicPasswordCheck)
				 {
					/*Admin mode Activated*/
					 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
					/*Admin mode Activated till the Admin Press Exit from the options*/
					 while(CLINIC_SYSTEM_ADMIN_MODE_ON == Global_uint8ClinicSystemModes_ON_OFF)
					 {
						/*Printing an interface to the Admin to Choose An Option*/
						 printf("|************************************ Welcome In Admin Mode **************************************|\n\
							   \r|Please Enter (1) To Add new patient record.                                                      |\n\
							   \r|Please Enter (2) To Edit patient record.                                                         |\n\
							   \r|Please Enter (3) To Reserve a slot with the doctor.                                              |\n\
							   \r|Please Enter (4) To Cancel reservation.                                                          |\n\
							   \r|Please Enter (5) To View All Patient Records.                                                    |\n\
							   \r|Please Enter (6) To Delete Specific Patient Record.                                              |\n\
							   \r|Please Enter (7) To Exit from Admin Mode.                                                        |\n\
							   \r|*************************************************************************************************|\n");
						
						
						/*Scaning the option Entered by the Admin*/
						 scanf("%d",&Global_uint8ClinicSystemAdminOption);
						/*Scaning the option Entered by the Admin while it is invalid*/
						 while(Global_uint8ClinicSystemAdminOption > CLINIC_SYSTEM_ADMIN_OPTIONS_NUM)
						 {
							/*Printing a message to the Admin to Reenter the option he want*/
							 printf("Please Enter a valid Option : ");
							
							/*Rescaning the Option from the Admin*/
							 scanf("%d",&Global_uint8ClinicSystemAdminOption);
						 }
						
						
						/*Switching on the Option Entered by the Admin*/
						 switch(Global_uint8ClinicSystemAdminOption)
						 {
							/******************************** CLINIC_SYSTEM_ADD_NEW_PATIENT_RECORD ***************************************/
							
							 case CLINIC_SYSTEM_ADD_NEW_PATIENT_RECORD:
							
									/*Calling the Function to add a new Pateint record*/
									ClinicSystem_VoidAdminAddNewPatientRecord();
									
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							 break;
							
							/********************************* CLINIC_SYSTEM_EDIT_PATIENT_RECORD ****************************************/
							
							 case CLINIC_SYSTEM_EDIT_PATIENT_RECORD:
							
									/*Calling the Function to Edit a Pateint record*/
									 ClinicSystem_VoidAdminEditPatientRecord();
							
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							 break;
							
							/****************************** CLINIC_SYSTEM_RESERVE_SLOT_WITH_DOCTOR **************************************/
							
							case CLINIC_SYSTEM_RESERVE_SLOT_WITH_DOCTOR:
							
									/*Calling the Function to Reserve a slot with the Doctor*/
									 ClinicSystem_VoidAdminReserveTimeSlot();
									
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							break;
							
							/********************************* CLINIC_SYSTEM_CANCEL_RESERVATION *****************************************/
							
							case CLINIC_SYSTEM_CANCEL_RESERVATION:
							
									/*Calling the Function to cancel a Reservation with the Doctor*/
									 ClinicSystem_VoidAdminCancelReservationTimeSlot();
									
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							break;
							
							/********************************** CLINIC_SYSTEM_VIEW_ALL_RECORDS ******************************************/
							
							case CLINIC_SYSTEM_VIEW_ALL_RECORDS:
							
									/*Calling the Function to Print All Records*/
									 LinkedList_Traverse();
									
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							break;
							
							/******************************** CLINIC_SYSTEM_DELETE_PATEINT_RECORD ****************************************/
							
							case CLINIC_SYSTEM_DELETE_PATEINT_RECORD:
							
									/*Calling The Function To Delete a Patient Record*/
									 ClinicSystem_VoidAdminDeletePatientRecord();
									
									/*Refreshing the Activation of the Admin Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_ON;
							break;
							
							/*********************************** CLINIC_SYSTEM_EXIT_ADMIN_MODE *******************************************/
							
							case CLINIC_SYSTEM_EXIT_ADMIN_MODE:
								
									/*Deactivate the Admin Mode*/
									Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_ADMIN_MODE_OFF;
							break;
							
							/************************************************************************************************************/
						 }
					 }
				 }
				 else
				 {
					/*Printing an Error message that the password Entring Trials Ran out*/	
					 printf("Sorry, You Used all the Trials. \n");
				 }
			
			 break;
			
			
			/******************************************************************************************************************************/
			/***************************************************** USER MODE **************************************************************/
			/******************************************************************************************************************************/
			 case CLINIC_SYSTEM_USER_MODE:
					
					/*Activate User Mode*/
					 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_USER_MODE_ON;
					/*User mode Activated till the User Press Exit from the options*/
					 while(CLINIC_SYSTEM_USER_MODE_ON == Global_uint8ClinicSystemModes_ON_OFF)
					 {
						/*Printing an interface to the User to Choose An Option*/
						 printf("|*********************************** Welcome In User Mode **************************************|\n\
							   \r|Please Enter (1) To View patient record.                                                       |\n\
							   \r|Please Enter (2) To View today\'s reservations.                                                 |\n\
							   \r|Please Enter (3) To Exit from User Mode.                                                       |\n\
							   \r|***********************************************************************************************|\n");
						
						/*Scaning the option Entered by the User*/
						 scanf("%d",&Global_uint8ClinicSystemUserOption);
						/*Scaning the option Entered by the User while it is invalid*/
						 while(Global_uint8ClinicSystemUserOption > CLINIC_SYSTEM_USER_OPTIONS_NUM)
						 {
							/*Printing a message to the User to Reenter the option he want*/
							 printf("Please Enter a valid Option : ");
							 
							/*Rescaning the Option from the User*/
							 scanf("%d",&Global_uint8ClinicSystemUserOption);
						 }
						
						
						/*Switching on the Option Entered by the User*/
						 switch(Global_uint8ClinicSystemUserOption)
						 {
							/********************************* CLINIC_SYSTEM_VIEW_PATIENT_RECORD *****************************************/
							
							case CLINIC_SYSTEM_VIEW_PATIENT_RECORD:
							
									/*Calling Function to View a patient Record*/
									 ClinicSystem_VoidUserViewPatientRecord();
									
									/*Refreshing the Activation of the User Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_USER_MODE_ON;
							break;
							
							/******************************* CLINIC_SYSTEM_VIEW_TODAY_RESERVATIONS **************************************/
							
							case CLINIC_SYSTEM_VIEW_TODAY_RESERVATIONS:
							
									/*Calling Function to View Today's Reservation*/
									 ClinicSystem_VoidUserViewTodayReservation();
									
									/*Refreshing the Activation of the User Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_USER_MODE_ON;
							break;
							
							/*********************************** CLINIC_SYSTEM_EXIT_USER_MODE *******************************************/
							
							case CLINIC_SYSTEM_EXIT_USER_MODE:
								
									/*Deactivate the User Mode*/
									 Global_uint8ClinicSystemModes_ON_OFF = CLINIC_SYSTEM_USER_MODE_OFF;
							break;
							
							/************************************************************************************************************/
						 }
					 }
			 break;
			
			 default:
			
					/*Printing an Error Message that the input is invalid*/
					 printf("Sorry,Please Enter a valid choice.\n\n");
				
			 break;
			
		 }
	 }
 }