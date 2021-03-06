/**
 * @file pdm_bccu.h
 * @date 2016-07-15
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * PDM_BCCU v4.1.8 - PDM_BCCU APP configures the Channel registers of the Brightness and Color Control Unit (BCCU).
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
 * 2015-04-06
 *     - Code snippet changed according to APP owner feedbacks.<br>
 *     - PDM_BCCU_SelDimEngine() API prototype declaration is removed.<br>
 *     - XMC_ASSERT is added in static in-line functions.<br>
 *
 * 2015-06-20
 *     -Version check added for XMCLib dependency.<br>
 *
 * @endcond
 *
 */

#ifndef PDM_BCCU_H
#define PDM_BCCU_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include <xmc_bccu.h>
#include <xmc_gpio.h>
#include <DAVE_common.h>
#include "pdm_bccu_conf.h"
#include "../GLOBAL_BCCU/global_bccu.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
#if (!((XMC_LIB_MAJOR_VERSION == 2U) && \
       (XMC_LIB_MINOR_VERSION >= 0U) && \
       (XMC_LIB_PATCH_VERSION >= 0U)))
#error "PDM_BCCU requires XMC Peripheral Library v2.0.0 or higher"
#endif

/**********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/

/**
* @ingroup PDM_BCCU_enumerations
* @{
*/

/**
* Defines status of PDM_BCCU APP
*/
typedef enum PDM_BCCU_STATUS
{
  PDM_BCCU_STATUS_SUCCESS = 0, /**< Status Success if initialization is successful */
  PDM_BCCU_STATUS_FAILURE     /**< Status Failure if initialization is failed */
} PDM_BCCU_STATUS_t;

/**
* Defines whether corresponding PDM_BCCU channel enabled or disabled at initialization
*/
typedef enum PDM_BCCU_ENABLE_AT_INIT
{
  PDM_BCCU_ENABLE_AT_INIT_FALSE  = 0U, /**< PDM_BCCU Channel Disabled */
  PDM_BCCU_ENABLE_AT_INIT_TRUE   /**< PDM_BCCU Channel Enabled */
} PDM_BCCU_ENABLE_AT_INIT_t;
/**
* @}
*/
/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/

/**
* @ingroup PDM_BCCU_datastructures
* @{
*/

/**
* Defines APP configuration parameters
*/
typedef struct PDM_BCCU
{
  BCCU_Type *const bccu_regs; /**< BCCU Global Register Pointer */
  const XMC_BCCU_CH_CONFIG_t *const config; /**< Reference to hardware channel configuration */
  XMC_GPIO_CONFIG_t *gpio_config; /**< GPIO input/output Characteristics  */
  XMC_GPIO_PORT_t *gpio_port; /**< GPIO Port Number */
  BCCU_CH_Type *const bccu_ch; /**< Channel specific register set */
  GLOBAL_BCCU_t *const global_bccu_handleptr; /**< GLOBAL_BCCU APP Handle Pointer */
  PDM_BCCU_ENABLE_AT_INIT_t channel_enable_at_init; /**< PDM_BCCU Channel status at initialization */
  XMC_BCCU_CH_ACTIVE_LEVEL_t output_level; /**<Channel Output Passive Level */
  XMC_BCCU_CH_TRIGOUT_t trigger_line; /**<Channel trigger line */
  uint32_t channel_no; /**< Channel Number */
  uint32_t linear_walk_time; /**< Initial linear walk time */
  uint32_t intensity; /**< Channel initial intensity */
  uint32_t trigger_en; /**< Channel trigger Edge enable */
  uint8_t  gpio_pin; /**< GPIO Pin Number */
  bool output_pin_enable; /**< Output Enable */
  bool trap_enable; /**<Trap Enable */
} PDM_BCCU_t;

/**
* @}
*/

/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 * API Prototypes
 **********************************************************************************************************************/

/**
* @ingroup PDM_BCCU_apidoc
* @{
*/

 /**
* @brief Get PDM_BCCU APP version
* @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
*
* \par<b>Description: </b><br>
* The function can be used to check application software compatibility with a
* specific version of the APP.
*
* Example Usage:
*
* @code
* #include <DAVE.h>
*
* int main(void) {
*   DAVE_STATUS_t init_status;
*   DAVE_APP_VERSION_t version;
*
*   // Initialize GLOBAL_BCCU APP:
*   // PDM_BCCU_Init() is called from within DAVE_Init().
*   init_status = DAVE_Init();
*
*   version = PDM_BCCU_GetAppVersion();
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

DAVE_APP_VERSION_t PDM_BCCU_GetAppVersion(void);

 /**
* @brief Initializes a PDM_BCCU APP instance based on user configuration.
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @return PDM_BCCU_STATUS_t APP status. Refer @ref PDM_BCCU_STATUS_t for details.
*
* \par<b>Description: </b><br>
* Initializes and enables BCCU module, GPIO pin, channel's passive level, Trap input, trigger output, linear walk time
* and target intensity.
*
* \par<b>Example Usage:</b><br>
*
* @code
* #include <DAVE.h>
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init(&PDM_BCCU_0) will be called within DAVE_Init()
*   if (status == DAVE_STATUS_SUCCESS)
*   {
*      // Add application code here
*         while(1U)
*         {
*         }
*   }
*   else
*   {
*     XMC_DEBUG("main: Application initialization failed");
*      while(1U)
*      {
*      }
*   }
*   return (1);
*  }
* @endcode<BR>
*/

