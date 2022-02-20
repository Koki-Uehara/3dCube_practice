#include"Arduino.h"

//関数一覧*******************************************************************************************************
/*
all_clear(void)
all_on(int delaytime)
drow(byte Array[8][8], int delaytime)
drow2(byte Array[8][8], int delaytime)
swap(byte pattern[][8])
copy(byte pattern[][8], int delay_time)
left_shift(void)
right_shift(void)
flont_shift(byte *pattern, int delayTime)
back_shift(byte *pattern, int delayTime)
up_shift(byte *pattern, int delayTime)
down_shift(byte *pattern, int delayTime)
 */
//*************************************************************************************************************


/* オール「0」 */
byte CL = 0x00;
/* オール「1」 */
byte ALL =0xff ;

/* 全レイヤーをLOWに、シフトレジスタに「0」のデータを送る関数　*/
/* setup()関数内に記述されています */
void all_clear(void) {
  delay(DINAMIC_DELAY_TIME);
  digitalWrite(SS, LOW);
  for(int i =0;i<8;i++)SPI.transfer(CL);
  digitalWrite(SS, HIGH );
  for(int i =0;i<8;i++)digitalWrite(layers[i], LOW);
 
}

/* 全てのLEDを点灯させる関数 */
/* 引数に点灯させたい時間を入れてください（単位はミリ秒）*/
/*void all_on(int delaytime) {
  //millis()を入れる変数の初期化
  unsigned long startTime = millis();
  startTime = millis();
  while (millis() - startTime <=  delaytime) {
    for (int i = 7; i >= 0; i--) {
      digitalWrite(layers[i], HIGH);
      digitalWrite( SS, LOW );
      for(int i =0;i<8;i++)SPI.transfer(ALL);
      digitalWrite( SS, HIGH );
      all_clear();
    }
  }
}
*/
/* 受け取った配列を縦方向の順に光らせる */
void drow(byte Array[8][8], int delaytime) {
  //millis()を入れる変数の初期化
  unsigned long startTime = millis();
  startTime = millis();
  while (millis() - startTime <=  delaytime) {
    for (int i = 0; i < LAYER_SUM; i++) {
      digitalWrite(layers[i], HIGH);
      digitalWrite(SS, LOW);
      SPI.transfer(Array[i][7]);
      SPI.transfer(Array[i][6]);
      SPI.transfer(Array[i][5]);
      SPI.transfer(Array[i][4]);
      SPI.transfer(Array[i][3]);
      SPI.transfer(Array[i][2]);
      SPI.transfer(Array[i][1]);
      SPI.transfer(Array[i][0]);
      digitalWrite(SS, HIGH);
      all_clear();
    }
  }
}

/* 受け取った配列を横方向の順に光らせる */
void drow2(byte Array[8][8], int delaytime) {
  //millis()を入れる変数の初期化
  unsigned long startTime = millis();
  startTime = millis();
  while (millis() - startTime <=  delaytime) {
    for (int i = 0; i < LAYER_SUM; i++) {
      digitalWrite(layers[i], HIGH);
      digitalWrite(SS, LOW);
      for(int j =0;j<8;j++)SPI.transfer(Array[j][i]);
      digitalWrite(SS, HIGH);
      all_clear();
    }
  }
}

/*配列1と配列2の内容を順々に入れ替える関数（drow2で後ろから前に、drowで下から上に）*/
void swap(byte pattern[][8]) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      byte temp = pattern[i][j];
      pattern[i][j] = pattern[i + 1][j];
      pattern[i + 1][j] = temp;
    }
  }
}

/*配列7番目を一つずつコピーして後ろから表示する。（任意の表示速度を引数として受ける。）*/
void copy(byte pattern[][8], int delay_time) {
  for (int i = 7; i > 0 ; i--) {
    for (int j = 0; j < 8; j++) {
      byte temp = pattern[i][j];
      pattern[i - 1][j] = temp;
    }
    drow2(pattern, delay_time);
  }
}


