#include <library.h>
const int speed = 100;
void Zahvat()
{
	if((s1 <= 2))
	{
		Start(D, -100);
		delay(500);
		Start(D, 100);
		delay(500);
		Move(BC, 200, speed);
	}
	else
	{
		Move(BC, 500, -100);
		Start(D, -100);
		delay(500);
		Move(BC, 850, 100);
		Start(D, 100);
		delay(500);
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
void LINE(int k1 = 1, int k2 = 1)
{
	k1 = k1 != -1 ? 0 : -1;
	k2 = k2 != -1 ? 0 : -1;
	Start((k2 != -1 ? C : B), speed);
	while(!isLine(S2) && k1 != -1);
	while(k1 == 0 ? isLine(S4) : !isLine(S4))
		if(isLine(S2) + k2)
	{
		Start(B, speed);
		Start(C, speed * 0.25);
	}
	else
	{
		Start(B, speed * 0.25);
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
	delay(5000);
	LINE();
	delay(5000);
	Start(BC, -speed);
	while(!isLine(S4));
	Start(BC, 0);
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 460);
	LINE(1, -1);
	Move(BC, 400, speed);
	LINE(-1, -1);
	Start(BC, 0);
	delay(5000);
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
	while(true);
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
	for(int i = 0; i < 3; i++){
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
	}
}
