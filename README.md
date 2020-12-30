# Директория с заданиями по распределенным системам

## FirstTask
Директория FirstTask содержит наивную и быструю реализацию программы (файлы naive.cpp main.cpp), моделирующий MPI_GATHERV для транспьютерной матрицы 4x4. Директория cmake-build-debug содержит Makefile. Для запуска требуется проделать следующие команды:
• cd cmake-build-debug
• make
• mpirun -np 16 –oversubscribe ./Normal (oversubscribe параметр в случае недостаточного количества ядер).

## SecondTask
Директория SecondTask cодержит реализацию отказоустойчивой программы Gauss (main.c), Makefile, а также два скрипта, реализующие сборку и запуск программы. Обязательно требуется проделать следующую команду:
• docker pull abouteiller/mpi-ft-ulfm
Также для удобства можно проделать следующие команды:
• alias make='docker run -v $PWD:/sandbox:Z abouteiller/mpi-ft-ulfm make'
• alias mpirun='docker run -v $PWD:/sandbox:Z abouteiller/mpi-ft-ulfm mpirun --oversubscribe
-mca btl tcp,self'
В результате их выполнение make и mpirun будут выполняться на докерах (без использования скрипта).