/*任意の大きさの正方形を作成する関数*/
/*
  x = Layer
  y = シフトレジスタ方向
  z = ビット方向
*/
void setCube(byte LEDbits[][8], int x, int y, int z, int s) {
  for (int i = 0; i < s; i++) {
    bitSet(LEDbits[x][y], z + i);
    bitSet(LEDbits[x][y + i], z);
    bitSet(LEDbits[x][y + i], z + s - 1);
    bitSet(LEDbits[x][y + s - 1], z + i);
    bitSet(LEDbits[x + i][y], z + s - 1);
    bitSet(LEDbits[x + i][y], z);
    bitSet(LEDbits[x + i][y + s - 1], z);
    bitSet(LEDbits[x + i][y + s - 1], z + s - 1);
    bitSet(LEDbits[x + s - 1][y], z + i);
    bitSet(LEDbits[x + s - 1][y + i], z);
    bitSet(LEDbits[x + s - 1][y + i], z + s - 1);
    bitSet(LEDbits[x + s - 1][y + s - 1], z + i);
  }
}


/* 右の面を左の面に向かって移動させる関数 */
void left_shift(void) {
  for (int k = 0; k < LAYER_SUM; k++) {
    //millis()を入れる変数の初期化
    unsigned long startTime = millis();
    startTime = millis();
    while ((millis() - startTime) <= DELAY_TIME) {
      for (int i = 0; i < LAYER_SUM; i++) {
        digitalWrite(layers[i], HIGH);
        int val_1 = B00000001 << k;
        int val_2 = val_1 & 0xff;
        digitalWrite(SS, LOW);
        for(int j =0;j<8;j++)SPI.transfer(val_2);   
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }
}

/* 左の面を右の面に向かって移動させる関数 */
void right_shift(void) {
  for (int k = 0; k < LAYER_SUM; k++) {
    //millis()を入れる変数の初期化
    unsigned long startTime = millis();
    startTime = millis();
    while ((millis() - startTime) <= DELAY_TIME) {
      for (int i = 0; i < LAYER_SUM; i++) {
        digitalWrite(layers[i], HIGH);
        int val_1 = B10000000 >> k;
        int val_2 = val_1 & 0xff;
        digitalWrite(SS, LOW);
        for(int j =0;j<8;j++)SPI.transfer(val_2); 
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }
}

/* 後ろの面を前の面に向かって移動させる関数 */
void flont_shift(byte *pattern, int delayTime) {
  byte cube[8][8] = {0};

  for (int i = 0; i < 8; i++) {
    cube[7][i] = pattern[i];
  }
  for (int i = 7; i > 0; i--) {
    drow2(cube, delayTime);
    for (int j = 0; j < 8; j++) {
      byte temp = cube[i][j];
      cube[i][j] =  cube[i - 1][j];
      cube[i - 1][j] = temp;
    }
  }
  drow2(cube, delayTime);
}

/* 前の面を後ろの面に向かって移動させる関数 */
void back_shift(byte *pattern, int delayTime) {
  byte cube[8][8] = {0};

  for (int i = 0; i < 8; i++) {
    cube[0][i] = pattern[i];
  }
  for (int i = 0; i < 7; i++) {
    drow2(cube, delayTime);
    for (int j = 0; j < 8; j++) {
      byte temp = cube[i][j];
      cube[i][j] =  cube[i + 1][j];
      cube[i + 1][j] = temp;
    }
  }
  drow2(cube, delayTime);
}

/* 下の面を上の面に向かって移動させる関数 */
void up_shift(byte *pattern, int delayTime) {
  byte cube[8][8] = {0};

  for (int i = 0; i < 8; i++) {
    cube[7][i] = pattern[i];
  }
  for (int i = 7; i > 0; i--) {
    drow(cube, delayTime);
    for (int j = 0; j < 8; j++) {
      byte temp = cube[i][j];
      cube[i][j] =  cube[i - 1][j];
      cube[i - 1][j] = temp;
    }
  }
  drow(cube, delayTime);
}

/* 上の面を下の面に向かって移動させる関数 */
void down_shift(byte *pattern, int delayTime) {
  byte cube[8][8] = {0};

  for (int i = 0; i < 8; i++) {
    cube[0][i] = pattern[i];
  }
  for (int i = 0; i < 7; i++) {
    drow(cube, delayTime);
    for (int j = 0; j < 8; j++) {
      byte temp = cube[i][j];
      cube[i][j] =  cube[i + 1][j];
      cube[i + 1][j] = temp;
    }
  }
  drow(cube, delayTime);
}
