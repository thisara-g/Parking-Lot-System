//including the IR library and intiating the IR reciever
#include<IRremote.h>
IRrecv irrecv(3);
decode_results results;

//including the RFID libraries and defining the pins and setting up the initial conditions
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           
#define SS_PIN          10          

MFRC522 mfrc522(SS_PIN, RST_PIN);   

MFRC522::MIFARE_Key key;

//defining the output LEDs
int left_led = 5; //p6
int forward_led = 7; //p4
int right_led = 6; //p5
int red_led = 4; //p7

//defining the input buttons
int button = 2;

//defining states
bool start = true;
bool junction1 = false;
bool junction2 = false;
bool finish = false;
bool irrec = true;
bool full = false;
int button_state = 0;

//defining the data array
int parking_lots[] = {3,3,3,3,3,3,3,3};
int directions [] = {3,3};

void setup() {

  Serial.begin(9600);

  //defining the LEDs as the outputs
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  //defining the button as an input
  pinMode(2,INPUT);

  //starting sequence
  for (int m = 0; m<3; m++){
    digitalWrite(red_led,HIGH);
    delay(100);
    digitalWrite(red_led,LOW);
    delay(100);
    digitalWrite(forward_led,HIGH);
    delay(100);
    digitalWrite(forward_led,LOW);
    delay(100);
    digitalWrite(right_led,HIGH);
    digitalWrite(left_led,HIGH);
    delay(100);
    digitalWrite(right_led,LOW);
    digitalWrite(left_led,LOW);
    delay(100);
  }

  //initializing the Serial communication with the IR sensor
  irrecv.enableIRIn();

  //initializing the RFID module
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  // Prepare the key (used both as key A and as key B)
  // using FFFFFFFFFFFFh which is the default at chip delivery from the factory
  for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
  }
}

void loop() {
  
  //initializing the button
  button_state = digitalRead(button);
  if (button_state == 1){
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)

    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);

    // Check for compatibility
    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        return;
    }

    // In this sample we use the second sector,
    // that is: sector #1, covering block #4 up to and including block #7
    byte sector         = 1;
    byte blockAddr      = 4;
    byte trailerBlock   = 7;
    MFRC522::StatusCode status;
    byte buffer[18];
    byte size = sizeof(buffer);

    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);

    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key, &(mfrc522.uid));

    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);

    for (byte i = 0; i < 8; i++) {
      // Compare buffer (= what we've read) with dataBlock (= what we've written)
      parking_lots[i] = buffer[i];
    }

    // Halt PICC
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
  }
  
  //checking whether data is entered through RFID
  if (parking_lots[0] == 3){
    digitalWrite(red_led,HIGH);
    delay(500);
    digitalWrite(red_led,LOW);
    delay(500);
  }
  //checking whether the car park is full 
  else if (full == true){
    digitalWrite(red_led,HIGH);
  }
  else{
  
  //finding whether the car park is full 
  int sum = 0;
  for (int i = 0;i<8;i++){
    sum += parking_lots[i];
  }
  if (sum == 0){
    full = true;
  }

  //if the car park is not full, then finding the directions
  else{

    //finding the directions within the first square
    int junction_counter = 0;
    for (int j = 1;j<6;j += 4){
      if (parking_lots[j] == 1){
        if (junction_counter == 1){
          directions[junction_counter - 1] = 1;
        }
        directions[junction_counter] = 0;
        break;
      }
      else if (parking_lots[j+1] == 1){
        if (junction_counter == 1){
          directions[junction_counter - 1] = 1;
        }
        directions[junction_counter] = 2;
        break;
      }
      junction_counter += 1;
    }

    //finding the directions within the second square
    if (junction_counter == 2){
      junction_counter = 0;
      for (int j = 0;j<6;j += 4){
        if (parking_lots[j] == 1){
          if (junction_counter == 1){
            directions[junction_counter - 1] = 1;
          }
          directions[junction_counter] = 0;
          break;
        }
        else if (parking_lots[j+3] == 1){
          if (junction_counter == 1){
            directions[junction_counter - 1] = 0;
          }
          directions[junction_counter] = 2;
          break;
        }
        junction_counter += 1;
      }
    }

    //Deciding which junction the car is in
    if(irrecv.decode(&results) && irrec == true){
      if(results.value == 0x1020 || results.value == 0x1820){
        start = false;
        junction1 = true;
        junction2 = false;
        digitalWrite(red_led,HIGH);
        delay(50);
        digitalWrite(red_led,LOW);
        delay(50);
      }
      else if(results.value == 0x1021 || results.value == 0x1821){
        start = false;
        junction1 = false;
        junction2 = true;
        digitalWrite(red_led,HIGH);
        delay(50);
        digitalWrite(red_led,LOW);
        delay(50);
      }
      irrecv.resume();
    }


    //giving directions with the bulbs
    if (start == true){
      digitalWrite(forward_led,HIGH); 
      digitalWrite(left_led,LOW);
      digitalWrite(right_led,LOW);
    }
    else if (junction1 == true){
      if (directions[0] == 0){
        digitalWrite(forward_led,LOW); 
        digitalWrite(left_led,HIGH);
        digitalWrite(right_led,LOW);
        junction1 = false;
        finish = true;
        delay(5000);
      }
      else if (directions[0] == 1){
        digitalWrite(forward_led,HIGH); 
        digitalWrite(left_led,LOW);
        digitalWrite(right_led,LOW);
      }
      else if (directions[0] == 2){
        digitalWrite(forward_led,LOW); 
        digitalWrite(left_led,LOW);
        digitalWrite(right_led,HIGH);
        junction1 = false;
        finish = true;
        delay(5000);
      }
    }
    else if (junction2 == true){
      if (directions[1] == 0){
        digitalWrite(forward_led,LOW); 
        digitalWrite(left_led,HIGH);
        digitalWrite(right_led,LOW);
        junction2 = false;
        finish = true;
        delay(5000);
      }
      else if (directions[1] == 2){
        digitalWrite(forward_led,LOW); 
        digitalWrite(left_led,LOW);
        digitalWrite(right_led,HIGH);
        junction2 = false;
        finish = true;
        delay(5000);
      }
    }
    
    if (finish == true){
      for (int l = 0; l<50; l++){
        digitalWrite(forward_led,HIGH); 
        digitalWrite(left_led,HIGH);
        digitalWrite(right_led,HIGH);
        delay(100);
        digitalWrite(forward_led,LOW); 
        digitalWrite(left_led,LOW);
        digitalWrite(right_led,LOW);
        delay(100);
      }
      finish = false;
      irrec = false;
      int parking_lots[] = {3,3,3,3,3,3,3,3};
    }
    delay(100);
  }
}
}

