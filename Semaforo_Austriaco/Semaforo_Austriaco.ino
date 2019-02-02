int r = 5;
int y = 6;
int g = 7;
int r1 = 8;
int y1 = 9;
int g1 = 10;

void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  
  VerdeRossoGiallo(r1, r, g1);
        
  VerdeRossoGiallo(r, r1, g);
}

void VerdeRossoGiallo(int r_off, int r_on, int g){
  digitalWrite(r_off, LOW);
  digitalWrite(y, LOW);    
  digitalWrite(y1, LOW);
  digitalWrite(r_on, HIGH);
  digitalWrite(g, HIGH);
  delay(1000);   
  
  Lampeggia(g, 400, 4);
  
  digitalWrite(g, LOW);
  digitalWrite(y1, HIGH);
  digitalWrite(y, HIGH);    
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
