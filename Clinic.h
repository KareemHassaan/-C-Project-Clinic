/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						24 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Clinic System                                                        							                      *
* ! File Name	: Clinic.h                                               		      							                      *
* ! Description : This file has the Clinic definitions needed				       							                          *
* ! Compiler  	: GNU GCC Native Compiler                                            							                      *
* ! Target 	  	: Windows 10                                         							                      				  *
**************************************************************************************************************************************/
#ifndef CLINIC_H
#define CLINIC_H

/*************************************************************** System Modes Macros **************************************************************************/

#define CLINIC_SYSTEM_ADMIN_MODE 						1														//Admin Mode Option.
#define CLINIC_SYSTEM_USER_MODE  						2														//User Mode Option.

#define CLINIC_SYSTEM_ADMIN_MODE_ON 					1														//Admin Mode ON.
#define CLINIC_SYSTEM_ADMIN_MODE_OFF					2														//Admin Mode OFF.
#define CLINIC_SYSTEM_USER_MODE_ON  					3														//User Mode ON.
#define CLINIC_SYSTEM_USER_MODE_OFF 					4														//User Mode OFF.

/*************************************************************** Admin Password Macros ************************************************************************/

#define CLINIC_SYSTEM_MAX_PASSWORD_TRIALS  				3   													//Admin Password Entering Maximum trials.
#define CLINIC_SYSTEM_ADMIN_PASSWORD  					1234													//Admin Password value.
#define CLINIC_SYSTEM_VALID_PASSWORD	 				1   													//Comparator of the Password Validity.

/************************************************************* Admin Mode Options Macros **********************************************************************/

#define CLINIC_SYSTEM_ADMIN_OPTIONS_NUM 				7														//Number of the Admin Options Avaliable.

#define	CLINIC_SYSTEM_ADD_NEW_PATIENT_RECORD			1														//Add new patient record Option.
#define	CLINIC_SYSTEM_EDIT_PATIENT_RECORD				2														//Edit patient record Option.
#define	CLINIC_SYSTEM_RESERVE_SLOT_WITH_DOCTOR			3														//Reserve slot with doctor Option.
#define CLINIC_SYSTEM_CANCEL_RESERVATION				4														//Cancel reservation Option.
#define CLINIC_SYSTEM_VIEW_ALL_RECORDS					5														//View all records Option.
#define CLINIC_SYSTEM_DELETE_PATEINT_RECORD				6														//Delete pateint record	Option.
#define CLINIC_SYSTEM_EXIT_ADMIN_MODE					7														//Exit admin mode Option.

/************************************************************ Admin Editing Function Macros *******************************************************************/

#define CLINIC_SYSTEM_EDIT_PATIENT_ID					1														//Patient ID Option to Edit.			
#define CLINIC_SYSTEM_EDIT_PATIENT_FIRSTNAME			2														//Patient First Name Option to Edit.
#define CLINIC_SYSTEM_EDIT_PATIENT_SECONDNAME			3														//Patient Second Name Option to Edit.
#define CLINIC_SYSTEM_EDIT_PATIENT_AGE					4														//Patient Age Option to Edit.
#define CLINIC_SYSTEM_EDIT_PATIENT_GENDER				5														//Patient Gender Option to Edit.
#define CLINIC_SYSTEM_EDIT_ALL_RECORDS					6														//Patient All Records Option to Edit.

/*********************************************************** Admin Reserving Function Macros ******************************************************************/

#define CLINIC_SYSTEM_NOT_RESERVED						0														//Time Slot is Not Reserverd.
#define CLINIC_SYSTEM_RESERVED							1														//Time Slot is Reserverd.
#define CLINIC_SYSTEM_NO_ID 							0														//Comparator with the ID Not Exist.

#define CLINIC_SYSTEM_SLOTS_NUM          				5														//Number of Time Slot avaliable.
#define CLINIC_SYSTEM_TIME_SLOTS_EMPTY          		0														//Comparator with the Time Slot avaliable is Empty.

