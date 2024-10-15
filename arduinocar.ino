#define pinSensorDireito 11
#define pinSensorEsquerdo 12
//o número ao lado é a porta aonde o fio do carrinho está conectado no sensor
//exemplo com dois sensores apenas

#define pinMotorE1 3
#define pinMotorE2 5
#define pinMotorD1 6
#define pinMotorD2 9

#define velocidade 70

void setup() {
//parte da configuração do projeto
	pinMode(pinSensorD, INPUT);
	pinMode(pinSensorE, INPUT); 

	pinMode(pinMotorD1, OUTPUT);
	pinMode(pinMotorD2, OUTPUT);
	pinMode(pinMotorE1, OUTPUT);
	pinMode(pinMotorE2, OUTPUT);
}

void loop() {
// parte da lógica que precisa ler o sensor
	bool estadoD = !digitalRead(pinSensorDireito);
	bool estadoE = !digitalRead(pinSensorEsquerdo);
//ler os sensores, estado seria o lugar da memória para armazenar a leitura

	if (estadoD  && estadoE) {
	analogWrite(pinMotor1, velocidade);
	digitalWrite(pinMotor2, velocidade);
}
	if (!estadoD && !estadoE) {
	digitalWrite(pinMotorD1, LOW);
	digitalWrite(pinMotorD2, LOW);
	digitalWrite(pinMotorE1, LOW);
	digitalWrite(pinMotorE2, LOW);
//se não houver reflexo nos dois sensores que poderia significar que o robo esta em um cruzamento ou saiu da mesa então o motor para
	}
	if (!estadoD && estadoE) {
	digitalWrite(pinMotorE1, Low);
	analogWrite(pinMotorE2, velocidade);
	digitalWrite(pinMotorD1, LOW);
	analogWrite(pinMotorD2, velocidade);
//se caso apenas um sensor estiver sem reflexo ele faz a curva para continuar na linha, nesse caso o sensor direito não tem reflexo então ele vira para direita
}
if (estadoD && !estadoE) {
	digitalWrite(pinMotorD2, LOW);
	analogWrite(pinMotorD1, velocidade);
	digitalWrite(pinMotorE2, LOW);
	analogWrite(pinMotorE1, velocidade);
	//ligar o motor D2 e o E1 que seria o sentido inverso deixa o carrinho mais esperto para seguir a linha.
	}
}
