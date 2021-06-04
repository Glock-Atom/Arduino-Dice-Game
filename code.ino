//Button for 2 Players
int taster = 2;
int taster2 = 12;

//LEDs for Dice
int untenLinks = 3;
int mitteLinks = 4;
int obenLinks = 5;
int mitte = 6;
int untenRechts = 7;
int mitteRechts = 8;
int obenRechts = 9;

//Playerpoints
int gruenScore = 0;
int blauScore = 0;

//Player display LEDs
int gruen = 10;
int blau = 11;

//ButtonState
int stellung = 0;
int stellung2 = 0;

//Declare random numbers
long zufallZahl; 


//All LEDs as OUTPUT and all buttons as INPUT
void setup(){
  pinMode(untenLinks, OUTPUT);
  pinMode(mitteLinks, OUTPUT);
  pinMode(obenLinks, OUTPUT);
  pinMode(mitte, OUTPUT);
  pinMode(untenRechts, OUTPUT);
  pinMode(mitteRechts, OUTPUT);
  pinMode(obenRechts, OUTPUT);
  
  //PlayerDisplay
  pinMode(gruen, OUTPUT);
  pinMode(blau, OUTPUT);
  
  //Button as INPUT
  pinMode(taster, INPUT);
  pinMode(taster2, INPUT);
  //Serielle Schnittstelle für Serielle Monitor
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

 void loop(){
	//Read whether the button was pressed, if so, roll the dice
	if (digitalRead(taster) == HIGH && stellung == 0){
		stellung = 1;
		zufallZahl = random(1, 7); //random number between 1-6
		delay(100);
        //Add every round the Points
        gruenScore = gruenScore + zufallZahl;
        //Print Points in Serial Monitor
      	Serial.print("Gruen: ");
		Serial.println(zufallZahl);
        Serial.print("Gruen Punkte: ");
      	Serial.println(gruenScore);
      	Serial.println("-------------");
		digitalWrite(gruen, HIGH);
      	digitalWrite(blau, LOW);

      	//Check which random number has come, then call the associated function
		if (zufallZahl == 6){
			sechs();
		}
		if (zufallZahl == 5){
			fuenf();
		}
		if (zufallZahl == 4){
			vier();
		}
		if (zufallZahl == 3){
			drei();
		}
		if (zufallZahl == 2){
			zwei();
		}
		if (zufallZahl == 1){
			eins();
		}
		delay(1000);
		allesloeschen();
		stellung = 0;
	}
   
   ////////////////////////////////////////////////////
   
   //Player 2
   if (digitalRead(taster2) == HIGH && stellung == 0){
		stellung2 = 1;
		zufallZahl = random(1, 7); 
		delay(100);
     	blauScore = blauScore + zufallZahl;
		Serial.print("Blau: ");
     	Serial.println(zufallZahl);
     	Serial.print("Blau Punkte: ");
      	Serial.println(blauScore);
     	Serial.println("-------------");
		digitalWrite(gruen, LOW);
      	digitalWrite(blau, HIGH);

		if (zufallZahl == 6){
			sechs2();
            
          
		}
		if (zufallZahl == 5){
			fuenf2();
		}
		if (zufallZahl == 4){
			vier2();
		}
		if (zufallZahl == 3){
			drei2();
		}
		if (zufallZahl == 2){
			zwei2();
		}
		if (zufallZahl == 1){
			eins2();
		}
		delay(1000);
		allesloeschen();
		stellung = 0;
	}
   
   
   if(gruenScore >= 21){
     for(int i = 0; i<3;i++){ //3-mal blinken
       digitalWrite(gruen, HIGH);
       delay(500);
	   digitalWrite(gruen, LOW);
       delay(500);
       }
       Serial.println("Gruen hat gewonnen!");//Ausgabe im Seriellen Monitor
   }
   
   if(blauScore >= 21){
     for(int i = 0; i<3;i++){ //3-mal blinken
       digitalWrite(blau, HIGH);
       delay(500);
	   digitalWrite(blau, LOW);
       delay(500);
       }
       Serial.println("Blau hat gewonnen!");
     
   }
   
 }


//Creating functions for every side of the dice player1
 void sechs()
{
  digitalWrite(untenLinks, HIGH);
  	delay(500);
  digitalWrite(mitteLinks, HIGH);
  	delay(500);
  digitalWrite(obenLinks, HIGH);
  	delay(500);   
  digitalWrite(untenRechts, HIGH);
  	delay(500);
  digitalWrite(mitteRechts, HIGH);
     delay(500);
  digitalWrite(obenRechts, HIGH);
     delay(500);
   gruenScore = gruenScore + 2;
   

}

void fuenf()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(untenLinks, HIGH);
	digitalWrite(mitte, HIGH);
	digitalWrite(obenRechts, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void vier()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(untenLinks, HIGH);
	digitalWrite(obenRechts, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void drei()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(mitte, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void zwei()
{
	digitalWrite(untenRechts, HIGH);
	digitalWrite(obenLinks, HIGH);
}

void eins(){
	digitalWrite(mitte, HIGH);
}

/////////////////////////////////////////////////
//for player2
void sechs2()
{
  digitalWrite(untenLinks, HIGH);
  	delay(500);
  digitalWrite(mitteLinks, HIGH);
  	delay(500);
  digitalWrite(obenLinks, HIGH);
  	delay(500);   
  digitalWrite(untenRechts, HIGH);
  	delay(500);
  digitalWrite(mitteRechts, HIGH);
     delay(500);
  digitalWrite(obenRechts, HIGH);
     delay(500);
  blauScore = blauScore +2;

}

void fuenf2()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(untenLinks, HIGH);
	digitalWrite(mitte, HIGH);
	digitalWrite(obenRechts, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void vier2()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(untenLinks, HIGH);
	digitalWrite(obenRechts, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void drei2()
{
	digitalWrite(obenLinks, HIGH);
	digitalWrite(mitte, HIGH);
	digitalWrite(untenRechts, HIGH);
}

void zwei2()
{
	digitalWrite(untenRechts, HIGH);
	digitalWrite(obenLinks, HIGH);
}

void eins2(){
	digitalWrite(mitte, HIGH);
}
////////////////

//delete all
void allesloeschen(){
	digitalWrite(untenLinks, LOW);
	digitalWrite(mitteLinks, LOW);
	digitalWrite(obenLinks, LOW);
	digitalWrite(mitte,LOW);
	digitalWrite(untenRechts, LOW);
	digitalWrite(mitteRechts, LOW);
	digitalWrite(obenRechts, LOW);
}