#define CLINIC_SYSTEM_SLOT_2_00_PM__2_30_PM				1														//Time Slot From 2:00 PM To 2:30 PM.
#define CLINIC_SYSTEM_SLOT_2_30_PM__3_00_PM				2														//Time Slot From 2:30 PM To 3:00 PM.
#define CLINIC_SYSTEM_SLOT_3_00_PM__3_30_PM				3														//Time Slot From 3:00 PM To 3:30 PM.
#define CLINIC_SYSTEM_SLOT_4_00_PM__4_30_PM				4														//Time Slot From 4:00 PM To 4:30 PM.
#define CLINIC_SYSTEM_SLOT_4_30_PM__5_00_PM				5														//Time Slot From 4:30 PM To 5:00 PM.

/*Struct Represent a Time Slot*/
typedef struct slot
{
	uint8 ClinicSystem_uint8SlotTime;
	uint8 ClinicSystem_uint8SlotID;
	uint8 ClinicSystem_uint8Reservation;
}Slot;

/*Assignation Macro of the Array of struct that Represent the Schedule of the Clinic and Avaliable Time Slots  */
#define CLINIC_SYSTEM_TIME_SLOTS_SCHEDULE  	{{CLINIC_SYSTEM_SLOT_2_00_PM__2_30_PM, CLINIC_SYSTEM_NO_ID, CLINIC_SYSTEM_NOT_RESERVED},\
											 {CLINIC_SYSTEM_SLOT_2_30_PM__3_00_PM, CLINIC_SYSTEM_NO_ID, CLINIC_SYSTEM_NOT_RESERVED},\
											 {CLINIC_SYSTEM_SLOT_3_00_PM__3_30_PM, CLINIC_SYSTEM_NO_ID, CLINIC_SYSTEM_NOT_RESERVED},\
											 {CLINIC_SYSTEM_SLOT_4_00_PM__4_30_PM, CLINIC_SYSTEM_NO_ID, CLINIC_SYSTEM_NOT_RESERVED},\
											 {CLINIC_SYSTEM_SLOT_4_30_PM__5_00_PM, CLINIC_SYSTEM_NO_ID, CLINIC_SYSTEM_NOT_RESERVED}};
											 
/********************************************************* User Mode Options Macros ***************************************************************************/

#define CLINIC_SYSTEM_USER_OPTIONS_NUM 					3														//Number of the User Options Avaliable.

#define	CLINIC_SYSTEM_VIEW_PATIENT_RECORD				1														//VIEW_PATIENT_RECORD Option.
#define	CLINIC_SYSTEM_VIEW_TODAY_RESERVATIONS			2														//VIEW_TODAY_RESERVATIONS Option.
#define CLINIC_SYSTEM_EXIT_USER_MODE					3														//EXIT_USER_MODE Option.

/**************************************************************************************************************************************************************/
/***************************************************** Admin Mode Functions Prototype *************************************************************************/
/**************************************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminPasswordCheck																	          *
* Parameters (in)	: None						                      																  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To check the Validity of the Password of the Admin								                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminPasswordCheck();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAddNewPatientRecord																	          *
* Parameters (in)	: uint8 Copy_uint8PatientID						                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Add New Patient Record in the List                							                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminAddNewPatientRecord();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAddNewPatientRecord																	          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Edit a Patient Record in the List               	 							                      *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminEditPatientRecord();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidReserveTimeSlot																		          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Reserve a New Time Slot with The Doctor                							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminReserveTimeSlot();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminCancelReservationTimeSlot																  *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Cancel a Reservation with The Doctor           	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminCancelReservationTimeSlot();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidAdminDeletePatientRecord																	      *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Delete a Patient Record				           	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidAdminDeletePatientRecord();

/**************************************************************************************************************************************************************/
/***************************************************** User Mode Functions Prototype **************************************************************************/
/**************************************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidUserViewPatientRecord																          *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To View a Specific Patient Records  			          	     							              *
**************************************************************************************************************************************/
 void ClinicSystem_VoidUserViewPatientRecord();
/**************************************************************************************************************************************
* Function Name		: ClinicSystem_VoidUserViewTodayReservation																     	  *
* Parameters (in)	: None											                      											  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To View Today's Reservations  			          	     							                  *
**************************************************************************************************************************************/
 void ClinicSystem_VoidUserViewTodayReservation();	

#endif /*CLINIC_H*/