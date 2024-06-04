#!/bin/bash

#SBATCH --job-name=matrixMultiplication
#SBATCH --time=01:00
#SBATCH --ntasks=2
#SBATCH --nodes=1
#SBATCH -o output.log # redirect STDOUT
#SBATCH -e errors.log # redirect STDERR

module load singularity

export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

singularity exec --bind $TMPDIR:$TMPDIR  matrix-multiplication.sif bash -c "export OMPI_MCA_tmpdir_base=$TMPDIR && mpirun -np 2 /prj/main"