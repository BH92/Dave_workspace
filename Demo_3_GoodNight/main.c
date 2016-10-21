/*
 * main.c
 *kopiert aus test_20160605a_soft04nils
 *--> neu 2016 10 11
 *--> einarbeiten einer automatischen dimmfunktion
 *--> 1. Warm weiss kalt weiss dimmen
 *--> 2. hell dunkel mit warm weiss kaltweiss dimmung
 *--> Umsetzen als auswählfunktion mittels serieller eingabe
 *--> auswählen funktion, helligkeit,
 *  Created on: 2016 May 06 10:13:00
 *  Author: samuel
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <samuel/samuel_io.h>

     uint32_t tester;
     uint16_t tester1;
     uint16_t tester2;
     uint16_t tester3;
     uint16_t tester4;
     uint16_t tester5;
     uint16_t command_nr;
//	 uint8_t ww[2];
//	 uint8_t cw[2];

	 DAVE_STATUS_t Dstatus;


int main(void)
{
	uint32_t TimerId,status;
	uint32_t Timer1M,status1M;
	uint32_t Timer20M,status20M;

   Dstatus = DAVE_Init();  //(DAVE_STATUS_t)DIGITAL_IO_Init(&DIGITAL_IO_0) is called within DAVE_Init()
   if(Dstatus == DAVE_STATUS_SUCCESS)
   {
    XMC_DEBUG("DAVE Apps initialization success\n");
   }
   else
   {
    XMC_DEBUG(("DAVE Apps initialization failed with status %d\n", Dstatus));
    while(1U)
    {
    }
   }
   // Initialisierung
   // Übergabe werte
	sysiniValueB1();
	sysiniValueB2();
	sysiniValueB4();
sysiniValueB5();
	//  tester4 = writeOff_light_B5_EEprom();
	  tester = readSerNrEEprom();
	if (tester == 0x03)
	{
	Ser_NrH = ReadBuffer1[0] * 0x100 + ReadBuffer1[1];
	Ser_NrL = ReadBuffer1[2] * 0x100 + ReadBuffer1[3];
  Hard_Vers = ReadBuffer1[4] * 0x100 + ReadBuffer1[5];
  Soft_Vers = ReadBuffer1[6] * 0x100 + ReadBuffer1[7];
  GEH_Vers = ReadBuffer1[8] * 0x100 + ReadBuffer1[9];
  Mon_Vers = ReadBuffer1[10] * 0x100 + ReadBuffer1[11];
  LED_WW_Vers = ReadBuffer1[12] * 0x100 + ReadBuffer1[13];
  LED_CW_Vers = ReadBuffer1[14] * 0x100 + ReadBuffer1[15];

  neu_Ser_NrH = 0 ;
  neu_Ser_NrL = 0 ;

	}
	else
	{
	sysiniValueB1();
	}

tester = readNodeIdEEprom();
	if (tester == 0x03)
	{
		node_id_alt = ReadBuffer2[0] ;
		node_id = ReadBuffer2[1];
		node_id_16bit = ReadBuffer2[2] * 0x100 + ReadBuffer2[3];
		val_Pow_Nom = ReadBuffer2[4] * 0x100 + ReadBuffer2[5];
		val_Pow_max = ReadBuffer2[6] * 0x100 + ReadBuffer2[7];
		val_Spannung_min = ReadBuffer2[8] * 0x100 + ReadBuffer2[9];
		val_Spannung_max = ReadBuffer2[10] * 0x100 + ReadBuffer2[11];
		led_grupp = ReadBuffer2[12] * 0x100 + ReadBuffer2[13];
		led_Strom = ReadBuffer2[14] * 0x100 + ReadBuffer2[15];

  	   node_id_neu = 1;
	}
	else
	{
   sysiniValueB2();
	}

tester = read_akt_light_EEprom();
	if (tester == 0x03)
	{

		Dimm_Gamma = ReadBuffer2[0] ;
		Dimm_Stufen = ReadBuffer2[1];
		Dimm_StufenGR = ReadBuffer2[2] ;
		Dimm_Valu = ReadBuffer2[3];
		Smooth_Value = ReadBuffer2[4] * 0x100 + ReadBuffer2[5];
		linearwalk_gen = ReadBuffer2[6] * 0x100 + ReadBuffer2[7];
		Farbe_wwcw_Quot_gen = ReadBuffer2[8] * 0x100 + ReadBuffer2[9];
		Reserve_1 = ReadBuffer2[10] * 0x100 + ReadBuffer2[11];
		Dimm_Max_WW = ReadBuffer2[12] * 0x100 + ReadBuffer2[13];
		Dimm_Max_CW = ReadBuffer2[14] * 0x100 + ReadBuffer2[15];

	      linearwalk_ww1 = linearwalk_gen;
	      linearwalk_ww2 = linearwalk_gen;
	      linearwalk_cw1 = linearwalk_gen;
	      linearwalk_cw2 = linearwalk_gen;

	      Farbe_ww1_Quot = Farbe_wwcw_Quot_gen>>8;
	      Farbe_cw1_Quot = Farbe_wwcw_Quot_gen>>8;
	      Farbe_ww2_Quot = Farbe_wwcw_Quot_gen & 0xff;
	      Farbe_cw2_Quot = Farbe_wwcw_Quot_gen & 0xff;

	}
	else
	{
	sysiniValueB4();
	}

tester = read_off_light_EEprom();
	if (tester == 0x03)
	{

		RegOnOff = ReadBuffer2[0] ;
		RegOnOff2 = ReadBuffer2[1];
		Reserve_2  = ReadBuffer2[2] * 0x100 + ReadBuffer2[3];
		dimOff_Ww = ReadBuffer2[4] * 0x100 + ReadBuffer2[5];
		dimOff_Cw = ReadBuffer2[6] * 0x100 + ReadBuffer2[7];
		dimNorm1_Ww  = ReadBuffer2[8] * 0x100 + ReadBuffer2[9];
		dimNorm1_Cw = ReadBuffer2[10] * 0x100 + ReadBuffer2[11];
		dimNorm2_Ww = ReadBuffer2[12] * 0x100 + ReadBuffer2[13];
		dimNorm2_Cw = ReadBuffer2[14] * 0x100 + ReadBuffer2[15];



	}
	else
	{
	sysiniValueB5();
	}



		// Übergabe Variablen
	    new_data_fill();

		// Start Farbberechnungen

		  bcuInit();
		  linearwalk_gen = 100;
	      linearwalk_ww1 = linearwalk_gen;//n+l
	      linearwalk_ww2 = linearwalk_gen;//n+l
	      linearwalk_cw1 = linearwalk_gen;//n+l
	      linearwalk_cw2 = linearwalk_gen;  //n+l

			 dimAkt_Ww =  0x07ff;//n+l
			 dimAkt_Cw =  0x07ff;//n+l

	//n+l	  bcuAktBerechnung();
	//	  bcudirAktBerechnung();//n+l
	//	  bcuUebergabe();


   //Placeholder for user application code. The while loop below can be replaced with user application code.
   TimerId = SYSTIMER_CreateTimer(ONESEC,SYSTIMER_MODE_PERIODIC,(void*)LED_Toggle_EverySec,NULL);
    if(TimerId != 0U)
    {
      status = SYSTIMER_StartTimer(TimerId);
      if(status == SYSTIMER_STATUS_SUCCESS)
      {
        // Timer is running
      }
      else
      {
        // Error during software timer start operation
      }
    }
    else
    {
      // Timer ID Can not be zero
    }
    //____________________________________________

    Timer1M = SYSTIMER_CreateTimer(T1milliSEC,SYSTIMER_MODE_PERIODIC,(void*)Time1msec,NULL);
     if(Timer1M != 0U)
     {
       status1M = SYSTIMER_StartTimer(Timer1M);
       if(status1M == SYSTIMER_STATUS_SUCCESS)
       {
       }
       else
       {

       }
     }
     else
     {
     }
    //____________________________________________

     Timer20M = SYSTIMER_CreateTimer(T20milliSEC,SYSTIMER_MODE_PERIODIC,(void*)Time20msec,NULL);
      if(Timer20M != 0U)
      {
        status20M = SYSTIMER_StartTimer(Timer20M);
        if(status20M == SYSTIMER_STATUS_SUCCESS)
        {
        }
        else
        {

        }
      }
      else
      {
      }

	//START hardware ###################################################################################


    DIGITAL_IO_SetOutputHigh(&xmc_lin_en);
	DIGITAL_IO_SetOutputHigh(&VCC_LED_shtdwn);
   // analog_start () ;
    ADC_MEASUREMENT_ADV_SoftwareTrigger(&ADC_MEASUREMENT_ADV_0);






	//#############################################

	while(1U)
	{

		if(   UART_Receive(&UART_1, ReadData, 1) == UART_STATUS_SUCCESS)
		{
			while(UART_1.runtime->rx_busy)
		 	{
		 	}



			 //START UART ###################################################################################
			 if ( charcount == 0 && synclevel == 0 && ReadData[0] == 0x4C )
			 {
			 	charcount = 1;
			 	synclevel = 1;
			 }
			 else if (  charcount == 1 && synclevel == 1 && ReadData[0] == 0x49 )
			 {
			 	charcount = 2;
			 	synclevel = 2;
			 }
			 else if (  charcount ==2 && synclevel == 2 && ReadData[0] == 0x4E )
			 {
			 	charcount = 3;
			 	synclevel = 3;
			 }
			 else if (  charcount == 3 && synclevel == 3 )
			 {
			 	charcount = 4;
			 	node_id_resi = ReadData[0];
			 }
			 else if (  charcount == 4 && synclevel == 3 )
			 {
			 	charcount = 5;
			 	framelength = ReadData[0];
			 }
			 else if ( charcount == 5 && synclevel == 3 )
			 {
			 	charcount = 6;
		 		command = ReadData[0];
			 }
			 else if ( charcount == 6 && synclevel == 3 )
			 {
			 	charcount = 7;
			 	ReadData[1] = ReadData[0];
			 }
			 else if ( charcount == 7 && synclevel == 3 )
			 {
			 	charcount = 8;
			 	ReadData[2] = ReadData[0];
			 }
			 else if ( charcount == 8 && synclevel == 3 )
			 {
			 	charcount = 9;
			 	ReadData[3] = ReadData[0];
			 }
			 else if ( charcount == 9 && synclevel == 3 )
			 {
			 	charcount = 10;
			 	ReadData[4] = ReadData[0];
			 }
			 else if ( charcount == 10 && synclevel == 3 && ReadData[0] == 0xFF )
			 {
			 	charcount = 0;
			 	synclevel = 0;
			 	execute = 1;
			 }
			 else
			 {
			 	charcount = 0;
			 	synclevel = 0;
			 	execute = 0;
			 }
			 // END UART ###################################################################################
			 if ( execute == 1 )
		{
			 	if (node_id_resi != node_id)
			 {
				// ohne Node übereinstimmung
				switch  (command) {
				case command_BroadcastResi : 	new_data_BroadcastBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_all_ledOff_Resi :
											if (ReadData[1] == 5 && ReadData[2] == 5 &&   ReadData[3] ==  secure_all_ledOffH_Resi  &&  ReadData[4] == secure_all_ledOffL_Resi )
												{new_data_HalloBack();
	 	 	 	 	 							B_nextLedOff=1;   // schaltet on led beim spannnungsvergleich aus
												DIGITAL_IO_SetOutputLow(&VCC_LED_shtdwn);
												new_data[5]= command_all_ledOffBack ;
												new_data[6]= Ser_NrH  / 0x100 ;
												new_data[7]= Ser_NrH  & 0xff ;
												new_data[8]= Ser_NrL  / 0x100 ;
												new_data[9]= Ser_NrL  & 0xff ;

												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;
				case command_all_ledOn_Resi :
											if (ReadData[1] == 3 && ReadData[2] == 3 &&   ReadData[3] ==  secure_all_ledOnH_Resi  &&  ReadData[4] == secure_all_ledOnL_Resi )
												{new_data_HalloBack();

			  	 	 	 	 	 	 	 	 	B_nextLedOff=0;
												DIGITAL_IO_SetOutputHigh(&VCC_LED_shtdwn);
												new_data[5]= command_all_ledOnBack ;
												new_data[6]= Ser_NrH  / 0x100 ;
												new_data[7]= Ser_NrH  & 0xff ;
												new_data[8]= Ser_NrL  / 0x100 ;
												new_data[9]= Ser_NrL  & 0xff ;

												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;


				default: 						execute = 0;
				break;
				}
			 }
			 	else //node_id_resi = node_id)
			 {

				switch  (command) {

				case command_BroadcastResi : 	new_data_BroadcastBack();
											UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_ana1Resi  :
												new_data_analog1Back();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_ana2Resi  :
												new_data_analog2Back();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_aktLichtResi : 	dimAkt_Ww=ReadData[1]*0x100+ReadData[2];
												dimAkt_Cw=ReadData[3]*0x100+ReadData[4];

												bcuAktBerechnung();
											    bcuUebergabe();

												new_data_aktLichtBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_offLichtResi :
											dimOff_Ww=ReadData[1]*0x100+ReadData[2];
											dimOff_Cw=ReadData[3]*0x100+ReadData[4];

												new_data_offLichtBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_HalloResi : 		new_data_HalloBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_nextledOff_Resi : 		new_data_HalloBack();
	 	 	 	 	 							B_nextLedOff=1;   // schaltet on led beim spannnungsvergleich aus
												DIGITAL_IO_SetOutputLow(&VCC_LED_shtdwn);
												new_data[5]= command_nextledOffBack ;
												new_data[6]= Ser_NrH  / 0x100 ;
												new_data[7]= Ser_NrH  & 0xff ;
												new_data[8]= Ser_NrL  / 0x100 ;
												new_data[9]= Ser_NrL  & 0xff ;

												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_nextledOn_Resi : 		new_data_HalloBack();

			  	 	 	 	 	 	 	 	 	B_nextLedOff=0;
												DIGITAL_IO_SetOutputHigh(&VCC_LED_shtdwn);
												new_data[5]= command_nextledOnBack ;
												new_data[6]= Ser_NrH  / 0x100 ;
												new_data[7]= Ser_NrH  & 0xff ;
												new_data[8]= Ser_NrL  / 0x100 ;
												new_data[9]= Ser_NrL  & 0xff ;

												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;

				case command_Bright_Color_Resi :	Brightness_Gen=ReadData[1]*0x100+ReadData[2];
													ColorQuot_Gen=ReadData[3]*0x100+ReadData[4];


													bcuColorBerechnung();
													bcuAktBerechnung();
													  bcuUebergabe();
													  //DimmUebergabe();

													new_data_Bright_Color_Back();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;

				case command_Quot_Walk_Resi :	linearwalk_gen = ReadData[1]*0x100+ReadData[2];
												linearwalk_ww1 = linearwalk_gen;
												linearwalk_ww2 = linearwalk_gen;
												linearwalk_cw1 = linearwalk_gen;
												linearwalk_cw2 = linearwalk_gen;

												Farbe_wwcw_Quot_gen=ReadData[3]*0x100+ReadData[4];
												Farbe_ww1_Quot = ReadData[3];
												Farbe_cw1_Quot = ReadData[3];
												Farbe_ww2_Quot = ReadData[4];
												Farbe_cw2_Quot = ReadData[4];

												bcuAktBerechnung();
												  bcuUebergabe();
												 // DimmUebergabe();

													new_data_Quot_Walk_Back();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;





				case command_neuNodeIdResi :	if (ReadData[1] == ReadData[2] &&  Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]))
												{
												node_id_neu = ReadData[1];
												command_nr=0x30;
												new_data_neuNodeIdBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
												else {
												node_id_neu = node_id;
												command_nr=0x0;
												 new_data_HalloBack();
												 new_data[6]='e';
												 new_data[7]= 4;
												 new_data[8]= Ser_NrL  / 0x100 ;
												 new_data[9]= Ser_NrL  & 0xff ;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}

											break;

				case command_neuSerNrResi :
												command_nr = 0x45;
												neu_Ser_NrH  = ReadData[1] * 0x100 + ReadData[2];
												neu_Ser_NrL  = ReadData[3] * 0x100 + ReadData[4];
												new_data_neuSerNrBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											break;
				case command_SerNrResi :		tester = readSerNrEEprom();
												if (tester == 0x03)
												{
												Ser_NrH = ReadBuffer1[0] * 0x100 + ReadBuffer1[1];
												Ser_NrL = ReadBuffer1[2] * 0x100 + ReadBuffer1[3];
												new_data_SerNrBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
												else
												{
											    new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=10;
												new_data[8]=tester;
												new_data[9]=0;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}

											break;
				case command_NodeIdResi :		tester = readNodeIdEEprom();
												if (tester == 0x03)
												{
												node_id_alt = ReadBuffer2[0];
												node_id  = ReadBuffer2[1];
												node_id_16bit = ReadBuffer2[2] * 0xFF + ReadBuffer2[3];
												new_data_NodeIdBack();
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
												else
												{
											    new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=11;
												new_data[8]=tester;
												new_data[9]=0;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;

				case command_akt_lightEEResi :		tester = read_akt_light_EEprom();
												if (tester == 0x03)
												{
													new_data_readbuff2Back();
  		  											 new_data[6]=4;  // 4= akt_light buffertyp
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
												else
												{
											    new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=45;
												new_data[8]=tester;
												new_data[9]=0;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;
				case command_offlightEEResi :		tester = read_off_light_EEprom();
												if (tester == 0x03)
												{
													new_data_readbuff2Back();
  		  											 new_data[6]=5;  // 5= offlight buffertyp
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
												else
												{
											    new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=21;
												new_data[8]=tester;
												new_data[9]=0;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;

				case command_neuNodeIdWriteResi:
											if (command_nr == 0x47 && Ser_NrH == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
												{
												tester = readNodeIdEEprom();
												  if (tester == 0x03)
											      {
												  ReadBuffer2[0]= 	node_id; //highbyte
												  ReadBuffer2[1]= 	node_id_neu; //lowbyte
												  tester2 = writeNodeid_B2_EEprom();
												    if( tester2  == 0x03 )
											        {
														new_data_HalloBack();
														 new_data[6]='i';
														 new_data[7]='n';
														 new_data[8]=tester;
														 new_data[9]=tester2;
														UART_Transmit(&UART_1, new_data,transmit_buf_size);
											        }
												    else
												    {
													new_data_HalloBack();
														 new_data[6]='e';
														 new_data[7]=7;
														 new_data[8]=tester;
														 new_data[9]=tester2;
														UART_Transmit(&UART_1, new_data,transmit_buf_size);
												    }
											      }
												    else
												  {
												  new_data_HalloBack();
												  new_data[6]='e';
												  new_data[7]=8;
												  new_data[8]=tester;
												  new_data[9]=0;
												  UART_Transmit(&UART_1, new_data,transmit_buf_size);
												  }
												}
										        else
										        {
										         new_data_HalloBack();
										         new_data[6]='e';
										         new_data[7]=9;
										         new_data[8]=command_nr;
										         new_data[9]=0;
										         UART_Transmit(&UART_1, new_data,transmit_buf_size);
										         }

											break;

				case command_neuSerNrWriteResi:
											if (command_nr == 0x66 && Ser_NrH == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
											{
												tester2=0xff;
												tester = readSerNrEEprom();
											    if( tester  == 0x03 )

											    {
												 ReadBuffer1[0]= 	Ser_NrH  / 0x100; //highbyte
												 ReadBuffer1[1]= 	Ser_NrH  & 0xff; //lowbyte
												 ReadBuffer1[2]= 	Ser_NrL  / 0x100; //highbyte
												 ReadBuffer1[3]= 	Ser_NrL  & 0xff; //lowbyte
												 tester2 = writeSernr_B1_EEprom() ;
												new_data_HalloBack();
												new_data[6]='i';
												new_data[7]='n';
												new_data[8]=tester;
												new_data[9]=tester2;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											    }
											    else {
												new_data_HalloBack();
												 new_data[6]='e';
												 new_data[7]=17;
												 new_data[8]=tester;
												 new_data[9]=tester2;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
											    }
											}
											 else {
											new_data_HalloBack();
											new_data[6]='e';
											new_data[7]=18;
											new_data[8]=tester;
											new_data[9]=tester2;
											UART_Transmit(&UART_1, new_data,transmit_buf_size);
											 }
											break;
				case command_neuakt_lightWriteResi:
												if (Ser_NrH == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
												{
													    ReadBuffer2[0]=Dimm_Gamma;
													    ReadBuffer2[1]=Dimm_Stufen;
													    ReadBuffer2[2] = Dimm_StufenGR;
													    ReadBuffer2[3] = Dimm_Valu;
													    ReadBuffer2[4] = Smooth_Value / 0x100;
													    ReadBuffer2[5] = Smooth_Value & 0xff;
													    ReadBuffer2[6] = linearwalk_gen /0x100;
													    ReadBuffer2[7] = linearwalk_gen & 0xff;
													    ReadBuffer2[8] = Farbe_wwcw_Quot_gen / 0x100;
													    ReadBuffer2[9] = Farbe_wwcw_Quot_gen & 0xff;
													    ReadBuffer2[10] = Reserve_1 /0x100;
													    ReadBuffer2[11] = Reserve_1 & 0xff;
													    ReadBuffer2[12] = Dimm_Max_WW /0x100;
													    ReadBuffer2[13] = Dimm_Max_WW & 0xff;
													    ReadBuffer2[14] = Dimm_Max_CW /0x100;
													    ReadBuffer2[15] = Dimm_Max_CW & 0xff;

												   if (resultB2 > min_EEP_Voltage_Uin)
												   {
											        tester2 = writeakt_light_data_B4_EEprom();
													new_data_HalloBack();
													new_data[6]='i';
													new_data[7]='n';
													new_data[8]=0;
													new_data[9]=tester2;
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												   }
												    else {
													new_data_HalloBack();
													 new_data[6]='e';
													 new_data[7]=75;
													 new_data[8]=0;
													 new_data[9]=tester2;
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												    }
												}
												 else {
												new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=28;
												new_data[8]=0;
												new_data[9]=tester2;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												 }
												break;
				case command_neuofflightWriteResi:
												if (Ser_NrH == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
												{
													    ReadBuffer2[0]=RegOnOff;
													    ReadBuffer2[1]=RegOnOff2;
													    ReadBuffer2[2] = Reserve_2 / 0x100;
													    ReadBuffer2[3] = Reserve_2 & 0xff;
													    ReadBuffer2[4] = dimOff_Ww / 0x100;
													    ReadBuffer2[5] = dimOff_Ww & 0xff;
													    ReadBuffer2[6] = dimOff_Cw / 0x100;
													    ReadBuffer2[7] = dimOff_Cw & 0xff;
													    ReadBuffer2[8] = dimNorm1_Ww / 0x100;
													    ReadBuffer2[9] = dimNorm1_Ww & 0xff;
													    ReadBuffer2[10] = dimNorm1_Cw / 0x100;
													    ReadBuffer2[11] = dimNorm1_Cw & 0xff;
													    ReadBuffer2[12] = dimNorm2_Ww / 0x100;
													    ReadBuffer2[13] = dimNorm2_Ww & 0xff;
													    ReadBuffer2[14] = dimNorm2_Cw / 0x100;;
													    ReadBuffer2[15] = dimNorm2_Cw & 0xff;

												   if (resultB2 > min_EEP_Voltage_Uin)
												   {
											        tester2 = writeOff_light_B5_EEprom();
													new_data_HalloBack();
													new_data[6]='i';
													new_data[7]='n';
													new_data[8]=0;
													new_data[9]=tester2;
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												   }
												    else {
													new_data_HalloBack();
													 new_data[6]='e';
													 new_data[7]=27;
													 new_data[8]=0;
													 new_data[9]=tester2;
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												    }
												}
												 else {
												new_data_HalloBack();
												new_data[6]='e';
												new_data[7]=28;
												new_data[8]=0;
												new_data[9]=tester2;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												 }
												break;


				case command_neuNodeConResi:
												if (command_nr == 0x30 &&  Ser_NrH  == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
				                                { command_nr = command_nr + 0x17;
				                                node_id = node_id_neu;

												new_data_HalloBack();
												 new_data[6]='i';
												 new_data[7]= command_nr;
												 new_data[8]= Ser_NrL  / 0x100 ;
												 new_data[9]= Ser_NrL  & 0xff ;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
				                                }
												else
												{
												 new_data_HalloBack();
												 new_data[6]='e';
												 new_data[7]= command_nr;
												 new_data[8]= Ser_NrL  / 0x100 ;
												 new_data[9]= Ser_NrL  & 0xff ;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;
				case command_neuSerNrConResi:
												if (command_nr == 0x45 &&  Ser_NrH  == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
				                                { command_nr = command_nr + 0x21;
				                                Ser_NrH=neu_Ser_NrH;
				                                Ser_NrL=neu_Ser_NrL;

												new_data_HalloBack();
												 new_data[6]='i';
												 new_data[7]= command_nr;
												 new_data[8]= Ser_NrL  / 0x100 ;
												 new_data[9]= Ser_NrL  & 0xff ;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
				                                }
												else
												{
												 new_data_HalloBack();
												 new_data[6]='e';
												 new_data[7]= command_nr;
												 new_data[8]= Ser_NrL  / 0x100 ;
												 new_data[9]= Ser_NrL  & 0xff ;
												UART_Transmit(&UART_1, new_data,transmit_buf_size);
												}
											break;
				case command_eprommInitResi :
										if (node_id_neu == 254 &&  Ser_NrH == 0x7b7a && Ser_NrH  == (ReadData[1] * 0x100 + ReadData[2]) && Ser_NrL == 0x5859 && Ser_NrL  == (ReadData[3] * 0x100 + ReadData[4]) )
										{
											 if(Dstatus == DAVE_STATUS_SUCCESS)
											 {
												 if (resultB2 > min_EEP_Voltage_Uin)
												 {
											//    	XMC_FLASH_ErasePages( (uint32_t*)E_EEPROM_XMC1_FLASH_BANK0_BASE,16);
													clearEpromBuffer();
													sysiniValueB1();

													 ReadBuffer1[0]= 	Ser_NrH  / 0x100; //highbyte
													 ReadBuffer1[1]= 	Ser_NrH  & 0xff; //lowbyte
													 ReadBuffer1[2]= 	Ser_NrL  / 0x100; //highbyte
													 ReadBuffer1[3]= 	Ser_NrL  & 0xff; //lowbyte
													 ReadBuffer1[4]= 	Hard_Vers  / 0x100; //highbyte
													 ReadBuffer1[5]= 	Hard_Vers  & 0xff; //lowbyte
													 ReadBuffer1[6]= 	Soft_Vers  / 0x100; //highbyte
													 ReadBuffer1[7]= 	Soft_Vers  & 0xff; //lowbyte
													 ReadBuffer1[8]= 	GEH_Vers  / 0x100; //highbyte
													 ReadBuffer1[9]= 	GEH_Vers  & 0xff; //lowbyte
													 ReadBuffer1[10]= 	Mon_Vers  / 0x100; //highbyte
													 ReadBuffer1[11]= 	Mon_Vers  & 0xff; //lowbyte
													 ReadBuffer1[12]= 	LED_WW_Vers  / 0x100; //highbyte
													 ReadBuffer1[13]= 	LED_WW_Vers  & 0xff; //lowbyte
													 ReadBuffer1[14]= 	LED_CW_Vers  / 0x100; //highbyte
													 ReadBuffer1[15]= 	LED_CW_Vers  & 0xff; //lowbyte

													 if (resultB2 > min_EEP_Voltage_Uin)
													 {	tester1 = writeSernr_B1_EEprom();
													 }
														sysiniValueB2();
													 ReadBuffer2[0]= 	node_id_alt; //highbyte
													 ReadBuffer2[1]= 	node_id; //lowbyte
													 ReadBuffer2[2]= 	node_id_16bit  / 0x100; //highbyte
													 ReadBuffer2[3]= 	node_id_16bit   & 0xff; //highbyte
													 ReadBuffer2[4]= 	val_Pow_Nom  / 0x100; //highbyte
													 ReadBuffer2[5]= 	val_Pow_Nom  & 0xff; //lowbyte
													 ReadBuffer2[6]= 	val_Pow_max  / 0x100; //highbyte
													 ReadBuffer2[7]= 	val_Pow_max  & 0xff; //lowbyte
													 ReadBuffer2[8]= 	val_Spannung_min / 0x100; //highbyte
													 ReadBuffer2[9]= 	val_Spannung_min  & 0xff; //lowbyte
													 ReadBuffer2[10]= 	val_Spannung_max  / 0x100; //highbyte
													 ReadBuffer2[11]= 	val_Spannung_max  & 0xff; //lowbyte
													 ReadBuffer2[12]= 	led_grupp  / 0x100; //highbyte
													 ReadBuffer2[13]= 	led_grupp  & 0xff; //lowbyte
													 ReadBuffer2[14]= 	led_Strom  / 0x100; //highbyte
													 ReadBuffer2[15]= 	led_Strom  & 0xff; //lowbyte

													 if (resultB2 > min_EEP_Voltage_Uin)
													 {
													 tester2 = writeNodeid_B2_EEprom();
													 }
														sysiniValueB4();
													ReadBuffer2[0]= 	Dimm_Gamma; //highbyte
													ReadBuffer2[1]= 	Dimm_Stufen; //lowbyte
													ReadBuffer2[2]= 	Dimm_StufenGR  ; //highbyte
													ReadBuffer2[3]= 	Dimm_Valu   ; //highbyte
													ReadBuffer2[4]= 	Smooth_Value  / 0x100; //highbyte
													ReadBuffer2[5]= 	Smooth_Value  & 0xff; //lowbyte
													ReadBuffer2[6]= 	linearwalk_gen  / 0x100; //highbyte
													ReadBuffer2[7]= 	linearwalk_gen  & 0xff; //lowbyte
													ReadBuffer2[8]= 	Farbe_wwcw_Quot_gen / 0x100; //highbyte
													ReadBuffer2[9]= 	Farbe_wwcw_Quot_gen  & 0xff; //lowbyte
													ReadBuffer2[10]= 	Reserve_1  / 0x100; //highbyte
													ReadBuffer2[11]= 	Reserve_1  & 0xff; //lowbyte
													ReadBuffer2[12]= 	Dimm_Max_WW  / 0x100; //highbyte
													ReadBuffer2[13]= 	Dimm_Max_WW  & 0xff; //lowbyte
													ReadBuffer2[14]= 	Dimm_Max_CW  / 0x100; //highbyte
													ReadBuffer2[15]= 	Dimm_Max_CW & 0xff; //lowbyte

											       if (resultB2 > min_EEP_Voltage_Uin)
													 {
													tester3 = writeakt_light_data_B4_EEprom();
													 }
													sysiniValueB5();
													    ReadBuffer2[0]=RegOnOff;
													    ReadBuffer2[1]=RegOnOff2;
													    ReadBuffer2[2] = Reserve_2 / 0x100;
													    ReadBuffer2[3] = Reserve_2 & 0xff;
													    ReadBuffer2[4] = dimOff_Ww / 0x100;
													    ReadBuffer2[5] = dimOff_Ww & 0xff;
													    ReadBuffer2[6] = dimOff_Cw / 0x100;
													    ReadBuffer2[7] = dimOff_Ww & 0xff;
													    ReadBuffer2[8] = dimNorm1_Ww /0x100;
													    ReadBuffer2[9] = dimNorm1_Ww & 0xff;
													    ReadBuffer2[10] = dimNorm1_Cw /0x100;
													    ReadBuffer2[11] = dimNorm1_Cw & 0xff;
													    ReadBuffer2[12] = dimNorm2_Ww / 0x100;
													    ReadBuffer2[13] = dimNorm2_Ww & 0xff;
													    ReadBuffer2[14] = dimNorm2_Cw /0x100;
													    ReadBuffer2[15] = dimNorm2_Cw & 0xff;

												 if (resultB2 > min_EEP_Voltage_Uin)
												 {
											      tester4 = writeOff_light_B5_EEprom();
												 }
												 tester = writeLamp_data_B3_EEprom();
												 if (tester1==0x03)
											 	 {
													new_data_HalloBack();
												  	 transmit_buf_size=12;
													 new_data[6]='i';
													 new_data[7]=tester1;
													 new_data[8]=tester2;
													 new_data[9]=tester3;
													 new_data[10]=tester4;
													 new_data[11]=0xff;
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												  }
													else
													{new_data_HalloBack();
												  	 transmit_buf_size=13;
													 new_data[6]='e';
													 new_data[7]=15;
													 new_data[8]=tester1;
													 new_data[9]=tester2;
													 new_data[10]=tester3;
													 new_data[11]=tester4;
													 new_data[12]=0xff;
													 UART_Transmit(&UART_1, new_data,transmit_buf_size);
													}
											 } //if result

												 else{
													new_data_HalloBack();
													 new_data[6]='e';
													 new_data[7]='r';
													 new_data[8]='0';
													 new_data[9]='3';
													UART_Transmit(&UART_1, new_data,transmit_buf_size);
												  }
										 }//if status
											else {
											new_data_HalloBack();     // vorgabewerte stimmen nicht
											 new_data[6]='e';
											 new_data[7]='r';
											 new_data[8]='0';
											 new_data[9]='2';
											 UART_Transmit(&UART_1, new_data,transmit_buf_size);
											}
									 }//if sernr
											else {
											new_data_HalloBack();     // vorgabewerte stimmen nicht
											 new_data[6]='e';
											 new_data[7]='r';
											 new_data[8]='0';
											 new_data[9]='1';
											 UART_Transmit(&UART_1, new_data,transmit_buf_size);
											}
											break;

				default:
				break;
				}//switch
			  } // else node id == ok

				//############
				execute = 0;
			} // if ( execute == 1 )
		} // if(UART_Receive(&UART_1, ReadData, 1) == UART_STATUS_SUCCESS)
	}





   while(1U)
   {
	   tester =  tester + 1;
	   tester =  digitalo();

	 //    resultA = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_Channel_A);
	 //    resultB = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_Channel_B);

	  //   XMC_UNUSED_ARG(resultA);
	  //   XMC_UNUSED_ARG(resultB);
	 //  analog_start () ; //  ADC_MEASUREMENT_ADV_SoftwareTrigger(&ADC_MEASUREMENT_ADV_0);
		UART_Transmit(&UART_1, rec_data, sizeof(rec_data));
   }
   return (1U);
 }

//----------------------------------------------------------------------------------------
void endofTransmitU1()//Callback functin for "End of transmit" event.
 {
 // UART_Receive(&UART_0, rec_data, sizeof(rec_data));
	  // DIGITAL_IO_ToggleOutput(&VCC_LED_shtdwn);
 }
//----------------------------------------------------------------------------------------
 void endofReceiveU1()//Callback function for "End of receive" event.
 {
	//   DIGITAL_IO_ToggleOutput(&DO_SEL_Gain);  //	 LED_Toggle_EverySec( );
	//UART_Transmit(&UART_0, rec_data, sizeof(rec_data));
 }
 //----------------------------------------------------------------------------------------
 void endofTransmitU0()//Callback functin for "End of transmit" event.
  {
 //a  UART_Receive(&UART_1, rec_data, sizeof(rec_data));
	 //a	  DIGITAL_IO_ToggleOutput(&DO_LED_Shtdwn);
  }
 //----------------------------------------------------------------------------------------
  void endofReceiveU0()//Callback function for "End of receive" event.
  {
 	  // DIGITAL_IO_ToggleOutput(&DO_SEL_Gain);  //	 LED_Toggle_EverySec( );
	  //a UART_Transmit(&UART_1, rec_data, sizeof(rec_data));
  }
 //----------------------------------------------------------------------------------------
  void adcIRQHandler(void)
  {
        // read the results of the conversion
        resultA = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_U_in);
        resultAalt = (resultA + 3*resultAalt)/4;
        resultB = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_ntc);
        resultBalt = (resultB + 3*resultBalt)/4;
        resultC = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_I_ww);
        resultCalt = (resultC + 3*resultCalt)/4;
        resultD = ADC_MEASUREMENT_ADV_GetResult(&ADC_MEASUREMENT_ADV_0_xmc_I_cw);
        resultDalt = (resultD + 3*resultDalt)/4;
        adc_ready=adc_ready + 1;
        //Start the next round of conversion
      //  ADC_MEASUREMENT_ADV_SoftwareTrigger(&ADC_MEASUREMENT_ADV_0);
  }
