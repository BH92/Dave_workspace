/**
 * @file digital_io.c
 * @date 2015-08-25
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * DIGITAL_IO v4.0.12 - The DIGITAL_IO APP is used to configure a port pin as digital Input/Output.
 *
 * Copyright (c) 2015, Infineon Technologies AG
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
 *     - Initial version<br>
 * 2015-12-22
 *     - Added hardware controlled IO feature.
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "samuel_io.h"
#include <DAVE.h>

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/
   uint32_t delay_count=5;
   uint32_t test=5;
   uint16_t  resultB = 0x0fff;
    E_EEPROM_XMC1_STATUS_t EEprom_status;
	E_EEPROM_XMC1_OPERATION_STATUS_t oper_status;

    uint8_t	   transmit_buf_size = 9;
       uint16_t		 Brightness_Gen = 0x7fff;
       uint16_t		 ColorQuot_Gen = 0x7fff;
       uint16_t  linearwalk_gen= 0xb0;

       uint16_t zahler_offlight = 0x0;
       uint16_t zahler_lightprog01 = 0x0;  //n+l

/***********************************************************************************************************************
 * LOCAL ROUTINES
 **********************************************************************************************************************/
       uint16_t resultA,resultB,resultC,resultD;
       uint16_t resultAalt,resultBalt,resultCalt,resultDalt=0;

       uint16_t resultAalt2,resultBalt2,resultCalt2,resultDalt2=0;

       uint16_t adc_ready,adc_ready20m =0;
  	 uint8_t B_nextLedOff=0;
	 uint8_t B_first_uart=0;  //  wenn 1 dann wird einmalig eine hallo nachricht gesendet
 /**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

  int digitalo (void)
  {
	 // DIGITAL_IO_ToggleOutput(&DO_Linux_Int); //toggles level at pin
	  test=test+1;
      for(delay_count = 0;delay_count<0xfffff;delay_count++);
	  return (test);
  }

  void LED_Toggle_EverySec(void)
  {
    // LED Toggle for every second
		//UART_Transmit(&UART_1, new_data,transmit_buf_size);
   // DIGITAL_IO_ToggleOutput(&VCC_LED_shtdwn);
    Offlight_zahler_write();
    firstuartBack ();
    lightprog01 ();  //n+l
  ///  light_aus ();//n+l
	  /// analog_start ();
	//a  new_data_fill();
	//a	UART_Transmit(&UART_1, new_data,transmit_buf_size);
  }
  //------------------------------------------
  void lightprog01 (void)//n+l
   {

	  ++zahler_lightprog01;
	  if ( zahler_lightprog01 == 41 )  //ende
	 			 {
		  zahler_lightprog01 = 0;
	 			 }
	 			 else if (  zahler_lightprog01 == 20)
	 			 {
	 				   	  PDM_DIMMED_LED_LAMP_0.config->led_intensity[0] = 0;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[1] = 0;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[2] = 0;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[3] = 0;
	 				      PDM_DIMMED_LED_LAMP_SetColor(&PDM_DIMMED_LED_LAMP_0);
	 				      PDM_DIMMED_LED_LAMP_SetDimLevelExponentialAdv(&PDM_DIMMED_LED_LAMP_0,0x0,0x394);
	 			 }
	 			 else if (  zahler_lightprog01 == 40 )
	 			 {
	 				   	  PDM_DIMMED_LED_LAMP_0.config->led_intensity[0] = 2800;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[1] = 0;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[2] = 2800;
	 				      PDM_DIMMED_LED_LAMP_0.config->led_intensity[3] = 0;
		 				  PDM_DIMMED_LED_LAMP_SetColor(&PDM_DIMMED_LED_LAMP_0);
			 			  PDM_DIMMED_LED_LAMP_SetDimLevelExponentialAdv(&PDM_DIMMED_LED_LAMP_0,0x0,0x394);
	 			 }
				 else

				 {

				 }

   }
  //------------------------------------------
  void light_aus (void)//n+l
   {
      linearwalk_ww1 = linearwalk_gen;
      linearwalk_ww2 = linearwalk_gen;
      linearwalk_cw1 = linearwalk_gen;
      linearwalk_cw2 = linearwalk_gen;
	  bcudirAktBerechnung();
	  bcuUebergabe();
	    // Set Target Level 50%
	     DIM_BCCU_SetDimLvl(&DIM_BCCU_0, 2048);
	     // Start Dimming
	     DIM_BCCU_StartDimming(&DIM_BCCU_0);

   }
  //------------------------------------------



 void analog_start (void)
  {
//ADC_MEASUREMENT_ADV_StartADC(&ADC_MEASUREMENT_ADV_0);
 // ADC_MEASUREMENT_ADV_SoftwareTrigger(&ADC_MEASUREMENT_ADV_0);

  }


 void UserIRQHandler(void)
  {
	 // DIGITAL_IO_ToggleOutput(&DO_VCC_LED_shtdwn);
	//  DIGITAL_IO_SetOutputHigh(&DO_VCC_LED_shtdwn);
    //    resultA = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_ntc);
    //    resultB = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_U_in);
    //    resultC = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_I_ww);
     //   resultD = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_I_cw);
   	//  DIGITAL_IO_SetOutputLow(&DO_VCC_LED_shtdwn);
  }

 void new_data_fill(void) // ausgabe über rxd
 {
	 transmit_buf_size=11;
	 new_data[0]=1;
	 new_data[1]=2;
	 new_data[2]=3;
	 new_data[3]=4;
	 new_data[4]=5;
	 new_data[5]=6;
 	 new_data[6]=7;
 	 new_data[7]=8;
 	 new_data[8]=9;
 	 new_data[9]='a';
	 new_data[10]='b';
 }




 void new_data_unbekanntBack(void) // ausgabe über rxd
 {
	 transmit_buf_size=11;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]= command_unbekanntBack;
	 new_data[6]='n';
	 new_data[7]='o';
	 new_data[8]='n';
	 new_data[9]='o';
	 new_data[10]=command_codeEnd;
 }

//------------------------------------------
 void new_data_BroadcastBack(void) // ausgabe über rxd
 {

	 transmit_buf_size=11;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]=command_BroadcastBack;
 	 new_data[6]= 	Ser_NrH  / 0x100; //highbyte
 	 new_data[7]= 	Ser_NrH  & 0xff; //highbyte
 	 new_data[8]= 	Ser_NrL  / 0x100; //highbyte
 	 new_data[9]= 	Ser_NrL  & 0xff; //lowbyte
	 new_data[10]=command_codeEnd;
 }
 //------------------------------------------
 void new_data_analog1Back(void) // ausgabe über rxd
 {
	 transmit_buf_size=11;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]=command_ana1Back;
 	 new_data[6]= 	resultA2  / 256; //highbyte
 	 new_data[7]= 	resultA2  & 0xff; //lowbyte
 	 new_data[8]= 	resultB2 / 256; //highbyte
 	 new_data[9]= 	resultB2  & 0xff; //lowbyte
	 new_data[10]=command_codeEnd;
 }
 //------------------------------------------------------

 void new_data_analog2Back(void) // ausgabe über rxd
 {
	 transmit_buf_size=11;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]=command_ana2Back;
 	 new_data[6]= 	resultC2  / 256; //highbyteresultD2
 	 new_data[7]= 	resultC2  & 0xff; //lowbyte
 	 new_data[8]= 	resultD2 / 256; //highbyte
 	 new_data[9]= 	resultD2  & 0xff; //lowbyte
	 new_data[10]=command_codeEnd;
 }
 //------------------------------------------------------

 void new_data_aktLichtBack(void) // ausgabe über rxd
 {
	 transmit_buf_size=11;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]=command_aktLichtBack;
 	 new_data[6]= 	dimAkt_Ww  / 256; //highbyte
 	 new_data[7]= 	dimAkt_Ww  & 0xff; //lowbyte
 	 new_data[8]= 	dimAkt_Cw / 256; //highbyte
 	 new_data[9]= 	dimAkt_Cw  & 0xff; //lowbyte
	 new_data[10]=command_codeEnd;
 }
 //------------------------------------------------------

 void new_data_offLichtBack(void) // ausgabe über rxd
 {
	 transmit_buf_size=13;
	 new_data[0]=command_code01;
	 new_data[1]=command_code02;
	 new_data[2]=command_code03;
	 new_data[3]=node_id;
	 new_data[4]=transmit_buf_size;
	 new_data[5]=command_offLichtBack;
 	 new_data[6]= 	dimOff_Ww  / 256; //highbyte
 	 new_data[7]= 	dimOff_Ww  & 0xff; //lowbyte
 	 new_data[8]= 	dimOff_Cw  / 256; //highbyte
 	 new_data[9]= 	dimOff_Cw  & 0xff; //lowbyte
 	 new_data[10]= 	RegOnOff ; //
 	 new_data[11]= 	RegOnOff2 ;
	 new_data[12]=command_codeEnd;
 }
 //------------------------------------------------------

  void new_data_Bright_Color_Back(void) // ausgabe über rxd
  {
 	 transmit_buf_size=11;
 	 new_data[0]=command_code01;
 	 new_data[1]=command_code02;
 	 new_data[2]=command_code03;
 	 new_data[3]=node_id;
 	 new_data[4]=transmit_buf_size;
 	 new_data[5]=command_Bright_Color_Back;
  	 new_data[6]= 	Brightness_Gen  / 256; //highbyte
  	 new_data[7]= 	Brightness_Gen  & 0xff; //lowbyte
  	 new_data[8]= 	ColorQuot_Gen / 256; //highbyte
  	 new_data[9]= 	ColorQuot_Gen  & 0xff; //lowbyte
 	 new_data[10]=command_codeEnd;
  }
  //------------------------------------------------------

  void new_data_Quot_Walk_Back(void) // ausgabe über rxd
  {
 	 transmit_buf_size=11;
 	 new_data[0]=command_code01;
 	 new_data[1]=command_code02;
 	 new_data[2]=command_code03;
 	 new_data[3]=node_id;
 	 new_data[4]=transmit_buf_size;
 	 new_data[5]=command_Quot_Walk_Back;
  	 new_data[6]= 	linearwalk_gen  / 256; //highbyte
  	 new_data[7]= 	linearwalk_gen  & 0xff; //lowbyte
  	 new_data[8]= 	Farbe_wwcw_Quot_gen / 256; //highbyte
  	 new_data[9]= 	Farbe_wwcw_Quot_gen  & 0xff; //lowbyte
 	 new_data[10]=command_codeEnd;
  }
 //------------------------------------------

  void new_data_HalloBack(void) // ausgabe über rxd
  {
 	 transmit_buf_size=11;
 	 new_data[0]=command_code01;
 	 new_data[1]=command_code02;
 	 new_data[2]=command_code03;
 	 new_data[3]=node_id;
 	 new_data[4]=transmit_buf_size;
 	 new_data[5]=command_HalloBack;
 	 new_data[6]='o';
 	 new_data[7]='k';
 	 new_data[8]='o';
 	 new_data[9]='k';
 	 new_data[10]=command_codeEnd;
  }
  //------------------------------------------------------
   void new_data_neuNodeIdBack(void) // ausgabe über rxd
   {
  	 transmit_buf_size=12;
  	 new_data[0]=command_code01;
  	 new_data[1]=command_code02;
  	 new_data[2]=command_code03;
  	 new_data[3]=node_id;
  	 new_data[4]=transmit_buf_size;
  	 new_data[5]=command_neuNodeIdBack;
   	 new_data[6]= 	node_id_neu; //highbyte
   	 new_data[7]= 	Ser_NrH  / 0x100; //highbyte
   	 new_data[8]= 	Ser_NrH  & 0xff; //lowbyte
   	 new_data[9]= 	Ser_NrL  / 0x100; //highbyte
   	 new_data[10]= 	Ser_NrL  & 0xff; //lowbyte
  	 new_data[11]=command_codeEnd;
   }
   //------------------------------------------------------

   void new_data_neuSerNrBack(void) // ausgabe über rxd
   {
  	 transmit_buf_size=15;
  	 new_data[0]=command_code01;
  	 new_data[1]=command_code02;
  	 new_data[2]=command_code03;
  	 new_data[3]=node_id;
  	 new_data[4]=transmit_buf_size;
  	 new_data[5]=command_neuSerNrBack;
   	 new_data[6]= 	neu_Ser_NrH  / 0x100; //highbyte
   	 new_data[7]= 	neu_Ser_NrH  & 0xff; //highbyte
   	 new_data[8]= 	neu_Ser_NrL  / 0x100; //highbyte
   	 new_data[9]= 	neu_Ser_NrL  & 0xff; //lowbyte
   	 new_data[10]= 	Ser_NrH  / 0x100; //highbyte
   	 new_data[11]= 	Ser_NrH  & 0xff; //highbyte
   	 new_data[12]= 	Ser_NrL  / 0x100; //highbyte
   	 new_data[13]= 	Ser_NrL  & 0xff; //lowbyte
  	 new_data[14]=command_codeEnd;
   }
   //------------------------------------------------------

   void new_data_NodeIdBack(void) // ausgabe über rxd
   {
  	 transmit_buf_size=13;
  	 new_data[0]=command_code01;
  	 new_data[1]=command_code02;
  	 new_data[2]=command_code03;
  	 new_data[3]=node_id;
  	 new_data[4]=transmit_buf_size;
  	 new_data[5]=command_NodeIdBack;
   	 new_data[6]= 	node_id_alt ; // alte node_id_eeprom
   	 new_data[7]= 	node_id; // node_id_eeprom
   	 new_data[8]= 	Ser_NrH  / 0x100; //highbyte
   	 new_data[9]= 	Ser_NrH  & 0xff; //highbyte
   	 new_data[10]= 	Ser_NrL  / 0x100; //highbyte
   	 new_data[11]= 	Ser_NrL  & 0xff; //lowbyte
  	 new_data[12]=command_codeEnd;
   }

   //------------------------------------------------------

   void new_data_SerNrBack(void) // ausgabe über rxd
   {
  	 transmit_buf_size=11;
  	 new_data[0]=command_code01;
  	 new_data[1]=command_code02;
  	 new_data[2]=command_code03;
  	 new_data[3]=node_id;
  	 new_data[4]=transmit_buf_size;
  	 new_data[5]=command_SerNrBack;
   	 new_data[6]= 	Ser_NrH  / 0x100; //highbyte
   	 new_data[7]= 	Ser_NrH  & 0xff; //lowbyte
   	 new_data[8]= 	Ser_NrL  / 0x100; //highbyte
   	 new_data[9]= 	Ser_NrL  & 0xff; //lowbyte
  	 new_data[10]=command_codeEnd;
   }
   //-------------------------------------
   void new_data_readbuff2Back(void) // ausgabe über rxd
   {
  	 transmit_buf_size=24;
  	 new_data[0]=command_code01;
  	 new_data[1]=command_code02;
  	 new_data[2]=command_code03;
  	 new_data[3]=node_id;
  	 new_data[4]=transmit_buf_size;
  	 new_data[5]=command_readbuff2Back;
  	 new_data[6]=0; // buffertyp
								 new_data[7]=ReadBuffer2[0];
								 new_data[8]=ReadBuffer2[1];
								 new_data[9]=ReadBuffer2[2];
								 new_data[10]=ReadBuffer2[3];
								 new_data[11]=ReadBuffer2[4];
								 new_data[12]=ReadBuffer2[5];
								 new_data[13]=ReadBuffer2[6];
								 new_data[14]=ReadBuffer2[7];
								 new_data[15]=ReadBuffer2[8];
								 new_data[16]=ReadBuffer2[9];
								 new_data[17]=ReadBuffer2[10];
								 new_data[18]=ReadBuffer2[11];
								 new_data[19]=ReadBuffer2[12];
								 new_data[20]=ReadBuffer2[13];
								 new_data[21]=ReadBuffer2[14];
								 new_data[22]=ReadBuffer2[15];

  	 new_data[23]=command_codeEnd;
   }

 //------------------------------------------------------

// Eprom speichern###############################################################
 //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
 void clearEpromBuffer(void)
 {

	//Clear the Read buffer before accepting the read request
	for(Index = 0; Index<16;Index++)
	{  ReadBuffer1[Index] = 0; }

	//Clear the Read buffer before accepting the read request
	for(Index = 0; Index<16;Index++)
	{  ReadBuffer2[Index] = 0; }

	//Clear the Read buffer before accepting the read request
	for(Index = 0; Index<32;Index++)
	{  ReadBuffer3[Index] = 0; }
 }

 //---------------------------------
 void fillEpromBuffer(void)// Fill the buffer with incremental data from 0 to 100
 {
	// Fill the buffer with incremental data from 0 to 100
	for(Index = 0; Index<100;Index++)
	{  data_buffer[Index] = Index; }
 }

 //---------------------------------
 void fill2EpromBuffer(void)  //Refill the data buffer with new values starting from 255 to 155
 {
	// Fill the buffer with incremental data from 0 to 100
	 for(Index = 0; Index<100; Index++)
	 {  data_buffer[Index] = (255 - Index); }
 }


 //------------------------------------------------


 //------------------------------------------------
 int readAllEEprom(void)
 {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
   {
   oper_status = E_EEPROM_XMC1_Read(serial_first_data,0U,ReadBuffer1,16U);
   }
   if(oper_status == E_EEPROM_XMC1_OPERATION_STATUS_SUCCESS)
   {
	   Ser_NrH = ReadBuffer1[1];
	   Ser_NrL = ReadBuffer1[2];


   oper_status = E_EEPROM_XMC1_Read(node_data,0U,ReadBuffer2,16U);
   }
   if(oper_status == E_EEPROM_XMC1_OPERATION_STATUS_SUCCESS)
   {
	   node_id_alt = ReadBuffer2[1];
	   node_id  = ReadBuffer2[2];
	   node_id_16bit = ReadBuffer2[3] * 0x100 + ReadBuffer2[4];

   oper_status = E_EEPROM_XMC1_Read(off_light_data,0U,ReadBuffer3,32U);
   }
   if(oper_status == E_EEPROM_XMC1_OPERATION_STATUS_SUCCESS)
   {
	   RegOnOff = ReadBuffer3[1];
	   RegOnOff2 = ReadBuffer3[2];
	   dimAkt_Ww = ReadBuffer3[3] * 0x100 + ReadBuffer3[4];
	   dimAkt_Cw =  ReadBuffer3[5] * 0x100 + ReadBuffer3[6];
	   dimOff_Ww = ReadBuffer3[7] * 0x100 + ReadBuffer3[8];
	   dimOff_Cw = ReadBuffer3[9] * 0x100 + ReadBuffer3[10];
	   dimNorm1_Ww = ReadBuffer3[11] * 0x100 + ReadBuffer3[12];
	   dimNorm1_Cw = ReadBuffer3[13] * 0x100 + ReadBuffer3[14];
	   dimNorm2_Ww = ReadBuffer3[15] * 0x100 + ReadBuffer3[16];
	   dimNorm2_Cw = ReadBuffer3[17] * 0x100 + ReadBuffer3[18];

   }
   return (EEprom_status+0x10*oper_status);
 }
 //------------------------------------------------

 int readSerNrEEprom(void)
 {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
	 {
       oper_status = E_EEPROM_XMC1_Read(serial_first_data,0U,ReadBuffer1,16U);
     }
 return (EEprom_status+0x10*oper_status);
 }
 //------------------------------------------------

 int readNodeIdEEprom(void)
 {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
	 {
       oper_status = E_EEPROM_XMC1_Read(node_data,0U,ReadBuffer2,16U);
     }
 return (EEprom_status+0x10*oper_status);// idle =3 succses =0  ==0x03
 }

 //------------------------------------------------

 int read_akt_light_EEprom(void)
 {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
	 {
       oper_status = E_EEPROM_XMC1_Read(akt_light_data,0U,ReadBuffer2,16U);
     }
 return (EEprom_status+0x10*oper_status);// idle =3 succses =0  ==0x03
 }
 //------------------------------------------------

 int read_off_light_EEprom(void)
 {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
	 {
       oper_status = E_EEPROM_XMC1_Read(off_light_data,0U,ReadBuffer2,16U);
     }
 return (EEprom_status+0x10*oper_status);// idle =3 succses =0  ==0x03
 }

 //------------------------------------------------
 int writeSernr_B1_EEprom(void)
 {
	 int a = 0b10000000;
	if (resultB > min_EEP_Voltage_Uin)
  {
	  EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
    {
    oper_status = E_EEPROM_XMC1_Write(serial_first_data,ReadBuffer1);
    }
	 a = 0;
  }
    return (EEprom_status + 0x10 * oper_status + a);
 }
 //------------------------------------------------
 int writeNodeid_B2_EEprom(void)
 {
  int a = 0b10000000; // erfolgreiche spannung=0
	if (resultB > min_EEP_Voltage_Uin)
    {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	  if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
      {
      oper_status = E_EEPROM_XMC1_Write(node_data,ReadBuffer2);
      }
	 a = 0;
    }
    return (EEprom_status + 0x10 * oper_status + a);
 }
 //----------------------------

 int writeLamp_data_B3_EEprom(void) // writeLamp_data_B3_EEprom
 {
	 int a = 0b10000000;
	if (resultB > min_EEP_Voltage_Uin)
  {
	  EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
    {
    oper_status = E_EEPROM_XMC1_Write(lamp_data,ReadBuffer3);
    }
	 a = 0;
  }
    return (EEprom_status + 0x10 * oper_status + a);
 }

 //------------------------------------------------
 int writeakt_light_data_B4_EEprom(void)
 {
  int a = 0b10000000; // erfolgreiche spannung=0
	if (resultB > min_EEP_Voltage_Uin)
    {
	 EEprom_status = E_EEPROM_XMC1_GetStatus();
	  if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
      {
      oper_status = E_EEPROM_XMC1_Write(akt_light_data,ReadBuffer2);
      }
	 a = 0;
    }
    return (EEprom_status + 0x10 * oper_status + a);
 }
 //----------------------------

 int writeOff_light_B5_EEprom(void)
 {
	 int a = 0b10000000;
	if (resultB > min_EEP_Voltage_Uin)
  {
	  EEprom_status = E_EEPROM_XMC1_GetStatus();
	 if(EEprom_status == E_EEPROM_XMC1_STATUS_IDLE)
    {
    oper_status = E_EEPROM_XMC1_Write(off_light_data,ReadBuffer2);




    }
	 a = 0;
  }
    return (EEprom_status + 0x10 * oper_status + a);
 }

///#############################################
 //initialisierung


 void sysiniValueB1(void)
 {
//	   Ser_NrH = 0x4142 ;
//	   Ser_NrL = 0x4344 ;

	   Ser_NrH = 0x7b7a;
       Ser_NrL = 0x5859 ;
       Hard_Vers = 1000 ;
	   Soft_Vers = 1000 ;
	   GEH_Vers = 1000 ;
	   Mon_Vers = 1000 ;
	   LED_WW_Vers = 1000 ;
	   LED_CW_Vers = 1000 ;

       neu_Ser_NrH = 0 ;
       neu_Ser_NrL = 0 ;

 }


 void sysiniValueB2(void)
 {
           node_id = 1;
           node_id_alt = 1;
    	   node_id_16bit = 0x1234;
    	   val_Pow_Nom=2000;
		   val_Pow_max=2000;
		   val_Spannung_min=3600;
		   val_Spannung_max=4200;
		   led_grupp=10;
		   led_Strom=0065;

    	   node_id_neu = 1;
 }

 void sysiniValueB4(void)
 {
	 Dimm_Gamma=10;
	 Dimm_Stufen=10;
	 Dimm_StufenGR=10;
	 Dimm_Valu=10;
	 Smooth_Value=10;
	 linearwalk_gen= 0xb0;
	 Farbe_wwcw_Quot_gen=0xffff;
	 Reserve_1=0;
	 Dimm_Max_WW=1000;
	 Dimm_Max_CW=1000;

	linearwalk_ww1 = linearwalk_gen;
	linearwalk_ww2 = linearwalk_gen;
	linearwalk_cw1 = linearwalk_gen;
	linearwalk_cw2 = linearwalk_gen;

	Farbe_ww1_Quot = Farbe_wwcw_Quot_gen>>8;
	Farbe_cw1_Quot = Farbe_wwcw_Quot_gen>>8;
	Farbe_ww2_Quot = Farbe_wwcw_Quot_gen & 0x00ff;
	Farbe_cw2_Quot = Farbe_wwcw_Quot_gen & 0x00ff;
 }

 void sysiniValueB5(void)
 {
	 RegOnOff = RegOnOff_OFFvalue;
	 RegOnOff2 = 0;
	 Reserve_2 = 0;
	 dimOff_Ww = 4095;
	 dimOff_Cw = 4095;
	 dimNorm1_Ww = 0x01ff;
	 dimNorm1_Cw = 0x01ff;
	 dimNorm2_Ww = 0x02ff;
	 dimNorm2_Cw = 0x02ff;
 }

 //-----------------------------------------------
 // BCCU Vorgaben

 void bcuInit(void)
 {
		switch  (RegOnOff)
		{
		case RegOnOff_0Proz : 		dimAkt_Ww = 0;
				 	 	 	 	 	dimAkt_Cw = 0;
									break;
		case RegOnOff_100Proz : 	dimAkt_Ww = 0x7fff;
				 	 	 	 	 	dimAkt_Cw = 0x7fff;
									break;
		case RegOnOff_N1value : 	dimAkt_Ww = dimNorm1_Ww;
				 	 	 	 	 	dimAkt_Cw = dimNorm1_Cw;
		case RegOnOff_N2value : 	dimAkt_Ww = dimNorm2_Ww;
				 	 	 	 	 	dimAkt_Cw = dimNorm2_Cw;
									break;
		case RegOnOff_OFFvalue : 	dimAkt_Ww = dimOff_Ww;
				 	 	 	 	 	dimAkt_Cw = dimOff_Cw;
									break;
		default:
									break;
		}

 }
 //----------------------------------

 void bcuUebergabe(void)
 {

//	 PDM_BCCU_AbortLinearWalk(&PDM_BCCU_0);
	//  PDM_BCCU_AbortLinearWalk(&PDM_BCCU_1);
	//  PDM_BCCU_AbortLinearWalk(&PDM_BCCU_2);
	//  PDM_BCCU_AbortLinearWalk(&PDM_BCCU_3);

 PDM_BCCU_SetIntensity(&PDM_BCCU_0,Farbe_ww2);
 PDM_BCCU_SetIntensity(&PDM_BCCU_1,Farbe_cw2);
 PDM_BCCU_SetIntensity(&PDM_BCCU_2,Farbe_ww1);
 PDM_BCCU_SetIntensity(&PDM_BCCU_3,Farbe_cw1);

 PDM_BCCU_SetLinearWalk(&PDM_BCCU_0,linearwalk_ww2); // Go to target intensity slowly
 PDM_BCCU_SetLinearWalk(&PDM_BCCU_1,linearwalk_cw2); // Go to target intensity slowly
 PDM_BCCU_SetLinearWalk(&PDM_BCCU_2,linearwalk_ww1); // Go to target intensity slowly
 PDM_BCCU_SetLinearWalk(&PDM_BCCU_3,linearwalk_cw1); // Go to target intensity slowly

 //PDM_BCCU_StartLinearWalk(&PDM_BCCU_0);
 //PDM_BCCU_StartLinearWalk(&PDM_BCCU_2);

 //PDM_BCCU_StartLinearWalk(&PDM_BCCU_1);
// PDM_BCCU_StartLinearWalk(&PDM_BCCU_3);
 }
 //----------------------------------


 //----------------------------------
 void bcuAktBerechnung(void)
  {
	 uint32_t 	VarA;

     Farbe_ww1_Quot = Farbe_wwcw_Quot_gen>>8;
     Farbe_cw1_Quot = Farbe_wwcw_Quot_gen>>8;
     Farbe_ww2_Quot = Farbe_wwcw_Quot_gen & 0xff;
     Farbe_cw2_Quot = Farbe_wwcw_Quot_gen & 0xff;

	 VarA = dimAkt_Ww * Farbe_ww1_Quot;
	 Farbe_ww1 = (VarA / 0x100) >>4;
	 VarA = dimAkt_Ww * Farbe_ww2_Quot;
	 Farbe_ww2 = (VarA / 0x100) >>4;

	 VarA = dimAkt_Cw * Farbe_cw1_Quot;
	 Farbe_cw1 = (VarA / 0x100) >>4;
	 VarA = dimAkt_Cw * Farbe_cw2_Quot;
	 Farbe_cw2 = (VarA / 0x100) >>4;
  }

 //----------------------------------  //n+l
 // direkte Lichtübergabe, 8 bit wert wird direkt übergeben ohne farbquotient
 // werte eingabe direkt in die variable  Farbe_ww1_Quot
 void bcudirAktBerechnung(void)

  {
	 uint32_t 	VarA;

	 Farbe_wwcw_Quot_gen=0xffff;
     Farbe_ww1_Quot = Farbe_wwcw_Quot_gen>>8;
     Farbe_cw1_Quot = Farbe_wwcw_Quot_gen>>8;
     Farbe_ww2_Quot = Farbe_wwcw_Quot_gen & 0xff;
     Farbe_cw2_Quot = Farbe_wwcw_Quot_gen & 0xff;

	 VarA = dimAkt_Ww * Farbe_ww1_Quot;
	 Farbe_ww1 = (VarA / 0x100) >>4;
	 VarA = dimAkt_Ww * Farbe_ww2_Quot;
	 Farbe_ww2 = (VarA / 0x100) >>4;

	 VarA = dimAkt_Cw * Farbe_cw1_Quot;
	 Farbe_cw1 = (VarA / 0x100) >>4;
	 VarA = dimAkt_Cw * Farbe_cw2_Quot;
	 Farbe_cw2 = (VarA / 0x100) >>4;
  }
 //----------------------------------

 void bcuColorBerechnung(void)
  {
	 uint32_t 	VarA;

	 dimAkt_Ww = 0xffff;
	 VarA = dimAkt_Ww * Brightness_Gen;
	 VarA = VarA>>16;
	 VarA = VarA * (0xffff - ColorQuot_Gen);
	 VarA = VarA>>16;
	 dimAkt_Ww = VarA;

	 dimAkt_Cw = 0xffff;
	 VarA = dimAkt_Cw * Brightness_Gen;
	 VarA = VarA>>16;
	 VarA = VarA * ColorQuot_Gen;
	 VarA = VarA>>16;
	 dimAkt_Cw = VarA;
  }
 //----------------------------------



 void Offlight_zahler_write(void)
 {
     uint8_t a;
	 if(RegOnOff == RegOnOff_OFFvalue)
	 {
	 zahler_offlight=zahler_offlight+1;

	  if(zahler_offlight >= con_zahler_offlight)
	  {
		     zahler_offlight=0;
			a = read_off_light_EEprom();
			if (a == 0x03)
			{
			dimOff_Ww = dimAkt_Ww;
			dimOff_Cw = dimAkt_Cw;

			 if ((ReadBuffer2[4] == (dimOff_Ww / 0x100)) && ( ReadBuffer2[5] == (dimOff_Ww & 0xff) ) && (ReadBuffer2[6] == (dimOff_Cw / 0x100)) && (ReadBuffer2[7] == (dimOff_Cw & 0xff)) )
			 {
		     zahler_offlight=0;
			 }
			 else{
		     ReadBuffer2[4] = dimOff_Ww / 0x100;
		     ReadBuffer2[5] = dimOff_Ww & 0xff;
		     ReadBuffer2[6] = dimOff_Cw / 0x100;
		     ReadBuffer2[7] = dimOff_Cw & 0xff;
		     a = writeOff_light_B5_EEprom();
		     zahler_offlight=0;
		    		//    DIGITAL_IO_ToggleOutput(&VCC_LED_shtdwn);
			 }
			}
			else {
			zahler_offlight = con_zahler_offlight/2;
			}

	   zahler_offlight=0;
	  }//zahler_offlight
	 }//regonoff
 }

 //----------------------------------------------------

 void plus39V_stop (void) // spannung ok
  {
	// 	DIGITAL_IO_SetOutputHigh(&xmc_sel_gain);


  }

 void plus39V_start (void) // spannung ok
  {
	// 	DIGITAL_IO_SetOutputHigh(&xmc_sel_gain);

  }

 //----------------------------------

  void Time1msec (void) //
  {
      ADC_MEASUREMENT_ADV_SoftwareTrigger(&ADC_MEASUREMENT_ADV_0);

  }
  //----------------------------------

   void Time20msec (void) //
   {

   //    DIGITAL_IO_ToggleOutput(&VCC_LED_shtdwn);
       resultA2 = (3*resultA2 + resultAalt)/4;
       resultB2 = (3*resultB2 + resultBalt)/4;
       resultC2 = (3*resultC2 + resultCalt)/4;
       resultD2 = (3*resultD2 + resultDalt)/4;
       adc_ready20m=adc_ready20m + 1;

      if (adc_ready20m > 5)
      {
     	//    DIGITAL_IO_ToggleOutput(&LED);
     	 adc_ready20m=0;
     	    if (resultA2 < min_EEP_Voltage_Uin)
     	     {
     	     plus39V_stop();
					B_nextLedOff=0;   // schaltet on led beim spannnungsvergleich aus
 	 		 	DIGITAL_IO_SetOutputLow(&VCC_LED_shtdwn);
     	     }
     	    else if (resultA2 > minHyst_EEP_Voltage_Uin)
 			 {
     	     plus39V_start();
				if(	B_nextLedOff==0)
 	 		 	{DIGITAL_IO_SetOutputHigh(&VCC_LED_shtdwn);}
 			 }
      }


   }
  //------------------------------

   void firstuartBack (void) //
   {	if ( B_first_uart == 0 )
   	   {
	   new_data_HalloBack();
	   new_data[5]= command_firstuartBack ;
   	   new_data[6]= Ser_NrH  / 0x100 ;
   	   new_data[7]= Ser_NrH  & 0xff ;
   	   new_data[8]= Ser_NrL  / 0x100 ;
   	   new_data[9]= Ser_NrL  & 0xff ;
   	   UART_Transmit(&UART_1, new_data,transmit_buf_size);
   	   B_first_uart=1;
   	   }
   }
   //------------------------------
