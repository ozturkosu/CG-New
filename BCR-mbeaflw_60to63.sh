#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR60to63rangeNis200
./mainbcr 5 496 100 60 63 0 mbeaflw.mtx >> BICGintoR60to63rangeNis200/BCR-60to63result_mbeaflw.txt
mkdir BICGintoR60to63rangeNis400
./mainbcr 5 496 200 60 63 0 mbeaflw.mtx >> BICGintoR60to63rangeNis400/BCR-60to63result_mbeaflw.txt
mkdir BICGintoR60to63rangeNis600
./mainbcr 5 496 300 60 63 0 mbeaflw.mtx >> BICGintoR60to63rangeNis600/BCR-60to63result_mbeaflw.txt
mkdir BICGintoR60to63rangeNis800
./mainbcr 5 496 400 60 63 0 mbeaflw.mtx >> BICGintoR60to63rangeNis800/BCR-60to63result_mbeaflw.txt
mkdir BICGintoP60to63rangeNis200
./mainbcr 5 496 100 60 63 1 mbeaflw.mtx >> BICGintoP60to63rangeNis200/BCR-60to63result_mbeaflw.txt
mkdir BICGintoP60to63rangeNis400
./mainbcr 5 496 200 60 63 1 mbeaflw.mtx >> BICGintoP60to63rangeNis400/BCR-60to63result_mbeaflw.txt
mkdir BICGintoP60to63rangeNis600
./mainbcr 5 496 300 60 63 1 mbeaflw.mtx >> BICGintoP60to63rangeNis600/BCR-60to63result_mbeaflw.txt
mkdir BICGintoP60to63rangeNis800
./mainbcr 5 496 400 60 63 1 mbeaflw.mtx >> BICGintoP60to63rangeNis800/BCR-60to63result_mbeaflw.txt
mkdir BICGintoX60to63rangeNis200
./mainbcr 5 496 100 60 63 2 mbeaflw.mtx >> BICGintoX60to63rangeNis200/BCR-60to63result_mbeaflw.txt
mkdir BICGintoX60to63rangeNis400
./mainbcr 5 496 200 60 63 2 mbeaflw.mtx >> BICGintoX60to63rangeNis400/BCR-60to63result_mbeaflw.txt
mkdir BICGintoX60to63rangeNis600
./mainbcr 5 496 300 60 63 2 mbeaflw.mtx >> BICGintoX60to63rangeNis600/BCR-60to63result_mbeaflw.txt
mkdir BICGintoX60to63rangeNis800
./mainbcr 5 496 400 60 63 2 mbeaflw.mtx >> BICGintoX60to63rangeNis800/BCR-60to63result_mbeaflw.txt
