echo "original code:\n"
disas/r main
p/x (int)main+0x4
set {unsigned char}$1 = 0x66
echo "patched code:\n"
disas/r main
q

