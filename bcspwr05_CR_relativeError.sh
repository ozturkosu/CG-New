#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./mainCGEnergyDefault 5 443 80 60 63 0 bcspwr05.mtx >> CRintoR60to63rangeNis200/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoR60to63rangeNis400
./mainCGEnergyDefault 5 443 160 60 63 0 bcspwr05.mtx >> CRintoR60to63rangeNis400/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoR60to63rangeNis600
./mainCGEnergyDefault 5 443 240 60 63 0 bcspwr05.mtx >> CRintoR60to63rangeNis600/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoR60to63rangeNis800
./mainCGEnergyDefault 5 443 320 60 63 0 bcspwr05.mtx >> CRintoR60to63rangeNis800/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoP60to63rangeNis200
./mainCGEnergyDefault 5 443 80 60 63 1 bcspwr05.mtx >> CRintoP60to63rangeNis200/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoP60to63rangeNis400
./mainCGEnergyDefault 5 443 160 60 63 1 bcspwr05.mtx >> CRintoP60to63rangeNis400/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoP60to63rangeNis600
./mainCGEnergyDefault 5 443 240 60 63 1 bcspwr05.mtx >> CRintoP60to63rangeNis600/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoP60to63rangeNis800
./mainCGEnergyDefault 5 443 320 60 63 1 bcspwr05.mtx >> CRintoP60to63rangeNis800/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoX60to63rangeNis200
./mainCGEnergyDefault 5 443 80 60 63 2 bcspwr05.mtx >> CRintoX60to63rangeNis200/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoX60to63rangeNis400
./mainCGEnergyDefault 5 443 160 60 63 2 bcspwr05.mtx >> CRintoX60to63rangeNis400/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoX60to63rangeNis600
./mainCGEnergyDefault 5 443 240 60 63 2 bcspwr05.mtx >> CRintoX60to63rangeNis600/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoX60to63rangeNis800
./mainCGEnergyDefault 5 443 320 60 63 2 bcspwr05.mtx >> CRintoX60to63rangeNis800/residual60to63result_RelativeError_bcspwr05.txt
mkdir CRintoR56to59rangeNis200
./mainCGEnergyDefault 5 443 80 56 59 0 bcspwr05.mtx >> CRintoR56to59rangeNis200/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoR56to59rangeNis400
./mainCGEnergyDefault 5 443 160 56 59 0 bcspwr05.mtx >> CRintoR56to59rangeNis400/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoR56to59rangeNis600
./mainCGEnergyDefault 5 443 240 56 59 0 bcspwr05.mtx >> CRintoR56to59rangeNis600/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoR56to59rangeNis800
./mainCGEnergyDefault 5 443 320 56 59 0 bcspwr05.mtx >> CRintoR56to59rangeNis800/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoP56to59rangeNis200
./mainCGEnergyDefault 5 443 80 56 59 1 bcspwr05.mtx >> CRintoP56to59rangeNis200/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoP56to59rangeNis400
./mainCGEnergyDefault 5 443 160 56 59 1 bcspwr05.mtx >> CRintoP56to59rangeNis400/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoP56to59rangeNis600
./mainCGEnergyDefault 5 443 240 56 59 1 bcspwr05.mtx >> CRintoP56to59rangeNis600/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoP56to59rangeNis800
./mainCGEnergyDefault 5 443 320 56 59 1 bcspwr05.mtx >> CRintoP56to59rangeNis800/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoX56to59rangeNis200
./mainCGEnergyDefault 5 443 80 56 59 2 bcspwr05.mtx >> CRintoX56to59rangeNis200/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoX56to59rangeNis400
./mainCGEnergyDefault 5 443 160 56 59 2 bcspwr05.mtx >> CRintoX56to59rangeNis400/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoX56to59rangeNis600
./mainCGEnergyDefault 5 443 240 56 59 2 bcspwr05.mtx >> CRintoX56to59rangeNis600/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoX56to59rangeNis800
./mainCGEnergyDefault 5 443 320 56 59 2 bcspwr05.mtx >> CRintoX56to59rangeNis800/residual56to63result_RelativeError_bcspwr05.txt
mkdir CRintoR52to55rangeNis200
./mainCGEnergyDefault 5 443 80 52 55 0 bcspwr05.mtx >> CRintoR52to55rangeNis200/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoR52to55rangeNis400
./mainCGEnergyDefault 5 443 160 52 55 0 bcspwr05.mtx >> CRintoR52to55rangeNis400/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoR52to55rangeNis600
./mainCGEnergyDefault 5 443 240 52 55 0 bcspwr05.mtx >> CRintoR52to55rangeNis600/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoR52to55rangeNis800
./mainCGEnergyDefault 5 443 320 52 55 0 bcspwr05.mtx >> CRintoR52to55rangeNis800/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoP52to55rangeNis200
./mainCGEnergyDefault 5 443 80 52 55 1 bcspwr05.mtx >> CRintoP52to55rangeNis200/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoP52to55rangeNis400
./mainCGEnergyDefault 5 443 160 52 55 1 bcspwr05.mtx >> CRintoP52to55rangeNis400/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoP52to55rangeNis600
./mainCGEnergyDefault 5 443 240 52 55 1 bcspwr05.mtx >> CRintoP52to55rangeNis600/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoP52to55rangeNis800
./mainCGEnergyDefault 5 443 320 52 55 1 bcspwr05.mtx >> CRintoP52to55rangeNis800/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoX52to55rangeNis200
./mainCGEnergyDefault 5 443 80 52 55 2 bcspwr05.mtx >> CRintoX52to55rangeNis200/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoX52to55rangeNis400
./mainCGEnergyDefault 5 443 160 52 55 2 bcspwr05.mtx >> CRintoX52to55rangeNis400/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoX52to55rangeNis600
./mainCGEnergyDefault 5 443 240 52 55 2 bcspwr05.mtx >> CRintoX52to55rangeNis600/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoX52to55rangeNis800
./mainCGEnergyDefault 5 443 320 52 55 2 bcspwr05.mtx >> CRintoX52to55rangeNis800/residual52to55result_RelativeError_bcspwr05.txt
mkdir CRintoR48to51rangeNis200
./mainCGEnergyDefault 5 443 80 48 51 0 bcspwr05.mtx >> CRintoR48to51rangeNis200/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoR48to51rangeNis400
./mainCGEnergyDefault 5 443 160 48 51 0 bcspwr05.mtx >> CRintoR48to51rangeNis400/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoR48to51rangeNis600
./mainCGEnergyDefault 5 443 240 48 51 0 bcspwr05.mtx >> CRintoR48to51rangeNis600/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoR48to51rangeNis800
./mainCGEnergyDefault 5 443 320 48 51 0 bcspwr05.mtx >> CRintoR48to51rangeNis800/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoP48to51rangeNis200
./mainCGEnergyDefault 5 443 80 48 51 1 bcspwr05.mtx >> CRintoP48to51rangeNis200/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoP48to51rangeNis400
./mainCGEnergyDefault 5 443 160 48 51 1 bcspwr05.mtx >> CRintoP48to51rangeNis400/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoP48to51rangeNis600
./mainCGEnergyDefault 5 443 240 48 51 1 bcspwr05.mtx >> CRintoP48to51rangeNis600/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoP48to51rangeNis800
./mainCGEnergyDefault 5 443 320 48 51 1 bcspwr05.mtx >> CRintoP48to51rangeNis800/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoX48to51rangeNis200
./mainCGEnergyDefault 5 443 80 48 51 2 bcspwr05.mtx >> CRintoX48to51rangeNis200/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoX48to51rangeNis400
./mainCGEnergyDefault 5 443 160 48 51 2 bcspwr05.mtx >> CRintoX48to51rangeNis400/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoX48to51rangeNis600
./mainCGEnergyDefault 5 443 240 48 51 2 bcspwr05.mtx >> CRintoX48to51rangeNis600/residual48to51result_RelativeError_bcspwr05.txt
mkdir CRintoX48to51rangeNis800
./mainCGEnergyDefault 5 443 320 48 51 2 bcspwr05.mtx >> CRintoX48to51rangeNis800/residual48to51result_RelativeError_bcspwr05.txt
 