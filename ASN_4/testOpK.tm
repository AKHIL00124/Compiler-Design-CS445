#DRBC OpK
#DRBC Func: main returns type void [mem: Global loc: 0 size: -2] [line: 15]
#DRBC .   Child: 1  Compound [mem: None loc: 0 size: -2] [line: 15]
#DRBC .   .   Child: 1  Op: + of type int [line: 16]
#DRBC .   .   .   Child: 0  Const 2 of type int [line: 16]
#DRBC .   .   .   Child: 1  Const 2 of type int [line: 16]
#DRBC * EXPRESSION                               Comment printed before every ExpK                                       
#DRBC LDC  3,2(6)     Load integer constant      -> child[0]           
#DRBC ST  3,-2(1)     Push left side             OpK: If Child[1] exists
#DRBC * TOFF dec: -3                             OpK: If Child[1] exists                      
#DRBC LDC  3,2(6)     Load integer constant      -> child[1]           
#DRBC * TOFF inc: -2                             OpK: If Child[1] exists  
#DRBC LD  4,-2(1)     Pop left into ac1          OpK: If Child[1] exists    
#DRBC ADD  3,4,3      Op +                       OpK: attr.op = '+' 
* bC compiler version bC-Su23
* File compiled:  test07OpK0.bC
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION input
  1:     ST  3,-1(1)	Store return address 
  2:     IN  2,2,2	Grab int input 
  3:     LD  3,-1(1)	Load return address 
  4:     LD  1,0(1)	Adjust fp 
  5:    JMP  7,0(3)	Return 
* END FUNCTION input
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION output
  6:     ST  3,-1(1)	Store return address 
  7:     LD  3,-2(1)	Load parameter 
  8:    OUT  3,3,3	Output integer 
  9:     LD  3,-1(1)	Load return address 
 10:     LD  1,0(1)	Adjust fp 
 11:    JMP  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputb
 12:     ST  3,-1(1)	Store return address 
 13:    INB  2,2,2	Grab bool input 
 14:     LD  3,-1(1)	Load return address 
 15:     LD  1,0(1)	Adjust fp 
 16:    JMP  7,0(3)	Return 
* END FUNCTION inputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputb
 17:     ST  3,-1(1)	Store return address 
 18:     LD  3,-2(1)	Load parameter 
 19:   OUTB  3,3,3	Output bool 
 20:     LD  3,-1(1)	Load return address 
 21:     LD  1,0(1)	Adjust fp 
 22:    JMP  7,0(3)	Return 
* END FUNCTION outputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputc
 23:     ST  3,-1(1)	Store return address 
 24:    INC  2,2,2	Grab char input 
 25:     LD  3,-1(1)	Load return address 
 26:     LD  1,0(1)	Adjust fp 
 27:    JMP  7,0(3)	Return 
* END FUNCTION inputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputc
 28:     ST  3,-1(1)	Store return address 
 29:     LD  3,-2(1)	Load parameter 
 30:   OUTC  3,3,3	Output char 
 31:     LD  3,-1(1)	Load return address 
 32:     LD  1,0(1)	Adjust fp 
 33:    JMP  7,0(3)	Return 
* END FUNCTION outputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outnl
 34:     ST  3,-1(1)	Store return address 
 35:  OUTNL  3,3,3	Output a newline 
 36:     LD  3,-1(1)	Load return address 
 37:     LD  1,0(1)	Adjust fp 
 38:    JMP  7,0(3)	Return 
* END FUNCTION outnl
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
* TOFF set: -2
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF set: -2
* Compound Body
* EXPRESSION
 40:    LDC  3,2(6)	Load integer constant 
 41:     ST  3,-2(1)	Push left side 
* TOFF dec: -3
 42:    LDC  3,2(6)	Load integer constant 
* TOFF inc: -2
 43:     LD  4,-2(1)	Pop left into ac1 
 44:    ADD  3,4,3	Op + 
* TOFF set: -2
* END COMPOUND
* Add standard closing in case there is no return statement
 45:    LDC  2,0(6)	Set return value to 0 
 46:     LD  3,-1(1)	Load return address 
 47:     LD  1,0(1)	Adjust fp 
 48:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,48(7)	Jump to init [backpatch] 
* INIT
 49:    LDA  1,0(0)	set first frame at end of globals 
 50:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 51:    LDA  3,1(7)	Return address in ac 
 52:    JMP  7,-14(7)	Jump to main 
 53:   HALT  0,0,0	DONE! 
* END INIT
Number of warnings: 0
Number of errors: 0
