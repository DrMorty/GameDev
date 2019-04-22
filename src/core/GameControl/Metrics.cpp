#include "Metrics.h"
#include <iostream>

namespace engine
{
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
