int Row1 = 13;  //Row 1
int Row2 = 12;  //Row 2
int Row3 = 11;  //Row 3



int Col1 = 10;
int Col2 = 9;
int Col3 = 8;

int Col4 = 7;
int Col5 = 6;
int Col6 = 5;


int Col7 = 4;
int Col8 = 3;
int Col9 = 2;



int rowmax = 3;
int colmax = 9;

int Col[9];
int Row[3];

int push_button = A0;
int effect,change;

void setup() {                
 
  Serial.begin(9600);

  pinMode(Row1, OUTPUT); //Top
  pinMode(Row2, OUTPUT); //Middle
  pinMode(Row3, OUTPUT); //Bottom
  
  pinMode(Col1, OUTPUT); //Left
  pinMode(Col2, OUTPUT); //Middle
  pinMode(Col3, OUTPUT); //Right
  pinMode(Col4, OUTPUT); //Left
  pinMode(Col5, OUTPUT); //Middle
  pinMode(Col6, OUTPUT); //Right
  pinMode(Col7, OUTPUT); //Left
  pinMode(Col8, OUTPUT); //Middle
  pinMode(Col9, OUTPUT); //Right

  pinMode(push_button, INPUT_PULLUP);//Changing color
  

  Col[0] = Col1;
  Col[1] = Col2;
  Col[2] = Col3;
  Col[3] = Col4;
  Col[4] = Col5;
  Col[5] = Col6;
  Col[6] = Col7;
  Col[7] = Col8;
  Col[8] = Col9;
  
  Row[0] = Row1;
  Row[1] = Row2;
  Row[2] = Row3; 
}

// the loop routine runs over and over again forever:

void loop() {
  change = digitalRead(push_button);
  effect += change;
  Serial.println(effect);
  
switch (effect){
    case 1:{
        frontPaneFigure8();
        rightPaneFigure8();
        backPaneFigure8();
        leftPaneFigure8();
        middleUpDown();      break;
    }

   
    case 2:{
      antiClockwise(50);
      antiClockwise(60);
      antiClockwise(70);   break;
    }
   
  
    case 3:{
        clockwise(70);
        clockwise(60);
        clockwise(50);   break;
    }
 
    case 4:{
        frontToBackPane();
        rightToLeftPane();
        backToFrontPane();
        leftToRightPane();
        //bottomToTopPanel();
       topToBottomPanel(); break;
    }
   
    case 5:{
        panelRotateCW();
        panelRotateCW();
        panelRotateCW();
        panelRotateCW();
        panelRotateCW();
        panelRotateCW();
        panelRotateCW();break;
    }
    
    case 6:{
       panelRotateAntiCW();
       panelRotateAntiCW();
       panelRotateAntiCW();
       panelRotateAntiCW();
       panelRotateAntiCW();
       panelRotateAntiCW();
       panelRotateAntiCW(); break;
    }
   
    case 7:{
        delay(100);
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF(); break;
    }
   
     case 8:{
        rainLight();
        lightning();
        rainMed();
        lightning();
        rainHeavy();
  
        delay(300);   break;
    }
 
    default:{        
        rainLight();
        lightning();
       
        } 
  }
}
//end main loop
//All helper functions used to create designs and patters throughout the loop
//LED movements

//flashes both top and bottom panes

void lightning(){
    topPaneOn();
    bottomPaneOn();
    delay(100);
    topPaneOff();
    bottomPaneOff();
    delay(100);
    topPaneOn();
    bottomPaneOn();
    delay(100);
    topPaneOff();
    bottomPaneOff();
    topPaneOn();
    bottomPaneOn();
    delay(100);
    topPaneOff();
    bottomPaneOff();
    delay(100);
}



//animate
void rndUpDown(){
    randomSeed(analogRead(0)%100);
    int row = random(0,100);
}

//animate
//Heavy rain
void rainHeavy(){
  int del = 80;
  int del2 = 60;
  randomSeed(analogRead(0)%10);
  //Serial.println("Analog input"); //testing
  //Serial.println(analogRead(0)%10); //testing
  for(int x= 0; x<50; x++){
    int stCol = random(0,colmax);
    int stCol2 = random(0,colmax);
    int stCol3 = random(0,colmax);
    int stCol4 = random(0,colmax);
    
    int dropNum = random(0,9);
    
    //Serial.println(dropNum); //testing

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 80;  //if first row
      onLED(Row[y], Col[stCol]);
      if(dropNum>=4){
        onLED(Row[y], Col[stCol2]);
      }
      if(dropNum>=7){
        onLED(Row[y], Col[stCol3]);
      }
      if(dropNum>=8){
        onLED(Row[y], Col[stCol4]);
      }
      
      delay(del2);
      
      //turn off all even if they wern't turned on.
      offLED(Row[y], Col[stCol]);
      offLED(Row[y], Col[stCol2]);
      offLED(Row[y], Col[stCol3]);
      offLED(Row[y], Col[stCol4]);
      
      
      del2=30;
    }
    delay(del);

  }
}



