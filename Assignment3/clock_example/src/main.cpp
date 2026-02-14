//
//  main.cpp
//  Assignment3
    
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "../include/cycletime.h"

using namespace std;
extern "C" {
    bool is_init=false;
    bool init_pmu_wrapper(unsigned int reset, unsigned int divider, bool is_debug){
        try{
            if(is_debug){
                cout << "reset: "<<reset<<", divider: "<<divider<<endl;
            }
            init_counters(reset, divider);
            is_init = true;
        }catch (const std::runtime_error& e) {
            cout << "Caught exception: " << e.what() << std::endl;
            is_init = false;
        }
        return is_init;
    }
    unsigned int get_cyclecount_wrapper(){
        return is_init ? get_cyclecount() : 0;
    }
}