/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\19.tyler.harpster                                */
/*    Created:      Thu Nov 16 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 9, 2, 10     
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <stdio.h>
#include <iostream>
#include "cooldictionarty.h"
#define turnspeedthing 500

using namespace vex;

void Drive(float ime){
  Drivetrain.drive(forward);
  vex::task::sleep(ime);
  Drivetrain.stop();
}
void ReverseDrive(float ime){
  Drivetrain.drive(reverse);
  vex::task::sleep(ime);
  Drivetrain.stop();
}
void TurnLeft(float ime){
  Drivetrain.turn(left);
  vex::task::sleep(ime);
  Drivetrain.stop();
}
void TurnRight(float ime){
  Drivetrain.turn(right);
  vex::task::sleep(ime);
  Drivetrain.stop();
}

void Record() {
  int move=0;
  int oldmove=0;
  int moveLength=0;
  printf("\n\n\n\n\n");
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
    while(Controller1.ButtonUp.pressing()+Controller1.ButtonRight.pressing()+Controller1.ButtonDown.pressing()+Controller1.ButtonLeft.pressing()!=1){
      vex::task::sleep(10);      
    }
    if(Controller1.ButtonUp.pressing()){
      move=1;
    }
    else if(Controller1.ButtonRight.pressing()){
      move=2;
    }
    else if(Controller1.ButtonDown.pressing()){
      move=3;
    }
    else if(Controller1.ButtonLeft.pressing()){
      move=4;
    }

    if(move==1 && oldmove==1){
      moveLength+=1000;
      Drive(1000);
    }
    if(move!=1 && oldmove==1){
      printf("Drive(%i);\n",moveLength);
      moveLength=0;
    }
    if(move==3 && oldmove==3){
      moveLength+=1000;
      ReverseDrive(1000);
    }
    if(move!=3 && oldmove==3){
      printf("ReverseDrive(%i);\n",moveLength);
      moveLength=0;
    }


    if(move==2 && oldmove==2){
      moveLength+=turnspeedthing;
      TurnRight(turnspeedthing);
    }
    if(move!=2 && oldmove==2){
      printf("TurnRight(%i);\n",moveLength);
      moveLength=turnspeedthing;
    }
    if(move==4 && oldmove==4){
      moveLength+=turnspeedthing;
      TurnLeft(turnspeedthing);
    }
    if(move!=4 && oldmove==4){
      printf("TurnLeft(%i);\n",moveLength);
      moveLength=0;
    }

    
    //printf("Move is set to %i and Oldmove is set to %i \n",move,oldmove);
    oldmove=move;
    vex::task::sleep(100); 
  }
}

