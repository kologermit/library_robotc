#define B motorB
#define C motorC
#define BC 927634
#define A motorA
#define D motorD
int count_crossroad = 0;
#define Start(a, b) {if (a == BC) {setMotorSpeed(B, b); setMotorSpeed(C, b);} else setMotorSpeed(a, b);}
#define StopAll() Start(A, 0); Start(B, 0); Start(C, 0); Start(D, 0)
#define Display displayBigStringAt
#define Clear() eraseDisplay()
#define s1 SensorValue[S1]
#define s2 SensorValue[S2]
#define s3 SensorValue[S3]
#define s4 SensorValue[S4]
#define Encoder getMotorEncoder
#define Move(a, b, c) if(a == BC){ resetMotorEncoder(B); Start(BC, c); while(abs(getMotorEncoder(B)) < abs(b)){} Start(BC, 0);} else { moveMotorTarget(a, b, c); }
#define Tone playTone
#define MoveToFunc(func, degrees) {resetMotorEncoder(B); while(abs(Encoder(B)) < abs(degrees)) func; StopAll();}
