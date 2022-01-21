from cmath import atan


xAchseSensor = 531
yAchseSensor = 0
outputRight = 0
outputLeft = 0
scale = 0
deg = 0
import math


for xAchseSensor in [531, 750, 1023]: #[473, 250, 0]: #
    if xAchseSensor > 530: # left hemisphere
        if yAchseSensor < 530 and yAchseSensor > 476:
          outputRight = yAchseSensor
          outputLeft = yAchseSensor
        elif yAchseSensor > 530:
          deg = math.atan2((yAchseSensor - 530), (xAchseSensor - 530))
          outputRight = yAchseSensor
          scale = ((deg-0.7853981)/(1.5687679-0.7853981))/2 + 0.5
          outputLeft = yAchseSensor * scale;  
          if outputLeft < 512:
              outputLeft = 512
          print("Deg: ",deg)
          print("Scale:", scale)
        else:
          deg = math.atan2((475 - yAchseSensor), (xAchseSensor - 529))
          outputRight = yAchseSensor
          scale = ((deg-0.7657928325402437)/(1.5665858253609926-0.7657928325402437))#/2 + 0.5
          outputLeft = yAchseSensor + ((512-yAchseSensor)* (1-scale))
          if outputLeft > 512:
              outputLeft = 512
          print("Deg: ",deg)
          print("Scale:", scale)
    elif xAchseSensor < 474: # right hemisphere
        if yAchseSensor < 530 and yAchseSensor > 476:
          outputRight = yAchseSensor
          outputLeft = yAchseSensor
        elif yAchseSensor > 530:
          deg = math.atan2((yAchseSensor - 529), (xAchseSensor))
          outputLeft = yAchseSensor
          scale = 1 - ((deg-0.8071113998439905)/(1.5707963267948966-0.8071113998439905))/2 
          outputRight = yAchseSensor * scale;  
          if outputRight < 512:
              outputRight = 512
          print("Deg: ",deg)
          print("Scale:", scale)
        else:
          deg = math.atan2((475 - yAchseSensor), (xAchseSensor))
          outputLeft = yAchseSensor
          scale = 1 - ((deg-0.7875078649088113)/(1.5707963267948966-0.7875078649088113))
          outputRight = yAchseSensor + ((512-yAchseSensor)* (1-scale))
          if outputRight > 512:
              outputRight = 512
          print("Deg: ",deg)
          print("Scale:", scale)
    else: # straight movement
        outputRight = yAchseSensor
        outputLeft = yAchseSensor

    # Output
    print("Motor right = ", math.floor(outputRight))
    print("Motor left = ", math.floor(outputLeft))
    print("ySensor = ", yAchseSensor)
    print("xSensor = ", xAchseSensor)

