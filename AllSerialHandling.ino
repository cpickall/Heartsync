
void serialOutputWhenBeatHappens(){    
        sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
        sendDataToSerial('Q',IBI);   // send time between beats with a 'Q' prefix
}

void serialOutputWhenBeatHappens2(){    
        sendDataToSerial('       P',BPM);   // send heart rate with a 'B' prefix
        sendDataToSerial('       I',IBI);   // send time between beats with a 'Q' prefix
}


void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);
    Serial.println(data);                
  }






