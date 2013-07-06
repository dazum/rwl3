#!/bin/sh

echo "==================="
perl -nle 'if (/Index: (\d+)\tData: (\d+) is a multiple of (\d+)/) {print "OK" if ($1 == $2 && $2 % $3 == 0); }' | uniq -c
echo "==================="
