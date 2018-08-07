#define rfTransmitPin 10  
#define delay0 10
#define delay1 20

int state;    

void setup(){
   pinMode(rfTransmitPin, OUTPUT);  
   Serial.begin(9600);
   
}

void loop(){
   char inData = "";

   if (Serial.available() > 0) {

    inData = Serial.read();
    Serial.print("data : ");
    Serial.print(inData);
    Serial.print("   0x");
    Serial.println(inData, HEX);
    state = !state;
                           
    if (state and inData != 0x0D and inData != 0x0A) {
      for(int i = 0 ; i < 8 ; i++){
        int tmp = inData & 1;
        Serial.print("inData =  ");
        Serial.print(inData, BIN );
        Serial.print("   tmp =  ");
        Serial.print(tmp );

       if(tmp == 0){
        for (int sl = 0; sl < 10; sl++) {
          digitalWrite(rfTransmitPin, HIGH);                          
          delay(delay0);
          digitalWrite(rfTransmitPin, LOW);
          delay(delay0);
        }
       }
       else if(tmp == 1){
        for (int sl = 0; sl < 5; sl++) {
          digitalWrite(rfTransmitPin, HIGH);                                      
          delay(delay1);
          digitalWrite(rfTransmitPin,LOW); 
          delay(delay1);
        }
       }
       inData >>= 1;
       Serial.println();
      }
     state = !state;
    }
   }
   digitalWrite(rfTransmitPin, HIGH);
   delayMicroseconds(50);
   digitalWrite(rfTransmitPin, LOW);
   delayMicroseconds(50);}
