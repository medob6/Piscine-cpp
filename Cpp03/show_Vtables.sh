#!/bin/bash

# =============================
# 1) Compile with debug symbols
# =============================
echo "[+] Compiling with -g -O0 -fno-inline..."
g++ -std=c++17 -O0 -g -fno-inline -o program *.cpp

# =============================
# 2) Find vtables using nm
# =============================
echo ""
echo "[+] Searching for vtables (_ZTV symbols)..."
nm -C program | grep "vtable" || nm -C program | grep "_ZTV"

# =============================
# 3) Dump full vtable sections
# =============================
echo ""
echo "[+] Dumping .data.rel.ro section (where vtables live on Linux)..."
objdump -s -j .data.rel.ro program

# =============================
# 4) List function symbols with addresses
# =============================
echo ""
echo "[+] Listing all symbols (functions) to match addresses..."
nm -C program | grep " W "

# =============================
# 5) Optional: Show vtable region with objdump disassembly
# =============================
echo ""
echo "[+] Showing disassembly near vtables for cross-reference..."
objdump -D program | grep -A5 -B5 "_ZTV"
