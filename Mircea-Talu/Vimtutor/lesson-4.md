# Lesson 4

## Lesson 4.1: CURSOR LOCATION AND FILE STATUS
* **CTRL-G** shows your location in the file
* **G** moves you to the end of the file
* **gg** moves you to the beginning of the file
* **[number]G** moves you to the line number

## Lesson 4.2: THE SEARCH COMMAND
* **/** followed by a phrase : searches for the phrase
* after, press **n** to search for the same phrase
* **N** searches in the opposite direction
* **?** instead of **/** searches for a phrase in the backward direction

## Lesson 4.3: MATCHING PARANTHESIS SEARCH
* **%** finds a matching ),] or }
* this is very useful when debugging a program with unmatched paranthesis

## Lesson 4.4: THE SUBSTITUTE COMMAND
* **:s/old/new/g** substitutes 'new' for 'old'
* example : **:s/thee/the** : this command only changes the **first** occurence of **thee** in the line
* **:s/thee/the/g** : changes all the occurences in the line
* **#,#s/old/new/g** : where # and # are line numbers of the range of lines where the substitution is to be done
* **%s/old/new/g** : changes every occurence in the whole file
* **%s/old/new/gc** : find every occurence with a prompt whether to substitute or not
