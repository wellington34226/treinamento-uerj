#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "includes.h"

String calculateTime(double time_seconds);
String calculateTime(uint32_t time_microseconds,uint32_t time_seconds=0);
uint32_t getConfigSizeJson(void);
uint32_t getDataSizeJson(void);
void printHelp(void);

String calculateTime(double time_seconds){
  return calculateTime(uint32_t((time_seconds-uint32_t(time_seconds))*1e6),uint32_t(time_seconds));
};
String calculateTime(uint32_t time_microseconds,uint32_t time_seconds){
  String time_converted = "";
  uint32_t months = 0;
  uint32_t weeks = 0;
  uint32_t days = 0;
  uint32_t hours = 0;
  uint32_t minutes = 0;
  uint32_t seconds = time_seconds;
  uint32_t miliseconds = 0;
  uint32_t microseconds = time_microseconds;
  if(microseconds>=1e3){
    miliseconds  = uint32_t(microseconds/1e3);
    microseconds -= uint32_t(miliseconds*1e3);
    if(miliseconds>=1e3){
      seconds  += uint32_t(miliseconds/1e3);
      miliseconds -= uint32_t(seconds*1e3);
    }
  }
  if(seconds >= 60){
    minutes = uint32_t(seconds/60);
    seconds -= uint32_t(minutes*60);
    if(minutes >= 60){
      hours = uint32_t(minutes/60);
      minutes -= uint32_t(hours*60);
      if(hours >= 24){
        days = uint32_t(hours/24);
        hours -= uint32_t(days*24);
        if(days >= 30){
          months = uint32_t(days/30);
          days -= uint32_t(months*30);
        }
        if(days >= 7){
          weeks = uint32_t(days/7);
          days -= uint32_t(weeks*7);
        }
      }
    }
  }
  if(months>0){
    time_converted += String(months) + " mês";
    if(months>1){
      time_converted += "es";
    }
    if(weeks>0){
      time_converted += ", " + String(weeks) + " semana";
      if(weeks>1){
        time_converted += "s";
      }
    }
    if(days>0){
      time_converted += ", " + String(days) + " dia";
      if(days>1){
        time_converted += "s";
      }
    }
    if(hours>0){
      time_converted += ", " + String(hours) +"h";
    }
    if(minutes>0){
      time_converted += ", " + String(minutes) +"min";
    }
  }else{
    if(weeks>0){
      time_converted += String(weeks) + " semana";
      if(weeks>1){
        time_converted += "s";
      }
      if(days>0){
        time_converted += ", " + String(days) + " dia";
        if(days>1){
          time_converted += "s";
        }
      }
      if(hours>0){
        time_converted += ", " + String(hours) + "h";
      }
      if(minutes>0){
        time_converted += ", " + String(minutes) + "min";
      }
      if(seconds>0){
        time_converted += ", " + String(seconds) + "s";
      }
    }else{
      if(days>0){
        time_converted += String(days) + " dia";
        if(days>1){
          time_converted += "s";
        }
        if(hours>0){
          time_converted += ", " + String(hours) + "h";
        }
        if(minutes>0){
          time_converted += ", " + String(minutes) + "min";
        }
        if(seconds>0){
          time_converted += ", " + String(seconds) + "s";
        }
      }else{
        if(hours>0){
          time_converted += String(hours) + "h";
          if(minutes>0){
            time_converted += ", " + String(minutes) + "min";
          }
          if(seconds>0){
            time_converted += ", " + String(seconds) + "s";
          }
        }else{
          if(minutes>0){
            time_converted += String(minutes) + "min";
            if(seconds>0){
              time_converted += ", " + String(seconds) + "s";
            }
            if(miliseconds>0){
              time_converted += ", " + String(miliseconds) + "ms";
            }
            if(microseconds>0){
              time_converted += ", " + String(microseconds) + "us";
            }
          }else{
            if(seconds>0){
              time_converted += String(seconds) + "s";
              if(miliseconds>0){
                time_converted += ", " + String(miliseconds) + "ms";
              }
              if(microseconds>0){
                time_converted += ", " + String(microseconds) + "us";
              }
            }else{
              if(miliseconds>0){
                time_converted += String(miliseconds) + "ms";
                if(microseconds>0){
                  time_converted += ", " + String(microseconds) + "us";
                }
              }else{
                if(microseconds>0){
                  time_converted += String(microseconds) + "us";
                }
              }
            }
          }
        }
      }
    }
  }
  return time_converted;
};

uint32_t getConfigSizeJson(void){
  return 1024;
};
uint32_t getDataSizeJson(void){
  return 16*1024;
};
void printHelp(void){
  File filehelp = LittleFS.open(helpPath,"r");
  if(filehelp){
    Serial.println();
    while(filehelp.available()){
      Serial.print((char)filehelp.read());
    }
    Serial.println();
    filehelp.close();
  }
  Serial.println();
};
#endif