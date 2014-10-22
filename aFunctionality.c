/*
 Sean Bapty
 ECE 382 T5
 22 October
 A functionality of a pong game
 Documentation:See Readme
 */

#include <msp430g2553.h>

//delayfunction__delay_cycles(160000)

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		XSTART_POSITION	3					//starting location given that
#define		YSTART_POSITION	3					//xmax is 10 and ymax is 6 based
												//on the ball size and screen size
#define		PADDLE_X		0					//paddle dimensions and starting
#define		PADDLE_Y		2					//location
#define		PADDLE_HEIGHT	1
#define		PADDLE_WIDTH	1

void main() {

	unsigned char button_press;
	char	xPos, yPos, xVelocity, yVelocity;	//location and vector of ball variables
	char	paddleX, paddleY;
	paddleX=PADDLE_X;
	paddleY=PADDLE_Y;
	xPos=XSTART_POSITION;
	yPos=YSTART_POSITION;
	xVelocity=1;
	yVelocity=1;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;

	init();
	initNokia();
	clearDisplay();

	while(1) {
/*=========================================================================
 * 								Update Ball Location
 */
		if(xPos>10){							//checks boundary conditions
			xVelocity=-xVelocity;				//in x and y respectively
		}
		if(xPos<=PADDLE_WIDTH){
			if(yPos==paddleY){
				xVelocity=-xVelocity;
			}
			else if(yPos==paddleY+PADDLE_HEIGHT){
				xVelocity=-xVelocity;
			}
			else
				endGame();
		}
		if(yPos>6){
			yVelocity=-yVelocity;
		}
		if(yPos<=0){
			yVelocity=-yVelocity;
		}

		xPos=xPos+xVelocity;					//moves ball in x and y
		yPos=yPos+yVelocity;					//8 pixels or the ball size


/*=========================================================================
 *							Update Paddle Location
 */
		if (UP_BUTTON == 0) {
			while(UP_BUTTON == 0);
			if (paddleY>=1) paddleY=paddleY-1;
			button_press = TRUE;
		} else if (DOWN_BUTTON == 0) {
			while(DOWN_BUTTON == 0);
			if (paddleY<=6) paddleY=paddleY+1;
			button_press = TRUE;
		}
/*=========================================================================
 *							Draw Screen
 */
		drawBlock(yPos,xPos);
		drawBlock(paddleY,paddleX);
		drawBlock(paddleY+PADDLE_HEIGHT,paddleX);
		__delay_cycles(1600000);				//delay of 1s
		clearDisplay();

		}
}

endGame(){
	while(1);
}

