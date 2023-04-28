/*
 Fundacion Kinal
 Electronica
Grado: Quito perito
seccion: A
curso: taller de electronica
Nombre: Diego Alejandro Culajay Gonzalez
carnet: 2019485
*/
#include <LiquidCrystal.h>

#define RS 11
#define enable 10
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define trig A3
#define echo A2
#define Buzzer 6
int Distancia;
int Duracion;
int conteo =0;
int nota_la = 440;
LiquidCrystal LCD_sensor(RS,enable,D4,D5,D6,D7);

byte Dnormal[] = {
0b00000,
0b11000,
0b10100,
0b10010,
0b10010,
0b10100,
0b11000,
0b00000
  };
byte corazonD[] = {
0b00010,
0b00101,
0b01001,
0b10010,
0b10010,
0b01001,
0b00101,
0b00010
  };

void setup() {
  pinMode(A3,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(Buzzer, OUTPUT);
  LCD_sensor.begin(16,2);
  LCD_sensor.setCursor(0,0);
  LCD_sensor.print("No.Personas");
  LCD_sensor.setCursor(0,0);
  LCD_sensor.createChar(1,Dnormal);
  LCD_sensor.createChar(2,corazonD);
}

void loop() { 
  LCD_sensor.write(1); 
  LCD_sensor.write(2);
  
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  Duracion = pulseIn(echo,HIGH);
  Distancia = Duracion / 59;
  Serial.println(Distancia);
  delay(500);

if(Distancia > 5 && Distancia < 11){
  conteo = conteo +1;
}

  if(conteo == 1){
  LCD_sensor.setCursor(0,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1); 
  noTone(Buzzer); 
  }
  if(conteo == 2){
  LCD_sensor.setCursor(1,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);
  noTone(Buzzer);  
  }
  if(conteo == 3){
  LCD_sensor.setCursor(2,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1); 
  noTone(Buzzer); 
  }
  if(conteo == 4){
  LCD_sensor.setCursor(3,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2); 
  noTone(Buzzer); 
  }
  if(conteo == 5){
  LCD_sensor.setCursor(4,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1);
  noTone(Buzzer);  
  }
  if(conteo == 6){
  LCD_sensor.setCursor(5,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);
  noTone(Buzzer);  
  }
  if(conteo == 7){
  LCD_sensor.setCursor(6,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1);
  noTone(Buzzer);  
  }
  if(conteo == 8){
  LCD_sensor.setCursor(7,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);  
  }
  if(conteo == 9){
  LCD_sensor.setCursor(8,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1);
  noTone(Buzzer);  
  }
  if(conteo == 10){
  LCD_sensor.setCursor(9,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);
  noTone(Buzzer);  
  }
  if(conteo == 11){
  LCD_sensor.setCursor(10,2);  //Primera columna y segunda fila  
  LCD_sensor.write(1); 
  noTone(Buzzer); 
  }
  if(conteo == 12){
  LCD_sensor.setCursor(11,3);  //Primera columna y segunda fila  
  LCD_sensor.write(2); 
  noTone(Buzzer); 
  }
  if(conteo == 13){
  LCD_sensor.setCursor(12,1);  //Primera columna y segunda fila  
  LCD_sensor.write(1); 
  noTone(Buzzer); 
  }
  if(conteo == 14){
  LCD_sensor.setCursor(13,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);
  noTone(Buzzer);  
  }
  if(conteo == 15){
  LCD_sensor.setCursor(14,2);  //Primera columna y segunda fila  
  LCD_sensor.write(1); 
  noTone(Buzzer); 
  }
  if(conteo >= 16){
  LCD_sensor.setCursor(15,1);  //Primera columna y segunda fila  
  LCD_sensor.write(2);
  delay(600); 
  LCD_sensor.setCursor(15,1);
  LCD_sensor.write(1);
  delay(600);
  tone(Buzzer,nota_la,440);
  }  
}
