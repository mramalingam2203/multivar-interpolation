#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ test_2d.o /$HOME/libcpp/lagrange_nd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_2d.o
#
mv a.out test_2d

