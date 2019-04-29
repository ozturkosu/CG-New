#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./maingcr 5 420 84 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis400
./maingcr 5 420 168 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis600
./maingcr 5 420 252 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis800
./maingcr 5 420 336 60 63 0 bcsstk06.mtx >> CRintoR60to63rangeNis800/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis200
./maingcr 5 420 84 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis400
./maingcr 5 420 168 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis600
./maingcr 5 420 252 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoP60to63rangeNis800
./maingcr 5 420 336 60 63 1 bcsstk06.mtx >> CRintoP60to63rangeNis800/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis200
./maingcr 5 420 84 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis200/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis400
./maingcr 5 420 168 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis400/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis600
./maingcr 5 420 252 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis600/residual60to63result_bcsstk06.txt
mkdir CRintoX60to63rangeNis800
./maingcr 5 420 336 60 63 2 bcsstk06.mtx >> CRintoX60to63rangeNis800/residual60to63result_bcsstk06.txt
mkdir CRintoR60to63rangeNis200
./maingcr 5 112 20 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CRintoR60to63rangeNis400
./maingcr 5 112 40 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CRintoR60to63rangeNis600
./maingcr 5 112 60 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CRintoR60to63rangeNis800
./maingcr 5 112 80 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CRintoP60to63rangeNis200
./maingcr 5 112 20 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CRintoP60to63rangeNis400
./maingcr 5 112 40 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CRintoP60to63rangeNis600
./maingcr 5 112 60 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CRintoP60to63rangeNis800
./maingcr 5 112 80 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CRintoX60to63rangeNis200
./maingcr 5 112 20 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CRintoX60to63rangeNis400
./maingcr 5 112 40 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CRintoX60to63rangeNis600
./maingcr 5 112 60 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CRintoX60to63rangeNis800
./maingcr 5 112 80 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CRintoR60to63rangeNis200
./maingcr 5 1473 280 60 63 0 bcsstm12.mtx >> CRintoR60to63rangeNis200/residual60to63result_bcsstm12.txt
mkdir CRintoR60to63rangeNis400
./maingcr 5 1473 560 60 63 0 bcsstm12.mtx >> CRintoR60to63rangeNis400/residual60to63result_bcsstm12.txt
mkdir CRintoR60to63rangeNis600
./maingcr 5 1473 720 60 63 0 bcsstm12.mtx >> CRintoR60to63rangeNis600/residual60to63result_bcsstm12.txt
mkdir CRintoR60to63rangeNis800
./maingcr 5 1473 1120 60 63 0 bcsstm12.mtx >> CRintoR60to63rangeNis800/residual60to63result_bcsstm12.txt
mkdir CRintoP60to63rangeNis200
./maingcr 5 1473 280 60 63 1 bcsstm12.mtx >> CRintoP60to63rangeNis200/residual60to63result_bcsstm12.txt
mkdir CRintoP60to63rangeNis400
./maingcr 5 1473 560 60 63 1 bcsstm12.mtx >> CRintoP60to63rangeNis400/residual60to63result_bcsstm12.txt
mkdir CRintoP60to63rangeNis600
./maingcr 5 1473 720 60 63 1 bcsstm12.mtx >> CRintoP60to63rangeNis600/residual60to63result_bcsstm12.txt
mkdir CRintoP60to63rangeNis800
./maingcr 5 1473 1120 60 63 1 bcsstm12.mtx >> CRintoP60to63rangeNis800/residual60to63result_bcsstm12.txt
mkdir CRintoX60to63rangeNis200
./maingcr 5 1473 280 60 63 2 bcsstm12.mtx >> CRintoX60to63rangeNis200/residual60to63result_bcsstm12.txt
mkdir CRintoX60to63rangeNis400
./maingcr 5 1473 560 60 63 2 bcsstm12.mtx >> CRintoX60to63rangeNis400/residual60to63result_bcsstm12.txt
mkdir CRintoX60to63rangeNis600
./maingcr 5 1473 720 60 63 2 bcsstm12.mtx >> CRintoX60to63rangeNis600/residual60to63result_bcsstm12.txt
mkdir CRintoX60to63rangeNis800
./maingcr 5 1473 1120 60 63 2 bcsstm12.mtx >> CRintoX60to63rangeNis800/residual60to63result_bcsstm12.txt
 