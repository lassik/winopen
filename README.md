# `open` for Windows #

## Intro ##

This is a quick Windows port of the Max OS X
[`open` utility](http://ss64.com/osx/open.html). That tool opens files
and folders from the command line as if you had double-clicked on them
in the Finder (the OS X equivalent to Windows Explorer).

## Download ##

[Download `open.exe` from AppVeyor](https://ci.appveyor.com/project/lassik/winopen/build/artifacts) and put it in your `PATH`.

## Usage ##

This port only covers the most common use case: opening one file using
its default file association. That's what you'll want 95% of the time.

    open someProgram.exe
    open someFile.txt
    open someFolder
