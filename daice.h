#include"Arduino.h"


//関数一覧*******************************************************************************************************
/*
swap2(byte pattern[][8])
bits_clear(byte LEDbits[][8])
bits_set(byte LED[][8], byte LEDpattern[][8])
setCube(byte LEDbits[][8], int x, int y, int z, int s)
daice(int x, int delay_time)
random_daice1(int x, int delay_time)
random_daice2(long x, int y, int delay_time)
DNA_side()
DNA_ver()
*/
//*************************************************************************************************************

/*配列の中身を0で初期化する。*/
void bits_clear(byte LEDbits[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      LEDbits[i][j] = CL;
    }
  }
}

/*配列の中身を指定したビットで上書きする。*/
void bits_set(byte LED[][8], byte LEDpattern[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      LED[i][j] = LEDpattern[i][j];
    }
  }
}



/*3Dサイコロ表示に必要な配列をグローバルに準備*/
byte LED[8][8];
byte LEDpattern[8][8] = {
  {
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B10000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
  },
  {
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111,
  }
};


  //サイコロを3Dに表示させて回転させる。
  void daice(int x, int delay_time){

  //配列の初期化
  bits_clear(LED);

  //用意した配列の中身を指定した配列で上書きする。
  bits_set(LED,LEDpattern);
  unsigned long daice_time = millis();
  while(millis() - daice_time <= x){
  //daice1の点滅
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);drow(LED,delay_time);
  setCube(LED,3,3,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);

  //daice2の回転
  setCube(LED,1,1,1,2);setCube(LED,5,5,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,5,5,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,5,5,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,5,3,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,5,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,1,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,1,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);

  //daice3の回転
  setCube(LED,1,1,1,2);setCube(LED,3,3,3,2);setCube(LED,5,5,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,3,3,3,2);setCube(LED,5,5,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,3,3,3,2);setCube(LED,5,5,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,3,3,3,2);setCube(LED,5,3,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,5,2);setCube(LED,3,3,3,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,3,2);setCube(LED,3,3,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,5,1,2);setCube(LED,3,3,3,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,1,2);setCube(LED,3,3,3,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);

  //daice4の回転
  setCube(LED,1,1,1,2);setCube(LED,5,5,5,2);setCube(LED,1,5,5,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,5,5,3,2);setCube(LED,1,5,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,5,5,1,2);setCube(LED,1,5,1,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,5,3,1,2);setCube(LED,1,3,1,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,1,2);setCube(LED,5,5,5,2);setCube(LED,1,5,5,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,5,5,3,2);setCube(LED,1,5,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,5,5,1,2);setCube(LED,1,5,1,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,5,3,1,2);setCube(LED,1,3,1,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);

  //daice5の回転
  setCube(LED,1,1,1,2);setCube(LED,5,5,5,2);setCube(LED,3,3,3,2);setCube(LED,1,5,5,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,5,5,3,2);setCube(LED,3,3,3,2);setCube(LED,1,5,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,5,5,1,2);setCube(LED,3,3,3,2);setCube(LED,1,5,1,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,5,3,1,2);setCube(LED,3,3,3,2);setCube(LED,1,3,1,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,1,2);setCube(LED,5,5,5,2);setCube(LED,3,3,3,2);setCube(LED,1,5,5,2);setCube(LED,5,1,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,3,2);setCube(LED,5,5,3,2);setCube(LED,3,3,3,2);setCube(LED,1,5,3,2);setCube(LED,5,1,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,1,5,2);setCube(LED,5,5,1,2);setCube(LED,3,3,3,2);setCube(LED,1,5,1,2);setCube(LED,5,1,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,1,3,5,2);setCube(LED,5,3,1,2);setCube(LED,3,3,3,2);setCube(LED,1,3,1,2);setCube(LED,5,3,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);

  //daice6の回転
  setCube(LED,0,1,1,2);setCube(LED,0,5,5,2);setCube(LED,3,1,1,2);setCube(LED,3,5,5,2);setCube(LED,6,1,1,2);setCube(LED,6,5,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,3,2);setCube(LED,0,5,3,2);setCube(LED,3,1,3,2);setCube(LED,3,5,3,2);setCube(LED,6,1,3,2);setCube(LED,6,5,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,5,2);setCube(LED,0,5,1,2);setCube(LED,3,1,5,2);setCube(LED,3,5,1,2);setCube(LED,6,1,5,2);setCube(LED,6,5,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,3,5,2);setCube(LED,0,3,1,2);setCube(LED,3,3,5,2);setCube(LED,3,3,1,2);setCube(LED,6,3,5,2);setCube(LED,6,3,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,1,2);setCube(LED,0,5,5,2);setCube(LED,3,1,1,2);setCube(LED,3,5,5,2);setCube(LED,6,1,1,2);setCube(LED,6,5,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,3,2);setCube(LED,0,5,3,2);setCube(LED,3,1,3,2);setCube(LED,3,5,3,2);setCube(LED,6,1,3,2);setCube(LED,6,5,3,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,5,2);setCube(LED,0,5,1,2);setCube(LED,3,1,5,2);setCube(LED,3,5,1,2);setCube(LED,6,1,5,2);setCube(LED,6,5,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,3,5,2);setCube(LED,0,3,1,2);setCube(LED,3,3,5,2);setCube(LED,3,3,1,2);setCube(LED,6,3,5,2);setCube(LED,6,3,1,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  setCube(LED,0,1,1,2);setCube(LED,0,5,5,2);setCube(LED,3,1,1,2);setCube(LED,3,5,5,2);setCube(LED,6,1,1,2);setCube(LED,6,5,5,2);drow(LED,delay_time);
  bits_set(LED,LEDpattern);
  }
}

