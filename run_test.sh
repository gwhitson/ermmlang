#!/bin/bash

make  clean
make

./compiler source/test.py listing/test.lst object/test.obj
cat listing/test.lst