//animate
//light rain
void rainLight(){
  int del = 170;
  int del2 = 70;
  
  for(int x= 0; x<20; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 110; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=70;
    }
    delay(del);

  }
}

//animate
//Medium rain
void rainMed(){
  int del = 70;
  int del2 = 35;
  
  for(int x= 0; x<25; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 85; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=35;
    }
    delay(del);

  }
}


//animate
//light rain
void rain(){
  int del = 150;
  int del2 = 50;
  
  for(int x= 0; x<40; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 90; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=50;
    }
    delay(del);

  }
}


//animate
void paneLTF(){
  int del = 100;
    leftPaneOn();
    delay(del);
    leftPaneOff();
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
}


//animate
void paneBTL(){
  int del = 100;
    backPaneOn();
    delay(del);
    backPaneOff();
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
}

//animate
void paneRTB(){
  int del = 100;
    rightPaneOn();
    delay(del);
    rightPaneOff();
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
}

//animate
void paneFTR(){
  int del = 100;
    frontPaneOn();
    delay(del);
    frontPaneOff();
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
}


void panelRotateCW(){
    int del = 80;
    
    middlePaneOn();
    delay(del);
    middlePaneOff();
    
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    
    
    //back to start.
    //middlePaneOn();
    //delay(del);
    //middlePaneOff();
    
}


void panelRotateAntiCW(){
    int del = 80;
    
    middlePaneOn();
    delay(del);
    middlePaneOff();
    
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    
    
    //back to start.
    //middlePaneOn();
    //delay(del);
    //middlePaneOff();
    
}


void diagonalBTFPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col7, HIGH);
    digitalWrite(Col9, HIGH);
    digitalWrite(Col3, HIGH);
}

void diagonalBTFPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col3, LOW);
    digitalWrite(Col9, LOW);
    digitalWrite(Col7, LOW);
}

void diagonalFTBPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col9, HIGH);
    digitalWrite(Col5, HIGH);

}
void diagonalFTBPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col5, LOW);
    digitalWrite(Col9, LOW);
    digitalWrite(Col1, LOW);

}

void frontToBackPane(){
    int del = 250;
    frontPaneOn();
    delay(del);
    frontPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
}

//animation
void rightToLeftPane(){
    int del = 250;
    rightPaneOn();
    delay(del);
    rightPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
}

//animation
void backToFrontPane(){
    int del = 250;
    backPaneOn();
    delay(del);
    backPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
}

//animation
void leftToRightPane(){
    int del = 250;
    leftPaneOn();
    delay(del);
    leftPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
}

//animation
void topToBottomPanel(){
    int del = 250;
    topPaneOn();
    delay(del);
    topPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    bottomPaneOn();
    delay(del);
    bottomPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    topPaneOn();
    delay(del);
    topPaneOff();

}

//animation
void bottomToTopPanel(){
    int del = 250;
    bottomPaneOn();
    delay(del);
    bottomPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    topPaneOn();
    delay(del);
    topPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    bottomPaneOn();
    delay(del);
    bottomPaneOff();

}


//static
void topPaneOn(){
    digitalWrite(Row1, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void topPaneOff(){
    digitalWrite(Row1, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}

//static
void middleTBPaneOn(){
    digitalWrite(Row2, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void middleTBPaneOff(){
    digitalWrite(Row2, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}

void bottomPaneOn(){
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void bottomPaneOff(){
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}


void rightPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
}

void rightPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
}

void middleLRPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col2, HIGH);
    digitalWrite(Col9, HIGH);
    digitalWrite(Col6, HIGH);
}

void middleLRPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col2, LOW);
    digitalWrite(Col9, LOW);
    digitalWrite(Col6, LOW);
}

void leftPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col1, HIGH);
}

void leftPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col1, LOW);
}


void backPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
}


void backPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
}
//-------------------------------

void middlePaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col4, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void middlePaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col4, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}



void frontPaneOn(){
    digitalWrite(Row1, HIGH);
    digitalWrite(Row2, HIGH);
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
}

void frontPaneOff(){
    digitalWrite(Row1, LOW);
    digitalWrite(Row2, LOW);
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
}



