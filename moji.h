#include"Arduino.h"

//関数一覧*******************************************************************************************************
/*
Word
Number_Clear()
CountDown_X(byte pattern_White[8], byte pattern_Orange[8])
Last()
CountDown001()
moji2(byte pattern[8], int delayTime)
Opening()
Opening_Compromise()
*/
//*************************************************************************************************************

// Last Attack
byte pattern_00[] = {B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000};
byte pattern_01[] = {B00000000, B00000000, B00111100, B00100100, B00100100, B00111100, B00000000, B00000000};
byte pattern_02[] = {B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000};
byte pattern_03[] = {B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111};
//アルファベット
byte pattern_A[] = {B00111100, B01111110, B11100111, B11000011, B11111111, B11111111, B11000011, B11000011};
byte pattern_B[] = {B11111110, B11111111, B10000001, B11111110, B11111111, B10000001, B11111111, B11111110};
byte pattern_C[] = {B00111100, B01111110, B11000111, B11000000, B11000000, B11000111, B01111110, B00111100};
byte pattern_D[] = {B11111100, B11111110, B11000111, B11000011, B11000011, B11000111, B11111110, B11111100};
byte pattern_E[] = {B11111111, B11111111, B11000000, B11111110, B11111110, B11000000, B11111111, B11111111};
byte pattern_F[] = {B11111111, B11111111, B11000000, B11111110, B11111110, B11000000, B11000000, B11000000};
byte pattern_G[] = {B01111110, B11111110, B11000000, B11011111, B11011111, B11000110, B11111110, B01111100};
byte pattern_H[] = {B11000011, B11000011, B11000011, B11111111, B11111111, B11000011, B11000011, B11000011};
byte pattern_I[] = {B00111100, B00111100, B00011000, B00011000, B00011000, B00011000, B00111100, B00111100};
byte pattern_J[] = {B11111111, B11111111, B00000110, B00000110, B11000110, B11000110, B01111110, B00111100};
byte pattern_K[] = {B11000110, B11001100, B11011000, B11110000, B11011000, B11001100, B11000110, B11000110};
byte pattern_L[] = {B11000000, B11000000, B11000000, B11000000, B11000000, B11000000, B11111110, B11111110};
byte pattern_M[] = {B11000011, B11100111, B11111111, B11011011, B11000011, B11000011, B11000011, B11000011};
byte pattern_N[] = {B11000011, B11100011, B11110011, B11011011, B11001111, B11000111, B11000011, B11000011};
byte pattern_O[] = {B00111100, B01111110, B11100111, B11000011, B11000011, B11100111, B01111110, B00111100};
byte pattern_P[] = {B11111110, B11111111, B11000011, B11000011, B11111111, B11111110, B11000000, B11000000};
byte pattern_Q[] = {B00111100, B01111110, B11100111, B11000011, B11001011, B11000111, B01111110, B00111101};
byte pattern_R[] = {B11111110, B11111111, B11000011, B11000011, B11111110, B11111111, B11000011, B11000011};
byte pattern_S[] = {B01111110, B01111110, B11000000, B11111110, B01111110, B00000001, B01111111, B01111110};
byte pattern_T[] = {B11111111, B11111111, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};
byte pattern_U[] = {B11000011, B11000011, B11000011, B11000011, B11000011, B11000011, B11111111, B11111111};
byte pattern_V[] = {B11000011, B11000011, B11000011, B11000011, B11000011, B11000011, B01111110, B00111100};
byte pattern_W[] = {B11000011, B11000011, B11011011, B11011011, B11011011, B11011011, B11011011, B01100110};
byte pattern_X[] = {B11000011, B11000011, B01100110, B00111100, B00111100, B01100110, B11000011, B11000011};
byte pattern_Y[] = {B10000001, B11000011, B01100110, B00111100, B00011000, B00011000, B00011000, B00011000};
byte pattern_Z[] = {B11111111, B11111111, B00000110, B00001100, B00011000, B00110000, B11111111, B11111111};
byte pattern_COLON[] = {B00000000, B00011000, B00011000, B00000000, B00000000, B00011000, B00011000, B00000000,};
byte pattern_SEMICO[] = {B00000000, B00011000, B00011000, B00000000, B00011000, B00011000, B00001000, B00000000};
byte pattern_DOT[] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000110, B00000110,};
byte pattern_KAO1[] = {B01000010, B11100111, B10100101, B00000000, B01111110, B01000010, B01000010, B01111110};
byte pattern_Mr[] = {B11111000, B10101000, B10101000, B10101000, B00000101, B00000110, B00000100, B00000100};
byte pattern_0[] = {B01111110, B01111110, B01100110, B01100110, B01100110, B01100110, B01111110, B01111110};
byte pattern_1[] = {B01111000, B01111000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};
byte pattern_2[] = {B01111110, B01111110, B00000110, B01111110, B01111110, B01100000, B01111110, B01111110};
byte pattern_3[] = {B01111110, B01111110, B00000110, B00111110, B00111110, B00111110, B00000110, B01111110};
byte pattern_4[] = {B01101100, B01101100, B01101100, B01101100, B01111110, B01111110, B00001100, B00001100};
byte pattern_5[] = {B01111110, B01111110, B01100000, B01111110, B01111110, B00000110, B01111110, B01111110};
byte pattern_6[] = {B01111110, B01111110, B01100000, B01111110, B01111110, B01100110, B01111110, B01111110};
byte pattern_7[] = {B01111110, B01111110, B01100110, B01100110, B00000110, B00000110, B00000110, B00000110};
byte pattern_8[] = {B01111110, B01100110, B01100110, B01111110, B01111110, B01100110, B01100110, B01111110};
byte pattern_9[] = {B01111110, B01111110, B01100110, B01111110, B01111110, B00000110, B01111110, B01111110};
byte pattern_Que[] = {B01111110, B11000011, B11000011, B00011111, B00011110, B00011000, B00000000, B00011000};
byte pattern_SPADE[] = {B00011000, B00111100, B01111110, B11111111, B11111111, B00011000, B00111100, B01111110};
byte pattern_HEART[] = {B01100110, B11111111, B11111111, B11111111, B11111111, B01111110, B00111100, B00011000};
byte pattern_DIA[] = {B00011000, B00111100, B01111110, B11111111, B11111111, B01111110, B00111100, B00011000};
byte pattern_CLUB[] = {B00111100, B00111100, B11111111, B11100111, B11100111, B00011000, B00111100, B01111110};
byte pattern_STAR[] = {B00011000, B00011000, B11111111, B11111111, B00111100, B01111110, B11000011, B11000011};
byte pattern_B_STAR[] = {B11111111, B11100111, B10000001, B10000001, B11000011, B10011001, B10011001, B11111111};
byte pattern_t[] = {B00000000, B00000000, B00011000, B00111100, B00111100, B00011000, B00011000, B00011100};
byte pattern_e[] = {B00000000, B00000000, B01111100, B01111100, B01100100, B01111100, B01100000, B01111100};
byte pattern_i[] = {B00000000, B00000000, B00011000, B00011000, B00000000, B00011000, B00011000, B00011000};
byte pattern_n[] = {B00000000, B00000000, B00000000, B01111100, B01111100, B01101100, B01101100, B01101100};
byte pattern_s[] = {B00000000, B00000000, B01111110, B01111110, B01100000, B01111110, B00000110, B01111110};
byte pattern_a[] = {B00000000, B00000000, B00111100, B00111100, B00001100, B01111100, B01101110, B01111110};
//カウントダウン---白抜きを「H」
byte pattern_L0[] = {B00000000, B00111100, B01111110, B01100110, B01100110, B01111110, B00111100, B00000000};
byte pattern_H0[] = {B11111111, B11000011, B10000001, B10011001, B10011001, B10000001, B11000011, B11111111};
byte pattern_L1[] = {B00000000, B00111000, B00111000, B00011000, B00011000, B00011000, B00011000, B00000000};
byte pattern_H1[] = {B11111111, B11000111, B11000111, B11100111, B11100111, B11100111, B11100111, B11111111};
byte pattern_L2[] = {B00000000, B00111100, B00000100, B00111100, B00100000, B00100000, B00111100, B00000000};
byte pattern_H2[] = {B11111111, B11000011, B11111011, B11000011, B11011111, B11011111, B11000011, B11111111};
byte pattern_L3[] = {B00000000, B00111100, B00000100, B00111100, B00000100, B00000100, B00111100, B00000000};
byte pattern_H3[] = {B11111111, B11000011, B11111011, B11000011, B11111011, B11111011, B11000011, B11111111};
byte pattern_L4[] = {B00000000, B00101000, B00101000, B00101000, B00111100, B00001000, B00001000, B00000000};
byte pattern_H4[] = {B11111111, B11010111, B11010111, B11010111, B11000011, B11110111, B11110111, B11111111};
byte pattern_L5[] = {B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000};
byte pattern_H5[] = {B11111111, B11000011, B11011111, B11000011, B01111011, B11111011, B11000011, B11111111};
byte pattern_L6[] = {B00000000, B00111100, B00100000, B00111100, B00100100, B00100100, B00111100, B00000000};
byte pattern_H6[] = {B11111111, B11000011, B11011111, B11000011, B11011011, B11011011, B11000011, B11111111};
byte pattern_L7[] = {B00000000, B00111100, B00100100, B00000100, B00000100, B00000100, B00000100, B00000000};
byte pattern_H7[] = {B11111111, B11000011, B11011011, B11111011, B11111011, B11111011, B11111011, B11111111};
byte pattern_L8[] = {B00000000, B00111100, B00100100, B00111100, B00100100, B00100100, B00111100, B00000000};
byte pattern_H8[] = {B11111111, B11000011, B11011011, B11000011, B11011011, B11011011, B11000011, B11111111};
byte pattern_L9[] = {B00000000, B00111100, B00100100, B00111100, B00000100, B00000100, B00111100, B00000000};
byte pattern_H9[] = {B11111111, B11000011, B11011011, B11000011, B01111011, B11111011, B11000011, B11111111};

