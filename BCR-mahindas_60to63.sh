#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR60to63rangeNis200
./mainbcr 5 1258 200 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis200/BCR-60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis400
./mainbcr 5 1258 400 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis400/BCR-60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis600
./mainbcr 5 1258 600 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis600/BCR-60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis800
./mainbcr 5 1258 800 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis800/BCR-60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis200
./mainbcr 5 1258 200 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis200/BCR-60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis400
./mainbcr 5 1258 400 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis400/BCR-60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis600
./mainbcr 5 1258 600 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis600/BCR-60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis800
./mainbcr 5 1258 800 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis800/BCR-60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis200
./mainbcr 5 1258 200 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis200/BCR-60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis400
./mainbcr 5 1258 400 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis400/BCR-60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis600
./mainbcr 5 1258 600 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis600/BCR-60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis800
./mainbcr 5 1258 800 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis800/BCR-60to63result_mahindas.txt
