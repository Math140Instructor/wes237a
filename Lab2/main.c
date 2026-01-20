#include <unistd.h>
   
int myAdd(int a, int b){
        sleep(1);
        return a+b;
}

int myMultiply(int a, int b){
        sleep(1);
        return a*b;
}

int myAddT(int a, int b, double time){
        sleep(time);
        return a+b;
}

int myMultiplyT(int a, int b, double time){
        sleep(time);
        return a*b;
}
