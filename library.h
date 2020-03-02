#define B motorB
#define C motorC
int BC = -1;
#define A motorA
#define D motorD
#define Start(a, b) {if (a == BC) {setMotorSpeed(B, b); setMotorSpeed(C, b);} else setMotorSpeed(a, b);}
#define StopAll() {Start(A, 0); Start(B, 0); Start(C, 0); Start(D, 0)}
#define Display displayString
#define endl '\n'
#define WT while(true);
#define Clear eraseDisplay
#define s1 SensorValue[S1]
#define s2 SensorValue[S2]
#define s3 SensorValue[S3]
#define s4 SensorValue[S4]
#define MAX_LINES_DISPLAY
#define MAX_CHARACTERS_DISPLAY
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sign(a) (!(a) ? 0 : abs(a) / (a))
#define Encoder getMotorEncoder
#define Tone playTone
<<<<<<< HEAD
#define MoveToFunc(func, degrees) {resetMotorEncoder(B); while(abs(Encoder(B)) <= abs(degrees)) func;}
#define elif else if
=======
#define FOR(n) for(int i = 0; i < n; i++)
#define elif else if
#define npos -1
#define MoveToFunc(func, degrees) {resetMotorEncoder(B); while(abs(Encoder(B)) <= abs(degrees)) func; StopAll();}
#define in_range(value, a, b) ((value) >= min(a, b) && (value) <= max(a, b))
>>>>>>> 1a1818d457480782f227ae35253b108b79798ccb
#define Move(port, degrees, speed) { \
	if(port == BC) \
	{ \
		Start(BC, 0);\
		MoveToFunc({Start(B, speed); Start(C, speed);}, degrees); StopAll(); \
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

void fwrite(char * path, long value){
	int fileDescriptor = file(path, 'w');
	fileWriteLong(fileDescriptor, value);
}

void fwrite(char * path, char value){
	int fileDescriptor = file(path, 'w');
	fileWriteChar(fileDescriptor, value);
}

void fwrite(char * path, short value){
	int fileDescriptor = file(path, 'w');
	fileWriteShort(fileDescriptor, value);
}

void fwrite(char * path, float value){
	int fileDescriptor = file(path, 'w');
	fileWriteFloat(fileDescriptor, value);
}

void sort(long * arr, int size){
	bool flag;
	do {
		flag = false;
		FOR(size - 1)
		if(arr[i] > arr[i + 1]){
			long temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			flag = true;
		}
	} while(flag);
}

int search(long * arr, int size, long value){
	FOR(size)
	if(arr[i] == value)
		return i;
	return npos;
}

int count(long * arr, int size, long value){
	int cn = 0;
	FOR(size)
	if(arr[i] == value) cn++;
	return cn;
}

enum COLOR{
	NONE,
	BLACK,
	WHITE,
	GREEN,
	RED,
	BLUE,
	YELLOW,
	BROWN
};

COLOR HT_color(int value){
	if(in_range(value, 3, 2))
		return BLUE;

	if(in_range(value, 4, 4))
		return GREEN;

	if(in_range(value, 7, 9))
		return RED;

	if(in_range(value, 5, 6))
		return YELLOW;

	if(in_range(value, 10, 17))
		return WHITE;

	if(in_range(value, 0, 0))
		return BLACK;

	return NONE;
}

#define COLOR_TO_STRING(a) (\
(a) == YELLOW ? "YELLOW" :\
(a) == BLUE ? "BLUE" :\
(a) == BLACK ? "BLACK" :\
(a) == WHITE ? "WHITE" :\
(a) == GREEN ? "GREEN" :\
(a) == RED ? "RED" :\
"NONE"\
)
