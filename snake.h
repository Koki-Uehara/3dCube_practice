#include"Arduino.h"
#define DELAY_SURFACE_AROUND 40
#define DELAY_FOLDING 70
#define DELAY_LARGECUBE 50
#define DELAY_LARGECUBE2 150

//関数一覧*******************************************************************************************************
/*
  ledsCube_clear()
  setCube(int x, int y, int z, int s)
  largeCube()
  folding_1(byte pattern[8], int d)
  folding_2(byte pattern[8], int d)
  folding_3(byte pattern[8], int d)
  folding_4(byte pattern[8], int d)
  folding_5(byte pattern[8], int d)
  folding_6(byte pattern[8], int d)
  folding_7(byte pattern[8], int d)
  folding_8(byte pattern[8], int d)
  start_move(byte pattern[8])
  finish_move(byte pattern[8])
  surface_around()
  surface_around2()
  two_point_line()
  snake()
  pyramid()
  surface_movement()
*/
//*************************************************************************************************************

byte ledsCube[8][8];

/* 二次配列ledsCubeの中身を0にする*/
void ledsCube_clear(void) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ledsCube[i][j] = CL;
    }
  }
}

/* 引数で受け取った座標にs*s*sサイズのキューブ型にビットを立てる*/
void setCube(int x, int y, int z, int s) {
  ledsCube_clear();
  for (int i = 0; i < s; i++) {
    bitSet(ledsCube[x][y], z + i);
    bitSet(ledsCube[x][y + i], z);
    bitSet(ledsCube[x][y + i], z + s - 1);
    bitSet(ledsCube[x][y + s - 1], z + i);

    bitSet(ledsCube[x + i][y], z + s - 1);
    bitSet(ledsCube[x + i][y], z);
    bitSet(ledsCube[x + i][y + s - 1], z);
    bitSet(ledsCube[x + i][y + s - 1], z + s - 1);


    bitSet(ledsCube[x + s - 1][y], z + i);
    bitSet(ledsCube[x + s - 1][y + i], z);
    bitSet(ledsCube[x + s - 1][y + i], z + s - 1);
    bitSet(ledsCube[x + s - 1][y + s - 1], z + i);

  }
}