/*3Dサイコロを実際に振っているようにランダムで表示するための関数*/
void random_daice1(int x, int delay_time) {

  //配列の初期化
  bits_clear(LED);

  //用意した配列の中身を指定した配列で上書きする。
  bits_set(LED, LEDpattern);

  unsigned long start_time = millis();
  while (millis() - start_time <= x) {
    //ランダム変数を用意
    int randomDaice = random(0, 6);
    switch (randomDaice) {
      case 0://daice1の点滅
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        break;
      case 1://daice2の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 2://daice3の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 3://daice4の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 4://daice5の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 5://daice6の回転
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 3, 2); setCube(LED, 0, 5, 3, 2); setCube(LED, 3, 1, 3, 2); setCube(LED, 3, 5, 3, 2); setCube(LED, 6, 1, 3, 2); setCube(LED, 6, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 5, 2); setCube(LED, 0, 5, 1, 2); setCube(LED, 3, 1, 5, 2); setCube(LED, 3, 5, 1, 2); setCube(LED, 6, 1, 5, 2); setCube(LED, 6, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 3, 5, 2); setCube(LED, 0, 3, 1, 2); setCube(LED, 3, 3, 5, 2); setCube(LED, 3, 3, 1, 2); setCube(LED, 6, 3, 5, 2); setCube(LED, 6, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 3, 2); setCube(LED, 0, 5, 3, 2); setCube(LED, 3, 1, 3, 2); setCube(LED, 3, 5, 3, 2); setCube(LED, 6, 1, 3, 2); setCube(LED, 6, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 5, 2); setCube(LED, 0, 5, 1, 2); setCube(LED, 3, 1, 5, 2); setCube(LED, 3, 5, 1, 2); setCube(LED, 6, 1, 5, 2); setCube(LED, 6, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 3, 5, 2); setCube(LED, 0, 3, 1, 2); setCube(LED, 3, 3, 5, 2); setCube(LED, 3, 3, 1, 2); setCube(LED, 6, 3, 5, 2); setCube(LED, 6, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      default:
        break;
    }
  }
  all_clear();
}

