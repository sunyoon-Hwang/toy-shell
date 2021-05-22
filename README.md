# toy-shell

####  Project #1 (Make Your Own Shell)

* OS environment is WSL2

* Outputs 'hostname' and 'username'.

* Outputs cwd. cwd is the current working directory.

* The colors 'host name' and 'user name' are dark green [92]. The color of cwd is dark blue [94].

* Adds a shutdown command. Type 'exit' in Myshell and output 'program exit!' before Myshell exits.

Support command-line arguments
==============================

1. ls (ls is a command that queries the list of files in the current location.)

    -l, -a, -t, -rt, -F
-------------------------------------------------------------------------------
2. cd (cd is the command used to move a path.)

    ~, .., /dir, -
-------------------------------------------------------------------------------
3. touch (Touch is a command to create and change the date of a file with a file capacity of 0.)

    filename, -c filename, -t 200001011200 filename, -r filename1 filename2
-------------------------------------------------------------------------------
4. mkdir (mkdir is the command used to create a new directory.)

    dirname, -p dirname/subdname, -m 644 dirname
-------------------------------------------------------------------------------
5. cp (cp is the command to copy files.)

    file cfile, -f file cfile, -R dir cdir
-------------------------------------------------------------------------------
6. mv (mv is the command to move files. It is similar to cp, but the difference is that cp copies the file and the original file remains, but MV does not have the original file left. It can also be used when changing the name.)

    fname mfname, -b fname mfname, -f fname mfname
-------------------------------------------------------------------------------
7. rm (rm is the command used to delete files or directories.)

    fname, -f fname, -r dir
-------------------------------------------------------------------------------
8. cat (Cat takes the file name as a factor and uses it to print out the contents.)

    fname, fname1 fname2, fname1 fname2 | more, fname1 fname2 | head, fname1 fname2 | tail
