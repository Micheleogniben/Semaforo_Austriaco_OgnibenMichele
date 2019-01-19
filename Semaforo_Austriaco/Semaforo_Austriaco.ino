int Red1 = 5;
int Yellow1 = 6;
int Green1 = 7;
int Red = 8;
int Yellow = 9;
int Green = 10;

void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
         
  digitalWrite(Red1, LOW);
  digitalWrite(Yellow, LOW);    
  digitalWrite(Yellow1, LOW);
  digitalWrite(Red, HIGH);        //ROSSO
  digitalWrite(Green1, HIGH);
  delay(1000);   
  
  Lampeggia(Green1, 400, 4);
             
  digitalWrite(Green1, LOW);
  digitalWrite(Yellow1, HIGH);      //GIALLO
  digitalWrite(Yellow, HIGH);    
  delay(2000);  
        
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);    //VERDE
  digitalWrite(Yellow1, LOW);
  digitalWrite(Red1, HIGH);
  digitalWrite(Green, HIGH);
  delay(1000);
  
  Lampeggia(Green, 400, 4);
  
  digitalWrite(Green, LOW);     //GIALLO
  digitalWrite(Yellow, HIGH);
  digitalWrite(Yellow1, HIGH);
  delay(2000);
}


void Lampeggia( int led, int ritardo, int n){
    for (int i = 0; i <= n; i++){
    delay(ritardo);
    digitalWrite(led, LOW);
    delay(ritardo);
    digitalWrite(led, HIGH);
  }
}



