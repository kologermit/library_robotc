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
	startTask(Kalibrovka);

}
