/*
 Stephen Cullen Apr 2015
 Capacitive touch sensor keyboard with MIDI project
 Coca cola cans used as keys. When touched a note is sent to a piezo pin
 Corresponding MIDI note also sent
 */

#include <CapacitiveSensorDue.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

int val = 100;

// Define Capacitive sensor inputs, pin 4 used as common pin
CapacitiveSensorDue cs_4_11 = CapacitiveSensorDue(4,11);  // 1M resistor between pins 4 & 11, pin 11 is sensor pin
CapacitiveSensorDue cs_4_2 = CapacitiveSensorDue(4,2);	  
CapacitiveSensorDue cs_4_3 = CapacitiveSensorDue(4,3);
CapacitiveSensorDue cs_4_5 = CapacitiveSensorDue(4,5);
CapacitiveSensorDue cs_4_6 = CapacitiveSensorDue(4,6);
CapacitiveSensorDue cs_4_7 = CapacitiveSensorDue(4,7);
CapacitiveSensorDue cs_4_8 = CapacitiveSensorDue(4,8);
CapacitiveSensorDue cs_4_10 = CapacitiveSensorDue(4,10);
CapacitiveSensorDue cs_4_A1 = CapacitiveSensorDue(4,A1);
CapacitiveSensorDue cs_4_A2 = CapacitiveSensorDue(4,A2);
CapacitiveSensorDue cs_4_A3 = CapacitiveSensorDue(4,A3);
CapacitiveSensorDue cs_4_A4 = CapacitiveSensorDue(4,A4);
int piezoPin = 9;    //Define pin 9 as piezo pin output
int sensorPin = 5;   //Define pin A5 as analog input from potentiometer
int sensorValue = 0; //Assign potentiometer value to variable

void setup()					
{
	Serial.begin(31250);
	MIDI.begin(1);
	pinMode(piezoPin, OUTPUT);  //Define pin 9 as output
	pinMode(12, OUTPUT);        //Define pin 12 as LED output
	pinMode(13, OUTPUT);        //Define pin 13 as LED output
	pinMode(A0, OUTPUT);        //Define pin A0 as LED output

}

