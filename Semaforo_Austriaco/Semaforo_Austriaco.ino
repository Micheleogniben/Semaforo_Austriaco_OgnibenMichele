            //  linea 1
int r  = 5;
int y  = 6;
int g  = 7;
            //  linea 2
int r1 = 8;
int y1 = 9;
int g1 = 10;
            //  variabili input
int n_lamp;  
int t_lamp;
int t_verde;
int t_giallo;

void setup() {
  pinMode(r,  OUTPUT);
  pinMode(y,  OUTPUT);
  pinMode(g,  OUTPUT);
  pinMode(r1,  OUTPUT);
  pinMode(y1,  OUTPUT);
  pinMode(g1, OUTPUT);
  Serial.begin(9600);                       //  tempo rosso = tempo verde + (tempo lampeggi verde * lampeggi) + tempo giallo
  n_lamp   = input("Quanti lampeggi deve fare il verde?", n_lamp, " lampeggi");
  t_lamp   = input("Quanti millisecondi devono durare i lampeggi del verde?", t_lamp, " millisecondi");
  t_verde  = input("Quanti millisecondi deve stare acceso il verde?", t_verde, " millisecondi");
  t_giallo = input("Quanti millisecondi deve stare acceso il giallo?", t_giallo, " millisecondi");
}

void loop() {                               //  richiamo il metodo che verrà ripetuto 2 volte
  lato(r1, r, g1);
  lato(r, r1, g);
}
                                            //  accensione del verde e del rosso del lato opposto + spegnimento dei led gialli e rosso
void lato(int r_off, int r_on, int g){
  digitalWrite(r_off, LOW);
  digitalWrite(y, LOW);    
  digitalWrite(y1, LOW);
  digitalWrite(r_on, HIGH);
  digitalWrite(g, HIGH);
  delay(t_verde);   
                                            //  lampeggio del verde
  for (int i = 0; i <= n_lamp; i++){
    delay(t_lamp);
    digitalWrite(g, HIGH);
    delay(t_lamp);
    digitalWrite(g, LOW);
  }                                         //  accensione dei led gialli
  
  digitalWrite(y1, HIGH);
  digitalWrite(y, HIGH);    
  delay(t_giallo);  
}
                                            //  metodo utilizzato per assegnare i dati presi in input alle variabili
int input(String frase, int var , String frase2){
  Serial.println(frase);
  while (Serial.available() == 0) {};
  var = Serial.readString().toInt();
  Serial.println(var + frase2);
  return var;
}
