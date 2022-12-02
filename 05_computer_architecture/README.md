Какой процесс имеет наименьший идентификатор?
ps -Ao pid,comm --sort=pid | head -n 2
  PID COMMAND
    1 init
Какой идетификтор у вашего текущего shell-процесса?
ps -p $$
  PID TTY          TIME CMD
    9 pts/0    00:00:00 bash
Сколько всего запущено процессов?
ps -A | wc -l
7
