const int FSR_PIN = A0; // Pin connected to FSR/resistor divider
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 3230.0; // Measured resistance of 3.3k resistor
float force;

void setup(){
  Serial.begin(9600);
  pinMode(FSR_PIN, INPUT);
}

void loop(){
  int fsrADC = analogRead(FSR_PIN);

  // Use ADC reading to calculate voltage:
  float fsrV = fsrADC * VCC / 1023.0;

  // Use voltage and static resistor value to
  // calculate FSR resistance:
  float fsrR = R_DIV * (VCC / fsrV - 1.0);
  Serial.println("Resistance: " + String(fsrR) + " ohms");

  // Guesstimate force based on slopes in figure 3 of
  // FSR datasheet:
  float fsrG = 1.0 / fsrR; // Calculate conductance

  // Break parabolic curve down into two linear slopes:
  if (fsrR <= 600)
    force = (fsrG - 0.00075) / 0.00000032639;
  else
    force =  fsrG / 0.000000642857;


  Serial.println("Force: " + String(force) + " g");

  delay(1);
}
