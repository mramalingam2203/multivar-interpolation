#! /bin/bash
#
g++ -c -Wall -w -I/$HOME/include randy.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ randy.o -w /$HOME/libcpp/lagrange_nd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm randy.o
#
mv a.out randy