//THANKYOU
void Word(){
flont_shift(pattern_T, 40);
flont_shift(pattern_H, 40);
flont_shift(pattern_A, 40);
flont_shift(pattern_N, 40);
flont_shift(pattern_K, 40);
flont_shift(pattern_Y, 40);
flont_shift(pattern_O, 40);
flont_shift(pattern_U, 40);
flont_shift(pattern_DOT, 40);
flont_shift(pattern_DOT, 40);
flont_shift(pattern_DOT, 40);
delay(2000);
flont_shift(pattern_Mr, 40);
flont_shift(pattern_DOT, 40);
flont_shift(pattern_M, 40);
flont_shift(pattern_I, 40);
flont_shift(pattern_Y, 40);
flont_shift(pattern_A, 40);
flont_shift(pattern_U, 40);
flont_shift(pattern_C, 40);
flont_shift(pattern_H, 40);
flont_shift(pattern_I, 40);
flont_shift(pattern_KAO1, 100);

}

//カウントダウン用の関数
byte Count_Number[8][8];
//Cube内のデータを消す
void Number_Clear(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Count_Number[i][j] = CL;
    }
  }
};

//カウントダウンの「X」
void CountDown_X(byte pattern_White[8], byte pattern_Orange[8]){
  Number_Clear();
  for(int i = 7; i > 3; i--){
    for(int j = 0; j < 8; j++){
      Count_Number[i][j] = pattern_White[j];
    } drow2(Count_Number, 100);
  }
  for(int i = 3; i >= 0; i--){
    for(int j = 0; j < 8; j++){
      Count_Number[i][j] = pattern_Orange[j];
    } drow2(Count_Number, 100);
  }
};

