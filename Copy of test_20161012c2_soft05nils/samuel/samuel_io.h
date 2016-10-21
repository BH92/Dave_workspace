/*
 *
 * @file samuel_io.h
 * @date 2015-12-22
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
 *     - Initial version
 *
 * 2015-04-22
 *     - XMC_ASSERT is added in static inline functions.<br>
 *
 * 2015-06-20
 *     - Version check added for XMCLib dependency.<br>
 *
 * 2015-12-22
 *     - Added hardware controlled IO feature.
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#ifndef SAMUEL_IO_H
#define SAMUEL_IO_H

#include "xmc_common.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
 #define ONESEC 1000000U
 	 #define 	T100mikroSEC 	100U
 	 #define 	T1milliSEC 	1000U
 	 #define 	T20milliSEC 	20000U


	#define	command_code01	'L'	//
	#define	command_code02	'I'	//
	#define	command_code03	'N'	//
	#define	command_codeEnd	0xff	//

	#define	command_firstuartBack '0'	//
 	 #define	command_unbekanntBack	'1'	//

	#define	command_ana1Back	'a'	//
	#define	command_ana2Back	'b'	//
	#define	command_aktLichtBack	'f'	//
	#define	command_offLichtBack	'g'	//
	#define	command_Bright_Color_Back	'h'	//
	#define	command_Quot_Walk_Back	'i'	//	Linearwalk CWWW + quotient cw1/2 ww1/2, übergabe16bit
	#define	command_HalloBack	'j'	//
	#define	command_neuNodeIdBack	'k'	//
	#define	command_neuSerNrBack	'l'	//
	#define	command_NodeIdBack	'm'	//
	#define	command_SerNrBack	'n'	//
	#define	command_BroadcastBack	'o'	//
	#define	command_readbuff2Back	'p'	//
	#define	command_nextledOffBack  	'r'	//
	#define	command_nextledOnBack 	's'	//
	#define	command_all_ledOffBack 	't'	//
	#define	command_all_ledOnBack 	'u'	//


	#define	command_ana1Resi	'A'	//
	#define	command_ana2Resi	'B'	//
	#define	command_aktLichtResi	'F'	//
	#define	command_offLichtResi	'G'	//
	#define	command_Bright_Color_Resi	'H'	//	übergabe Helligkeit und color 16bit
	#define	command_Quot_Walk_Resi	'I'	//	 Linearwalk CWWW + quotient cw1/2 ww1/2, übergabe16bit
	#define	command_HalloResi	'J'	//
	#define	command_neuNodeIdResi	'K'	//
	#define	command_neuSerNrResi	'L'	//
	#define	command_NodeIdResi	'M'	//
	#define	command_SerNrResi	'N'	//
	#define	command_BroadcastResi	'O'	//
	#define	command_akt_lightEEResi	'P'	//

	#define	command_offlightEEResi 	'Q'	//
	#define	command_nextledOff_Resi 	'R'	//
	#define	command_nextledOn_Resi 	'S'	//

	#define	command_all_ledOff_Resi 	'T'	//
	#define	command_all_ledOn_Resi 	'U'	//
	#define	secure_all_ledOffH_Resi 0x34
	#define	secure_all_ledOffL_Resi 0x78
	#define	secure_all_ledOnH_Resi 0xf5
	#define	secure_all_ledOnL_Resi 0xc5


	#define	command_eprommInitResi	'3'	//
	#define	command_neuNodeIdWriteResi	'4'	//
	#define	command_neuSerNrWriteResi	'5'	//
	#define	command_neuNodeConResi	 '7'	//	eingabe	bestätige neue nodeID + zeige akt serNR in wert1-4
	#define	command_neuSerNrConResi	 '8'	//	eingabe	bestätige neue SerNr + zeige akt serNR in wert1-4
	#define	command_neuofflightWriteResi '9'	//	eingabe
	#define	command_neuakt_lightWriteResi '<'	//	eingabe




//EEpromm blöcke
	#define block_serial_first_data 16  // 16 bytelang   serNrH-SerNrL- -alte serNrH-SerNrL -- erstelldatum -- hardware version nr
	#define block_node_data_data 16  // 16 bytelang   nodeId_alt-nodeId-nodeId_neu--leuchtentyp ( länge,Leistung,farbe)
	#define block_lamp_data_data 32
	#define block_akt_light_data_data_data 16
	#define block_off_light_data_data_data 16
//case für RegOnOff
	#define  RegOnOff_0Proz	1	//	off wert =0
	#define  RegOnOff_100Proz	2	//	off wert =100%
	#define  RegOnOff_N1value	3	//	off wert = N1 wert
	#define  RegOnOff_N2value	4	//	off wert = N2 wert
	#define  RegOnOff_OFFvalue	5	//	off wert = wird automatisch aus dem letzten wert  (>10min und > 5% Dimmung) in den EEpromgeschrieben
	#define  con_zahler_offlight	60 // sekunden bis zum abspeichern
// adc
	#define	min_EEP_Voltage_Uin	0x0ba0	//	geringste spannung zum schreiben auf eeprom 37,15V  abschalten
	#define	minHyst_EEP_Voltage_Uin	0x0bf0	//	geringste spannung zum schreiben auf eeprom 38,15V  anschalten
	//	d3c 40,14
	//	cea 40,14
	//	c99 39,36
	//	c45 38,61
	//	bf6 37,62
	//	ba6 36,62

/**********************************************************************************************************************
* ENUMS
**********************************************************************************************************************/
enum onOffLight {
	Black, NormWert1, NormWert2, letztWert, weiss
};


