#!/bin/bash

gcc -Wall $1.c -o $1 && chmod u+x $1 && ./$1 
