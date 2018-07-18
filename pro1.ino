#define faseA 2
#define faseB 3
#define sw 4

volatile int LastB=1;
volatile int LastA=1;
volatile int PosE =0;

void setup(){

  pinMode(faseA,INPUT_PULLUP);
  pinMode(faseB,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(faseA) ,funcA, FALLING);
  attachInterrupt(digitalPinToInterrupt(faseB) ,funcB, FALLING);

  Serial.begin(9600);
}

void loop(){
  
  LastA=digitalRead(faseA);
  LastB=digitalRead(faseB);
  Serial.println(PosE);
  /*Serial.print("\t");
  Serial.print(LastA);  
  Serial.print("\t");
  Serial.println(LastB);*/
 }

void funcA(){
  if(LastA!=0 & LastB!=0){
  PosE++;
  }
 LastA=0;
}

void funcB(){  
  if(LastA!=0 & LastB!=0){
    PosE--;
  }
  LastB=0;
  
}