/**********************************************************************************************************************
* variablen
**********************************************************************************************************************/
 uint16_t adc_ready,adc_ready20m;
 uint16_t resultA,resultB,resultC,resultD;
 uint16_t resultA2,resultB2,resultC2,resultD2;
 uint16_t resultAalt,resultBalt,resultCalt,resultDalt;

 uint16_t resultAalt2,resultBalt2,resultCalt2,resultDCalt2;


uint32_t delay_count;
      uint16_t zahler_offlight;
      uint16_t zahler_lightprog01;//n+l

       //ValueB1

              uint16_t Ser_NrH ;
              uint16_t Ser_NrL  ;
              uint16_t Hard_Vers ;
              uint16_t Soft_Vers  ;
              uint16_t GEH_Vers ;
              uint16_t Mon_Vers ;
              uint16_t LED_WW_Vers ;
              uint16_t LED_CW_Vers  ;

              uint16_t neu_Ser_NrH ;
              uint16_t neu_Ser_NrL;
       //ValueB2

              uint8_t node_id ;
              uint8_t node_id_alt ;
              uint16_t node_id_16bit ;
              uint16_t val_Pow_Nom;
              uint16_t val_Pow_max;
              uint16_t val_Spannung_min;
              uint16_t val_Spannung_max;
              uint16_t led_grupp;
              uint16_t led_Strom;

              uint8_t  node_id_resi;
              uint8_t node_id_neu ;
       //ValueB4

              uint8_t Dimm_Gamma;
              uint8_t Dimm_Stufen;
              uint8_t Dimm_StufenGR;
              uint8_t Dimm_Valu;
              uint16_t Smooth_Value;
              uint16_t linearwalk_gen;
              uint16_t Farbe_wwcw_Quot_gen;
              uint16_t Reserve_1;
              uint16_t Dimm_Max_WW;
              uint16_t Dimm_Max_CW;

              uint16_t dimAkt_Ww; //aktuell wert Licht
              uint16_t dimAkt_Cw; //aktuell wert Licht

              uint16_t linearwalk_gen;
              uint16_t linearwalk_ww1;
              uint16_t linearwalk_ww2;
              uint16_t linearwalk_cw1;
              uint16_t linearwalk_cw2;

              uint16_t Farbe_ww1_Quot;
              uint16_t Farbe_cw1_Quot;
              uint16_t Farbe_ww2_Quot;
              uint16_t Farbe_cw2_Quot;

         	 uint16_t 	Farbe_ww1;	//	nur intern ausgabe wert 12bit vorne
         	 uint16_t 	Farbe_ww2;	//	nur intern ausgabe wert 12bit hinten
          	 uint16_t 	Farbe_cw1;	//	nur intern ausgabe wert 12bit vorne
         	 uint16_t 	Farbe_cw2;	//	nur intern ausgabe wert 12bit hinten

       //ValueB5
              uint8_t RegOnOff;
              uint8_t RegOnOff2;
              uint16_t Reserve_2;
              uint16_t dimOff_Ww;
              uint16_t dimOff_Cw;
              uint16_t dimNorm1_Ww;
              uint16_t dimNorm1_Cw;
              uint16_t dimNorm2_Ww;
              uint16_t dimNorm2_Cw;

          	 uint16_t Brightness_Gen;	//	Helligkeit Generell Multiplikator zu aktFarbe : akt Farbe sollt möglichst oxffff sein
         	 uint16_t ColorQuot_Gen;	//	Verhältniss WW zu CW Generell Multiplikator : akt Farbe sollt möglichst oxffff sein


       uint8_t rec_data[16];
       uint8_t new_data[16];
       uint16_t eeprom_data[16];

    uint8_t  transmit_buf_size;

  // serielle abfrage
       uint8_t ReadData[8];
        uint8_t execute;
        uint8_t charcount;
        uint8_t synclevel;
       uint8_t command;
       uint8_t framelength;

   //eprom data


	 uint8_t Index;
	 uint8_t ReadBuffer1[16];
	 uint8_t ReadBuffer2[16];
	 uint8_t ReadBuffer3[32];
	 uint8_t data_buffer[100];

	 uint16_t ReadBuffer4[16];

	 //BCCU
	 uint8_t B_first_uart;  //  wenn 1 dann wird einmalig eine hallo nachricht gesendet
	 uint8_t B_nextLedOff;  // wenn 1 dann wird next led per command geschaltet

