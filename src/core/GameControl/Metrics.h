#ifndef METRICS_H
#define METRICS_H

#include <chrono>
#include <ctime>

namespace engine
{
    class Metrics
    {
     public:
        static float deltaTime;
        static void updateTime();
        
        static void updateMetrics();
        static void updateFPS(int& frames, float& elapsed);

        static void enableLogging();
        static void disableLogging();

        static int FPS;

     private:
        static std::chrono::time_point <std::chrono::_V2::system_clock> previousTime;
        static bool Logging;
        
        Time(); 
        Metrics();
    };
}

#endif
