#!/bin/sh

# This program would need to be adjusted, but it was used to generate all the log files

filename="$1"
~/Research/SAT_Solvers/kissat/build/kissat "${filename}" > "${filename}_kissat.log"
~/Research/SAT_Solvers/minisat/core/minisat "${filename}" > "${filename}_minisat.log"
rm "${filename}"
