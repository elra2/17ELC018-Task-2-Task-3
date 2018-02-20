// Definitions for the Device Drivers on STM32F3 Discovery Board
// DJM 23/01/2018

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WM_H
#define __WM_H


class door{
	public:
	door();
	bool GetDoorStatus();
	void ReadDoorStatus();
	private:
	bool doorstatus;
};

class buzzer {
	public:
	buzzer();
	void SetBuzzer();
	private:
	bool buzzerstatus;
};

class switches
{
	public:
		switches();
		bool GetSwitch(unsigned short);
	  void Reset();
	  void AcceptUserInput();
	private:
	bool switchvalue;
};

class motor
{
	public: 
	motor();
	int GetMotorSpeed();
	void SetControlOFF();
	void SetControlON();
	void SetDirectionCW();
	void SetDirectionACW();
	private:
	int motorspeed;
	int motordirection;
};

class timer
{
	public:
		timer();
		void wait(unsigned int);
	private:
		unsigned int time;
};

#endif /* __WM_H */
