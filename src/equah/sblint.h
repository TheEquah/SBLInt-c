// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.27 HE
// Date (Modified): 12020.01.05 HE
// License: apache-2.0

#ifndef equah_sblint__HEADER
#define equah_sblint__HEADER


#include <stddef.h>
#include <stdio.h>

#include "equah/sbsint.h"


// [>] Default Integer Type
// [i] Default type used when working with integers.
#define equah_sblint__DEFAULT_INT_TYPE unsigned int


// [i] Function declarations.
size_t equah_sblint__required_bytes(equah_sblint__DEFAULT_INT_TYPE);
size_t equah_sblint__required_int_bytes(equah_sblint__DEFAULT_INT_TYPE);
size_t equah_sblint__bytes_to_int(unsigned char *, size_t, equah_sblint__DEFAULT_INT_TYPE *);
size_t equah_sblint__int_to_bytes(equah_sblint__DEFAULT_INT_TYPE, unsigned char *, size_t);


#endif