PDM_BCCU_STATUS_t PDM_BCCU_Init(PDM_BCCU_t * handle);
/**
* @brief Enable the Channel
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @return None
*
*
* \par<b>Example Usage: </b> Explicitly enabling BCCU channel and changing channel intensity.<br>
* Step1: Instantiate PDM_BCCU APP.<br>
* Step2: Deselect Enable channel at initialization in PDM_BCCU.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*   PDM_BCCU_EnableChannel(&PDM_BCCU_0); // Enable mapped channel by solver
*   while(1U)
*   {
*     // Change intensity to 50%
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,2048);
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*     // Wait for All Channels to Complete Linear Walk
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);
*
*   }
*   return (1);
* }
*
* @endcode<BR>
*/
 void PDM_BCCU_EnableChannel(PDM_BCCU_t *handle);
 /**
* @brief Disable the Channel
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @return None
*
* \par<b>Description: </b><br>
* Channel is disabled, the output level goes to passive; the Linear Walker and the Sigma-Delta Modulator are reset,
* Packer FIFO is flushed; all internal logic and INTy are reset when the channel gets disabled.
*
* \par<b>Example Usage:</b> <br>
* Step1: Instantiate PDM_BCCU APP.<br>
* Step2: Deselect Enable channel at initialization in PDM_BCCU.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*   PDM_BCCU_EnableChannel(&PDM_BCCU_0); // Enable mapped channel by solver
*   while(1U)
*   {
*     // Change intensity to 50%
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,2048);
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*     // Wait for All Channels to Complete Linear Walk
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);
*     //disable channel for valid reason
*     PDM_BCCU_DisableChannel(&PDM_BCCU_0);
*   }
*   return (1);
* }
*
* @endcode<BR>
*/

void PDM_BCCU_DisableChannel(PDM_BCCU_t *handle);
/**
* @brief Enable gating input
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @return None
*
* \par<b>Description: </b><br>
* The gating connection is made of combinatorial logic only to enable fast control schemes, such as peak-current control.
*
* Example Usage:
*/

void PDM_BCCU_GateEnable(PDM_BCCU_t *handle);
/**
* @brief Disable gating input.
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @return None
*
* \par<b>Description: </b><br>
* Gating function is disabled.
*
* Example Usage:
*/

void PDM_BCCU_GateDisable(PDM_BCCU_t *handle);
/**
* @brief Set Target Channel Intensity.
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @param intensity Target Channel Intensity. Range :0-4095
* @return None
*
* \par<b>Description: </b><br>
* Sets target channel intensity.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU APP.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*    }
*   PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,0); // Go to target intensity immediately
*
*   while(1U)
*   {
*     // Change intensity to 25%
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,1024);
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*     // Wait for All Channels to Complete Linear Walk
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);
*   }
*   return (1);
* }
*
* @endcode<BR>
*/

void PDM_BCCU_SetIntensity(PDM_BCCU_t *handle,uint32_t intensity);
/**
* @brief Set Linear Walk Time.
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
* @param prescaler Linear Walker Clock Prescaler. Range :0-1023
*
* @return None
*
* \par<b>Description: </b><br>
* Determines how long it takes for the Channel Intensity to reach the Target Channel Intensity after shadow transfer
* (after CHSTRCON.CHyS is set). Necessary for smooth linear color transitions. If this value is 0, then the intensity
* level will become the same as the target intensity level on shadow transfer and the linear walker is bypassed.
*
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU APP.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
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
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,512);// Change intensity to 12.5%
*     PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,1023); // Go to target intensity slowly
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);// Wait for All Channels to Complete Linear Walk
*
*   }
*   return (1);
* }
*
* @endcode<BR>
*/

 void PDM_BCCU_SetLinearWalk(PDM_BCCU_t *handle,uint32_t prescalar);
 /**
* @brief Start Linear Walk
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return None
*
* \par<b>Description: </b><br>
* After channel initialization, the outcome of executing the API starts changing the color smoothly towards the target
* by writing register bit CHSTRCON.CHyS.
*
* \par<b>Example Usage: </b><br>
* Step1: Instantiate PDM_BCCU APP.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*    }
*    while(1U)
*    {
*
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,2048);// Change intensity to 50%
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);// Wait for All Channels to Complete Linear Walk
*    }
*   return (1);
* }
*
* @endcode<BR>
*/

