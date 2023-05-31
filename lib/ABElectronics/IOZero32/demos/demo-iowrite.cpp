/*
 * demo-iowrite.cpp
 *
 *      compile with "g++ demo-iowrite.cpp ../ABE_IOZero32.cpp -Wall -Wextra -Wpedantic -Woverflow -o demo-iowrite"
 *      run with "./demo-iowrite"
 * 
 * This demo sets the pins on bus 1 as outputs, turns all of the pins off and toggles the state of pin 1 at a 1 second interval.
 */

#include <stdio.h>
#include <stdexcept>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include "../ABE_IOZero32.h"

using namespace std;

int main(int argc, char **argv){
	using namespace ABElectronics_CPP_Libraries;

	try
	{
		IOZero32 bus1(0x20);
		bus1.set_port_direction(0, 0x00); // set the direction for bank 0 to be outputs
		bus1.set_port_direction(1, 0x00); // set the direction for bank 1 to be outputs
		bus1.write_port(1, 0xFF);
		while (1){
			bus1.write_pin(1, 1); // turn pin 1 on and off at 1 second intervals
			usleep(1000000);
			bus1.write_pin(1, 0);
			usleep(1000000);
		}
	}
	catch (exception &e)
	{
		cout << e.what();
	}

	(void)argc;
	(void)argv;
	return (0);
}
