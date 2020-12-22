#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
{'1', '2', '3', '+'},
{'4', '5', '6', '-'},
{'7', '8', '9', '*'},
{'X', '0', '=', '/'}
};

byte rowPins[ROWS] = {3, 2, 1, 0};
byte colPins[COLS] = {7, 6, 5, 4};

LiquidCrystal lcd(9, 8, 10, 11, 12, 13);
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

boolean valorActual = false;
boolean siguiente = false;
boolean final = false;
String num1, num2,num3;
int total;
int movimiento;
char op;

void setup(){
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("@codelectronica");
    lcd.setCursor(0,1);
    lcd.print("@OscarDevOps");
    delay(2500);
    lcd.clear();
}

void loop(){
    char key = myKeypad.getKey();
    if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0')){
    if (valorActual != true){
        num1 = num1 + key;
        int numLength = num1.length();
        movimiento = numLength;
        lcd.setCursor(0, 0);
        lcd.print(num1);
    }
    else {
        num2 = num2 + key;
        int numLength = num2.length();
        lcd.setCursor(movimiento+1, 0);
        lcd.print(num2);
        final = true;
    }
    }

    else if (valorActual == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+')){
    if (valorActual == false){
        valorActual = true;
        op = key;
        lcd.setCursor(movimiento,0);
        lcd.print(op);
    }
    }

    else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
        total = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
        total = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
        total = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
        if(num2.toInt()==0){
        total = ' ';
        }else{
        total = num1.toInt() / num2.toInt();
        }
    }
    num3=String(total);
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    if(total==' '){
        lcd.print("Sintax Error");
    }else if(num3.length()>4){
        lcd.print("No hay memoria");
    }else{
        lcd.print(total);
    }
    lcd.noAutoscroll();
    }
    else if (key != NO_KEY && key == 'X'){
        lcd.clear();
        valorActual = false;
        final = false;
        num1 = "";
        num2 = "";
        total = 0;
        op = ' ';
    }
}
