* bC compiler version bC-Su23
* File compiled:  game2.bC
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
* FUNCTION myRand
* TOFF set: -2
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF set: -2
* Compound Body
* EXPRESSION
 40:     LD  3,0(0)	Load variable next
 41:     ST  3,-2(1)	Push left side 
* TOFF dec: -3
 42:     LD  3,0(0)	Load variable next
* TOFF inc: -2
 43:     LD  4,-2(1)	Pop left into ac1 
 44:    MUL  3,4,3	Op * 
 45:     ST  3,-2(1)	Push left side 
* TOFF dec: -3
 46:    LDC  3,100(6)	Load integer constant 
* TOFF inc: -2
 47:     LD  4,-2(1)	Pop left into ac1 
 48:    DIV  3,4,3	Op / 
 49:     ST  3,-2(1)	Push left side 
* TOFF dec: -3
 50:    LDC  3,10000(6)	Load integer constant 
* TOFF inc: -2
 51:     LD  4,-2(1)	Pop left into ac1 
 52:    MOD  3,4,3	Op % 
 53:     ST  3,0(0)	Store variable next
* RETURN
 54:     LD  3,0(0)	Load variable next
 55:    LDA  2,0(3)	Copy result to return register 
 56:     LD  3,-1(1)	Load return address 
 57:     LD  1,0(1)	Adjust fp 
 58:    JMP  7,0(3)	Return 
* TOFF set: -2
* END COMPOUND
* Add standard closing in case there is no return statement
 59:    LDC  2,0(6)	Set return value to 0 
 60:     LD  3,-1(1)	Load return address 
 61:     LD  1,0(1)	Adjust fp 
 62:    JMP  7,0(3)	Return 
* END FUNCTION myRand
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION println
* TOFF set: -3
 63:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF set: -4
 64:    LDC  3,0(6)	Load integer constant 
 65:     ST  3,-3(1)	Store variable i
* Compound Body
* WHILE
 66:     LD  3,-2(1)	Load address of base of array str
 67:     ST  3,-4(1)	Push left side 
* TOFF dec: -5
 68:     LD  3,-3(1)	Load variable i
* TOFF inc: -4
 69:     LD  4,-4(1)	Pop left into ac1 
 70:    SUB  3,4,3	compute location from index 
 71:     LD  3,0(3)	Load array element 
 72:     ST  3,-4(1)	Push left side 
* TOFF dec: -5
 73:    LDC  3,0(6)	Load char constant 
* TOFF inc: -4
 74:     LD  4,-4(1)	Pop left into ac1 
 75:    TNE  3,4,3	Op != 
 76:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF set: -4
* Compound Body
* EXPRESSION
* CALL outputc
 78:     ST  1,-4(1)	Store fp in ghost frame for outputc
* TOFF dec: -5
* TOFF dec: -6
* Param 1
 79:     LD  3,-2(1)	Load address of base of array str
 80:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
 81:     LD  3,-3(1)	Load variable i
* TOFF inc: -6
 82:     LD  4,-6(1)	Pop left into ac1 
 83:    SUB  3,4,3	compute location from index 
 84:     LD  3,0(3)	Load array element 
 85:     ST  3,-6(1)	Push parameter 
* TOFF dec: -7
* Param end outputc
 86:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 87:    LDA  3,1(7)	Return address in ac 
 88:    JMP  7,-61(7)	CALL outputc
 89:    LDA  3,0(2)	Save the result in ac 
* Call end outputc
* TOFF set: -4
* EXPRESSION
 90:     LD  3,-3(1)	load lhs variable i
 91:    LDA  3,1(3)	increment value of i
 92:     ST  3,-3(1)	Store variable i
* TOFF set: -4
* END COMPOUND
 93:    JMP  7,-28(7)	go to beginning of loop 
 77:    JMP  7,16(7)	Jump past loop [backpatch] 
* END WHILE
* EXPRESSION
* CALL outnl
 94:     ST  1,-4(1)	Store fp in ghost frame for outnl
* TOFF dec: -5
* TOFF dec: -6
* Param end outnl
 95:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 96:    LDA  3,1(7)	Return address in ac 
 97:    JMP  7,-64(7)	CALL outnl
 98:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -4
* TOFF set: -3
* END COMPOUND
* Add standard closing in case there is no return statement
 99:    LDC  2,0(6)	Set return value to 0 
