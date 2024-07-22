#ifndef __Timing__
#define __Timing__
#include <iostream>
#include <chrono>

class Timer
{
    private:
    std::chrono::time_point<std::chrono::system_clock> start_time, end_time;
    std::chrono::duration<double> elapsed_seconds;
    public:
    Timer();
    void start();
    void end();
    double get_time();
};

#endif