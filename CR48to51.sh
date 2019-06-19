#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR48to51rangeNis200
./main2 5 420 84 48 51 0 bcsstk06.mtx >> CRintoR48to51rangeNis200/residual48to51result_bcsstk06.txt
mkdir CRintoR48to51rangeNis400
./main2 5 420 168 48 51 0 bcsstk06.mtx >> CRintoR48to51rangeNis400/residual48to51result_bcsstk06.txt
mkdir CRintoR48to51rangeNis600
./main2 5 420 252 48 51 0 bcsstk06.mtx >> CRintoR48to51rangeNis600/residual48to51result_bcsstk06.txt
mkdir CRintoR48to51rangeNis800
./main2 5 420 336 48 51 0 bcsstk06.mtx >> CRintoR48to51rangeNis800/residual48to51result_bcsstk06.txt
mkdir CRintoP48to51rangeNis200
./main2 5 420 84 48 51 1 bcsstk06.mtx >> CRintoP48to51rangeNis200/residual48to51result_bcsstk06.txt
mkdir CRintoP48to51rangeNis400
./main2 5 420 168 48 51 1 bcsstk06.mtx >> CRintoP48to51rangeNis400/residual48to51result_bcsstk06.txt
mkdir CRintoP48to51rangeNis600
./main2 5 420 252 48 51 1 bcsstk06.mtx >> CRintoP48to51rangeNis600/residual48to51result_bcsstk06.txt
mkdir CRintoP48to51rangeNis800
./main2 5 420 336 48 51 1 bcsstk06.mtx >> CRintoP48to51rangeNis800/residual48to51result_bcsstk06.txt
mkdir CRintoX48to51rangeNis200
./main2 5 420 84 48 51 2 bcsstk06.mtx >> CRintoX48to51rangeNis200/residual48to51result_bcsstk06.txt
mkdir CRintoX48to51rangeNis400
./main2 5 420 168 48 51 2 bcsstk06.mtx >> CRintoX48to51rangeNis400/residual48to51result_bcsstk06.txt
mkdir CRintoX48to51rangeNis600
./main2 5 420 252 48 51 2 bcsstk06.mtx >> CRintoX48to51rangeNis600/residual48to51result_bcsstk06.txt
mkdir CRintoX48to51rangeNis800
./main2 5 420 336 48 51 2 bcsstk06.mtx >> CRintoX48to51rangeNis800/residual48to51result_bcsstk06.txt
 