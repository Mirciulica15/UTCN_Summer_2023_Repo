# Lesson 2

## Lesson 2.1: DELETION COMMANDS
* **dw** deletes a word
* move the cursor at the beginning of a word that needs to be deleted

## Lesson 2.2: MORE DELETION COMMANDS
* **d$** deletes from cursor to the end of the line

## Lesson 2.3: OPERATORS AND MOTIONS
* many commands that change text are made from an **operator** and a **motion**
* the format for a delete command with the **d** delete operator is: **d motion**
* **d** : the delete operator
* **motion** : what the operator will operate on
* short list of motions:
  1. **w** : until the start of the next word, EXCLUDING its first character
  2. **e** : until the end of the current word, INCLUDING the last character
  3. **$** : until the end of the line, INCLUDING the last character
* **USEFUL** : pressing the **motion** without an operator in Normal Mode will move the cursor as specified

## Lesson 2.4: USING A COUNT FOR A MOTION
* typing a number before a motion repeats it that many times
* example : typing **2w** will move the cursor 2 words forward
* example : type **0** to move to the start of the line

## Lesson 2.5: USING A COUNT TO DELETE MORE
* typing a number with the operator repeats it that many times
* example : **d number motion**
* example : **d2w** will delete 2 words

## Lesson 2.6: OPERATING ON LINES
* **dd** deletes a whole line
* **2dd** deletes 2 lines
* doubling to operate on a line also works for operators mentioned below

## Lesson 2.7: THE UNDO COMMAND
* **u** undoes the last command
* **U** fixes the whole line
* **CTRL-R** redoes the command (undoes the undos)
