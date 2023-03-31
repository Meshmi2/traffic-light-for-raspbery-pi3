// TRAFFIC LIGHT ON RPI3 BUILD WITH FLOWCODE
#define MX_RPI

#define MX_CAL_RPI

#define MX_CLK_SPEED 76800000

#define FCP_NULL Unconnected_Port


#define MX_CAL_RPI
#define	MX_REGISTER_MAP_BASE	0x3F000000


/*========================================================================*\
   Use :Include the type definitions
\*========================================================================*/
#include "C:\ProgramData\MatrixTSL\FlowcodeV8\CAL\internals.c"





/*========================================================================*\
   Use :panel
       :Variable declarations
       :Macro function declarations
\*========================================================================*/
#define FCV_FALSE (0)
#define FCV_TRUE (1)


/*========================================================================*\
   Use :component_label1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/
void FCD_03d93_led_base1__TurnOn();
void FCD_03d93_led_base1__TurnOff();

/*========================================================================*\
   Use :component_label1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/
void FCD_03d92_led_base1__TurnOn();
void FCD_03d92_led_base1__TurnOff();

/*========================================================================*\
   Use :component_label1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Variable declarations
       :Macro function declarations
\*========================================================================*/
void FCD_03d91_led_base1__TurnOn();
void FCD_03d91_led_base1__TurnOff();

/*========================================================================*\
   Use :Include the chip adaption layer
\*========================================================================*/
#include "C:\ProgramData\MatrixTSL\FlowcodeV8\CAL\includes.c"


/*========================================================================*\
   Use :component_label1
       :Macro implementations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Macro implementations
\*========================================================================*/
/*=----------------------------------------------------------------------=*\
   Use :Turn the LED off.
\*=----------------------------------------------------------------------=*/
void FCD_03d93_led_base1__TurnOn()
{

	#if (1)

		SET_PORT_PIN(G, 22, 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}

/*=----------------------------------------------------------------------=*\
   Use :Turn the LED on.
\*=----------------------------------------------------------------------=*/
void FCD_03d93_led_base1__TurnOff()
{

	#if (1)

		SET_PORT_PIN(G, 22, 1 - 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}


/*========================================================================*\
   Use :component_label1
       :Macro implementations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Macro implementations
\*========================================================================*/
/*=----------------------------------------------------------------------=*\
   Use :Turn the LED off.
\*=----------------------------------------------------------------------=*/
void FCD_03d92_led_base1__TurnOn()
{

	#if (1)

		SET_PORT_PIN(G, 27, 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}

/*=----------------------------------------------------------------------=*\
   Use :Turn the LED on.
\*=----------------------------------------------------------------------=*/
void FCD_03d92_led_base1__TurnOff()
{

	#if (1)

		SET_PORT_PIN(G, 27, 1 - 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}


/*========================================================================*\
   Use :component_label1
       :Macro implementations
\*========================================================================*/

/*========================================================================*\
   Use :led_base1
       :Macro implementations
\*========================================================================*/
/*=----------------------------------------------------------------------=*\
   Use :Turn the LED off.
\*=----------------------------------------------------------------------=*/
void FCD_03d91_led_base1__TurnOn()
{

	#if (1)

		SET_PORT_PIN(G, 17, 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}

/*=----------------------------------------------------------------------=*\
   Use :Turn the LED on.
\*=----------------------------------------------------------------------=*/
void FCD_03d91_led_base1__TurnOff()
{

	#if (1)

		SET_PORT_PIN(G, 17, 1 - 1);

	// #else

	//Code has been optimised out by the pre-processor
	#endif

}


/*========================================================================*\
   Use :panel
       :Macro implementations
\*========================================================================*/


/*========================================================================*\
   Use :Main
\*========================================================================*/
int main()
{
	if ((gpio = FC_CAL_GetRegisterMap(MX_REGISTER_MAP_GPIO)) == MAP_FAILED) return -1 ;
	FC_CAL_PullupsOff();
#ifdef USE_FLOWCODE_ICD2
	// Set pullups on ICD Clock and Data GPIO pins
	MX_GPIO_PULL = 2;
	FCI_DELAYBYTE_US(100);
	MX_GPIO_PULLCLK0 = (1 << MX_ICD_DATA_GPIO) | (1 << MX_ICD_CLK_GPIO);
	FCI_DELAYBYTE_US(100);
	MX_GPIO_PULLCLK0 = 0;
	// ICD Startup
	dbg_mode = 0x08;
	ICD_PUSH(0);
	FC_MARKER(1);
	FC_MARKER(1);
	ICD_POP();
#endif


	// Name: Loop, Type: Loop: While 1
	while (1)
	{

		// Name: Delay, Type: Delay: 1 s
		FCI_DELAYBYTE_S(1);

		// Name: Output, Type: Output: true -> G17
		SET_PORT_PIN(G,17,(FCV_TRUE));

		// Name: Output, Type: Output: false -> G27
		SET_PORT_PIN(G,27,(FCV_FALSE));

		// Name: Delay, Type: Delay: 1 s
		FCI_DELAYBYTE_S(1);

		// Name: Output, Type: Output: false -> G17
		SET_PORT_PIN(G,17,(FCV_FALSE));

		// Name: Output, Type: Output: true -> G22
		SET_PORT_PIN(G,22,(FCV_TRUE));

		// Name: Delay, Type: Delay: 1 s
		FCI_DELAYBYTE_S(1);

		// Name: Output, Type: Output: false -> G22
		SET_PORT_PIN(G,22,(FCV_FALSE));

		// Name: Output, Type: Output: true -> G27
		SET_PORT_PIN(G,27,(FCV_TRUE));


	}


	munmap((void *)gpio, getpagesize());
	return 0;
}
	

/*========================================================================*\
   Use :Interrupt
\*========================================================================*/




