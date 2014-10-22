/*
 Sean Bapty
 ECE 382 T5
 22 October
 Basic B functionality of a bouncing ball
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

void main() {

	char	xPos, yPos, xVelocity, yVelocity;	//location and vector variables
	xPos=XSTART_POSITION;
	yPos=YSTART_POSITION;
	xVelocity=1;
	yVelocity=1;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */


	init();
	initNokia();
	clearDisplay();

	while(1) {
		if(xPos>10){
			xVelocity=-xVelocity;
		}
		if(xPos<=0){
			xVelocity=-xVelocity;
		}
		if(yPos>6){
			yVelocity=-yVelocity;
		}
		if(yPos<=0){
			yVelocity=-yVelocity;
		}

		xPos=xPos+xVelocity;
		yPos=yPos+yVelocity;

		drawBlock(yPos,xPos);
		__delay_cycles(16000000);
		clearDisplay();

		}
}
