# Pipes and redirections
### Pipes and redirections take the output of a command and serve it as an input to another command

### example : cat numbers.txt | wc -l
### wc : counts (-l counts lines)

## Pipes: command1 | command2 | command3 | command4
## Redirections: command1 > command2

### example : cat numbers.txt | wc -l > count.txt
This counts the number of lines in numbers.txt and puts it in a file count.txt.

### '>' works this way:
* if file doesn't exist -> create it and add the content to it
* else if file exists -> remove its content and replace it with the new one
* => if we want to APPEND to a file, we must use ">>" instead of ">"

### We can also create loops (the syntax looks like pseudo-code)
* example : while read line; do echo "Content of the line: ${line}"; done < numbers.txt
* explanation: 1. while we can read lines from the file
               2. we print "Content of the line: " and ${line} -> the content of the line
               3. until done
               4. we take the input from the file numbers.txt
  
### Read a dubious html 3.2 web page where I learned about the "less" command:
1. cat ("concatenate") is considered stupid by the author for reading the contents of a file
2. therefore, he suggest using "less" instead
3. tried using it, got a vim editor
