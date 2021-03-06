
/*************************************************************
* Copyright 2007-2008 Jovian Advanced Control Technology, Co.
* 
*  FileName:        
*  Abstract:         debug Task
*                   
*
*  Current Version: 
*  Writer:          
*  Date:           
*---------------------------------------------------------------
* Modification history:
* Date: 
* Version:
* Description:
*
****************************************************************/


#include "board.h"
#include "debugTask.h"
#include "uartdriver.h"

DebugTask  *DebugTask::_pDebugTask = (DebugTask  *)0 ;

/***************THE LOCAL VARIABLES ***************************/


DebugTask::DebugTask(){
	
}

DebugTask::~DebugTask(){
}


DebugTask*  DebugTask::GetInstance()
{
    if(  (DebugTask  *)0== _pDebugTask )
    {
        _pDebugTask = new DebugTask();
    }
    return  _pDebugTask;
}


/*
@brief  :
@param  :
@retval :
@note   :
*/
void DebugTask::Initiliaze()
{
		debug_link  = new CUartDriver(USART1_IDX);
}

/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/
void DebugTask::Run()
{
    _bRun       = true;
    OSTaskCreateExt((void (*)(void *)) DebugLoop,
                             (void          * ) 0,
                             (OS_STK        * )&App_DebugTask1Stack[APP_DebugTASK1_STK_SIZE - 1],
                             (uint8_t         ) APP_DebugTASK1_PRIO,
                             (uint16_t        ) APP_DebugTASK1_PRIO,
                             (OS_STK        * )&App_DebugTask1Stack[0],
                             (INT32U          ) APP_DebugTASK1_STK_SIZE,
                             (void          * )0,
                             (uint16_t        )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
														 
//		OSTaskCreateExt((void (*)(void *)) IMUTask ,
//                             (void          * ) 0,
//                             (OS_STK        * )&App_DebugTask2Stack[APP_DebugTASK2_STK_SIZE - 1],
//                             (uint8_t         ) APP_DebugTASK2_PRIO,
//                             (uint16_t        ) APP_DebugTASK2_PRIO,
//                             (OS_STK        * )&App_DebugTask2Stack[0],
//                             (INT32U          ) APP_DebugTASK2_STK_SIZE,
//                             (void          * )0,
//                             (uint16_t        )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));

//    OSTaskCreateExt((void (*)(void *)) SendMsgTask ,
//                             (void          * ) 0,
//                             (OS_STK        * )&App_DebugTask3Stack[APP_DebugTASK3_STK_SIZE - 1],
//                             (uint8_t         ) APP_DebugTASK3_PRIO,
//                             (uint16_t        ) APP_DebugTASK3_PRIO,
//                             (OS_STK        * )&App_DebugTask3Stack[0],
//                             (INT32U          ) APP_DebugTASK3_STK_SIZE,
//                             (void          * )0,
//                             (uint16_t        )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
														 
}

/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/
void DebugTask::DebugLoop(void){
	 if( !_pDebugTask->_bRun )
    {
        OSTaskSuspend(OS_PRIO_SELF);
    }
		#ifdef DEBUG_ON
		OS_STK_DATA StackBytes;
		#endif
		while(1){
			#ifdef DEBUG_ON
			OSTaskStkChk(APP_TASK_START_PRIO, &StackBytes);
			PRINT("mainTask TX: OSFree=%6d OSUsed=%6d\r\n",StackBytes.OSFree,StackBytes.OSUsed);
			
			OSTaskStkChk(APP_TASK_UBLOX_PRIO, &StackBytes);
			PRINT("ubloxTask: OSFree=%6d OSUsed=%6d\r\n",StackBytes.OSFree,StackBytes.OSUsed);
			
			OSTaskStkChk(APP_TASK_SERVER_RX_PRIO, &StackBytes);
			PRINT("ucloudTask RX: OSFree=%6d OSUsed=%6d\r\n",StackBytes.OSFree,StackBytes.OSUsed);
			OSTaskStkChk(APP_TASK_SERVER_TX_PRIO, &StackBytes);
			PRINT("ucloudTask TX: OSFree=%6d OSUsed=%6d\r\n",StackBytes.OSFree,StackBytes.OSUsed);
			#endif
			
			OSTimeDly(1000);
			
			LED0_TOGGLE;
		}
		
    //OSTimeDly(300);

}

/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/
void DebugTask::BurstPacket(void){
		
}



/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/
int DebugTask::RecvMsg(){
	return 1;
}

/*
@brief  : AutoPilot Communication Manager
@param  : a packag of COMMPACKET_t
@retval : the length of  byte sent
@NOTE   : NONE
*/
int DebugTask::SendMsg()
{
	return 1;
}/* end of SendMsg */



/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/

void DebugTask::SendMsgTask(void){
	while(1){
		_pDebugTask->SendDaemon();
		OSTimeDly(10);
	}
}


void DebugTask::ReceLoop(void)
{
	if( !_bRun )
    {
        OSTaskSuspend(OS_PRIO_SELF);
    }
    //OSTimeDly(300);
	while (1)
	{

	}/* end of while */
}


/*
@brief  : the Send Package Data Daemon function
@param  : NONE
@retval : NONE
@note   : this method must be invoked by a independent task , the task will  be responsible for sending data
*/
void DebugTask::SendDaemon()
{
	
	OSTimeDly(10);
//	UINT8 *taskBuffer;

//	while (1)
//	{
//    	if(debug_link->ready())
//    	{
//				 taskBuffer = (UINT8 *)OSQPend(m_pQSem, 0,&g_u8Rerr);
//    		 debug_link->write((UINT8*)(taskBuffer+2),taskBuffer[1]);
//			   if(taskBuffer[0])
//         {
//			     free(taskBuffer);
//         }
//    	}
//		else
//		{
//		      OSTimeDly(10);
//		}
//	}/* end of while */

}/*end of SendDaemon */


/*
@brief  :
@param  : NONE
@retval : NONE
@note   :
*/
void DebugTask::IMUTask(void){
	while(1){
		//VISCA_set_address(&iface, &camera_num);
//		USART2_send_byte(0x66); 
//		OSTimeDly(10);
			
		OSTimeDly(1000);
	}
	
}


/* end of file */


