#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR52to55rangeNis200
./mainbcr 5 1107 200 52 55 0 gre_1107.mtx >> BICGintoR52to55rangeNis200/BCR-52to55result_gre_1107.txt
mkdir BICGintoR52to55rangeNis400
./mainbcr 5 1107 400 52 55 0 gre_1107.mtx >> BICGintoR52to55rangeNis400/BCR-52to55result_gre_1107.txt
mkdir BICGintoR52to55rangeNis600
./mainbcr 5 1107 600 52 55 0 gre_1107.mtx >> BICGintoR52to55rangeNis600/BCR-52to55result_gre_1107.txt
mkdir BICGintoR52to55rangeNis800
./mainbcr 5 1107 800 52 55 0 gre_1107.mtx >> BICGintoR52to55rangeNis800/BCR-52to55result_gre_1107.txt
mkdir BICGintoP52to55rangeNis200
./mainbcr 5 1107 200 52 55 1 gre_1107.mtx >> BICGintoP52to55rangeNis200/BCR-52to55result_gre_1107.txt
mkdir BICGintoP52to55rangeNis400
./mainbcr 5 1107 400 52 55 1 gre_1107.mtx >> BICGintoP52to55rangeNis400/BCR-52to55result_gre_1107.txt
mkdir BICGintoP52to55rangeNis600
./mainbcr 5 1107 600 52 55 1 gre_1107.mtx >> BICGintoP52to55rangeNis600/BCR-52to55result_gre_1107.txt
mkdir BICGintoP52to55rangeNis800
./mainbcr 5 1107 800 52 55 1 gre_1107.mtx >> BICGintoP52to55rangeNis800/BCR-52to55result_gre_1107.txt
mkdir BICGintoX60to63rangeNis200
./mainbcr 5 1107 200 52 55 2 gre_1107.mtx >> BICGintoX52to55rangeNis200/BCR-52to55result_gre_1107.txt
mkdir BICGintoX60to63rangeNis400
./mainbcr 5 1107 400 52 55 2 gre_1107.mtx >> BICGintoX52to55rangeNis400/BCR-52to55result_gre_1107.txt
mkdir BICGintoX60to63rangeNis600
./mainbcr 5 1107 600 52 55 2 gre_1107.mtx >> BICGintoX52to55rangeNis600/BCR-52to55result_gre_1107.txt
mkdir BICGintoX60to63rangeNis800
./mainbcr 5 1107 800 52 55 2 gre_1107.mtx >> BICGintoX52to55rangeNis800/BCR-52to55result_gre_1107.txt