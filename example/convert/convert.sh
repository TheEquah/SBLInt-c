# Author (Created): Roger "Equah" Hürzeler
# Date (Created): 12020.01.05 HE
# License: apache-2.0

SRC_DIR="`dirname $0`/../../src"
LIB_DIR="`dirname $0`/../../lib"
MAIN_DIR="`dirname $0`"


echo "=== INSTALL DEPENDENCIES ==="
git clone "https://github.com/TheEquah/SBSInt-c" $LIB_DIR/SBSInt-c

echo "=== COMPILE ==="
gcc -I $LIB_DIR/SBSInt-c/src -x c $LIB_DIR/SBSInt-c/src/equah/sbsint.c -I $SRC_DIR -x c $SRC_DIR/equah/sblint.c -x c $MAIN_DIR/convert.c -o $MAIN_DIR/convert.o

echo "=== EXECUTE ==="
$MAIN_DIR/convert.o

echo "=== END ==="
