nasm -f win64 matrixaccel.asm                    
gcc -c matrixaccel_c.c -o matrixaccel_c.obj -m64 
gcc matrixaccel_c.obj matrixaccel.obj -o matrixaccel.exe -m64   
matrixaccel.exe                                   