#include"Arduino.h"

//関数一覧*******************************************************************************************************
/*
  clearCube_i(int x, int y, int z, int s)
  down_swap(byte pattern[][8])
  dice_to_cubeslide()
  cubeSlide(int drow_tipe)
  LEDbit_clear()
  rain()
  fire()
  rain_all()
  allOnCheck(byte arrays[][8])
  random_on()
  arrow_rain(int rain_speed)
  arrow()
  tetris_clear_check()
  bottom_clear()
  bottom_set()
  tetris()
*/
//*************************************************************************************************************


byte LEDbits[8][8];

/*LEDbits配列をすべて0にします */
void LEDbit_clear() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        bitClear(LEDbits[i][j], k);
      }
    }
  }
}

void setCube_i(int x, int y, int z, int s) {

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
/*座標とサイズを渡し、キューブ型にビットをクリア*/
void clearCube_i(int x, int y, int z, int s) {
 
  for (int i = 0; i < s; i++) {
    bitClear(LEDbits[x][y], z + i);
    bitClear(LEDbits[x][y + i], z);
    bitClear(LEDbits[x][y + i], z + s - 1);
    bitClear(LEDbits[x][y + s - 1], z + i);

    bitClear(LEDbits[x + i][y], z + s - 1);
    bitClear(LEDbits[x + i][y], z);
    bitClear(LEDbits[x + i][y + s - 1], z);
    bitClear(LEDbits[x + i][y + s - 1], z + s - 1);


    bitClear(LEDbits[x + s - 1][y], z + i);
    bitClear(LEDbits[x + s - 1][y + i], z);
    bitClear(LEDbits[x + s - 1][y + i], z + s - 1);
    bitClear(LEDbits[x + s - 1][y + s - 1], z + i);

  }
}

/*下方向に向けてレイヤーを入れ替えます*/
void down_swap(byte pattern[][8]) {
  for (int i = 6; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      byte temp = pattern[i][j];
      pattern[i][j] = pattern[i + 1][j];
      pattern[i + 1][j] = temp;
    }
  }
}

/*8*8*8 から4*4*4のキューブに2個に分裂*/
void dice_to_cubeslide() {
  setCube_i(0, 0, 0, 8);
  drow(LEDbits, 200);
  clearCube_i(0, 0, 0, 8);

  for (int i = 7; i >= 4; i--) {
    setCube_i(0, 0, 0, i);
    setCube_i(8 - i, 8 - i, 8 - i, i);
    drow(LEDbits, 200);
    clearCube_i(0, 0, 0, i);
    clearCube_i(8 - i, 8 - i, 8 - i, i);
  }
}

/*4*4*4のキューブが２つ対角の位置でスライドします*/
void cubeSlide(int drow_tipe) {

  unsigned long startSec = millis();
  while (millis() - startSec <= 3800) {
    int xLow = 4;
    for (int xHigh = 0; xHigh < 5; xHigh++) {
      setCube_i(0, 0, xHigh, 4);
      setCube_i(4, 4, xLow, 4);
      if (drow_tipe == 0) {
        drow(LEDbits, 30);
      }
      else {
        drow2(LEDbits, 30);
      }


      clearCube_i(0, 0, xHigh, 4);
      clearCube_i(4, 4, xLow, 4);
      xLow--;
    }
    xLow = 4;
    for (int yHigh = 0; yHigh < 5; yHigh++) {
      setCube_i(0, yHigh, 4, 4);
      setCube_i(4, xLow, 0, 4);

      if (drow_tipe == 0) {
        drow(LEDbits, 100);
      }
      else {
        drow2(LEDbits, 100);
      }

      clearCube_i(0, yHigh, 4 , 4);
      clearCube_i(4, xLow, 0, 4);
      xLow--;
    }
    xLow = 0;
    for (int xHigh = 4; xHigh >= 0; xHigh--) {
      setCube_i(0, 4, xHigh, 4);
      setCube_i(4, 0, xLow, 4);

      if (drow_tipe == 0) {
        drow(LEDbits, 30);
      }
      else {
        drow2(LEDbits, 30);
      }

      clearCube_i(0, 4, xHigh, 4);
      clearCube_i(4, 0, xLow, 4);
      xLow++;
    }

    xLow = 0;
    for (int yHigh = 4; yHigh >= 0; yHigh--) {
      setCube_i(0, yHigh, 0, 4);
      setCube_i(4, xLow, 4, 4);

      if (drow_tipe == 0) {
        drow(LEDbits, 100);
      }
      else {
        drow2(LEDbits, 100);
      }

      clearCube_i(0, yHigh, 0 , 4);
      clearCube_i(4, xLow, 4, 4);
      xLow++;
    }

  }
}

/*引数で雨を降らせるカラムと上下の方向を指定  */
void rain(int least, int most,int drow_type) {
  LEDbit_clear();
  unsigned long startSec = millis();
  while (millis() - startSec <= 6000) {
    for (int i = 0; i < 8; i++) {
      int x = random(least, most);
      int y = random(0, 8);
      bitSet(LEDbits[0][x], y);
      
      if(drow_type== 0){
        down_swap(LEDbits);
      }else{
      swap(LEDbits);
      }
      drow(LEDbits, 50);
      
    }
  }
  LEDbit_clear();
}

