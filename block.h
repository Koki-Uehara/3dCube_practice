#include"Arduino.h"
#define SLIDE_SPEED 40

//関数一覧*******************************************************************************************************
/*
megaphone()　なみなみメガホン
brock_slide_1() ブロック移動１
brock_change_slide() ブロック移動つなぎ２
brock_slide_2() ブロック移動２
wave() 波
*/
//*************************************************************************************************************

/*なみなみメガホン*/
void megaphone() {
  byte pattern[][8] = {
    {
      B11111111,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B11111111
    },

    {
      B10000001,
      B01111110,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B01111110,
      B10000001,
    },

    {
      B10000001,
      B00000000,
      B00111100,
      B00000000,
      B0000000,
      B00111100,
      B00000000,
      B10000001,
    },

    {
      B10000001,
      B00000000,
      B00000000,
      B00011000,
      B00011000,
      B00000000,
      B00000000,
      B10000001
    },

    {
      B10000001,
      B00000000,
      B00000000,
      B00011000,
      B00011000,
      B00000000,
      B00000000,
      B10000001
    },

    {
      B10000001,
      B00000000,
      B00111100,
      B00000000,
      B00000000,
      B00111100,
      B00000000,
      B10000001,
    },

    {
      B10000001,
      B01111110,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B01111110,
      B10000001,
    },

    {
      B11111111,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B11111111
    }
  };

  unsigned long startTime = millis();
  while (millis() - startTime <=  5000) {
    for(int i = 0; i < 8; i++){
      drow(pattern,80);
      swap(pattern);
    }
  }
}

/* 4*4*8箱左から右へスライド→元に戻る */
void brock_slide_1(void) {
  byte brock[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      brock[i][j] = CL;
    }
  }

// 橙色箱右スライド
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        brock[k][i] = (val >> k) & 0xff;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }

// 橙色箱左スライド
  for(int k = 0; k < 5; k++){
    int j = 4;
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
       for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
    j--;
  }
  
// 白色箱右スライド
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        brock[k][i] = (val >> k) & 0xff;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }

// 白色箱左スライド
  for(int k = 0; k < 5; k++){
    int j = 4;
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
       for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        SPI.transfer(brock[j][i] << k);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
    j--;
  }

/* 4*4*8箱左から右へスライド →　元に戻る*/
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      brock[i][j] = CL;
    }
  }

/*橙色右スライド*/
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        brock[k][i] = (val >> k) & 0xff;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }

/* 白色箱右スライド*/
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
       for (int i = 0; i < LAYER_SUM; i++) {
        int val = B00001111;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }

/*橙色箱左スライド*/
  for(int k = 0; k < 5; k++){
    int j = 0;
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        int val = B00001111;
        brock[k][i] = (val << k) & 0xff;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }
/*白色箱左スライド*/
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
       for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }
}

/* 次のスライドへの繋ぎ */
void brock_change_slide(void) {
  byte brock[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      brock[i][j] = CL;
    }
  }
    
// 橙色右スライド
  for(int k = 0; k < 5; k++){
    unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        int val = B11110000;
        brock[k][i] = (val >> k) & 0xff;
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(brock[k][i]);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        SPI.transfer(val);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }
  }

// 後方スライド（収まる）
  unsigned long startTime = millis();
    while((millis() - startTime) <= SLIDE_SPEED) {
      for (int i = 0; i < LAYER_SUM; i++) {
        digitalWrite(layers[i], HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(B00001111);
        SPI.transfer(B00001111);
        SPI.transfer(B00001111);
        SPI.transfer(B00001111);
        SPI.transfer(B11110000);
        SPI.transfer(B11110000);
        SPI.transfer(B11110000);
        SPI.transfer(B11110000);
        digitalWrite(SS, HIGH );
        all_clear();
      }
    }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      brock[i][j] = B00001111;
    }
  }
  for (int i = 4; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      brock[i][j] = B11110000;
    }
  }

  for (int j = 4; j < 8; j++ ) {
    for (int i = 0; i < 8; i++) {
      brock[j - 4][i] = CL;
      brock[j][i] = ALL;
    }
    drow2(brock, SLIDE_SPEED);
  }
}

/* 上段8*4*4箱前方スライド→元に戻る */
void brock_slide_2(){
  byte brock[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i >= 4) {
        brock[i][j] = ALL;
      } else {
        brock[i][j] = CL;
      } 
    }
  }

// 上段前方スライド
  for (int i = 7; i > 3; i--) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 0; j < 4; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i - 4][j];
      brock[i - 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

// 上段後方スライド
  for (int i = 0; i < 4; i++) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 0; j < 4; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i + 4][j];
      brock[i + 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

/* 下段8*4*4箱前方スライド→元に戻る */

// 下段前方スライド
  for (int i = 7; i > 3; i--) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 4; j < 8; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i - 4][j];
      brock[i - 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

// 下段後方スライド
  for (int i = 0; i < 4; i++) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 4; j < 8; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i + 4][j];
      brock[i + 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

/* 上段・下段8*4*4箱前方スライド */

// 上段スライド
  for (int i = 7; i > 3; i--) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 0; j < 4; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i - 4][j];
      brock[i - 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

// 下段スライド
  for (int i = 7; i > 3; i--) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 4; j < 8; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i - 4][j];
      brock[i - 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

/* 上段・下段8*4*4箱後方スライド */
 // 上段後方スライド
  for (int i = 0; i < 4; i++) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 0; j < 4; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i + 4][j];
      brock[i + 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);

// 下段後方スライド
  for (int i = 0; i < 4; i++) {
    drow2(brock, SLIDE_SPEED);
    for (int j = 4; j < 8; j++) {
      byte temp = brock[i][j];
      brock[i][j] =  brock[i + 4][j];
      brock[i + 4][j] = temp;        
    }
  }
  drow2(brock, SLIDE_SPEED);
}

/* 波 */
void wave(){
  byte LED[][8]={
    {
      0,
      0,
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111
    },
    {
      0,
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111,
      B11111111
    },
    {
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111
    },
    {
      0,
      0,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111
    },
    {
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111
    },
   {
      0,
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111,
      B11111111
    },
   {
      0,
      0,
      0,
      0,
      0,
      B11111111,
      B11111111,
      B11111111
    },
   {
      0,
      0,
      0,
      0,
      0,
      0,
      B11111111,
      B11111111
    },
  };
  byte LED2[][8]={
    {
      0,
      0,
      0,
      B11111111,
      0,
      0,
      0,
      B11111111
    },
    {
      0,
      0,
      B11111111,
      0,
      0,
      B11111111,
      0,
      0
    },
    {
      0,
      B11111111,
      0,
      0,
      0,
      B11111111,
      0,
      0
    },
    {
      B11111111,
      0,
      0,
      0,
      B11111111,
      0,
      0,
      0
    },
    {
      0,
      B11111111,
      0,
      0,
      0,
      B11111111,
      0,
      0
    },
   {
      0,
      0,
      B11111111,
      0,
      0,
      0,
      B11111111,
      0
    },
   {
      0,
      0,
      0,
      B11111111,
      0,
      0,
      0,
      B11111111
    },
   {
      0,
      0,
      B11111111,
      0,
      0,
      0,
      B11111111,
      0
    },
  };
  unsigned long startTime = millis();
  while (millis() - startTime <=  5000) {
    for(int i = 0; i < 8; i++){
      drow2(LED,50);
      swap(LED);
    }
  }
}
