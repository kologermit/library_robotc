#define B motorB
#define C motorC
int BC  = rand();
#define A motorA
#define D motorD
#define Start(a, b) {if (a == BC) {setMotorSpeed(B, b); setMotorSpeed(C, b);} else setMotorSpeed(a, b);}
#define StopAll() Start(A, 0); Start(B, 0); Start(C, 0); Start(D, 0)
#define Display displayBigStringAt
#define Clear eraseDisplay
#define s1 SensorValue[S1]
#define s2 SensorValue[S2]
#define s3 SensorValue[S3]
#define s4 SensorValue[S4]
#define Encoder getMotorEncoder
#define Tone playTone
#define MoveToFunc(func, degrees) {resetMotorEncoder(B); while(abs(Encoder(B)) < abs(degrees)) func; StopAll();}
#define Move(port, degrees, speed) { \
	if(port == BC) \
	{ \
		resetMotorEncoder(B); \
		Start(B, speed); \
		Start(C, speed); \
		while(abs(Encoder(B)) <= abs(degrees)); \
		Start(B, 0); \
		Start(C, 0); \
	} \
	else \
	{ \
		resetMotorEncoder(port); \
		Start(port, speed); \
		while(abs(Encoder(port)) <= abs(degrees)); \
		Start(port, 0); \
	} \
}
