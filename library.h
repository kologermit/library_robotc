#define B motorB
#define C motorC
int BC  = rand();
#define A motorA
#define D motorD
#define Start(a, b) {if (a == BC) {setMotorSpeed(B, b); setMotorSpeed(C, b);} else setMotorSpeed(a, b);}
#define StopAll() Start(A, 0); Start(B, 0); Start(C, 0); Start(D, 0)
#define Display displayBigStringAt // y = 125; x = 0; Display(x, y, "", ...);
#define Clear eraseDisplay
#define s1 SensorValue[S1]
#define s2 SensorValue[S2]
#define s3 SensorValue[S3]
#define s4 SensorValue[S4]
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define Encoder getMotorEncoder
#define Tone playTone
#define MoveToFunc(func, degrees) {resetMotorEncoder(B); while(abs(Encoder(B)) <= abs(degrees)) func; StopAll();}

#define Move(port, degrees, speed) { \
	if(port == BC) \
	{ \
		Start(BC, 0);\
		MoveToFunc({Start(B, speed); Start(C, speed);}, degrees) \
	} \
	else \
	{ \
		resetMotorEncoder(port); \
		Start(port, speed); \
		while(abs(Encoder(port)) <= abs(degrees)); \
		Start(port, 0); \
	} \
}

bool isLine(int port){
	static int Max[4] = {0, 0, 0, 0};
	static int Min[4] = {100, 100, 100, 100};
	Max[port] = max(SensorValue[port], Max[port]);
	Min[port] = min(SensorValue[port], Min[port]);
	return !((Min[port] + Max[port]) / 2 < SensorValue[port]);
}

#define file(b, a) (a == 'w' ? fileOpenWrite(b) : fileOpenRead(b))

long freadLong(int fileDescriptor){
	long data;
	fileReadLong(fileDescriptor, &data);
	return data;
}

char freadChar(int fileDescriptor){
	char data;
	fileReadChar(fileDescriptor, &data);
	return data;
}

float freadFloat(int fileDescriptor){
	float data;
	fileReadFloat(fileDescriptor, &data);
	return data;
}

short freadShort(int fileDescriptor){
	short data;
	fileReadShort(fileDescriptor, &data);
	return data;
}

void fwrite(int fileDescriptor, long value){
	fileWriteLong(fileDescriptor, value);
}

void fwrite(int fileDescriptor, char value){
	fileWriteChar(fileDescriptor, value);
}

void fwrite(int fileDescriptor, short value){
	fileWriteShort(fileDescriptor, value);
}

void fwrite(int fileDescriptor, float value){
	fileWriteFloat(fileDescriptor, value);
}

