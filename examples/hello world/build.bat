:: build script for hello world PE loader

gcc -c helloworld.c -Os -s -std=c99 -g
gcc -o helloworld.exe helloworld.o ..\..\Release\PEel32.lib -Os -s
del helloworld.o

pause