//呼び出す用の関数
void CountDown001(){
  byte pattern_Orange0[] = {B00000000, B01111110, B01111110, B01100110, B01100110, B01111110, B01111110, B00000000};
  byte pattern_White0[] = {B11111111, B10000001, B10000001, B10011001, B10011001, B10000001, B10000001, B11111111};
  byte pattern_Orange1[] = {B00000000, B00111000, B00111000, B00011000, B00011000, B00011000, B00011000, B00000000};
  byte pattern_White1[] = {B11111111, B11000111, B11000111, B11100111, B11100111, B11100111, B11100111, B11111111};
  byte pattern_Orange2[] = {B00000000, B00111100, B00000100, B00111100, B00100000, B00100000, B00111100, B00000000};
  byte pattern_White2[] = {B11111111, B11000011, B11111011, B11000011, B11011111, B11011111, B11000011, B11111111};
  byte pattern_Orange3[] = {B00000000, B00111100, B00000100, B00111100, B00000100, B00000100, B00111100, B00000000};
  byte pattern_White3[] = {B11111111, B11000011, B11111011, B11000011, B11111011, B11111011, B11000011, B11111111};
  byte pattern_Orange4[] = {B00000000, B00101000, B00101000, B00101000, B00111100, B00001000, B00001000, B00000000};
  byte pattern_White4[] = {B11111111, B11010111, B11010111, B11010111, B11000011, B11110111, B11110111, B11111111};
  byte pattern_Orange5[] = {B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000};
  byte pattern_White5[] = {B11111111, B11000011, B11011111, B11000011, B01111011, B11111011, B11000011, B11111111};
  
  CountDown_X(pattern_White5, pattern_Orange5);
  CountDown_X(pattern_White4, pattern_Orange4);
  CountDown_X(pattern_White3, pattern_Orange3);
  CountDown_X(pattern_White2, pattern_Orange2);
  CountDown_X(pattern_White1, pattern_Orange1);
  CountDown_X(pattern_White0, pattern_Orange0);
  
}

