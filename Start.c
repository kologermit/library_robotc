#include <library.h>
void Zahvat()
{
	if(s1 < 10)
	{
		Start(D, -100);
		delay(1000);
		Start(D, 100);
		delay(1000);
	}
	else
	{
		Move(BC, 500, -100);
		Start(D, -100);
		delay(1000);
		Move(BC, 700, 100);
		Start(D, 100);
		delay(1000);
	}
}
bool isKalibrovka = true;
task Kalibrovka()
{
	while(isKalibrovka)
	{
		isLine(S2);
		isLine(S4);
	}
}
task main()
{
	const int speed = 50;
	Start(D, 100);
	startTask(Kalibrovka);
	Move(BC, 135, -speed);
	Move(C, 950, -speed);
	Move(BC, 480, speed);
	Zahvat();
	Start(BC, speed);
	while(!isLine(S4));
	Start(BC, 0);
}