/* 2*2*2から8*8*8までCUBEを拡大縮小*/
void largeCube(void) {
  int i;
  setCube(0, 0, 0 , 8); drow(ledsCube, 150);
  for (i = 7 ; i >= 3; i--) {
    setCube(0, 0, 0 , i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 2); drow(ledsCube, 150);
  for (i = 3 ; i < 7; i++) {
    setCube(0, 0, 0 , i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, 150);

  for (i = 7 ; i >= 3; i--) {
    setCube(0, 0, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 6, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(0, 0, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(0, 8 - i, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 6, 0, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(0, 8 - i, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(0, 8 - i, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 6, 6, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(0, 8 - i, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(8 - i, 0, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(6, 0, 0, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(8 - i, 0, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(8 - i, 0, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(6, 0, 6, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(8 - i, 0, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(8 - i, 8 - i, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(6, 6, 0, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(8 - i, 8 - i, 0, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);

  for (i = 7 ; i >= 3; i--) {
    setCube(8 - i, 8 - i, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(6, 6, 6, 2); drow(ledsCube, DELAY_LARGECUBE2);
  for (i = 3 ; i < 7 ; i++) {
    setCube(8 - i, 8 - i, 8 - i, i); drow(ledsCube, DELAY_LARGECUBE);
  }
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);
  setCube(1, 1, 1, 6); drow(ledsCube, 70);
  setCube(2, 2, 2, 4); drow(ledsCube, 70);
  setCube(3, 3, 3, 2); drow(ledsCube, DELAY_LARGECUBE2);
  setCube(2, 2, 2, 4); drow(ledsCube, 70);
  setCube(1, 1, 1, 6); drow(ledsCube, 70);
  setCube(0, 0, 0 , 8); drow(ledsCube, DELAY_LARGECUBE2);
}

/*引数で受け取ったパターンを引数d=1でup-back,d=2でflont-upに移動*/
void folding_1(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[i][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[i][0] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でback-down,d=2でup_backに移動*/
void folding_2(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[i][0] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[i][7 - i ] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7][7 - i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でdown_front,d=2でback_downに移動*/
void folding_3(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7][7 - i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7 - i][7 - i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7 - i][7] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/*引数で受け取ったパターンを引数d=1でfront_up,d=2でdown_frontに移動 */
void folding_4(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7 - i][7] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7 - i ][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でup_right,d=2でfront_rightに移動 */
void folding_5(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[j][i], j);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[j][i], 0);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でright_downt,d=2でright_backに移動 */
void folding_6(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[j][i], 0);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[7 - j][i], j);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でdown_left,d=2でback_leftに移動 */
void folding_7(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[7][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[j][i], j);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[7 - j][i], 7);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 引数で受け取ったパターンを引数d=1でleft_up,d=2でleft_frontに移動 */
void folding_8(byte pattern[8], int d) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[7 - j][i], 7);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j) == 1) {
        bitSet(ledsCube[7 - j][i], j);
      }
    }
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[i];
  }
  if (d == 1) {
    drow(ledsCube, DELAY_FOLDING);
  } else {
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/**/
void start_move(byte pattern[8]) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[7 - i];
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/**/
void finish_move(byte pattern[8]) {
  ledsCube_clear();
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = pattern[7 - i];
  }
  for (int i = 0; i < 8; i++) {
    ledsCube[0][i] = CL;
    drow2(ledsCube, DELAY_FOLDING);
  }
}

/* 面の外周移動（横）*/
void surface_around(void) {
  byte pattern[8][8] = {
    { B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
    },
    {0}, {0}, {0}, {0}, {0}, {0},
  };

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[0][j] = bitClear(pattern[0][j], i);
      pattern[i + 1][j] = bitSet( pattern[i + 1][j], 7);
    }
    drow2(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[i][j] = bitClear(pattern[i][j], 7);
      pattern[7][j] = bitSet(pattern[7][j], 6 - i);
    }
    drow2(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 6; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      pattern[7][j] = bitClear(pattern[7][j], i + 1);
      pattern[i][j] = bitSet(pattern[i][j], 0);
    }
    drow2(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[7 - i][j] = bitClear(pattern[7 - i][j], 0);
      pattern[0][j] = bitSet(pattern[0][j], i + 1);
    }
    drow2(pattern, DELAY_SURFACE_AROUND);
  }
}

/* 面の外周移動（縦）*/
void surface_around2(void) {
  byte pattern[8][8] = {
    { B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
    },
    {0}, {0}, {0}, {0}, {0}, {0},
  };

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[0][j] = bitClear(pattern[0][j], i);
      pattern[i + 1][j] = bitSet( pattern[i + 1][j], 7);
      // drow(pattern, DELAY_SURFACE_AROUND);
    }
    drow(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[i][j] = bitClear(pattern[i][j], 7);
      pattern[7][j] = bitSet(pattern[7][j], 6 - i);
      //drow(pattern, DELAY_SURFACE_AROUND);
    }
    drow(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 6; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      pattern[7][j] = bitClear(pattern[7][j], i + 1);
      pattern[i][j] = bitSet(pattern[i][j], 0);
      // drow(pattern, DELAY_SURFACE_AROUND);
    }
    drow(pattern, DELAY_SURFACE_AROUND);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pattern[7 - i][j] = bitClear(pattern[7 - i][j], 0);
      pattern[0][j] = bitSet(pattern[0][j], i + 1);
      // drow(pattern, DELAY_SURFACE_AROUND);
    }
    drow(pattern, DELAY_SURFACE_AROUND);
  }
}

int pos_discrimination(int pos_start, int pos_goal) {
  if (pos_start < pos_goal) {
    pos_start++;
  } else if (pos_start > pos_goal) {
    pos_start--;
  }
  return pos_start;
}

// 8点をランダムで出現,その中の2点間を繋ぐ様に点灯
void two_point_line(void) {
  unsigned long now = millis();
  while (millis() - now < 10000) {
    ledsCube_clear();
    int posX1 = random(0, 2);
    int posY1 = random(0, 8);
    int posZ1 = random(0, 8);
    int posX2 = random(6, 8);
    int posY2 = random(0, 8);
    int posZ2 = random(0, 8);
    int posX3 = random(0, 2);
    int posY3 = random(0, 8);
    int posZ3 = random(0, 8);
    int posX4 = random(6, 8);
    int posY4 = random(0, 8);
    int posZ4 = random(0, 8);
    int posX5 = random(0, 2);
    int posY5 = random(0, 8);
    int posZ5 = random(0, 8);
    int posX6 = random(6, 8);
    int posY6 = random(0, 8);
    int posZ6 = random(0, 8);
    int posX7 = random(0, 2);
    int posY7 = random(0, 8);
    int posZ7 = random(0, 8);
    int posX8 = random(6, 8);
    int posY8 = random(0, 8);
    int posZ8 = random(0, 8);
    bitSet(ledsCube[posX1][posY1], posZ1);
    bitSet(ledsCube[posX2][posY2], posZ2);
    bitSet(ledsCube[posX3][posY3], posZ3);
    bitSet(ledsCube[posX4][posY4], posZ4);
    bitSet(ledsCube[posX5][posY5], posZ5);
    bitSet(ledsCube[posX6][posY6], posZ6);
    bitSet(ledsCube[posX7][posY7], posZ7);
    bitSet(ledsCube[posX8][posY8], posZ8);
    drow2(ledsCube, 700);
    while (!((posX1 == posX2) && (posY1 == posY2) && (posZ1 == posZ2)
             && (posX3 == posX4) && (posY3 == posY4) && (posZ3 == posZ4)
             && (posX5 == posX6) && (posY5 == posY6) && (posZ5 == posZ6)
             && (posX7 == posX8) && (posY7 == posY8) && (posZ7 == posZ8))) {
      posX1 = pos_discrimination(posX1, posX2);
      posY1 = pos_discrimination(posY1, posY2);
      posZ1 = pos_discrimination(posZ1, posZ2);
      posX4 = pos_discrimination(posX4, posX3);
      posY4 = pos_discrimination(posY4, posY3);
      posZ4 = pos_discrimination(posZ4, posZ3);
      posX5 = pos_discrimination(posX5, posX6);
      posY5 = pos_discrimination(posY5, posY6);
      posZ5 = pos_discrimination(posZ5, posZ6);
      posX8 = pos_discrimination(posX8, posX7);
      posY8 = pos_discrimination(posY8, posY7);
      posZ8 = pos_discrimination(posZ8, posZ7);

      bitSet(ledsCube[posX1][posY1], posZ1);
      bitSet(ledsCube[posX4][posY4], posZ4);
      bitSet(ledsCube[posX5][posY5], posZ5);
      bitSet(ledsCube[posX8][posY8], posZ8);
      drow2(ledsCube, 40);
    }
    drow2(ledsCube, 40);
  }
}

// ランダムに出現した6点間を繋ぐように点灯
void snake(void) {
  unsigned long now = millis();
  while (millis() - now < 15000) {
    ledsCube_clear();
    int posX = random(0, 4);
    int posY = random(0, 8);
    int posZ = random(0, 8);
    int posX2 = random(4, 8);
    int posY2 = random(0, 8);
    int posZ2 = random(0, 8);
    int posX3 = random(0, 4);
    int posY3 = random(0, 8);
    int posZ3 = random(0, 8);
    int posX4 = random(4, 8);
    int posY4 = random(0, 8);
    int posZ4 = random(0, 8);
    int posX5 = random(0, 4);
    int posY5 = random(0, 8);
    int posZ5 = random(0, 8);
    int posX6 = random(4, 8);
    int posY6 = random(0, 8);
    int posZ6 = random(0, 8);
    bitSet(ledsCube[posX][posY], posZ);
    bitSet(ledsCube[posX2][posY2], posZ2);
    bitSet(ledsCube[posX3][posY3], posZ3);
    bitSet(ledsCube[posX4][posY4], posZ4);
    bitSet(ledsCube[posX5][posY5], posZ5);
    bitSet(ledsCube[posX6][posY6], posZ6);
    drow2(ledsCube, 500);
    while (!((posX == posX2) && (posY == posY2) && (posZ == posZ2))) {
      posX = pos_discrimination(posX, posX2);
      posY = pos_discrimination(posY, posY2);
      posZ = pos_discrimination(posZ, posZ2);
      bitSet(ledsCube[posX][posY], posZ);
      drow2(ledsCube, 40);
    }
    while (!((posX == posX3) && (posY == posY3) && (posZ == posZ3))) {
      posX = pos_discrimination(posX, posX3);
      posY = pos_discrimination(posY, posY3);
      posZ = pos_discrimination(posZ, posZ3);
      bitSet(ledsCube[posX][posY], posZ);
      drow2(ledsCube, 40);
    }
    while (!((posX == posX4) && (posY == posY4) && (posZ == posZ4))) {
      posX = pos_discrimination(posX, posX4);
      posY = pos_discrimination(posY, posY4);
      posZ = pos_discrimination(posZ, posZ4);
      bitSet(ledsCube[posX][posY], posZ);
      drow2(ledsCube, 40);
    }
    while (!((posX == posX5) && (posY == posY5) && (posZ == posZ5))) {
      posX = pos_discrimination(posX, posX5);
      posY = pos_discrimination(posY, posY5);
      posZ = pos_discrimination(posZ, posZ5);
      bitSet(ledsCube[posX][posY], posZ);
      drow2(ledsCube, 40);
    }
    while (!((posX == posX6) && (posY == posY6) && (posZ == posZ6))) {
      posX = pos_discrimination(posX, posX6);
      posY = pos_discrimination(posY, posY6);
      posZ = pos_discrimination(posZ, posZ6);
      bitSet(ledsCube[posX][posY], posZ);
      drow2(ledsCube, 40);
    }
    drow2(ledsCube, 500);
  }
}

/* ピラミッドを下から順次点灯、その後上から順次消灯*/
void pyramid (void) {
  ledsCube_clear();
  byte pyramid[][8] = {
    {
      B11111111,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B11111111
    },

    {
      B00000000,
      B01111110,
      B01000010,
      B01000010,
      B01000010,
      B01000010,
      B01111110,
      B00000000,
    },

    {
      B00000000,
      B00000000,
      B00111100,
      B00100100,
      B00100100,
      B00111100,
      B00000000,
      B00000000,
    },

    {
      B00000000,
      B00000000,
      B00000000,
      B00011000,
      B00011000,
      B00000000,
      B00000000,
      B00000000
    },

    {
      B00000000,
      B00000000,
      B00000000,
      B00011000,
      B00011000,
      B00000000,
      B00000000,
      B00000000
    },

    {
      B00000000,
      B00000000,
      B00111100,
      B00100100,
      B00100100,
      B00111100,
      B00000000,
      B00000000,
    },

    {
      B00000000,
      B01111110,
      B01000010,
      B01000010,
      B01000010,
      B01000010,
      B01111110,
      B00000000,
    },

    {
      B11111111,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B10000001,
      B11111111
    }
  };

  for (int i = 7; i >= 0; i --) {
    for (int j = 7; j >= 0; j--) {
      for (int k = 7; k >= 0; k--) {
        if (bitRead(pyramid[i][j], k) == 1) {
          bitSet(ledsCube[i][j], k);
          drow(ledsCube, 15);
        }
      }
    }
  }
  for (int i = 0; i < 8; i ++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        if (bitRead(pyramid[i][j], k) == 1) {
          bitClear(ledsCube[i][j], k);
          drow(ledsCube, 15);
        }
      }
    }
  }
  for (int i = 7; i >= 0; i --) {
    for (int j = 7; j >= 0; j--) {
      for (int k = 7; k >= 0; k--) {
        if (bitRead(pyramid[i][j], k) == 1) {
          bitSet(ledsCube[i][j], k);
          drow2(ledsCube, 15);
        }
      }
    }
  }
}

/* 面の移動パターンを決める関数*/
void surface_movement(void) {
  byte pattern[8] = {
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
  };
  start_move(pattern);
  back_shift(pattern, 40);
  flont_shift(pattern, 40);
  back_shift(pattern, 40);
  folding_7(pattern, 2);
  folding_8(pattern, 2);
  folding_5(pattern, 2);
  left_shift();
  right_shift();
  left_shift();
  folding_8(pattern, 1);
  folding_5(pattern, 1);
  folding_6(pattern, 1);
  up_shift(pattern, 40);
  down_shift(pattern, 40);
  up_shift(pattern, 40);
  folding_1(pattern, 1);
  folding_2(pattern, 1);
  folding_3(pattern, 1);
  surface_around();
  folding_1(pattern, 2);
  folding_2(pattern, 2);
  folding_3(pattern, 2);
  folding_4(pattern, 2);
  folding_1(pattern, 2);
  surface_around2();
  folding_8(pattern, 2);
  folding_5(pattern, 2);
  folding_6(pattern, 2);
  folding_7(pattern, 2);
  folding_8(pattern, 2);
  finish_move(pattern);
}
