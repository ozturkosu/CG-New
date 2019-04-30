#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR52to55rangeNis200
./mainbcg 5 512 100 52 55 0 gre_512.mtx >> BICGintoR52to55rangeNis200/52to55result_gre_512.txt
mkdir BICGintoR52to55rangeNis400
./mainbcg 5 512 200 52 55 0 gre_512.mtx >> BICGintoR52to55rangeNis400/52to55result_gre_512.txt
mkdir BICGintoR52to55rangeNis600
./mainbcg 5 512 300 52 55 0 gre_512.mtx >> BICGintoR52to55rangeNis600/52to55result_gre_512.txt
mkdir BICGintoR52to55rangeNis800
./mainbcg 5 512 400 52 55 0 gre_512.mtx >> BICGintoR52to55rangeNis800/52to55result_gre_512.txt
mkdir BICGintoP52to55rangeNis200
./mainbcg 5 512 100 52 55 1 gre_512.mtx >> BICGintoP52to55rangeNis200/52to55result_gre_512.txt
mkdir BICGintoP52to55rangeNis400
./mainbcg 5 512 200 52 55 1 gre_512.mtx >> BICGintoP52to55rangeNis400/52to55result_gre_512.txt
mkdir BICGintoP52to55rangeNis600
./mainbcg 5 512 300 52 55 1 gre_512.mtx >> BICGintoP52to55rangeNis600/52to55result_gre_512.txt
mkdir BICGintoP52to55rangeNis800
./mainbcg 5 512 400 52 55 1 gre_512.mtx >> BICGintoP52to55rangeNis800/52to55result_gre_512.txt
mkdir BICGintoX52to55rangeNis200
./mainbcg 5 512 100 52 55 2 gre_512.mtx >> BICGintoX52to55rangeNis200/52to55result_gre_512.txt
mkdir BICGintoX52to55rangeNis400
./mainbcg 5 512 200 52 55 2 gre_512.mtx >> BICGintoX52to55rangeNis400/52to55result_gre_512.txt
mkdir BICGintoX52to55rangeNis600
./mainbcg 5 512 300 52 55 2 gre_512.mtx >> BICGintoX52to55rangeNis600/52to55result_gre_512.txt
mkdir BICGintoX52to55rangeNis800
./mainbcg 5 512 400 52 55 2 gre_512.mtx >> BICGintoX52to55rangeNis800/52to55result_gre_512.txt
