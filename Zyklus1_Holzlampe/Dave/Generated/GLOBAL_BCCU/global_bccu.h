/**
 * @file global_bccu.h
 * @date 2016-07-15
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * GLOBAL_BCCU v4.1.6 - GLOBAL_BCCU APP configures the global registers of the Brightness and Color Control Unit (BCCU).
 *                      The configured parameters are clock frequencies, trap functionality, triggering, channel
 *                      passive levels and interrupts. The APP provides dynamic APIs to high level APPs such as
 *                      event flag configuration, interrupt configuration and trap configuration.It also provides
 *                      dynamic APIs to high level APPs such as DALI_CG and LED_LAMP.
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16
 *     - Initial version.<br>
 *
 * 2015-04-01
 *     - Return type of GLOBAL_BCCU_GetTrapState() is corrected.<br>
 *     - All API's code snippet are modified according to code review feedbacks.<br>
 *     - Trap edge configuration is added in GLOBAL_BCCU_t data structure.<br>
 *     - XMC_ASSERT is added for static inline functions.<br>
 *
 * 2015-06-20
 *     - Version check added for XMCLib dependency.<br>
 *
 * @endcond
 *
 */

#ifndef GLOBAL_BCCU_H
#define GLOBAL_BCCU_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include <xmc_bccu.h>
#include <DAVE_common.h>
#include "global_bccu_conf.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
#if (!((XMC_LIB_MAJOR_VERSION == 2U) && \
       (XMC_LIB_MINOR_VERSION >= 0U) && \
       (XMC_LIB_PATCH_VERSION >= 0U)))
#error "GLOBAL_BCCU requires XMC Peripheral Library v2.0.0 or higher"
#endif

/**********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/

/**
* @ingroup GLOBAL_BCCU_enumerations
* @{
*/

/**
* @brief Defines status of GLOBAL_BCCU
*/
typedef enum GLOBAL_BCCU_STATUS
{
  GLOBAL_BCCU_STATUS_SUCCESS = 0U, /**< Status Success if initialization is successful */
  GLOBAL_BCCU_STATUS_FAILURE,     /**< Status Failure if initialization is failed */
} GLOBAL_BCCU_STATUS_t;
/**
* @}
*/

/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/

/**
* @ingroup GLOBAL_BCCU_datastructures
* @{
*/

/**
* @brief Defines the APP configuration parameters
*/
typedef struct GLOBAL_BCCU
{
  BCCU_Type *const bccuregs; /**< BCCU Global Register Pointer */
  const XMC_BCCU_GLOBAL_CONFIG_t *const config; /**< Global configuration Structure Pointer */
  uint32_t enable_events; /**< BCCU interrupt configuration */
  XMC_BCCU_CH_TRAP_IN_t trap_source; /**< Trap input source for mux configuration*/
  XMC_BCCU_CH_TRAP_EDGE_t trap_edge; /**< Trap input  edge type for mux configuration*/
  bool init_status; /**< APP initialization status  */
} GLOBAL_BCCU_t;

/**
* @}
*/

/***********************************************************************************************************************
 * API Prototypes
 **********************************************************************************************************************/

/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif

  /**
* @ingroup GLOBAL_BCCU_apidoc
* @{
*/

  /**
* @brief Get GLOBAL_BCCU APP version
* @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
*
* \par<b>Description: </b><br>
* The function can be used to check application software compatibility with a
* specific version of the APP.
*
* \par<b>Example Usage:</b><br>
*
* @code
* #include <DAVE.h>
*
* int main(void) {
*   DAVE_STATUS_t init_status;
*   DAVE_APP_VERSION_t version;
*
*   // Initialize GLOBAL_BCCU APP:
*   // GLOBAL_BCCU_Init() is called from within DAVE_Init().
*   init_status = DAVE_Init();
*
*   version = GLOBAL_BCCU_GetAppVersion();
*   if (version.major != 4U) {
*     // Probably, not the right version.
*   }
*
*   // More code here
*   while(1) {
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

DAVE_APP_VERSION_t GLOBAL_BCCU_GetAppVersion(void);

 /**
* @brief Initializes a GLOBAL_BCCU APP instance based on user configuration.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return GLOBAL_BCCU_STATUS_t APP status. Refer @ref GLOBAL_BCCU_STATUS_t for details.
*
* \par<b>Description:</b><br>
* Configures Trap input source and initializes the global resources of a BCCU module.
*
* \par<b>Related APIs:</b><BR>
* None
*
* \par<b>Example Usage:</b><br>
*
* @code
* #include <DAVE.h>
*  int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_SUCCESS)
*   {
*     // Add application code here
*     while(1U)
*     {
*     }
*   }
*   else
*   {
*     XMC_DEBUG("main: Application initialization failed");
*     while(1U)
*     {
*     }
*   }
*   return (1);
*  }
* @endcode<BR>
*/

