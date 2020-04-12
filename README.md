# Editor

In this exercise we partially implement the editor "ed" (editor without graphical interface) attached to Linux.

you read more about "ed" by enter the command :

```bash
    man ed
```

or read at this link https://www.gnu.org/software/ed/manual/ed_manual.html .

On the linux system, run the command:
```bash
ed > input.txt
```

The command runs editor "ed" according to the input contained in the input.txt file.

## explanation of the editing commands :
  
  (the numbers are just an example , it can be any numbers according to file). 

**3n**
      
      
    go to line 3, print the line number, print TAB, print the line.
    The current line is now 3.

**&p**
  
    print all file lines.
    The current line is last .
  
**a**

**one line or more**

**. (dot)**
  
    append one line or more after the cuurent line.
  
**i** 
 
**one line or more** 
 
**.**
  
    insert one line or more before the current line.
  
 
 **c**
 
 **one line or more**
 
 **.**
  
    change the current line with one or more lines.


**3d**
  
    go to line 3,delete the line.
    The current line is now 3 (One line after the deleted one).

**/text**
  
    search forward the first line that contains the string "text".
    move to the same line, if the word is not found. Go to the last line.

**?text**
  
    search backward the first line that contains the string "text".
    move to the same line, if the word is not found. Go to the first line.

**s/old/new/**
  
    Replace the first instance of the "old" string with the "new" string in the current row.

**3,4j**
  
    attach lines 3 and 4 to one row. The current row is 3, the number of rows in a file is smaller by 1.

**Q**
  
    quit the editor.
  
  