//文末に表示する
void Last(){
    back_shift(pattern_03, 20);
    back_shift(pattern_02, 20);
    back_shift(pattern_01, 20);
    back_shift(pattern_00, 20);
    flont_shift(pattern_01, 20);
    flont_shift(pattern_02, 20);
    flont_shift(pattern_03, 20);
}
//オープニング

void moji2(byte pattern[8], int delayTime) {
Number_Clear();
 
       drow2(Count_Number, delayTime);
       Count_Number[0][6] = pattern[0];
       Count_Number[0][7] = pattern[1];
       drow2(Count_Number, delayTime);
       Count_Number[0][5] = pattern[0];
       Count_Number[0][6] = pattern[1];
       Count_Number[0][7] = pattern[2];
       drow2(Count_Number, delayTime);
       Count_Number[0][4] = pattern[0];
       Count_Number[0][5] = pattern[1];
       Count_Number[0][6] = pattern[2];
       Count_Number[0][7] = pattern[3];
       drow2(Count_Number, delayTime);
       Count_Number[0][3] = pattern[0];
       Count_Number[0][4] = pattern[1];
       Count_Number[0][5] = pattern[2];
       Count_Number[0][6] = pattern[3];
       Count_Number[0][7] = pattern[4];
       drow2(Count_Number, delayTime);
       Count_Number[0][2] = pattern[0];
       Count_Number[0][3] = pattern[1];
       Count_Number[0][4] = pattern[2];
       Count_Number[0][5] = pattern[3];
       Count_Number[0][6] = pattern[4];
       Count_Number[0][7] = pattern[5];
       drow2(Count_Number, delayTime);
       Count_Number[0][1] = pattern[0];
       Count_Number[0][2] = pattern[1];
       Count_Number[0][3] = pattern[2];
       Count_Number[0][4] = pattern[3];
       Count_Number[0][5] = pattern[4];
       Count_Number[0][6] = pattern[5];
       Count_Number[0][7] = pattern[6];
       drow2(Count_Number, delayTime);
       Count_Number[0][0] = pattern[0];
       Count_Number[0][1] = pattern[1];
       Count_Number[0][2] = pattern[2];
       Count_Number[0][3] = pattern[3];
       Count_Number[0][4] = pattern[4];
       Count_Number[0][5] = pattern[5];
       Count_Number[0][6] = pattern[6];
       Count_Number[0][7] = pattern[7];
       drow2(Count_Number, delayTime);
       back_shift(pattern, 10);

}

void Opening(){
  moji2(pattern_A, 40);
//  back_shift(pattern_A, 0);
  moji2(pattern_R, 40);
//  back_shift(pattern_R, 40);
  moji2(pattern_E, 40);
//  back_shift(pattern_E, 40);
  moji2(pattern_Y, 40);
//  back_shift(pattern_Y, 40);
  moji2(pattern_O, 40);
//  back_shift(pattern_O, 40);
  moji2(pattern_U, 40);
//  back_shift(pattern_U, 40);
  moji2(pattern_R, 40);
//  back_shift(pattern_R, 40);
  moji2(pattern_E, 40);
//  back_shift(pattern_E, 40);
  moji2(pattern_A, 40);
//  back_shift(pattern_A, 40);
  moji2(pattern_D, 40);
//  back_shift(pattern_D, 40);
  moji2(pattern_Y, 40);
//  back_shift(pattern_Y, 40);
  moji2(pattern_Que,40);
//  back_shift(pattern_Que, 40);
};

void Opening_Compromise(){
  
  back_shift(pattern_A, 40);
 
  back_shift(pattern_R, 40);
 
  back_shift(pattern_E, 40);
  
  back_shift(pattern_Y, 40);
  
  back_shift(pattern_O, 40);
  
  back_shift(pattern_U, 40);
 
  back_shift(pattern_R, 40);
  
  back_shift(pattern_E, 40);
  
  back_shift(pattern_A, 40);
 
  back_shift(pattern_D, 40);
  
  back_shift(pattern_Y, 40);
  
  back_shift(pattern_Que, 40);
};
  
