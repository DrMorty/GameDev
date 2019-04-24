#include "ControlFPS.h"
#include <iostream>

namespace engine
{
  float Time::deltaTime = 0;
    std::chrono::time_point <std::chrono::_V2::system_clock> Time::previousTime = std::chrono::system_clock::now();

  void Time::UpdateTime()
  {
    auto currentTime = std::chrono::system_clock::now();

        std::chrono::duration<double> delta = currentTime - previousTime;
        deltaTime = delta.count();

        previousTime = currentTime;
    }
  
  int::Metrics::FPS = 0;
  bool Metrics::Logging = false;
  
  void Metrics::updateMetrics()
  {
    static int frames = 0;
    static float elapsedTime = 0;
    
    elapsedTime += Time::deltaTime;
    frames++;
    
    if (elapsedTime >=1.0f)
      updateFPS(frames, elapsedTime);
      
  }
  
  void Metrics::updateFPS(int&frames, float&elapsed)
  {
    FPS = frames / elapsed;
    
    frames =  0;
    elapsed = 0;
    
    if (Logging)
      std::cout << "FPS = " << FPS << std::endl;
  }
  
  void Metrics::enableLogging()
   {
        Logging = true;
    }
  void Metrics::disableLogging()
    {
        Logging = false;
    }
}