void PDM_BCCU_StartLinearWalk(PDM_BCCU_t *handle);
/**
* @brief Abort Linear Walk
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return None
*
* \par<b>Description: </b><br>
* When the linear walk in progress, the outcome of executing the API is stopping the linear walk (i.e. color change)
* immediately.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU APP.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*    }
*
*    while(1U)
*    {
*      // Change intensity to 12.5%
*      PDM_BCCU_SetIntensity(&PDM_BCCU_0,512);
*      // Go to target intensity slowly
*      PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,1023);
*      PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*      // Wait for All Channels to Complete Linear Walk
*      PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);
*
*      // After some time due to some reasons abort current linear walk and set new value.
*      PDM_BCCU_AbortLinearWalk(&PDM_BCCU_0); // Stops changing intensity.
*      // Go to target intensity slowly
*      PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,512);
*      PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*      // Wait for All Channels to Complete Linear Walk
*      PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);
*     }
*   return (1);
* }
*
* @endcode<BR>
*/

void PDM_BCCU_AbortLinearWalk(PDM_BCCU_t *handle);

/**
* @brief Get the linear Walk Status
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return uint32_t returns linear walk status of the channel. Range: 0-Completed or 1-Walking
*
* \par<b>Description: </b><br>
* Retrieves linear walk completion status.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*    }
*
*   while(1U)
*   {
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,512);// Change intensity to 12.5%
*     PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,1023); // Go to target intensity slowly
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*
*     while(PDM_BCCU_LinearWalkStatus(&PDM_BCCU_0)!= 0);// waiting for channel to reach target intensity
*
*   }
*   return (1);
* }
*
* @endcode<BR>
*/

uint32_t  PDM_BCCU_LinearWalkStatus(PDM_BCCU_t *handle);
/**
* @brief Wait until linear walk is completed.
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return None
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
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
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,512);// Change intensity to 12.5%
*     PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,1023); // Go to target intensity slowly
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*
*     PDM_BCCU_AwaitEndOfLinearWalk(&PDM_BCCU_0);// Wait for All Channels to Complete Linear Walk
*
*    }
*   return (1);
*  }
*
* @endcode<BR>
*/

void PDM_BCCU_AwaitEndOfLinearWalk(PDM_BCCU_t *handle);
/**
* @brief Returns the output level at the latest trigger
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return returns the output level when the last trigger occurred <BR>
*
* \par<b>Description: </b><br>
* Returns the output level the channel had when the latest trigger occurred. This is useful in Trigger Mode 0.
* When a trigger occurs, the triggered ADC measurement may not be valid, depending on the channel output level.
*
* \par<b>Example Usage:</b> ADC triggering configured. Several BCCU channels trigger the ADC.<br>
*
* @code
* #include <DAVE.h>
*
* void ADC_RESULT_ISR(void)
* {
*   uint32_t output_lvl;
*
*   output_lvl = PDM_BCCU_GetOpLvlAtLastTrigger(PDM_BCCU_t *handle);
*   if (output_lvl) {
*   // measurement was valid
*   // read ADC result here *
*   }
* }
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*   {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*   PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,0); // Go to target intensity immediately
*
*   while(1U)
*   {
*
*    // user application code
*
*   }
*   return (1);
* }
*
* @endcode<BR>
*/
__STATIC_INLINE uint32_t PDM_BCCU_GetOpLvlAtLastTrigger(PDM_BCCU_t *handle)
{
  XMC_ASSERT("PDM_BCCU_GetOpLvlAtLastTrigger: handler null pointer", handle != NULL);
  return (XMC_BCCU_GetChannelOutputLvlAtLastTrigger(handle->bccu_regs,handle->channel_no));
}
  /**
* @brief Return current channel intensity
* @param handle Pointer pointing to APP data structure. Refer @ref PDM_BCCU_t for details.
*
* @return uint32_t returns channel intensity
*
* \par<b>Description: </b><br>
* Retrieves current channel intensity.
*
* \par<b>Example Usage:</b><br>
* Step1: Instantiate PDM_BCCU.<br>
*
* @code
* #include <DAVE.h>
*
* int main(void)
* {
*   DAVE_STATUS_t status;
*   status = DAVE_Init();// PDM_BCCU_Init() will be called within DAVE_Init()
*
*   if (status == DAVE_STATUS_FAILURE)
*  {
*     XMC_DEBUG(("DAVE APPs initialization failed with status %d\n", status));
*     while(1U)
*     {
*     }
*   }
*
*   while(1U)
*   {
*     PDM_BCCU_SetIntensity(&PDM_BCCU_0,512);// Change intensity to 12.5%
*     PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,1023); // Go to target intensity slowly
*     PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
*
*     do
*     {
*
*       //user application code
*
*     }while(PDM_BCCU_GetIntensity(&PDM_BCCU_0)!= 512);// waiting for channel to reach target intensity
*
*   }
*   return (1);
* }
*
* @endcode<BR>
*/

__STATIC_INLINE uint32_t PDM_BCCU_GetIntensity(PDM_BCCU_t *handle)
{
  XMC_ASSERT("PDM_BCCU_GetIntensity: handler null pointer", handle != NULL);
  return XMC_BCCU_CH_ReadIntensity(handle->bccu_ch);
}

/**
 *@}
 */

#ifdef __cplusplus
}
#endif

/* Include APP extern file */
#include "pdm_bccu_extern.h"

#endif /* _PDM_BCCU_H_ */

