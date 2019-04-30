#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR60to63rangeNis200
./mainbcg 5 1258 200 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis200/60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis400
./mainbcg 5 1258 400 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis400/60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis600
./mainbcg 5 1258 600 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis600/60to63result_mahindas.txt
mkdir BICGintoR60to63rangeNis800
./mainbcg 5 1258 800 60 63 0 mahindas.mtx >> BICGintoR60to63rangeNis800/60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis200
./mainbcg 5 1258 200 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis200/60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis400
./mainbcg 5 1258 400 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis400/60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis600
./mainbcg 5 1258 600 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis600/60to63result_mahindas.txt
mkdir BICGintoP60to63rangeNis800
./mainbcg 5 1258 800 60 63 1 mahindas.mtx >> BICGintoP60to63rangeNis800/60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis200
./mainbcg 5 1258 200 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis200/60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis400
./mainbcg 5 1258 400 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis400/60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis600
./mainbcg 5 1258 600 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis600/60to63result_mahindas.txt
mkdir BICGintoX60to63rangeNis800
./mainbcg 5 1258 800 60 63 2 mahindas.mtx >> BICGintoX60to63rangeNis800/60to63result_mahindas.txt
