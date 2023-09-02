# Lesson 5

## Lesson 5.1: HOW TO EXECUTE AN EXTERNAL COMMAND
* type **:!** followed by an external command to execute that command
* example : **:!ls** shows a listing of the directory
* _NOTE: it is possible to execute any external command this way, even with arguments_
* _NOTE: all **:** commands must be finished by hitting **ENTER**

 ## Lesson 5.2: MORE ON WRITING FILES
 * **:w FILENAME** saves changes made to the text inside FILENAME
 * remove the file:
    1. :!del FILENAME (Unix)
    2. :!rm FILENAME (Linux)

## Lesson 5.3: SELECTING TEXT TO WRITE
* **v motion :w FILENAME**
* **v** starts Visual Mode
* **motion** refers to moving the cursor and selecting the content
* press **:**
* type **w TEST**
* vim will write the selected lines to the TEST file
* _NOTE: you can also use **v** in other ways, in deletion by example_

## Lesson 5.4: RETRIEVING AND MERGING FILES
* **:r** FILENAME inserts the contents of FILENAME
* you can also read the output of external commands: **:r !ls**

