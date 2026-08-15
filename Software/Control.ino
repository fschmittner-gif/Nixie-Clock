#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define A1 8
#define B1 10
#define C1 12
#define D1 9
#define A2 14
#define B2 15
#define C2 16
#define D2 17
#define A3 4
#define B3 6
#define C3 7
#define D3 5
#define A4 0
#define B4 2
#define C4 3
#define D4 1

char A[4] = {A1, A2, A3, A4};
char B[4] = {B1, B2, B3, B4};
char C[4] = {C1, C2, C3, C4};
char D[4] = {D1, D2, D3, D4};



const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

tmElements_t tm;
int hour1, hour2, minute1, minute2;

void setup() {

  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(D4, OUTPUT);
 // pinMode(pot, INPUT);
  for (char i = 0; i < 4; i++) {
    digitalWrite(A[i], LOW);
    digitalWrite(B[i], LOW);
    digitalWrite(C[i], LOW);
    digitalWrite(D[i], LOW);
  }
  
  bool parse=false;
  bool config=false;

  // get the date and time the compiler was run
//  if (getDate(__DATE__) && getTime(__TIME__)) {
//    parse = true;
//    // and configure the RTC with this info
//    if (RTC.write(tm)) {
//      config = true;
//    }
//  }

  //Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
  delay(200);
  if (parse && config) {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  } else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  } else {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }

  hour1 = tm.Hour /10;
  hour2 = tm.Hour - 10*hour1;

  minute1 = tm.Minute /10;
  minute2 = tm.Minute -10*minute1; 

//  Serial.print("hour1= ");
//  Serial.print(hour1);
//  Serial.print("hour2= ");
//  Serial.print(hour2);
//
//  Serial.print("minute1= ");
//  Serial.print(minute1);
//  Serial.print("minute2= ");
//  Serial.print(minute2);


  writenumber(3,hour2);
  writenumber(4,hour1);
  writenumber(2,minute1);
  writenumber(1,minute2);
  
  delay(1000);

}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

bool getTime(const char *str)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

bool getDate(const char *str)
{
  char Month[12];
  int Day, Year;
  uint8_t monthIndex;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3) return false;
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(Month, monthName[monthIndex]) == 0) break;
  }
  if (monthIndex >= 12) return false;
  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);
  return true;
}

void writenumber(int a, int b) {        // a: 4 == hour1 3 == hour2 2 == minute1 1 == minute2 

  int x,y,z,i;
  switch (a) {
    case 1:
      x = 8;
      y = 9;
      z = 10;
      i = 12;
      break;
    case 2:
      x = 14;
      y = 15;
      z = 16;
      i = 17;
      break;
    case 4: 
      x = 4;
      y = 5;
      z = 6;
      i = 7;
      break;
    case 3: 
      x = 0;
      y = 1;
      z = 2;
      i = 3;
      break; 
  }
    
  
  switch (b) {
    case 0:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //0
      }else{
      digitalWrite(x, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //0  
      }    
      break;
    case 9:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, LOW); //9
      }else{
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, LOW); //9  
      }    
      break;
    case 8:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(z, HIGH);
      digitalWrite(i, LOW); //8
      }else{
      digitalWrite(x, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, LOW); //8  
      }
      break;
    case 7:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, HIGH); //7
      }else{
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, HIGH); //7  
      }
      break;
    case 6:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(z, LOW);
      digitalWrite(i, HIGH); //6
      }else{
      digitalWrite(x, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, HIGH); //6  
      }
      break;
    case 5:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, HIGH); //5
      }else{
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, HIGH); //5  
      }
      break;
    case 4:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(z, HIGH);
      digitalWrite(i, HIGH); //4
      }else{
      digitalWrite(x, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(z, HIGH);
      digitalWrite(i, HIGH); //4  
      }
      break;
    case 3:
      if(a == 3){
      digitalWrite(x, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //3
      }else{
      digitalWrite(x, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //3  
      }
      break;
    case 2:
      if(a == 3){
      digitalWrite(x, HIGH);
      digitalWrite(y, HIGH);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //2
      }else{
      digitalWrite(x, HIGH);
      digitalWrite(y, HIGH);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //2  
      }
      break;
    case 1:
      if(a == 3){
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //1
      }else{
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      digitalWrite(z, LOW);
      digitalWrite(i, LOW); //1  
      }
      break;
  }
}
