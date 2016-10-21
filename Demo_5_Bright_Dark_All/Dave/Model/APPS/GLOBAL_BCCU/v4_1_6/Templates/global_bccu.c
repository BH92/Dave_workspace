/**
 * @file global_bccu.c
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
 * 2015-03-30
 *     - GLOBAL_BCCU_ForceTrap, GLOBAL_BCCU_ExitTrap API's are modified to set/clear trap event.<br>
 *     - Comments are added for XMC_ASSERT().<br>
 *     - Return type of GLOBAL_BCCU_GetTrapState() is corrected.<br>
 *     - Trap input edge configuration added in initialization.<br>
 *     - XMC_ASSERT check is added for all API's.<br>
 *
 * @endcond
 *
 */


/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include "global_bccu.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL ROUTINES
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*
 * @brief API to retrieve the version of the GLOBAL_BCCU
 *
 * @return DAVE_APP_VERSION_t Structure containing major version, minor version
 *         and patch version.
 */
DAVE_APP_VERSION_t GLOBAL_BCCU_GetAppVersion(void)
{
  DAVE_APP_VERSION_t version;

  version.major = (uint8_t)GLOBAL_BCCU_MAJOR_VERSION;
  version.minor = (uint8_t)GLOBAL_BCCU_MINOR_VERSION;
  version.patch = (uint8_t)GLOBAL_BCCU_PATCH_VERSION;

  return (version);
}

/**
 * @brief   This function Initializes a GLOBAL_BCCU APP instances based on
 *          user configuration.
 */
GLOBAL_BCCU_STATUS_t GLOBAL_BCCU_Init(GLOBAL_BCCU_t *handle)
{
  GLOBAL_BCCU_STATUS_t status;

  /* Checks input parameters when XMC_ASSERT is enabled. Useful for Debugging */
  XMC_ASSERT("GLOBAL_BCCU APP handle function pointer uninitialized", (((handle != NULL) &&
  			(handle->bccuregs != NULL)) && ((handle->config != NULL) && (handle->enable_events <= 31U) &&
  	        (handle->trap_source <= 15))));

  /* Checking for initialization state of the instance */
  if (false == handle->init_status)
  {
    /* Configure Trap input source */
    XMC_BCCU_SelectTrapInput(handle->bccuregs,handle->trap_source);
    /* Configure Trap input edge*/
    XMC_BCCU_SetTrapEdge(handle->bccuregs,handle->trap_edge);
    /* Hardware initialization based on UI */
    XMC_BCCU_GlobalInit(handle->bccuregs, handle->config);
	/**< Initialize all the interrupt configurations */
    if (0U != handle->enable_events)
    {
      XMC_BCCU_EnableInterrupt(handle->bccuregs, handle->enable_events);
    }
    /* Return status after initialization */
    status = GLOBAL_BCCU_STATUS_SUCCESS;

    /* Update the Initialization status of the GLOBAL_BCCU APP instance */
    handle->init_status = true;
  }
  else
  {
    /* Return the status if instance is already initialized */
    status = GLOBAL_BCCU_STATUS_SUCCESS;
  }
  return (status);
}

/**
* @brief This function is used to configure Global Dimming Level.
*
* @param handle Instance handle
* @param level  Global Dimming Level value
* @return None
*/
void GLOBAL_BCCU_SetGlobDimLevel(GLOBAL_BCCU_t *handle, uint32_t level)
{
  XMC_ASSERT("GLOBAL_BCCU_SetGlobDimLevel: handler null pointer", handle != NULL);
  XMC_BCCU_SetGlobalDimmingLevel(handle->bccuregs, level);
}

/**
* @brief This function is used to configure Dimming Clock Prescaler.
*
* @param handle Instance handle
* @param dimclk_ps  Dimming Clock prescaler value
* @return None
*/
void GLOBAL_BCCU_SetDimClkPS(GLOBAL_BCCU_t *handle, uint32_t dimclk_ps)
{
  XMC_ASSERT("GLOBAL_BCCU_SetDimClkPS: handler null pointer", handle != NULL);
  XMC_BCCU_SetDimClockPrescaler(handle->bccuregs, dimclk_ps);
}

/**
* @brief This function is used to Generate the Trap Interrupt.
*
* @param handle Instance handle
* @return None
*/
void GLOBAL_BCCU_ForceTrap(GLOBAL_BCCU_t *handle)
{
  XMC_ASSERT("GLOBAL_BCCU_ForceTrap: handler null pointer", handle != NULL);
  XMC_BCCU_SetEventFlag(handle->bccuregs, (uint32_t)(XMC_BCCU_EVENT_STATUS_TRAP | XMC_BCCU_EVENT_STATUS_TRAP_STATE));
}
/**
* @brief This function is used to exit from the Trap State.
*
* @param handle Instance handle
* @return None
*/
void GLOBAL_BCCU_ExitTrap(GLOBAL_BCCU_t *handle)
{
  XMC_ASSERT("GLOBAL_BCCU_ExitTrap: handler null pointer", handle != NULL);
  XMC_BCCU_ClearEventFlag(handle->bccuregs, (uint32_t)(XMC_BCCU_EVENT_STATUS_TRAP | XMC_BCCU_EVENT_STATUS_TRAP_STATE));
}

/**
* @brief This function is used to check the current trap state.
*
* @param handle Instance handle
* @return XMC_BCCU_CH_TRAP_EDGE_t Trap state
*/
XMC_BCCU_TRAP_STATUS_t GLOBAL_BCCU_GetTrapState(GLOBAL_BCCU_t *handle)
{
  XMC_ASSERT("GLOBAL_BCCU_GetTrapState: handler null pointer", handle != NULL);
  return ((XMC_BCCU_TRAP_STATUS_t )((XMC_BCCU_ReadEventFlag(handle->bccuregs) & BCCU_EVFR_TPSF_Msk) >>
          BCCU_EVFR_TPSF_Pos));
}
/**
* @brief This function is used to get the Trap input level.
*
* @param handle Instance handle
* @return XMC_BCCU_TRAP_LEVEL_t Trap input level
*/
XMC_BCCU_TRAP_LEVEL_t GLOBAL_BCCU_GetTrapInputLvl(GLOBAL_BCCU_t *handle)
{
  XMC_ASSERT("GLOBAL_BCCU_GetTrapInputLvl: handler null pointer", handle != NULL);
  return ((XMC_BCCU_TRAP_LEVEL_t )((XMC_BCCU_ReadEventFlag(handle->bccuregs) & BCCU_EVFR_TPINL_Msk) >>
          BCCU_EVFR_TPINL_Pos));
}

