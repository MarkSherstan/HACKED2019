// Declare some variables
const int FSR_PIN[] = {0, 1, 2, 3, 4, 5, 6, 7};

const float VCC = 4.98;
const float R_DIV = 5100.0;
 
int fsrADC;
float force[8];
float fsrV;
float fsrR;
float fsrG;

String label = "foo\n";

void setup(){
  // Set up serial and pin mode
  Serial.begin(57600);
  for (int i=0;i<8;i++){
  pinMode(FSR_PIN[i], INPUT);
  }
}


void loop(){

if (Serial.available() > 0) {
                // read the incoming byte:
  label = Serial.readString();
    
  }

  for (int i=0; i<8;i++){
      // Read pin
    fsrADC = analogRead(FSR_PIN[i]);
  
    // Use ADC reading to calculate voltage:
    fsrV = fsrADC * VCC / 1023.0;
  
    // Use voltage and static resistor value to calculate FSR resistance:
    fsrR = ((VCC - fsrV) * R_DIV) / fsrV;
  
    // Guesstimate force based on slopes in figure 3 of FSR datasheet (conductance):
    fsrG = 1.0 / fsrR;
  
    // Break parabolic curve down into two linear slopes:
    if (fsrR <= 600)
      force[i] = (fsrG - 0.00075) / 0.00000032639;  
    else
      force[i] =  fsrG / 0.000000642857;
    
  }


  // Display data [in grams] and add small pause
    for (int i=0; i<8; i++){
        Serial.print(force[i]);
        Serial.print(',');
    }
    Serial.print(label);
    delay(1);
}
