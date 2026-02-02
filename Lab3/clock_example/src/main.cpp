//
//  main.cpp
//  Lab3
//
//  Created by Alireza on 2/14/20.
//  Copyright Â© 2020 Alireza. All rights reserved.
//

#include "main.h"
#include "cycletime.h"
#include "timer.h"
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[])
{
    init_counters(1, 0);
	float cpu_timer;
	unsigned int delay = 1;
	
	cout << "WES237A lab 3" << endl;

	char key=0;
	
	// 1 argument on command line: delay = arg
	if(argc >= 2)
	{
		delay = atoi(argv[1]);
	}
    cout << "Delay: "<< delay << "us" << endl;
    //TODO: declare 2 cpu_count variables: 1 for before sleeping, 1 for after sleeping (see cpu_timer)
    //TODO: initialize the counter
    unsigned int before = get_cyclecount();
    //TODO: get the cyclecount before sleeping
    usleep(delay);
    //TODO: get the cyclecount after sleeping
    unsigned int after = get_cyclecount(); // wraps naturally for unsigned
    //TODO: subtract the before and after cyclecount
    //TODO: print the cycle count (see the print statement for the cpu_timer below)
    unsigned int delta_cycles = after - before;
    std::cout << "Cycle count before: " << before << std::endl;
    std::cout << "Cycle count after: " << after << std::endl;
    std::cout << "Cycles elapsed: " << delta_cycles << std::endl;

	LinuxTimer t;
	usleep(delay);
	t.stop();
	cpu_timer = t.getElapsed();

	
	cout << "Timer: " << (double)cpu_timer/1000000000.0 << endl;

	return 0;
}

