int r  = 5;
int y  = 6;
int g  = 7;
int r1 = 8;
int y1 = 9;
int g1 = 10;
int n_lamp   = 0;  
int t_lamp   = 0;
int t_rosso  = 0;    //v + g
int t_giallo = 0;    // r - v

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  Serial.print("Digita il numero di lampeggi del verde");
  Input(n_lamp);
  Serial.print("Digita il tempo di intervallo per i lampeggi del verde");
  Input(t_lamp);
}

void loop() {
  Lato(r1, r, g1);
  Lato(r, r1, g);
}

void Lato(int r_off, int r_on, int g){
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


void Input(int var){
  while (Serial.available() == 0) {};
  var = Serial.readString().toInt();
}


void Lampeggia( int led, int t_lamp, int n_lamp){
    for (int i = 0; i <= n_lamp; i++){
    delay(t_lamp);
    digitalWrite(led, LOW);
    delay(t_lamp);
    digitalWrite(led, HIGH);
  }
}
