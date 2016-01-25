# diwali-opengl
This was my final submission for CS 471 Computer Graphics at my Undergraduate College.

Windows

Installing OpenGL and GLUT

Windows comes pre-installed with OpenGL

on a 32-bit system:  place this GLUT include file in C:\Program Files \Microsoft Visual Studio 10.0\VC\include\GL  (you may have to create the GL subdirectory)
on a 64-bit system:  place this GLUT include file in C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\include\GL
glut.h: http://www.cis.gvsu.edu/~wolffe/courses/cs367/docs/glut.h

on a 32-bit system:  place this GLUT library in C:\Program Files\Microsoft Visual Studio 10.0\VC\lib
on a 64-bit system:  place this GLUT library in C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\lib
glut32.lib: http://www.cis.gvsu.edu/~wolffe/courses/cs367/docs/glut32.lib

Compiling OpenGL/GLUT programs
create a Visual C++ | Win32 Console Application | Empty project
build and execute as usual

Running OpenGL programs
on a 32-bit system:  place this dynamically-linked library into C:\Windows\System32
on a 64-bit system:  place this dynamically-linked library into C:\Windows\SysWOW64
glut32.dll: http://www.cis.gvsu.edu/~wolffe/courses/cs367/docs/glut32.dll

For more info on running OpenGL programs, check http://www.cis.gvsu.edu/~wolffe/courses/cs367/docs/developingRunningOGL.html