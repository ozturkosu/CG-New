#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./mainCGEnergyDefault 5 112 22 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis200/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoR60to63rangeNis400
./mainCGEnergyDefault 5 112 44 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis400/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoR60to63rangeNis600
./mainCGEnergyDefault 5 112 66 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis600/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoR60to63rangeNis800
./mainCGEnergyDefault 5 112 88 60 63 0 bcsstk03.mtx >> CRintoR60to63rangeNis800/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoP60to63rangeNis200
./mainCGEnergyDefault 5 112 22 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis200/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoP60to63rangeNis400
./mainCGEnergyDefault 5 112 44 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis400/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoP60to63rangeNis600
./mainCGEnergyDefault 5 112 66 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis600/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoP60to63rangeNis800
./mainCGEnergyDefault 5 112 88 60 63 1 bcsstk03.mtx >> CRintoP60to63rangeNis800/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoX60to63rangeNis200
./mainCGEnergyDefault 5 112 22 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis200/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoX60to63rangeNis400
./mainCGEnergyDefault 5 112 44 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis400/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoX60to63rangeNis600
./mainCGEnergyDefault 5 112 66 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis600/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoX60to63rangeNis800
./mainCGEnergyDefault 5 112 88 60 63 2 bcsstk03.mtx >> CRintoX60to63rangeNis800/residual60to63result_RelativeError_bcsstk03.txt
mkdir CRintoR56to59rangeNis200
./mainCGEnergyDefault 5 112 22 56 59 0 bcsstk03.mtx >> CRintoR56to59rangeNis200/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoR56to59rangeNis400
./mainCGEnergyDefault 5 112 44 56 59 0 bcsstk03.mtx >> CRintoR56to59rangeNis400/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoR56to59rangeNis600
./mainCGEnergyDefault 5 112 66 56 59 0 bcsstk03.mtx >> CRintoR56to59rangeNis600/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoR56to59rangeNis800
./mainCGEnergyDefault 5 112 88 56 59 0 bcsstk03.mtx >> CRintoR56to59rangeNis800/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoP56to59rangeNis200
./mainCGEnergyDefault 5 112 22 56 59 1 bcsstk03.mtx >> CRintoP56to59rangeNis200/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoP56to59rangeNis400
./mainCGEnergyDefault 5 112 44 56 59 1 bcsstk03.mtx >> CRintoP56to59rangeNis400/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoP56to59rangeNis600
./mainCGEnergyDefault 5 112 66 56 59 1 bcsstk03.mtx >> CRintoP56to59rangeNis600/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoP56to59rangeNis800
./mainCGEnergyDefault 5 112 88 56 59 1 bcsstk03.mtx >> CRintoP56to59rangeNis800/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoX56to59rangeNis200
./mainCGEnergyDefault 5 112 22 56 59 2 bcsstk03.mtx >> CRintoX56to59rangeNis200/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoX56to59rangeNis400
./mainCGEnergyDefault 5 112 44 56 59 2 bcsstk03.mtx >> CRintoX56to59rangeNis400/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoX56to59rangeNis600
./mainCGEnergyDefault 5 112 66 56 59 2 bcsstk03.mtx >> CRintoX56to59rangeNis600/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoX56to59rangeNis800
./mainCGEnergyDefault 5 112 88 56 59 2 bcsstk03.mtx >> CRintoX56to59rangeNis800/residual56to63result_RelativeError_bcsstk03.txt
mkdir CRintoR52to55rangeNis200
./mainCGEnergyDefault 5 112 22 52 55 0 bcsstk03.mtx >> CRintoR52to55rangeNis200/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoR52to55rangeNis400
./mainCGEnergyDefault 5 112 44 52 55 0 bcsstk03.mtx >> CRintoR52to55rangeNis400/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoR52to55rangeNis600
./mainCGEnergyDefault 5 112 66 52 55 0 bcsstk03.mtx >> CRintoR52to55rangeNis600/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoR52to55rangeNis800
./mainCGEnergyDefault 5 112 88 52 55 0 bcsstk03.mtx >> CRintoR52to55rangeNis800/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoP52to55rangeNis200
./mainCGEnergyDefault 5 112 22 52 55 1 bcsstk03.mtx >> CRintoP52to55rangeNis200/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoP52to55rangeNis400
./mainCGEnergyDefault 5 112 44 52 55 1 bcsstk03.mtx >> CRintoP52to55rangeNis400/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoP52to55rangeNis600
./mainCGEnergyDefault 5 112 66 52 55 1 bcsstk03.mtx >> CRintoP52to55rangeNis600/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoP52to55rangeNis800
./mainCGEnergyDefault 5 112 88 52 55 1 bcsstk03.mtx >> CRintoP52to55rangeNis800/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoX52to55rangeNis200
./mainCGEnergyDefault 5 112 22 52 55 2 bcsstk03.mtx >> CRintoX52to55rangeNis200/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoX52to55rangeNis400
./mainCGEnergyDefault 5 112 44 52 55 2 bcsstk03.mtx >> CRintoX52to55rangeNis400/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoX52to55rangeNis600
./mainCGEnergyDefault 5 112 66 52 55 2 bcsstk03.mtx >> CRintoX52to55rangeNis600/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoX52to55rangeNis800
./mainCGEnergyDefault 5 112 88 52 55 2 bcsstk03.mtx >> CRintoX52to55rangeNis800/residual52to55result_RelativeError_bcsstk03.txt
mkdir CRintoR48to51rangeNis200
./mainCGEnergyDefault 5 112 22 48 51 0 bcsstk03.mtx >> CRintoR48to51rangeNis200/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoR48to51rangeNis400
./mainCGEnergyDefault 5 112 44 48 51 0 bcsstk03.mtx >> CRintoR48to51rangeNis400/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoR48to51rangeNis600
./mainCGEnergyDefault 5 112 66 48 51 0 bcsstk03.mtx >> CRintoR48to51rangeNis600/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoR48to51rangeNis800
./mainCGEnergyDefault 5 112 88 48 51 0 bcsstk03.mtx >> CRintoR48to51rangeNis800/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoP48to51rangeNis200
./mainCGEnergyDefault 5 112 22 48 51 1 bcsstk03.mtx >> CRintoP48to51rangeNis200/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoP48to51rangeNis400
./mainCGEnergyDefault 5 112 44 48 51 1 bcsstk03.mtx >> CRintoP48to51rangeNis400/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoP48to51rangeNis600
./mainCGEnergyDefault 5 112 66 48 51 1 bcsstk03.mtx >> CRintoP48to51rangeNis600/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoP48to51rangeNis800
./mainCGEnergyDefault 5 112 88 48 51 1 bcsstk03.mtx >> CRintoP48to51rangeNis800/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoX48to51rangeNis200
./mainCGEnergyDefault 5 112 22 48 51 2 bcsstk03.mtx >> CRintoX48to51rangeNis200/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoX48to51rangeNis400
./mainCGEnergyDefault 5 112 44 48 51 2 bcsstk03.mtx >> CRintoX48to51rangeNis400/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoX48to51rangeNis600
./mainCGEnergyDefault 5 112 66 48 51 2 bcsstk03.mtx >> CRintoX48to51rangeNis600/residual48to51result_RelativeError_bcsstk03.txt
mkdir CRintoX48to51rangeNis800
./mainCGEnergyDefault 5 112 88 48 51 2 bcsstk03.mtx >> CRintoX48to51rangeNis800/residual48to51result_RelativeError_bcsstk03.txt
 