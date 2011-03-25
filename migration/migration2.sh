!/bin/bash
    
gcc prog.c -o 1.out                                                   
time ./1.out &                                                                             
PID=$(pidof -s "1.out")            
j=1;    
while [[ -z $PID ]]; do                                 
        (taskset -p $j $PID) > /dev/null                                        
  j=$(($j^1));                                    
        PID=$(pidof -s "1.out")                                                                            
    done                                                                                                    
time./1.out                                                                               
rm 1.out      


                                                                             
