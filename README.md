# pipex
scored 100 / 100

program replicates the pipe control operator '|' in bash shell

How to use: 
"./pipex file1 cmd1 cmd2 file2"

Example:
$ touch infile
$ touch outfile
$  ./pipex infile "ls -l" "wc -l" outfile
$ cat outfile
$ 14

Behaves just like:
$ < infile ls -l | wc -l > outfile
