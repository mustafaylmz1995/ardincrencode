#define faseA 2
#define faseB 3
#define sw 4

volatile int LastB=1;
volatile int LastA=1;
volatile int LastSw=1;
volatile int PosE =0;

void setup(){
  SREG = SREG | 0x08; // general ınterrupt enable
  PCICR |= 0x04; // PCINT[23:16] yani D0 to D7 portu için interrupt açıldı
  PCMSK2 |= 0x10; // intr pini için interrupt açıldı

  pinMode(faseA,INPUT_PULLUP);
  pinMode(faseB,INPUT_PULLUP);
  pinMode(sw, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(faseA) ,funcA, FALLING);
  attachInterrupt(digitalPinToInterrupt(faseB) ,funcB, FALLING);

  Serial.begin(9600);
}

void loop(){
  
  LastA=digitalRead(faseA);
  LastB=digitalRead(faseB);
  LastSw=digitalRead(sw);
  Serial.print(PosE);
  Serial.print("\t");
  Serial.println(LastSw);
  /*  
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

ISR(PCINT2_vect){
  if(LastSw!=0){
  }
  LastSw=0;
}
