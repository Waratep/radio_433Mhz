#define rfReceivePin A0  
#define pulsein 10
#define ledPin 13        
unsigned int data = 0,fre0 = 0,fre1 = 0;   
int count_bit = 0;
int a = 0;

void setup(){
   pinMode(ledPin, OUTPUT);
   Serial.begin(9600);
}

void loop(){
  
   data = pulseIn(pulsein,1);    

   if (data > 17000 and data < 20000){
      fre1++;
      if(fre1 == 5){
//        Serial.print(1);
        fre1 = 0;
        count_bit++;
      }
   }
   if (data > 7000 and data < 10000) {
      fre0++;
      if(fre0 == 10){
//        Serial.print(0);
        fre0 = 0;
        count_bit++;
      }
   }

   if(count_bit == 8){
      count_bit = 0;
   }
   Serial.println(data);

}


