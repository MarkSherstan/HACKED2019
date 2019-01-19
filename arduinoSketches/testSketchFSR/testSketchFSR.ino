// Declare some variables
const int FSR_PIN = A0;
const float VCC = 4.98;
const float R_DIV = 5100.0;
int fsrADC;
float force;
float fsrV;
float fsrR;
float fsrG;


void setup(){
  // Set up serial and pin mode
  Serial.begin(9600);
  pinMode(FSR_PIN, INPUT);
}


void loop(){
  // Read pin
  fsrADC = analogRead(FSR_PIN);

  // Use ADC reading to calculate voltage:
  fsrV = fsrADC * VCC / 1023.0;

  // Use voltage and static resistor value to calculate FSR resistance:
  fsrR = R_DIV * (VCC / fsrV - 1.0);

  // Guesstimate force based on slopes in figure 3 of FSR datasheet (conductance):
  fsrG = 1.0 / fsrR;

  // Break parabolic curve down into two linear slopes:
  if (fsrR <= 600)
    force = (fsrG - 0.00075) / 0.00000032639;
  else
    force =  fsrG / 0.000000642857;

  // Display data and small pause
  Serial.println("Force: " + String(force) + " g");
  delay(1);
}
