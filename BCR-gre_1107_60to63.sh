#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR60to63rangeNis200
./mainbcr 5 1107 200 60 63 0 gre_1107.mtx >> BICGintoR60to63rangeNis200/BCR-60to63result_gre_1107.txt
mkdir BICGintoR60to63rangeNis400
./mainbcr 5 1107 400 60 63 0 gre_1107.mtx >> BICGintoR60to63rangeNis400/BCR-60to63result_gre_1107.txt
mkdir BICGintoR60to63rangeNis600
./mainbcr 5 1107 600 60 63 0 gre_1107.mtx >> BICGintoR60to63rangeNis600/BCR-60to63result_gre_1107.txt
mkdir BICGintoR60to63rangeNis800
./mainbcr 5 1107 800 60 63 0 gre_1107.mtx >> BICGintoR60to63rangeNis800/BCR-60to63result_gre_1107.txt
mkdir BICGintoP60to63rangeNis200
./mainbcr 5 1107 200 60 63 1 gre_1107.mtx >> BICGintoP60to63rangeNis200/BCR-60to63result_gre_1107.txt
mkdir BICGintoP60to63rangeNis400
./mainbcr 5 1107 400 60 63 1 gre_1107.mtx >> BICGintoP60to63rangeNis400/BCR-60to63result_gre_1107.txt
mkdir BICGintoP60to63rangeNis600
./mainbcr 5 1107 600 60 63 1 gre_1107.mtx >> BICGintoP60to63rangeNis600/BCR-60to63result_gre_1107.txt
mkdir BICGintoP60to63rangeNis800
./mainbcr 5 1107 800 60 63 1 gre_1107.mtx >> BICGintoP60to63rangeNis800/BCR-60to63result_gre_1107.txt
mkdir BICGintoX60to63rangeNis200
./mainbcr 5 1107 200 60 63 2 gre_1107.mtx >> BICGintoX60to63rangeNis200/BCR-60to63result_gre_1107.txt
mkdir BICGintoX60to63rangeNis400
./mainbcr 5 1107 400 60 63 2 gre_1107.mtx >> BICGintoX60to63rangeNis400/BCR-60to63result_gre_1107.txt
mkdir BICGintoX60to63rangeNis600
./mainbcr 5 1107 600 60 63 2 gre_1107.mtx >> BICGintoX60to63rangeNis600/BCR-60to63result_gre_1107.txt
mkdir BICGintoX60to63rangeNis800
./mainbcr 5 1107 800 60 63 2 gre_1107.mtx >> BICGintoX60to63rangeNis800/BCR-60to63result_gre_1107.txt
