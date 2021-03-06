Lab4
====
##Objectives
The purpose of this lab was to combine assembly and c code to build an "etch-a-sketch-type program." 
###Required Functionality
The required functionality will allow a user to draw/erase 8x8 pixel blocks on a Nokia LCD screen. The draw/erase function will be toggled by input from the LCD's auxilary button. The following table shows the buttons on the LCD to move the block and toggle the color.

| Button    | Function                            |
|-----------|-------------------------------------|
| SW5/Up    | Move the cursor up 1 block          |
| SW4/Down  | Move the cursor down 1 block        |
| SW2/Left  | Move the cursor left 1 block        |
| SW1/Right | Move the cursor right 1 block       |
| SW3/Aux   | Toggle the color of the paint brush |

###B Functionality
B functionality will display an 8x8 block that moves a maximum of 8 pixels at a time and "bounces" each side of the screen.
###A Functionality
A Functionality is an implementation of the Pong game. Similar to B Functionality, an 8x8 block will bounce off 3 sides of the LCD and when it reaches the left-most side, the user must control a "paddle" so that the block strikes the paddle to reverse direction else the game will end.

###Bonus Functionality
The following was achieved in addition to the above.

Circle: Instead of a bouncing block, create a bouncing circular ball!

#Preliminary Design/PreLab
see Prelab section for work done prior to coding including building tables of the functions of registers and how information is passed to the Nokia LCD.

##Data Types
From the C compilers users guide the following table was filled out for various types of data.
<table style="border-collapse:collapse;border-spacing:0"><tr><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Size</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Signed/Unsigned</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Type</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Min value</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Max value</th></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">8-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned char</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">255</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">8-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">char<br></td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">-128</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">127</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">16-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned short</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">65,535</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">16-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">int</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">-32,768</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">32,767</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">32-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned long</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">4,294,967,295</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">32-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">long</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">-2,147,483,648</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">2,147,483,647</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">64-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned long long</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">18,446,744,073,709,551,615</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">64-bit</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">long long</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">-9,223,372,036,854,775,808</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">-9,223,372,036,854,775,807</td></tr></table>

Next, the following table was filled out based on various type definintion to show the obvious connection between the data type and the number of bits in the representation.

<table style="border-collapse:collapse;border-spacing:0"><tr><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:bold;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Type</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:bold;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Meaning</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:bold;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">C typedef declaration</th></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">int8</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned 8-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef unsigned char int8;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">sint8</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed 8-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef char sint8;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">int16</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned 16-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef unsigned short int16;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">sint16</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed 16-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef short sint16;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">int32</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned 32-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef unsigned long int32;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">sint32</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed 32-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef long sint32;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">int64</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">unsigned 64-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef unsigned long long int64;</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">sint64</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">signed 64-bit value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">typedef long long sint64;</td></tr></table>

##Calling/Return Convention
Based on the give code simple.c, the following values for the variables were determined.

<table style="border-collapse:collapse;border-spacing:0"><tr><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Iteration</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">a</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">b</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">c</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">d</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">e</th></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">1st</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">10</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">9</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">8</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">7</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">10</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">2nd</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">16</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">15</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">14</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">13</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">16</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">3rd</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">22</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">21</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">20</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">19</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">22</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">4th</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">28</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">27</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">26</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">25</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">28</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">5th</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">34</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">33</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">32</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">31</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">34</td></tr></table>

Next the address values/registers were determined for the function calls in simple.c.

<table style="border-collapse:collapse;border-spacing:0"><tr><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:bold;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Parameter</th><th style="font-family:Arial, sans-serif;font-size:14px;font-weight:bold;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Value Sought</th></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Starting address of func</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0xC0BA</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Ending address of func</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">0xC0C6</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Register holding w</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">R12</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Register holding x</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">R13</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Register holding y</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">R14</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Register holding z</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">R15</td></tr><tr><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">Register holding return value</td><td style="font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal">R12</td></tr></table>

##Cross language build constructs
The last part of the prelaboraty design work was to answer the following questions.

What is the role of the extern directive in a .c file? Hint: check out the external variable Wikipedia page. 

According to Wikipedia, an external variable is one that's defined outside of the function block. In CCS these are variables defined outside of main.c. It should be noted that compilers build one file at a time so when the function is being built the code has to include a "hole" for the variable specifics. This hole is then filled during linking by the variable specifics defined in the other file.

What is the role of the .global directive in an .asm file (used in lines 28-32)? Hint: reference section 2.6.2 in the MSP 430 Assembly Language Tools v4.3 User's Guide. 

The .global is the flip side of the extern directive. In the lab code the .global definition of things like the clear display are compiled independently of the code where they are used, and then put together during linking.

