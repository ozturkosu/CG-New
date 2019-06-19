#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./main2 5 420 84 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis400
./main2 5 420 168 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis600
./main2 5 420 252 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis800
./main2 5 420 336 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis800/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis200
./main2 5 420 84 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis400
./main2 5 420 168 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis600
./main2 5 420 252 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis800
./main2 5 420 336 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis800/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis200
./main2 5 420 84 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis400
./main2 5 420 168 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis600
./main2 5 420 252 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis800
./main2 5 420 336 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis800/residual60to63result_bcsstk06.txt
 