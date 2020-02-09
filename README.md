<!-- Author (Created): Roger "Equah" Hürzeler -->
<!-- Author (Modified): Roger "Equah" Hürzeler -->
<!-- Date (Created): 12019.12.27 HE -->
<!-- Date (Modified): 12020.02.09 HE -->
<!-- License: apache-2.0 -->

**SBLInt [C]**
================================================================================

[SBLInt](https://github.com/TheEquah/SBLInt/) C library implementation.

--------------------------------------------------------------------------------

# Architecture

Overview of the SBLInt architecture.

## SBLInt

SBLInt starts with [SBSInt](https://github.com/TheEquah/SBSInt/) bytes, defining the amount of following bytes containing the integer. After this the following bytes are an integer staring with the MSB. This allows to write smaller integers using less bytes than larger integers. The exception is `0`, which will be directly printed as `0x00` without following bytes.

--------------------------------------------------------------------------------

# Compile

To compile a C file using SBSInt, use the `#include "equah/sblint.h"` at the beginning of the file.

The file can then be compiled by adding the `-I ./<path_to_src> -x c ./<path_to_src>/equah/sbsint.c` to the `gcc` command where `<path_to_src>` is the path to the [`/src/`](https://github.com/TheEquah/SBLInt-c/tree/master/src/) directory.

You also need the [SBSInt C](https://github.com/TheEquah/SBSInt-c/) library. Download it with `git clone "https://github.com/TheEquah/SBSInt-c.git"` and add to the `gcc` command the `-I ./<path_to_sbsint_src>` and `-x c ./<path_to_sbsint_src/equah/sbsint.c`.

It will probably look something like `gcc -I ./SBLInt-c/src -x c ./SBLInt-c/src/equah/sblint.c -I ./SBLInt-c/lib/SBSInt-c/src -x c ./SBLInt-c/lib/SBSInt-c/src/equah/sbsint.c -x c ./main.c -o main.o`.

## Requires

SBLInt requires the [SBSInt C](https://github.com/TheEquah/SBSInt-c/) library.

--------------------------------------------------------------------------------

# Examples

This repository provides the following example uses for SBLInt.

## Convert

Example which converts an integer to SBLInt and back.

Directory: [`/example/convert/`](https://github.com/TheEquah/SBLInt-c/tree/master/example/convert/)

## Convert Stream

Example which converts an integer to SBLInt and back using the "single byte read/write" functions.

Directory: [`/example/convert/`](https://github.com/TheEquah/SBLInt-c/tree/master/example/convert_stream/)

--------------------------------------------------------------------------------
