#include <library.h>
task Black_Banka()
{
	Start(D, -100);
	delay(1000);
	Start(D, 100);
	delay(1000);
}
void Zahvat()
{
	if(s1 < 10)
		startTask(Black_Banka);
	else
	{
		Move(BC, 500, -100);
		Start(D, -100);
		delay(1000);
		Move(BC, 800, 100);
		Start(D, 100);
		delay(1000);
	}
}
const int speed = 50;
bool isKalibrovka = true;
task Kalibrovka()
{
	while(isKalibrovka)
	{
		isLine(S2);
		isLine(S4);
	}
}
void LINE()
{
	while(isLine(S4))
		if(isLine(S2))
	{
		Start(B, speed);
		Start(C, 0);
	}
	else
	{
		Start(B, 0);
		Start(C, speed);
	}
	Start(BC, 0);
}
task main()
{
	Start(D, 100);
	startTask(Kalibrovka);
	Move(BC, 230, -speed);
	Move(C, 950, -speed);
	Move(BC, 480, speed);
	isKalibrovka = false;
	Zahvat();
	Start(BC, speed);
	while(!isLine(S4));
	Move(BC, 50, speed);
	for(int i = 0; i < 3; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
}
