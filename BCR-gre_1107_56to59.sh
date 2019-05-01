#!/bin/bash
#SBATCH --time=23:59:00
./mainbcr 5 1107 200 56 59 0 gre_1107.mtx >> BICGintoR56to59rangeNis200/BCR-56to59result_gre_1107.txt
mkdir BICGintoR56to59rangeNis400
./mainbcr 5 1107 400 56 59 0 gre_1107.mtx >> BICGintoR56to59rangeNis400/BCR-56to59result_gre_1107.txt
mkdir BICGintoR56to59rangeNis600
./mainbcr 5 1107 600 56 59 0 gre_1107.mtx >> BICGintoR56to59rangeNis600/BCR-56to59result_gre_1107.txt
mkdir BICGintoR56to59rangeNis800
./mainbcr 5 1107 800 56 59 0 gre_1107.mtx >> BICGintoR56to59rangeNis800/BCR-56to59result_gre_1107.txt
mkdir BICGintoP56to59rangeNis200
./mainbcr 5 1107 200 56 59 1 gre_1107.mtx >> BICGintoP56to59rangeNis200/BCR-56to59result_gre_1107.txt
mkdir BICGintoP56to59rangeNis400
./mainbcr 5 1107 400 56 59 1 gre_1107.mtx >> BICGintoP56to59rangeNis400/BCR-56to59result_gre_1107.txt
mkdir BICGintoP56to59rangeNis600
./mainbcr 5 1107 600 56 59 1 gre_1107.mtx >> BICGintoP56to59rangeNis600/BCR-56to59result_gre_1107.txt
mkdir BICGintoP56to59rangeNis800
./mainbcr 5 1107 800 56 59 1 gre_1107.mtx >> BICGintoP56to59rangeNis800/BCR-56to59result_gre_1107.txt
mkdir BICGintoX56to59rangeNis200
./mainbcr 5 1107 200 56 59 2 gre_1107.mtx >> BICGintoX56to59rangeNis200/BCR-56to59result_gre_1107.txt
mkdir BICGintoX56to59rangeNis400
./mainbcr 5 1107 400 56 59 2 gre_1107.mtx >> BICGintoX56to59rangeNis400/BCR-56to59result_gre_1107.txt
mkdir BICGintoX56to59rangeNis600
./mainbcr 5 1107 600 56 59 2 gre_1107.mtx >> BICGintoX56to59rangeNis600/BCR-56to59result_gre_1107.txt
mkdir BICGintoX56to59rangeNis800
./mainbcr 5 1107 800 56 59 2 gre_1107.mtx >> BICGintoX56to59rangeNis800/BCR-56to59result_gre_1107.txt