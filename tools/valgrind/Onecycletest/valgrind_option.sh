#run process with memory leak check 
 valgrind --tool=memcheck --leak-check=full ./a.out 

# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out
