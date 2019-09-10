#include <library.h>
void Zahvat()
{
	if((s1 <= 2))
	{
		Start(D, -100);
		delay(500);
		Start(D, 100);
		delay(500);
	}
	else
	{
		Move(BC, 500, -100);
		Start(D, -100);
		delay(500);
		Move(BC, 800, 100);
		Start(D, 100);
		delay(500);
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
	Move(BC, 250, -speed);
	Move(C, 950, -speed);
	isKalibrovka = false;
	Start(BC, speed);
	while(!isLine(S4));
	Move(BC, 50, speed);
	for(int i = 0; i < 4; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 450);
	for(int i = 0; i < 1; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 450);
	for(int i = 0; i < 3; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
	LINE();
	Start(BC, -speed);
	while(!isLine(S4));
	Start(BC, 0);
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 460);
	while(isLine(S4))
		if(!isLine(S2))
	{
		Start(B, speed);
		Start(C, 0);
	}
	else
	{
		Start(B, 0);
		Start(C, speed);
	}
	Move(BC, 400, speed);
	while(!isLine(S4))
		if(!isLine(S2))
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
	Start(D, -100);
	delay(500);
	Move(BC, 2200, -speed);
	Start(D, 100);
	delay(500);
	Move(C, 900, -speed);
	for(int i = 0; i < 4; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 450);
	for(int i = 0; i < 1; i++)
	{
		LINE();
		Move(BC, 20, speed);
		Zahvat();
		Start(BC, speed);
		while(!isLine(S4));
		Move(BC, 50, speed);
	}
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 450);
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
