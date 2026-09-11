#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
const double Rc = 0.001;
void setup() 
{
 lcd.begin(16,2);
 lcd.print("3 PHASE FAULT &");
 lcd.setCursor(0,1);
 lcd.print("DISTANCE LOCATOR");
  
 delay(500);

 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(A0,INPUT);
  
}

void loop() 
{
 double Vx = (5.0/1024.0)*analogRead(A0);
 double Rx = Vx/(1.25/12);
 if(Rx <= 9.61)
 {
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  
  lcd.clear();
  lcd.print("NO FAULT PHASE 3");
  delay(500);
  
 }
 else if(Rx == 0)
 {
 
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  
  lcd.clear();
  lcd.print("FAULT PHASE 3");
  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print((Rx/Rc)/2);   
  lcd.print("M");
  delay(500);
 }
  else if(Rx >= 10)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 3");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Rx/Rc)/3);  
  lcd.print("M");
  delay(500);
  
  }
  else if(Rx >= 6)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 3");
  lcd.setCursor(0,1);;
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Rx/Rc)/4);   
  lcd.print("M");
  delay(500);
  
  }
  else
  {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);

  lcd.clear();
  lcd.print("FAULT PHASE 3");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Rx/Rc)/4);   
  lcd.print("M");
  delay(500);
  
  }
 double Va = (5.0/1024.0)*analogRead(A1);
 double Ra = Va/(1.25/12);
 if(Ra <= 9.61)
 {
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  
  lcd.clear();
  
  lcd.print("NO FAULT PHASE 1");
  delay(500);
  
 }
 else if(Ra == 0)
 {
 
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  
  lcd.clear();
  lcd.print("FAULT PHASE 1");
  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print((Ra/Rc)/2);   
  lcd.print("M");
  delay(500);
 }
  else if(Ra >= 10)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 1");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Ra/Rc)/4);  
  lcd.print("M");
  delay(500);
  
  }
  else if(Ra >= 6)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 1");
  lcd.setCursor(0,1);;
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Ra/Rc)/5);   
  lcd.print("M");
  delay(500);
  
  }
  else
  {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);

  lcd.clear();
  lcd.print("FAULT PHASE 1");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((Ra/Rc)/5);   
  lcd.print("M");
  delay(500);
  }
  double VY = (5.0/1024.0)*analogRead(A2);
 double RY = VY/(1.25/12);
 if(RY <= 9.61)
 {
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  
  lcd.clear();
  
  lcd.print("NO FAULT PHASE 2");
  delay(500);
  
 }
 else if(RY == 0)
 {
 
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  
  lcd.clear();
  lcd.print("FAULT PHASE 2");
  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print((RY/Rc)/1);   
  lcd.print("M");
  delay(500);
 }
  else if(RY >= 10)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 2");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((RY/Rc)/2);  
  lcd.print("M");
  delay(500);
  
  }
  else if(RY >= 6)
  {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);

  lcd.clear();
  lcd.print("FAULT PHASE 2");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((RY/Rc)/3);   
  lcd.print("M");
  delay(500);
  
  }
  else
  {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);

  lcd.clear();
  lcd.print("FAULT PHASE 2");
  lcd.setCursor(0,1);
  lcd.print("Dist ");
  lcd.print((RY/Rc)/3);   
  lcd.print("M");
  delay(500);
  }
}
