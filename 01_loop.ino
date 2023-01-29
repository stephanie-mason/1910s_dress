void loop() {  
  /** Update Variables **/
  startIndex++;
  
  EVERY_N_SECONDS( 60 ) {
      if (animationMode == numAnimations) {
        animationMode = 0;     
      } else {
        animationMode++;      
      }
  }

  switch (animationMode) {
    case 0:
      /** LOVE CONNECTION - PINK **/
      FastLED.setBrightness(100); 
      currentPalette = Love_p;  
      alternatingPaletteFill(startIndex);
      currentBlending = NOBLEND;
      steps = 10;      
      break;    
    case 1:
      /** RAYS OF WHITE **/ 
      FastLED.setBrightness(200); 
      currentPalette = White_p;  
      burstPaletteFillTail(startIndex);
      burstPaletteFillBody(startIndex);
      burstPaletteFillNeck(startIndex);
      currentBlending = LINEARBLEND;
      steps = 4;      
      break;  
    case 2: 
      /** BEATS **/
      FastLED.setBrightness(40); 
      currentPalette = Pink_p;
      currentBlending = LINEARBLEND;
      bpm();
      break;
    case 3:
      /** BRITE BOOUNCE **/
      FastLED.setBrightness(100);
      currentPalette = BriteNoBlack_p;
      alternatingPaletteFill(startIndex);   
      currentBlending = LINEARBLEND;   
      steps = 5;
      break;
    case 4: 
      /** RED TEAL FLOWS **/ 
      FastLED.setBrightness(100); 
      currentPalette = RedTeal_p;  
      burstPaletteFillTail(startIndex);
      burstPaletteFillBody(startIndex);
      burstPaletteFillNeck(startIndex);
      currentBlending = LINEARBLEND;
      steps = 4;      
      break;      
    case 5:
      /** BRITE & SHINE **/
      FastLED.setBrightness(90);
      currentPalette = BriteWithBlack_p;
      burstPaletteFillTail(startIndex);
      burstPaletteFillBody(startIndex);
      burstPaletteFillNeck(startIndex);      
      currentBlending = LINEARBLEND;
      steps = 7;    
      break;    
    case 6:
      /** PEW PEW **/ 
      FastLED.setBrightness(100); 
      currentPalette = White_p;  
      alternatingPaletteFill(startIndex);
      currentBlending = LINEARBLEND;
      steps = 5;      
      break;            
    case 7:
      /** VAPORWAVE **/
      FastLED.setBrightness(100);
      currentPalette = Vaporwave_p;  
      alternatingPaletteFill(startIndex);     
      currentBlending = LINEARBLEND; 
      steps = 10;      
      break;
    case 8:
      /** PURPLE RAIN, PURPLE RAIN **/ /* DONE */
      FastLED.setBrightness(255);
      currentPalette = Purple_p;  
      burstPaletteFillTail(startIndex);
      burstPaletteFillBody(startIndex);
      burstPaletteFillNeck(startIndex);    
      currentBlending = LINEARBLEND;  
      steps = 8;      
      break;
    case 9: 
      /** SPARKLE **/
      FastLED.setBrightness(30);
      sparkle();      
      break;              
  }   
  
    
  FastLED.show(); 
  delay(animationSpeed);  
}
