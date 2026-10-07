// ===== BOTONES =====
const int boton1 = 2;  // Adelante
const int boton2 = 3;  // Atrás
const int boton3 = 4;  // Derecha
const int boton4 = 5;  // Izquierda

// ===== DRIVER LADO IZQUIERDO =====
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 9;

// ===== DRIVER LADO DERECHO =====
const int IN3 = 8;
const int IN4 = 12;
const int ENB = 10;

// Velocidad de los motores
const int velocidad = 200;

void setup() {

  // Botones
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
  pinMode(boton4, INPUT_PULLUP);

  // Motor izquierdo
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Motor derecho
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  detener();
}

void loop() {

  if (digitalRead(boton1) == LOW) {
    adelante();
  }

  else if (digitalRead(boton2) == LOW) {
    atras();
  }

  else if (digitalRead(boton3) == LOW) {
    derecha();
  }

  else if (digitalRead(boton4) == LOW) {
    izquierda();
  }

  else {
    detener();
  }
}

// ===== ADELANTE =====
void adelante() {

  // Lado izquierdo
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Lado derecho
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

// ===== ATRÁS =====
void atras() {

  // Lado izquierdo
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Lado derecho
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

// ===== GIRAR DERECHA =====
void derecha() {

  // Izquierdos adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Derechos atrás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

// ===== GIRAR IZQUIERDA =====
void izquierda() {

  // Izquierdos atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Derechos adelante
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

// ===== DETENER =====
void detener() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}