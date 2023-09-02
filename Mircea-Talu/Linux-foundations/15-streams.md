# Streams

## The concept of streams is essential in Linux

### Theory of streams
* we can define new, or redefine existing streams using programming languages (like C for example)
* there are 3 default streams in the system:
1. **Standard input**
  * it's file descriptor is 0
  * we use the name STDIN
2. **Standard output**
  * when STDIN is waiting for instructions passed to it, standard output displays repsonses from the system (in the simplest scenario)
  * it's file descriptor is 1
  * we use the name STDOUT
3. **Standard error**
  * it's file descrpitor is 2
  * we use the name STDERR
  * to redirect the error output of a command, we ue **2>** ,instead of **>** (we specify the file descriptor as 2)
  * we can capture both STDOUT and STDERR in the same file, using: **cat notexists.txt > capture.txt 2>&1**
