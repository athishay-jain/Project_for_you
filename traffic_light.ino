//Trafic Light System 

// North
#define N_RED    2
#define N_YELLOW 3
#define N_GREEN  4

// East
#define E_RED    5
#define E_YELLOW 6
#define E_GREEN  7

// South
#define S_RED    8
#define S_YELLOW 9
#define S_GREEN  10

// West
#define W_RED    11
#define W_YELLOW 12
#define W_GREEN  13

void setup() {
  for(int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {

  // Phase 1: North & South Green
  digitalWrite(N_GREEN, HIGH);
  digitalWrite(S_GREEN, HIGH);

  digitalWrite(E_RED, HIGH);
  digitalWrite(W_RED, HIGH);

  digitalWrite(N_RED, LOW);
  digitalWrite(S_RED, LOW);

  delay(5000);

  // Phase 2: North & South Yellow
  digitalWrite(N_GREEN, LOW);
  digitalWrite(S_GREEN, LOW);

  digitalWrite(N_YELLOW, HIGH);
  digitalWrite(S_YELLOW, HIGH);

  delay(2000);

  digitalWrite(N_YELLOW, LOW);
  digitalWrite(S_YELLOW, LOW);

  digitalWrite(N_RED, HIGH);
  digitalWrite(S_RED, HIGH);

  // Phase 3: East & West Green
  digitalWrite(E_RED, LOW);
  digitalWrite(W_RED, LOW);

  digitalWrite(E_GREEN, HIGH);
  digitalWrite(W_GREEN, HIGH);

  delay(5000);

  // Phase 4: East & West Yellow
  digitalWrite(E_GREEN, LOW);
  digitalWrite(W_GREEN, LOW);

  digitalWrite(E_YELLOW, HIGH);
  digitalWrite(W_YELLOW, HIGH);

  delay(2000);

  digitalWrite(E_YELLOW, LOW);
  digitalWrite(W_YELLOW, LOW);

  digitalWrite(E_RED, HIGH);
  digitalWrite(W_RED, HIGH);
}
