#!/bin/bash
make clean 
git add * && git commit -m "$*" && git push