100:     LD  3,-1(1)	Load return address 
101:     LD  1,0(1)	Adjust fp 
102:    JMP  7,0(3)	Return 
* END FUNCTION println
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
* TOFF set: -2
103:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF set: -3
104:    LDC  3,1(6)	Load integer constant 
105:     ST  3,-2(1)	Store variable choice
* Compound Body
* WHILE
106:     LD  3,-2(1)	Load variable choice
107:     ST  3,-3(1)	Push left side 
* TOFF dec: -4
108:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -3
109:     LD  4,-3(1)	Pop left into ac1 
110:    TEQ  3,4,3	Op == 
111:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF set: -6
113:    LDC  3,32(6)	Load integer constant 
114:     ST  3,-3(1)	Store variable obj
115:    LDC  3,1(6)	Load integer constant 
116:     ST  3,-4(1)	Store variable pl
* Compound Body
* EXPRESSION
* CALL println
117:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
  2:    LIT  "Welcom to Nim Game."
118:    LDA  3,-2(0)	Load address of char array 
119:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
120:    LDA  1,-6(1)	Ghost frame becomes new active frame 
121:    LDA  3,1(7)	Return address in ac 
122:    JMP  7,-60(7)	CALL println
123:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL println
124:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
 23:    LIT  "You have 32 objects."
125:    LDA  3,-23(0)	Load address of char array 
126:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
127:    LDA  1,-6(1)	Ghost frame becomes new active frame 
128:    LDA  3,1(7)	Return address in ac 
129:    JMP  7,-67(7)	CALL println
130:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL println
131:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
 45:    LIT  "Enter a number between 1 - 4 to remove them"
132:    LDA  3,-45(0)	Load address of char array 
133:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
134:    LDA  1,-6(1)	Ghost frame becomes new active frame 
135:    LDA  3,1(7)	Return address in ac 
136:    JMP  7,-74(7)	CALL println
137:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL println
138:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
 90:    LIT  "and the computer will remove <4 objects."