#Code
##Pseduo Code
No pseduo code was written to this lab because the solution was readily apparent. The C code needed to be modified so that it didn't clear the screen after the block was moved, and the drawBlock function needed to include the blocks color and change the color based on input from the button.
##Required Code
For complete implementation reference the file in this repository. The code below include the modifications to the c file needed for the required functionality.

```
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
```
...
```
	unsigned char	x, y, button_press,color; 					//added color char

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;	color = 1;
	drawBlock(y,x,color);						//added color as an input
```
...
```
else if (AUX_BUTTON == 0){
	color = -color;
	button_press = TRUE;
}
```

The assembly file Nokia.asm was also modified to handle the additional color input and act appropriatly. Below are the changes made to this file.

```
drawBlock:
	push	R5
	push	R12
	push	R13
	push	R14

	rla.w	R13					; the column address needs multiplied
	rla.w	R13					; by 8in order to convert it into a
	rla.w	R13					; pixel address.
	call	#setAddress			; move cursor to upper left corner of block

	mov		#1, R12
	cmp		#1, R14
	jnz		filled				; if the color varible (R14 holds a 1)
	jz		notFilled			; it will be filled
filled
	mov		#0xFF, R6
	jmp		draw
notFilled
	mov		#0x0,  R6
draw
	mov.w	R6, R13
	mov.w	#0x08, R5			; loop all 8 pixel columns
loopdB:
	call	#writeNokiaByte		; draw the pixels
	dec.w	R5
	jnz		loopdB

	pop		R14
	pop		R13
	pop		R12
	pop		R5

	ret							; return whence you came
```

##B Functionality Code
For B Functionality, the Nokia.asm file was restored to its original version provided by Dr. Coulston and the C code was modified from the ORIGINAL (i.e. not required version) with the following changes.
```
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
		if(xPos>10){							//checks boundary conditions
			xVelocity=-xVelocity;				//in x and y respectively
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

		xPos=xPos+xVelocity;					//moves ball in x and y
		yPos=yPos+yVelocity;					//8 pixels or the ball size

		drawBlock(yPos,xPos);
		__delay_cycles(16000000);				//delay of 1s
		clearDisplay();

		}
}
```

##A Functionality
A and B both had the original Nokia.asm file, and below is the C code for the A Functionality.
```
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
```

##Bonus Functionality
For the bonus functionality, the C code for the B functionality was used, and below is the assembly draw block function where the only modifications were made.
```
drawBlock:
	push	R5
	push	R12
	push	R13

	rla.w	R13					; the column address needs multiplied
	rla.w	R13					; by 8in order to convert it into a
	rla.w	R13					; pixel address.
	call	#setAddress			; move cursor to upper left corner of block

	mov		#1, R12
	mov		#0x3C, R6
	mov.w	R6, R13
	mov.w	#0x08, R5			; loop all 8 pixel columns
loopdB:
	call	#writeNokiaByte		; draw the pixels
	dec.w	R5
	cmp		#7, R5
	jz		secondBall
	cmp		#2, R5
	jz		secondBall
	cmp		#1, R5
	jz		firstBall
midBall:
	mov		#0xFF, R6			;draws the middle part of the ball where
	mov.w	R6, R13				;all 8 pixels are filled in
	jmp		loopdB
firstBall:
	mov		#0x3C, R6			;draws the first part of the ball where only
	mov.w	R6, R13				;the middle 4 pixels are filled
	call	#writeNokiaByte
	jmp		endBall
secondBall:
	mov		#0x7E, R6			;middle 6 pixels are filled
	mov.w	R6, R13
	jmp		loopdB
endBall:
	pop		R13
	pop		R12
	pop		R5

	ret							; return whence you came
```
#Debugging
There were no errors encountered during the building of the required functionality.
While building the B Functionality, the block was originally bouncing between 2 points rather than the whole screen. The reason for this was eventually determined to be the fact that the velocity of the ball was defined as a unsigned char. This did not allow the ball to properly change directions. This was fixed by changing the velocity type to char.
#Testing Methodology/Results
All of the functionality could be physically observed, thus it was all done by loading the program onto the MSP430 and observing the behavior displayed on the LCD. 
#Observations/Conclusions
The biggest takeaway from this lab is the different strengths/weaknesses of assembly and C programming. Assembly allows for a much greater level of control of variables, however implementing things like loops is much more difficult. Fortunatly, assembly and C can be combined to meet the end purpose with the greatest ease.
####Documentation
I referenced C2C Arneberg's gitHub to check my table answers with another cadet's. I also used Wikipedia to refresh my memory of external variables.
With his permission, I also referenced C2C Ruprect's ReadMe for tips on formatting because he "always gets a hundo". 
