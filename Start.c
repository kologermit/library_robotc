<<<<<<< HEAD
#include "library.h"
const int speed = 30;
void LINE(float kk = 0.3){
	const float k = kk;
	if(!isLine(S2) && isLine(S3)){
		Start(B, speed); Start(C, speed * k);
	}
	elif(isLine(S2) && !isLine(S3)){
		Start(B, speed * k); Start(C, speed);
	}
	else
		Start(BC, speed);
}
void LINE_ONE(float kk = 0.34){
	const float k = kk;
	if(!isLine(S3))
	{Start(B, speed * k); Start(C, speed); }
	else
	{Start(B, speed); Start(C, speed * k); }
}
task main()
{
	Start(D, 25);
	Start(A, 25);
	Start(BC, speed);
	MoveToFunc({isLine(S2); isLine(S3)}, 200);
	while(!isLine(S2) || !isLine(S3))
		LINE(0.8);
	Move(BC, 70, speed);
	MoveToFunc({Start(B, speed); Start(C, -speed);}, 180);
	MoveToFunc(LINE(0.3), 750);
	while(s4 > 15) LINE(0.75);
	StopAll();
	Start(D, -100);
	delay(1500);
	Start(A, -100);
	delay(1000);
	Start(D, 100);
	delay(1500);
	Start(D, 100);
	Start(A, -100);
	MoveToFunc(LINE_ONE(0.6), 1560);
	MoveToFunc({Start(B, -speed); Start(C, speed);}, 180);
	MoveToFunc(LINE_ONE(0.8), 1400);
	MoveToFunc({Start(B, -speed); Start(C, speed);}, 180);
	for(;s4 > 15;) LINE_ONE(0.3);
	StopAll();
	Move(D, 100, -20);
	delay(2000);
	Start(A, 100);
	delay(1000);

=======
#include <library.h>
const int speed = 100;
task main(){
>>>>>>> 1a1818d457480782f227ae35253b108b79798ccb
}