139:    LDA  3,-90(0)	Load address of char array 
140:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
141:    LDA  1,-6(1)	Ghost frame becomes new active frame 
142:    LDA  3,1(7)	Return address in ac 
143:    JMP  7,-81(7)	CALL println
144:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL println
145:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
132:    LIT  "Last man standing wins!"
146:    LDA  3,-132(0)	Load address of char array 
147:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
148:    LDA  1,-6(1)	Ghost frame becomes new active frame 
149:    LDA  3,1(7)	Return address in ac 
150:    JMP  7,-88(7)	CALL println
151:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* WHILE
152:     LD  3,-3(1)	Load variable obj
153:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
154:    LDC  3,0(6)	Load integer constant 
* TOFF inc: -6
155:     LD  4,-6(1)	Pop left into ac1 
156:    TGT  3,4,3	Op > 
157:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF set: -6
* Compound Body
* IF
159:     LD  3,-3(1)	Load variable obj
160:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
161:    LDC  3,5(6)	Load integer constant 
* TOFF inc: -6
162:     LD  4,-6(1)	Pop left into ac1 
163:    TLT  3,4,3	Op < 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
165:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
157:    LIT  "Someone is going to be a winner soon"
166:    LDA  3,-157(0)	Load address of char array 
167:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
168:    LDA  1,-6(1)	Ghost frame becomes new active frame 
169:    LDA  3,1(7)	Return address in ac 
170:    JMP  7,-108(7)	CALL println
171:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL outnl
172:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
173:    LDA  1,-6(1)	Ghost frame becomes new active frame 
174:    LDA  3,1(7)	Return address in ac 
175:    JMP  7,-142(7)	CALL outnl
176:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -6
* END COMPOUND
164:    JZR  3,12(7)	Jump around the THEN if false [backpatch] 
* END IF
* IF
177:     LD  3,-4(1)	Load variable pl
178:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
179:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
180:     LD  4,-6(1)	Pop left into ac1 
181:    TEQ  3,4,3	Op == 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
183:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
195:    LIT  "Player 1 enter your move (1-4):  "
184:    LDA  3,-195(0)	Load address of char array 
185:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
186:    LDA  1,-6(1)	Ghost frame becomes new active frame 
187:    LDA  3,1(7)	Return address in ac 
188:    JMP  7,-126(7)	CALL println
189:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL input
190:     ST  1,-6(1)	Store fp in ghost frame for input
* TOFF dec: -7
* TOFF dec: -8
* Param end input
191:    LDA  1,-6(1)	Ghost frame becomes new active frame 
192:    LDA  3,1(7)	Return address in ac 
193:    JMP  7,-193(7)	CALL input
194:    LDA  3,0(2)	Save the result in ac 
* Call end input
* TOFF set: -6
195:     ST  3,-5(1)	Store variable move
* EXPRESSION
* CALL outnl
196:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
197:    LDA  1,-6(1)	Ghost frame becomes new active frame 
198:    LDA  3,1(7)	Return address in ac 
199:    JMP  7,-166(7)	CALL outnl
200:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* WHILE
201:     LD  3,-5(1)	Load variable move
202:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
203:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
204:     LD  4,-6(1)	Pop left into ac1 
205:    TLT  3,4,3	Op < 
206:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
207:     LD  3,-5(1)	Load variable move
208:     ST  3,-7(1)	Push left side 
* TOFF dec: -8
209:    LDC  3,4(6)	Load integer constant 
* TOFF inc: -7
210:     LD  4,-7(1)	Pop left into ac1 
211:    TGT  3,4,3	Op > 
* TOFF inc: -6
212:     LD  4,-6(1)	Pop left into ac1 
213:     OR  3,4,3	Op OR 
214:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
215:     LD  3,-5(1)	Load variable move
216:     ST  3,-7(1)	Push left side 
* TOFF dec: -8
217:     LD  3,-3(1)	Load variable obj
* TOFF inc: -7
218:     LD  4,-7(1)	Pop left into ac1 
219:    TGT  3,4,3	Op > 
* TOFF inc: -6
220:     LD  4,-6(1)	Pop left into ac1 
221:     OR  3,4,3	Op OR 
222:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
224:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
230:    LIT  "Illegal move. "
225:    LDA  3,-230(0)	Load address of char array 
226:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
227:    LDA  1,-6(1)	Ghost frame becomes new active frame 
228:    LDA  3,1(7)	Return address in ac 
229:    JMP  7,-167(7)	CALL println
230:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL println
231:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
246:    LIT  "Enter a new move (1-4): "
232:    LDA  3,-246(0)	Load address of char array 
233:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
234:    LDA  1,-6(1)	Ghost frame becomes new active frame 
235:    LDA  3,1(7)	Return address in ac 
236:    JMP  7,-174(7)	CALL println
237:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL input
238:     ST  1,-6(1)	Store fp in ghost frame for input
* TOFF dec: -7
* TOFF dec: -8
* Param end input
239:    LDA  1,-6(1)	Ghost frame becomes new active frame 
240:    LDA  3,1(7)	Return address in ac 
241:    JMP  7,-241(7)	CALL input
242:    LDA  3,0(2)	Save the result in ac 
* Call end input
* TOFF set: -6
243:     ST  3,-5(1)	Store variable move
* EXPRESSION
* CALL outnl
244:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
245:    LDA  1,-6(1)	Ghost frame becomes new active frame 
246:    LDA  3,1(7)	Return address in ac 
247:    JMP  7,-214(7)	CALL outnl
248:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -6
* END COMPOUND
249:    JMP  7,-49(7)	go to beginning of loop 
223:    JMP  7,26(7)	Jump past loop [backpatch] 
* END WHILE
* TOFF set: -6
* END COMPOUND
182:    JZR  3,68(7)	Jump around the THEN if false [backpatch] 
* ELSE
* COMPOUND
* TOFF set: -6
* Compound Body
* IF
251:     LD  3,-3(1)	Load variable obj
252:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
253:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
254:     LD  4,-6(1)	Pop left into ac1 
255:    TGT  3,4,3	Op > 
256:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
257:     LD  3,-3(1)	Load variable obj
258:     ST  3,-7(1)	Push left side 
* TOFF dec: -8
259:    LDC  3,5(6)	Load integer constant 
* TOFF inc: -7
260:     LD  4,-7(1)	Pop left into ac1 
261:    TLT  3,4,3	Op < 
* TOFF inc: -6
262:     LD  4,-6(1)	Pop left into ac1 
263:    AND  3,4,3	Op AND 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
265:     LD  3,-3(1)	Load variable obj
266:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
267:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
268:     LD  4,-6(1)	Pop left into ac1 
269:    SUB  3,4,3	Op - 
270:     ST  3,-5(1)	Store variable move
* TOFF set: -6
* END COMPOUND
264:    JZR  3,6(7)	Jump around the THEN if false [backpatch] 
* END IF
* IF
271:     LD  3,-3(1)	Load variable obj
272:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
273:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
274:     LD  4,-6(1)	Pop left into ac1 
275:    TEQ  3,4,3	Op == 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
277:    LDC  3,1(6)	Load integer constant 
278:     ST  3,-5(1)	Store variable move
* TOFF set: -6
* END COMPOUND
276:    JZR  3,3(7)	Jump around the THEN if false [backpatch] 
* ELSE
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
280:    LDC  3,1(6)	Load integer constant 
281:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
* CALL myRand
282:     ST  1,-7(1)	Store fp in ghost frame for myRand
* TOFF dec: -8
* TOFF dec: -9
* Param end myRand
283:    LDA  1,-7(1)	Ghost frame becomes new active frame 
284:    LDA  3,1(7)	Return address in ac 
285:    JMP  7,-247(7)	CALL myRand
286:    LDA  3,0(2)	Save the result in ac 
* Call end myRand
* TOFF set: -7
287:     ST  3,-7(1)	Push left side 
* TOFF dec: -8
288:    LDC  3,4(6)	Load integer constant 
* TOFF inc: -7
289:     LD  4,-7(1)	Pop left into ac1 
290:    MOD  3,4,3	Op % 
* TOFF inc: -6
291:     LD  4,-6(1)	Pop left into ac1 
292:    ADD  3,4,3	Op + 
293:     ST  3,-5(1)	Store variable move
* TOFF set: -6
* END COMPOUND
279:    JMP  7,14(7)	Jump around the ELSE [backpatch] 
* END IF
* EXPRESSION
* CALL println
294:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
272:    LIT  "Computer removed "
295:    LDA  3,-272(0)	Load address of char array 
296:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
297:    LDA  1,-6(1)	Ghost frame becomes new active frame 
298:    LDA  3,1(7)	Return address in ac 
299:    JMP  7,-237(7)	CALL println
300:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL output
301:     ST  1,-6(1)	Store fp in ghost frame for output
* TOFF dec: -7
* TOFF dec: -8
* Param 1
302:     LD  3,-5(1)	Load variable move
303:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end output
304:    LDA  1,-6(1)	Ghost frame becomes new active frame 
305:    LDA  3,1(7)	Return address in ac 
306:    JMP  7,-301(7)	CALL output
307:    LDA  3,0(2)	Save the result in ac 
* Call end output
* TOFF set: -6
* EXPRESSION
* CALL outnl
308:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
309:    LDA  1,-6(1)	Ghost frame becomes new active frame 
310:    LDA  3,1(7)	Return address in ac 
311:    JMP  7,-278(7)	CALL outnl
312:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -6
* END COMPOUND
250:    JMP  7,62(7)	Jump around the ELSE [backpatch] 
* END IF
* EXPRESSION
313:     LD  3,-3(1)	Load variable obj
314:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
315:     LD  3,-5(1)	Load variable move
* TOFF inc: -6
316:     LD  4,-6(1)	Pop left into ac1 
317:    SUB  3,4,3	Op - 
318:     ST  3,-3(1)	Store variable obj
* TOFF set: -9
* FOR
319:    LDC  3,0(6)	Load integer constant 
320:     ST  3,-6(1)	save starting value in index variable 
321:     LD  3,-3(1)	Load variable obj
322:     ST  3,-7(1)	save stop value 
323:    LDC  3,1(6)	default increment by 1 
324:     ST  3,-8(1)	save step value 
325:     LD  4,-6(1)	loop index 
326:     LD  5,-7(1)	stop value 
327:     LD  3,-8(1)	step value 
328:    SLT  3,4,5	Op < 
329:    JNZ  3,1(7)	Jump to loop body 
* COMPOUND
* TOFF set: -9
* Compound Body
* EXPRESSION
* CALL outputc
331:     ST  1,-9(1)	Store fp in ghost frame for outputc
* TOFF dec: -10
* TOFF dec: -11
* Param 1
332:    LDC  3,35(6)	Load char constant 
333:     ST  3,-11(1)	Push parameter 
* TOFF dec: -12
* Param end outputc
334:    LDA  1,-9(1)	Ghost frame becomes new active frame 
335:    LDA  3,1(7)	Return address in ac 
336:    JMP  7,-309(7)	CALL outputc
337:    LDA  3,0(2)	Save the result in ac 
* Call end outputc
* TOFF set: -9
* TOFF set: -9
* END COMPOUND
* Bottom of loop increment and jump
338:     LD  3,-6(1)	Load index 
339:     LD  5,-8(1)	Load step 
340:    ADD  3,3,5	increment 
341:     ST  3,-6(1)	store back to index 
342:    JMP  7,-18(7)	go to beginning of loop 
330:    JMP  7,12(7)	Jump past loop [backpatch] 
* END LOOP
* EXPRESSION
* CALL output
343:     ST  1,-9(1)	Store fp in ghost frame for output
* TOFF dec: -10
* TOFF dec: -11
* Param 1
344:     LD  3,-3(1)	Load variable obj
345:     ST  3,-11(1)	Push parameter 
* TOFF dec: -12
* Param end output
346:    LDA  1,-9(1)	Ghost frame becomes new active frame 
347:    LDA  3,1(7)	Return address in ac 
348:    JMP  7,-343(7)	CALL output
349:    LDA  3,0(2)	Save the result in ac 
* Call end output
* TOFF set: -9
* EXPRESSION
* CALL println
350:     ST  1,-9(1)	Store fp in ghost frame for println
* TOFF dec: -10
* TOFF dec: -11
* Param 1
291:    LIT  " objects remaining. "
351:    LDA  3,-291(0)	Load address of char array 
352:     ST  3,-11(1)	Push parameter 
* TOFF dec: -12
* Param end println
353:    LDA  1,-9(1)	Ghost frame becomes new active frame 
354:    LDA  3,1(7)	Return address in ac 
355:    JMP  7,-293(7)	CALL println
356:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -9
* EXPRESSION
* CALL outnl
357:     ST  1,-9(1)	Store fp in ghost frame for outnl
* TOFF dec: -10
* TOFF dec: -11
* Param end outnl
358:    LDA  1,-9(1)	Ghost frame becomes new active frame 
359:    LDA  3,1(7)	Return address in ac 
360:    JMP  7,-327(7)	CALL outnl
361:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -9
* IF
362:     LD  3,-3(1)	Load variable obj
363:     ST  3,-9(1)	Push left side 
* TOFF dec: -10
364:    LDC  3,25(6)	Load integer constant 
* TOFF inc: -9
365:     LD  4,-9(1)	Pop left into ac1 
366:    TGT  3,4,3	Op > 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
368:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
313:    LIT  "There's still a lot of game left "
369:    LDA  3,-313(0)	Load address of char array 
370:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
371:    LDA  1,-6(1)	Ghost frame becomes new active frame 
372:    LDA  3,1(7)	Return address in ac 
373:    JMP  7,-311(7)	CALL println
374:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL outnl
375:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
376:    LDA  1,-6(1)	Ghost frame becomes new active frame 
377:    LDA  3,1(7)	Return address in ac 
378:    JMP  7,-345(7)	CALL outnl
379:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -9
* END COMPOUND
367:    JZR  3,12(7)	Jump around the THEN if false [backpatch] 
* END IF
* EXPRESSION
380:     LD  3,-4(1)	Load variable pl
381:     ST  3,-9(1)	Push left side 
* TOFF dec: -10
382:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -9
383:     LD  4,-9(1)	Pop left into ac1 
384:    ADD  3,4,3	Op + 
385:     ST  3,-9(1)	Push left side 
* TOFF dec: -10
386:    LDC  3,2(6)	Load integer constant 
* TOFF inc: -9
387:     LD  4,-9(1)	Pop left into ac1 
388:    MOD  3,4,3	Op % 
389:     ST  3,-4(1)	Store variable pl
* TOFF set: -6
* END COMPOUND
390:    JMP  7,-239(7)	go to beginning of loop 
158:    JMP  7,232(7)	Jump past loop [backpatch] 
* END WHILE
* IF
391:     LD  3,-4(1)	Load variable pl
392:     ST  3,-6(1)	Push left side 
* TOFF dec: -7
393:    LDC  3,1(6)	Load integer constant 
* TOFF inc: -6
394:     LD  4,-6(1)	Pop left into ac1 
395:    TEQ  3,4,3	Op == 
* THEN
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
397:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
348:    LIT  "Confgratulations, You won!!! "
398:    LDA  3,-348(0)	Load address of char array 
399:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
400:    LDA  1,-6(1)	Ghost frame becomes new active frame 
401:    LDA  3,1(7)	Return address in ac 
402:    JMP  7,-340(7)	CALL println
403:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL outnl
404:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
405:    LDA  1,-6(1)	Ghost frame becomes new active frame 
406:    LDA  3,1(7)	Return address in ac 
407:    JMP  7,-374(7)	CALL outnl
408:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -6
* END COMPOUND
396:    JZR  3,13(7)	Jump around the THEN if false [backpatch] 
* ELSE
* COMPOUND
* TOFF set: -6
* Compound Body
* EXPRESSION
* CALL println
410:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
379:    LIT  "Sorry, you lost "
411:    LDA  3,-379(0)	Load address of char array 
412:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
413:    LDA  1,-6(1)	Ghost frame becomes new active frame 
414:    LDA  3,1(7)	Return address in ac 
415:    JMP  7,-353(7)	CALL println
416:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL outnl
417:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
418:    LDA  1,-6(1)	Ghost frame becomes new active frame 
419:    LDA  3,1(7)	Return address in ac 
420:    JMP  7,-387(7)	CALL outnl
421:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -6
* END COMPOUND
409:    JMP  7,12(7)	Jump around the ELSE [backpatch] 
* END IF
* EXPRESSION
* CALL println
422:     ST  1,-6(1)	Store fp in ghost frame for println
* TOFF dec: -7
* TOFF dec: -8
* Param 1
397:    LIT  "Enter 1 to replay, or any other number to quit:  "
423:    LDA  3,-397(0)	Load address of char array 
424:     ST  3,-8(1)	Push parameter 
* TOFF dec: -9
* Param end println
425:    LDA  1,-6(1)	Ghost frame becomes new active frame 
426:    LDA  3,1(7)	Return address in ac 
427:    JMP  7,-365(7)	CALL println
428:    LDA  3,0(2)	Save the result in ac 
* Call end println
* TOFF set: -6
* EXPRESSION
* CALL input
429:     ST  1,-6(1)	Store fp in ghost frame for input
* TOFF dec: -7
* TOFF dec: -8
* Param end input
430:    LDA  1,-6(1)	Ghost frame becomes new active frame 
431:    LDA  3,1(7)	Return address in ac 
432:    JMP  7,-432(7)	CALL input
433:    LDA  3,0(2)	Save the result in ac 
* Call end input
* TOFF set: -6
434:     ST  3,-2(1)	Store variable choice
* EXPRESSION
* CALL outnl
435:     ST  1,-6(1)	Store fp in ghost frame for outnl
* TOFF dec: -7
* TOFF dec: -8
* Param end outnl
436:    LDA  1,-6(1)	Ghost frame becomes new active frame 
437:    LDA  3,1(7)	Return address in ac 
438:    JMP  7,-405(7)	CALL outnl
439:    LDA  3,0(2)	Save the result in ac 
* Call end outnl
* TOFF set: -6
* TOFF set: -3
* END COMPOUND
440:    JMP  7,-335(7)	go to beginning of loop 
112:    JMP  7,328(7)	Jump past loop [backpatch] 
* END WHILE
* TOFF set: -2
* END COMPOUND
* Add standard closing in case there is no return statement
441:    LDC  2,0(6)	Set return value to 0 
442:     LD  3,-1(1)	Load return address 
443:     LD  1,0(1)	Adjust fp 
444:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,444(7)	Jump to init [backpatch] 
* INIT
445:    LDA  1,-447(0)	set first frame at end of globals 
446:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
447:    LDC  3,3251(6)	Load integer constant 
448:     ST  3,0(0)	Store variable next
* END INIT GLOBALS AND STATICS
449:    LDA  3,1(7)	Return address in ac 
450:    JMP  7,-348(7)	Jump to main 
451:   HALT  0,0,0	DONE! 
* END INIT
