void alternatingPaletteFill(uint8_t colorIndex) {
  for(uint8_t i = 0; i < NUM_TAIL_LEDS; i++) {
    tail_leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += steps;              
  }
  for(uint8_t i = 0; i < NUM_BODY_LEDS; i++) {
    if (i != 13){
      body_leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    colorIndex += steps;              
  }
   for(uint8_t i = 0; i < NUM_NECK_LEDS; i++) {
    neck_leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += steps;              
  }
}

void burstPaletteFillTail (uint8_t colorIndex) {
  for (uint8_t i = 0; i < 19; i++) {
    if (i < 9) {
      tail_leds[stripOne[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      tail_leds[stripSeven[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    if (i < 17) {
      tail_leds[stripTwo[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      tail_leds[stripSix[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);      
    }
    if (i < 18) {
      tail_leds[stripThree[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      tail_leds[stripFive[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
      tail_leds[stripFour[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    
    colorIndex += steps;
  }
}

void burstPaletteFillBody (uint8_t colorIndex) {
  for (uint8_t i = 0; i < 9; i++) {
    if (i < 4) {
      body_leds[stripEleven[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      body_leds[stripThirteen[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    if (i < 5) {
      body_leds[stripEight[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      body_leds[stripTen[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    if (i < 6) {
      body_leds[stripTwelve[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    body_leds[stripNine[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);

    colorIndex += steps;
  }
}

void burstPaletteFillNeck (uint8_t colorIndex) {
  for (uint8_t i = 0; i < 12; i++) {
    neck_leds[stripFourteen[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    neck_leds[stripFifteen[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);

    colorIndex += steps;
  }
}

void sparkle() 
{ 
  fadeToBlackBy( tail_leds, NUM_TAIL_LEDS, 10);
  int tail_pos = random16(NUM_TAIL_LEDS);
  tail_leds[tail_pos] += 0xEEEEEE;

  fadeToBlackBy( body_leds, NUM_BODY_LEDS, 30);
  int body_pos = random16(NUM_BODY_LEDS);
  body_leds[body_pos] += 0xAAAAAA;
  body_leds[13] = 0x000000; /* this LED should always be off*/

  fadeToBlackBy( neck_leds, NUM_NECK_LEDS, 30);
  int neck_pos = random16(NUM_NECK_LEDS);
  neck_leds[neck_pos] += 0xFFFFFF;
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 60;
  uint8_t beat = beatsin8( BeatsPerMinute, 0, 200);
  for( int i = 0; i < NUM_TAIL_LEDS; i++) { //9948
    tail_leds[i] = ColorFromPalette(currentPalette, gHue+(i/3), beat-gHue+(i*10));
  }

  /* Back Body */
  for( int i = 0; i < 20; i++) { //9948
    if (i != 13)  {
      body_leds[i] = ColorFromPalette(currentPalette, gHue+(i/3), beat-gHue+(i*10));
    }
  }
  /* Front Body */
   for( int i = 21; i < NUM_BODY_LEDS; i++) { //9948
    body_leds[i] = ColorFromPalette(currentPalette, gHue+(i/3), beat-gHue+(i*10));
  }

  for( int i = 0; i < NUM_NECK_LEDS; i++) { //9948
    neck_leds[i] = ColorFromPalette(currentPalette, gHue+(i/3), beat-gHue+(i*10));
  }
}
