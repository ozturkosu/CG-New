#!/bin/bash
#SBATCH --time=23:59:00
mkdir BICGintoR52to55rangeNis200
./mainbcg 5 1258 200 52 55 0 mahindas.mtx >> BICGintoR52to55rangeNis200/52to55result_mahindas.txt
mkdir BICGintoR52to55rangeNis400
./mainbcg 5 1258 400 52 55 0 mahindas.mtx >> BICGintoR52to55rangeNis400/52to55result_mahindas.txt
mkdir BICGintoR52to55rangeNis600
./mainbcg 5 1258 600 52 55 0 mahindas.mtx >> BICGintoR52to55rangeNis600/52to55result_mahindas.txt
mkdir BICGintoR52to55rangeNis800
./mainbcg 5 1258 800 52 55 0 mahindas.mtx >> BICGintoR52to55rangeNis800/52to55result_mahindas.txt
mkdir BICGintoP52to55rangeNis200
./mainbcg 5 1258 200 52 55 1 mahindas.mtx >> BICGintoP52to55rangeNis200/52to55result_mahindas.txt
mkdir BICGintoP52to55rangeNis400
./mainbcg 5 1258 400 52 55 1 mahindas.mtx >> BICGintoP52to55rangeNis400/52to55result_mahindas.txt
mkdir BICGintoP52to55rangeNis600
./mainbcg 5 1258 600 52 55 1 mahindas.mtx >> BICGintoP52to55rangeNis600/52to55result_mahindas.txt
mkdir BICGintoP52to55rangeNis800
./mainbcg 5 1258 800 52 55 1 mahindas.mtx >> BICGintoP52to55rangeNis800/52to55result_mahindas.txt
mkdir BICGintoX60to63rangeNis200
./mainbcg 5 1258 200 52 55 2 mahindas.mtx >> BICGintoX52to55rangeNis200/52to55result_mahindas.txt
mkdir BICGintoX60to63rangeNis400
./mainbcg 5 1258 400 52 55 2 mahindas.mtx >> BICGintoX52to55rangeNis400/52to55result_mahindas.txt
mkdir BICGintoX60to63rangeNis600
./mainbcg 5 1258 600 52 55 2 mahindas.mtx >> BICGintoX52to55rangeNis600/52to55result_mahindas.txt
mkdir BICGintoX60to63rangeNis800
./mainbcg 5 1258 800 52 55 2 mahindas.mtx >> BICGintoX52to55rangeNis800/52to55result_mahindas.txt