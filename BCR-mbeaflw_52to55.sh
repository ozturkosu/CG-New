#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR52to55rangeNis200
./mainbcr 5 512 100 52 55 0 mbeaflw.mtx >> BICGintoR52to55rangeNis200/BCR-52to55result_mbeaflw.txt
mkdir BICGintoR52to55rangeNis400
./mainbcr 5 512 200 52 55 0 mbeaflw.mtx >> BICGintoR52to55rangeNis400/BCR-52to55result_mbeaflw.txt
mkdir BICGintoR52to55rangeNis600
./mainbcr 5 512 300 52 55 0 mbeaflw.mtx >> BICGintoR52to55rangeNis600/BCR-52to55result_mbeaflw.txt
mkdir BICGintoR52to55rangeNis800
./mainbcr 5 512 400 52 55 0 mbeaflw.mtx >> BICGintoR52to55rangeNis800/BCR-52to55result_mbeaflw.txt
mkdir BICGintoP52to55rangeNis200
./mainbcr 5 512 100 52 55 1 mbeaflw.mtx >> BICGintoP52to55rangeNis200/BCR-52to55result_mbeaflw.txt
mkdir BICGintoP52to55rangeNis400
./mainbcr 5 512 200 52 55 1 mbeaflw.mtx >> BICGintoP52to55rangeNis400/BCR-52to55result_mbeaflw.txt
mkdir BICGintoP52to55rangeNis600
./mainbcr 5 512 300 52 55 1 mbeaflw.mtx >> BICGintoP52to55rangeNis600/BCR-52to55result_mbeaflw.txt
mkdir BICGintoP52to55rangeNis800
./mainbcr 5 512 400 52 55 1 mbeaflw.mtx >> BICGintoP52to55rangeNis800/BCR-52to55result_mbeaflw.txt
mkdir BICGintoX52to55rangeNis200
./mainbcr 5 512 100 52 55 2 mbeaflw.mtx >> BICGintoX52to55rangeNis200/BCR-52to55result_mbeaflw.txt
mkdir BICGintoX52to55rangeNis400
./mainbcr 5 512 200 52 55 2 mbeaflw.mtx >> BICGintoX52to55rangeNis400/BCR-52to55result_mbeaflw.txt
mkdir BICGintoX52to55rangeNis600
./mainbcr 5 512 300 52 55 2 mbeaflw.mtx >> BICGintoX52to55rangeNis600/BCR-52to55result_mbeaflw.txt
mkdir BICGintoX52to55rangeNis800
./mainbcr 5 512 400 52 55 2 mbeaflw.mtx >> BICGintoX52to55rangeNis800/BCR-52to55result_mbeaflw.txt
