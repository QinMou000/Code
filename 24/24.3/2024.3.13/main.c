#define _CRT_SECURE_NO_WARNINGS 1
unsigned char KeyNum;
unsigned int  LEDMode = 0;

void main()
{
	P2 = 0xFE;
	Timer0Init();
	while (1)
	{
		KeyNum = Key();
		if (KeyNum)
		{
			if (KeyNum == 1)
			{
				LEDMode++;
				if (LEDMode >= 2)LEDMode = 0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0X18;
	TH0 = 0XFC;
	T0Count++;
	if (T0Count >= 500)
	{
		T0Count = 0;
		if (LEDMode == 0)
			P2 = _crol_(P2, 1);
		if (LEDMode == 1)
			P2 = _cror_(P2, 1);
	}
}
