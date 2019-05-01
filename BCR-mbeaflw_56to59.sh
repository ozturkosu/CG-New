#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR56to59rangeNis200
./mainbcr 5 496 100 56 59 0 mbeaflw.mtx >> BICGintoR56to59rangeNis200/BCR-56to59result_mbeaflw.txt
mkdir BICGintoR56to59rangeNis400
./mainbcr 5 496 200 56 59 0 mbeaflw.mtx >> BICGintoR56to59rangeNis400/BCR-56to59result_mbeaflw.txt
mkdir BICGintoR56to59rangeNis600
./mainbcr 5 496 300 56 59 0 mbeaflw.mtx >> BICGintoR56to59rangeNis600/BCR-56to59result_mbeaflw.txt
mkdir BICGintoR56to59rangeNis800
./mainbcr 5 496 400 56 59 0 mbeaflw.mtx >> BICGintoR56to59rangeNis800/BCR-56to59result_mbeaflw.txt
mkdir BICGintoP56to59rangeNis200
./mainbcr 5 496 100 56 59 1 mbeaflw.mtx >> BICGintoP56to59rangeNis200/BCR-56to59result_mbeaflw.txt
mkdir BICGintoP56to59rangeNis400
./mainbcr 5 496 200 56 59 1 mbeaflw.mtx >> BICGintoP56to59rangeNis400/BCR-56to59result_mbeaflw.txt
mkdir BICGintoP56to59rangeNis600
./mainbcr 5 496 300 56 59 1 mbeaflw.mtx >> BICGintoP56to59rangeNis600/BCR-56to59result_mbeaflw.txt
mkdir BICGintoP56to59rangeNis800
./mainbcr 5 496 400 56 59 1 mbeaflw.mtx >> BICGintoP56to59rangeNis800/BCR-56to59result_mbeaflw.txt
mkdir BICGintoX56to59rangeNis200
./mainbcr 5 496 100 56 59 2 mbeaflw.mtx >> BICGintoX56to59rangeNis200/BCR-56to59result_mbeaflw.txt
mkdir BICGintoX56to59rangeNis400
./mainbcr 5 496 200 56 59 2 mbeaflw.mtx >> BICGintoX56to59rangeNis400/BCR-56to59result_mbeaflw.txt
mkdir BICGintoX56to59rangeNis600
./mainbcr 5 496 300 56 59 2 mbeaflw.mtx >> BICGintoX56to59rangeNis600/BCR-56to59result_mbeaflw.txt
mkdir BICGintoX56to59rangeNis800
./mainbcr 5 496 400 56 59 2 mbeaflw.mtx >> BICGintoX56to59rangeNis800/BCR-56to59result_mbeaflw.txt
