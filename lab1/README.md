
1.  Write a C program that reads text from a file and prints on the terminal each input line, preceded by the line number. The output will look like -

        1     This is the first trial line in the file,
        2     and this is the second line. 

    Try the problem once using fgetc() function and once using fgets() function for reading the input. Why is fread() not suitable for this purpose?

    Do not ignore the value returned by the functions fgetc() and fgets(). After this exercise the you should be comfortable with the formatted input and output functions of C.

    
2.  Write a program that takes from the user the name of a file and a "field-number", and then reads that file and for each line in that file prints on the terminal word at position "field-number". For example if there are the following lines in the specified file -

        C is a programming language.
        lex produces a lexical analyser

              cc is a compiler 

    and if the field-number specified is 4, then the output of the program is -

        programming
        lexical
        (NULL)
        compiler 


    After this exercise you should be able to deal with individual words in a text file.

3.  Write a C program that reads the names (as character strings of length upto 20 bytes) and corresponsing roll-numbers (as integers) of 10 students from the user and stores them in a file whose name is specified by the user-
        in text format
        in binary format 

    After running the program check the size of the file created using ls -l command. Also see the content of the binary file using the command
    od -c filename.

    After this exercise you should be clear about the difference between a text file and a binary file.

4.  Write a C program that works like the od program of LINUX (UNIX).

5.  Write a C program that works like the strings program of LINUX (UNIX). 