void loop()					
{
	
	//long start = millis();
  //Assign Capacitive inputs to variables
	long total11 = cs_4_11.read(30);
	long total2 = cs_4_2.read(30);
	long total3 = cs_4_3.read(30);
	long total5 = cs_4_5.read(30);
	long total6 = cs_4_6.read(30);
	long total7 = cs_4_7.read(30);			
	long total8 = cs_4_8.read(30);
	long total10 = cs_4_10.read(30);
	long totalA1 = cs_4_A1.read(30);
	long totalA2 = cs_4_A2.read(30);			
	long totalA3 = cs_4_A3.read(30);
	long totalA4 = cs_4_A4.read(30);
	sensorValue =  analogRead(sensorPin);            //Read Value from potentiometer
	int octave = map (sensorValue, 0, 1023, 0, 3);   //Map value
	
	// LED for octave 0 is always lit due to lack of ports
	if (octave == 1){
	  digitalWrite (12, HIGH);
	  digitalWrite (13, LOW);
	  digitalWrite (A0, LOW); //2 LED's lit
	}
	else if (octave == 2){
	  digitalWrite (12, HIGH);
	  digitalWrite (13, HIGH);  //3 LED's lit
	  digitalWrite (A0, LOW);
	}
	else if (octave == 3){
	  digitalWrite (12, HIGH);
	  digitalWrite (13, HIGH);
	  digitalWrite (A0, HIGH);  //4 LED's lit
	}
	else{
	  digitalWrite (12, LOW);
	  digitalWrite (13, LOW);
	  digitalWrite (A0, LOW);
	}
              
  //If a can is touched...play corresponding note through piezo buzzer
  //and send corresponding MIDI note
  if (total11 > 100 && octave == 0){
    tone (piezoPin, 131);
    MIDI.sendNoteOn(60,127,1);
    delay(val);    
  }else if (total2 > 100 && octave == 0){
    tone (piezoPin, 138);                   //CSHARP3
    MIDI.sendNoteOn(61,127,1);  
    delay(val);
  }else if (total3 > 100 && octave == 0){
    tone (piezoPin, 146);                   //D3
    MIDI.sendNoteOn(62,127,1);  
    delay(val);
  }else if (total5 > 100 && octave == 0){
    tone (piezoPin, 156);                   //DSHARP3
    MIDI.sendNoteOn(63,127,1);  
    delay(val);
  }else if (total6 > 100 && octave == 0){
    tone (piezoPin, 165);                   //E3
    MIDI.sendNoteOn(64,127,1);  
    delay(val);
  }else if (total7 > 100 && octave == 0){
    tone (piezoPin, 175);                    //F3
    MIDI.sendNoteOn(65,127,1);  
    delay(val);
  }else if (total8 > 100 && octave == 0){
    tone (piezoPin, 185);                    //FSHARP3
    MIDI.sendNoteOn(66,127,1);  
    delay(val);
  }else if (total10 > 100 && octave == 0){
    tone (piezoPin, 196);                     //G3
    MIDI.sendNoteOn(67,127,1);  
    delay(val);
  }else if (totalA1 > 100 && octave == 0){
      tone (piezoPin, 208);                     //GSHARP3
      MIDI.sendNoteOn(68,127,1);  
      delay(val);
  }else if (totalA2 > 200 && octave == 0){
    tone (piezoPin, 220);                     //A3
    MIDI.sendNoteOn(69,127,1);  
    delay(val);
  }else if (totalA3 > 100 && octave == 0){
    tone (piezoPin, 233);                     //ASHARP3
    MIDI.sendNoteOn(70,127,1);  
    delay(val);
  }else if (totalA4 >100 && octave == 0){
    tone (piezoPin, 247);                      //B3
    MIDI.sendNoteOn(71,127,1);  
    delay(val);
      
  }else if (total11 > 100 && octave == 1){
    tone (piezoPin, 262);                      //C4
    MIDI.sendNoteOn(72,127,1);  
    delay(val);
  }else if (total2 > 100 && octave == 1){
    tone (piezoPin, 277);                      //CSHARP4
    MIDI.sendNoteOn(73,127,1);  
    delay(val);
  }else if (total3 > 100 && octave == 1){
    tone (piezoPin, 294);                      //D3
    MIDI.sendNoteOn(74,127,1);  
    delay(val);
  }else if (total5 > 100 && octave == 1){
    tone (piezoPin, 311);                      //DSHARP4
    MIDI.sendNoteOn(75,127,1);  
    delay(val);
  }else if (total6 > 100 && octave == 1){
    tone (piezoPin, 330);                      //E4
    MIDI.sendNoteOn(76,127,1);  
    delay(val);
  }else if (total7 > 100 && octave == 1){
    tone (piezoPin, 349);                      //F4
    MIDI.sendNoteOn(77,127,1);  
    delay(val);
  }else if (total8 > 100 && octave == 1){
    tone (piezoPin, 370);                      //FSHARP4
    MIDI.sendNoteOn(78,127,1);  
     delay(val);
  }else if (total10 > 100 && octave == 1){
    tone (piezoPin, 392);                      //G4
    MIDI.sendNoteOn(79,127,1);  
    delay(val);
  }else if (totalA1 > 100 && octave == 1){
    tone (piezoPin, 415);                      //GSHARP4
    MIDI.sendNoteOn(80,127,1);  
    delay(val);
  }else if (totalA2 > 200 && octave == 1){
    tone (piezoPin, 440);                      //A4
    MIDI.sendNoteOn(81,127,1);  
    delay(val);
  }else if (totalA3 > 100 && octave == 1){
    tone (piezoPin, 466);                      //ASHARP4
    MIDI.sendNoteOn(82,127,1);  
    delay(val);
  }else if (totalA4 >100 && octave == 1){
    tone (piezoPin, 494);                       //B4
    MIDI.sendNoteOn(83,127,1);  
    delay(val);
      
  }else if (total11 > 100 && octave == 2){
    tone (piezoPin, 523);                       //C5
    MIDI.sendNoteOn(84,127,1);  
    delay(val);
  }else if (total2 > 100 && octave == 2){
    tone (piezoPin, 554);                       //CSHARP5
    MIDI.sendNoteOn(85,127,1);  
    delay(val);
  }else if (total3 > 100 && octave == 2){
    tone (piezoPin, 587);                       //D5
    MIDI.sendNoteOn(86,127,1);  
    delay(val);
  }else if (total5 > 100 && octave == 2){
    tone (piezoPin, 622);                       //DSHARP5
    MIDI.sendNoteOn(87,127,1);  
    delay(val);
  }else if (total6 > 100 && octave == 2){
    tone (piezoPin, 659);                       //E5
    MIDI.sendNoteOn(88,127,1);  
    delay(val);
  }else if (total7 > 100 && octave == 2){
    tone (piezoPin, 698);                        //F5
    MIDI.sendNoteOn(89,127,1);  
    delay(val);
  }else if (total8 > 100 && octave == 2){
    tone (piezoPin, 740);                        //FSHARP5
    MIDI.sendNoteOn(90,127,1);  
    delay(val);
  }else if (total10 > 100 && octave == 2){
    tone (piezoPin, 784);                        //G5
    MIDI.sendNoteOn(91,127,1);  
    delay(val);
  }else if (totalA1 > 100 && octave == 2){
    tone (piezoPin, 831);                        //GSHARP5
    MIDI.sendNoteOn(92,127,1);  
    delay(val);
  }else if (totalA2 > 200 && octave == 2){
    tone (piezoPin, 880);                        //A5
    MIDI.sendNoteOn(93,127,1);  
    delay(val);
  }else if (totalA3 > 100 && octave == 2){
    tone (piezoPin, 932);                        //ASHARP5
    MIDI.sendNoteOn(94,127,1);  
    delay(val);
  }else if (totalA4 >100 && octave == 2){
    tone (piezoPin, 988);                        //B5
    MIDI.sendNoteOn(95,127,1);  
    delay(val);
      
  }else if (total11 > 100 && octave == 3){
    tone (piezoPin, 1047);                        //C-6
    MIDI.sendNoteOn(96,127,1);  
    delay(val);
  }else if (total2 > 100 && octave == 3){
    tone (piezoPin, 1109);                       //C-SHARP-6
    MIDI.sendNoteOn(97,127,1);  
    delay(val);
  }else if (total3 > 100 && octave == 3){
    tone (piezoPin, 1175);                       //D-6
    MIDI.sendNoteOn(98,127,1);  
    delay(val);
  }else if (total5 > 100 && octave == 3){
    tone (piezoPin, 1245);                       //D-SHARP-6
    MIDI.sendNoteOn(99,127,1);  
    delay(val);
  }else if (total6 > 100 && octave == 3){
    tone (piezoPin, 1319);                       //E-6
    MIDI.sendNoteOn(100,127,1);  
    delay(val);
  }else if (total7 > 100 && octave == 3){
    tone (piezoPin, 1397);                       //F-6
    MIDI.sendNoteOn(101,127,1);  
    delay(val);
  }else if (total8 > 100 && octave == 3){
    tone (piezoPin, 1480);                       //F-SHARP-6
    MIDI.sendNoteOn(102,127,1);  
    delay(val);
  }else if (total10 > 100 && octave == 3){
    tone (piezoPin, 1568);                       //G-6
    MIDI.sendNoteOn(103,127,1);  
    delay(val);
  }else if (totalA1 > 100 && octave == 3){
    tone (piezoPin, 1661);                       //G-SHARP-6
    MIDI.sendNoteOn(104,127,1);  
    delay(val);
  }else if (totalA2 > 200 && octave == 3){
    tone (piezoPin, 1760);                       //A-6
    MIDI.sendNoteOn(105,127,1);  
    delay(val);
  }else if (totalA3 > 100 && octave == 3){
    tone (piezoPin, 1865);                       //A-SHARP-6
    MIDI.sendNoteOn(106,127,1);  
    delay(val);
  }else if (totalA4 >100 && octave == 3){
    tone (piezoPin, 1976);                       //B-6
    MIDI.sendNoteOn(107,127,1);  
    delay(val);
  }
    //Stops tone and MIDI notes when no can is being touched
    else{     
      noTone(piezoPin);   
      
      MIDI.sendNoteOff(60,0,1);
      MIDI.sendNoteOff(61,0,1); 
      MIDI.sendNoteOff(62,0,1);
      MIDI.sendNoteOff(63,0,1);
      MIDI.sendNoteOff(64,0,1);
      MIDI.sendNoteOff(65,0,1);
      MIDI.sendNoteOff(66,0,1);
      MIDI.sendNoteOff(67,0,1);
      MIDI.sendNoteOff(68,0,1);
      MIDI.sendNoteOff(69,0,1);
      MIDI.sendNoteOff(70,0,1);
      MIDI.sendNoteOff(71,0,1);
      MIDI.sendNoteOff(72,0,1);
      MIDI.sendNoteOff(73,0,1); 
      MIDI.sendNoteOff(74,0,1);
      MIDI.sendNoteOff(75,0,1);
      MIDI.sendNoteOff(76,0,1);
      MIDI.sendNoteOff(77,0,1);
      MIDI.sendNoteOff(78,0,1);
      MIDI.sendNoteOff(79,0,1);
      MIDI.sendNoteOff(80,0,1);
      MIDI.sendNoteOff(81,0,1);
      MIDI.sendNoteOff(82,0,1);
      MIDI.sendNoteOff(83,0,1);
      MIDI.sendNoteOff(84,0,1);
      MIDI.sendNoteOff(85,0,1); 
      MIDI.sendNoteOff(86,0,1);
      MIDI.sendNoteOff(87,0,1);
      MIDI.sendNoteOff(88,0,1);
      MIDI.sendNoteOff(89,0,1);
      MIDI.sendNoteOff(90,0,1);
      MIDI.sendNoteOff(91,0,1);
      MIDI.sendNoteOff(92,0,1);
      MIDI.sendNoteOff(93,0,1);
      MIDI.sendNoteOff(94,0,1);
      MIDI.sendNoteOff(95,0,1);
      MIDI.sendNoteOff(96,0,1);
      MIDI.sendNoteOff(97,0,1); 
      MIDI.sendNoteOff(98,0,1);
      MIDI.sendNoteOff(99,0,1);
      MIDI.sendNoteOff(100,0,1);
      MIDI.sendNoteOff(101,0,1);
      MIDI.sendNoteOff(102,0,1);
      MIDI.sendNoteOff(103,0,1);
      MIDI.sendNoteOff(104,0,1);
      MIDI.sendNoteOff(105,0,1);
      MIDI.sendNoteOff(106,0,1);
      MIDI.sendNoteOff(107,0,1);
    }
    							
}
