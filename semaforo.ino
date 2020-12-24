const int semaforo1[] = {
  2, 3, 4
},
cruce1[] = {
  5, 6
},
semaforo2[] = {
  7, 8, 9
},
cruce2[] = {
  10, 11
},
duracion_verde_rojo = 2000,
duracion_amarillo = 1000,
duracion_parpadeo = 150;
const boolean DEBUG = true;


void encender_verde_semaforo_1() {
  digitalWrite(semaforo1[0], HIGH);
  if (DEBUG) Serial.println("Semaforo 1: VERDE");
}


void apagar_verde_semaforo_1() {
  digitalWrite(semaforo1[0], LOW);
}

void parpadear_verde_semaforo_1() {
  if (DEBUG) Serial.println("Semaforo 1: VERDE PARPADEANDO");
  for (int x = 0; x < 2; x++) {
    digitalWrite(semaforo1[0], HIGH);
    delay(duracion_parpadeo);
    digitalWrite(semaforo1[0], LOW);
    delay(duracion_parpadeo);
  }
  if (DEBUG) Serial.println("Semaforo 1: VERDE HA TERMINADO DE PARPADEAR");
}
void encender_amarillo_semaforo_1() {
  if (DEBUG) Serial.println("Semaforo 1: AMARILLO");
  digitalWrite(semaforo1[1], HIGH);
}


void apagar_amarillo_semaforo_1() {
  digitalWrite(semaforo1[1], LOW);
}

void encender_rojo_semaforo_1() {
  if (DEBUG) Serial.println("Semaforo 1: ROJO");
  digitalWrite(semaforo1[2], HIGH);
}


void apagar_rojo_semaforo_1() {
  digitalWrite(semaforo1[2], LOW);
}


void encender_verde_semaforo_2() {
  if (DEBUG) Serial.println("Semaforo 2: VERDE");
  digitalWrite(semaforo2[0], HIGH);
}


void apagar_verde_semaforo_2() {
  digitalWrite(semaforo2[0], LOW);
}

void parpadear_verde_semaforo_2() {
  if (DEBUG) Serial.println("Semaforo 2: VERDE PARPADEANDO");
  for (int x = 0; x < 2; x++) {
    digitalWrite(semaforo2[0], HIGH);
    delay(duracion_parpadeo);
    digitalWrite(semaforo2[0], LOW);
    delay(duracion_parpadeo);
  }
  if (DEBUG) Serial.println("Semaforo 2: VERDE HA TERMINADO DE PARPADEAR");
}
void encender_amarillo_semaforo_2() {
  if (DEBUG) Serial.println("Semaforo 2: AMARILLO");
  digitalWrite(semaforo2[1], HIGH);
}


void apagar_amarillo_semaforo_2() {
  digitalWrite(semaforo2[1], LOW);
}

void encender_rojo_semaforo_2() {
  if (DEBUG) Serial.println("Semaforo 2: ROJO");
  digitalWrite(semaforo2[2], HIGH);
}


void apagar_rojo_semaforo_2() {
  digitalWrite(semaforo2[2], LOW);
}

void esperar_duracion_verde_o_rojo() {
  if (DEBUG) Serial.println("Esperando que acabe el tiempo del verde o del rojo");
  delay(duracion_verde_rojo);
  if (DEBUG) Serial.println("Tiempo del verde o del rojo terminado");
}
void esperar_duracion_amarillo() {
  if (DEBUG) Serial.println("Esperando que acabe el tiempo del amarillo");
  delay(duracion_amarillo);
  if (DEBUG) Serial.println("Tiempo del amarillo terminado");
}

void parpadear_verde_cruce_1() {
  if (DEBUG) Serial.println("Cruce peatonal 1: VERDE PARPADEANDO");
  for (int x = 0; x < 5; x++) {
    digitalWrite(cruce1[0], HIGH);
    delay(duracion_parpadeo);
    digitalWrite(cruce1[0], LOW);
    delay(duracion_parpadeo);
  }
  if (DEBUG) Serial.println("Cruce peatonal 1: VERDE HA TERMINADO DE PARPADEAR");
}

void encender_verde_cruce_1() {
  if (DEBUG) Serial.println("Cruce peatonal 1: VERDE");
  digitalWrite(cruce1[0], HIGH);
}
void apagar_verde_cruce_1() {
  digitalWrite(cruce1[0], LOW);
}

void encender_rojo_cruce_1() {
  if (DEBUG) Serial.println("Cruce peatonal 1: ROJO");
  digitalWrite(cruce1[1], HIGH);
}
void apagar_rojo_cruce_1() {
  digitalWrite(cruce1[1], LOW);
}

void parpadear_verde_cruce_2() {
  if (DEBUG) Serial.println("Cruce peatonal 2: VERDE PARPADEANDO");
  for (int x = 0; x < 5; x++) {
    digitalWrite(cruce2[0], HIGH);
    delay(duracion_parpadeo);
    digitalWrite(cruce2[0], LOW);
    delay(duracion_parpadeo);
  }
  if (DEBUG) Serial.println("Cruce peatonal 2: VERDE HA TERMINADO DE PARPADEAR");
}

void encender_verde_cruce_2() {
  if (DEBUG) Serial.println("Cruce peatonal 2: VERDE");
  digitalWrite(cruce2[0], HIGH);
}
void apagar_verde_cruce_2() {
  digitalWrite(cruce2[0], LOW);
}

void encender_rojo_cruce_2() {
  if (DEBUG) Serial.println("Cruce peatonal 2: ROJO");
  digitalWrite(cruce2[1], HIGH);
}
void apagar_rojo_cruce_2() {
  digitalWrite(cruce2[1], LOW);
}
void setup() {
  if (DEBUG) Serial.begin(9600);
  for (int x = 0; x < 3; x++) {
    pinMode(semaforo1[x], OUTPUT);
    pinMode(semaforo2[x], OUTPUT);
  }
  for (int x = 0; x < 2; x++) {
    pinMode(cruce1[x], OUTPUT);
    pinMode(cruce2[x], OUTPUT);
  }
}

void loop() {
  if (DEBUG) Serial.println("\n");
  encender_verde_semaforo_1();
  encender_rojo_semaforo_2();
  encender_rojo_cruce_1();
  encender_verde_cruce_2();
  esperar_duracion_verde_o_rojo();


  parpadear_verde_semaforo_1();
  apagar_verde_semaforo_1();
  encender_amarillo_semaforo_1();
  parpadear_verde_cruce_2();


  apagar_rojo_semaforo_2();
  apagar_amarillo_semaforo_1();
  encender_verde_semaforo_2();
  encender_rojo_semaforo_1();
  apagar_rojo_cruce_1();
  encender_verde_cruce_1();
  apagar_verde_cruce_2();
  encender_rojo_cruce_2();
  esperar_duracion_verde_o_rojo();

  parpadear_verde_semaforo_2();
  apagar_verde_semaforo_2();
  encender_amarillo_semaforo_2();
  parpadear_verde_cruce_1();
  apagar_rojo_semaforo_1();
  apagar_amarillo_semaforo_2();
  apagar_verde_cruce_1();
  apagar_rojo_cruce_2();
}
