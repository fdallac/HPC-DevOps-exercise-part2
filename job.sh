#!/bin/bash

#SBATCH --job-name=matrixMultiplication
#SBATCH --nodes=1
#SBATCH --time=01:00
#SBATCH --ntasks=2
#SBATCH -o output.log # assign STDOUT
#SBATCH -e errors.log # assign STDERR

module load singularity
export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

singularity exec --bind $TMPDIR:$TMPDIR  matrix-multiplication.sif bash -c "export OMPI_MCA_tmpdir_base=$TMPDIR && mpirun -np 2 main"