/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/




/***********************************************************************************************************************
 * API Prototypes
 **********************************************************************************************************************/
	   int digitalo (void);

	   void LED_Toggle_EverySec(void);
	   void analog_start (void);
	   void lightprog01 (void);
	   void light_aus (void);
	   void plus39V_stop (void);
	   void plus39V_start (void);
	//   void baldachin_init (void);
	   void Time1msec (void);
	   void Time20msec (void);


    //   void UserIRQHandler(void);
	   void new_data_fill(void);

	  void new_data_unbekanntBack(void);
	  void new_data_BroadcastBack(void);


	  void new_data_analog1Back(void);
	  void new_data_analog2Back(void);
	  void new_data_aktLichtBack(void);
	  void new_data_offLichtBack(void);
	  void new_data_Bright_Color_Back(void);
	  void new_data_Quot_Walk_Back(void);
	  void new_data_HalloBack(void);
	  void new_data_neuNodeIdBack(void);
	  void new_data_neuSerNrBack(void);
	   void new_data_NodeIdBack(void);
	 void new_data_SerNrBack(void);
	   void new_data_readbuff2Back(void);
	// Eprom Api
		  void clearEpromBuffer(void);
	  void fillEpromBuffer(void);
	  void fill2EpromBuffer(void);




	  int readAllEEprom(void);
	  int readSerNrEEprom(void);
	  int readNodeIdEEprom(void);
	  int read_akt_light_EEprom(void);
	  int read_off_light_EEprom(void);
	  int writeSernr_B1_EEprom(void);
	  int writeNodeid_B2_EEprom(void) ;

	  int writeLamp_data_B3_EEprom(void);//writeLamp_data_B3_EEprom
	  int writeakt_light_data_B4_EEprom(void);
	  int writeOff_light_B5_EEprom(void);



	  void sysiniValueB1(void);
	  void sysiniValueB2(void);

	  void sysiniValueB4(void);
	  void sysiniValueB5(void);
	  void sysini(void);

	  void bcuInit(void);
	  void bcuUebergabe(void);

	  void bcuAktBerechnung(void);
	  void bcudirAktBerechnung(void);
	  void bcuColorBerechnung(void);


	  void Offlight_zahler_write(void);
	//  void new_datawe(void);
	   void firstuartBack (void);
/***********************************************************************************************************************
 * End
 **********************************************************************************************************************/
#endif /* SAMUEL_IO_H */
