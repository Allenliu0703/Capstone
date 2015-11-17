
const int boundBL[2] = {0, 0}; //Bottom Left coordinate
const int boundBR[2] = {100, 0}; //Bottom Right  "
const int boundTL[2] = {0, 100}; //Top Left     "
const int boundTR[2] = {100, 100}; //Top Right     "
const String STATES[4] = {"MOVE", "RECTIFY", "SHIFT", "UPDATE"};


void setup() {
    String currS = STATES[0]; // initialize primary state: MOVE
}

void loop() {
  //global variables calling subroutines
  //int start = get_start(); // [startX, startY]
  //int goal = get_goal(); // [goalX, goalY] from corner coordinates
  //int goalDEG = get_goalDEG(); //IN DEGREES!
  //int compass = get_compass();
  //int pos = get_position(); //[posX, posY]

  //STATE MACHINE
    // State Transition
      if (currS == STATES[0]) // MOVE
        { 
          Serial.print ("Drive motor"); // Sate Defninition
          
          if (compass-goal < -22.5 || compass-goal > 22.5)
           {nxtS = STATES[1]} //RECTIFY
         }
//////////
         
      else if (currS == STATES[1]) // RECTIFY
        {
          Serial.print ("Update motor"); // Sate Defninition
          //no need to get position since in loop ? !
          
          if (compass-goal > -22.5 || compass-goal < 22.5)
            {nxtS = STATES[0]}//MOVE
          else if (pos == goal)
           {nxtS = STATES[2]} //SHIFT
         }
//////////
         
      else if (currS == STATEs[2]) //SHIFT
        {
          nxt_pos = get_pos();
          while (nxt_pos[0] < pos[0]+5)
            {Serial.print ("Drive left"); // Sate Defninition}
          
          if (goal == [ pos[0]+5, pos[1] ]) //COMPILE ? ! 
           {nxtS = STATES[3]} //UPDATE
         }
//////////
         
      else //if (currS == STATES[3]) //UPDATE
        {
          Serial.print ("Goal*"); // Sate Defninition
           get_goal();
          
          if (nxtGOAL != goal) // ? ? ?
           {nxtS = STATES[0]} //MOVE
         }
//////////
     
     currS = nxtS  
}

//UPDATE GOAL
int get_goal(sart){ //make goal a parameter ? !

  return theGoal;
  }
int get_goalDEG(start, pos){
  
  return theGoal;
  }


// FROM SONAR BEACON
int get_start(){
  
  return theStart;
  }

// FROM COMPASS
int get_compass(){

  return degree;
}