GLOBAL_BCCU_STATUS_t GLOBAL_BCCU_Init(GLOBAL_BCCU_t *handle);

/**
* @brief Configures Global Dimming Level.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param level Global Dimming Level value. Range:0-4095
* @return None
*
* \par<b>Description:</b><br>
* Configures global dimming level by writing to register GLOBDIM. This is useful only if global dimming engine is
* selected.
*
* \par<b>Related APIs:</b><BR>
*  None
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU and 1 DIM_BCCU APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*      XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*      while(1U)
*      {
*      }
*   }
*   PDM_BCCU_EnableChannel(&PDM_BCCU_0); // Enables channel mapped by solver
*   while(1U)
*   {
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,4095);// maximum intensity
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0); // Go to target intensity immediately
*     GLOBAL_BCCU_SetGlobDimLevel(&GLOBAL_BCCU_0,2048);// go to 50% dimming level
*     //Observe 50% Dimming
*   }
*
*   return (1);
* }
* @endcode<BR>
*/
  void GLOBAL_BCCU_SetGlobDimLevel(GLOBAL_BCCU_t *handle, uint32_t level);

  /**
* @brief Configures Dimming Clock Prescaler.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param dimclk_ps Dimmer Clock Prescaler Factor. Range:0-4095
* @return None
*
* \par<b>Description:</b><br>
* Configures the dimmer clock prescaler factor (DCLK_PS) of a BCCU module. The the dimmer clock
* prescaler factor (DCLK_PS) and the dimming clock divider (DIMDIV) control the fade rate during dimming.
*
* \par<b>Related APIs:</b><BR>
* None
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU and 1 DIM_BCCU APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step2: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step3: Make HW signal connection from DIM_BCCU's dimming_level to PDM_BCCU's dimming_level_input.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   PDM_BCCU_EnableChannel(&PDM_BCCU_0); // Enables mapped channel by solver
*   while(1U)
*   {
*     //When dim clock prescaler is maximum it takes time(gradually) to reach target dimming level from 0% to 100%
*     GLOBAL_BCCU_SetDimClkPS(&GLOBAL_BCCU_0,4095);
*     DIM_BCCU_SetDimLvl(&DIM_BCCU_0, 4095);// Set Target Level 100%
*     DIM_BCCU_StartDimming(&DIM_BCCU_0); // Start Dimming
*     DIM_BCCU_AwaitFadeCompletion(&DIM_BCCU_0); // Wait for Completion
*
*     //If dim clock prescaler is minimum,it will reach target dimming level from 100% to 0% faster
*     GLOBAL_BCCU_SetDimClkPS(&GLOBAL_BCCU_0,50);
*     DIM_BCCU_SetDimLvl(&DIM_BCCU_0, 0); // Set Target Level 0%
*     DIM_BCCU_StartDimming(&DIM_BCCU_0); // Start Dimming
*     DIM_BCCU_AwaitFadeCompletion(&DIM_BCCU_0);// Wait for Completion
*   }
*
*   return (1);
* }
* @endcode<BR>
*/

 void GLOBAL_BCCU_SetDimClkPS(GLOBAL_BCCU_t *handle, uint32_t dimclk_ps);
 /**
* @brief Enforces a TRAP by software.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return None
*
* \par<b>Description:</b><br>
* This function activates TRAP which results in all affected channels going to passive level.
*
* \par<b>Description:</b><br>
*  None
*
*\par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU and 1 DIM_BCCU APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
*
* @code
* #include <DAVE.h>
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   PDM_BCCU_EnableChannel(&PDM_BCCU_0); // Enables channel mapped by solver
*   PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,0);
*   PDM_BCCU_SetIntensity(&PDM_BCCU_0,4095); // maximum intensity
*   PDM_BCCU_StartLinearWalk(&PDM_BCCU_0); // Go to target intensity immediately
*   GLOBAL_BCCU_SetDimClkPS(&GLOBAL_BCCU_0,225); // dimmer clock prescaler factor
*   DIM_BCCU_SetDimLvl(&DIM_BCCU_0, 1024); // Set Target Level 12.5%
*   DIM_BCCU_StartDimming(&DIM_BCCU_0); // go to 12.5% now
*   while(1U)
*   {
*    // user software running
*
*    // suddenly something went wrong (e.g. overcurrent detected)
*    GLOBAL_BCCU_ForceTrap(&GLOBAL_BCCU_0);
*   }
*  return (1);
* }
*
* @endcode<BR>
*/

