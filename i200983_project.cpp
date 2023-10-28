/* 	Fahad Kamran
	CS-B
	i200983
	Semester 1 PF Project*/



//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================
//Fahad Kamran
//20I-0983
//CS-B
//FIRST YEAR PROJECT
#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
//#include <windows.h>      //include this header file to use Sleep( ) function
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt, etc
using namespace std;
//declaration of variables
int PlayerCount=0, choice=0, turn=0, counter=0, currentturn=0;
int blue[4][2], bpos[4], red[4][2], rpos[4],yellow[4][2],ypos[4],green[4][2],gpos[4], choicesCheck[4], dicenumber;
string player[4], playerColour[4];
bool takenColour[4], rkill[4], bkill[4], ykill[4], gkill[4], bwin=false, rwin=false, ywin=false, gwin=false;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
//function for checking is a colour has won
void win(){
if (bwin==false){
	if ((bpos[0]==57)&&(bpos[1]==57)&&(bpos[2]==57)&&(bpos[3]==57)){
	bwin=true;}}
if (rwin==false){
	if ((rpos[0]==57)&&(rpos[1]==57)&&(rpos[2]==57)&&(rpos[3]==57)){
	rwin=true;}}
if (gwin==false){
	if ((gpos[0]==57)&&(gpos[1]==57)&&(gpos[2]==57)&&(gpos[3]==57)){
	gwin=true;}}	
if (ywin==false){
	if ((ypos[0]==57)&&(ypos[1]==57)&&(ypos[2]==57)&&(ypos[3]==57)){
	ywin=true;}}
if(bwin==true){
	DrawString( 1200, 400, "BLUE HAS WON", colors[MISTY_ROSE]);
	}
if(rwin==true){
	DrawString( 1200, 300, "RED HAS WON", colors[MISTY_ROSE]);
	}
if(gwin==true){
	DrawString( 1200, 200, "GREEN HAS WON", colors[MISTY_ROSE]);
	}
if(ywin==true){
	DrawString( 1200, 100, "YELLOW HAS WON", colors[MISTY_ROSE]);
	}

}

void Turns(){
//calculating whose turn it is and displaying message accordingly
	currentturn=turn%PlayerCount;
	if ((currentturn)==1){
		DrawString( 1200, 1000, "It is", colors[MISTY_ROSE]);
		DrawString( 1300, 1000, player[0], colors[MISTY_ROSE]);
		DrawString( 1350, 1000, "'s turn", colors[MISTY_ROSE]);
		DrawString( 1200, 950, playerColour[0], colors[MISTY_ROSE]);
		DrawString( 1200, 900, "Press Spacebar to roll dice", colors[MISTY_ROSE]);}
	if ((currentturn)==2){
		DrawString( 1200, 1000, "It is", colors[MISTY_ROSE]);
		DrawString( 1300, 1000, player[1], colors[MISTY_ROSE]);
		DrawString( 1350, 1000, "'s turn", colors[MISTY_ROSE]);
		DrawString( 1200, 950, playerColour[0], colors[MISTY_ROSE]);
		DrawString( 1200, 900, "Press Spacebar to roll dice", colors[MISTY_ROSE]);}
	if ((currentturn)==3){
		DrawString( 1200, 1000, "It is", colors[MISTY_ROSE]);
		DrawString( 1300, 1000, player[2], colors[MISTY_ROSE]);
		DrawString( 1350, 1000, "'s turn", colors[MISTY_ROSE]);
		DrawString( 1200, 950, playerColour[0], colors[MISTY_ROSE]);
		DrawString( 1200, 900, "Press Spacebar to roll dice", colors[MISTY_ROSE]);}
	if ((currentturn)==0){
		DrawString( 1200, 1000, "It is", colors[MISTY_ROSE]);
		DrawString( 1300, 1000, player[3], colors[MISTY_ROSE]);
		DrawString( 1350, 1000, "'s turn", colors[MISTY_ROSE]);
		DrawString( 1200, 950, playerColour[0], colors[MISTY_ROSE]);
		DrawString( 1200, 900, "Press Spacebar to roll dice", colors[MISTY_ROSE]);}	
	}
	
