/*******************************************************************************
* RoboCore Kit Iniciante V8 para Arduino - 22. Projeto Dado Eletrônico
* Sorteia e exibe valores de 1 a 8 no display de 7 segmentos
*******************************************************************************/
//Pinos responsáveis pelo código BCD
const int pino_a = 12;
const int pino_b = 9;
const int pino_c = 10;
const int pino_d = 11;

//Pino para o botão de sorteio
const int pino_botao = 2 ; 
const int pinVec[4] = { pino_a, pino_b, pino_c, pino_d };
int binaryNum[32];

int  leitura_botao, resultado; //  variáveis para leitura do botão 

void invertBinArray(){
   int auxArr[4]; 
    for(int i=0; i<4; i++){
      auxArr[i] = binaryNum[3-i];
   }
   memset(binaryNum, 0, sizeof(binaryNum));
     for(int i=0; i<4; i++){
      binaryNum[i] = auxArr[i];
   }
}


void decToBinary(int n){
   // counter for binary array 
    int i = 0; 
    while (n > 0) { 
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    invertBinArray();
}

void setup() {
  Serial.begin(9600);
  //Configuraçao dos pinos do código BCD
  pinMode(pino_a, OUTPUT); //digito menos significativo
  pinMode(pino_b, OUTPUT);
  pinMode(pino_c, OUTPUT);
  pinMode(pino_d, OUTPUT); //digito mais significativo

  pinMode(pino_botao, INPUT_PULLUP); //pino para o botão de sorteio
}

void loop() {
  memset(binaryNum, 0, sizeof(binaryNum));
  leitura_botao = digitalRead(pino_botao); // leitura do botão
  if (leitura_botao == LOW) {  // verifica se o botão foi pressionado
    delay(150); // delay de 100 ms para que o código não fique sorteando diversos números
    resultado = random(1, 7);// sorteia valores de 1 a 8
    decToBinary(resultado);
    Serial.print("----------------");
    Serial.print(" ");
    Serial.println(resultado);
    switch (resultado) { // verifica em qual case o valor da variável resultado é igual
      case 1: // aciona os pinos para o dígito 1, caso o valor da váriavel resultado seja igual a 1
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

      case 2: // aciona os pinos para o dígito 2, caso o valor da váriavel resultado seja igual a 2
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

      case 3: // aciona os pinos para o dígito 3, caso o valor da váriavel resultado seja igual a 3
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

      case 4: // aciona os pinos para o dígito 4, caso o valor da váriavel resultado seja igual a 4
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

      case 5: // aciona os pinos para o dígito 5, caso o valor da váriavel resultado seja igual a 5
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

      case 6: // aciona os pinos para o dígito 6, caso o valor da váriavel resultado seja igual a 6
        for(int i=0;i<sizeof(pinVec)/sizeof(pinVec[0]);i++)
            digitalWrite(pinVec[i], binaryNum[3-i]);
      break; // encerra o switch

    }
  }
}
