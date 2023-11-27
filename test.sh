#!/bin/bash
ARG=$(node tester.js)
echo $ARG
./push_swap $ARG | ./checker $ARG
