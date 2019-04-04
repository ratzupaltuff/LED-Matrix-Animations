#ifndef Snake_h
#define Snake_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif


class Snake {
	public:
  		Snake(int, int);

		void 
  			print(void),
  			move(int),
  			addOne(void);
 
		int
  			getScore(void);
};

#endif
