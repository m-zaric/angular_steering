const int analogInPin0 = A0;
const int motorRightout = 5;
const int analogInPin1 = A1;
const int motorLeftout = 6;

int xAchseSensor = 0;
int yAchseSensor = 0;
float outputRight = 0;
float outputLeft = 0;
float scale = 0;
float deg = 0;


int main(){
    yAchseSensor = analogRead(analogInPin0);
    xAchseSensor = analogRead(analogInPin1);

   if (xAchseSensor > 530) {  // left hemisphere
    if (yAchseSensor < 530 && yAchseSensor > 476){
      outputRight = yAchseSensor;
      outputLeft = yAchseSensor;
    }else if(yAchseSensor > 530){
      deg = atan2((yAchseSensor - 530), (xAchseSensor - 530));
      outputRight = yAchseSensor;
      scale = ((deg-0.7853981)/(1.5687679-0.7853981))/2 + 0.5;
      outputLeft = yAchseSensor * scale;
      if (outputLeft < 512) outputLeft = 512;  
    }else{
      deg = atan2((475 - yAchseSensor), (xAchseSensor - 529));
      outputRight = yAchseSensor;
      scale = ((deg-0.7657928325402437)/(1.5665858253609926-0.7657928325402437));
      outputLeft = yAchseSensor + ((512-yAchseSensor)* (1-scale));
      if (outputLeft > 512) outputLeft = 512;
    }
  } else if (xAchseSensor < 474) {  // right hemisphere
        if (yAchseSensor < 530 && yAchseSensor > 476){
          outputRight = yAchseSensor;
          outputLeft = yAchseSensor;
        }else if (yAchseSensor > 530){
          deg = atan2((yAchseSensor - 529), (xAchseSensor));
          outputLeft = yAchseSensor;
          scale = 1 - ((deg-0.8071113998439905)/(1.5707963267948966-0.8071113998439905))/2;
          outputRight = yAchseSensor * scale;  
          if (outputRight < 512) outputRight = 512;
        }else{
          deg = atan2((475 - yAchseSensor), (xAchseSensor));
          outputLeft = yAchseSensor;
          scale = 1 - ((deg-0.7875078649088113)/(1.5707963267948966-0.7875078649088113));
          outputRight = yAchseSensor + ((512-yAchseSensor)* (1-scale));
          if (outputRight > 512) outputRight = 512;
        }
  } else{ // straight ahead
    outputRight = yAchseSensor;
    outputLeft = yAchseSensor;
  }
  


  //analogWrite(motorRight, outputRight);
  //analogWrite(motorLeft, outputLeft);

  // Output
  Serial.print("Motor rechts = ");
  Serial.print(outputRight);
  Serial.print("\t Motor links = ");
  Serial.print(outputLeft);
  //Serial.print("\t ySensor = ");
  //Serial.println(yAchseSensor);
  Serial.print("\n xSensor = ");
  Serial.print(xAchseSensor);
}
