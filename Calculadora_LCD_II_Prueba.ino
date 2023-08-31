#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

#define STEPS 360

Stepper stepper(STEPS, 10,11,12,13);

const byte FIL = 4; 
const byte COL = 4;
char keys[FIL][COL] = {{'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', 'x'}, {'C', '0', 'E', '/'}}; //define la matriz del teclado
byte filas[FIL] = {2, 3, 4, 5};
byte columnas[COL] = {6, 7, 8, 9};
Keypad teclado = Keypad(makeKeymap(keys), filas, columnas, FIL, COL);
char tecla;

LiquidCrystal_I2C lcd(0x27, 16, 2); // (0x3f,16,2)(0x27,16,2)ó(0x20,16,2)

const int Buzzer = A1; //Pto PWM para buzzer (3, 5, 6, 9, 10, 12)
const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;

void sonido() {
  for (int iTono = 0; iTono < countTonos; iTono++)
  {
    tone(Buzzer, tonos[iTono]);
    delay(50);
  }
  noTone(Buzzer);
}

char num[7]; //numero a ingresar max de 7 digitos
byte indice = 0;
byte pos = 0;

void borrenum()
{
  num[0] = 0;
  num[1] = 0;
  num[2] = 0;
  num[3] = 0;
  num[4] = 0;
  num[5] = 0;
  num[6] = 0;
  indice = 0;
}

void imprimirlcd()
{ lcd.setCursor(pos, 0); //indice
  lcd.print(tecla);
  tone(Buzzer, 350, 100);
}
void cargar() {
  if (indice >= 7) {
    tone(Buzzer, 150, 100);
  }
  else {
    num[indice] = tecla;
    indice++;
    pos++;
    Serial.print(tecla);
    imprimirlcd();
  }
}

long num1 = 0;
long num2 = 0;
char operacion = '+';

void setup() {
  stepper.setSpeed(100);
  pinMode(Buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Univalle");
  lcd.setCursor (0, 1);
  lcd.print("Tec electronica");
  delay(1000);
  sonido();
  lcd.clear();
  lcd.setCursor(0, 0); //posicion inicial
  lcd.blink();
  Serial.begin(9600);
}
void loop() {
  tecla = teclado.getKey();
  if (tecla) {
    switch (tecla) {
      case '1':
        cargar();
        break;
      case '2':
        cargar();
        break;
      case '3':
        cargar();
        break;
      case '4':
        cargar();
        break;
      case '5':
        cargar();
        break;
      case '6':
        cargar();
        break;
      case '7':
        cargar();
        break;
      case '8':
        cargar();
        break;
      case '9':
        cargar();
        break;
      case '0':
        cargar();
        break;
      case '+':
        Serial.println();
        num1 = atof(num); //las funciones atol y atof convierten un char array, a un número entero o de coma flotante.
        lcd.setCursor(indice + 1, 0);
        borrenum();
        operacion = '+';
        pos++;
        tone(Buzzer, 250, 100);
        lcd.print(operacion);
        break;
      case '-':
        Serial.println();
        num1 = atof(num); //las funciones atol y atof convierten un char array, a un número entero o de coma flotante.
        lcd.setCursor(indice + 1, 0);
        borrenum();
        operacion = '-';
        pos++;
        tone(Buzzer, 250, 100);
        lcd.print(operacion);
        break;
      case 'x':
        Serial.println();
        num1 = atof(num); //las funciones atol y atof convierten un char array, a un número entero o de coma flotante.
        Serial.println(num1);
        lcd.setCursor(indice + 1, 0);
        borrenum();
        operacion = 'x';
        pos++;
        tone(Buzzer, 250, 100);
        lcd.print(operacion);
        break;
      case '/':
        Serial.println();
        num1 = atof(num); //las funciones atol y atof convierten un char array, a un número entero o de coma flotante.
        lcd.setCursor(indice + 1, 0);
        borrenum();
        operacion = '/';
        pos++;
        tone(Buzzer, 250, 100);
        lcd.print(operacion);
        break;
      case 'C':
        tone(Buzzer, 450, 100);
        Serial.println();
        borrenum();
        lcd.clear();
        pos = 0;
        lcd.setCursor(0, 0); //posicion inicial
        break;
      case 'E':
        num2 = atof(num);
        borrenum();
        Serial.println();
        Serial.print(num1);
        Serial.print(operacion);
        Serial.print(num2);
        Serial.print("=");
        tone(Buzzer, 250, 100);
        lcd.setCursor(0, 1);
        lcd.print('=');
         if (num2==50){
          stepper.step(360);
          //delay(90);
          stepper.step(-360);
        }
         if (num2==100){
          stepper.step(360);
          delay(350);
          stepper.step(-360);
        }
         if (num2==150){
          stepper.step(360);
          delay(750);
          stepper.step(-360);
        }
         if (num2==200){
          stepper.step(360);
          delay(1000);
          stepper.step(-360);
        }
         if (num2==250){
          stepper.step(360);
          delay(1370);
          stepper.step(-360);
        }
         if (num2==300){
          stepper.step(360);
          delay(1730);
          stepper.step(-360);
        }
         if (num2==350){
          stepper.step(360);
          delay(2050);
          stepper.step(-360);
        }
         if (num2==400){
          stepper.step(360);
          delay(2370);
          stepper.step(-360);
        }
         if (num2==450){
          stepper.step(360);
          delay(2780);
          stepper.step(-360);
        }
         if (num2==500){
          stepper.step(360);
          delay(3000);
          stepper.step(-360);
        }
        switch (operacion) {
          case '+':
            Serial.println(num1);
            Serial.println(num2);
            Serial.println(num1 + num2);
            lcd.print(num1 + num2);
            lcd.setCursor(0, 0);
            pos = 0;
            num1 = 0;
            num2 = 0;
            break;
          case '-':
            Serial.print(num1 - num2);
            lcd.print(num1 - num2);
            lcd.setCursor(0, 0);
            pos = 0;
            num1 = 0;
            num2 = 0;
            break;
          case 'x':
            Serial.print(num1 * num2);
            lcd.print(num1 * num2);
            lcd.setCursor(0, 0);
            pos = 0;
            num1 = 0;
            num2 = 0;
            break;
          case '/':
            if (num2 == 0) {
              Serial.println("Error div/0");
            }
            else {
              Serial.print(num1 / num2);
              lcd.print(num1 / num2);
              lcd.setCursor(0, 0);
              pos = 0;
              num1 = 0;
              num2 = 0;
            }
            break;
        }
        break;
    }
  }
}
