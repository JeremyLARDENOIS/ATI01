#!/bin/bash
make clean &2> /dev/null 
git add * && git commit -m "$*" && git push
