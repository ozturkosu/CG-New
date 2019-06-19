#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./maincr1 5 1086 240 60 63 0 bcsstm10.mtx >> CRintoR60to63rangeNis200/residual60to63result_bcsstm10.txt
mkdir CRintoR60to63rangeNis400
./maincr1 5 1086 480 60 63 0 bcsstm10.mtx >> CRintoR60to63rangeNis400/residual60to63result_bcsstm10.txt
mkdir CRintoR60to63rangeNis600
./maincr1 5 1086 720 60 63 0 bcsstm10.mtx >> CRintoR60to63rangeNis600/residual60to63result_bcsstm10.txt
mkdir CRintoR60to63rangeNis800
./maincr1 5 1086 960 60 63 0 bcsstm10.mtx >> CRintoR60to63rangeNis800/residual60to63result_bcsstm10.txt
mkdir CRintoP60to63rangeNis200
./maincr1 5 1086 240 60 63 1 bcsstm10.mtx >> CRintoP60to63rangeNis200/residual60to63result_bcsstm10.txt
mkdir CRintoP60to63rangeNis400
./maincr1 5 1086 480 60 63 1 bcsstm10.mtx >> CRintoP60to63rangeNis400/residual60to63result_bcsstm10.txt
mkdir CRintoP60to63rangeNis600
./maincr1 5 1086 720 60 63 1 bcsstm10.mtx >> CRintoP60to63rangeNis600/residual60to63result_bcsstm10.txt
mkdir CRintoP60to63rangeNis800
./maincr1 5 1086 960 60 63 1 bcsstm10.mtx >> CRintoP60to63rangeNis800/residual60to63result_bcsstm10.txt
mkdir CRintoX60to63rangeNis200
./maincr1 5 1086 240 60 63 2 bcsstm10.mtx >> CRintoX60to63rangeNis200/residual60to63result_bcsstm10.txt
mkdir CRintoX60to63rangeNis400
./maincr1 5 1086 480 60 63 2 bcsstm10.mtx >> CRintoX60to63rangeNis400/residual60to63result_bcsstm10.txt
mkdir CRintoX60to63rangeNis600
./maincr1 5 1086 720 60 63 2 bcsstm10.mtx >> CRintoX60to63rangeNis600/residual60to63result_bcsstm10.txt
mkdir CRintoX60to63rangeNis800
./maincr1 5 1086 960 60 63 2 bcsstm10.mtx >> CRintoX60to63rangeNis800/residual60to63result_bcsstm10.txt
mkdir CRintoR56to59rangeNis200
./maincr1 5 1086 240 56 59 0 bcsstm10.mtx >> CRintoR56to59rangeNis200/residual56to63result_bcsstm10.txt
mkdir CRintoR56to59rangeNis400
./maincr1 5 1086 480 56 59 0 bcsstm10.mtx >> CRintoR56to59rangeNis400/residual56to63result_bcsstm10.txt
mkdir CRintoR56to59rangeNis600
./maincr1 5 1086 720 56 59 0 bcsstm10.mtx >> CRintoR56to59rangeNis600/residual56to63result_bcsstm10.txt
mkdir CRintoR56to59rangeNis800
./maincr1 5 1086 960 56 59 0 bcsstm10.mtx >> CRintoR56to59rangeNis800/residual56to63result_bcsstm10.txt
mkdir CRintoP56to59rangeNis200
./maincr1 5 1086 240 56 59 1 bcsstm10.mtx >> CRintoP56to59rangeNis200/residual56to63result_bcsstm10.txt
mkdir CRintoP56to59rangeNis400
./maincr1 5 1086 480 56 59 1 bcsstm10.mtx >> CRintoP56to59rangeNis400/residual56to63result_bcsstm10.txt
mkdir CRintoP56to59rangeNis600
./maincr1 5 1086 720 56 59 1 bcsstm10.mtx >> CRintoP56to59rangeNis600/residual56to63result_bcsstm10.txt
mkdir CRintoP56to59rangeNis800
./maincr1 5 1086 960 56 59 1 bcsstm10.mtx >> CRintoP56to59rangeNis800/residual56to63result_bcsstm10.txt
mkdir CRintoX56to59rangeNis200
./maincr1 5 1086 240 56 59 2 bcsstm10.mtx >> CRintoX56to59rangeNis200/residual56to63result_bcsstm10.txt
mkdir CRintoX56to59rangeNis400
./maincr1 5 1086 480 56 59 2 bcsstm10.mtx >> CRintoX56to59rangeNis400/residual56to63result_bcsstm10.txt
mkdir CRintoX56to59rangeNis600
./maincr1 5 1086 720 56 59 2 bcsstm10.mtx >> CRintoX56to59rangeNis600/residual56to63result_bcsstm10.txt
mkdir CRintoX56to59rangeNis800
./maincr1 5 1086 960 56 59 2 bcsstm10.mtx >> CRintoX56to59rangeNis800/residual56to63result_bcsstm10.txt
mkdir CRintoR52to55rangeNis200
./maincr1 5 1086 240 52 55 0 bcsstm10.mtx >> CRintoR52to55rangeNis200/residual52to55result_bcsstm10.txt
mkdir CRintoR52to55rangeNis400
./maincr1 5 1086 480 52 55 0 bcsstm10.mtx >> CRintoR52to55rangeNis400/residual52to55result_bcsstm10.txt
mkdir CRintoR52to55rangeNis600
./maincr1 5 1086 720 52 55 0 bcsstm10.mtx >> CRintoR52to55rangeNis600/residual52to55result_bcsstm10.txt
mkdir CRintoR52to55rangeNis800
./maincr1 5 1086 960 52 55 0 bcsstm10.mtx >> CRintoR52to55rangeNis800/residual52to55result_bcsstm10.txt
mkdir CRintoP52to55rangeNis200
./maincr1 5 1086 240 52 55 1 bcsstm10.mtx >> CRintoP52to55rangeNis200/residual52to55result_bcsstm10.txt
mkdir CRintoP52to55rangeNis400
./maincr1 5 1086 480 52 55 1 bcsstm10.mtx >> CRintoP52to55rangeNis400/residual52to55result_bcsstm10.txt
mkdir CRintoP52to55rangeNis600
./maincr1 5 1086 720 52 55 1 bcsstm10.mtx >> CRintoP52to55rangeNis600/residual52to55result_bcsstm10.txt
mkdir CRintoP52to55rangeNis800
./maincr1 5 1086 960 52 55 1 bcsstm10.mtx >> CRintoP52to55rangeNis800/residual52to55result_bcsstm10.txt
mkdir CRintoX52to55rangeNis200
./maincr1 5 1086 240 52 55 2 bcsstm10.mtx >> CRintoX52to55rangeNis200/residual52to55result_bcsstm10.txt
mkdir CRintoX52to55rangeNis400
./maincr1 5 1086 480 52 55 2 bcsstm10.mtx >> CRintoX52to55rangeNis400/residual52to55result_bcsstm10.txt
mkdir CRintoX52to55rangeNis600
./maincr1 5 1086 720 52 55 2 bcsstm10.mtx >> CRintoX52to55rangeNis600/residual52to55result_bcsstm10.txt
mkdir CRintoX52to55rangeNis800
./maincr1 5 1086 960 52 55 2 bcsstm10.mtx >> CRintoX52to55rangeNis800/residual52to55result_bcsstm10.txt
mkdir CRintoR48to51rangeNis200
./maincr1 5 1086 240 48 51 0 bcsstm10.mtx >> CRintoR48to51rangeNis200/residual48to51result_bcsstm10.txt
mkdir CRintoR48to51rangeNis400
./maincr1 5 1086 480 48 51 0 bcsstm10.mtx >> CRintoR48to51rangeNis400/residual48to51result_bcsstm10.txt
mkdir CRintoR48to51rangeNis600
./maincr1 5 1086 720 48 51 0 bcsstm10.mtx >> CRintoR48to51rangeNis600/residual48to51result_bcsstm10.txt
mkdir CRintoR48to51rangeNis800
./maincr1 5 1086 960 48 51 0 bcsstm10.mtx >> CRintoR48to51rangeNis800/residual48to51result_bcsstm10.txt
mkdir CRintoP48to51rangeNis200
./maincr1 5 1086 240 48 51 1 bcsstm10.mtx >> CRintoP48to51rangeNis200/residual48to51result_bcsstm10.txt
mkdir CRintoP48to51rangeNis400
./maincr1 5 1086 480 48 51 1 bcsstm10.mtx >> CRintoP48to51rangeNis400/residual48to51result_bcsstm10.txt
mkdir CRintoP48to51rangeNis600
./maincr1 5 1086 720 48 51 1 bcsstm10.mtx >> CRintoP48to51rangeNis600/residual48to51result_bcsstm10.txt
mkdir CRintoP48to51rangeNis800
./maincr1 5 1086 960 48 51 1 bcsstm10.mtx >> CRintoP48to51rangeNis800/residual48to51result_bcsstm10.txt
mkdir CRintoX48to51rangeNis200
./maincr1 5 1086 240 48 51 2 bcsstm10.mtx >> CRintoX48to51rangeNis200/residual48to51result_bcsstm10.txt
mkdir CRintoX48to51rangeNis400
./maincr1 5 1086 480 48 51 2 bcsstm10.mtx >> CRintoX48to51rangeNis400/residual48to51result_bcsstm10.txt
mkdir CRintoX48to51rangeNis600
./maincr1 5 1086 720 48 51 2 bcsstm10.mtx >> CRintoX48to51rangeNis600/residual48to51result_bcsstm10.txt
mkdir CRintoX48to51rangeNis800
./maincr1 5 1086 960 48 51 2 bcsstm10.mtx >> CRintoX48to51rangeNis800/residual48to51result_bcsstm10.txt
 