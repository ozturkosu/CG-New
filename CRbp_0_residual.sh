#!/bin/bash
#SBATCH --time=23:59:00
mkdir CRintoR60to63rangeNis200
./maincr1 5 822 160 60 63 0 bp_0.mtx >> CRintoR60to63rangeNis200/residual60to63result_bp_0.txt
mkdir CRintoR60to63rangeNis400
./maincr1 5 822 320 60 63 0 bp_0.mtx >> CRintoR60to63rangeNis400/residual60to63result_bp_0.txt
mkdir CRintoR60to63rangeNis600
./maincr1 5 822 480 60 63 0 bp_0.mtx >> CRintoR60to63rangeNis600/residual60to63result_bp_0.txt
mkdir CRintoR60to63rangeNis800
./maincr1 5 822 640 60 63 0 bp_0.mtx >> CRintoR60to63rangeNis800/residual60to63result_bp_0.txt
mkdir CRintoP60to63rangeNis200
./maincr1 5 822 160 60 63 1 bp_0.mtx >> CRintoP60to63rangeNis200/residual60to63result_bp_0.txt
mkdir CRintoP60to63rangeNis400
./maincr1 5 822 320 60 63 1 bp_0.mtx >> CRintoP60to63rangeNis400/residual60to63result_bp_0.txt
mkdir CRintoP60to63rangeNis600
./maincr1 5 822 480 60 63 1 bp_0.mtx >> CRintoP60to63rangeNis600/residual60to63result_bp_0.txt
mkdir CRintoP60to63rangeNis800
./maincr1 5 822 640 60 63 1 bp_0.mtx >> CRintoP60to63rangeNis800/residual60to63result_bp_0.txt
mkdir CRintoX60to63rangeNis200
./maincr1 5 822 160 60 63 2 bp_0.mtx >> CRintoX60to63rangeNis200/residual60to63result_bp_0.txt
mkdir CRintoX60to63rangeNis400
./maincr1 5 822 320 60 63 2 bp_0.mtx >> CRintoX60to63rangeNis400/residual60to63result_bp_0.txt
mkdir CRintoX60to63rangeNis600
./maincr1 5 822 480 60 63 2 bp_0.mtx >> CRintoX60to63rangeNis600/residual60to63result_bp_0.txt
mkdir CRintoX60to63rangeNis800
./maincr1 5 822 640 60 63 2 bp_0.mtx >> CRintoX60to63rangeNis800/residual60to63result_bp_0.txt
mkdir CRintoR56to59rangeNis200
./maincr1 5 822 160 56 59 0 bp_0.mtx >> CRintoR56to59rangeNis200/residual56to63result_bp_0.txt
mkdir CRintoR56to59rangeNis400
./maincr1 5 822 320 56 59 0 bp_0.mtx >> CRintoR56to59rangeNis400/residual56to63result_bp_0.txt
mkdir CRintoR56to59rangeNis600
./maincr1 5 822 480 56 59 0 bp_0.mtx >> CRintoR56to59rangeNis600/residual56to63result_bp_0.txt
mkdir CRintoR56to59rangeNis800
./maincr1 5 822 640 56 59 0 bp_0.mtx >> CRintoR56to59rangeNis800/residual56to63result_bp_0.txt
mkdir CRintoP56to59rangeNis200
./maincr1 5 822 160 56 59 1 bp_0.mtx >> CRintoP56to59rangeNis200/residual56to63result_bp_0.txt
mkdir CRintoP56to59rangeNis400
./maincr1 5 822 320 56 59 1 bp_0.mtx >> CRintoP56to59rangeNis400/residual56to63result_bp_0.txt
mkdir CRintoP56to59rangeNis600
./maincr1 5 822 480 56 59 1 bp_0.mtx >> CRintoP56to59rangeNis600/residual56to63result_bp_0.txt
mkdir CRintoP56to59rangeNis800
./maincr1 5 822 640 56 59 1 bp_0.mtx >> CRintoP56to59rangeNis800/residual56to63result_bp_0.txt
mkdir CRintoX56to59rangeNis200
./maincr1 5 822 160 56 59 2 bp_0.mtx >> CRintoX56to59rangeNis200/residual56to63result_bp_0.txt
mkdir CRintoX56to59rangeNis400
./maincr1 5 822 320 56 59 2 bp_0.mtx >> CRintoX56to59rangeNis400/residual56to63result_bp_0.txt
mkdir CRintoX56to59rangeNis600
./maincr1 5 822 480 56 59 2 bp_0.mtx >> CRintoX56to59rangeNis600/residual56to63result_bp_0.txt
mkdir CRintoX56to59rangeNis800
./maincr1 5 822 640 56 59 2 bp_0.mtx >> CRintoX56to59rangeNis800/residual56to63result_bp_0.txt
mkdir CRintoR52to55rangeNis200
./maincr1 5 822 160 52 55 0 bp_0.mtx >> CRintoR52to55rangeNis200/residual52to55result_bp_0.txt
mkdir CRintoR52to55rangeNis400
./maincr1 5 822 320 52 55 0 bp_0.mtx >> CRintoR52to55rangeNis400/residual52to55result_bp_0.txt
mkdir CRintoR52to55rangeNis600
./maincr1 5 822 480 52 55 0 bp_0.mtx >> CRintoR52to55rangeNis600/residual52to55result_bp_0.txt
mkdir CRintoR52to55rangeNis800
./maincr1 5 822 640 52 55 0 bp_0.mtx >> CRintoR52to55rangeNis800/residual52to55result_bp_0.txt
mkdir CRintoP52to55rangeNis200
./maincr1 5 822 160 52 55 1 bp_0.mtx >> CRintoP52to55rangeNis200/residual52to55result_bp_0.txt
mkdir CRintoP52to55rangeNis400
./maincr1 5 822 320 52 55 1 bp_0.mtx >> CRintoP52to55rangeNis400/residual52to55result_bp_0.txt
mkdir CRintoP52to55rangeNis600
./maincr1 5 822 480 52 55 1 bp_0.mtx >> CRintoP52to55rangeNis600/residual52to55result_bp_0.txt
mkdir CRintoP52to55rangeNis800
./maincr1 5 822 640 52 55 1 bp_0.mtx >> CRintoP52to55rangeNis800/residual52to55result_bp_0.txt
mkdir CRintoX52to55rangeNis200
./maincr1 5 822 160 52 55 2 bp_0.mtx >> CRintoX52to55rangeNis200/residual52to55result_bp_0.txt
mkdir CRintoX52to55rangeNis400
./maincr1 5 822 320 52 55 2 bp_0.mtx >> CRintoX52to55rangeNis400/residual52to55result_bp_0.txt
mkdir CRintoX52to55rangeNis600
./maincr1 5 822 480 52 55 2 bp_0.mtx >> CRintoX52to55rangeNis600/residual52to55result_bp_0.txt
mkdir CRintoX52to55rangeNis800
./maincr1 5 822 640 52 55 2 bp_0.mtx >> CRintoX52to55rangeNis800/residual52to55result_bp_0.txt
mkdir CRintoR48to51rangeNis200
./maincr1 5 822 160 48 51 0 bp_0.mtx >> CRintoR48to51rangeNis200/residual48to51result_bp_0.txt
mkdir CRintoR48to51rangeNis400
./maincr1 5 822 320 48 51 0 bp_0.mtx >> CRintoR48to51rangeNis400/residual48to51result_bp_0.txt
mkdir CRintoR48to51rangeNis600
./maincr1 5 822 480 48 51 0 bp_0.mtx >> CRintoR48to51rangeNis600/residual48to51result_bp_0.txt
mkdir CRintoR48to51rangeNis800
./maincr1 5 822 640 48 51 0 bp_0.mtx >> CRintoR48to51rangeNis800/residual48to51result_bp_0.txt
mkdir CRintoP48to51rangeNis200
./maincr1 5 822 160 48 51 1 bp_0.mtx >> CRintoP48to51rangeNis200/residual48to51result_bp_0.txt
mkdir CRintoP48to51rangeNis400
./maincr1 5 822 320 48 51 1 bp_0.mtx >> CRintoP48to51rangeNis400/residual48to51result_bp_0.txt
mkdir CRintoP48to51rangeNis600
./maincr1 5 822 480 48 51 1 bp_0.mtx >> CRintoP48to51rangeNis600/residual48to51result_bp_0.txt
mkdir CRintoP48to51rangeNis800
./maincr1 5 822 640 48 51 1 bp_0.mtx >> CRintoP48to51rangeNis800/residual48to51result_bp_0.txt
mkdir CRintoX48to51rangeNis200
./maincr1 5 822 160 48 51 2 bp_0.mtx >> CRintoX48to51rangeNis200/residual48to51result_bp_0.txt
mkdir CRintoX48to51rangeNis400
./maincr1 5 822 320 48 51 2 bp_0.mtx >> CRintoX48to51rangeNis400/residual48to51result_bp_0.txt
mkdir CRintoX48to51rangeNis600
./maincr1 5 822 480 48 51 2 bp_0.mtx >> CRintoX48to51rangeNis600/residual48to51result_bp_0.txt
mkdir CRintoX48to51rangeNis800
./maincr1 5 822 640 48 51 2 bp_0.mtx >> CRintoX48to51rangeNis800/residual48to51result_bp_0.txt
 