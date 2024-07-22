#include <iostream>
#include <timing.hpp>

Timer::Timer() {}

void Timer::start()
{
    start_time = std::chrono::system_clock::now();
}

void Timer::end()
{
    end_time = std::chrono::system_clock::now();
    elapsed_seconds = end_time - start_time;
}

double Timer::get_time()
{
    return elapsed_seconds.count();
}