# Lesson 3

## Lesson 3.1: THE PUT COMMAND
* **p** puts previously deleted text after the cursor
* **dd** deletes the line and stores it in a Vim register
* move the cursor **ABOVE** where the deleted line should go
* **p** puts the line **BELOW** the cursor

## Lesson 3.2: THE REPLACE COMMAND
* **rx** replaces the character at the cursor with the character **x**
* move the cursor on top of (right before) the character you want to replace

## Lesson 3.3: THE CHANGE OPERATOR
* **ce** changes until the **end** of the word
* place the cursor before the character in the word where you want to start replacing
* type **ce** and replace the word
* **ESC** and go back to Normal Mode
* **cc** does the same, but for the whole line

## Lesson 3.4: MORE CHANGES USING c
* the change operator **c** is used with the same motions as delete (**d**)
* **c [number] motion**
* _NOTE : you can use **Backspace** to correct mistakes while typing_