void GLOBAL_BCCU_ForceTrap(GLOBAL_BCCU_t *handle);
/**
* @brief Exits from the Trap State.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return None
*
* \par<b>Description:</b><br>
* Exits from the Trap State.
*
* \par<b>Description:</b><br>
*  None
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Enable TRAP interrupt in GLOBAL_BCCU APP GUI.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step6: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t Trap_trig_flag,Trap_State,Trap_Inpt_Lvl;
* void BCCU_Trap_ISR(void)
* {
*   Trap_trig_flag = 1;
*   Trap_State = GLOBAL_BCCU_GetTrapState(&GLOBAL_BCCU_0);
*   // this determines whether the dangerous external event is still active or not
*   Trap_Inpt_Lvl = GLOBAL_BCCU_GetTrapInputLvl(&GLOBAL_BCCU_0);
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

void GLOBAL_BCCU_ExitTrap(GLOBAL_BCCU_t *handle);
/**
* @brief Checks the current trap state.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return XMC_BCCU_CH_TRAP_EDGE_t Trap state. Refer @ref XMC_BCCU_CH_TRAP_EDGE_t.
*
* \par<b>Description:</b><br>
*  Returns the current trap state.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Enable TRAP interrupt in GLOBAL_BCCU APP GUI.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step6: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t Trap_trig_flag,Trap_State,Trap_Inpt_Lvl;
* void BCCU_Trap_ISR(void)
* {
*   Trap_trig_flag = 1;
*   Trap_State = GLOBAL_BCCU_GetTrapState(&GLOBAL_BCCU_0);
*   // this determines whether the dangerous external event is still active or not
*   Trap_Inpt_Lvl = GLOBAL_BCCU_GetTrapInputLvl(&GLOBAL_BCCU_0);
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init(); //GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

XMC_BCCU_TRAP_STATUS_t GLOBAL_BCCU_GetTrapState(GLOBAL_BCCU_t *handle);
/**
* @brief Get the Trap input level.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return XMC_BCCU_TRAP_LEVEL_t Trap input level. Refer @ref XMC_BCCU_TRAP_LEVEL_t for details.
*
* \par<b>Description:</b><br>
*  Returns the Trap input level.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Enable TRAP interrupt in GLOBAL_BCCU APP GUI.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step6: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t Trap_trig_flag,Trap_State,Trap_Inpt_Lvl;
* void BCCU_Trap_ISR(void)
* {
*   Trap_trig_flag = 1;
*   Trap_State = GLOBAL_BCCU_GetTrapState(&GLOBAL_BCCU_0);
*   // this determines whether the dangerous external event is still active or not
*   Trap_Inpt_Lvl = GLOBAL_BCCU_GetTrapInputLvl(&GLOBAL_BCCU_0);
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init(); //GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

XMC_BCCU_TRAP_LEVEL_t GLOBAL_BCCU_GetTrapInputLvl(GLOBAL_BCCU_t *handle);
/**
* @brief Gets Last Trigger Source.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return uint32_t Channel number
*
* \par<b>Description:</b><br>
* Returns Last Trigger Source, shows which channel generated the last trigger (the value is always 0 in Trigger Mode 0)
*
* \par<b>Example Usage:</b><br>
* @code
* #include <DAVE.h>
*
* uint32_t step,Last_Trigger_Ch,EVFR_Status;
*
* void ADC_RESULT_ISR(void)
* {
*   Last_Trigger_Ch = GLOBAL_BCCU_GetLastTrigSrc(&GLOBAL_BCCU_0);
*   // check whether the last trigger source matches the ADC channel
*   // --> if yes, the ADC result is valid
*   // --> if not, the ADC queue and the BCCU trigger mechanism are out of sync --> reset everything
*   GLOBAL_BCCU_IntDisable(&GLOBAL_BCCU_0,2);
*   GLOBAL_BCCU_ClearEventFlag(&GLOBAL_BCCU_0, 2);
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*   while(1U)
*   {
*      // Trigger mode 1
*     // VADC Queue source is used
*
*     //  BCCU channels and dimming engine initialized in GUI
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

__STATIC_INLINE uint32_t GLOBAL_BCCU_GetLastTrigSrc(GLOBAL_BCCU_t *handle)
{
    XMC_ASSERT("GLOBAL_BCCU_GetLastTrigSrc: handler null pointer", handle != NULL);
    return (XMC_BCCU_ReadLastTrigChanNr(handle->bccuregs));
}

/**
* @brief Get the current details of the Event Flags raised.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @return uint32_t Event Flags raised
*
* \par<b>Description:</b><br>
*  Returns the current details of the Event Flags raised, It reads EVFR register.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Enable TRAP interrupt in GLOBAL_BCCU APP GUI.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step6: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t event_flag;
* void BCCU_Trap_ISR(void)
* {
*   event_flag = GLOBAL_BCCU_GetEventFlag(&GLOBAL_BCCU_0); // this gives trigger,fifo and trap flags status.
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

__STATIC_INLINE uint32_t GLOBAL_BCCU_GetEventFlag(GLOBAL_BCCU_t *handle)
{
    XMC_ASSERT("GLOBAL_BCCU_GetEventFlag: handler null pointer", handle != NULL);
    return (XMC_BCCU_ReadEventFlag(handle->bccuregs) & 0xFF);
}
/**
* @brief Sets the current details of the Event Flags raised.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param flag_type Event Mask value, multiple events can be ORed with this mask.
* @return None
*
* \par<b>Description:</b><br>
* Sets the current details of the Event Flags raised, It sets EVFSR register.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t event_flag;
* void BCCU_Trap_ISR(void)
* {
*   event_flag = GLOBAL_BCCU_GetEventFlag(&GLOBAL_BCCU_0);// this gives trigger,fifo and trap flags status.
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*   // software trap event and interrupt
*   GLOBAL_BCCU_SetEventFlag(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_STATUS_TRAP);  //enable TRAP event
*   GLOBAL_BCCU_IntEnable(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_TRAP);// enable TRAP interrupt
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

__STATIC_INLINE void GLOBAL_BCCU_SetEventFlag(GLOBAL_BCCU_t *handle, uint32_t flag_type)
{
    XMC_ASSERT("GLOBAL_BCCU_SetEventFlag: handler null pointer", handle != NULL);
    XMC_BCCU_SetEventFlag(handle->bccuregs, flag_type);
}
/**
* @brief Clears the current details of the Event Flags raised.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param flag_type Event Mask value. Multiple flags can be cleared with this mask.
* @return None
*
* \par<b>Description:</b><br>
* Clears the current details of the Event Flags raised, It sets EVFCR register.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
*
* void BCCU_Trap_ISR(void)
* {
*   // clears trap event
*   GLOBAL_BCCU_ClearEventFlag(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_STATUS_TRAP);
*
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   // software trap event and interrupt
*   GLOBAL_BCCU_SetEventFlag(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_STATUS_TRAP);  //enable TRAP event
*   GLOBAL_BCCU_IntEnable(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_TRAP);// enable TRAP interrupt
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

__STATIC_INLINE void GLOBAL_BCCU_ClearEventFlag(GLOBAL_BCCU_t *handle, uint32_t flag_type)
{
    XMC_ASSERT("GLOBAL_BCCU_ClearEventFlag: handler null pointer", handle != NULL);
    XMC_BCCU_ClearEventFlag(handle->bccuregs, flag_type);
}
/**
* @brief Enable the Interrupts for BCCU Trigger, FIFO and Trap events.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param interrupt Interrupt Mask value, multiple interrupts can be enabled with the mask.
* @return None
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t Trap_trig_flag,Trap_State,Trap_Inpt_Lvl;
* void BCCU_Trap_ISR(void)
* {
*   Trap_trig_flag = 1;
*   Trap_State = GLOBAL_BCCU_GetTrapState(&GLOBAL_BCCU_0);
*   // this determines whether the dangerous external event is still active or not
*   Trap_Inpt_Lvl = GLOBAL_BCCU_GetTrapInputLvl(&GLOBAL_BCCU_0);
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*    }
*
*   // software trap event and interrupt
*   GLOBAL_BCCU_SetEventFlag(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_STATUS_TRAP);  //enable TRAP event
*   GLOBAL_BCCU_IntEnable(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_TRAP);// enable TRAP interrupt
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/

__STATIC_INLINE void GLOBAL_BCCU_IntEnable(GLOBAL_BCCU_t *handle, uint32_t event)
{
    XMC_ASSERT("GLOBAL_BCCU_IntEnable: handler null pointer", handle != NULL);
    XMC_BCCU_EnableInterrupt(handle->bccuregs, event);
}
/**
* @brief Disables the Interrupts for BCCU Trigger, FIFO and Trap events.
* @param handle Pointer pointing to APP data structure. Refer @ref GLOBAL_BCCU_t for details.
* @param interrupt interrupt Interrupt Mask value, multiple interrupts can be disabled with the mask.
* @return None
*
* \par<b>Description:</b><br>
* Disables the Interrupts for BCCU Trigger and FIFO events.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate 1 PDM_BCCU , 1 DIM_BCCU  and 1 INTERRUPT APPs.<br>
* Step2: Enable dimming engine in DIM_BCCU APP GUI.<br>
* Step3: Deselect bypass dimming input in PDM_BCCU APP GUI.<br>
* Step4: Make HW signal connection from GLOBAL_BCCU's global_dimming_level to PDM_BCCU's dimming_level_input.<br>
* Step5: Make HW signal connection from GLOBAL_BCCU's event_trap_output to INTERRUPT's sr_irq. <br>
*
* @code
* #include <DAVE.h>
*
* uint32_t Trap_trig_flag,Trap_State,Trap_Inpt_Lvl;
* void BCCU_Trap_ISR(void)
* {
*   Trap_trig_flag = 1;
*   Trap_State = GLOBAL_BCCU_GetTrapState(&GLOBAL_BCCU_0);
*   // this determines whether the dangerous external event is still active or not
*   Trap_Inpt_Lvl = GLOBAL_BCCU_GetTrapInputLvl(&GLOBAL_BCCU_0);
*
*   // here evaluate whether we can exit trap or not
*
*   GLOBAL_BCCU_ExitTrap(&GLOBAL_BCCU_0);// exit trap, resume normal operation
*   GLOBAL_BCCU_IntDisable(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_TRAP);
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// GLOBAL_BCCU_Init() will be called within DAVE_Init()
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   // software trap event and interrupt
*   GLOBAL_BCCU_SetEventFlag(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_STATUS_TRAP);  //enable TRAP event
*   GLOBAL_BCCU_IntEnable(&GLOBAL_BCCU_0,XMC_BCCU_EVENT_TRAP);// enable TRAP interrupt
*
*   while(1U)
*   {
*      //  BCCU channels and dimming engine initialized in GUI
*     //  sometime during normal operation a TRAP is asserted
*
*   }
*   return (1);
* }
* @endcode<BR>
*/
__STATIC_INLINE void GLOBAL_BCCU_IntDisable(GLOBAL_BCCU_t *handle, uint32_t event)
{
    XMC_ASSERT("GLOBAL_BCCU_IntDisable: handler null pointer", handle != NULL);
    XMC_BCCU_DisableInterrupt(handle->bccuregs, event);
}

/**
* @}
*/

#ifdef __cplusplus
}
#endif

  /* Include APP extern file */
#include "global_bccu_extern.h"

#endif /* GLOBAL_BCCU_H */
