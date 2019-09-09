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
}
task main()
{
	Start(D, 100);
	int speed = 50;
	Move(C, 500, speed);
	Move(BC, 100, speed);
	Zahvat();
}