/* 渡した配列の中にいくつ１が立っているかカウントします */
int allOnCheck(byte arrays[][8]) {
  int highCount = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        if (bitRead(arrays[i][j], k) == 1) {
          highCount++;
        }
      }
    }
  }
  return highCount;
}

/* LEDをランダムに一つずつ点灯させる関数 */
void random_on(int mode) {
  LEDbit_clear();
  while (allOnCheck(LEDbits) <= 150) {
    int layerTemp = random(0, 8);
    int bitTemp = random(0, 8);
    int arrayTemp = random(0, 8);
    if (bitRead(LEDbits[layerTemp][arrayTemp], bitTemp) == 0) {
      bitSet(LEDbits[layerTemp][arrayTemp], bitTemp);
      drow(LEDbits, 1);
    }
  }
  if(mode == 0){
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        if (bitRead(LEDbits[i][j], k) == 1) {
          bitClear(LEDbits[i][j], k);
          drow(LEDbits, 1);
        }
      }
    }
  }
  }
}


/* 矢印の形に雨を降らせます */
void arrow_rain(int rain_speed) {
 
  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][6], 4);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][6], 4);
  }

  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][5], 4);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][5], 4);
  }
  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][5], 5);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][5], 5);
  }
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 8; i++) {
      bitSet(LEDbits[i][4], j);
      drow(LEDbits, rain_speed);
      if (!(i == 7) )bitClear(LEDbits[i][4], j);
    }

  }
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 8; i++) {
      bitSet(LEDbits[i][3], j);
      drow(LEDbits, rain_speed);
      if (!(i == 7) )bitClear(LEDbits[i][3], j);
    }

  }
  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][2], 5);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][2], 5);
  }
  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][2], 4);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][2], 4);
  }
  for (int i = 0; i < 8; i++) {
    bitSet(LEDbits[i][1], 4);
    drow(LEDbits, rain_speed);
    if (!(i == 7) )bitClear(LEDbits[i][1], 4);
  }



}

/* 矢印が降って、その方向に進みます */
void arrow() {
  LEDbit_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bitSet(LEDbits[0][i], j);
      drow(LEDbits, 10);
    }
  }
  arrow_rain(10);

  for (int h = 0; h < 6; h++) {
    for (int i = 1; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        byte temp = LEDbits[i][j];
        LEDbits[i][j] = LEDbits[i + 1][j];
        LEDbits[i + 1][j] = temp;
      }
    }
    drow(LEDbits, 30);

  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bitClear(LEDbits[1][i], j);

    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bitSet(LEDbits[0][i], j);

    }
  }
  drow(LEDbits, 10);

  arrow_rain(3);

  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      LEDbits[7][i] = LEDbits[7][i] << 1;
      LEDbits[7][i] = LEDbits[7][i] & 0xff;
    }
    drow(LEDbits, 20);
  }

  LEDbit_clear();

}

/*テトリスの最下層が何個埋まっているかチェック */
int tetris_clear_check() {
  int bottom = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bottom = bottom + bitRead(LEDbits[6][i], j);

    }
  }
  return bottom;
}

/*テトリスの最下層ビットをクリアまたはセット */
void bottom_Write(int mode) {
  for (int i = 6; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        bitWrite(LEDbits[i][j], k,mode);
      }
    }
  }
}

/*テトリスのように上からブロックがランダムで落ち、一層貯まると消える */
void tetris() {

  unsigned long startSec = millis();
  while (millis() - startSec <= 30000) {
    int times = 0;
    const int cubesize = 2; //キューブサイズは固定で2*2*2
    int X = (random(0, 4) * 2); //2.4.6のなかからランダムで
    int Z = (random(0, 4) * 2);
    int down = 7;
    int cullent_layer = 6;


    if (tetris_clear_check() >= 64) {

      bottom_Write(0);
      drow(LEDbits, 10);
      bottom_Write(1);
      drow(LEDbits, 30);
      bottom_Write(0);
      drow(LEDbits, 10);
      bottom_Write(1);
      drow(LEDbits, 30);
      bottom_Write(0);

      for (int i = 0; i < 2; i++) {
        down_swap(LEDbits);
        drow(LEDbits, 50);
        times++;
      }
    }

    for (int i = 0; i < 4; i++) {
      if ( bitRead(LEDbits[cullent_layer][X], Z) == 1) {
        down = down  - 2; //落とす階層数を設定
        cullent_layer = cullent_layer - 2;//現在の階層を設定
      }
    }

    for (int i = 0; i < down ; i++ ) {
      setCube_i(i, X, Z, cubesize);
      drow(LEDbits, 100);
      if (!(i == cullent_layer)) {
        clearCube_i(i, X, Z, cubesize);
      }
    }

    if (times == 3) {
      break;
    }
  }
  LEDbit_clear();
}
