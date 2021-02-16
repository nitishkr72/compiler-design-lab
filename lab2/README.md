#### Write a lexical analyser for the assembly language described above. The program should take as input a text file containing an assembly program and print the stream of token values corresponding to the items in the input file. For identifiers and numbers the actual input item should also appear within brackets along with the token value. e.g. the output may look like:

    17 20(100) 21(AGAIN) 14 20(3) 21(TERM) .... 

#### Write the program once in plain C, and once using flex utility. 


A hypothetical Assembly Language:

Imperative Statements:

    Instruction   Assembly	       Remarks
    Op-code       Instruction 
                  Format
    __________________________________________________________________________            
    00            STOP            Execution stops
  
    01            ADD   ONE       Add constant ONE to Accumulator (implicit
                                     operand)
  
    02            SUB   NUM       Subtract NUM from accumulator
  
    03            MULT  TERM      Multiply accumulator contents by TERM
  
    04            LOAD  N         Load value of N into accumulator
  
    05            STORE RESULT    Store value of accumulator in RESULT.
  
    06            TRANS NEXT      Transfer control to instruction with label NEXT
  
    07            TRIM  NEXT      Transfer control to NEXT if acc < 0
  
    08            DIV   D         Divide accumulator by D.
  
    09            READ  A         Read value read from input device into location A.
  
    10            PRINT COUNT     Print value of COUNT on terminal.
  
    11            LIR   4,A       Load index register 4 with last three digits of location A.
  
    12            IIR   3,A       Increment index register 3 with last three
                                digits of operand A.
    13            LOOP  4,AGAIN   Decrement index register 4. If new content > 0
                                transfer control to AGAIN.

Assembler Directives:
                
                Assembly	Remarks
                Instruction
                Format
                _____________________________________________________________________________
                START  1000     Assume that program will be loaded from
                                location 1000.
                END             Consider it as the last instruction in the
                                program.
                LTORG           Literals may be alloted memory space from here.

Declarative Statements:
                
                Assembly	Remarks
                Instruction
                Format
           _______________________________________________________________________
           G    DS  20          Declare 20 bytes and call it as G
           
           ONE  DC  '1'         Store 1 in the required number of bytes and
                                call that address ONE.
