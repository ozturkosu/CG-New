#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR56to59rangeNis200
./mainbcr 5 512 100 56 59 0 gre_512.mtx >> BICGintoR56to59rangeNis200/BCR-56to59result_gre_512.txt
mkdir BICGintoR56to59rangeNis400
./mainbcr 5 512 200 56 59 0 gre_512.mtx >> BICGintoR56to59rangeNis400/BCR-56to59result_gre_512.txt
mkdir BICGintoR56to59rangeNis600
./mainbcr 5 512 300 56 59 0 gre_512.mtx >> BICGintoR56to59rangeNis600/BCR-56to59result_gre_512.txt
mkdir BICGintoR56to59rangeNis800
./mainbcr 5 512 400 56 59 0 gre_512.mtx >> BICGintoR56to59rangeNis800/BCR-56to59result_gre_512.txt
mkdir BICGintoP56to59rangeNis200
./mainbcr 5 512 100 56 59 1 gre_512.mtx >> BICGintoP56to59rangeNis200/BCR-56to59result_gre_512.txt
mkdir BICGintoP56to59rangeNis400
./mainbcr 5 512 200 56 59 1 gre_512.mtx >> BICGintoP56to59rangeNis400/BCR-56to59result_gre_512.txt
mkdir BICGintoP56to59rangeNis600
./mainbcr 5 512 300 56 59 1 gre_512.mtx >> BICGintoP56to59rangeNis600/BCR-56to59result_gre_512.txt
mkdir BICGintoP56to59rangeNis800
./mainbcr 5 512 400 56 59 1 gre_512.mtx >> BICGintoP56to59rangeNis800/BCR-56to59result_gre_512.txt
mkdir BICGintoX56to59rangeNis200
./mainbcr 5 512 100 56 59 2 gre_512.mtx >> BICGintoX56to59rangeNis200/BCR-56to59result_gre_512.txt
mkdir BICGintoX56to59rangeNis400
./mainbcr 5 512 200 56 59 2 gre_512.mtx >> BICGintoX56to59rangeNis400/BCR-56to59result_gre_512.txt
mkdir BICGintoX56to59rangeNis600
./mainbcr 5 512 300 56 59 2 gre_512.mtx >> BICGintoX56to59rangeNis600/BCR-56to59result_gre_512.txt
mkdir BICGintoX56to59rangeNis800
./mainbcr 5 512 400 56 59 2 gre_512.mtx >> BICGintoX56to59rangeNis800/BCR-56to59result_gre_512.txt
