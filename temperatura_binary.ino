#include <string.h>
const int analogPin = A0;

void setup_digital_pins(){
  for(int i=2;i<7;i++){
    pinMode(i,OUTPUT);
  }
}

String reverse_string(String value){
  String output = "";
  for(int i=value.length()-1;i>=0;i--){
      output += value[i];
  }
  return output;
}

String convert_dec_to_binary(int value){
  String binary_val = "";

  while(value != 1){
    if(value % 2 == 0){
      binary_val += "0";
    }
    else{
      binary_val += "1";
    }
    value = value / 2;
  }
  binary_val += "1";
  String output = reverse_string(binary_val);
  return output;
}

void set_digital_to_low(){
  for(int i=2;i<7;i++){
    digitalWrite(i,LOW);
  }
}

void show_temperature(String value_in_binary){
  int digitalPin_index = 2;
  for(int i=value_in_binary.length()-1;i>=0;i--){
    if(value_in_binary[i] == '1'){
      digitalWrite(digitalPin_index,HIGH);
    }
    digitalPin_index+=1;
  }
}

void setup() {
  Serial.begin(9600);
  setup_digital_pins();
}

void loop() {
  set_digital_to_low();
  int sensorVal=analogRead(analogPin);

  float voltage = (sensorVal/1024.0)*5.0;

  int temperature=(voltage-.5)*100;
  Serial.println("");
  Serial.print("Temperatura : ");
  Serial.print(temperature);
  Serial.print(", binary : ");

  String binary = convert_dec_to_binary(temperature);
  Serial.print(binary);

  show_temperature(binary);

  delay(10000);
}
