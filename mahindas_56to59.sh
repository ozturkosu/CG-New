#!/bin/bash
#SBATCH --time=23:59:00
./mainbcg 5 1258 200 56 59 0 mahindas.mtx >> BICGintoR56to59rangeNis200/56to59result_mahindas.txt
mkdir BICGintoR56to59rangeNis400
./mainbcg 5 1258 400 56 59 0 mahindas.mtx >> BICGintoR56to59rangeNis400/56to59result_mahindas.txt
mkdir BICGintoR56to59rangeNis600
./mainbcg 5 1258 600 56 59 0 mahindas.mtx >> BICGintoR56to59rangeNis600/56to59result_mahindas.txt
mkdir BICGintoR56to59rangeNis800
./mainbcg 5 1258 800 56 59 0 mahindas.mtx >> BICGintoR56to59rangeNis800/56to59result_mahindas.txt
mkdir BICGintoP56to59rangeNis200
./mainbcg 5 1258 200 56 59 1 mahindas.mtx >> BICGintoP56to59rangeNis200/56to59result_mahindas.txt
mkdir BICGintoP56to59rangeNis400
./mainbcg 5 1258 400 56 59 1 mahindas.mtx >> BICGintoP56to59rangeNis400/56to59result_mahindas.txt
mkdir BICGintoP56to59rangeNis600
./mainbcg 5 1258 600 56 59 1 mahindas.mtx >> BICGintoP56to59rangeNis600/56to59result_mahindas.txt
mkdir BICGintoP56to59rangeNis800
./mainbcg 5 1258 800 56 59 1 mahindas.mtx >> BICGintoP56to59rangeNis800/56to59result_mahindas.txt
mkdir BICGintoX56to59rangeNis200
./mainbcg 5 1258 200 56 59 2 mahindas.mtx >> BICGintoX56to59rangeNis200/56to59result_mahindas.txt
mkdir BICGintoX56to59rangeNis400
./mainbcg 5 1258 400 56 59 2 mahindas.mtx >> BICGintoX56to59rangeNis400/56to59result_mahindas.txt
mkdir BICGintoX56to59rangeNis600
./mainbcg 5 1258 600 56 59 2 mahindas.mtx >> BICGintoX56to59rangeNis600/56to59result_mahindas.txt
mkdir BICGintoX56to59rangeNis800
./mainbcg 5 1258 800 56 59 2 mahindas.mtx >> BICGintoX56to59rangeNis800/56to59result_mahindas.txt