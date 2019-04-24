#include "ControlFPS.h"
#include <iostream>

namespace engine
{
  float ControlFPS::deltaTime = 0;
    std::chrono::time_point <std::chrono::_V2::system_clock> Time::previousTime = std::chrono::system_clock::now();
  ControlFPS::ControlFPS()
  {
  }

  void ControlFPS::UpdateTime()
  {
    auto currentTime = std::chrono::system_clock::now();

        std::chrono::duration<double> delta = currentTime - previousTime;
        deltaTime = delta.count();

        previousTime = currentTime;
    }
  
  int::ControlFPS::FPS = 0;
  bool ControlFPS::Logging = false;
  
  void ControlFPS::updateMetrics()
  {
    static int frames = 0;
    static float elapsedTime = 0;
    
    elapsedTime += ControlFPS::deltaTime;
    frames++;
    
    if (elapsedTime >=1.0f)
      updateFPS(frames, elapsedTime);
      
  }
  
  void ControlFPS::updateFPS(int&frames, float&elapsed)
  {
    FPS = frames / elapsed;
    
    frames =  0;
    elapsed = 0;
    
    if (Logging)
      std::cout << "FPS = " << FPS << std::endl;
  }
  
  void ControlFPS::enableLogging()
   {
        Logging = true;
    }
  void ControlFPS::disableLogging()
    {
        Logging = false;
    }
}
