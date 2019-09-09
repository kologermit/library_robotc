#include <library.h>
bool isBanka = false;
task Banka()
{
	while(true)
		Start(D, !isBanka ? 100 : -100);
}
task main()
{
	startTask(Banka);
	while(true)
	{
		isBanka = false;
		delay(1000);
		isBanka = true;
		delay(1000);
	}
}
