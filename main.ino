#include <SPI.h>

/* 各レイヤーピン番号 */
#define LAYER_0 2
#define LAYER_1 3
#define LAYER_2 4
#define LAYER_3 5
#define LAYER_4 6
#define LAYER_5 7
#define LAYER_6 8
#define LAYER_7 9

/* ディレイタイム */
/*（値「1000」で1秒間消灯）*/
#define DELAY_TIME 50

/* ダイナミック点灯のディレイタイム */
/* 値「1」で固定 */
#define DINAMIC_DELAY_TIME 2

/* レイヤー合計数 */
#define LAYER_SUM 8

/* 各レイヤー配列 */
/* キューブの最上部の面を「0」、最下部の面を「7」とする */
int layers[] = {
  LAYER_0,
  LAYER_1,
  LAYER_2,
  LAYER_3,
  LAYER_4,
  LAYER_5,
  LAYER_6,
  LAYER_7,
};

/* ヘッダーファイルをインクルード */
#include"function.h"
#include"daice.h"
#include"snake.h"
#include"randam.h"
#include"moji.h"
#include"block.h"


/* セットアップ関数 */
void setup() {
/* SPI通信のセットアップ*/
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, LSBFIRST, SPI_MODE0));
/* レイヤーピンをアウトプットに設定*/ 
for(int i = 0; i<8;i++ )
pinMode( layers[i], OUTPUT );
/* 各レイヤーはLOWで初期化 */
  all_clear();
  randomSeed(digitalRead(0));
}

/* 関数 */
void loop() {
  Opening();
  CountDown001();
  delay(1500);
  random_on(0);
  pyramid();
  Last();
  megaphone();
  delay(500);
  random_on(1);
  DNA_side();
  DNA_ver();
  wave();
  delay(1000);
  rain(0,4,0);
  rain(4,8,1);
  rain(0,8,0);
  arrow();
  surface_movement();
  tetris();
  delay(500);
  brock_slide_1();
  brock_slide_1();
  brock_change_slide();
  brock_slide_2();
  brock_slide_2();
  largeCube();
  random_daice2(30000, 2, 200);
  dice_to_cubeslide();
  cubeSlide(0);
  cubeSlide(2);
  delay(500);
  two_point_line();
  snake();
  delay(500);
  Word();
  delay(100000);
}
