#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR60to63rangeNis200
./mainbcg 5 512 100 60 63 0 gre_512.mtx >> BICGintoR60to63rangeNis200/60to63result_gre_512.txt
mkdir BICGintoR60to63rangeNis400
./mainbcg 5 512 200 60 63 0 gre_512.mtx >> BICGintoR60to63rangeNis400/60to63result_gre_512.txt
mkdir BICGintoR60to63rangeNis600
./mainbcg 5 512 300 60 63 0 gre_512.mtx >> BICGintoR60to63rangeNis600/60to63result_gre_512.txt
mkdir BICGintoR60to63rangeNis800
./mainbcg 5 512 400 60 63 0 gre_512.mtx >> BICGintoR60to63rangeNis800/60to63result_gre_512.txt
mkdir BICGintoP60to63rangeNis200
./mainbcg 5 512 100 60 63 1 gre_512.mtx >> BICGintoP60to63rangeNis200/60to63result_gre_512.txt
mkdir BICGintoP60to63rangeNis400
./mainbcg 5 512 200 60 63 1 gre_512.mtx >> BICGintoP60to63rangeNis400/60to63result_gre_512.txt
mkdir BICGintoP60to63rangeNis600
./mainbcg 5 512 300 60 63 1 gre_512.mtx >> BICGintoP60to63rangeNis600/60to63result_gre_512.txt
mkdir BICGintoP60to63rangeNis800
./mainbcg 5 512 400 60 63 1 gre_512.mtx >> BICGintoP60to63rangeNis800/60to63result_gre_512.txt
mkdir BICGintoX60to63rangeNis200
./mainbcg 5 512 100 60 63 2 gre_512.mtx >> BICGintoX60to63rangeNis200/60to63result_gre_512.txt
mkdir BICGintoX60to63rangeNis400
./mainbcg 5 512 200 60 63 2 gre_512.mtx >> BICGintoX60to63rangeNis400/60to63result_gre_512.txt
mkdir BICGintoX60to63rangeNis600
./mainbcg 5 512 300 60 63 2 gre_512.mtx >> BICGintoX60to63rangeNis600/60to63result_gre_512.txt
mkdir BICGintoX60to63rangeNis800
./mainbcg 5 512 400 60 63 2 gre_512.mtx >> BICGintoX60to63rangeNis800/60to63result_gre_512.txt
mkdir BICGintoR56to59rangeNis200