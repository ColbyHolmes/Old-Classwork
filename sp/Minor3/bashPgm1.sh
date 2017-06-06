#!/bin/bash

echo "Enter A, B, or C: "
read choice
case $choice in
   A | B | C)  echo "You entered: $choice";;
   *) echo "The value you entered is invalid.";;
esac
