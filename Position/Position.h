#ifndef Position_h
#define Position_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif


class Position {
	public:
  		Position(int, int);

		void 
  			setX(int),
			setY(int);
		int
  			getX(void),
  			getY(void);
};

#endif