void Movement(){
//display geeti key detail based on turn
if (dicenumber>0){
		if (playerColour[currentturn]=="RED"){
			DrawString( 1200, 800, "Press A to move 1st Geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 700, "Press B to move 2nd Geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 600, "Press C to move 3rd Geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 500, "Press D to move 4th Geeti", colors[MISTY_ROSE]);}
		else if (playerColour[currentturn]=="BLUE"){
			DrawString( 1200, 800, "Press F to move 1st Geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 700, "Press G to move 2nd Geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 600, "Press H to move 3rd geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 500, "Press I to move 4th geeti", colors[MISTY_ROSE]);}
		else if (playerColour[currentturn]=="GREEN"){
			DrawString( 1200, 800, "Press M to move 1st geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 700, "Press N to move 2nd geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 600, "Press O to move 3rd geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 500, "Press P to move 4th geeti", colors[MISTY_ROSE]);}
		else if (playerColour[currentturn]=="YELLOW"){
			DrawString( 1200, 800, "Press Q to move 1st geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 700, "Press R to move 2nd geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 600, "Press S to move 3rd geeti", colors[MISTY_ROSE]);
			DrawString( 1200, 500, "Press T to move 4th geeti", colors[MISTY_ROSE]);}
	 
}	
}
//function for user initial input
void InitialInput(){
//asking user for number of players
	cout<<"Enter Number Of Players Between 2 And 4 : "<<endl;
	cin>>PlayerCount;
	//checking for correct input
	while (PlayerCount<=1 || PlayerCount > 4){
		cout<<"INVALID INPUT : There Can Only be 2, 3 or 4 Number of Players."<<endl;
		cout<<"Please Enter Again"<<endl;
		cin>>PlayerCount;
	}
	//asking user to enter detail for playing for each player: name and colour choice
	for (int i=0;i<PlayerCount;i++){
		cout<<"Enter The Name Of Player Number "<<(i+1)<<endl;
		cin>>player[i];
		cout<<"From the options below, Choose color number for Player "<<(i+1)<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		//condition to show colour it not taken
		if (takenColour[0]==false){
		cout<<"Press 1 for Red"<<endl;}
		if (takenColour[1]==false){
		cout<<"Press 2 for Blue"<<endl;}
		if (takenColour[2]==false){
		cout<<"Press 3 for Green"<<endl;}
		if (takenColour[3]==false){
		cout<<"Press 4 for Yellow"<<endl;}
		cin>>choice;
		//checking if colour entry is valid or invalid 
		while (choice<1 || choice==choicesCheck[0] || choice==choicesCheck[1] || choice==choicesCheck[2] || choice==choicesCheck[3] || choice>4){
			cout<<"Your Entry was invalid, Please Enter choice again"<<endl;
			cin>>choice;
		}
		//if colour get picked by a certain player then the colour is selected for that player and next player entry will not get choice of that colour
		if (choice==1){
			takenColour[0]=true;
			playerColour[i]="RED";}
		else if (choice==2){
			takenColour[1]=true;
			playerColour[i]="BLUE";}
		else if (choice==3){
			takenColour[2]=true;
			playerColour[i]="GREEN";}
		else if (choice==4){
			takenColour[3]=true;
			playerColour[i]="YELLOW";}
		if (takenColour[0]==true){
			choicesCheck[0]=1;}
		if (takenColour[1]==true){
			choicesCheck[1]=2;}
		if (takenColour[2]==true){
			choicesCheck[2]=3;}	
		if (takenColour[3]==true){
			choicesCheck[3]=4;}
	}
}

//function to display dice dots based on random number using DrawRoundRect(60, 60, 70, 70,colors[MISTY_ROSE], 10);
void DiceDots(int random){
//displays number of dots on dice based on its number
	if (random==1){
		DrawCircle(95, 95, 15, colors[RED]);
	}
	else if (random==2){
		DrawCircle(80, 95, 10, colors[BLACK]);
		DrawCircle(110, 95, 10, colors[BLACK]);
	}
	else if (random==3){
		DrawCircle(80, 80, 10, colors[BLACK]);
		DrawCircle(95, 95, 10, colors[BLACK]);
		DrawCircle(110, 110, 10, colors[BLACK]);
	}
	else if (random==4){
		DrawCircle(80, 80, 10, colors[RED]);
		DrawCircle(110, 110, 10, colors[RED]);
		DrawCircle(110, 80, 10, colors[RED]);
		DrawCircle(80, 110, 10, colors[RED]);
	}
	else if (random==5){
		DrawCircle(80, 80, 10, colors[BLACK]);
		DrawCircle(110, 110, 10, colors[BLACK]);
		DrawCircle(95, 95, 10, colors[BLACK]);
		DrawCircle(110, 80, 10, colors[BLACK]);
		DrawCircle(80, 110, 10, colors[BLACK]);
	}
	else if (random==6){
		DrawCircle(80, 75, 8, colors[DARK_RED]);
		DrawCircle(80, 95, 8, colors[DARK_RED]);
		DrawCircle(80, 115, 8, colors[DARK_RED]);
		DrawCircle(110, 75, 8, colors[DARK_RED]);
		DrawCircle(110, 95, 8, colors[DARK_RED]);
		DrawCircle(110, 115, 8, colors[DARK_RED]);
	}
}
//position coordinate for blue goti
void positionBlue(int num){
num=num-1;
//assigning coordinates for each position according to the colour of the function
{if (num==0){

	if (bpos[num]==0){

		blue[0][0]=267.5;
		blue[0][1]=712.5;}
	}
else if (num==1){
	if(bpos[num]==0){
		blue[1][0]=367.5;
		blue[1][1]=712.5;}
		}
else if (num==2){
	if(bpos[num]==0){		
		blue[2][0]=267.5;
		blue[2][1]=812.5;}
		}
	
else if(num==3){
	if(bpos[num]==0){		
		blue[3][0]=367.5;
		blue[3][1]=812.5;}
		}}
	{if(bpos[num]==1){
		blue[num][0]=230;
		blue[num][1]=560;}
	else if(bpos[num]==2){
		blue[num][0]=280;
		blue[num][1]=560;}
	else if(bpos[num]==3){
		blue[num][0]=330;
		blue[num][1]=560;}
	else if(bpos[num]==4){
		blue[num][0]=380;
		blue[num][1]=560;}
	else if(bpos[num]==5){
		blue[num][0]=430;
		blue[num][1]=560;}
	else if(bpos[num]==6){
		blue[num][0]=520;
		blue[num][1]=650;}
	else if(bpos[num]==7){
		blue[num][0]=520;
		blue[num][1]=700;}
	else if(bpos[num]==8){
		blue[num][0]=520;
		blue[num][1]=750;}
	else if(bpos[num]==9){
		blue[num][0]=520;
		blue[num][1]=800;}
	else if(bpos[num]==10){
		blue[num][0]=520;
		blue[num][1]=850;}
	else if(bpos[num]==11){
		blue[num][0]=520;
		blue[num][1]=900;}
	else if(bpos[num]==12){
		blue[num][0]=590;
		blue[num][1]=900;}
	else if(bpos[num]==13){
		blue[num][0]=660;
		blue[num][1]=900;}
	else if(bpos[num]==14){
		blue[num][0]=660;
		blue[num][1]=850;}
	else if(bpos[num]==15){
		blue[num][0]=660;
		blue[num][1]=800;}
	else if(bpos[num]==16){
		blue[num][0]=660;
		blue[num][1]=750;}
	else if(bpos[num]==17){
		blue[num][0]=660;
		blue[num][1]=700;}
	else if(bpos[num]==18){
		blue[num][0]=660;
		blue[num][1]=650;}
	else if(bpos[num]==19){
		blue[num][0]=750;
		blue[num][1]=560;}
	else if(bpos[num]==20){
		blue[num][0]=800;
		blue[num][1]=560;}
	else if(bpos[num]==21){
		blue[num][0]=850;
		blue[num][1]=560;}
	else if(bpos[num]==22){
		blue[num][0]=900;
		blue[num][1]=560;}
	else if(bpos[num]==23){
		blue[num][0]=950;
		blue[num][1]=560;}
	else if(bpos[num]==24){
		blue[num][0]=1000;
		blue[num][1]=560;}
	else if(bpos[num]==25){
		blue[num][0]=1000;
		blue[num][1]=490;}
	else if(bpos[num]==26){
		blue[num][0]=1000;
		blue[num][1]=420;}
	else if(bpos[num]==27){
		blue[num][0]=950;
		blue[num][1]=420;}
	else if(bpos[num]==28){
		blue[num][0]=900;
		blue[num][1]=420;}
	else if(bpos[num]==29){
		blue[num][0]=850;
		blue[num][1]=420;}
	else if(bpos[num]==30){
		blue[num][0]=800;
		blue[num][1]=420;}
	else if(bpos[num]==31){
		blue[num][0]=750;
		blue[num][1]=420;}
	else if(bpos[num]==32){
		blue[num][0]=660;
		blue[num][1]=330;}
	else if(bpos[num]==33){
		blue[num][0]=660;
		blue[num][1]=280;}
	else if(bpos[num]==34){
		blue[num][0]=660;
		blue[num][1]=230;}
	else if(bpos[num]==35){
		blue[num][0]=660;
		blue[num][1]=180;}
	else if(bpos[num]==36){
		blue[num][0]=660;
		blue[num][1]=130;}
	else if(bpos[num]==37){
		blue[num][0]=660;
		blue[num][1]=80;}
	else if(bpos[num]==38){
		blue[num][0]=590;
		blue[num][1]=80;}
	else if(bpos[num]==39){
		blue[num][0]=520;
		blue[num][1]=80;}
	else if(bpos[num]==40){
		blue[num][0]=520;
		blue[num][1]=130;}
	else if(bpos[num]==41){
		blue[num][0]=520;
		blue[num][1]=180;}
	else if(bpos[num]==42){
		blue[num][0]=520;
		blue[num][1]=230;}
	else if(bpos[num]==43){
		blue[num][0]=520;
		blue[num][1]=280;}
	else if(bpos[num]==44){
		blue[num][0]=520;
		blue[num][1]=330;}
	else if(bpos[num]==45){
		blue[num][0]=430;
		blue[num][1]=420;}
	else if(bpos[num]==46){
		blue[num][0]=380;
		blue[num][1]=420;}
	else if(bpos[num]==47){
		blue[num][0]=330;
		blue[num][1]=420;}
	else if(bpos[num]==48){
		blue[num][0]=280;
		blue[num][1]=420;}
	else if(bpos[num]==49){
		blue[num][0]=230;
		blue[num][1]=420;}
	else if(bpos[num]==50){
		blue[num][0]=180;
		blue[num][1]=420;}
	else if(bpos[num]==51){
		blue[num][0]=180;
		blue[num][1]=490;}
	else if(bpos[num]==52 && bkill[num]==false){
		blue[num][0]=180;
		blue[num][1]=660;}
	else if(bpos[num]==52 && bkill[num]==true){
		blue[num][0]=230;
		blue[num][1]=490;}
	else if(bpos[num]==53){
		blue[num][0]=280;
		blue[num][1]=490;}
	else if(bpos[num]==54){
		blue[num][0]=330;
		blue[num][1]=490;}
	else if(bpos[num]==55){
		blue[num][0]=380;
		blue[num][1]=490;}
	else if(bpos[num]==56){
		blue[num][0]=430;
		blue[num][1]=490;}
	else if(bpos[num]==57){
		blue[num][0]=520;
		blue[num][1]=490;}
	
		}
		
		
}		
//position coordinate for yellow goti
void positionYellow(int num){
num=num-1;
//assigning coordinates for each position according to the colour of the function
{if (num==0){

	if (ypos[num]==0){
		yellow[0][0]=807.5;
		yellow[0][1]=712.5;}
	}
else if (num==1){
	if(ypos[num]==0){
		yellow[1][0]=907.5;
		yellow[1][1]=712.5;}
		}
else if (num==2){
	if(ypos[num]==0){		
		yellow[2][0]=807.5;
		yellow[2][1]=812.5;}
		}
	
else if(num==3){
	if(ypos[num]==0){		
		yellow[3][0]=907.5;
		yellow[3][1]=812.5;}
		}
	}
	{if(ypos[num]==1){
		yellow[num][0]=660;
		yellow[num][1]=850;}
	else if(ypos[num]==2){
		yellow[num][0]=660;
		yellow[num][1]=800;}
	else if(ypos[num]==3){
		yellow[num][0]=660;
		yellow[num][1]=750;}
	else if(ypos[num]==4){
		yellow[num][0]=660;
		yellow[num][1]=700;}
	else if(ypos[num]==5){
		yellow[num][0]=660;
		yellow[num][1]=650;}
	else if(ypos[num]==6){
		yellow[num][0]=750;
		yellow[num][1]=560;}
	else if(ypos[num]==7){
		yellow[num][0]=800;
		yellow[num][1]=560;}
	else if(ypos[num]==8){
		yellow[num][0]=850;
		yellow[num][1]=560;}
	else if(ypos[num]==9){
		yellow[num][0]=900;
		yellow[num][1]=560;}
	else if(ypos[num]==10){
		yellow[num][0]=950;
		yellow[num][1]=560;}
	else if(ypos[num]==11){
		yellow[num][0]=1000;
		yellow[num][1]=560;}
	else if(ypos[num]==12){
		yellow[num][0]=1000;
		yellow[num][1]=490;}
	else if(ypos[num]==13){
		yellow[num][0]=1000;
		yellow[num][1]=420;}
	else if(ypos[num]==14){
		yellow[num][0]=950;
		yellow[num][1]=420;}
	else if(ypos[num]==15){
		yellow[num][0]=900;
		yellow[num][1]=420;}
	else if(ypos[num]==16){
		yellow[num][0]=850;
		yellow[num][1]=420;}
	else if(ypos[num]==17){
		yellow[num][0]=800;
		yellow[num][1]=420;}
	else if(ypos[num]==18){
		yellow[num][0]=750;
		yellow[num][1]=420;}
	else if(ypos[num]==19){
		yellow[num][0]=660;
		yellow[num][1]=330;}
	else if(ypos[num]==20){
		yellow[num][0]=660;
		yellow[num][1]=280;}
	else if(ypos[num]==21){
		yellow[num][0]=660;
		yellow[num][1]=230;}
	else if(ypos[num]==22){
		yellow[num][0]=660;
		yellow[num][1]=180;}
	else if(ypos[num]==23){
		yellow[num][0]=660;
		yellow[num][1]=130;}
	else if(ypos[num]==24){
		yellow[num][0]=660;
		yellow[num][1]=80;}
	else if(ypos[num]==25){
		yellow[num][0]=590;
		yellow[num][1]=80;}
	else if(ypos[num]==26){
		yellow[num][0]=520;
		yellow[num][1]=80;}
	else if(ypos[num]==27){
		yellow[num][0]=520;
		yellow[num][1]=130;}
	else if(ypos[num]==28){
		yellow[num][0]=520;
		yellow[num][1]=180;}
	else if(ypos[num]==29){
		yellow[num][0]=520;
		yellow[num][1]=230;}
	else if(ypos[num]==30){
		yellow[num][0]=520;
		yellow[num][1]=280;}
	else if(ypos[num]==31){
		yellow[num][0]=520;
		yellow[num][1]=330;}
	else if(ypos[num]==32){
		yellow[num][0]=430;
		yellow[num][1]=420;}
	else if(ypos[num]==33){
		yellow[num][0]=380;
		yellow[num][1]=420;}
	else if(ypos[num]==34){
		yellow[num][0]=330;
		yellow[num][1]=420;}
	else if(ypos[num]==35){
		yellow[num][0]=280;
		yellow[num][1]=420;}
	else if(ypos[num]==36){
		yellow[num][0]=230;
		yellow[num][1]=420;}
	else if(ypos[num]==37){
		yellow[num][0]=180;
		yellow[num][1]=420;}
	else if(ypos[num]==38){
		yellow[num][0]=180;
		yellow[num][1]=490;}
	else if(ypos[num]==39){
		yellow[num][0]=180;
		yellow[num][1]=560;}
	else if(ypos[num]==40){
		yellow[num][0]=230;
		yellow[num][1]=560;}
	else if(ypos[num]==41){
		yellow[num][0]=280;
		yellow[num][1]=560;}
	else if(ypos[num]==42){
		yellow[num][0]=330;
		yellow[num][1]=560;}
	else if(ypos[num]==43){
		yellow[num][0]=380;
		yellow[num][1]=560;}
	else if(ypos[num]==44){
		yellow[num][0]=430;
		yellow[num][1]=560;}
	else if(ypos[num]==45){
		yellow[num][0]=520;
		yellow[num][1]=650;}
	else if(ypos[num]==46){
		yellow[num][0]=520;
		yellow[num][1]=700;}
	else if(ypos[num]==47){
		yellow[num][0]=520;
		yellow[num][1]=750;}
	else if(ypos[num]==48){
		yellow[num][0]=520;
		yellow[num][1]=800;}
	else if(ypos[num]==49){
		yellow[num][0]=520;
		yellow[num][1]=850;}
	else if(ypos[num]==50){
		yellow[num][0]=520;
		yellow[num][1]=900;}
	else if(ypos[num]==51){
		yellow[num][0]=590;
		yellow[num][1]=900;}
	else if(ypos[num]==52 && ykill[num]==false){
		yellow[num][0]=660;
		yellow[num][1]=900;}
	else if(ypos[num]==52 && ykill[num]==true){
		yellow[num][0]=590;
		yellow[num][1]=850;}
	else if(ypos[num]==53){
		yellow[num][0]=590;
		yellow[num][1]=800;}
	else if(ypos[num]==54){
		yellow[num][0]=590;
		yellow[num][1]=750;}
	else if(ypos[num]==55){
		yellow[num][0]=590;
		yellow[num][1]=700;}
	else if(ypos[num]==56){
		yellow[num][0]=590;
		yellow[num][1]=650;}
	else if(ypos[num]==57){
		yellow[num][0]=590;
		yellow[num][1]=560;}
	
		}
			
}					
//position coordinate for green goti
void positionGreen(int num){
num=num-1;
//assigning coordinates for each position according to the colour of the function
{if (num==0){

	if (gpos[num]==0){
		green[0][0]=807.5;
		green[0][1]=172.5;}
	}
else if (num==1){
	if(gpos[num]==0){
		green[1][0]=907.5;
		green[1][1]=272.5;}
		}
else if (num==2){
	if(gpos[num]==0){		
		green[2][0]=807.5;
		green[2][1]=272.5;}
		}
	
else if(num==3){
	if(gpos[num]==0){		
		green[3][0]=907.5;
		green[3][1]=172.5;}
		}
	}
	{if(gpos[num]==1){
		green[num][0]=950;
		green[num][1]=420;}
	else if(gpos[num]==2){
		green[num][0]=900;
		green[num][1]=420;}
	else if(gpos[num]==3){
		green[num][0]=850;
		green[num][1]=420;}
	else if(gpos[num]==4){
		green[num][0]=800;
		green[num][1]=420;}
	else if(gpos[num]==5){
		green[num][0]=750;
		green[num][1]=420;}
	else if(gpos[num]==6){
		green[num][0]=660;
		green[num][1]=330;}
	else if(gpos[num]==7){
		green[num][0]=660;
		green[num][1]=280;}
	else if(gpos[num]==8){
		green[num][0]=660;
		green[num][1]=230;}
	else if(gpos[num]==9){
		green[num][0]=660;
		green[num][1]=180;}
	else if(gpos[num]==10){
		green[num][0]=660;
		green[num][1]=130;}
	else if(gpos[num]==11){
		green[num][0]=660;
		green[num][1]=80;}
	else if(gpos[num]==12){
		green[num][0]=590;
		green[num][1]=80;}
	else if(gpos[num]==13){
		green[num][0]=520;
		green[num][1]=80;}
	else if(gpos[num]==14){
		green[num][0]=520;
		green[num][1]=130;}
	else if(gpos[num]==15){
		green[num][0]=520;
		green[num][1]=180;}
	else if(gpos[num]==16){
		green[num][0]=520;
		green[num][1]=230;}
	else if(gpos[num]==17){
		green[num][0]=520;
		green[num][1]=280;}
	else if(gpos[num]==18){
		green[num][0]=520;
		green[num][1]=330;}
	else if(gpos[num]==19){
		green[num][0]=430;
		green[num][1]=420;}
	else if(gpos[num]==20){
		green[num][0]=380;
		green[num][1]=420;}
	else if(gpos[num]==21){
		green[num][0]=330;
		green[num][1]=420;}
	else if(gpos[num]==22){
		green[num][0]=280;
		green[num][1]=420;}
	else if(gpos[num]==23){
		green[num][0]=230;
		green[num][1]=420;}
	else if(gpos[num]==24){
		green[num][0]=180;
		green[num][1]=420;}
	else if(gpos[num]==25){
		green[num][0]=180;
		green[num][1]=490;}
	else if(gpos[num]==26){
		green[num][0]=180;
		green[num][1]=560;}
	else if(gpos[num]==27){
		green[num][0]=230;
		green[num][1]=560;}
	else if(gpos[num]==28){
		green[num][0]=280;
		green[num][1]=560;}
	else if(gpos[num]==29){
		green[num][0]=330;
		green[num][1]=560;}
	else if(gpos[num]==30){
		green[num][0]=380;
		green[num][1]=560;}
	else if(gpos[num]==31){
		green[num][0]=430;
		green[num][1]=560;}
	else if(gpos[num]==32){
		green[num][0]=520;
		green[num][1]=650;}
	else if(gpos[num]==33){
		green[num][0]=520;
		green[num][1]=700;}
	else if(gpos[num]==34){
		green[num][0]=520;
		green[num][1]=750;}
	else if(gpos[num]==35){
		green[num][0]=520;
		green[num][1]=800;}
	else if(gpos[num]==36){
		green[num][0]=520;
		green[num][1]=850;}
	else if(gpos[num]==37){
		green[num][0]=520;
		green[num][1]=900;}
	else if(gpos[num]==38){
		green[num][0]=590;
		green[num][1]=900;}
	else if(gpos[num]==39){
		green[num][0]=660;
		green[num][1]=900;}
	else if(gpos[num]==40){
		green[num][0]=660;
		green[num][1]=850;}
	else if(gpos[num]==41){
		green[num][0]=660;
		green[num][1]=800;}
	else if(gpos[num]==42){
		green[num][0]=660;
		green[num][1]=750;}
	else if(gpos[num]==43){
		green[num][0]=660;
		green[num][1]=700;}
	else if(gpos[num]==44){
		green[num][0]=660;
		green[num][1]=650;}
	else if(gpos[num]==45){
		green[num][0]=750;
		green[num][1]=560;}
	else if(gpos[num]==46){
		green[num][0]=800;
		green[num][1]=560;}
	else if(gpos[num]==47){
		green[num][0]=850;
		green[num][1]=560;}
	else if(gpos[num]==48){
		green[num][0]=900;
		green[num][1]=560;}
	else if(gpos[num]==49){
		green[num][0]=950;
		green[num][1]=560;}
	else if(gpos[num]==50){
		green[num][0]=1000;
		green[num][1]=560;}
	else if(gpos[num]==51){
		green[num][0]=1000;
		green[num][1]=490;}
	else if(gpos[num]==52 && gkill[num]==false){
		green[num][0]=1000;
		green[num][1]=420;}
	else if(gpos[num]==52 && gkill[num]==true){
		green[num][0]=950;
		green[num][1]=490;}
	else if(gpos[num]==53){
		green[num][0]=900;
		green[num][1]=490;}
	else if(gpos[num]==54){
		green[num][0]=850;
		green[num][1]=490;}
	else if(gpos[num]==55){
		green[num][0]=800;
		green[num][1]=490;}
	else if(gpos[num]==56){
		green[num][0]=750;
		green[num][1]=490;}
	else if(gpos[num]==57){
		green[num][0]=660;
		green[num][1]=490;}
	
		}
}

					
//position coordinate for green goti
void positionRed(int num){
num=num-1;
//assigning coordinates for each position according to the colour of the function
{if (num==0){

	if (rpos[num]==0){
		red[0][0]=267.5;
		red[0][1]=172.5;}
	}
else if (num==1){
	if(rpos[num]==0){
		red[1][0]=367.5;
		red[1][1]=272.5;}
		}
else if (num==2){
	if(rpos[num]==0){		
		red[2][0]=267.5;
		red[2][1]=272.5;}
		}
	
else if(num==3){
	if(rpos[num]==0){		
		red[3][0]=367.5;
		red[3][1]=172.5;}
		}
	}
	{if(rpos[num]==1){
		red[num][0]=520;
		red[num][1]=130;}
	else if(rpos[num]==2){
		red[num][0]=520;
		red[num][1]=180;}
	else if(rpos[num]==3){
		red[num][0]=520;
		red[num][1]=230;}
	else if(rpos[num]==4){
		red[num][0]=520;
		red[num][1]=280;}
	else if(rpos[num]==5){
		red[num][0]=520;
		red[num][1]=330;}
	else if(rpos[num]==6){
		red[num][0]=430;
		red[num][1]=420;}
	else if(rpos[num]==7){
		red[num][0]=380;
		red[num][1]=420;}
	else if(rpos[num]==8){
		red[num][0]=330;
		red[num][1]=420;}
	else if(rpos[num]==9){
		red[num][0]=280;
		red[num][1]=420;}
	else if(rpos[num]==10){
		red[num][0]=230;
		red[num][1]=420;}
	else if(rpos[num]==11){
		red[num][0]=180;
		red[num][1]=420;}
	else if(rpos[num]==12){
		red[num][0]=180;
		red[num][1]=490;}
	else if(rpos[num]==13){
		red[num][0]=180;
		red[num][1]=560;}
	else if(rpos[num]==14){
		red[num][0]=230;
		red[num][1]=560;}
	else if(rpos[num]==15){
		red[num][0]=280;
		red[num][1]=560;}
	else if(rpos[num]==16){
		red[num][0]=330;
		red[num][1]=560;}
	else if(rpos[num]==17){
		red[num][0]=380;
		red[num][1]=560;}
	else if(rpos[num]==18){
		red[num][0]=430;
		red[num][1]=560;}
	else if(rpos[num]==19){
		red[num][0]=520;
		red[num][1]=650;}
	else if(rpos[num]==20){
		red[num][0]=520;
		red[num][1]=700;}
	else if(rpos[num]==21){
		red[num][0]=520;
		red[num][1]=750;}
	else if(rpos[num]==22){
		red[num][0]=520;
		red[num][1]=800;}
	else if(rpos[num]==23){
		red[num][0]=520;
		red[num][1]=850;}
	else if(rpos[num]==24){
		red[num][0]=520;
		red[num][1]=900;}
	else if(rpos[num]==25){
		red[num][0]=590;
		red[num][1]=900;}
	else if(rpos[num]==26){
		red[num][0]=660;
		red[num][1]=900;}
	else if(rpos[num]==27){
		red[num][0]=660;
		red[num][1]=850;}
	else if(rpos[num]==28){
		red[num][0]=660;
		red[num][1]=800;}
	else if(rpos[num]==29){
		red[num][0]=660;
		red[num][1]=750;}
	else if(rpos[num]==30){
		red[num][0]=660;
		red[num][1]=700;}
	else if(rpos[num]==31){
		red[num][0]=660;
		red[num][1]=650;}
	else if(rpos[num]==32){
		red[num][0]=750;
		red[num][1]=560;}
	else if(rpos[num]==33){
		red[num][0]=800;
		red[num][1]=560;}
	else if(rpos[num]==34){
		red[num][0]=850;
		red[num][1]=560;}
	else if(rpos[num]==35){
		red[num][0]=900;
		red[num][1]=560;}
	else if(rpos[num]==36){
		red[num][0]=950;
		red[num][1]=560;}
	else if(rpos[num]==37){
		red[num][0]=1000;
		red[num][1]=560;}
	else if(rpos[num]==38){
		red[num][0]=1000;
		red[num][1]=490;}
	else if(rpos[num]==39){
		red[num][0]=1000;
		red[num][1]=420;}
	else if(rpos[num]==40){
		red[num][0]=950;
		red[num][1]=420;}
	else if(rpos[num]==41){
		red[num][0]=900;
		red[num][1]=420;}
	else if(rpos[num]==42){
		red[num][0]=850;
		red[num][1]=420;}
	else if(rpos[num]==43){
		red[num][0]=800;
		red[num][1]=420;}
	else if(rpos[num]==44){
		red[num][0]=750;
		red[num][1]=420;}
	else if(rpos[num]==45){
		red[num][0]=660;
		red[num][1]=330;}
	else if(rpos[num]==46){
		red[num][0]=660;
		red[num][1]=280;}
	else if(rpos[num]==47){
		red[num][0]=660;
		red[num][1]=230;}
	else if(rpos[num]==48){
		red[num][0]=660;
		red[num][1]=180;}
	else if(rpos[num]==49){
		red[num][0]=660;
		red[num][1]=130;}
	else if(rpos[num]==50){
		red[num][0]=660;
		red[num][1]=80;}
	else if(rpos[num]==51){
		red[num][0]=590;
		red[num][1]=80;}
	else if(rpos[num]==52 && rkill[num]==false){
		red[num][0]=520;
		red[num][1]=80;}
	else if(rpos[num]==52 && rkill[num]==true){
		red[num][0]=590;
		red[num][1]=130;}
	else if(rpos[num]==53){
		red[num][0]=590;
		red[num][1]=180;}
	else if(rpos[num]==54){
		red[num][0]=590;
		red[num][1]=230;}
	else if(rpos[num]==55){
		red[num][0]=590;
		red[num][1]=280;}
	else if(rpos[num]==56){
		red[num][0]=590;
		red[num][1]=330;}
	else if(rpos[num]==57){
		red[num][0]=590;
		red[num][1]=420;}
	
		}
	
}

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//side boxes
	DrawSquare( 160 , 60 ,320,colors[DARK_RED]); 
	DrawSquare( 700 , 60 ,320,colors[DARK_GREEN]);
	DrawSquare( 700 , 600 ,320,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 160 , 600 ,320,colors[LIGHT_SKY_BLUE]);
	//inside these boxes
	DrawSquare( 190 , 90 ,260,colors[INDIAN_RED]); 
	DrawSquare( 730 , 90 ,260,colors[LIGHT_GREEN]); 
	DrawSquare( 730 , 630 ,260,colors[MISTY_ROSE]); 
	DrawSquare( 190 , 630 ,260,colors[DEEP_SKY_BLUE]); 
	//goti boxes red
	DrawSquare( 245 , 150 ,45,colors[DARK_RED]);
	DrawSquare( 345 , 150 ,45,colors[DARK_RED]);
	DrawSquare( 245 , 250 ,45,colors[DARK_RED]);
	DrawSquare( 345 , 250 ,45,colors[DARK_RED]);
	//goti boxes blue
	DrawSquare( 245 , 690 ,45,colors[LIGHT_SKY_BLUE]);
	DrawSquare( 345 , 690 ,45,colors[LIGHT_SKY_BLUE]);
	DrawSquare( 245 , 790 ,45,colors[LIGHT_SKY_BLUE]);
	DrawSquare( 345 , 790 ,45,colors[LIGHT_SKY_BLUE]);
	//goti boxes yellow
	DrawSquare( 785 , 690 ,45,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 885 , 690 ,45,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 785 , 790 ,45,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 885 , 790 ,45,colors[DARK_GOLDEN_ROD]);
	//goti boxes green
	DrawSquare( 785 , 150 ,45,colors[DARK_GREEN]);
	DrawSquare( 885 , 150 ,45,colors[DARK_GREEN]);
	DrawSquare( 785 , 250 ,45,colors[DARK_GREEN]);
	DrawSquare( 885 , 250 ,45,colors[DARK_GREEN]);
	//small boxes red
	DrawSquare( 500 , 60 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 60 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 640 , 60 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 110 ,40,colors[DARK_RED]); 
	DrawSquare( 570 , 110 ,40,colors[DARK_RED]); 
	DrawSquare( 640 , 110 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 160 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 160 ,40,colors[DARK_RED]); 
	DrawSquare( 640 , 160 ,40,colors[SLATE_GRAY]); 
	
	DrawSquare( 500 , 210 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 210 ,40,colors[DARK_RED]); 
	DrawSquare( 640 , 210 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 260 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 260 ,40,colors[DARK_RED]); 
	DrawSquare( 640 , 260 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 310 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 310 ,40,colors[DARK_RED]); 
	DrawSquare( 640 , 310 ,40,colors[MISTY_ROSE]); 
	//small boxes yellow
	DrawSquare( 500 , 630 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 630 ,40,colors[DARK_GOLDEN_ROD]); 
	DrawSquare( 640 , 630 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 680 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 680 ,40,colors[DARK_GOLDEN_ROD]); 
	DrawSquare( 640 , 680 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 730 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 730 ,40,colors[DARK_GOLDEN_ROD]); 
	DrawSquare( 640 , 730 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 780 ,40,colors[SLATE_GRAY]); 
	DrawSquare( 570 , 780 ,40,colors[DARK_GOLDEN_ROD]); 
	DrawSquare( 640 , 780 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 500 , 830 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 830 ,40,colors[DARK_GOLDEN_ROD]); 
	DrawSquare( 640 , 830 ,40,colors[DARK_GOLDEN_ROD]); 
	
	DrawSquare( 500 , 880 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 570 , 880 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 640 , 880 ,40,colors[MISTY_ROSE]); 
	//small boxes blue
	DrawSquare( 160 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 160 , 470 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 160 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 210 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 210 , 470 ,40,colors[LIGHT_SKY_BLUE]); 
	DrawSquare( 210 , 540 ,40,colors[LIGHT_SKY_BLUE]); 
	
	DrawSquare( 260 , 400 ,40,colors[SLATE_GRAY]); 
	DrawSquare( 260 , 470 ,40,colors[LIGHT_SKY_BLUE]); 
	DrawSquare( 260 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 310 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 310 , 470 ,40,colors[LIGHT_SKY_BLUE]); 
	DrawSquare( 310 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 360 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 360 , 470 ,40,colors[LIGHT_SKY_BLUE]); 
	DrawSquare( 360 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 410 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 410 , 470 ,40,colors[LIGHT_SKY_BLUE]); 
	DrawSquare( 410 , 540 ,40,colors[MISTY_ROSE]); 
	//small boxes green
	DrawSquare( 730 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 730 , 470 ,40,colors[DARK_GREEN]); 
	DrawSquare( 730 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 780 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 780 , 470 ,40,colors[DARK_GREEN]); 
	DrawSquare( 780 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 830 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 830 , 470 ,40,colors[DARK_GREEN]); 
	DrawSquare( 830 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 880 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 880 , 470 ,40,colors[DARK_GREEN]); 
	DrawSquare( 880 , 540 ,40,colors[SLATE_GRAY]); 
	
	DrawSquare( 930 , 400 ,40,colors[DARK_GREEN]); 
	DrawSquare( 930 , 470 ,40,colors[DARK_GREEN]); 
	DrawSquare( 930 , 540 ,40,colors[MISTY_ROSE]); 
	
	DrawSquare( 980 , 400 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 980 , 470 ,40,colors[MISTY_ROSE]); 
	DrawSquare( 980 , 540 ,40,colors[MISTY_ROSE]);
	
	//display dice
	DrawRoundRect(60, 60, 70, 70,colors[MISTY_ROSE], 10);
	DiceDots(dicenumber);
	
	//Display Score
	DrawString( 20, 1000, "Score=", colors[MISTY_ROSE]);
	//Spider
	DrawTriangle( 485, 380 , 590, 470 , 695 , 380, colors[DARK_RED] ); 
	DrawTriangle( 485, 600 , 590, 510 , 695 , 600, colors[DARK_GOLDEN_ROD] ); 
	DrawTriangle( 480, 385 , 570, 490 , 480 , 595, colors[LIGHT_SKY_BLUE] ); 
	DrawTriangle( 700, 385 , 610, 490 , 700 , 595, colors[DARK_GREEN] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
//center at (590,490)

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 150 , 50 ,  1030 , 50 , 10 , colors[MISTY_ROSE] );	
	DrawLine( 150 , 50 ,  150 , 930 , 10 , colors[MISTY_ROSE] );	
	DrawLine( 1030 , 50 ,  1030 , 930 , 10 , colors[MISTY_ROSE] );	
	DrawLine( 150 , 930 ,  1030 , 930 , 10 , colors[MISTY_ROSE] );
	//draw borderline between board and right test diplay
	DrawLine( 1100 , 0 ,  1100 , 1080 , 10 , colors[MISTY_ROSE] );
	DrawLine( 1115 , 0 ,  1115 , 1080 , 10 , colors[MISTY_ROSE] );
	//testing position change
	
	//Draw blue gotis in base after calling functions to check coordinates incase of changes
	positionBlue(1);
	positionBlue(2);
	positionBlue(3);
	positionBlue(4);
	DrawCircle(blue[0][0],blue[0][1],20,colors[BLUE]);
	DrawCircle(blue[1][0],blue[1][1],20,colors[BLUE]);
	DrawCircle(blue[2][0],blue[2][1],20,colors[BLUE]);
	DrawCircle(blue[3][0],blue[3][1],20,colors[BLUE]);
	//Draw red gotis in base after calling function to check coordinates incase of changes
	positionRed(1);
	positionRed(2);
	positionRed(3);
	positionRed(4);
	DrawCircle(red[0][0],red[0][1],20,colors[RED]);
	DrawCircle(red[1][0],red[1][1],20,colors[RED]);
	DrawCircle(red[2][0],red[2][1],20,colors[RED]);
	DrawCircle(red[3][0],red[3][1],20,colors[RED]);
	//Draw yellow gotis in base after calling function to check coordinates incase of changes
	positionYellow(1);
	positionYellow(2);
	positionYellow(3);
	positionYellow(4);
	DrawCircle(yellow[0][0],yellow[0][1],20,colors[KHAKI]);
	DrawCircle(yellow[1][0],yellow[1][1],20,colors[KHAKI]);
	DrawCircle(yellow[2][0],yellow[2][1],20,colors[KHAKI]);
	DrawCircle(yellow[3][0],yellow[3][1],20,colors[KHAKI]);
	//Draw green gotis in base after calling function to check coordinates incase of changes
	positionGreen(1);
	positionGreen(2);
	positionGreen(3);
	positionGreen(4);
	DrawCircle(green[0][0],green[0][1],20,colors[FOREST_GREEN]);
	DrawCircle(green[1][0],green[1][1],20,colors[FOREST_GREEN]);
	DrawCircle(green[2][0],green[2][1],20,colors[FOREST_GREEN]);
	DrawCircle(green[3][0],green[3][1],20,colors[FOREST_GREEN]);
	
	//call function to check and display whose turn it is
	Turns();	
	//telling user which key to press to move a particular geeti
	Movement();
	//display win when a colour has won
	win();		
		
	glutSwapBuffers(); // do not modify this line..
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}
	
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}


 //rules for red geeti keys
void rulesRed(int number){
bool movepiece=true;
int counter2;
//loop for checking geeti kill conditions
	for(counter2=0;counter2<4;counter2++){
		if ((rpos[number]==gpos[counter2]+12)&&(rpos[number]!=0)&&(rpos[number]!=57)&&(rpos[number]!=56)&&(rpos[number]!=55)&&(rpos[number]!=54)&&(rpos[number]!=53)&&(rpos[number]!=52)){
			rkill[number]=true;
			gpos[counter2]=0;}
		if ((rpos[number]==bpos[counter2]+12)&&(rpos[number]!=0)&&(rpos[number]!=57)&&(rpos[number]!=56)&&(rpos[number]!=55)&&(rpos[number]!=54)&&(rpos[number]!=53)&&(rpos[number]!=52)){
			rkill[number]=true;
			bpos[counter2]=0;}
		if ((rpos[number]==ypos[counter2]+12)&&(rpos[number]!=0)&&(rpos[number]!=57)&&(rpos[number]!=56)&&(rpos[number]!=55)&&(rpos[number]!=54)&&(rpos[number]!=53)&&(rpos[number]!=52)){
			rkill[number]=true;
			ypos[counter2]=0;}
	}
	//condition for removing geeti form home
	if ((rpos[number]==0) && (dicenumber!=6)){
		movepiece=false;}
	if ((rpos[number]==0) && (dicenumber==6)){
		rpos[number]=1;
		movepiece=false;}
		//condition for geeeti to move into winning coloum if made a kill
	if (((57-rpos[number])<dicenumber)&&(rkill[number]==true)){
		movepiece=false;}
		//condition that checks if geeti has already won then don't move it
	if (rpos[number]==57){
		movepiece=false;}
		//condition that keeps geeti moving in circle unless it has made a kill
	if((rpos[number]+dicenumber)>52){
	if((rkill[number]==false)&&((52-rpos[0])>dicenumber)&&(movepiece==true)){
		rpos[number]=rpos[number]+dicenumber-52;
		//counter=counter+1;
		movepiece=false;
		}}
	if(movepiece==true){
		rpos[number]=rpos[number]+dicenumber;
		}
			turn++;
}
//rules for blue geeti keys
void rulesBlue(int number){
bool movepiece=true;
int counter2;
//loop to check for killing geeti conditions
	for(counter2=0;counter2<4;counter2++){
	//condition for killing green geeti
		if ((bpos[number]==gpos[counter2]+12)&&(bpos[number]!=0)&&(bpos[number]!=57)&&(bpos[number]!=56)&&(bpos[number]!=55)&&(bpos[number]!=54)&&(bpos[number]!=53)&&(bpos[number]!=52)){
			bkill[number]=true;
			gpos[counter2]=0;}
		//condition for killing red geeti
		if ((bpos[number]==rpos[counter2]+12)&&(bpos[number]!=0)&&(bpos[number]!=57)&&(bpos[number]!=56)&&(bpos[number]!=55)&&(bpos[number]!=54)&&(bpos[number]!=53)&&(bpos[number]!=52)){
			bkill[number]=true;
			rpos[counter2]=0;}
		//condition for killing yellow geeti
		if ((bpos[number]==ypos[counter2]+12)&&(bpos[number]!=0)&&(bpos[number]!=57)&&(bpos[number]!=56)&&(bpos[number]!=55)&&(bpos[number]!=54)&&(bpos[number]!=53)&&(bpos[number]!=52)){
			bkill[number]=true;
			ypos[counter2]=0;}
	}
	//condition for not removing geeti from home unless it is a 6
	if ((bpos[number]==0) && (dicenumber!=6)){
		movepiece=false;}
	if ((bpos[number]==0) && (dicenumber==6)){
		bpos[number]=1;
		movepiece=false;}
	//condition for entry into winning column
	if (((57-bpos[number])<dicenumber)&&(bkill[number]==true)){
		movepiece=false;}
	//if geeti has won then dont move it
	if (bpos[number]==57){
		movepiece=false;}
	//if geeti hasnt made a kill then keep it moving clockwise till it makes a kill
	if ((bpos[number]+dicenumber)>52){
	if((bkill[number]==false)&&((52-bpos[0])>dicenumber)&&(movepiece==true)){
		bpos[number]=bpos[number]+dicenumber-52;
		//counter=counter+1;
		movepiece=false;
		}}
	//condition that moves geeti then only if satisfying required conditions
	if(movepiece==true){
		bpos[number]=bpos[number]+dicenumber;
		}
			turn++;
}
//rules for yellow geeti keys
void rulesYellow(int number){
bool movepiece=true;
int counter2;
//loop for checking condition for killing geeti
	for(counter2=0;counter2<4;counter2++){
		if ((ypos[number]==gpos[counter2]+12)&&(ypos[number]!=0)&&(ypos[number]!=57)&&(ypos[number]!=56)&&(ypos[number]!=55)&&(ypos[number]!=54)&&(ypos[number]!=53)&&(ypos[number]!=52)){
			ykill[number]=true;
			gpos[counter2]=0;}
		if ((ypos[number]==rpos[counter2]+12)&&(ypos[number]!=0)&&(ypos[number]!=57)&&(ypos[number]!=56)&&(ypos[number]!=55)&&(ypos[number]!=54)&&(ypos[number]!=53)&&(ypos[number]!=52)){
			ykill[number]=true;
			rpos[counter2]=0;}
		if ((ypos[number]==bpos[counter2]+12)&&(ypos[number]!=0)&&(ypos[number]!=57)&&(ypos[number]!=56)&&(ypos[number]!=55)&&(ypos[number]!=54)&&(ypos[number]!=53)&&(ypos[number]!=52)){
			ykill[number]=true;
			bpos[counter2]=0;}
	}
//checking if geeti in in home, if so then it only comes out on a 6
	if ((ypos[number]==0) && (dicenumber!=6)){
		movepiece=false;}
	if ((ypos[number]==0) && (dicenumber==6)){
		ypos[number]=1;
		movepiece=false;}
//condition that only lets geeti move to winning column if it has make a kill
	if (((57-ypos[number])<dicenumber)&&(ykill[number]==true)){
		movepiece=false;}
		//condition that checks if geeti has already won then no move
	if (ypos[number]==57){
		movepiece=false;}
		//condition that if geeti hasn't made a kill then keep moving clockwise on board till it makes a kill
		if ((ypos[number]+dicenumber)>52){
	if((ykill[number]==false)&&((52-ypos[0])>diceresults[counter])&&(movepiece==false)){
		ypos[number]=ypos[number]+dicenumber-52;
		//counter=counter+1;
		movepiece=false;
		}}
	if(movepiece==true){
		ypos[number]=ypos[number]+dicenumber;
		}
			turn++;
}

//rules for green geeti keys
void rulesGreen(int number){
bool movepiece=true;
int counter2;
//condition for killing geeti
	for(counter2=0;counter2<4;counter2++){
		if ((gpos[number]==ypos[counter2]+12)&&(gpos[number]!=0)&&(gpos[number]!=57)&&(gpos[number]!=56)&&(gpos[number]!=55)&&(gpos[number]!=54)&&(gpos[number]!=53)&&(gpos[number]!=52)){
			gkill[number]=true;
			ypos[counter2]=0;}
		if ((gpos[number]==rpos[counter2]+12)&&(gpos[number]!=0)&&(gpos[number]!=57)&&(gpos[number]!=56)&&(gpos[number]!=55)&&(gpos[number]!=54)&&(gpos[number]!=53)&&(gpos[number]!=52)){
			gkill[number]=true;
			rpos[counter2]=0;}
		if ((gpos[number]==bpos[counter2]+12)&&(gpos[number]!=0)&&(gpos[number]!=57)&&(gpos[number]!=56)&&(gpos[number]!=55)&&(gpos[number]!=54)&&(gpos[number]!=53)&&(gpos[number]!=52)){
			gkill[number]=true;
			bpos[counter2]=0;}
	}
	//condition to only remove geeti from home incase of 6
	if ((gpos[number]==0) && (dicenumber!=6)){
		movepiece=false;}
	if ((gpos[number]==0) && (dicenumber==6)){
		gpos[number]=1;
		movepiece=false;}
	//condition to only let geeti enter home column of it has made a kill
	if (((57-gpos[number])<dicenumber)&&(gkill[number]==true)){
		movepiece=false;}
	//if geeti has already won then no move
	if (gpos[number]==57){
		movepiece=false;}
	//if geeti has not made kill then keep moving on board clockwise till it makes a kill
	if ((gpos[number]+dicenumber)>52){
	if((gkill[number]==false)&&((52-gpos[0])>dicenumber)&&(movepiece==false)){
		gpos[number]=gpos[number]+dicenumber-52;
		//counter=counter+1;
		movepiece=false;
		}}
	if(movepiece==true){
		gpos[number]=gpos[number]+dicenumber;
		}
			turn++;
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32/*Space Bar ASCII*/){ //Key for placing the bomb
	dicenumber= GetRandInRange(1, 7);
	//roll upto 3 times if space bar is pressed
	/*diceresults[0] = GetRandInRange(1, 7);
	if (diceresults[0]==6){
		diceresults[1]= GetRandInRange(1, 7);
		if (diceresults[1]==6){
			diceresults[2]= GetRandInRange(1, 7);
			if (diceresults[2]==6){
				for (int i=0;i<3;i++){
					diceresults[i]=0;
				}
				DrawString( 1200, 1000, "You Got 3 sixes so no move", colors[MISTY_ROSE]);
			}
		}
	}*/

	}
	
	//red
	if (key == 65 || key == 97/* letter a and A*/){
	rulesRed(0);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 66 || key == 98/*letter b and B*/){
	rulesRed(1);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 67 || key == 99/*letter c and C*/){
	rulesRed(2);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 68 || key == 100/*letter d and D*/){
	rulesRed(3);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	
	//blue
	if (key == 70 || key == 102/*letter f and F*/){
	rulesBlue(0);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 71 || key == 103/*letter g and G*/){
	rulesBlue(1);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 72 || key == 104/*letter h and H*/){
	rulesBlue(2);
	dicenumber=0;
	//diceresults[counter]=0;}
	}
	if (key == 73 || key == 105/*letter i and I*/){
	rulesBlue(3);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	
	//green
	if (key == 77 || key == 109/*letter m and M*/){
	rulesGreen(0);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 78 || key == 110/*letter n aand N*/){
	rulesGreen(1);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 79 || key == 111/*letter o and O*/){
	rulesGreen(2);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 80 || key == 112/*letter p and P*/){
	rulesGreen(3);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	
	//yellow
	if (key == 81 || key == 113/*letter q and Q*/){
	rulesYellow(0);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 82 || key == 114/*letter r and R*/){
	rulesYellow(1);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 83 || key == 115/*letter s and S*/){
	rulesYellow(2);
	dicenumber=0;
	//diceresults[counter]=0;
	}
	if (key == 84 || key == 116/*letter t and T*/){
	rulesYellow(3);
	dicenumber=0;
	//diceresults[counter]=0;
	} 
	

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	/*cout << x << " " << y << endl;
	glutPostRedisplay();*/
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	/*if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}*/
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
//initializing arrays with 0
	int i, j;
//initializing arrays
for (i=0;i<4;i++){
	for(j=0;j<4;j++){
		blue[i][j]=0;
		red[i][j]=0;
		yellow[i][j]=0;
		green[i][j]=0;
	}
	bpos[i]=0;
	rpos[i]=0;
	gpos[i]=0;
	ypos[i]=0;
	player[i]="";
	playerColour[i]="";
	takenColour[i]=false;
	choicesCheck[i]=0;
	rkill[i]=false;
	bkill[i]=false;
	ykill[i]=false;
	gkill[i]=false;
}

//calling function for inputs before game starts
InitialInput();
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1800, height = 1080; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