/*3Dサイコロを実際に振っているようにランダムで表示する。*/
void random_daice2(long x, int y, int delay_time) {

  //配列の初期化
  bits_clear(LED);

  //用意した配列の中身を指定した配列で上書きする。
  bits_set(LED, LEDpattern);

  //1の目のカウンターセット
  int count = 0;
  unsigned long end_time = millis();
  //1の目がy回出るか、時間切れまでダイスを振る。
  while ((millis() - end_time <= x) || count == y) {
    //ダイスを振っている状態
    random_daice1(1200, 15);

    //ランダム変数を用意
    int randomDaice = random(0, 6);
    switch (randomDaice) {
      case 0://daice1の点滅
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        setCube(LED, 3, 3, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern); drow(LED, delay_time);
        count++;  //1の目が出た回数をカウントする
        break;
      case 1://daice2の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 2://daice3の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 3://daice4の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 4://daice5の回転
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 1, 2); setCube(LED, 5, 5, 5, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 5, 2); setCube(LED, 5, 1, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 3, 2); setCube(LED, 5, 5, 3, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 3, 2); setCube(LED, 5, 1, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 1, 5, 2); setCube(LED, 5, 5, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 5, 1, 2); setCube(LED, 5, 1, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 1, 3, 5, 2); setCube(LED, 5, 3, 1, 2); setCube(LED, 3, 3, 3, 2); setCube(LED, 1, 3, 1, 2); setCube(LED, 5, 3, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      case 5://daice6の回転
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 3, 2); setCube(LED, 0, 5, 3, 2); setCube(LED, 3, 1, 3, 2); setCube(LED, 3, 5, 3, 2); setCube(LED, 6, 1, 3, 2); setCube(LED, 6, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 5, 2); setCube(LED, 0, 5, 1, 2); setCube(LED, 3, 1, 5, 2); setCube(LED, 3, 5, 1, 2); setCube(LED, 6, 1, 5, 2); setCube(LED, 6, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 3, 5, 2); setCube(LED, 0, 3, 1, 2); setCube(LED, 3, 3, 5, 2); setCube(LED, 3, 3, 1, 2); setCube(LED, 6, 3, 5, 2); setCube(LED, 6, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 3, 2); setCube(LED, 0, 5, 3, 2); setCube(LED, 3, 1, 3, 2); setCube(LED, 3, 5, 3, 2); setCube(LED, 6, 1, 3, 2); setCube(LED, 6, 5, 3, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 5, 2); setCube(LED, 0, 5, 1, 2); setCube(LED, 3, 1, 5, 2); setCube(LED, 3, 5, 1, 2); setCube(LED, 6, 1, 5, 2); setCube(LED, 6, 5, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 3, 5, 2); setCube(LED, 0, 3, 1, 2); setCube(LED, 3, 3, 5, 2); setCube(LED, 3, 3, 1, 2); setCube(LED, 6, 3, 5, 2); setCube(LED, 6, 3, 1, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        setCube(LED, 0, 1, 1, 2); setCube(LED, 0, 5, 5, 2); setCube(LED, 3, 1, 1, 2); setCube(LED, 3, 5, 5, 2); setCube(LED, 6, 1, 1, 2); setCube(LED, 6, 5, 5, 2); drow(LED, delay_time);
        bits_set(LED, LEDpattern);
        break;
      default:
        break;
    }
  }
  all_clear();
}

/*DNA用パターン配列を準備*/
byte LED_dna[][8] = {
  {
    0,
    0,
    0,
    B00001111,
    B11110000,
    0,
    0,
    0
  },
  {
    0,
    0,
    B00000000,
    B11110000,
    B00001111,
    B00000000,
    0,
    0,
  },
  {
    0,
    B10000000,
    B01000000,
    B00110000,
    B00001100,
    B00000010,
    B00000001,
    0,
  },
  {
    B00010000,
    B00100000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000100,
    B00001000,
  },
  {
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00001000,
    B00001000,
    B00001000,
    B00001000
  },
  {
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
  },
  {
    B00001000,
    B00000100,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B00100000,
    B00010000,
  },
  {
    B00000000,
    B00000001,
    B00000010,
    B00001100,
    B00110000,
    B01000000,
    B10000000,
    B00000000,
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00001111,
    B11110000,
    B00000000,
    B00000000,
    B00000000
  }
};

/*DNAのようなイメージが横回転する。*/
void DNA_side() {
  unsigned long Time = millis();
  while (millis() - Time <= 5000) {
    for (int i = 0; i < 8; i++) {
      drow2(LED_dna, 100);
      swap(LED_dna);
    }
  }
}

/*DNAのようなイメージが縦回転する。*/
void DNA_ver() {
  unsigned long Time = millis();
  while (millis() - Time <= 5000) {
    for (int i = 0; i < 8; i++) {
      drow(LED_dna, 80);
      swap(LED_dna);
    }
  }
}
