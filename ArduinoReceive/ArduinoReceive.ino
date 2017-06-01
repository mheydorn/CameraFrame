#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define BAUD_RATE 57600

RF24 radio(10,14
);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

void setup(void)
{    
    pinMode(2, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    digitalWrite(7,HIGH);
    digitalWrite(3, HIGH);
    Serial.begin(BAUD_RATE);
    Serial.println("Starting up");
    
    radio.begin();    
    radio.setRetries(15,15);       
    radio.openReadingPipe(1,pipes[1]);    
    radio.startListening();    
    radio.openWritingPipe(pipes[1]);
    radio.openReadingPipe(1,pipes[0]);
}
String command = "";
String prevCommand = "";
char c = '~';
int Location2 = 2400;
bool ok;

void loop(void){    
    c = '~';
    
    if ( radio.available() )
    {      
        char got_time = 'p';
      
        bool done = false;
       
        while (!done)
        {
            
            done = radio.read( &got_time, sizeof(char) );
           
        }
        command.concat(got_time);
      
        c = got_time;         
        ok = c == 'e';
        if(ok){
            String tempCommand = "";
            bool hasNewLine = false;
            bool cont = true;
            for(int i = 0; i < command.length(); i++){
                if(cont){
                    if(command.charAt(i) == '\n'){
                        hasNewLine = true;
                    }
                    if(command.charAt(i) != '\n' && command.charAt(i) != 'e'){
                        tempCommand += command.charAt(i);
                    }
                    if(command.charAt(i) == '\n' || command.charAt(i) == 'e')    {
                        if(command.charAt(i) == 'e' && hasNewLine ){
                            cont = false;
                            }else{
                            proccess(tempCommand + 'e');
                            
                            tempCommand = "";
                        }
                    }
                }
            }
            command = "";
        }
       
        prevCommand = command;
        radio.startListening();
        
    }    
}
void proccess(String command){
    digitalWrite(2, HIGH);
    
    if(command == ""){
        return;
    }
    if(command.charAt(0) == 'd'){
        String delayTime = "";
        for(int i = 1; i < command.length(); i++){
            delayTime += command.charAt(i);
            
        }
        delay(delayTime.toInt());
        digitalWrite(2, LOW);
        return;
    }
    
    if(command.charAt(0) == 's'){
        sendSnapShotSignal();
        digitalWrite(2, LOW);
        
        return;
    }
    if(command.charAt(0) == 'a'){
        
        String angle = "";
        int i = 2;
        for(i = 2; i < command.length(); i++){
            angle += command.charAt(i);
            if(command.charAt(i) == ':'){
               break;
            } 
        }
        i++;
        if(angle.toInt() > 0){
            digitalWrite(7, HIGH);
        }
        if(angle.toInt() < 0){
            digitalWrite(7, LOW);
        }
        int turns = abs(AngleToSteps(angle.toInt()));
        //int turns = abs(angle.toInt());
        String delayBetweenSteps = "";
        for(;i< command.length(); i++){
           delayBetweenSteps += command.charAt(i);
        }
        moveMotor(turns, delayBetweenSteps.toInt());
    }
    digitalWrite(2, LOW);    
}

void moveMotor(int moves, int delayBetweenSteps){
    for(int i = 0 ; i < moves; i++){
                digitalWrite(8, HIGH);
                delayMicroseconds(delayBetweenSteps/2);
                digitalWrite(8, LOW);
                delayMicroseconds(delayBetweenSteps/2);

        /*        
        //if we're accelerating
        if(i < moves/2){
            
            if(i < 250*4){
                digitalWrite(8, HIGH);
                
                delayMicroseconds(400 - (i/4));
                digitalWrite(8, LOW);
                
                delayMicroseconds(400- (i/4));
                }else{
                digitalWrite(8, HIGH);
                
                delayMicroseconds(150);
                digitalWrite(8, LOW);
                
                delayMicroseconds(150);
            }
        }
        //if we're decelerating
        if(i >= moves/2){
            //return;
            if((moves - i) > 250*4){
                digitalWrite(8, HIGH);
                
                delayMicroseconds(150);
                digitalWrite(8, LOW);
                
                delayMicroseconds(150);
                
                }else{
                digitalWrite(8, HIGH);
                
                delayMicroseconds(400 + (i - moves)/4);
                digitalWrite(8, LOW);
                
                delayMicroseconds(400 + (i - moves)/4);
                
            }
        }  
      */        
    }        
}

//This function is for the rotation motor (motor 1)
int AngleToSteps(int angle){
    return (int)(angle*26.66666666666666666666666);
}

void send(char c){
    bool ok = false;
    while(!ok){
        
        delay(8);
        ok = radio.write(&c, sizeof(char));
    }
}
void sendSnapShotSignal(){
    radio.stopListening();
    send('_');
    send('s');
    
    radio.startListening();
}
