#!/bin/bash
#SBATCH --time=23:59:00
mkdir IntoR60to63rangeNis200
./mainCGEnergy2 5 1138 220 60 63 0 1138_bus.mtx >> IntoR60to63rangeNis200/1138_bus.txt
mkdir IntoR60to63rangeNis400
./mainCGEnergy2 5 1138 440 60 63 0 1138_bus.mtx >> IntoR60to63rangeNis400/1138_bus.txt
mkdir IntoR60to63rangeNis600
./mainCGEnergy2 5 1138 660 60 63 0 1138_bus.mtx >> IntoR60to63rangeNis600/1138_bus.txt
mkdir IntoR60to63rangeNis800
./mainCGEnergy2 5 1138 880 60 63 0 1138_bus.mtx >> IntoR60to63rangeNis800/1138_bus.txt
mkdir IntoP60to63rangeNis200
./mainCGEnergy2 5 1138 220 60 63 1 1138_bus.mtx >> IntoP60to63rangeNis200/1138_bus.txt
mkdir IntoP60to63rangeNis400
./mainCGEnergy2 5 1138 440 60 63 1 1138_bus.mtx >> IntoP60to63rangeNis400/1138_bus.txt
mkdir IntoP60to63rangeNis600
./mainCGEnergy2 5 1138 660 60 63 1 1138_bus.mtx >> IntoP60to63rangeNis600/1138_bus.txt
mkdir IntoP60to63rangeNis800
./mainCGEnergy2 5 1138 880 60 63 1 1138_bus.mtx >> IntoP60to63rangeNis800/1138_bus.txt
mkdir IntoX60to63rangeNis200
./mainCGEnergy2 5 1138 220 60 63 2 1138_bus.mtx >> IntoX60to63rangeNis200/1138_bus.txt
mkdir IntoX60to63rangeNis400
./mainCGEnergy2 5 1138 440 60 63 2 1138_bus.mtx >> IntoX60to63rangeNis400/1138_bus.txt
mkdir IntoX60to63rangeNis600
./mainCGEnergy2 5 1138 660 60 63 2 1138_bus.mtx >> IntoX60to63rangeNis600/1138_bus.txt
mkdir IntoX60to63rangeNis800
./mainCGEnergy2 5 1138 880 60 63 2 1138_bus.mtx >> IntoX60to63rangeNis800/1138_bus.txt
mkdir IntoR56to59rangeNis200
./mainCGEnergy2 5 1138 220 56 59 0 1138_bus.mtx >> IntoR56to59rangeNis200/1138_bus.txt
mkdir IntoR56to59rangeNis400
./mainCGEnergy2 5 1138 440 56 59 0 1138_bus.mtx >> IntoR56to59rangeNis400/1138_bus.txt
mkdir IntoR56to59rangeNis600
./mainCGEnergy2 5 1138 660 56 59 0 1138_bus.mtx >> IntoR56to59rangeNis600/1138_bus.txt
mkdir IntoR56to59rangeNis800
./mainCGEnergy2 5 1138 880 56 59 0 1138_bus.mtx >> IntoR56to59rangeNis800/1138_bus.txt
mkdir IntoP56to59rangeNis200
./mainCGEnergy2 5 1138 220 56 59 1 1138_bus.mtx >> IntoP56to59rangeNis200/1138_bus.txt
mkdir IntoP56to59rangeNis400
./mainCGEnergy2 5 1138 440 56 59 1 1138_bus.mtx >> IntoP56to59rangeNis400/1138_bus.txt
mkdir IntoP56to59rangeNis600
./mainCGEnergy2 5 1138 660 56 59 1 1138_bus.mtx >> IntoP56to59rangeNis600/1138_bus.txt
mkdir IntoP56to59rangeNis800
./mainCGEnergy2 5 1138 880 56 59 1 1138_bus.mtx >> IntoP56to59rangeNis800/1138_bus.txt
mkdir IntoX56to59rangeNis200
./mainCGEnergy2 5 1138 220 56 59 2 1138_bus.mtx >> IntoX56to59rangeNis200/1138_bus.txt
mkdir IntoX56to59rangeNis400
./mainCGEnergy2 5 1138 440 56 59 2 1138_bus.mtx >> IntoX56to59rangeNis400/1138_bus.txt
mkdir IntoX56to59rangeNis600
./mainCGEnergy2 5 1138 660 56 59 2 1138_bus.mtx >> IntoX56to59rangeNis600/1138_bus.txt
mkdir IntoX56to59rangeNis800
./mainCGEnergy2 5 1138 880 56 59 2 1138_bus.mtx >> IntoX56to59rangeNis800/1138_bus.txt
mkdir IntoR52to55rangeNis200
./mainCGEnergy2 5 1138 220 52 55 0 1138_bus.mtx >> IntoR52to55rangeNis200/1138_bus.txt
mkdir IntoR52to55rangeNis400
./mainCGEnergy2 5 1138 440 52 55 0 1138_bus.mtx >> IntoR52to55rangeNis400/1138_bus.txt
mkdir IntoR52to55rangeNis600
./mainCGEnergy2 5 1138 660 52 55 0 1138_bus.mtx >> IntoR52to55rangeNis600/1138_bus.txt
mkdir IntoR52to55rangeNis800
./mainCGEnergy2 5 1138 880 52 55 0 1138_bus.mtx >> IntoR52to55rangeNis800/1138_bus.txt
mkdir IntoP52to55rangeNis200
./mainCGEnergy2 5 1138 220 52 55 1 1138_bus.mtx >> IntoP52to55rangeNis200/1138_bus.txt
mkdir IntoP52to55rangeNis400
./mainCGEnergy2 5 1138 440 52 55 1 1138_bus.mtx >> IntoP52to55rangeNis400/1138_bus.txt
mkdir IntoP52to55rangeNis600
./mainCGEnergy2 5 1138 660 52 55 1 1138_bus.mtx >> IntoP52to55rangeNis600/1138_bus.txt
mkdir IntoP52to55rangeNis800
./mainCGEnergy2 5 1138 880 52 55 1 1138_bus.mtx >> IntoP52to55rangeNis800/1138_bus.txt
mkdir IntoX52to55rangeNis200
./mainCGEnergy2 5 1138 220 52 55 2 1138_bus.mtx >> IntoX52to55rangeNis200/1138_bus.txt
mkdir IntoX52to55rangeNis400
./mainCGEnergy2 5 1138 440 52 55 2 1138_bus.mtx >> IntoX52to55rangeNis400/1138_bus.txt
mkdir IntoX52to55rangeNis600
./mainCGEnergy2 5 1138 660 52 55 2 1138_bus.mtx >> IntoX52to55rangeNis600/1138_bus.txt
mkdir IntoX52to55rangeNis800
./mainCGEnergy2 5 1138 880 52 55 2 1138_bus.mtx >> IntoX52to55rangeNis800/1138_bus.txt
mkdir IntoR48to51rangeNis200
./mainCGEnergy2 5 1138 220 48 51 0 1138_bus.mtx >> IntoR48to51rangeNis200/1138_bus.txt
mkdir IntoR48to51rangeNis400
./mainCGEnergy2 5 1138 440 48 51 0 1138_bus.mtx >> IntoR48to51rangeNis400/1138_bus.txt
mkdir IntoR48to51rangeNis600
./mainCGEnergy2 5 1138 660 48 51 0 1138_bus.mtx >> IntoR48to51rangeNis600/1138_bus.txt
mkdir IntoR48to51rangeNis800
./mainCGEnergy2 5 1138 880 48 51 0 1138_bus.mtx >> IntoR48to51rangeNis800/1138_bus.txt
mkdir IntoP48to51rangeNis200
./mainCGEnergy2 5 1138 220 48 51 1 1138_bus.mtx >> IntoP48to51rangeNis200/1138_bus.txt
mkdir IntoP48to51rangeNis400
./mainCGEnergy2 5 1138 440 48 51 1 1138_bus.mtx >> IntoP48to51rangeNis400/1138_bus.txt
mkdir IntoP48to51rangeNis600
./mainCGEnergy2 5 1138 660 48 51 1 1138_bus.mtx >> IntoP48to51rangeNis600/1138_bus.txt
mkdir IntoP48to51rangeNis800
./mainCGEnergy2 5 1138 880 48 51 1 1138_bus.mtx >> IntoP48to51rangeNis800/1138_bus.txt
mkdir IntoX48to51rangeNis200
./mainCGEnergy2 5 1138 220 48 51 2 1138_bus.mtx >> IntoX48to51rangeNis200/1138_bus.txt
mkdir IntoX48to51rangeNis400
./mainCGEnergy2 5 1138 440 48 51 2 1138_bus.mtx >> IntoX48to51rangeNis400/1138_bus.txt
mkdir IntoX48to51rangeNis600
./mainCGEnergy2 5 1138 660 48 51 2 1138_bus.mtx >> IntoX48to51rangeNis600/1138_bus.txt
mkdir IntoX48to51rangeNis800
./mainCGEnergy2 5 1138 880 48 51 2 1138_bus.mtx >> IntoX48to51rangeNis800/1138_bus.txt
 