void antiClockwise(int movSpeed){
    int delVal = movSpeed;
   
    for(int x=0; x<3; x++){
      for(int y=0; y<8; y++){
        onLED(Row[x],Col[y]);
        delay(delVal);
        offLED(Row[x],Col[y]);
      }
    }
}


void clockwise(int movSpeed){
    int delVal = movSpeed;
    
    for(int x=2; x>-1; x--){
      for(int y=7; y>-1; y--){
        onLED(Row[x],Col[y]);
        delay(delVal);
        offLED(Row[x],Col[y]);
      }
    }
}



//snake movement on front pane only
void frontPaneFigure8(){
  
  int delVal = 130;

    for(int y=0;y<3;y++){
      onLED(Row[0],Col[y]);
      delay(delVal);
      offLED(Row[0],Col[y]);
    }
    for(int y=2;y>-1;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }
    for(int y=0;y<3;y++){
      onLED(Row[2],Col[y]);
      delay(delVal);
      offLED(Row[2],Col[y]);
    }
    for(int y=2;y>-1;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }

}


void rightPaneFigure8(){
  
  int delVal = 130;

    for(int y=2;y<5;y++){
      onLED(Row[0],Col[y]);
      delay(delVal);
      offLED(Row[0],Col[y]);
    }
    for(int y=4;y>1;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }
    for(int y=2;y<5;y++){
      onLED(Row[2],Col[y]);
      delay(delVal);
      offLED(Row[2],Col[y]);
    }
    for(int y=4;y>1;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }

}

void backPaneFigure8(){
  
  int delVal = 130;

    for(int y=4;y<7;y++){
      onLED(Row[0],Col[y]);
      delay(delVal);
      offLED(Row[0],Col[y]);
    }
    for(int y=6;y>3;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }
    for(int y=4;y<7;y++){
      onLED(Row[2],Col[y]);
      delay(delVal);
      offLED(Row[2],Col[y]);
    }
    for(int y=6;y>3;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }

}

void leftPaneFigure8(){
  
  int delVal = 130;

    for(int y=6;y<8;y++){
      onLED(Row[0],Col[y]);
      delay(delVal);
      offLED(Row[0],Col[y]);
    }
      
      //back to first
      onLED(Row[0],Col[0]);
      delay(delVal);
      offLED(Row[0],Col[0]);
    
    
      //back to first
      onLED(Row[1],Col[0]);
      delay(delVal);
      offLED(Row[1],Col[0]);
    
    
    for(int y=7;y>5;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }
    
    for(int y=6;y<8;y++){
      onLED(Row[2],Col[y]);
      delay(delVal);
      offLED(Row[2],Col[y]);
    }
    
      //back to first
      onLED(Row[2],Col[0]);
      delay(delVal);
      offLED(Row[2],Col[0]);
    
    
      //back to first
      onLED(Row[1],Col[0]);
      delay(delVal);
      offLED(Row[1],Col[0]);
    
    for(int y=6;y>5;y--){
      onLED(Row[1],Col[y]);
      delay(delVal);
      offLED(Row[1],Col[y]);
    }

}



void middleUpDown(){
      int delVal = 130;
      onLED(Row[0],Col[8]);
      delay(delVal);
      offLED(Row[0],Col[8]);
      
      onLED(Row[1],Col[8]);
      delay(delVal);
      offLED(Row[1],Col[8]);
      
      onLED(Row[2],Col[8]);
      delay(delVal);
      offLED(Row[2],Col[8]);
      
      onLED(Row[1],Col[8]);
      delay(delVal);
      offLED(Row[1],Col[8]);
      
      onLED(Row[0],Col[8]);
      delay(delVal);
      offLED(Row[0],Col[8]);
}

//turn on all LEDs one by one.
void testAllLEDs(){
    int delVal = 500;
    
    for(int x=0;x<3;x++){
      for(int y=0;y<9;y++){
        //Serial.print(x + " " + y);
        onLED(Row[x],Col[y]);
        delay(delVal);
        offLED(Row[x],Col[y]);
        delay(200);
      }
    }
}




//turn on LED based on row number and column number
void onLED(int row, int col){
  
  digitalWrite(row, HIGH); //turn on row
  digitalWrite(col, HIGH); //turn on col
  
}

//overload funtion - used to turn LED on with certain intensity
void onLED(int row, int col, int value){
  digitalWrite(row, HIGH); //turn on row
  analogWrite(col, value); //turn on col
}


//turn off LED based on row number and column number
void offLED(int row, int col){
  digitalWrite(row, LOW); //turn on row
  digitalWrite(col, LOW); //turn on col
}


